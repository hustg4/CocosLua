//
//  JSONFormatter.h
//  Framework
//
//  Created by wp_g4 on 13-3-1.
//
//

#ifndef __Framework__JSONFormatter__
#define __Framework__JSONFormatter__

#include <iostream>
#include "JSONElement.h"
#include "libjson/libjson.h"

/**
 ******************JSONFormatter******************
 * json 格式化器
 */

class JSONFormatter {
    
private:
    
    static JSONNODE* formatToJSONNode(cocos2d::Ref* object);
    
    static JSONNODE* formatJSONObjectToJSONNode(JSONObject* jsonObject);
    
    static JSONNODE* formatJSONArrayToJSONNode(JSONArray* jsonArray);
    
public:
    
    //将指定对象格式化为json字符串，对象的类型必需为JSONObject JSONArray二者之一
    static const char* format(cocos2d::Ref* object,bool pretty);
    
};

#endif /* defined(__Framework__JSONFormatter__) */
