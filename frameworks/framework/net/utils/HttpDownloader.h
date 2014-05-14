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
#include "curl/easy.h"
#include <stdio.h>

#include <pthread.h>
#include <semaphore.h>

#include <sys/stat.h>
#include <errno.h>



class HttpDownloader;
class DownloadTask;

//TODO:明确的error code
enum class HttpDownloaderErrorCode
{
    INIT_TASK_ERROR,
    DOWNLOAD_ERROR,
    RENAME_FILE_ERROR,
};

/**
 * 文件下载器的回调
 */
class HttpDownloaderDelegate {
    
public:
    
    virtual ~HttpDownloaderDelegate(){};
    
    virtual void onStart(void *userData) {};
    virtual void onError(void *userData, HttpDownloaderErrorCode errorCode){};
    virtual void onProgress(void *userData, double percent) {};
    virtual void onSuccess(void *userData) {};
};


/**
 * 下载任务
 */
class DownloadTask : public cocos2d::Ref{
    
public:
    
    DownloadTask(const std::string& url,const std::string& path,bool breakpointResume, void* userdata);
    
    ~DownloadTask();
    
    static DownloadTask* create(const std::string& url,const std::string& path,bool breakpointResume, void *userdata);
    
    const char* getUrl();
    
    const char* getPath();
    
    bool isBreakpointResume();
    
    int getBreakPointBytes();
    
    void* getUserdata();
    
    
protected:
    
    void setBreakPointBytes(int breakPointBytes);
    
    void setSavedFile(FILE* file);
    
    FILE* getSavedFile();
    
    void setLastDownloadedBytes(int lastDownloadedBytes);
    
    int getLastDownloadedBytes();
    
    void setUnreceivedDataTimes(int unreceivedDataTimes);
    
    int getUnreceivedDataTimes();
    
    void setUserdata(void* userdata);
    
private:
    
    friend class HttpDownloader;
    
    friend int onProgress(void *ptr, double totalToDownload, double nowDownloaded, double totalToUpLoad, double nowUpLoaded);
    
    friend size_t onReceiveData(void *buffer, size_t size, size_t nmemb, void *ptr);
    
    std::string url;                //文件地址
    
    std::string path;               //保存路径
    
    bool breakpointResume;          //断点续传
    
    void* userdata;             //用户信息
    
    int breakPointBytes;            //断点的字节数
    
    FILE *pFile;                    //保存的文件
    
    int lastDownloadedBytes;        //上一次curl收到数据时的字节数
    
    int unreceivedDataTimes;        //没收到数据的curl回调次数
    
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
    bool download(const std::string& url,const std::string& savePath,bool breakpointResume = false, void* userdata = NULL);
    
    bool isDownloading();
    
    //处理下载事件
    void processDownloadEvent(float deta);
    
protected:
    
    friend size_t onReceiveData(void *buffer, size_t size, size_t nmemb, void *ptr);
    
//    friend void* downloadThread(void *data);
    
    void downloadThreadFunc();
    
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
    
    /******************* functions run in download thread *******************/
    
protected:
    
    HttpDownloaderDelegate*     delegate;               //事件委托
    
    bool                        isThreadInited;         //线程是否已经初始化
    
    cocos2d::Vector<DownloadTask*>                 taskQueue;              //任务队列
    
    bool                        needQuit;               //下载线程退出标志
    
    DownloadTask*               currentTask;            //当前下载任务
    
    bool                        downloading;            //下载标志
    
    std::thread                 downloadThread;         //线程
    std::condition_variable     queueSizeCond;
    std::mutex                  downloadMutex;
    
};

#endif /* defined(__HttpDownloader__) */
