//
//  FileDecryptUtil.cpp
//  The9Framework
//
//  Created by wp_g4 on 13-12-12.
//
//

#include "FileDecryptUtil.h"
#include "cocos2d.h"
#include "DESUtil.h"

USING_NS_CC;

#define DefaultDecryptKey "aaaaaaaabbbbbbbbcccccccc"

static std::string decryptKey;

void FileDecryptUtil::setDecryptKey(const std::string &key)
{
    decryptKey = key;
}

const char* FileDecryptUtil::decrypt(const std::string &filePath)
{
    std::string key = decryptKey;
    if (key.size() == 0) {
        key = DefaultDecryptKey;
    }
    
    //取数据
    long size = 0;
    //为兼容android  此处必须先获取全路径
    std::string fullPath = CCFileUtils::getInstance()->fullPathForFilename(filePath.c_str());
    unsigned char* data = CCFileUtils::getInstance()->getFileData(fullPath.c_str(), "rb", &size);
    
    //解密
    int outSize = 0;
    unsigned char* decryptData = DESUtil::decrypt3(key.c_str(), data, size, &outSize);
    __String* str = __String::createWithData(decryptData, outSize);
    
    //释放内存
    delete [] data;
    free(decryptData);
    
    return str->getCString();
}
