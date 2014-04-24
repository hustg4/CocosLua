//
//  NetCenter.h
//  Framework
//
//  Created by wp_g4 on 13-2-21.
//
//

#ifndef __Framework__NetCenter__
#define __Framework__NetCenter__

#include <iostream>
#include "cocos2d.h"
#include "NetService.h"
#include "NetHandler.h"
#include "NetProtocol.h"
#include "NetRequest.h"
#include "NetResponse.h"
#include "NetFilter.h"

/**
 ******************NetCenter******************
 * 网络中心
 * 网络框架的核心，网络框架定位在业务逻辑层和网络服务层之间，向上提供注册协议、发送消息的接口，向下提供注册网络服务、分发消息的接口
 */
class NetCenter : public cocos2d::Ref{
    
public:
    
    ~NetCenter();
    
    //返回NetCenter的唯一实例
    static NetCenter* sharedNetCenter();
    
    //往NetCenter中添加"网络服务"，service的serviceID必需唯一
    void addNetService(const std::string& serviceID,NetService* service);
    
    //从NetCenter中删除指定的"网络服务"
    void removeNetService(const std::string& serviceID);
    
    //往NetCenter中添加协议，协议有三要素 protocolID（必需唯一）,serviceID（必需是添加到NetCenter中的"网络服务"ID）,handler（不能为NULL）
    void addNetProtocol(const std::string& protocolID,const std::string& serviceID,NetHandler* handler);
    
    //往NetCenter中添加协议
    void addNetProtocol(NetProtocol* protocol);
    
    //移除NetCenter中指定消息id的协议
    void removeNetProtocol(const std::string& protocolID);
    
    //移除NetCenter中所有指定"网络服务"的协议
    void removeNetProtocolForNetService(const std::string& serviceID);
    
    //添加过滤器
    void addNetFilter(NetFilter* filter);
    
    //移除过滤器
    void removeNetFilter(NetFilter* filter);
    
    //移除所有过滤器
    void removeAllNetFilters();
    
    //发送消息，此接口供游戏业务层发送消息使用
    void sendMessage(NetRequest* request);
    
    //分发成功消息，此接口供各"网络服务"分发收到的网络消息使用
    void dispatchSuccessfulMessage(NetResponse* response);
    
    //分发失败消息，此接口供各"网络服务"分发收到的网络消息使用
    void dispatchFailedMessage(NetResponse* response);
    
    //发送命令
    void sendCommand(const std::string& serviceID,const std::string& command,cocos2d::Ref* param);
    
private:
    
    cocos2d::__Dictionary* netServiceDict;      //网络服务集合
    
    cocos2d::__Dictionary* netProtocolDict;     //协议集合
    
    cocos2d::__Array* netFilterChain;           //消息过滤链
    
    NetCenter();

};

#endif /* defined(__Framework__NetCenter__) */
