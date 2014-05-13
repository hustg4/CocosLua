#include "lua_framework_auto.hpp"
#include "JSONElement.h"
#include "GameScene.h"
#include "NetCenter.h"
#include "SQLite.h"
#include "Game.h"
#include "SceneManager.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_framework_JSONObject_getJSONArray(lua_State* tolua_S)
{
    int argc = 0;
    JSONObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONObject_getJSONArray'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        JSONArray* ret = cobj->getJSONArray(arg0);
        object_to_luaval<JSONArray>(tolua_S, "JSONArray",(JSONArray*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getJSONArray",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONObject_getJSONArray'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONObject_getString(lua_State* tolua_S)
{
    int argc = 0;
    JSONObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONObject_getString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        const char* ret = cobj->getString(arg0);
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONObject_getString'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONObject_putJSONObject(lua_State* tolua_S)
{
    int argc = 0;
    JSONObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONObject_putJSONObject'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        JSONObject* arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_object<JSONObject>(tolua_S, 3, "JSONObject",&arg1);
        if(!ok)
            return 0;
        cobj->putJSONObject(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "putJSONObject",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONObject_putJSONObject'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONObject_toLuaString(lua_State* tolua_S)
{
    int argc = 0;
    JSONObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONObject_toLuaString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->toLuaString();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "toLuaString",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONObject_toLuaString'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONObject_allKeys(lua_State* tolua_S)
{
    int argc = 0;
    JSONObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONObject_allKeys'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::__Array* ret = cobj->allKeys();
        object_to_luaval<cocos2d::__Array>(tolua_S, "cc.__Array",(cocos2d::__Array*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "allKeys",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONObject_allKeys'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONObject_getNumber(lua_State* tolua_S)
{
    int argc = 0;
    JSONObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONObject_getNumber'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        double ret = cobj->getNumber(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getNumber",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONObject_getNumber'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONObject_putBool(lua_State* tolua_S)
{
    int argc = 0;
    JSONObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONObject_putBool'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        bool arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->putBool(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "putBool",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONObject_putBool'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONObject_init(lua_State* tolua_S)
{
    int argc = 0;
    JSONObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONObject_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONObject_init'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONObject_toString(lua_State* tolua_S)
{
    int argc = 0;
    JSONObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONObject_toString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->toString();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "toString",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONObject_toString'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONObject_has(lua_State* tolua_S)
{
    int argc = 0;
    JSONObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONObject_has'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        bool ret = cobj->has(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "has",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONObject_has'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONObject_get(lua_State* tolua_S)
{
    int argc = 0;
    JSONObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONObject_get'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cocos2d::Ref* ret = cobj->get(arg0);
        object_to_luaval<cocos2d::Ref>(tolua_S, "cc.Ref",(cocos2d::Ref*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "get",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONObject_get'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONObject_getBool(lua_State* tolua_S)
{
    int argc = 0;
    JSONObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONObject_getBool'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        bool ret = cobj->getBool(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBool",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONObject_getBool'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONObject_toPrettyString(lua_State* tolua_S)
{
    int argc = 0;
    JSONObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONObject_toPrettyString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->toPrettyString();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "toPrettyString",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONObject_toPrettyString'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONObject_putString(lua_State* tolua_S)
{
    int argc = 0;
    JSONObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONObject_putString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_std_string(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->putString(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "putString",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONObject_putString'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONObject_put(lua_State* tolua_S)
{
    int argc = 0;
    JSONObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONObject_put'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        cocos2d::Ref* arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 3, "cc.Ref",&arg1);
        if(!ok)
            return 0;
        cobj->put(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "put",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONObject_put'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONObject_count(lua_State* tolua_S)
{
    int argc = 0;
    JSONObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONObject_count'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->count();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "count",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONObject_count'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONObject_getJSONObject(lua_State* tolua_S)
{
    int argc = 0;
    JSONObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONObject_getJSONObject'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        JSONObject* ret = cobj->getJSONObject(arg0);
        object_to_luaval<JSONObject>(tolua_S, "JSONObject",(JSONObject*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getJSONObject",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONObject_getJSONObject'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONObject_putJSONArray(lua_State* tolua_S)
{
    int argc = 0;
    JSONObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONObject_putJSONArray'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        JSONArray* arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_object<JSONArray>(tolua_S, 3, "JSONArray",&arg1);
        if(!ok)
            return 0;
        cobj->putJSONArray(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "putJSONArray",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONObject_putJSONArray'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONObject_putNumber(lua_State* tolua_S)
{
    int argc = 0;
    JSONObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONObject_putNumber'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        double arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->putNumber(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "putNumber",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONObject_putNumber'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONObject_remove(lua_State* tolua_S)
{
    int argc = 0;
    JSONObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONObject_remove'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->remove(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "remove",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONObject_remove'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONObject_removeAll(lua_State* tolua_S)
{
    int argc = 0;
    JSONObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONObject_removeAll'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeAll();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeAll",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONObject_removeAll'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONObject_createWithFile(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"JSONObject",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        JSONObject* ret = JSONObject::createWithFile(arg0);
        object_to_luaval<JSONObject>(tolua_S, "JSONObject",(JSONObject*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createWithFile",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONObject_createWithFile'.",&tolua_err);
#endif
    return 0;
}
int lua_framework_JSONObject_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"JSONObject",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        JSONObject* ret = JSONObject::create();
        object_to_luaval<JSONObject>(tolua_S, "JSONObject",(JSONObject*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONObject_create'.",&tolua_err);
#endif
    return 0;
}
int lua_framework_JSONObject_createWithString(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"JSONObject",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        JSONObject* ret = JSONObject::createWithString(arg0);
        object_to_luaval<JSONObject>(tolua_S, "JSONObject",(JSONObject*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createWithString",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONObject_createWithString'.",&tolua_err);
#endif
    return 0;
}
int lua_framework_JSONObject_constructor(lua_State* tolua_S)
{
    int argc = 0;
    JSONObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new JSONObject();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"JSONObject");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "JSONObject",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONObject_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_framework_JSONObject_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (JSONObject)");
    return 0;
}

int lua_register_framework_JSONObject(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"JSONObject");
    tolua_cclass(tolua_S,"JSONObject","JSONObject","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"JSONObject");
        tolua_function(tolua_S,"getJSONArray",lua_framework_JSONObject_getJSONArray);
        tolua_function(tolua_S,"getString",lua_framework_JSONObject_getString);
        tolua_function(tolua_S,"putJSONObject",lua_framework_JSONObject_putJSONObject);
        tolua_function(tolua_S,"toLuaString",lua_framework_JSONObject_toLuaString);
        tolua_function(tolua_S,"allKeys",lua_framework_JSONObject_allKeys);
        tolua_function(tolua_S,"getNumber",lua_framework_JSONObject_getNumber);
        tolua_function(tolua_S,"putBool",lua_framework_JSONObject_putBool);
        tolua_function(tolua_S,"init",lua_framework_JSONObject_init);
        tolua_function(tolua_S,"toString",lua_framework_JSONObject_toString);
        tolua_function(tolua_S,"has",lua_framework_JSONObject_has);
        tolua_function(tolua_S,"get",lua_framework_JSONObject_get);
        tolua_function(tolua_S,"getBool",lua_framework_JSONObject_getBool);
        tolua_function(tolua_S,"toPrettyString",lua_framework_JSONObject_toPrettyString);
        tolua_function(tolua_S,"putString",lua_framework_JSONObject_putString);
        tolua_function(tolua_S,"put",lua_framework_JSONObject_put);
        tolua_function(tolua_S,"count",lua_framework_JSONObject_count);
        tolua_function(tolua_S,"getJSONObject",lua_framework_JSONObject_getJSONObject);
        tolua_function(tolua_S,"putJSONArray",lua_framework_JSONObject_putJSONArray);
        tolua_function(tolua_S,"putNumber",lua_framework_JSONObject_putNumber);
        tolua_function(tolua_S,"remove",lua_framework_JSONObject_remove);
        tolua_function(tolua_S,"removeAll",lua_framework_JSONObject_removeAll);
        tolua_function(tolua_S,"new",lua_framework_JSONObject_constructor);
        tolua_function(tolua_S,"createWithFile", lua_framework_JSONObject_createWithFile);
        tolua_function(tolua_S,"create", lua_framework_JSONObject_create);
        tolua_function(tolua_S,"createWithString", lua_framework_JSONObject_createWithString);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(JSONObject).name();
    g_luaType[typeName] = "JSONObject";
    g_typeCast["JSONObject"] = "JSONObject";
    return 1;
}

int lua_framework_JSONArray_getJSONArray(lua_State* tolua_S)
{
    int argc = 0;
    JSONArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONArray_getJSONArray'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        JSONArray* ret = cobj->getJSONArray(arg0);
        object_to_luaval<JSONArray>(tolua_S, "JSONArray",(JSONArray*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getJSONArray",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_getJSONArray'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONArray_getString(lua_State* tolua_S)
{
    int argc = 0;
    JSONArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONArray_getString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        const char* ret = cobj->getString(arg0);
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_getString'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONArray_insertNumber(lua_State* tolua_S)
{
    int argc = 0;
    JSONArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONArray_insertNumber'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        unsigned int arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        ok &= luaval_to_uint32(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->insertNumber(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "insertNumber",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_insertNumber'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONArray_addBool(lua_State* tolua_S)
{
    int argc = 0;
    JSONArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONArray_addBool'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->addBool(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addBool",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_addBool'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONArray_toLuaString(lua_State* tolua_S)
{
    int argc = 0;
    JSONArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONArray_toLuaString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->toLuaString();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "toLuaString",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_toLuaString'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONArray_getNumber(lua_State* tolua_S)
{
    int argc = 0;
    JSONArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONArray_getNumber'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        double ret = cobj->getNumber(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getNumber",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_getNumber'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONArray_addJSONObject(lua_State* tolua_S)
{
    int argc = 0;
    JSONArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONArray_addJSONObject'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        JSONObject* arg0;

        ok &= luaval_to_object<JSONObject>(tolua_S, 2, "JSONObject",&arg0);
        if(!ok)
            return 0;
        cobj->addJSONObject(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addJSONObject",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_addJSONObject'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONArray_add(lua_State* tolua_S)
{
    int argc = 0;
    JSONArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONArray_add'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Ref* arg0;

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0);
        if(!ok)
            return 0;
        cobj->add(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "add",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_add'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONArray_init(lua_State* tolua_S)
{
    int argc = 0;
    JSONArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONArray_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_init'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONArray_toString(lua_State* tolua_S)
{
    int argc = 0;
    JSONArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONArray_toString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->toString();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "toString",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_toString'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONArray_insertJSONArray(lua_State* tolua_S)
{
    int argc = 0;
    JSONArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONArray_insertJSONArray'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        JSONArray* arg0;
        unsigned int arg1;

        ok &= luaval_to_object<JSONArray>(tolua_S, 2, "JSONArray",&arg0);

        ok &= luaval_to_uint32(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->insertJSONArray(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "insertJSONArray",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_insertJSONArray'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONArray_addString(lua_State* tolua_S)
{
    int argc = 0;
    JSONArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONArray_addString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->addString(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_addString'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONArray_addNumber(lua_State* tolua_S)
{
    int argc = 0;
    JSONArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONArray_addNumber'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->addNumber(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addNumber",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_addNumber'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONArray_addJSONArray(lua_State* tolua_S)
{
    int argc = 0;
    JSONArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONArray_addJSONArray'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        JSONArray* arg0;

        ok &= luaval_to_object<JSONArray>(tolua_S, 2, "JSONArray",&arg0);
        if(!ok)
            return 0;
        cobj->addJSONArray(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addJSONArray",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_addJSONArray'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONArray_get(lua_State* tolua_S)
{
    int argc = 0;
    JSONArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONArray_get'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cocos2d::Ref* ret = cobj->get(arg0);
        object_to_luaval<cocos2d::Ref>(tolua_S, "cc.Ref",(cocos2d::Ref*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "get",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_get'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONArray_getBool(lua_State* tolua_S)
{
    int argc = 0;
    JSONArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONArray_getBool'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        bool ret = cobj->getBool(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBool",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_getBool'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONArray_toPrettyString(lua_State* tolua_S)
{
    int argc = 0;
    JSONArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONArray_toPrettyString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->toPrettyString();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "toPrettyString",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_toPrettyString'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONArray_count(lua_State* tolua_S)
{
    int argc = 0;
    JSONArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONArray_count'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->count();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "count",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_count'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONArray_insert(lua_State* tolua_S)
{
    int argc = 0;
    JSONArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONArray_insert'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Ref* arg0;
        unsigned int arg1;

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0);

        ok &= luaval_to_uint32(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->insert(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "insert",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_insert'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONArray_getJSONObject(lua_State* tolua_S)
{
    int argc = 0;
    JSONArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONArray_getJSONObject'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        JSONObject* ret = cobj->getJSONObject(arg0);
        object_to_luaval<JSONObject>(tolua_S, "JSONObject",(JSONObject*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getJSONObject",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_getJSONObject'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONArray_insertJSONObject(lua_State* tolua_S)
{
    int argc = 0;
    JSONArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONArray_insertJSONObject'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        JSONObject* arg0;
        unsigned int arg1;

        ok &= luaval_to_object<JSONObject>(tolua_S, 2, "JSONObject",&arg0);

        ok &= luaval_to_uint32(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->insertJSONObject(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "insertJSONObject",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_insertJSONObject'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONArray_remove(lua_State* tolua_S)
{
    int argc = 0;
    JSONArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONArray_remove'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->remove(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "remove",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_remove'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONArray_removeAll(lua_State* tolua_S)
{
    int argc = 0;
    JSONArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONArray_removeAll'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeAll();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeAll",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_removeAll'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONArray_removeLast(lua_State* tolua_S)
{
    int argc = 0;
    JSONArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONArray_removeLast'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeLast();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeLast",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_removeLast'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONArray_insertString(lua_State* tolua_S)
{
    int argc = 0;
    JSONArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONArray_insertString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        unsigned int arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_uint32(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->insertString(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "insertString",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_insertString'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONArray_insertBool(lua_State* tolua_S)
{
    int argc = 0;
    JSONArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (JSONArray*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_JSONArray_insertBool'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        bool arg0;
        unsigned int arg1;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);

        ok &= luaval_to_uint32(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->insertBool(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "insertBool",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_insertBool'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_JSONArray_createWithFile(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        JSONArray* ret = JSONArray::createWithFile(arg0);
        object_to_luaval<JSONArray>(tolua_S, "JSONArray",(JSONArray*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createWithFile",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_createWithFile'.",&tolua_err);
#endif
    return 0;
}
int lua_framework_JSONArray_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        JSONArray* ret = JSONArray::create();
        object_to_luaval<JSONArray>(tolua_S, "JSONArray",(JSONArray*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_create'.",&tolua_err);
#endif
    return 0;
}
int lua_framework_JSONArray_createWithString(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"JSONArray",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        JSONArray* ret = JSONArray::createWithString(arg0);
        object_to_luaval<JSONArray>(tolua_S, "JSONArray",(JSONArray*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createWithString",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_createWithString'.",&tolua_err);
#endif
    return 0;
}
int lua_framework_JSONArray_constructor(lua_State* tolua_S)
{
    int argc = 0;
    JSONArray* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new JSONArray();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"JSONArray");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "JSONArray",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_framework_JSONArray_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_framework_JSONArray_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (JSONArray)");
    return 0;
}

int lua_register_framework_JSONArray(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"JSONArray");
    tolua_cclass(tolua_S,"JSONArray","JSONArray","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"JSONArray");
        tolua_function(tolua_S,"getJSONArray",lua_framework_JSONArray_getJSONArray);
        tolua_function(tolua_S,"getString",lua_framework_JSONArray_getString);
        tolua_function(tolua_S,"insertNumber",lua_framework_JSONArray_insertNumber);
        tolua_function(tolua_S,"addBool",lua_framework_JSONArray_addBool);
        tolua_function(tolua_S,"toLuaString",lua_framework_JSONArray_toLuaString);
        tolua_function(tolua_S,"getNumber",lua_framework_JSONArray_getNumber);
        tolua_function(tolua_S,"addJSONObject",lua_framework_JSONArray_addJSONObject);
        tolua_function(tolua_S,"add",lua_framework_JSONArray_add);
        tolua_function(tolua_S,"init",lua_framework_JSONArray_init);
        tolua_function(tolua_S,"toString",lua_framework_JSONArray_toString);
        tolua_function(tolua_S,"insertJSONArray",lua_framework_JSONArray_insertJSONArray);
        tolua_function(tolua_S,"addString",lua_framework_JSONArray_addString);
        tolua_function(tolua_S,"addNumber",lua_framework_JSONArray_addNumber);
        tolua_function(tolua_S,"addJSONArray",lua_framework_JSONArray_addJSONArray);
        tolua_function(tolua_S,"get",lua_framework_JSONArray_get);
        tolua_function(tolua_S,"getBool",lua_framework_JSONArray_getBool);
        tolua_function(tolua_S,"toPrettyString",lua_framework_JSONArray_toPrettyString);
        tolua_function(tolua_S,"count",lua_framework_JSONArray_count);
        tolua_function(tolua_S,"insert",lua_framework_JSONArray_insert);
        tolua_function(tolua_S,"getJSONObject",lua_framework_JSONArray_getJSONObject);
        tolua_function(tolua_S,"insertJSONObject",lua_framework_JSONArray_insertJSONObject);
        tolua_function(tolua_S,"remove",lua_framework_JSONArray_remove);
        tolua_function(tolua_S,"removeAll",lua_framework_JSONArray_removeAll);
        tolua_function(tolua_S,"removeLast",lua_framework_JSONArray_removeLast);
        tolua_function(tolua_S,"insertString",lua_framework_JSONArray_insertString);
        tolua_function(tolua_S,"insertBool",lua_framework_JSONArray_insertBool);
        tolua_function(tolua_S,"new",lua_framework_JSONArray_constructor);
        tolua_function(tolua_S,"createWithFile", lua_framework_JSONArray_createWithFile);
        tolua_function(tolua_S,"create", lua_framework_JSONArray_create);
        tolua_function(tolua_S,"createWithString", lua_framework_JSONArray_createWithString);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(JSONArray).name();
    g_luaType[typeName] = "JSONArray";
    g_typeCast["JSONArray"] = "JSONArray";
    return 1;
}

int lua_framework_ViewController_load(lua_State* tolua_S)
{
    int argc = 0;
    ViewController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ViewController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ViewController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_ViewController_load'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->load();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "load",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_ViewController_load'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_ViewController_setRootLayer(lua_State* tolua_S)
{
    int argc = 0;
    ViewController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ViewController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ViewController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_ViewController_setRootLayer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Layer* arg0;

        ok &= luaval_to_object<cocos2d::Layer>(tolua_S, 2, "cc.Layer",&arg0);
        if(!ok)
            return 0;
        cobj->setRootLayer(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setRootLayer",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_ViewController_setRootLayer'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_ViewController_layerDidDisappear(lua_State* tolua_S)
{
    int argc = 0;
    ViewController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ViewController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ViewController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_ViewController_layerDidDisappear'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->layerDidDisappear();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "layerDidDisappear",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_ViewController_layerDidDisappear'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_ViewController_unload(lua_State* tolua_S)
{
    int argc = 0;
    ViewController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ViewController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ViewController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_ViewController_unload'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->unload();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "unload",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_ViewController_unload'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_ViewController_getRootLayer(lua_State* tolua_S)
{
    int argc = 0;
    ViewController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ViewController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ViewController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_ViewController_getRootLayer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Layer* ret = cobj->getRootLayer();
        object_to_luaval<cocos2d::Layer>(tolua_S, "cc.Layer",(cocos2d::Layer*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getRootLayer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_ViewController_getRootLayer'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_ViewController_getType(lua_State* tolua_S)
{
    int argc = 0;
    ViewController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ViewController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ViewController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_ViewController_getType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = (int)cobj->getType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_ViewController_getType'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_ViewController_layerWillDisappear(lua_State* tolua_S)
{
    int argc = 0;
    ViewController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ViewController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ViewController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_ViewController_layerWillDisappear'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->layerWillDisappear();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "layerWillDisappear",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_ViewController_layerWillDisappear'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_ViewController_getScene(lua_State* tolua_S)
{
    int argc = 0;
    ViewController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ViewController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ViewController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_ViewController_getScene'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        GameScene* ret = cobj->getScene();
        object_to_luaval<GameScene>(tolua_S, "GameScene",(GameScene*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getScene",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_ViewController_getScene'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_ViewController_layerWillAppear(lua_State* tolua_S)
{
    int argc = 0;
    ViewController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ViewController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ViewController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_ViewController_layerWillAppear'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->layerWillAppear();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "layerWillAppear",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_ViewController_layerWillAppear'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_ViewController_layerDidAppear(lua_State* tolua_S)
{
    int argc = 0;
    ViewController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ViewController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ViewController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_ViewController_layerDidAppear'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->layerDidAppear();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "layerDidAppear",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_ViewController_layerDidAppear'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_ViewController_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ViewController",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        ViewControllerType arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        ViewController* ret = ViewController::create(arg0);
        object_to_luaval<ViewController>(tolua_S, "ViewController",(ViewController*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_ViewController_create'.",&tolua_err);
#endif
    return 0;
}
int lua_framework_ViewController_constructor(lua_State* tolua_S)
{
    int argc = 0;
    ViewController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        ViewControllerType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj = new ViewController(arg0);
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"ViewController");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "ViewController",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_framework_ViewController_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_framework_ViewController_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ViewController)");
    return 0;
}

int lua_register_framework_ViewController(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ViewController");
    tolua_cclass(tolua_S,"ViewController","ViewController","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"ViewController");
        tolua_function(tolua_S,"load",lua_framework_ViewController_load);
        tolua_function(tolua_S,"setRootLayer",lua_framework_ViewController_setRootLayer);
        tolua_function(tolua_S,"layerDidDisappear",lua_framework_ViewController_layerDidDisappear);
        tolua_function(tolua_S,"unload",lua_framework_ViewController_unload);
        tolua_function(tolua_S,"getRootLayer",lua_framework_ViewController_getRootLayer);
        tolua_function(tolua_S,"getType",lua_framework_ViewController_getType);
        tolua_function(tolua_S,"layerWillDisappear",lua_framework_ViewController_layerWillDisappear);
        tolua_function(tolua_S,"getScene",lua_framework_ViewController_getScene);
        tolua_function(tolua_S,"layerWillAppear",lua_framework_ViewController_layerWillAppear);
        tolua_function(tolua_S,"layerDidAppear",lua_framework_ViewController_layerDidAppear);
        tolua_function(tolua_S,"new",lua_framework_ViewController_constructor);
        tolua_function(tolua_S,"create", lua_framework_ViewController_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(ViewController).name();
    g_luaType[typeName] = "ViewController";
    g_typeCast["ViewController"] = "ViewController";
    return 1;
}

int lua_framework_GameScene_removeMutexRelation(lua_State* tolua_S)
{
    int argc = 0;
    GameScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_GameScene_removeMutexRelation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_std_string(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->removeMutexRelation(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeMutexRelation",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_GameScene_removeMutexRelation'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_GameScene_onEnter(lua_State* tolua_S)
{
    int argc = 0;
    GameScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_GameScene_onEnter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->onEnter();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onEnter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_GameScene_onEnter'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_GameScene_onExit(lua_State* tolua_S)
{
    int argc = 0;
    GameScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_GameScene_onExit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->onExit();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onExit",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_GameScene_onExit'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_GameScene_unloadViewController(lua_State* tolua_S)
{
    int argc = 0;
    GameScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_GameScene_unloadViewController'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->unloadViewController(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "unloadViewController",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_GameScene_unloadViewController'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_GameScene_getAttribute(lua_State* tolua_S)
{
    int argc = 0;
    GameScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_GameScene_getAttribute'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cocos2d::Value ret = cobj->getAttribute(arg0);
        ccvalue_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAttribute",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_GameScene_getAttribute'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_GameScene_loadViewController(lua_State* tolua_S)
{
    int argc = 0;
    GameScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_GameScene_loadViewController'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        ViewController* arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_object<ViewController>(tolua_S, 3, "ViewController",&arg1);
        if(!ok)
            return 0;
        cobj->loadViewController(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "loadViewController",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_GameScene_loadViewController'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_GameScene_getViewController(lua_State* tolua_S)
{
    int argc = 0;
    GameScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_GameScene_getViewController'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        ViewController* ret = cobj->getViewController(arg0);
        object_to_luaval<ViewController>(tolua_S, "ViewController",(ViewController*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getViewController",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_GameScene_getViewController'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_GameScene_showViewController(lua_State* tolua_S)
{
    int argc = 0;
    GameScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_GameScene_showViewController'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->showViewController(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "showViewController",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_GameScene_showViewController'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_GameScene_init(lua_State* tolua_S)
{
    int argc = 0;
    GameScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_GameScene_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_GameScene_init'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_GameScene_hideViewController(lua_State* tolua_S)
{
    int argc = 0;
    GameScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_GameScene_hideViewController'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->hideViewController(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "hideViewController",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_GameScene_hideViewController'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_GameScene_getMutexRelationArray(lua_State* tolua_S)
{
    int argc = 0;
    GameScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_GameScene_getMutexRelationArray'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cocos2d::ValueVector ret = cobj->getMutexRelationArray(arg0);
        ccvaluevector_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getMutexRelationArray",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_GameScene_getMutexRelationArray'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_GameScene_addMutexRelation(lua_State* tolua_S)
{
    int argc = 0;
    GameScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_GameScene_addMutexRelation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_std_string(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->addMutexRelation(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addMutexRelation",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_GameScene_addMutexRelation'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_GameScene_unloadAllViewController(lua_State* tolua_S)
{
    int argc = 0;
    GameScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_GameScene_unloadAllViewController'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->unloadAllViewController();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "unloadAllViewController",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_GameScene_unloadAllViewController'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_GameScene_putAttribute(lua_State* tolua_S)
{
    int argc = 0;
    GameScene* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GameScene",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GameScene*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_GameScene_putAttribute'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        cocos2d::Value arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_ccvalue(tolua_S, 3, &arg1);
        if(!ok)
            return 0;
        cobj->putAttribute(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "putAttribute",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_GameScene_putAttribute'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_GameScene_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"GameScene",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        GameScene* ret = GameScene::create();
        object_to_luaval<GameScene>(tolua_S, "GameScene",(GameScene*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_GameScene_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_framework_GameScene_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GameScene)");
    return 0;
}

int lua_register_framework_GameScene(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"GameScene");
    tolua_cclass(tolua_S,"GameScene","GameScene","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"GameScene");
        tolua_function(tolua_S,"removeMutexRelation",lua_framework_GameScene_removeMutexRelation);
        tolua_function(tolua_S,"onEnter",lua_framework_GameScene_onEnter);
        tolua_function(tolua_S,"onExit",lua_framework_GameScene_onExit);
        tolua_function(tolua_S,"unloadViewController",lua_framework_GameScene_unloadViewController);
        tolua_function(tolua_S,"getAttribute",lua_framework_GameScene_getAttribute);
        tolua_function(tolua_S,"loadViewController",lua_framework_GameScene_loadViewController);
        tolua_function(tolua_S,"getViewController",lua_framework_GameScene_getViewController);
        tolua_function(tolua_S,"showViewController",lua_framework_GameScene_showViewController);
        tolua_function(tolua_S,"init",lua_framework_GameScene_init);
        tolua_function(tolua_S,"hideViewController",lua_framework_GameScene_hideViewController);
        tolua_function(tolua_S,"getMutexRelationArray",lua_framework_GameScene_getMutexRelationArray);
        tolua_function(tolua_S,"addMutexRelation",lua_framework_GameScene_addMutexRelation);
        tolua_function(tolua_S,"unloadAllViewController",lua_framework_GameScene_unloadAllViewController);
        tolua_function(tolua_S,"putAttribute",lua_framework_GameScene_putAttribute);
        tolua_function(tolua_S,"create", lua_framework_GameScene_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(GameScene).name();
    g_luaType[typeName] = "GameScene";
    g_typeCast["GameScene"] = "GameScene";
    return 1;
}

int lua_framework_NetRequest_setBody(lua_State* tolua_S)
{
    int argc = 0;
    NetRequest* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetRequest",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetRequest*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetRequest_setBody'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        JSONObject* arg0;

        ok &= luaval_to_object<JSONObject>(tolua_S, 2, "JSONObject",&arg0);
        if(!ok)
            return 0;
        cobj->setBody(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBody",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetRequest_setBody'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetRequest_setConfigInfo(lua_State* tolua_S)
{
    int argc = 0;
    NetRequest* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetRequest",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetRequest*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetRequest_setConfigInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        JSONObject* arg0;

        ok &= luaval_to_object<JSONObject>(tolua_S, 2, "JSONObject",&arg0);
        if(!ok)
            return 0;
        cobj->setConfigInfo(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setConfigInfo",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetRequest_setConfigInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetRequest_getProtocolID(lua_State* tolua_S)
{
    int argc = 0;
    NetRequest* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetRequest",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetRequest*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetRequest_getProtocolID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const std::string& ret = cobj->getProtocolID();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getProtocolID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetRequest_getProtocolID'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetRequest_getConfigInfo(lua_State* tolua_S)
{
    int argc = 0;
    NetRequest* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetRequest",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetRequest*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetRequest_getConfigInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        JSONObject* ret = cobj->getConfigInfo();
        object_to_luaval<JSONObject>(tolua_S, "JSONObject",(JSONObject*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getConfigInfo",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetRequest_getConfigInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetRequest_setProtocolID(lua_State* tolua_S)
{
    int argc = 0;
    NetRequest* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetRequest",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetRequest*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetRequest_setProtocolID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setProtocolID(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setProtocolID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetRequest_setProtocolID'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetRequest_init(lua_State* tolua_S)
{
    int argc = 0;
    NetRequest* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetRequest",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetRequest*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetRequest_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetRequest_init'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetRequest_getBody(lua_State* tolua_S)
{
    int argc = 0;
    NetRequest* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetRequest",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetRequest*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetRequest_getBody'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        JSONObject* ret = cobj->getBody();
        object_to_luaval<JSONObject>(tolua_S, "JSONObject",(JSONObject*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBody",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetRequest_getBody'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetRequest_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"NetRequest",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);
            if (!ok) { break; }
            JSONObject* arg1;
            ok &= luaval_to_object<JSONObject>(tolua_S, 3, "JSONObject",&arg1);
            if (!ok) { break; }
            NetRequest* ret = NetRequest::create(arg0, arg1);
            object_to_luaval<NetRequest>(tolua_S, "NetRequest",(NetRequest*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            NetRequest* ret = NetRequest::create();
            object_to_luaval<NetRequest>(tolua_S, "NetRequest",(NetRequest*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetRequest_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_framework_NetRequest_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (NetRequest)");
    return 0;
}

int lua_register_framework_NetRequest(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"NetRequest");
    tolua_cclass(tolua_S,"NetRequest","NetRequest","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"NetRequest");
        tolua_function(tolua_S,"setBody",lua_framework_NetRequest_setBody);
        tolua_function(tolua_S,"setConfigInfo",lua_framework_NetRequest_setConfigInfo);
        tolua_function(tolua_S,"getProtocolID",lua_framework_NetRequest_getProtocolID);
        tolua_function(tolua_S,"getConfigInfo",lua_framework_NetRequest_getConfigInfo);
        tolua_function(tolua_S,"setProtocolID",lua_framework_NetRequest_setProtocolID);
        tolua_function(tolua_S,"init",lua_framework_NetRequest_init);
        tolua_function(tolua_S,"getBody",lua_framework_NetRequest_getBody);
        tolua_function(tolua_S,"create", lua_framework_NetRequest_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(NetRequest).name();
    g_luaType[typeName] = "NetRequest";
    g_typeCast["NetRequest"] = "NetRequest";
    return 1;
}

int lua_framework_NetResponse_setRequest(lua_State* tolua_S)
{
    int argc = 0;
    NetResponse* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetResponse",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetResponse*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetResponse_setRequest'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        NetRequest* arg0;

        ok &= luaval_to_object<NetRequest>(tolua_S, 2, "NetRequest",&arg0);
        if(!ok)
            return 0;
        cobj->setRequest(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setRequest",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetResponse_setRequest'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetResponse_setBody(lua_State* tolua_S)
{
    int argc = 0;
    NetResponse* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetResponse",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetResponse*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetResponse_setBody'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        JSONObject* arg0;

        ok &= luaval_to_object<JSONObject>(tolua_S, 2, "JSONObject",&arg0);
        if(!ok)
            return 0;
        cobj->setBody(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBody",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetResponse_setBody'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetResponse_getProtocolID(lua_State* tolua_S)
{
    int argc = 0;
    NetResponse* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetResponse",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetResponse*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetResponse_getProtocolID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const std::string& ret = cobj->getProtocolID();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getProtocolID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetResponse_getProtocolID'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetResponse_getRequest(lua_State* tolua_S)
{
    int argc = 0;
    NetResponse* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetResponse",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetResponse*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetResponse_getRequest'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        NetRequest* ret = cobj->getRequest();
        object_to_luaval<NetRequest>(tolua_S, "NetRequest",(NetRequest*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getRequest",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetResponse_getRequest'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetResponse_setProtocolID(lua_State* tolua_S)
{
    int argc = 0;
    NetResponse* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetResponse",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetResponse*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetResponse_setProtocolID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setProtocolID(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setProtocolID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetResponse_setProtocolID'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetResponse_init(lua_State* tolua_S)
{
    int argc = 0;
    NetResponse* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetResponse",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetResponse*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetResponse_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetResponse_init'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetResponse_getBody(lua_State* tolua_S)
{
    int argc = 0;
    NetResponse* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetResponse",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetResponse*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetResponse_getBody'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        JSONObject* ret = cobj->getBody();
        object_to_luaval<JSONObject>(tolua_S, "JSONObject",(JSONObject*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBody",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetResponse_getBody'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetResponse_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"NetResponse",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);
            if (!ok) { break; }
            JSONObject* arg1;
            ok &= luaval_to_object<JSONObject>(tolua_S, 3, "JSONObject",&arg1);
            if (!ok) { break; }
            NetResponse* ret = NetResponse::create(arg0, arg1);
            object_to_luaval<NetResponse>(tolua_S, "NetResponse",(NetResponse*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);
            if (!ok) { break; }
            JSONObject* arg1;
            ok &= luaval_to_object<JSONObject>(tolua_S, 3, "JSONObject",&arg1);
            if (!ok) { break; }
            NetRequest* arg2;
            ok &= luaval_to_object<NetRequest>(tolua_S, 4, "NetRequest",&arg2);
            if (!ok) { break; }
            NetResponse* ret = NetResponse::create(arg0, arg1, arg2);
            object_to_luaval<NetResponse>(tolua_S, "NetResponse",(NetResponse*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            NetResponse* ret = NetResponse::create();
            object_to_luaval<NetResponse>(tolua_S, "NetResponse",(NetResponse*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetResponse_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_framework_NetResponse_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (NetResponse)");
    return 0;
}

int lua_register_framework_NetResponse(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"NetResponse");
    tolua_cclass(tolua_S,"NetResponse","NetResponse","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"NetResponse");
        tolua_function(tolua_S,"setRequest",lua_framework_NetResponse_setRequest);
        tolua_function(tolua_S,"setBody",lua_framework_NetResponse_setBody);
        tolua_function(tolua_S,"getProtocolID",lua_framework_NetResponse_getProtocolID);
        tolua_function(tolua_S,"getRequest",lua_framework_NetResponse_getRequest);
        tolua_function(tolua_S,"setProtocolID",lua_framework_NetResponse_setProtocolID);
        tolua_function(tolua_S,"init",lua_framework_NetResponse_init);
        tolua_function(tolua_S,"getBody",lua_framework_NetResponse_getBody);
        tolua_function(tolua_S,"create", lua_framework_NetResponse_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(NetResponse).name();
    g_luaType[typeName] = "NetResponse";
    g_typeCast["NetResponse"] = "NetResponse";
    return 1;
}

int lua_framework_NetHandler_handleFailedMessage(lua_State* tolua_S)
{
    int argc = 0;
    NetHandler* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetHandler",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetHandler*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetHandler_handleFailedMessage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        NetResponse* arg0;

        ok &= luaval_to_object<NetResponse>(tolua_S, 2, "NetResponse",&arg0);
        if(!ok)
            return 0;
        cobj->handleFailedMessage(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "handleFailedMessage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetHandler_handleFailedMessage'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetHandler_init(lua_State* tolua_S)
{
    int argc = 0;
    NetHandler* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetHandler",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetHandler*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetHandler_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetHandler_init'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetHandler_handleSuccessfulMessage(lua_State* tolua_S)
{
    int argc = 0;
    NetHandler* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetHandler",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetHandler*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetHandler_handleSuccessfulMessage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        NetResponse* arg0;

        ok &= luaval_to_object<NetResponse>(tolua_S, 2, "NetResponse",&arg0);
        if(!ok)
            return 0;
        cobj->handleSuccessfulMessage(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "handleSuccessfulMessage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetHandler_handleSuccessfulMessage'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetHandler_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"NetHandler",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        NetHandler* ret = NetHandler::create();
        object_to_luaval<NetHandler>(tolua_S, "NetHandler",(NetHandler*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetHandler_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_framework_NetHandler_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (NetHandler)");
    return 0;
}

int lua_register_framework_NetHandler(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"NetHandler");
    tolua_cclass(tolua_S,"NetHandler","NetHandler","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"NetHandler");
        tolua_function(tolua_S,"handleFailedMessage",lua_framework_NetHandler_handleFailedMessage);
        tolua_function(tolua_S,"init",lua_framework_NetHandler_init);
        tolua_function(tolua_S,"handleSuccessfulMessage",lua_framework_NetHandler_handleSuccessfulMessage);
        tolua_function(tolua_S,"create", lua_framework_NetHandler_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(NetHandler).name();
    g_luaType[typeName] = "NetHandler";
    g_typeCast["NetHandler"] = "NetHandler";
    return 1;
}

int lua_framework_NetService_executeCommand(lua_State* tolua_S)
{
    int argc = 0;
    NetService* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetService",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetService*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetService_executeCommand'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        cocos2d::Ref* arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 3, "cc.Ref",&arg1);
        if(!ok)
            return 0;
        cobj->executeCommand(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "executeCommand",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetService_executeCommand'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetService_sendMessage(lua_State* tolua_S)
{
    int argc = 0;
    NetService* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetService",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetService*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetService_sendMessage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        NetRequest* arg0;

        ok &= luaval_to_object<NetRequest>(tolua_S, 2, "NetRequest",&arg0);
        if(!ok)
            return 0;
        cobj->sendMessage(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "sendMessage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetService_sendMessage'.",&tolua_err);
#endif

    return 0;
}
static int lua_framework_NetService_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (NetService)");
    return 0;
}

int lua_register_framework_NetService(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"NetService");
    tolua_cclass(tolua_S,"NetService","NetService","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"NetService");
        tolua_function(tolua_S,"executeCommand",lua_framework_NetService_executeCommand);
        tolua_function(tolua_S,"sendMessage",lua_framework_NetService_sendMessage);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(NetService).name();
    g_luaType[typeName] = "NetService";
    g_typeCast["NetService"] = "NetService";
    return 1;
}

int lua_framework_NetProtocol_setID(lua_State* tolua_S)
{
    int argc = 0;
    NetProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetProtocol_setID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setID(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetProtocol_setID'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetProtocol_getID(lua_State* tolua_S)
{
    int argc = 0;
    NetProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetProtocol_getID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const std::string& ret = cobj->getID();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetProtocol_getID'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetProtocol_init(lua_State* tolua_S)
{
    int argc = 0;
    NetProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetProtocol_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetProtocol_init'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetProtocol_setServiceID(lua_State* tolua_S)
{
    int argc = 0;
    NetProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetProtocol_setServiceID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setServiceID(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setServiceID",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetProtocol_setServiceID'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetProtocol_getServiceID(lua_State* tolua_S)
{
    int argc = 0;
    NetProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetProtocol_getServiceID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const std::string& ret = cobj->getServiceID();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getServiceID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetProtocol_getServiceID'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetProtocol_getHandler(lua_State* tolua_S)
{
    int argc = 0;
    NetProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetProtocol_getHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        NetHandler* ret = cobj->getHandler();
        object_to_luaval<NetHandler>(tolua_S, "NetHandler",(NetHandler*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetProtocol_getHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetProtocol_setHandler(lua_State* tolua_S)
{
    int argc = 0;
    NetProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetProtocol_setHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        NetHandler* arg0;

        ok &= luaval_to_object<NetHandler>(tolua_S, 2, "NetHandler",&arg0);
        if(!ok)
            return 0;
        cobj->setHandler(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetProtocol_setHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetProtocol_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"NetProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 3)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);
            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1);
            if (!ok) { break; }
            NetHandler* arg2;
            ok &= luaval_to_object<NetHandler>(tolua_S, 4, "NetHandler",&arg2);
            if (!ok) { break; }
            NetProtocol* ret = NetProtocol::create(arg0, arg1, arg2);
            object_to_luaval<NetProtocol>(tolua_S, "NetProtocol",(NetProtocol*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            NetProtocol* ret = NetProtocol::create();
            object_to_luaval<NetProtocol>(tolua_S, "NetProtocol",(NetProtocol*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetProtocol_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_framework_NetProtocol_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (NetProtocol)");
    return 0;
}

int lua_register_framework_NetProtocol(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"NetProtocol");
    tolua_cclass(tolua_S,"NetProtocol","NetProtocol","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"NetProtocol");
        tolua_function(tolua_S,"setID",lua_framework_NetProtocol_setID);
        tolua_function(tolua_S,"getID",lua_framework_NetProtocol_getID);
        tolua_function(tolua_S,"init",lua_framework_NetProtocol_init);
        tolua_function(tolua_S,"setServiceID",lua_framework_NetProtocol_setServiceID);
        tolua_function(tolua_S,"getServiceID",lua_framework_NetProtocol_getServiceID);
        tolua_function(tolua_S,"getHandler",lua_framework_NetProtocol_getHandler);
        tolua_function(tolua_S,"setHandler",lua_framework_NetProtocol_setHandler);
        tolua_function(tolua_S,"create", lua_framework_NetProtocol_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(NetProtocol).name();
    g_luaType[typeName] = "NetProtocol";
    g_typeCast["NetProtocol"] = "NetProtocol";
    return 1;
}

int lua_framework_NetFilter_init(lua_State* tolua_S)
{
    int argc = 0;
    NetFilter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetFilter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetFilter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetFilter_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetFilter_init'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetFilter_filterSuccessfulMessage(lua_State* tolua_S)
{
    int argc = 0;
    NetFilter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetFilter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetFilter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetFilter_filterSuccessfulMessage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        NetResponse* arg0;

        ok &= luaval_to_object<NetResponse>(tolua_S, 2, "NetResponse",&arg0);
        if(!ok)
            return 0;
        NetResponse* ret = cobj->filterSuccessfulMessage(arg0);
        object_to_luaval<NetResponse>(tolua_S, "NetResponse",(NetResponse*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "filterSuccessfulMessage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetFilter_filterSuccessfulMessage'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetFilter_filterFailedMessage(lua_State* tolua_S)
{
    int argc = 0;
    NetFilter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetFilter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetFilter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetFilter_filterFailedMessage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        NetResponse* arg0;

        ok &= luaval_to_object<NetResponse>(tolua_S, 2, "NetResponse",&arg0);
        if(!ok)
            return 0;
        NetResponse* ret = cobj->filterFailedMessage(arg0);
        object_to_luaval<NetResponse>(tolua_S, "NetResponse",(NetResponse*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "filterFailedMessage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetFilter_filterFailedMessage'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetFilter_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"NetFilter",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        NetFilter* ret = NetFilter::create();
        object_to_luaval<NetFilter>(tolua_S, "NetFilter",(NetFilter*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetFilter_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_framework_NetFilter_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (NetFilter)");
    return 0;
}

int lua_register_framework_NetFilter(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"NetFilter");
    tolua_cclass(tolua_S,"NetFilter","NetFilter","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"NetFilter");
        tolua_function(tolua_S,"init",lua_framework_NetFilter_init);
        tolua_function(tolua_S,"filterSuccessfulMessage",lua_framework_NetFilter_filterSuccessfulMessage);
        tolua_function(tolua_S,"filterFailedMessage",lua_framework_NetFilter_filterFailedMessage);
        tolua_function(tolua_S,"create", lua_framework_NetFilter_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(NetFilter).name();
    g_luaType[typeName] = "NetFilter";
    g_typeCast["NetFilter"] = "NetFilter";
    return 1;
}

int lua_framework_NetCenter_addNetService(lua_State* tolua_S)
{
    int argc = 0;
    NetCenter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetCenter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetCenter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetCenter_addNetService'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        NetService* arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_object<NetService>(tolua_S, 3, "NetService",&arg1);
        if(!ok)
            return 0;
        cobj->addNetService(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addNetService",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetCenter_addNetService'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetCenter_removeAllNetFilters(lua_State* tolua_S)
{
    int argc = 0;
    NetCenter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetCenter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetCenter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetCenter_removeAllNetFilters'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeAllNetFilters();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeAllNetFilters",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetCenter_removeAllNetFilters'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetCenter_dispatchSuccessfulMessage(lua_State* tolua_S)
{
    int argc = 0;
    NetCenter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetCenter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetCenter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetCenter_dispatchSuccessfulMessage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        NetResponse* arg0;

        ok &= luaval_to_object<NetResponse>(tolua_S, 2, "NetResponse",&arg0);
        if(!ok)
            return 0;
        cobj->dispatchSuccessfulMessage(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "dispatchSuccessfulMessage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetCenter_dispatchSuccessfulMessage'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetCenter_removeNetProtocol(lua_State* tolua_S)
{
    int argc = 0;
    NetCenter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetCenter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetCenter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetCenter_removeNetProtocol'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->removeNetProtocol(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeNetProtocol",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetCenter_removeNetProtocol'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetCenter_removeNetProtocolForNetService(lua_State* tolua_S)
{
    int argc = 0;
    NetCenter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetCenter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetCenter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetCenter_removeNetProtocolForNetService'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->removeNetProtocolForNetService(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeNetProtocolForNetService",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetCenter_removeNetProtocolForNetService'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetCenter_removeNetFilter(lua_State* tolua_S)
{
    int argc = 0;
    NetCenter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetCenter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetCenter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetCenter_removeNetFilter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        NetFilter* arg0;

        ok &= luaval_to_object<NetFilter>(tolua_S, 2, "NetFilter",&arg0);
        if(!ok)
            return 0;
        cobj->removeNetFilter(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeNetFilter",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetCenter_removeNetFilter'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetCenter_removeNetService(lua_State* tolua_S)
{
    int argc = 0;
    NetCenter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetCenter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetCenter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetCenter_removeNetService'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->removeNetService(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeNetService",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetCenter_removeNetService'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetCenter_addNetProtocol(lua_State* tolua_S)
{
    int argc = 0;
    NetCenter* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetCenter",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (NetCenter*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetCenter_addNetProtocol'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            NetProtocol* arg0;
            ok &= luaval_to_object<NetProtocol>(tolua_S, 2, "NetProtocol",&arg0);

            if (!ok) { break; }
            cobj->addNetProtocol(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 3) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1);

            if (!ok) { break; }
            NetHandler* arg2;
            ok &= luaval_to_object<NetHandler>(tolua_S, 4, "NetHandler",&arg2);

            if (!ok) { break; }
            cobj->addNetProtocol(arg0, arg1, arg2);
            return 0;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addNetProtocol",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetCenter_addNetProtocol'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetCenter_sendMessage(lua_State* tolua_S)
{
    int argc = 0;
    NetCenter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetCenter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetCenter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetCenter_sendMessage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        NetRequest* arg0;

        ok &= luaval_to_object<NetRequest>(tolua_S, 2, "NetRequest",&arg0);
        if(!ok)
            return 0;
        cobj->sendMessage(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "sendMessage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetCenter_sendMessage'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetCenter_dispatchFailedMessage(lua_State* tolua_S)
{
    int argc = 0;
    NetCenter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetCenter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetCenter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetCenter_dispatchFailedMessage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        NetResponse* arg0;

        ok &= luaval_to_object<NetResponse>(tolua_S, 2, "NetResponse",&arg0);
        if(!ok)
            return 0;
        cobj->dispatchFailedMessage(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "dispatchFailedMessage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetCenter_dispatchFailedMessage'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetCenter_addNetFilter(lua_State* tolua_S)
{
    int argc = 0;
    NetCenter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetCenter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetCenter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetCenter_addNetFilter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        NetFilter* arg0;

        ok &= luaval_to_object<NetFilter>(tolua_S, 2, "NetFilter",&arg0);
        if(!ok)
            return 0;
        cobj->addNetFilter(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addNetFilter",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetCenter_addNetFilter'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetCenter_sendCommand(lua_State* tolua_S)
{
    int argc = 0;
    NetCenter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"NetCenter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (NetCenter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_NetCenter_sendCommand'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        std::string arg0;
        std::string arg1;
        cocos2d::Ref* arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_std_string(tolua_S, 3,&arg1);

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 4, "cc.Ref",&arg2);
        if(!ok)
            return 0;
        cobj->sendCommand(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "sendCommand",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetCenter_sendCommand'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_NetCenter_sharedNetCenter(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"NetCenter",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        NetCenter* ret = NetCenter::sharedNetCenter();
        object_to_luaval<NetCenter>(tolua_S, "NetCenter",(NetCenter*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "sharedNetCenter",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_NetCenter_sharedNetCenter'.",&tolua_err);
#endif
    return 0;
}
static int lua_framework_NetCenter_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (NetCenter)");
    return 0;
}

int lua_register_framework_NetCenter(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"NetCenter");
    tolua_cclass(tolua_S,"NetCenter","NetCenter","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"NetCenter");
        tolua_function(tolua_S,"addNetService",lua_framework_NetCenter_addNetService);
        tolua_function(tolua_S,"removeAllNetFilters",lua_framework_NetCenter_removeAllNetFilters);
        tolua_function(tolua_S,"dispatchSuccessfulMessage",lua_framework_NetCenter_dispatchSuccessfulMessage);
        tolua_function(tolua_S,"removeNetProtocol",lua_framework_NetCenter_removeNetProtocol);
        tolua_function(tolua_S,"removeNetProtocolForNetService",lua_framework_NetCenter_removeNetProtocolForNetService);
        tolua_function(tolua_S,"removeNetFilter",lua_framework_NetCenter_removeNetFilter);
        tolua_function(tolua_S,"removeNetService",lua_framework_NetCenter_removeNetService);
        tolua_function(tolua_S,"addNetProtocol",lua_framework_NetCenter_addNetProtocol);
        tolua_function(tolua_S,"sendMessage",lua_framework_NetCenter_sendMessage);
        tolua_function(tolua_S,"dispatchFailedMessage",lua_framework_NetCenter_dispatchFailedMessage);
        tolua_function(tolua_S,"addNetFilter",lua_framework_NetCenter_addNetFilter);
        tolua_function(tolua_S,"sendCommand",lua_framework_NetCenter_sendCommand);
        tolua_function(tolua_S,"sharedNetCenter", lua_framework_NetCenter_sharedNetCenter);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(NetCenter).name();
    g_luaType[typeName] = "NetCenter";
    g_typeCast["NetCenter"] = "NetCenter";
    return 1;
}

int lua_framework_SQLite_updateTable(lua_State* tolua_S)
{
    int argc = 0;
    SQLite* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SQLite",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SQLite*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_SQLite_updateTable'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 4) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            cocos2d::ValueMap arg1;
            ok &= luaval_to_ccvaluemap(tolua_S, 3, &arg1);

            if (!ok) { break; }
            std::string arg2;
            ok &= luaval_to_std_string(tolua_S, 4,&arg2);

            if (!ok) { break; }
            std::string arg3;
            ok &= luaval_to_std_string(tolua_S, 5,&arg3);

            if (!ok) { break; }
            bool ret = cobj->updateTable(arg0, arg1, arg2, arg3);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 3) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            cocos2d::ValueMap arg1;
            ok &= luaval_to_ccvaluemap(tolua_S, 3, &arg1);

            if (!ok) { break; }
            cocos2d::ValueMap arg2;
            ok &= luaval_to_ccvaluemap(tolua_S, 4, &arg2);

            if (!ok) { break; }
            bool ret = cobj->updateTable(arg0, arg1, arg2);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "updateTable",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_SQLite_updateTable'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_SQLite_dropTable(lua_State* tolua_S)
{
    int argc = 0;
    SQLite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SQLite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SQLite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_SQLite_dropTable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        bool ret = cobj->dropTable(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "dropTable",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_SQLite_dropTable'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_SQLite_clearTable(lua_State* tolua_S)
{
    int argc = 0;
    SQLite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SQLite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SQLite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_SQLite_clearTable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        bool ret = cobj->clearTable(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "clearTable",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_SQLite_clearTable'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_SQLite_deleteFromTable(lua_State* tolua_S)
{
    int argc = 0;
    SQLite* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SQLite",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SQLite*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_SQLite_deleteFromTable'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 3) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1);

            if (!ok) { break; }
            std::string arg2;
            ok &= luaval_to_std_string(tolua_S, 4,&arg2);

            if (!ok) { break; }
            bool ret = cobj->deleteFromTable(arg0, arg1, arg2);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            cocos2d::ValueMap arg1;
            ok &= luaval_to_ccvaluemap(tolua_S, 3, &arg1);

            if (!ok) { break; }
            bool ret = cobj->deleteFromTable(arg0, arg1);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "deleteFromTable",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_SQLite_deleteFromTable'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_SQLite_getRecordCount(lua_State* tolua_S)
{
    int argc = 0;
    SQLite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SQLite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SQLite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_SQLite_getRecordCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        int ret = cobj->getRecordCount(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getRecordCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_SQLite_getRecordCount'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_SQLite_createTable(lua_State* tolua_S)
{
    int argc = 0;
    SQLite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SQLite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SQLite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_SQLite_createTable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        cocos2d::ValueVector arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_ccvaluevector(tolua_S, 3, &arg1);
        if(!ok)
            return 0;
        bool ret = cobj->createTable(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createTable",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_SQLite_createTable'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_SQLite_insertIntoTable(lua_State* tolua_S)
{
    int argc = 0;
    SQLite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SQLite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SQLite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_SQLite_insertIntoTable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        cocos2d::ValueMap arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_ccvaluemap(tolua_S, 3, &arg1);
        if(!ok)
            return 0;
        bool ret = cobj->insertIntoTable(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "insertIntoTable",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_SQLite_insertIntoTable'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_SQLite_selectTable(lua_State* tolua_S)
{
    int argc = 0;
    SQLite* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SQLite",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (SQLite*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_SQLite_selectTable'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 3) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1);

            if (!ok) { break; }
            std::string arg2;
            ok &= luaval_to_std_string(tolua_S, 4,&arg2);

            if (!ok) { break; }
            cocos2d::ValueVector ret = cobj->selectTable(arg0, arg1, arg2);
            ccvaluevector_to_luaval(tolua_S, ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            cocos2d::ValueMap arg1;
            ok &= luaval_to_ccvaluemap(tolua_S, 3, &arg1);

            if (!ok) { break; }
            cocos2d::ValueVector ret = cobj->selectTable(arg0, arg1);
            ccvaluevector_to_luaval(tolua_S, ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 3) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1);

            if (!ok) { break; }
            cocos2d::ValueVector arg2;
            ok &= luaval_to_ccvaluevector(tolua_S, 4, &arg2);

            if (!ok) { break; }
            cocos2d::ValueVector ret = cobj->selectTable(arg0, arg1, arg2);
            ccvaluevector_to_luaval(tolua_S, ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1);

            if (!ok) { break; }
            cocos2d::ValueVector ret = cobj->selectTable(arg0, arg1);
            ccvaluevector_to_luaval(tolua_S, ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "selectTable",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_SQLite_selectTable'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_SQLite_openSQLite(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SQLite",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        SQLite* ret = SQLite::openSQLite(arg0);
        object_to_luaval<SQLite>(tolua_S, "SQLite",(SQLite*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "openSQLite",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_SQLite_openSQLite'.",&tolua_err);
#endif
    return 0;
}
int lua_framework_SQLite_clearConnectionCache(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SQLite",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        SQLite::clearConnectionCache();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "clearConnectionCache",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_SQLite_clearConnectionCache'.",&tolua_err);
#endif
    return 0;
}
static int lua_framework_SQLite_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (SQLite)");
    return 0;
}

int lua_register_framework_SQLite(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"SQLite");
    tolua_cclass(tolua_S,"SQLite","SQLite","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"SQLite");
        tolua_function(tolua_S,"updateTable",lua_framework_SQLite_updateTable);
        tolua_function(tolua_S,"dropTable",lua_framework_SQLite_dropTable);
        tolua_function(tolua_S,"clearTable",lua_framework_SQLite_clearTable);
        tolua_function(tolua_S,"deleteFromTable",lua_framework_SQLite_deleteFromTable);
        tolua_function(tolua_S,"getRecordCount",lua_framework_SQLite_getRecordCount);
        tolua_function(tolua_S,"createTable",lua_framework_SQLite_createTable);
        tolua_function(tolua_S,"insertIntoTable",lua_framework_SQLite_insertIntoTable);
        tolua_function(tolua_S,"selectTable",lua_framework_SQLite_selectTable);
        tolua_function(tolua_S,"openSQLite", lua_framework_SQLite_openSQLite);
        tolua_function(tolua_S,"clearConnectionCache", lua_framework_SQLite_clearConnectionCache);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(SQLite).name();
    g_luaType[typeName] = "SQLite";
    g_typeCast["SQLite"] = "SQLite";
    return 1;
}

int lua_framework_Game_restart(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"Game",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        Game::restart();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "restart",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_Game_restart'.",&tolua_err);
#endif
    return 0;
}
static int lua_framework_Game_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Game)");
    return 0;
}

int lua_register_framework_Game(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"Game");
    tolua_cclass(tolua_S,"Game","Game","",nullptr);

    tolua_beginmodule(tolua_S,"Game");
        tolua_function(tolua_S,"restart", lua_framework_Game_restart);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(Game).name();
    g_luaType[typeName] = "Game";
    g_typeCast["Game"] = "Game";
    return 1;
}

int lua_framework_SceneManager_runScene(lua_State* tolua_S)
{
    int argc = 0;
    SceneManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SceneManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SceneManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_framework_SceneManager_runScene'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        GameScene* arg0;

        ok &= luaval_to_object<GameScene>(tolua_S, 2, "GameScene",&arg0);
        if(!ok)
            return 0;
        cobj->runScene(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "runScene",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_SceneManager_runScene'.",&tolua_err);
#endif

    return 0;
}
int lua_framework_SceneManager_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SceneManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        SceneManager* ret = SceneManager::getInstance();
        object_to_luaval<SceneManager>(tolua_S, "SceneManager",(SceneManager*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_framework_SceneManager_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_framework_SceneManager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (SceneManager)");
    return 0;
}

int lua_register_framework_SceneManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"SceneManager");
    tolua_cclass(tolua_S,"SceneManager","SceneManager","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"SceneManager");
        tolua_function(tolua_S,"runScene",lua_framework_SceneManager_runScene);
        tolua_function(tolua_S,"getInstance", lua_framework_SceneManager_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(SceneManager).name();
    g_luaType[typeName] = "SceneManager";
    g_typeCast["SceneManager"] = "SceneManager";
    return 1;
}
TOLUA_API int register_all_framework(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,nullptr,0);
	tolua_beginmodule(tolua_S,nullptr);

	lua_register_framework_SceneManager(tolua_S);
	lua_register_framework_SQLite(tolua_S);
	lua_register_framework_NetResponse(tolua_S);
	lua_register_framework_NetHandler(tolua_S);
	lua_register_framework_NetRequest(tolua_S);
	lua_register_framework_JSONArray(tolua_S);
	lua_register_framework_JSONObject(tolua_S);
	lua_register_framework_NetService(tolua_S);
	lua_register_framework_Game(tolua_S);
	lua_register_framework_NetCenter(tolua_S);
	lua_register_framework_NetFilter(tolua_S);
	lua_register_framework_ViewController(tolua_S);
	lua_register_framework_NetProtocol(tolua_S);
	lua_register_framework_GameScene(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

