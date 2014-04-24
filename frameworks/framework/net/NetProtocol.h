//
//  NetProtocol.h
//  Framework
//
//  Created by wp_g4 on 13-3-2.
//
//

#ifndef __Framework__NetProtocol__
#define __Framework__NetProtocol__

#include <iostream>
#include "cocos2d.h"
#include "NetHandler.h"

/**
 ******************NetProtocol******************
 * 网络协议，对消息类型的封装，例如注册、登录为两个不同的消息类型，与二者所使用的“网络服务”无关
 */
class NetProtocol : public cocos2d::Ref{
    
public:
    
    bool init();
    
    ~NetProtocol();
    
    //创建一个空的“网络协议”
    CREATE_FUNC(NetProtocol);
    
    //创建指定消息ID，网络服务ID，处理器的“网络协议”
    static NetProtocol* create(const std::string& protocolID,const std::string& serviceID,NetHandler* handler);
    
    //设置和获取“网络协议”的消息ID
    CC_SYNTHESIZE_PASS_BY_REF(std::string, protocolID, ID);
    
    //设置和获取“网络协议”的网络服务ID
    CC_SYNTHESIZE_PASS_BY_REF(std::string, serviceID, ServiceID);
    
    //设置和获取“网络协议”的处理器
    CC_SYNTHESIZE_RETAIN(NetHandler*, handler, Handler)
    
};

#endif /* defined(__Framework__NetProtocol__) */
