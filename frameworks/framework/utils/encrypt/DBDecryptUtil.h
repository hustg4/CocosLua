//
//  DBDecryptUtil.h
//  The9Framework
//
//  Created by wp_g4 on 13-11-19.
//
//

#ifndef __The9Framework__DBDecryptUtil__
#define __The9Framework__DBDecryptUtil__

#include <iostream>

class DBDecryptUtil {
    
public:
    
    //在解密之前必须先设置解密用的key,key必需符合3des规范，即24个字符
    static void setDecryptKey(const std::string& key);
    
    //解密，先反base64(使用Base64Util),再解密(使用DESUtil)操作，与EncryptSQLiteTool对应
    static const char* decrypt(const std::string& text);
    
};

#endif /* defined(__The9Framework__DBDecryptUtil__) */
