//
//  DESUtil.cpp
//  The9Framework
//
//  Created by wp_g4 on 13-9-18.
//
//

#include "DESUtil.h"
#include "des.h"

unsigned char* DESUtil::encrypt3(const char *key, unsigned char *data, int inSize, int *outSize)
{
    DES des;
    *outSize = des.extend(inSize);
    unsigned char* buffer = (unsigned char*)malloc(*outSize);
    memcpy(buffer, data, inSize);
    des.encrypt3((unsigned char*)key, buffer, inSize);
    
    return buffer;
}

unsigned char* DESUtil::decrypt3(const char *key, unsigned char *data, int inSize, int *outSize)
{
    
    unsigned char* buffer = (unsigned char*)malloc(inSize);
    memcpy(buffer, data, inSize);
    
    DES des;
    des.decrypt3((unsigned char*)key, buffer, inSize, outSize);
    
    return buffer;
}
