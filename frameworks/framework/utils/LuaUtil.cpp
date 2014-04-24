//
//  LuaUtil.cpp
//  Framework
//
//  Created by wp_g4 on 13-3-13.
//
//

extern "C" {
#include "tolua++.h"
#include "tolua_fix.h"
}

#include "LuaUtil.h"
#include "CCLuaEngine.h"

using namespace cocos2d;

static std::string defaultPackagePath;

const char* LuaUtil::getPackagePath()
{
    LuaEngine* pEngine = LuaEngine::getInstance();
    lua_State* m_state=pEngine->getLuaStack()->getLuaState();
    lua_getglobal(m_state, "package");                                  /* L: package */
    lua_getfield(m_state, -1, "path");                /* get package.path, L: package path */
    std::string path =  lua_tostring(m_state, -1);
    lua_pop(m_state, 1);
    return __String::create(path)->getCString();
}

void LuaUtil::setPackagePath(std::vector<std::string> paths)
{
    if (defaultPackagePath.size()==0) {
        defaultPackagePath = LuaUtil::getPackagePath();
    }
    std::string path=defaultPackagePath;
    for (std::vector<std::string>::const_iterator iter = paths.begin(); iter != paths.end(); ++iter)
    {
        path.append(";");
        path.append(*iter);
        path.append("/?.lua");
    }
    LuaUtil::setPackagePath(path);
}

void LuaUtil::executeScriptFile(const std::string &filePath)
{
    LuaEngine* pEngine = LuaEngine::getInstance();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    
    unsigned long size = 0;
    unsigned char* buffer = CCFileUtils::getInstance()->getFileData(filePath.c_str(), "rb", &size);
    if (buffer) {
        tolua_dobuffer(pEngine->getLuaStack()->getLuaState(), (char*)buffer, size, (char*)buffer);
        delete [] buffer;
    }else{
        CCLog("can not get file data of %s", filePath.c_str());
    }
    
#else
    std::string path = CCFileUtils::getInstance()->fullPathForFilename(filePath.c_str());
    pEngine->executeScriptFile(path.c_str());
#endif
}

void LuaUtil::setTableFieid(const std::string &tableName, const std::string &key, cocos2d::Ref *value, const std::string &valueType)
{
    LuaEngine* pEngine = LuaEngine::getInstance();
    lua_State* m_state=pEngine->getLuaStack()->getLuaState();
    //    printf("setTableFieid [%s].[%s] start lua top:%d\n",tableName.c_str(),key.c_str(),lua_gettop(m_state));
    //tableName入栈
    lua_getglobal(m_state, tableName.c_str());
    //检查栈顶是不是table
    if (!lua_istable(m_state, -1)) {
        CCLOG("[LUA ERROR] name '%s' does not represent a Lua Table", tableName.c_str());
        lua_pop(m_state, 1);
        return;
    }
    //key入栈
    lua_pushstring(m_state, key.c_str());
    pEngine->getLuaStack()->pushObject(value, valueType.c_str());
    lua_settable(m_state, -3);
    lua_pop(m_state, 1);
    //    printf("setTableFieid [%s].[%s] end lua top:%d\n",tableName.c_str(),key.c_str(),lua_gettop(m_state));
}

//运行table的function
void* LuaUtil::executeTableFunction(const std::string& tableName,const std::string& functionName,cocos2d::__Array* params,cocos2d::__Array* paramTypes,bool hasReturnValue)
{
    LuaEngine* pEngine = LuaEngine::getInstance();
    lua_State* m_state=pEngine->getLuaStack()->getLuaState();
    
    //    printf("executeTableFunction [%s].[%s] start lua top:%d\n",tableName.c_str(),functionName.c_str(),lua_gettop(m_state));
    
    lua_getglobal(m_state, tableName.c_str());
    
    //检查栈顶是不是table
    if (!lua_istable(m_state, -1)) {
        CCLOG("[LUA ERROR] name '%s' does not represent a Lua Table", tableName.c_str());
        lua_pop(m_state, 1);
        return NULL;
    }
    
    //functionName入栈
    lua_pushstring(m_state, functionName.c_str());
    
    //从table中取function
    lua_gettable(m_state, -2);
    
    //检查栈顶是不是function
    if (!lua_isfunction(m_state, -1)) {
        CCLOG("[LUA ERROR] name '%s' does not represent a Lua function", functionName.c_str());
        lua_pop(m_state, 1);
        return NULL;
    }
    
    //table作为第一个参数入栈，保证lua使用table:function()调用方法时第一个参数self为table
    lua_pushvalue(m_state,-2);

    void* result = LuaUtil::executeFunction(params, paramTypes, hasReturnValue);
    
    //弹出table
    lua_pop(m_state, 1);
    
    //    printf("executeTableFunction [%s].[%s] end lua top:%d\n",tableName.c_str(),functionName.c_str(),lua_gettop(m_state));
    
    return result;
}

void* LuaUtil::executePeertableFunction(Ref* userdata, const std::string &functionName, cocos2d::__Array *params, cocos2d::__Array *paramTypes, bool hasReturnValue)
{
    LuaEngine* pEngine = LuaEngine::getInstance();
    lua_State* m_state=pEngine->getLuaStack()->getLuaState();
    
    if (!LuaUtil::hasFunction(userdata, functionName)) {  //如果userdata没有peertable或者peertable没有指定function则直接返回
        return NULL;
    }
//    printf("executePeertableFunction [%s] start lua top:%d\n",functionName.c_str(),lua_gettop(m_state));
    
    /* stack: userdata */
    tolua_pushusertype(m_state, userdata, "cc.Ref");
    
    //functionName入栈
    lua_pushstring(m_state, functionName.c_str());
    
    //从userdata中取function
    lua_gettable(m_state, -2);
    
    //userdata作为第一个参数入栈，保证lua使用userdata:function()调用方法时第一个参数self为userdata
    lua_pushvalue(m_state,-2);
    
    void* result = LuaUtil::executeFunction(params, paramTypes, hasReturnValue);
    
    //弹出userdata
    lua_pop(m_state, 1);
    
//    printf("executePeertableFunction [%s] end lua top:%d\n",functionName.c_str(),lua_gettop(m_state));
    
    return result;
}

//=========================以下为私有API=========================

void LuaUtil::setPackagePath(const std::string &path)
{
    LuaEngine* pEngine = LuaEngine::getInstance();
    lua_State* m_state=pEngine->getLuaStack()->getLuaState();
    lua_getglobal(m_state, "package");                          /* L: package */
    lua_pushstring(m_state, path.c_str());                      /* L: package newpath */
    lua_setfield(m_state, -2, "path");                          /* package.path = newpath, L: package */
    lua_pop(m_state, 1);                                        /* L: - */
}

bool LuaUtil::hasPeertable(void* userdata)
{
    LuaEngine* pEngine = LuaEngine::getInstance();
    lua_State* m_state=pEngine->getLuaStack()->getLuaState();
    
    //    printf("hasPeertable start lua top:%d\n",lua_gettop(m_state));
    
    bool flag = false;
    
    /* stack: userdata */
    tolua_pushusertype(m_state, userdata, "cc.Ref");
    
    lua_getfenv(m_state, -1);
    if (lua_rawequal(m_state, -1, TOLUA_NOPEER)) {
        flag = false;
    }else{
        flag = true;
    }
    lua_pop(m_state, 2);
    
    //    printf("hasPeertable end lua top:%d\n",lua_gettop(m_state));
    
    return flag;
}

bool LuaUtil::hasFunction(void *userdata, const std::string &functionName)
{
    
    if (!LuaUtil::hasPeertable(userdata)) {
        return false;
    }
    
    LuaEngine* pEngine = LuaEngine::getInstance();
    lua_State* m_state=pEngine->getLuaStack()->getLuaState();
    
//    printf("hasFunction [%s] start lua top:%d\n",functionName.c_str(),lua_gettop(m_state));
    
    /* stack: userdata */
    tolua_pushusertype(m_state, userdata, "cc.Ref");
    
    //获取peertable
    lua_getfenv(m_state, -1);
    
    //functionName入栈
    lua_pushstring(m_state, functionName.c_str());
    
    //从userdata中取function
    lua_gettable(m_state, -2);
    
    bool flag = lua_isfunction(m_state, -1);

    lua_pop(m_state, 3);
    
//    printf("hasFunction [%s] end lua top:%d\n",functionName.c_str(),lua_gettop(m_state));
    
    return flag;
}

void* LuaUtil::executeFunction(cocos2d::__Array *params, cocos2d::__Array *paramTypes, bool hasReturnValue)
{
    LuaEngine* pEngine = LuaEngine::getInstance();
    lua_State* m_state=pEngine->getLuaStack()->getLuaState();           /* L: ... func self */
    
    int traceback = 0;
    lua_getglobal(m_state, "__G__TRACKBACK__");                         /* L: ... func self G */
    if (!lua_isfunction(m_state, -1))
    {
        lua_pop(m_state, 1);                                            /* L: ... func self */
    }
    else
    {
        lua_insert(m_state, -3);                                        /* L: ... G func self */
        traceback = -3;
    }
    
    
    //参数入栈
    if (params!=NULL) {
        
        if (traceback != 0) {
            traceback -= params->count();
        }
        
        for (int i = 0; i < params->count(); i++) {
            Ref* param = params->getObjectAtIndex(i);
            const char* paramType = ((__String*)paramTypes->getObjectAtIndex(i))->getCString();
            //判断是否是基本类型
            if (strcmp(paramType, "CCBool") == 0) {
                
                bool boolValue = ((__Bool*)param)->getValue();
                lua_pushboolean(m_state, boolValue);
                
            }else if (strcmp(paramType, "CCInteger") == 0){
                
                int intValue = ((__Integer*)param)->getValue();
                lua_pushnumber(m_state, intValue);
                
            }else if (strcmp(paramType, "CCFloat") == 0){
                
                float floatValue = ((__Double*)param)->getValue();
                lua_pushnumber(m_state, floatValue);
                
            }else if (strcmp(paramType, "CCDouble") == 0){
                
                double doubleValue = ((__Double*)param)->getValue();
                lua_pushnumber(m_state, doubleValue);
                
            }else if (strcmp(paramType, "CCString") == 0){
                
                const char* strValue = ((__String*)param)->getCString();
                lua_pushstring(m_state, strValue);
                
            }else{
                
                pEngine->getLuaStack()->pushObject(param,paramType);
                
            }
        }
    }
    
    
    //调用function                        /* L: ... G func self arg1 arg2 ... argn */
    int error = lua_pcall(m_state, params!=NULL?params->count()+1:1, hasReturnValue?1:0, traceback);
    
    void* result = NULL;
    
    if (error){                         /* L: ... G error */
        
        if (traceback == 0) {
            const char* errorMsg = lua_tostring(m_state, -1);
            CCLOG("[LUA ERROR] %s",errorMsg);
        }
        lua_pop(m_state, 1); // pop error           /* L: ... G */
        
    }else{
        
        if (hasReturnValue) {           /* L: ... G result */
            
            if (lua_type(m_state, -1) == LUA_TBOOLEAN) {
                
                bool value = lua_toboolean(m_state, -1);
                result = CCBool::create(value);
                
            }else if (lua_type(m_state, -1) == LUA_TNUMBER) {
                
                double value = lua_tonumber(m_state, -1);
                result = CCDouble::create(value);
                
            }else if (lua_type(m_state, -1) == LUA_TSTRING) {
                
                const char* value = lua_tostring(m_state, -1);
                result = __String::create(value);
                
            }else{
                
                result = tolua_tousertype(m_state, -1, NULL);
                
            }
            lua_pop(m_state, 1);//pop result        /* L: ... G */
        }
        
    }
    
    //移除__G__TRACKBACK__
    if (traceback != 0) {
        lua_pop(m_state, 1);
    }
    
    return result;
}

