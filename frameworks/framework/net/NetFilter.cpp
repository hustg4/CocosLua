//
//  NetFilter.cpp
//  Framework
//
//  Created by wp_g4 on 13-6-26.
//
//

#include "NetFilter.h"
#include "LuaUtil.h"

using namespace cocos2d;

bool NetFilter::init()
{
    return true;
}

NetFilter::~NetFilter()
{
    
}

NetResponse* NetFilter::filterSuccessfulMessage(NetResponse *response)
{
    __Array* params = __Array::createWithObject(response);
    __Array* paramTypes = __Array::createWithObject(__String::create("NetResponse"));
    response = (NetResponse*)LuaUtil::executePeertableFunction(this, "filterSuccessfulMessage", params,paramTypes,true);
    return response;
}

NetResponse* NetFilter::filterFailedMessage(NetResponse *response)
{
    __Array* params = __Array::createWithObject(response);
    __Array* paramTypes = __Array::createWithObject(__String::create("NetResponse"));
    response = (NetResponse*) LuaUtil::executePeertableFunction(this, "filterFailedMessage", params,paramTypes,true);
    return response;
}
