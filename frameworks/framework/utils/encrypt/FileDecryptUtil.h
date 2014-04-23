//
//  FileDecryptUtil.h
//  The9Framework
//
//  Created by wp_g4 on 13-12-12.
//
//

#ifndef __The9Framework__FileDecryptUtil__
#define __The9Framework__FileDecryptUtil__

#include <iostream>

class FileDecryptUtil {
    
public:
    
    //在解密之前必须先设置解密用的key,key必需符合3des规范，即24个字符
    static void setDecryptKey(const std::string& key);
    
    //解密
    static const char*  decrypt(const std::string& filePath);
    
};

#endif /* defined(__The9Framework__FileDecryptUtil__) */
