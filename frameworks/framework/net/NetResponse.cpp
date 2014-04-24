//
//  NetResponse.cpp
//  Framework
//
//  Created by wp_g4 on 13-3-4.
//
//

#include "NetResponse.h"

bool NetResponse::init()
{
    return true;
}

NetResponse* NetResponse::create(const std::string &protocolID, JSONObject *body,NetRequest* request)
{
    NetResponse* response=NetResponse::create();
    response->setProtocolID(protocolID);
    response->setBody(body);
    response->setRequest(request);
    return response;
}

NetResponse::~NetResponse()
{
    CC_SAFE_RELEASE_NULL(body);
    CC_SAFE_RELEASE_NULL(request);
}