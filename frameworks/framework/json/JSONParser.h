//
//  JSONParser.h
//  Framework
//
//  Created by wp_g4 on 13-3-1.
//
//

#ifndef __Framework__JSONParser__
#define __Framework__JSONParser__

#include <iostream>
#include "JSONElement.h"
#include "libjson/libjson.h"

/**
 ******************JSONParser******************
 * json 解析器
 */

class JSONParser {
    
private:
    
    static cocos2d::Ref* parseJSONNode(JSONNODE* jsonNode);
    
    static JSONObject* parseToJSONObject(JSONNODE* jsonNode);
    
    static JSONArray* parseToJSONArray(JSONNODE* jsonNode);
    
public:
    
    //将指定json字符串解析为对象，对象类型为JSONObject JSONArray二者之一
    static cocos2d::Ref* parseString(const std::string& jsonStr);
    
    //将指定json文件解析为对象，对象类型为JSONObject JSONArray二者之一
    static cocos2d::Ref* parseFile(const std::string& jsonFile);
    
};

#endif /* defined(__Framework__JSONParser__) */

