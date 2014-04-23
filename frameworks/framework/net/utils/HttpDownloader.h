//
//  HttpDownloader.h
//
//  Created by wp_g4 on 13-3-11.
//
//

#ifndef __HttpDownloader__
#define __HttpDownloader__

#include "cocos2d.h"

#include "curl/curl.h"
#include <curl/easy.h>
#include <stdio.h>

#include <pthread.h>
#include <semaphore.h>

#include <sys/stat.h>
#include <errno.h>



class HttpDownloader;
class DownloadTask;
class DownloadEvent;

/**
 * 文件下载器的回调
 */
class HttpDownloaderDelegate {
    
public:
    
    virtual ~HttpDownloaderDelegate(){};
    
    virtual void onDownloadEvent(HttpDownloader* downloader,DownloadEvent* event) = 0;
    
};


/**
 * 下载任务
 */
class DownloadTask : public cocos2d::Ref{
    
public:
    
    DownloadTask(const std::string& url,const std::string& path,bool breakpointResume,Ref* userdata);
    
    ~DownloadTask();
    
    static DownloadTask* create(const std::string& url,const std::string& path,bool breakpointResume,Ref* userdata);
    
    const char* getUrl();
    
    const char* getPath();
    
    bool isBreakpointResume();
    
    int getBreakPointBytes();
    
    Ref* getUserdata();
    
    
protected:
    
    void setBreakPointBytes(int breakPointBytes);
    
    void setSavedFile(FILE* file);
    
    FILE* getSavedFile();
    
    void setLastDownloadedBytes(int lastDownloadedBytes);
    
    int getLastDownloadedBytes();
    
    void setUnreceivedDataTimes(int unreceivedDataTimes);
    
    int getUnreceivedDataTimes();
    
    void setUserdata(Ref* userdata);
    
private:
    
    friend class HttpDownloader;
    
    friend int onProgress(void *ptr, double totalToDownload, double nowDownloaded, double totalToUpLoad, double nowUpLoaded);
    
    friend size_t onReceiveData(void *buffer, size_t size, size_t nmemb, void *ptr);
    
    std::string url;                //文件地址
    
    std::string path;               //保存路径
    
    bool breakpointResume;          //断点续传
    
    Ref* userdata;             //用户信息
    
    int breakPointBytes;            //断点的字节数
    
    FILE *pFile;                    //保存的文件
    
    int lastDownloadedBytes;        //上一次curl收到数据时的字节数
    
    int unreceivedDataTimes;        //没收到数据的curl回调次数
    
};

enum DownloadEventType {
    kDownloadEventTypeStart = 0,        //开始
    kDownloadEventTypeProgress = 1,     //进度
    kDownloadEventTypeSuccess = 2,      //成功
    kDownloadEventTypeFailure = 3,      //失败
};

class DownloadEvent : public cocos2d::Ref{
    
public:
    
    DownloadEvent(DownloadEventType type,DownloadTask* task);
    
    ~DownloadEvent();
    
    CC_SYNTHESIZE(DownloadEventType, type, Type);
    
    CC_SYNTHESIZE_RETAIN(DownloadTask*, task, Task);
    
    CC_SYNTHESIZE(float, progress, Progress);
    
    CC_SYNTHESIZE_PASS_BY_REF(std::string, errorMsg, ErrorMsg);
    
};


/**
 * 文件下载器
 */
class HttpDownloader : public cocos2d::Ref
{
    
public:
    
    HttpDownloader();
    
    virtual ~HttpDownloader();
    
    void setDelegate(HttpDownloaderDelegate* delegate);
    
    HttpDownloaderDelegate* getDelegate();
    
    //销毁
    void destroy();
    
    //进行下载
    void download(const std::string& url,const std::string& savePath,bool breakpointResume = false,Ref* userdata = NULL);
    
    bool isDownloading();
    
    //处理下载事件
    void processDownloadEvent(float deta);
    
protected:
    
    friend size_t onReceiveData(void *buffer, size_t size, size_t nmemb, void *ptr);
    
    friend void* downloadThread(void *data);
    
    friend int onProgress(void *ptr, double totalToDownload, double nowDownloaded, double totalToUpLoad, double nowUpLoaded);
    
    bool initThread();
    
    /******************* functions run in download thread *******************/
    
    // 执行文件下载任务
    void executeTask();
    
    /**
     *  初始化任务
     *  1、如果是非断点续传模式，删除temp文件（如果存在）并重新创建
     *  2、如果是断点续传模式，计算断点值（即当前temp文件尺寸）
     */
    bool initTask();
    
    /**
     * 开始下载
     */
    bool doDownload();
    
    // 将下载完成的temp文件重命名为正确文件名
    bool renameFile();
    
    //往事件队列中添加事件
    void addDownloadEvent(DownloadEventType type,DownloadTask* task,float progress,const std::string& errorMsg);
    
    /******************* functions run in download thread *******************/
    
protected:
    
    HttpDownloaderDelegate*     delegate;               //事件委托
    
    bool                        isThreadInited;         //线程是否已经初始化
    
    cocos2d::__Array*           taskQueue;              //任务队列
    
    cocos2d::__Array*           eventQueue;             //事件队列
    
    bool                        needQuit;               //下载线程退出标志
    
    DownloadTask*               currentTask;            //当前下载任务
    
    bool                        downloading;            //下载标志
    
    pthread_t                   networkThread;          //线程
    
    sem_t*                      pSem;                   //信号量
    
    sem_t                       sem;                    //信号量
    
    pthread_mutex_t             taskQueueMutex;         //任务队列互斥锁
    
    pthread_mutex_t             eventQueueMutex;        //事件队列互斥锁
    
    
};

#endif /* defined(__HttpDownloader__) */
