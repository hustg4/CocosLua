//
//  Base64Util.cpp
//  Framework
//
//  Created by wp_g4 on 13-7-18.
//
//

#include "Base64Util.h"
#include "Base64.h"
#include "cocos2d.h"

using namespace cocos2d;

const char* Base64Util::encode(const std::string &str)
{
    std::string res;
    CBase64::Encode((unsigned char*)str.c_str(), str.length(), res);
    return __String::create(res)->getCString();
}


const char* Base64Util::decode(const std::string &str)
{
    unsigned char* pOut = (unsigned char*)malloc(str.length());
    unsigned long size = str.length();
    CBase64::Decode(str, pOut, &size);
    std::string res;
    res.append(pOut, pOut+size);
    free(pOut);
    return __String::create(res)->getCString();
}

const char* Base64Util::encode(const unsigned char *pIn, unsigned long size)
{
    std::string res;
    CBase64::Encode(pIn, size, res);
    return __String::create(res)->getCString();
}

unsigned char* Base64Util::decode(const std::string &str, unsigned long *size)
{
    unsigned char* pOut = (unsigned char*)malloc(str.length());
    *size = str.length();
    CBase64::Decode(str, pOut, size);
    return pOut;
}
