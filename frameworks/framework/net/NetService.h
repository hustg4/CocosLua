//
//  NetService.h
//  Framework
//
//  Created by wp_g4 on 13-2-21.
//
//

#ifndef __Framework__NetService__
#define __Framework__NetService__

#include <iostream>
#include "cocos2d.h"
#include "NetHandler.h"
#include "NetRequest.h"

/**
 ******************NetService******************
 * 网络服务基类
 * 网络服务是对一簇同类型消息的处理过程的封装
 */
class NetService : public cocos2d::Ref {
    
public:
    
    virtual ~NetService(){};
    
    //发送消息
    virtual void sendMessage(NetRequest* request) = 0;
    
    //执行命令
    virtual void executeCommand(const std::string& command, Ref* param) = 0;
    
};

#endif /* defined(__Framework__NetService__) */
