//
//  NetStatusUtil.h
//  The9Framework
//
//  Created by wp_g4 on 13-10-11.
//
//

#ifndef __The9Framework__NetStatusUtil__
#define __The9Framework__NetStatusUtil__

#include <iostream>

enum NetStatus {
    kNetStatusNotReachable = 0,         // 无网络
    kNetStatusReachableViaWiFi = 1,     // wifi
    kNetStatusReachableViaWWAN = 2      // 2G/3G
};


/**
 * 检查网络状态，具体实现分ios版和android版
 */

class NetStatusUtil {
    
public:
    
    static NetStatus checkNetStatus();
    
};

#endif /* defined(__The9Framework__NetStatusUtil__) */
