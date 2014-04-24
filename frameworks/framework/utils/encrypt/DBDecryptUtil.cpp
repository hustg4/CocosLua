//
//  DBDecryptUtil.cpp
//  Framework
//
//  Created by wp_g4 on 13-11-19.
//
//

#include "DBDecryptUtil.h"
#include "Base64Util.h"
#include "DESUtil.h"
#include "cocos2d.h"

USING_NS_CC;

#define DefaultDecryptKey "aaaaaaaabbbbbbbbcccccccc"

static std::string decryptKey;


void DBDecryptUtil::setDecryptKey(const std::string &key)
{
    decryptKey = key;
}

const char* DBDecryptUtil::decrypt(const std::string &text)
{
    std::string key = decryptKey;
    if (key.size() == 0) {
        key = DefaultDecryptKey;
    }
    unsigned long size = 0;
    unsigned char* base64Res = Base64Util::decode(text, &size);
    
    int desSize = 0;
    unsigned char* desDecode = DESUtil::decrypt3(key.c_str(), base64Res, size, &desSize);
    std::string res;
    res.append(desDecode, desDecode+desSize);
    free(desDecode);
    free(base64Res);
    return __String::create(res)->getCString();
}