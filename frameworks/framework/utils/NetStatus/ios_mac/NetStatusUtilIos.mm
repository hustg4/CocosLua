//
//  NetStatusUtilIos.cpp
//  The9Framework
//
//  Created by wp_g4 on 13-10-11.
//
//

#include "NetStatusUtil.h"
#import "Reachability.h"

NetStatus NetStatusUtil::checkNetStatus()
{
    Reachability *reachability = [Reachability reachabilityWithHostName:@"www.apple.com"];
    //注：NetStatus与NetworkStatus的定义必须一致
    return (NetStatus)[reachability currentReachabilityStatus];
}