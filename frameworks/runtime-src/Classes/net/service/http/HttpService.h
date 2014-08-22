//
//  HttpService.h
//  Framework
//
//  Created by wp_g4 on 13-2-22.
//
//

#ifndef __Framework__HttpService__
#define __Framework__HttpService__

#include <iostream>
#include "framework.h"
#include "network/HttpClient.h"

class HttpService : public NetService {
    
public:
    
    bool init();
    
    CREATE_FUNC(HttpService);
    
    void sendMessage(NetRequest* request);
    
    //执行命令
    void executeCommand(const std::string& command, Ref* param);
    
    void onHttpRequestCompleted(cocos2d::network::HttpClient* client, cocos2d::network::HttpResponse* response);
    
    const char* replaceCallback(const std::string& oldStr);
    
    const char* convertUnicodeToUTF8(unsigned int unicode);
};

#endif /* defined(__Framework__HttpService__) */
