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
    
    Director::getInstance()->getScheduler()->performFunctionInCocosThread([=]{
        if(downloader->delegate)
        {
            downloader->delegate->onProgress(task->userdata, progress);
        }
    });
    
    return 0;
}

/********************************** thread function ***********************************/

// Worker thread
void HttpDownloader::downloadThreadFunc()
{
    while (!needQuit) {
        downloading = true;
        DownloadTask* task = NULL;
        do {
            //scope lock
            unique_lock<mutex> lock(downloadMutex);
            while(taskQueue.empty())
            {
                queueSizeCond.wait(lock);
            }
            
            task = (DownloadTask*)taskQueue.back();
            task->retain();
            taskQueue.popBack();
        } while( 0 );

        if (task) {
            currentTask = task;
            executeTask();
            task->release();
        }
        downloading = false;
    }
}


/********************************* DownloadTask *********************************/


DownloadTask::DownloadTask(const std::string &url, const std::string &path, bool breakpointResume, void *userdata)
:userdata(NULL),
breakPointBytes(0),
pFile(NULL),
lastDownloadedBytes(0),
unreceivedDataTimes(0)
{
    this->url = url;
    this->path = path;
    this->breakpointResume = breakpointResume;
    this->userdata = userdata;
}

DownloadTask::~DownloadTask(){
}

DownloadTask* DownloadTask::create(const std::string &url, const std::string &path, bool breakpointResume, void *userdata)
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

void* DownloadTask::getUserdata()
{
    return this->userdata;
}

void DownloadTask::setUserdata(void *userdata)
{
    this->userdata = userdata;
}

/********************************* end DownloadTask *********************************/


/********************************* HttpDownloader *******************************/

HttpDownloader::HttpDownloader()
:delegate(NULL),
isThreadInited(false),
needQuit(false),
currentTask(NULL),
downloading(false)
{
}

HttpDownloader::~HttpDownloader()
{
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
    downloadThread = thread([=]()
                            {
                                downloadThreadFunc();
                            });
    downloadThread.detach();
    
    return true;
}


void HttpDownloader::destroy()
{
    CCDirector::getInstance()->getScheduler()->unscheduleAllForTarget(this);
    
    this->needQuit = true;
    
    this->release();
    
}


bool HttpDownloader::download(const std::string &url, const std::string &savePath, bool breakpointResume, void* userdata)
{
    //参数检查
    if (url.length() ==0 || savePath.size() == 0) {
        CCLOG("url和文件保存路径均不能为空");
        return false;
    }
    
    //初始化线程
    if (!isThreadInited) {
        isThreadInited = this->initThread();
        if (!isThreadInited) {
            CCLOG("HttpDownloader 线程初始化失败");
            return false;
        }
    }
    
    //创建下载任务并添加到任务队列
    DownloadTask* task = DownloadTask::create(url, savePath, breakpointResume,userdata);
    
    unique_lock<mutex> lock(downloadMutex);
    taskQueue.pushBack(task);
    queueSizeCond.notify_one();
    
    return true;
}

bool HttpDownloader::isDownloading()
{
    return this->downloading;
}

/**
 * 执行下载任务。run in download thread
 */
void HttpDownloader::executeTask()
{
    
    // 下载和保存文件
    CCLOG("即将下载文件:[%s]",this->currentTask->getUrl());
    
    Director::getInstance()->getScheduler()->performFunctionInCocosThread([=]{
        if(this->delegate)
        {
            delegate->onStart(this->currentTask->userdata);
        }
    });
    
    bool status = true;
    
    do {
        
        //初始化任务
        if (status) {
            status = this->initTask();
        }
        
        //检查初始化结果
        if (!status) {
            Director::getInstance()->getScheduler()->performFunctionInCocosThread([=]{
                if(delegate)
                {
                    delegate->onError(this->currentTask->userdata, HttpDownloaderErrorCode::INIT_TASK_ERROR);
                }
            });
            break;
        }
        
        //开始下载
        if (status) {
            status = this->doDownload();
        }
        
        //检查下载结果
        if (!status) {
            Director::getInstance()->getScheduler()->performFunctionInCocosThread([=]{
                if(delegate)
                {
                    delegate->onError(this->currentTask->userdata, HttpDownloaderErrorCode::DOWNLOAD_ERROR);
                }
            });
            break;
        }
        
        //后续处理
        if (status) {
            status = this->renameFile();
        }
        
        //检查后续处理结果
        if (!status) {
            Director::getInstance()->getScheduler()->performFunctionInCocosThread([=]{
                if(delegate)
                {
                    delegate->onError(this->currentTask->userdata, HttpDownloaderErrorCode::RENAME_FILE_ERROR);
                }
            });
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
        Director::getInstance()->getScheduler()->performFunctionInCocosThread([=]{
            if(delegate)
            {
                delegate->onSuccess(this->currentTask->userdata);
            }
        });
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