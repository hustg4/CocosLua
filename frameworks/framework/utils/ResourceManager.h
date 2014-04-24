//
//  ResourceManager.h
//  Framework
//
//  Created by wp_g4 on 13-4-18.
//
//

#ifndef __Framework__ResourceManager__
#define __Framework__ResourceManager__

#include <iostream>
#include "cocos2d.h"
#include "../json/JSONElement.h"
#include "../net/utils/HttpDownloader.h"

enum ResourceManagerErrorType {
    kResourceManagerErrorTypeVersionIsLatest = 0,           //版本已是最新
    kResourceManagerErrorTypeNoSuchModule = 1,              //模块不存在
    kResourceManagerErrorTypeDownloadFailure = 2,           //下载失败
    kResourceManagerErrorTypeVersionUpdateFailure = 3,      //版本更新失败（下载成功，但是解压缩错误）
};


enum DownloadFileType {
    kDownloadFileTypeBundleMd5File,             //Bundle的md5文件
    kDownloadFileTypeVersionFile,               //version说明文件下载
    kDownloadFileTypeConfigFile,                //资源配置文件下载
    kDownloadFileTypeModule                     //模块资源下载
};

/******************************** ResourceUpdateDelegate ********************************/

class ResourceUpdateDelegate {
    
public:
    
    virtual ~ResourceUpdateDelegate(){}
    
    /**
     * 版本检查结束
     * @param hasUpdate 是否有更新
     * @param needUpdateProgram 是否需要更新客户端程序
     * @param programUpdateURL 如果需要更新客户端程序，此参数是新版本客户端下载地址
     */
    virtual void onVersionCheckCompleted(bool hasUpdate,bool needUpdateProgram,const std::string& programUpdateURL){}
    
    /**
     * 版本更新完成
     */
    virtual void onVersionUpdated(){}
    
    /**
     * 模块更新完毕
     */
    virtual void onModuleUpdated(const std::string& moduleName){}
    
    /**
     * 单个文件已更新
     */
    virtual void onSingleFileUpdated(const std::string& moduleName,const std::string& filePath){}
    
    /**
     * 资源检查、更新过程中出错
     * @param 错误类型
     * @param 错误消息
     */
    virtual void onErrorOccured(ResourceManagerErrorType errorType , const std::string& message){}
    
};

/***************************************** End *****************************************/


class ResourceManagerUI;

/*********************************** ResourceManager ***********************************/

class ResourceManager :public cocos2d::Ref, public HttpDownloaderDelegate{
    
    
public:
    
    static ResourceManager* sharedResourceManager();
    
    ~ResourceManager();
    
    /**
     * 设置、获取资源更新事件委托
     */
    CC_SYNTHESIZE(ResourceUpdateDelegate*, delegate, Delegate);
    
    /**
     * 设置、获取资源更新事件委托（脚本）
     */
    CC_SYNTHESIZE(cocos2d::Ref*, scriptDelegate, ScriptDelegate);
    
    /**
     * 程序版本
     */
    void setProgramVersion(float programVersion){ this->programVersion = programVersion; }
    
    float getProgramVersion(){ return this->programVersion; }
    
    /**
     * 程序包中资源的版本
     */
    void setBundleResourceVersion(float bundleResourceVersion){ this->bundleResourceVersion = bundleResourceVersion; }
    
    float getBundleResourceVersion(){ return this->bundleResourceVersion; }
    
    /**
     * 开发模式设置
     */
    void setDevelopMode(bool developMode){ this->developMode = developMode; }
    
    bool isDevelopMode(){ return this->developMode; }
    
    /**
     * 设置资源根地址
     */
    void setRootURL(const std::string& rootUrl);
    
    /**
     * 获取资源根地址
     */
    const char* getRootURL();
    
    /**
     * 版本是否更新
     */
    bool isVersionLatest();
    
    /**
     * 获取版本
     */
    CC_SYNTHESIZE_READONLY(float, localVersion, Version);
    
    /**
     * 更新SearchPath设置
     */
    void configSearchPath();
    
    /**
     * 设置需要从bundle/apk中拷贝到用户下的文件列表
     */
    void setCopyFileList(cocos2d::__Array* copyFileList);
    
    /**
     * 检查版本号
     * 异步接口，检查完毕后会回调delegate的versionCheckCompleted接口
     */
    void checkVersion();
    
    /*
     * 更新版本
     */
    void updateVersion();
    
    /**
     * 检查模块资源版本
     * @return 需要更新的文件数量，如果是0表示模块不需要更新
     */
    int checkModule(const std::string& moduleName);
    
    /**
     * 更新模块资源
     */
    void updateModule(const std::string& moduleName);
    
    /**
     * 获取主版本待更新文件总尺寸
     */
    int getVersionUpdateSize();
    
    /**
     * 获取模块待更新文件的总尺寸
     */
    int getModuleUpdateSize(const std::string& moduleName);
    
    /**
     *  将相关配置信息写入文件
     *  当前版本只有 md5.global.txt
     *  在程序切到后台时，应该调用此接口，及时保存已经下载文件记录。
     */
    void flush();
    
public:
    
    virtual void onDownloadEvent(HttpDownloader* downloader,DownloadEvent* event);
    
private:
    
    float programVersion;                           //程序版本（指C++部分）
    
    float bundleResourceVersion;                    //程序包内脚本、资源的版本
    
    bool developMode;                               //debug模式开关.开关打开后，不再从资源服务器上获取资源
    
    std::string rootUrl;                            //资源根地址
    
    HttpDownloader* downloader;                     //下载器
    
    DownloadFileType downloadFileType;              //操作类型
    
    float serverVersion;                            //服务端资源版本
    
    bool versionLatest;                             //版本是否最新的标志
    
    cocos2d::__Dictionary*  downloadCache;          //待更新模块资源缓存 k-模块名  v-__Array
    
    cocos2d::__Array* updatingModuleList;           //正在更新的模块列表（后提交更新的模块具有更高的优先级）
    
    bool moduleUpdating;                            //模块是否正在更新
    
    cocos2d::__Array* copyFileList;
    
    float minProgramVersion;                        //游戏运行需要的最小程序版本号
    
    std::string programUpdateURL;                   //游戏程序更新地址
    
    JSONObject* jsonObjConfig;                      //服务器资源配置
    
    JSONObject* jsonObjMd5;                         //本地资源的md5信息
    
    bool globalMD5NeedFlush;                        //本地资源的md5配置信息是否需要更新到文件
    
    ResourceManager();
    
    void init();
    
    //拷贝 bundle/apk 下的指定文件到 用户目录
    void copyFiles(cocos2d::__Array* copyFileList);
    
    //清理SearchPath
    void clearSearchPath();
    
    void downloadBundleMD5File();
    
    //合并md5.bundle与md5.global,并将过时的文件删除
    void mergeMD5File();
    
    //下载版本描述文件
    void downloadVersionFile();
    
    //下载资源配置文件
    void downloadConfigFile();
    
    //下载模块文件
    void downloadModuleFile();
    
    //检查资源配置文件或者直接检查主模块文件
    void processAfterVersionFileDownload();
    
    //下载完资源配置文件之后，检查主模块文件
    void processAfterConfigFileDownload();
    
    //检查主模块
    void checkMainModule();
    
    //单个模块文件下载完成后的处理
    void processAfterSingleModleFileDownload(const std::string& moduleName);
    
    //保存版本号
    void saveVersion(float version);
    
    //获取文件的绝对路径(本地资源目录下)
    const char* fullLocalResourcePath(const std::string& filePath);
    
    //报告错误，对delegate和scriptDelegate进行回调
    void reportError(const std::string& moduleName, ResourceManagerErrorType errorType , const std::string& errorMsg);
    
    void removeModuleFromUpdatingList(const std::string& moduleName);
    
    //检查文件是否已经更新到最新
    bool isFileUpdated(const std::string& filePath);
    
    //执行版本检查结束的回调
    void callbackVersionCheckCompleted(bool hasUpdate,bool needUpdateProgram,const std::string& programUpdateURL);
};

/***************************************** End *****************************************/

#endif /* defined(__Framework__ResourceManager__) */
