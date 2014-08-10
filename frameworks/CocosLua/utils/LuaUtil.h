//
//  LuaUtil.h
//  Framework
//
//  Created by wp_g4 on 13-3-13.
//
//

#ifndef __Framework__LuaUtil__
#define __Framework__LuaUtil__

#include <iostream>
#include "cocos2d.h"

class LuaUtil {
    
public:
    
    //获取包路径
    static const char* getPackagePath();
    
    //设置lua包路径
    static void setPackagePath(std::vector<std::string> paths);
    
    //执行脚本文件
    static void executeScriptFile(const std::string& filePath);
    
    //设置table的字段
    static void setTableFieid(const std::string& tableName,const std::string& key,cocos2d::Ref* value,const std::string& valueType);
    
    //运行table的function
    static void* executeTableFunction(const std::string& tableName,const std::string& functionName,cocos2d::__Array* params,cocos2d::__Array* paramTypes,bool hasReturnValue);
    
    //运行peertable的function
    static void* executePeertableFunction(cocos2d::Ref* userdata,const std::string& functionName,cocos2d::__Array* params,cocos2d::__Array* paramTypes,bool hasReturnValue);
    
private:
    
    //设置包路径
    static void setPackagePath(const std::string& path);
    
    //判断一个userdata是否有peertable
    static bool hasPeertable(void* userdata);
    
    //判断一个userdata的peertable是否有指定名称的function
    static bool hasFunction(void* userdata,const std::string& functionName);
    
    //运行function (执行此方法前保证function和self参数已入栈)
    static void* executeFunction(cocos2d::__Array* params,cocos2d::__Array* paramTypes,bool hasReturnValue);
    
};

#endif /* defined(__Framework__LuaUtil__) */
