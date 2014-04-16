//
//  RegexUtil.h
//  The9Framework
//
//  Created by wp_g4 on 13-3-19.
//
//

#ifndef __The9Framework__RegexUtil__
#define __The9Framework__RegexUtil__

#include <iostream>
#include "cocos2d.h"

typedef const char* (cocos2d::Ref::*RegexUtilReplaceCallBack)(const std::string& oldStr);

class RegexUtil {
    
public:
    
    //查找str中第一个匹配正则表达式regex的子字符串 如果不存在，返回NULL
    static const char* search(const std::string& str,const std::string& regex);
    
    //用newStr替换str中的oldStr 返回替换的次数
    static int replaceAll(std::string& str,const std::string& oldStr,const std::string& newStr);
    
    //替换str中所有匹配正则表达式regex的子字符串，新字符串使用RegexUtilReplaceCallBack取得
    static int replaceAll(std::string& str,const std::string& regex,cocos2d::Ref* target,RegexUtilReplaceCallBack callback);
    
};

#endif /* defined(__The9Framework__RegexUtil__) */
