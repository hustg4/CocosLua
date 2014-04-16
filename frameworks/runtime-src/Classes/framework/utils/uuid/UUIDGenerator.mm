//
//  UUIDGenerator.cpp
//  quiz
//
//  Created by wp_g4 on 13-11-25.
//
//

#include "UUIDGenerator.h"

const char* UUIDGenerator::generate()
{
    CFUUIDRef puuid = CFUUIDCreate(nil);
    CFStringRef uuidstr = CFUUIDCreateString(nil, puuid);
    NSString* res = (NSString*)CFStringCreateCopy(nil, uuidstr);
    CFRelease(puuid);
    CFRelease(uuidstr);
    return [res UTF8String];
}