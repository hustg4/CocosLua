//
//  NetFilter.h
//  The9Framework
//
//  Created by wp_g4 on 13-6-26.
//
//

#ifndef __The9Framework__NetFilter__
#define __The9Framework__NetFilter__

#include "cocos2d.h"
#include "NetResponse.h"

class NetFilter : public cocos2d::Ref {
    
public:
    
    CREATE_FUNC(NetFilter);
    
    bool init();
    
    virtual ~NetFilter();
    
    //处理网络成功的消息
    virtual NetResponse* filterSuccessfulMessage(NetResponse* response);
    
    //处理网络失败的消息
    virtual NetResponse* filterFailedMessage(NetResponse* response);

};

#endif /* defined(__The9Framework__NetFilter__) */
