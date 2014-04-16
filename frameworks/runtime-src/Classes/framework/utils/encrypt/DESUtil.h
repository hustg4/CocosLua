//
//  DESUtil.h
//  The9Framework
//
//  Created by wp_g4 on 13-9-18.
//
//

#ifndef __The9Framework__DESUtil__
#define __The9Framework__DESUtil__

#include <iostream>

class DESUtil {
    
public:
    
    //返回值如果不为NULL，需要用户释放内存，free(p)
    static unsigned char* encrypt3(const char key[24],unsigned char* data,int inSize,int* outSize);
    
    //返回值如果不为NULL，需要用户释放内存，free(p)
    static unsigned char* decrypt3(const char key[24],unsigned char* data,int inSize,int* outSize);
    
};

#endif /* defined(__The9Framework__DESUtil__) */
