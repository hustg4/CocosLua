//
//  NetRequest.h
//  Framework
//
//  Created by wp_g4 on 13-2-23.
//
//

#ifndef __Framework__NetRequest__
#define __Framework__NetRequest__

#include <iostream>
#include "cocos2d.h"
#include "../json/JSONElement.h"

/**
 ******************NetRequest******************
 * 网络请求
 */
class NetRequest : public cocos2d::Ref{
    
public:
    
    virtual bool init();

	NetRequest();
    
    virtual ~NetRequest();
    
    //创建一个空的网络请求
    CREATE_FUNC(NetRequest);
    
    //根据指定的id和包体创建网络请求
    static NetRequest* create(const std::string& protocolID,JSONObject* body);
    
    //设置和获取网络请求的id
    CC_SYNTHESIZE_PASS_BY_REF(std:: string, protocolID, ProtocolID);
    
    //设置和获取网络请求的包体
    CC_SYNTHESIZE_RETAIN(JSONObject*, body, Body);
    
    //设置和获取配置信息
    CC_SYNTHESIZE_RETAIN(JSONObject*, configInfo, ConfigInfo);
    
};

#endif /* defined(__Framework__NetRequest__) */
