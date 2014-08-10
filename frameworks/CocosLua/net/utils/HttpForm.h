//
//  HttpForm.h
//  Framework
//
//  Created by wp_g4 on 13-3-5.
//
//

#ifndef __Framework__HttpForm__
#define __Framework__HttpForm__

#include <iostream>
#include "cocos2d.h"

class HttpForm : public cocos2d::Ref{
    
    cocos2d::__Dictionary* paramDict;
    
    char dec2hexChar(short int n);
    
    short int hexChar2dec(char c);
    
    const char* deescapeURL(const std::string &URL);
    
    const char* escapeURL(const std::string &URL);
    
public:
    
    ~HttpForm();
    
    bool init();
    
    CREATE_FUNC(HttpForm);
    
    //添加参数
    void putParam(const std::string& paramName,const std::string& paramValue);
    
    //获取参数
    const char* getParam(const std::string& paramName);
    
    //移除参数
    void removeParam(const std::string& paramName);
    
    //转换为字符串
    const char* toString();
    
};

#endif /* defined(__Framework__HttpForm__) */
