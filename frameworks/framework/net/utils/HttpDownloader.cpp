//
//  HttpDownloader.cpp
//
//  Created by wp_g4 on 13-3-11.
//
//

#include "HttpDownloader.h"
#include "FileManager.h"

using namespace cocos2d;
using namespace std;

// 临时文件后缀，下载完成后会通过rename方式去掉
#define FileTempSuffix ".tmp"

static std::string httpDownloaderSemName = "download_sem"; //为安全起见，使用时应该附加唯一的值(比如时间戳)

#define DOWNLOAD_WAIT_UNRECEIVED_DATA_TIMES 10      //下载数据不再变化到结束下载需要等待的次数


/********************************* curl functions **************************************/

// 网络有数据时回调，直接回写到file
size_t onReceiveData(void *buffer, size_t size, size_t nmemb, void *ptr)
{
    HttpDownloader* downloader = (HttpDownloader*)ptr;
    DownloadTask* task = downloader->currentTask;
    
    size_t written = fwrite(buffer, size, nmemb, task->getSavedFile());
    return written;
}

// 下载进度回调
int onProgress(void *ptr, double totalToDownload, double nowDownloaded, double totalToUpLoad, double nowUpLoaded)
{
    HttpDownloader* downloader = (HttpDownloader*)ptr;
    
    DownloadTask* task = downloader->currentTask;
    
    //当前下载字节数 nowDownloaded 超过 DOWNLOAD_WAIT_UNRECEIVED_DATA_TIMES 次没变化，则认为下载出现异常
    
    if (task->getLastDownloadedBytes() == (int)nowDownloaded) {
        task->setUnreceivedDataTimes(task->getUnreceivedDataTimes()+1);
    }else{
        task->setUnreceivedDataTimes(0);
    }
    task->setLastDownloadedBytes(nowDownloaded);
    
    if (task->getUnreceivedDataTimes() >= DOWNLOAD_WAIT_UNRECEIVED_DATA_TIMES) {
        return 1;
    }
    
    float progress = nowDownloaded/totalToDownload;
    //CCLOG("totalToDownload:%lf nowDownloaded:%lf",nowDownloaded,totalToDownload);
    progress = progress < 0 ? 0 : progress;
    progress = progress > 1 ? 1 : progress;
    //CCLOG("download progress:[%.2f%%]", progress*100);
    
    downloader->addDownloadEvent(kDownloadEventTypeProgress, task, progress, "");
    
    return 0;
}

/********************************** thread function ***********************************/

// Worker thread
void* downloadThread(void *ptr)
{
    HttpDownloader* downloader = (HttpDownloader*)ptr;
    
    while (!downloader->needQuit) {
    
        sem_wait(downloader->pSem);
        
        downloader->downloading = true;
        
        DownloadTask* task = NULL;
        
        pthread_mutex_lock(&downloader->taskQueueMutex);
        
        if (downloader->taskQueue->count() > 0) {
            task = (DownloadTask*)downloader->taskQueue->getObjectAtIndex(0);
            task->retain();
            downloader->taskQueue->removeObjectAtIndex(0);
        }
        
        pthread_mutex_unlock(&downloader->taskQueueMutex);
        
        if (task) {
            
            downloader->currentTask = task;
            downloader->executeTask();
            task->release();
        }
        
        downloader->downloading = false;
    }
    
    return NULL;
}


/********************************* DownloadTask *********************************/


DownloadTask::DownloadTask(const std::string &url, const std::string &path, bool breakpointResume, cocos2d::Ref *userdata)
:userdata(NULL),
breakPointBytes(0),
pFile(NULL),
lastDownloadedBytes(0),
unreceivedDataTimes(0)
{
    this->url = url;
    this->path = path;
    this->breakpointResume = breakpointResume;
    this->setUserdata(userdata);
}

DownloadTask::~DownloadTask(){
    CC_SAFE_RELEASE_NULL(userdata);
}

DownloadTask* DownloadTask::create(const std::string &url, const std::string &path, bool breakpointResume, cocos2d::Ref *userdata)
{
    DownloadTask* task = new DownloadTask(url,path,breakpointResume,userdata);
    task->autorelease();
    return task;
}


const char* DownloadTask::getUrl()
{
    return this->url.c_str();
}

const char* DownloadTask::getPath()
{
    return this->path.c_str();
}

bool DownloadTask::isBreakpointResume()
{
    return this->breakpointResume;
}

int DownloadTask::getBreakPointBytes()
{
    return this->breakPointBytes;
}

void DownloadTask::setBreakPointBytes(int breakPointBytes)
{
    this->breakPointBytes = breakPointBytes;
}

void DownloadTask::setSavedFile(FILE* file)
{
    this->pFile = file;
}

FILE* DownloadTask::getSavedFile()
{
    return this->pFile;
}

void DownloadTask::setLastDownloadedBytes(int lastDownloadedBytes)
{
    this->lastDownloadedBytes = lastDownloadedBytes;
}

int DownloadTask::getLastDownloadedBytes()
{
    return this->lastDownloadedBytes;
}

void DownloadTask::setUnreceivedDataTimes(int unreceivedDataTimes)
{
    this->unreceivedDataTimes = unreceivedDataTimes;
}

int DownloadTask::getUnreceivedDataTimes()
{
    return this->unreceivedDataTimes;
}

Ref* DownloadTask::getUserdata()
{
    return this->userdata;
}

void DownloadTask::setUserdata(cocos2d::Ref *userdata)
{
    CC_SAFE_RETAIN(userdata);
    CC_SAFE_RELEASE_NULL(this->userdata);
    this->userdata = userdata;
}

/********************************* DownloadTask *********************************/

DownloadEvent::DownloadEvent(DownloadEventType type, DownloadTask *task)
:task(NULL),
progress(0),
errorMsg("")
{
    this->setType(type);
    this->setTask(task);
}

DownloadEvent::~DownloadEvent()
{
    CC_SAFE_RELEASE_NULL(task);
}


/********************************* HttpDownloader *******************************/

HttpDownloader::HttpDownloader()
:delegate(NULL),
isThreadInited(false),
needQuit(false),
currentTask(NULL),
downloading(false),
pSem(NULL)
{
    taskQueue = __Array::create();
    CC_SAFE_RETAIN(taskQueue);
    
    eventQueue = __Array::create();
    CC_SAFE_RETAIN(eventQueue);
}

HttpDownloader::~HttpDownloader()
{
    CC_SAFE_RELEASE_NULL(taskQueue);
    CC_SAFE_RELEASE_NULL(eventQueue);
}

void HttpDownloader::setDelegate(HttpDownloaderDelegate *delegate)
{
    this->delegate = delegate;
}

HttpDownloaderDelegate* HttpDownloader::getDelegate()
{
    return this->delegate;
}

bool HttpDownloader::initThread()
{
    pthread_mutex_init(&taskQueueMutex, NULL);
    pthread_mutex_init(&eventQueueMutex, NULL);
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    long t = time(NULL);
    httpDownloaderSemName.append(__String::createWithFormat("%ld",t)->getCString());
    pSem = sem_open(httpDownloaderSemName.c_str(), O_CREAT, 0644, 0);
    if (pSem == SEM_FAILED) {
        CCLOG("Open HttpDownloader Semaphore failed,errno=%d",errno);
        pSem = NULL;
        return false;
    }
#else
    int semRet = sem_init(&sem, 0, 0);
    if (semRet < 0) {
        CCLog("Init HttpDownloader Semaphore failed");
        return false;
    }
    pSem = &sem;
#endif
    
    pthread_create(&networkThread, NULL, downloadThread, this);
    pthread_detach(networkThread);
    
    CCDirector::getInstance()->getScheduler()->scheduleSelector(schedule_selector(HttpDownloader::processDownloadEvent), this,  0 ,false);
    
    return true;
}


void HttpDownloader::destroy()
{
    CCDirector::getInstance()->getScheduler()->unscheduleAllForTarget(this);
    
    this->needQuit = true;
    
    if (pSem != NULL) {
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
        sem_unlink(httpDownloaderSemName.c_str());
        sem_close(pSem);
#else
        sem_destroy(pSem);
#endif
        
        pSem = NULL;
    }
    
    this->release();
    
}

void HttpDownloader::download(const std::string &url, const std::string &savePath, bool breakpointResume,Ref* userdata)
{
    //参数检查
    if (url.length() ==0 || savePath.size() == 0) {
        CCLOG("url和文件保存路径均不能为空");
        return ;
    }
    
    //初始化线程
    if (!isThreadInited) {
        isThreadInited = this->initThread();
        if (!isThreadInited) {
            CCLOG("HttpDownloader 线程初始化失败");
            return;
        }
    }
    
    //创建下载任务并添加到任务队列
    DownloadTask* task = DownloadTask::create(url, savePath, breakpointResume,userdata);
    
    pthread_mutex_lock(&taskQueueMutex);
    taskQueue->addObject(task);
    pthread_mutex_unlock(&taskQueueMutex);
    
    //向下载线程发信号
    sem_post(pSem);
    
}

bool HttpDownloader::isDownloading()
{
    return this->downloading;
}

void HttpDownloader::processDownloadEvent(float deta)
{
    __Array* tempEventList = __Array::create();
    pthread_mutex_lock(&eventQueueMutex);
    tempEventList->addObjectsFromArray(this->eventQueue);
    this->eventQueue->removeAllObjects();
    pthread_mutex_unlock(&eventQueueMutex);
    
    int count = tempEventList->count();
    for (int i = 0; i < count; i++) {
        
        DownloadEvent* event = (DownloadEvent*)tempEventList->getObjectAtIndex(i);
        if (this->delegate)
        {
            this->delegate->onDownloadEvent(this, event);
        }
        
    }
}

/**
 * 执行下载任务。run in download thread
 */
void HttpDownloader::executeTask()
{
    
    // 下载和保存文件
    CCLOG("即将下载文件:[%s]",this->currentTask->getUrl());
    
    this->addDownloadEvent(kDownloadEventTypeStart, this->currentTask, 0, "");
    
    bool status = true;
    
    do {
        
        //初始化任务
        if (status) {
            status = this->initTask();
        }
        
        //检查初始化结果
        if (!status) {
            this->addDownloadEvent(kDownloadEventTypeFailure, this->currentTask, 0, "初始化任务失败");
            break;
        }
        
        //开始下载
        if (status) {
            status = this->doDownload();
        }
        
        //检查下载结果
        if (!status) {
            this->addDownloadEvent(kDownloadEventTypeFailure, this->currentTask, 0, "下载失败");
            break;
        }
        
        //后续处理
        if (status) {
            status = this->renameFile();
        }
        
        //检查后续处理结果
        if (!status) {
            this->addDownloadEvent(kDownloadEventTypeFailure, this->currentTask, 0, "下载后重命名文件失败");
            break;
        }
    
    }while (0);
    
    if (this->currentTask->getSavedFile()) {
        fclose(this->currentTask->getSavedFile());
        this->currentTask->setSavedFile(NULL);
    }
    
    //如果所有步骤正确完成，则下载成功
    if (status) {
        CCLOG("下载成功");
        this->addDownloadEvent(kDownloadEventTypeSuccess, this->currentTask, 1, "");
    }
}

/**
 * 初始化任务. run in download thread
 */
bool HttpDownloader::initTask()
{
    string tempStdFullPath = this->currentTask->getPath();
    
    if(tempStdFullPath[tempStdFullPath.size() - 1] == '/') // 需要指定文件而不是路径
    {
        CCLOG("需要指定文件而不是目录");
        return false;
    }
    
    //创建目录
    if(!FileManager::createDirectory(tempStdFullPath))
    {
        CCLOG("创建目录错误");
        return false;
    }
    
    tempStdFullPath.append(FileTempSuffix); // 先写入一个temp文件，然后重命名，确保下载事务操作
    
    //非断点模式先删除旧的temp文件
    if (!this->currentTask->isBreakpointResume() && FileManager::fileExists(tempStdFullPath)) {
        bool res = FileManager::removeFile(tempStdFullPath);
        if (!res) {
            CCLOG("删除旧temp文件错误");
            return false;
        }
    }
    
    FILE* pFile = fopen(tempStdFullPath.c_str(), "ab");
    if (! pFile)
    {
        CCLOG("创建文件错误");
        return false;
    }
    
    //断点续传模式下，获取文件大小
    fseek(pFile,0,SEEK_END);       //定位到文件末
    this->currentTask->setBreakPointBytes(ftell(pFile));
    this->currentTask->setSavedFile(pFile);
    
    return true;
}

/**
 * 开始下载. run in download thread
 */
bool HttpDownloader::doDownload()
{
    CURL *curl = curl_easy_init();
    if (! curl)
    {
        CCLOG("初始化curl出错");
        return false;
    }
    
    char* errorBuffer = (char*)malloc(CURL_ERROR_SIZE);
    
    CURLcode res;
    
    curl_easy_setopt(curl, CURLOPT_URL, this->currentTask->getUrl());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, onReceiveData);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, this);
    
    //是否断点续传
    if (this->currentTask->isBreakpointResume() && this->currentTask->getBreakPointBytes()!=0) {
        char s[1000]={0};
        sprintf(s, "%d-",this->currentTask->getBreakPointBytes());
        std::string str = s;
        curl_easy_setopt(curl, CURLOPT_RANGE,str.c_str());
    }
    
    // 设置超时时间为无限
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 0);
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 0);
    curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errorBuffer);
    
    // 下载进度
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, false);
    curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, onProgress);
    curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, this);
    
    //禁用掉alarm超时，注：DNS超时依赖与此，禁用之后DNS没有了超时检查
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);
    
    //dns缓存 6小时
    static CURLSH* share_handle = NULL;
    if (!share_handle)
    {
        share_handle = curl_share_init();
        curl_share_setopt(share_handle, CURLSHOPT_SHARE, CURL_LOCK_DATA_DNS);
    }
    curl_easy_setopt(curl, CURLOPT_SHARE, share_handle);
    curl_easy_setopt(curl, CURLOPT_DNS_CACHE_TIMEOUT, 3600 * 6);
    
    res = curl_easy_perform(curl);
    
    int responseCode;
    CURLcode code = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &responseCode);
    if (code != CURLE_OK || (responseCode != 200 && responseCode != 206))//206为断点续传
    {
        code = CURLE_HTTP_RETURNED_ERROR;
    }
    
    curl_easy_cleanup(curl);
    
    
    if (res != 0 || code != CURLE_OK || (responseCode != 200 && responseCode != 206))//206为断点续传
    {
        std::string errorMsg;
        errorMsg.append("下载失败:").append(errorBuffer);
        CCLOG("%s",errorMsg.c_str());
        return false;
    }
    free(errorBuffer);
    return true;
}

/**
 * 重命名文件. run in download thread
 */
bool HttpDownloader::renameFile()
{
    std::string tmpFullPath = this->currentTask->getPath();
    tmpFullPath.append(FileTempSuffix);
    
    if (0 != rename(tmpFullPath.c_str(), this->currentTask->getPath())) {
        CCLOG("重命名文件失败:errno=%d",errno);
        return false;
    }
    return true;
}

/**
 * 往事件队列中添加事件. run in download thread
 */
void HttpDownloader::addDownloadEvent(DownloadEventType type, DownloadTask *task, float progress, const std::string &errorMsg)
{
    
    DownloadEvent* event = new DownloadEvent(type,task);
    
    if (type == kDownloadEventTypeProgress) {
        event->setProgress(progress);
    }else if (type == kDownloadEventTypeSuccess){
        event->setProgress(1);
    }else if (type == kDownloadEventTypeFailure){
        event->setErrorMsg(errorMsg);
    }
    
    pthread_mutex_lock(&eventQueueMutex);
    this->eventQueue->addObject(event);
    pthread_mutex_unlock(&eventQueueMutex);
    
    event->release();
}
