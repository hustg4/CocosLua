//
//  NetResponse.h
//  Framework
//
//  Created by wp_g4 on 13-3-4.
//
//

#ifndef __Framework__NetResponse__
#define __Framework__NetResponse__

#include <iostream>
#include "cocos2d.h"
#include "NetRequest.h"

/**
 ******************NetResponse******************
 * 网络响应
 */
class NetResponse : public cocos2d::Ref{
    
public:
    
    virtual bool init();
    
    virtual ~NetResponse();
    
    //创建一个空的网络响应
    CREATE_FUNC(NetResponse);
    
    //根据指定的id、包体和对应的网络请求创建网络响应
    static NetResponse* create(const std::string& protocolID,JSONObject* body,NetRequest* request=NULL);
    
    //设置和获取网络响应的id
    CC_SYNTHESIZE_PASS_BY_REF(std:: string, protocolID, ProtocolID);
    
    //设置和获取网络响应的包体
    CC_SYNTHESIZE_RETAIN(JSONObject*, body, Body);
    
    //设置和获取网络响应对应的网络请求
    CC_SYNTHESIZE_RETAIN(NetRequest*, request, Request);
    
};

#endif /* defined(__Framework__NetResponse__) */
