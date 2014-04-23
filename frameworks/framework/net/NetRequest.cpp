//
//  NetRequest.cpp
//  The9Framework
//
//  Created by wp_g4 on 13-2-23.
//
//

#include "NetRequest.h"

bool NetRequest::init()
{
    return true;
}

NetRequest* NetRequest::create(const std::string &protocolID, JSONObject *body)
{
    NetRequest* request=NetRequest::create();
    request->setProtocolID(protocolID);
    request->setBody(body);
    return request;
}

NetRequest::~NetRequest()
{
    CC_SAFE_RELEASE_NULL(body);
    CC_SAFE_RELEASE_NULL(configInfo);
}

