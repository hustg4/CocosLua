//
//  SocketService.cpp
//  Framework
//
//  Created by wp_g4 on 13-2-22.
//
//

#include "SocketService.h"

using namespace cocos2d;

bool SocketService::init()
{
    return true;
}

void SocketService::sendMessage(NetRequest *request)
{
    //socket从这里发消息
    CCString* msgStr=(CCString*)request->getBody();
    CCLOG("socket发出包:%s",msgStr->getCString());
    NetResponse* response=NetResponse::create(request->getProtocolID(), request->getBody(),request);
    NetCenter::sharedNetCenter()->dispatchFailedMessage(response);
}

void SocketService::executeCommand(const std::string &command, cocos2d::Ref *param)
{
}