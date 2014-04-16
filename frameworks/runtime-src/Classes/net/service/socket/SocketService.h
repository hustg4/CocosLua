//
//  SocketService.h
//  The9Framework
//
//  Created by wp_g4 on 13-2-22.
//
//

#ifndef __The9Framework__SocketService__
#define __The9Framework__SocketService__

#include <iostream>
#include "the9framework.h"

class SocketService : public NetService{
    
public:
  
    bool init();
    
    CREATE_FUNC(SocketService);
    
    void sendMessage(NetRequest* request);
    
    //执行命令
    void executeCommand(const std::string& command, Ref* param) ;
    
};

#endif /* defined(__The9Framework__SocketService__) */
