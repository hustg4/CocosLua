//
//  NetHandler.cpp
//  Framework
//
//  Created by wp_g4 on 13-2-21.
//
//

#include "NetHandler.h"
#include "LuaUtil.h"

using namespace cocos2d;

bool NetHandler::init()
{
    return true;
}

NetHandler::~NetHandler()
{
    
}

void NetHandler::handleSuccessfulMessage(NetResponse *response)
{
    __Array* params = __Array::createWithObject(response);
    __Array* paramTypes = __Array::createWithObject(__String::create("NetResponse"));
    LuaUtil::executePeertableFunction(this, "handleSuccessfulMessage", params,paramTypes,false);
}

void NetHandler::handleFailedMessage(NetResponse *response)
{
    __Array* params = __Array::createWithObject(response);
    __Array* paramTypes = __Array::createWithObject(__String::create("NetResponse"));
    LuaUtil::executePeertableFunction(this, "handleFailedMessage", params,paramTypes,false);
}
