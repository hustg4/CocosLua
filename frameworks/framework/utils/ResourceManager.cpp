//
//  ResourceManager.cpp
//  Framework
//
//  Created by wp_g4 on 13-4-18.
//
//

#include "ResourceManager.h"
#include "FileManager.h"
#include "LuaUtil.h"

USING_NS_CC;

#define RMVersionFile                   "version.txt"               //版本描述文件
#define RMBundleMD5File                 "md5.bundle.txt"            //程序发布时，程序包内文件的md5
#define RMGlobalMD5File                 "md5.global.txt"            //程序当前所有文件的最新版本的md5
#define RMConfigFile                    "config.resource.txt"       //当前最新版本资源的配置文件
#define RMMainModuleName                "__main__"                  //主模块名称

#define RMServerResourceDirectory       "Resource"                  //最新资源包在资源服务器上的目录
#define RMBundleMD5Directory            "BundleMD5"                 //版本md5文件在资源服务器上目录
#define RMLocalResourceDirectory        "Resource"                  //最新资源包在本地的目录


#define RMVersionKey                    "version"                   //版本号在version.txt和UserDefault中的键名
#define RMMinProgramVersionKey          "minProgramVersion"         //最低要求的程序版本号在version.txt中的键名
#define RMProgramUpdateURLKey           "programUpdateURL"          //程序更新地址的version.txt中的键名


//比较两个版本号，versionA大于versionB，返回1，相等返回0，小于则返回-1
int compareVersion(float versionA,float versionB)
{
    if (fabsf(versionA - versionB) < 0.0001) {
        return 0;
    }else if (versionA > versionB){
        return 1;
    }else{
        return -1;
    }
}

static ResourceManager* instance = NULL;

ResourceManager::ResourceManager()
:programVersion(0),
bundleResourceVersion(0),
developMode(false),
serverVersion(0),
versionLatest(false),
moduleUpdating(false),
copyFileList(NULL),
minProgramVersion(0),
programUpdateURL(""),
jsonObjConfig(NULL),
jsonObjMd5(NULL),
globalMD5NeedFlush(false)
{
}

void ResourceManager::init()
{
    //实例化downloader
    downloader = new HttpDownloader();
    downloader->setDelegate(this);
    CC_SAFE_RETAIN(downloader);
    
    //创建模块待下载文件缓存
    downloadCache = __Dictionary::create();
    CC_SAFE_RETAIN(downloadCache);
    
    //创建正在更新的模块列表
    updatingModuleList = __Array::create();
    CC_SAFE_RETAIN(updatingModuleList);
    
    //初始化本地资源版本
    localVersion = CCUserDefault::sharedUserDefault()->getFloatForKey(RMVersionKey);
    
    //读取资源配置信息
    std::string configFilePath = this->fullLocalResourcePath(RMConfigFile);
    if (FileManager::fileExists(configFilePath)) {
        jsonObjConfig = JSONObject::createWithFile(configFilePath);
    }else{
        jsonObjConfig = JSONObject::create();
    }
    CC_SAFE_RETAIN(jsonObjConfig);
    
    //读取本地全局资源md5信息
    std::string globalMD5FilePath = this->fullLocalResourcePath(RMGlobalMD5File);
    if (FileManager::fileExists(globalMD5FilePath)) {
        jsonObjMd5 = JSONObject::createWithFile(globalMD5FilePath);
    }else{
        jsonObjMd5 = JSONObject::create();
    }
    CC_SAFE_RETAIN(jsonObjMd5);
}

ResourceManager::~ResourceManager()
{
    downloader->destroy();
    CC_SAFE_RELEASE_NULL(downloadCache);
    CC_SAFE_RELEASE_NULL(updatingModuleList);
    CC_SAFE_RELEASE_NULL(jsonObjConfig);
    CC_SAFE_RELEASE_NULL(jsonObjMd5);
}

ResourceManager* ResourceManager::sharedResourceManager()
{
    if (instance == NULL) {
        instance = new ResourceManager();
        instance->init();
    }
    return instance;
}

void ResourceManager::setRootURL(const std::string& rootUrl)
{
    this->rootUrl = rootUrl;
    if (this->rootUrl.at(this->rootUrl.size()-1) != '/') {
        this->rootUrl.append("/");
    }
}

const char* ResourceManager::getRootURL()
{
    return this->rootUrl.c_str();
}

bool ResourceManager::isVersionLatest()
{
    return versionLatest;
}

void ResourceManager::configSearchPath()
{
    
    //(a) 清除当前SearchPath设置与缓存
    this->clearSearchPath();
    
    //(b) res path:WritablePath->Bundle
    std::vector<std::string> searchPaths;
    searchPaths.push_back(this->fullLocalResourcePath(""));
    searchPaths.push_back(RMLocalResourceDirectory);
    
    //script
    std::string scriptPath = "script";
    searchPaths.push_back(this->fullLocalResourcePath(scriptPath));
    searchPaths.push_back(FileManager::splicePath(CCFileUtils::getInstance()->fullPathForFilename(RMLocalResourceDirectory), scriptPath));
    
    
    CCFileUtils::getInstance()->setSearchPaths(searchPaths);
    
}

void ResourceManager::clearSearchPath()
{
    std::vector<std::string> emptySearchPaths;
    CCFileUtils::getInstance()->setSearchPaths(emptySearchPaths);
    CCFileUtils::getInstance()->purgeCachedEntries();
}

void ResourceManager::setCopyFileList(const cocos2d::ValueVector &copyFileList)
{
    this->copyFileList = copyFileList;
}

void ResourceManager::checkVersion()
{
    //检查Resource目录是否存在，如果不存在则创建
    std::string localResourcePath = FileManager::splicePath(CCFileUtils::getInstance()->getWritablePath(), RMLocalResourceDirectory);
    localResourcePath.append("/");
    if (!FileManager::fileExists(localResourcePath)) {
        FileManager::createDirectory(localResourcePath);
    }
    
    //检查bundle内资源版本，如果比local内资源版本高，则先进行必要的处理
    if (compareVersion(this->bundleResourceVersion, localVersion) == 1) {
        
        this->clearSearchPath();
        
        //(1) 下载BundleResourceVersion对应的md5文件
        this->downloadBundleMD5File();
        
        //(2) 拷贝 bundle/apk 下的指定文件到 用户目录
        this->copyFiles(this->copyFileList);
        
        this->configSearchPath();
        
    }else{
        //下载 版本描述文件
        this->downloadVersionFile();
    }
    
}

void ResourceManager::downloadBundleMD5File()
{
    //从服务器下载bundler md5文件
    //(1) 下载地址
    std::string downloadPath = FileManager::splicePath(this->rootUrl, RMBundleMD5Directory);
    __String* verStr = __String::createWithFormat("%.2f",this->bundleResourceVersion);
    downloadPath = FileManager::splicePath(downloadPath, verStr->getCString());
    downloadPath = FileManager::splicePath(downloadPath, RMBundleMD5File);
    
    //(2) 保存地址
    std::string savePath = this->fullLocalResourcePath(RMBundleMD5File);
    
    //(3) 下载
    this->downloadFileType = kDownloadFileTypeBundleMd5File;
    std::string *userData = new std::string(RMMainModuleName);
    downloader->download(downloadPath,savePath,false,userData);
}

void ResourceManager::mergeMD5File()
{
    //(1) 获取md5.bundle
    JSONObject* md5BundleObj = JSONObject::createWithFile(this->fullLocalResourcePath(RMBundleMD5File));
    
    //(2) 合并且删除旧文件
    __Array* fileNameArray = md5BundleObj->allKeys();
    if (fileNameArray) {
        int count = fileNameArray->count();
        for (int i = 0; i < count; i ++) {
            std::string fileName = ((__String*)fileNameArray->getObjectAtIndex(i))->getCString();
            
            //更新md5
            jsonObjMd5->putString(fileName, md5BundleObj->getString(fileName));
            
            //删除旧文件
            std::string oldFilePath = this->fullLocalResourcePath(fileName);
            FileManager::removeFile(oldFilePath);
            
        }
    }
    
    //(3) 保存md5.global
    std::string json = jsonObjMd5->toString();
    std::string md5GlobalPath = this->fullLocalResourcePath(RMGlobalMD5File);
    FileManager::writeDataToFile((unsigned char*)json.c_str(), json.size(), md5GlobalPath);
    
    //(4) 设置新的local version
    this->saveVersion(this->bundleResourceVersion);
    
}

void ResourceManager::updateVersion()
{
    if (versionLatest) {
        std::string errorMsg = "版本已是最新,不需要更新";
        this->reportError(RMMainModuleName, kResourceManagerErrorTypeVersionIsLatest,errorMsg);
        return;
    }
    
    if (compareVersion(minProgramVersion,this->programVersion) == 1) {
        
        std::string errorMsg = "程序版本太低，请先更新程序";
        this->reportError(RMMainModuleName, kResourceManagerErrorTypeVersionIsLatest,errorMsg);
        return;
    }
    
    this->updateModule(RMMainModuleName);
}

int ResourceManager::checkModule(const std::string &moduleName)
{
    //(1)检查模块是否存在
    JSONObject* objModules = jsonObjConfig->getJSONObject("modules");
    
    if (!objModules->has(moduleName)) {
        __String* errorMsg = __String::createWithFormat("模块[%s]不存在",moduleName.c_str());
        this->reportError(moduleName, kResourceManagerErrorTypeNoSuchModule,errorMsg->getCString());
        return -1;
    }
    
    //(2)对比生成模型的下载文件列表
    
    __Array* downloadFileList = __Array::create();
    
    JSONArray* arrayModule = objModules->getJSONArray(moduleName);
    
    //比较md5，不同的则是要更新的
    int count = arrayModule->count();
    for (int i = 0; i < count; i++) {
        std::string fileName = arrayModule->getString(i);
        
        //检查文件是否已经更新到最新
        if (!this->isFileUpdated(fileName)) {
            downloadFileList->addObject(__String::create(fileName));
        }
    }
    downloadCache->setObject(downloadFileList, moduleName);
    
    CCLOG("模块[%s]有[%d]个文件待更新",moduleName.c_str(),downloadFileList->count());
    
    return downloadFileList->count();
}

void ResourceManager::updateModule(const std::string &moduleName)
{
    int fileNum = this->checkModule(moduleName);
    if (fileNum  ==  -1) {
        //表示检查版本时出错，错误回调已经在 checkModule 中进行
        return;
    }
    if (fileNum  ==  0) {
        //模块不需要更新
        return;
    }
    //将模块插在list头
    updatingModuleList->insertObject(__String::create(moduleName), 0);
    
    if (!moduleUpdating) {
        this->downloadModuleFile();
    }
}

void ResourceManager::downloadVersionFile()
{
    //从服务器下载版本描述文件
    //(1) 下载地址
    std::string downloadPath = FileManager::splicePath(this->rootUrl, RMVersionFile);
    
    //(2) 保存地址
    std::string savePath = this->fullLocalResourcePath(RMVersionFile);
    
    //(3) 下载
    this->downloadFileType = kDownloadFileTypeVersionFile;
    std::string *userData = new std::string(RMMainModuleName);
    downloader->download(downloadPath,savePath,false,userData);
}

void ResourceManager::downloadConfigFile()
{
    //从服务器下载资源配置文件
    //(1) 下载地址
    std::string downloadPath = FileManager::splicePath(this->rootUrl, RMConfigFile);
    
    //(2) 保存地址
    std::string savePath = this->fullLocalResourcePath(RMConfigFile);
    
    //(3) 下载
    this->downloadFileType = kDownloadFileTypeConfigFile;
    std::string *userData = new std::string(RMMainModuleName);
    downloader->download(downloadPath,savePath,false,userData);
}



void ResourceManager::downloadModuleFile()
{
    //(1)检查待更新模块列表是否为空
    if (updatingModuleList->count() == 0) {
        return;
    }
    
    //(2)取待更新模块列表中第一个模块
    std::string moduleName = ((__String*)updatingModuleList->getObjectAtIndex(0))->getCString();
    
    //(3)检查模块缓存的下载文件列表
    __Array* downloadFileList=(__Array*)downloadCache->objectForKey(moduleName);
    if (downloadFileList == NULL||downloadFileList->count() == 0) {
        return;
    }
    
    __String* filePath = (__String*)downloadFileList->getObjectAtIndex(0);
    
    //(4)检查文件是否已经最新（文件被多个模块共享的情况下，可能已经被其它模块更新）
    if (this->isFileUpdated(filePath->getCString())) {
        CCLOG("文件[%s]已被其它模块更新",filePath->getCString());
        this->processAfterSingleModleFileDownload(moduleName);
        return;
    }
    
    moduleUpdating = true;
    
    //(5)按顺序下载该模块的文件
    
    CCLOG("下载模块[%s]文件[%s]",moduleName.c_str(),filePath->getCString());
    
    //(5-1) 下载地址
    std::string downloadPath=FileManager::splicePath(this->rootUrl, RMServerResourceDirectory);
    downloadPath=FileManager::splicePath(downloadPath, filePath->getCString());
    
    //(5-2) 保存地址
    std::string savePath=this->fullLocalResourcePath(filePath->getCString());
    
    //(5-3) 下载
    this->downloadFileType = kDownloadFileTypeModule;
    
    std::string *userData = new std::string(moduleName);
    downloader->download(downloadPath,savePath,false,userData);
    
}

//void ResourceManager::onDownloadEvent(HttpDownloader *downloader, DownloadEvent *event)
//{
//    __String* moduleName = (__String*)event->getTask()->getUserdata();
//
//    if (event->getType() == kDownloadEventTypeSuccess) {
//        //文件下载成功
//        if (this->downloadFileType == kDownloadFileTypeBundleMd5File) {
//
//            //Bundler资源md5文件
//            this->mergeMD5File();
//            //下载 版本描述文件
//            this->downloadVersionFile();
//
//        }else if (this->downloadFileType == kDownloadFileTypeVersionFile) {
//
//            //版本描述文件
//            this->processAfterVersionFileDownload();
//
//        }else if (this->downloadFileType == kDownloadFileTypeConfigFile) {
//
//            //资源配置文件
//            this->processAfterConfigFileDownload();
//
//        }else{
//
//            //模块文件
//            this->processAfterSingleModleFileDownload(moduleName->getCString());
//
//        }
//    }else if (event->getType() == kDownloadEventTypeFailure){
//
//        moduleUpdating = false;
//
//        //文件下载出错
//        CCLOG("error:%s",event->getErrorMsg().c_str());
//        this->reportError(moduleName->getCString(),kResourceManagerErrorTypeDownloadFailure,event->getErrorMsg());
//
//    }
//}

#pragma mark - HttpDownloaderDelegate
void ResourceManager::onError(void *userData, HttpDownloaderErrorCode errorCode)
{
    std::string* moduleName = (std::string*)userData;
    moduleUpdating = false;
    
    this->reportError(*moduleName,kResourceManagerErrorTypeDownloadFailure, "");
    delete moduleName;
    moduleName = nullptr;
    
}

//文件下载成功
void ResourceManager::onSuccess(void *userData)
{
    std::string* moduleName = (std::string*)userData;
    if (this->downloadFileType == kDownloadFileTypeBundleMd5File) {
        
        //Bundler资源md5文件
        this->mergeMD5File();
        //下载 版本描述文件
        this->downloadVersionFile();
        
    }else if (this->downloadFileType == kDownloadFileTypeVersionFile) {
        
        //版本描述文件
        this->processAfterVersionFileDownload();
        
    }else if (this->downloadFileType == kDownloadFileTypeConfigFile) {
        
        //资源配置文件
        this->processAfterConfigFileDownload();
        
    }else{
        
        //模块文件
        this->processAfterSingleModleFileDownload(*moduleName);
        
    }
    delete moduleName;
    moduleName = nullptr;
}

#pragma mark -

void ResourceManager::processAfterVersionFileDownload()
{
    //(1) 取版本描述文件内配置
    JSONObject* versionObj = JSONObject::createWithFile(RMVersionFile);
    
    serverVersion = versionObj->getNumber(RMVersionKey);
    minProgramVersion = versionObj->getNumber(RMMinProgramVersionKey);
    programUpdateURL = versionObj->getString(RMProgramUpdateURLKey);
    
    //(2) 检查资源配置的版本
    float configVersion = 0;
    if (jsonObjConfig->has(RMVersionKey)) {
        configVersion = jsonObjConfig->getNumber(RMVersionKey);
    }
    
    if (compareVersion(serverVersion,configVersion) == 1) {
        
        //资源配置版本过低，先更新
        this->downloadConfigFile();
        
    }else{
        
        //检查主模块资源
        this->checkMainModule();
    }
    
}

void ResourceManager::processAfterConfigFileDownload()
{
    //TODO 最新资源配置下载完成，处理被删除的文件
    
    //读取最新资源配置信息
    std::string configFilePath = this->fullLocalResourcePath(RMConfigFile);
    CC_SAFE_RELEASE_NULL(jsonObjConfig);
    jsonObjConfig = JSONObject::createWithFile(configFilePath);
    CC_SAFE_RETAIN(jsonObjConfig);
    
    this->checkMainModule();
}

void ResourceManager::checkMainModule()
{
    
    //主模块需要更新的文件数量
    int fileNum = this->checkModule(RMMainModuleName);
    
    if (fileNum == 0) {
        this->saveVersion(serverVersion);
    }
    
    //是否需要更新程序
    bool needUpdateProgram = (compareVersion(minProgramVersion,this->programVersion) == 1);
    
    //版本是否最新
    versionLatest = (compareVersion(serverVersion,this->localVersion) == 0)&&(fileNum == 0)&&(!needUpdateProgram);
    
    this->callbackVersionCheckCompleted(!versionLatest,needUpdateProgram,needUpdateProgram?this->programUpdateURL:"");
    
}

void ResourceManager::processAfterSingleModleFileDownload(const std::string &moduleName)
{
    bool isMainModule = (strcmp(moduleName.c_str(), RMMainModuleName) == 0);
    
    __Array* downloadFileList = (__Array*)downloadCache->objectForKey(moduleName);
    std::string filePath = ((__String*)downloadFileList->getObjectAtIndex(0))->getCString();
    downloadFileList->getObjectAtIndex(0);
    CCLOG("模块[%s]成功更新了一个文件,还有[%d]个文件待更新",moduleName.c_str(),downloadFileList->count());
    
    //回调
    if (this->delegate) {
        this->delegate->onSingleFileUpdated(moduleName,filePath);
    }
    if (this->scriptDelegate) {
        __Array* params = __Array::create(__String::create(moduleName),__String::create(filePath),NULL);
        __Array* paramTypes = __Array::create(__String::create("__String"),__String::create("__String"),NULL);
        LuaUtil::executePeertableFunction(this->scriptDelegate, "onSingleFileUpdated", params, paramTypes, false);
    }
    
    
    //获取服务器上此文件的md5
    JSONArray* arrayFile = jsonObjConfig->getJSONObject("files")->getJSONArray(filePath);
    std::string md5Server = arrayFile->getString(0);
    
    //更新本地此文件的md5
    jsonObjMd5->putString(filePath, md5Server);
    globalMD5NeedFlush = true;
    
    //检查缓存列表
    if (downloadFileList->count() == 0) {
        
        CCLOG("模块[%s]更新完成",moduleName.c_str());
        //模块更新完成，从待更新模块列表中删除此模块
        this->removeModuleFromUpdatingList(moduleName);
        downloadCache->removeObjectForKey(moduleName);
        
        this->flush();
        
        //回调
        if (isMainModule) {
            
            this->saveVersion(serverVersion);
            versionLatest = true;
            
            if (this->delegate) {
                this->delegate->onVersionUpdated();
            }
            
            if (this->scriptDelegate) {
                LuaUtil::executePeertableFunction(this->scriptDelegate, "onVersionUpdated", NULL, NULL, false);
            }
            
            
        }else{
            if (this->delegate) {
                this->delegate->onModuleUpdated(moduleName);
            }
            if (this->scriptDelegate) {
                __Array* params = __Array::createWithObject(__String::create(moduleName));
                __Array* paramTypes = __Array::createWithObject(__String::create("__String"));
                LuaUtil::executePeertableFunction(this->scriptDelegate, "onModuleUpdated", params, paramTypes, false);
            }
        }
    }
    
    moduleUpdating = false;
    this->downloadModuleFile();
}

int ResourceManager::getVersionUpdateSize()
{
    return this->getModuleUpdateSize(RMMainModuleName);
}

int ResourceManager::getModuleUpdateSize(const std::string &moduleName)
{
    __Array* downloadFileList=(__Array*)downloadCache->objectForKey(moduleName);
    if (downloadFileList == NULL||downloadFileList->count() == 0) {
        return 0;
    }
    int size = 0;
    
    JSONObject* objFiles = jsonObjConfig->getJSONObject("files");
    
    int fileCount = downloadFileList->count();
    for (int i = 0; i < fileCount; i++) {
        __String* filePath = (__String*)downloadFileList->getObjectAtIndex(i);
        JSONArray* arrayFile = objFiles->getJSONArray(filePath->getCString());
        int fileSize = arrayFile->getNumber(1);
        size += fileSize;
    }
    
    return size;
}

void ResourceManager::flush()
{
    if (globalMD5NeedFlush) {
        globalMD5NeedFlush = false;
        
        std::string md5GlobalPath = this->fullLocalResourcePath(RMGlobalMD5File);
        std::string jsonStr = jsonObjMd5->toString();
        FileManager::writeDataToFile((const unsigned char*)jsonStr.c_str(),jsonStr.size(), md5GlobalPath);
    }
}

void ResourceManager::saveVersion(float version)
{
    localVersion = version;
    CCUserDefault::sharedUserDefault()->setFloatForKey(RMVersionKey, localVersion);
    CCUserDefault::sharedUserDefault()->flush();
}

const char* ResourceManager::fullLocalResourcePath(const std::string& filePath)
{
    std::string localResourcePath = FileManager::splicePath(CCFileUtils::getInstance()->getWritablePath(), RMLocalResourceDirectory);
    return FileManager::splicePath(localResourcePath, filePath);
}

void ResourceManager::reportError(const std::string &moduleName, ResourceManagerErrorType errorType, const std::string &errorMsg)
{
    if (this->delegate) {
        this->delegate->onErrorOccured(errorType,errorMsg.c_str());
    }
    if (this->scriptDelegate) {
        __Array* params = __Array::create(__Integer::create(errorType),__String::create(errorMsg),NULL);
        __Array* paramTypes = __Array::create(__String::create("__Integer"),__String::create("__String"),NULL);
        LuaUtil::executePeertableFunction(this->scriptDelegate, "onErrorOccured", params, paramTypes, false);
    }
}

void ResourceManager::copyFiles(const cocos2d::ValueVector &copyFileList)
{
    if (copyFileList.empty()) {
        CCLOG("copyFiles copyFileList is empty");
        return;
    }
    CCLOG("copyFiles:%ld",copyFileList.size());
    for (int i = 0; i < copyFileList.size(); i++) {
        std::string filePath = copyFileList[i].asString();
        long len = 0;
        //为兼容android  此处必须先获取全路径
        std::string fullPath = CCFileUtils::getInstance()->fullPathForFilename(filePath);
        unsigned char* fileData = CCFileUtils::getInstance()->getFileData(fullPath.c_str(), "rb", &len);
        CCLOG("fullPath:[%s]",fullPath.c_str());
        CCLOG("file len:[%lu]",len);
        FileManager::createDirectory(this->fullLocalResourcePath(filePath));
        FileManager::writeDataToFile(fileData , len , this->fullLocalResourcePath(filePath));
        delete [] fileData;
    }
    CCFileUtils::getInstance()->purgeCachedEntries();
}

void ResourceManager::removeModuleFromUpdatingList(const std::string &moduleName)
{
    int index = -1;
    for (int i = 0; i < updatingModuleList->count(); i++) {
        __String* tempModuleName = (__String*)updatingModuleList->getObjectAtIndex(i);
        if (strcmp(moduleName.c_str(), tempModuleName->getCString()) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        updatingModuleList->getObjectAtIndex(index);
    }
}

bool ResourceManager::isFileUpdated(const std::string &filePath)
{
    //获取服务器上此文件的md5
    JSONObject* objFiles = jsonObjConfig->getJSONObject("files");
    JSONArray* arrayFile = objFiles->getJSONArray(filePath);
    std::string md5Server = arrayFile->getString(0);
    
    //获取本地此文件的md5
    std::string md5Local;
    if (jsonObjMd5->has(filePath)) {
        md5Local = jsonObjMd5->getString(filePath);
    }
    
    return (strcmp(md5Server.c_str(), md5Local.c_str())==0);
}

void ResourceManager::callbackVersionCheckCompleted(bool hasUpdate, bool needUpdateProgram, const std::string &programUpdateURL)
{
    if (this->delegate) {
        this->delegate->onVersionCheckCompleted(hasUpdate,needUpdateProgram,programUpdateURL);
        
    }
    if (this->scriptDelegate) {
        __Array* params = __Array::create(CCBool::create(hasUpdate),CCBool::create(hasUpdate),__String::create(programUpdateURL),NULL);
        __Array* paramTypes = __Array::create(__String::create("CCBool"),__String::create("CCBool"),__String::create("__String"),NULL);
        LuaUtil::executePeertableFunction(this->scriptDelegate, "onVersionCheckCompleted", params, paramTypes, false);
    }
    
}

/***************************************** End *****************************************/
