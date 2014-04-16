//
//  NetHandler.h
//  The9Framework
//
//  Created by wp_g4 on 13-2-21.
//
//

#ifndef __The9Framework__NetHandler__
#define __The9Framework__NetHandler__

#include <iostream>
#include "cocos2d.h"
#include "NetResponse.h"

/**
 ******************NetHandler******************
 * 网络消息处理器
 * 消息处理器用于处理消息
 */
class NetHandler : public cocos2d::Ref {
    
public:
    
    CREATE_FUNC(NetHandler);
    
    bool init();
    
    virtual ~NetHandler();
    
    //处理网络成功的消息
    virtual void handleSuccessfulMessage(NetResponse* response);
    
    //处理网络失败的消息
    virtual void handleFailedMessage(NetResponse* response);
    
};

#endif /* defined(__The9Framework__NetHandler__) */
