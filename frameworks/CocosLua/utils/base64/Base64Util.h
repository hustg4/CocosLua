//
//  Base64Util.h
//  Framework
//
//  Created by wp_g4 on 13-7-18.
//
//

#ifndef __Framework__Base64Util__
#define __Framework__Base64Util__

#include <iostream>

class Base64Util {
    
public:
    
    //编码
    static const char* encode(const std::string& str);
    
    //解码
    static const char* decode(const std::string& str);
    
    //编码
    static const char* encode(const unsigned char* pIn,unsigned long size);
    
    //解码，返回值如果不为NULL，用户需要释放内存，free(p)
    static unsigned char* decode(const std::string& str,unsigned long* size);

};

#endif /* defined(__Framework__Base64Util__) */
