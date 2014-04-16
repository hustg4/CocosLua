/*
** Lua binding: LuaFramework
** Generated automatically by tolua++-1.0.92 on Mon Mar 24 15:32:11 2014.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_LuaFramework_open (lua_State* tolua_S);

#include "LuaFramework.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"NetFilter");
 tolua_usertype(tolua_S,"ResourceUpdateDelegate");
 tolua_usertype(tolua_S,"__Dictionary");
 tolua_usertype(tolua_S,"DBDecryptUtil");
 tolua_usertype(tolua_S,"NetCenter");
 tolua_usertype(tolua_S,"SQLite");
 tolua_usertype(tolua_S,"NetStatusUtil");
 tolua_usertype(tolua_S,"GameScene");
 tolua_usertype(tolua_S,"JSONBool");
 tolua_usertype(tolua_S,"JSONElement");
 tolua_usertype(tolua_S,"NetService");
 tolua_usertype(tolua_S,"JSONObject");
 tolua_usertype(tolua_S,"__Array");
 tolua_usertype(tolua_S,"NetRequest");
 tolua_usertype(tolua_S,"NetHandler");
 tolua_usertype(tolua_S,"Base64Util");
 tolua_usertype(tolua_S,"UUIDGenerator");
 tolua_usertype(tolua_S,"JSONArray");
 tolua_usertype(tolua_S,"JSONString");
 tolua_usertype(tolua_S,"CCScene");
 tolua_usertype(tolua_S,"HttpDownloaderDelegate");
 tolua_usertype(tolua_S,"ResourceManager");
 tolua_usertype(tolua_S,"ViewController");
 tolua_usertype(tolua_S,"NetResponse");
 tolua_usertype(tolua_S,"NetProtocol");
 tolua_usertype(tolua_S,"JSONNumber");
 tolua_usertype(tolua_S,"Ref");
 tolua_usertype(tolua_S,"cocos2d::Ref");
 tolua_usertype(tolua_S,"FileDecryptUtil");
}

/* method: create of class  JSONObject */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONObject_create00
static int tolua_LuaFramework_JSONObject_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"JSONObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   JSONObject* tolua_ret = (JSONObject*)  JSONObject::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithString of class  JSONObject */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONObject_createWithString00
static int tolua_LuaFramework_JSONObject_createWithString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"JSONObject",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string jsonStr = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   JSONObject* tolua_ret = (JSONObject*)  JSONObject::createWithString(jsonStr);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONObject");
   tolua_pushcppstring(tolua_S,(const char*)jsonStr);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createWithString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithFile of class  JSONObject */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONObject_createWithFile00
static int tolua_LuaFramework_JSONObject_createWithFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"JSONObject",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string jsonFilePath = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   JSONObject* tolua_ret = (JSONObject*)  JSONObject::createWithFile(jsonFilePath);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONObject");
   tolua_pushcppstring(tolua_S,(const char*)jsonFilePath);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createWithFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: has of class  JSONObject */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONObject_has00
static int tolua_LuaFramework_JSONObject_has00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONObject* self = (JSONObject*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'has'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->has(key);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'has'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: count of class  JSONObject */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONObject_count00
static int tolua_LuaFramework_JSONObject_count00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONObject* self = (JSONObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'count'", NULL);
#endif
  {
   int tolua_ret = (int)  self->count();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'count'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: putBool of class  JSONObject */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONObject_putBool00
static int tolua_LuaFramework_JSONObject_putBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONObject* self = (JSONObject*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  bool value = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'putBool'", NULL);
#endif
  {
   self->putBool(key,value);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'putBool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBool of class  JSONObject */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONObject_getBool00
static int tolua_LuaFramework_JSONObject_getBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONObject* self = (JSONObject*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBool'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getBool(key);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: putNumber of class  JSONObject */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONObject_putNumber00
static int tolua_LuaFramework_JSONObject_putNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONObject* self = (JSONObject*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  double value = ((double)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'putNumber'", NULL);
#endif
  {
   self->putNumber(key,value);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'putNumber'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNumber of class  JSONObject */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONObject_getNumber00
static int tolua_LuaFramework_JSONObject_getNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONObject* self = (JSONObject*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNumber'", NULL);
#endif
  {
   double tolua_ret = (double)  self->getNumber(key);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNumber'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: putString of class  JSONObject */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONObject_putString00
static int tolua_LuaFramework_JSONObject_putString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONObject* self = (JSONObject*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'putString'", NULL);
#endif
  {
   self->putString(key,value);
   tolua_pushcppstring(tolua_S,(const char*)key);
   tolua_pushcppstring(tolua_S,(const char*)value);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'putString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getString of class  JSONObject */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONObject_getString00
static int tolua_LuaFramework_JSONObject_getString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONObject* self = (JSONObject*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getString'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getString(key);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: putJSONObject of class  JSONObject */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONObject_putJSONObject00
static int tolua_LuaFramework_JSONObject_putJSONObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"JSONObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONObject* self = (JSONObject*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  JSONObject* value = ((JSONObject*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'putJSONObject'", NULL);
#endif
  {
   self->putJSONObject(key,value);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'putJSONObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getJSONObject of class  JSONObject */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONObject_getJSONObject00
static int tolua_LuaFramework_JSONObject_getJSONObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONObject* self = (JSONObject*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getJSONObject'", NULL);
#endif
  {
   JSONObject* tolua_ret = (JSONObject*)  self->getJSONObject(key);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONObject");
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getJSONObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: putJSONArray of class  JSONObject */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONObject_putJSONArray00
static int tolua_LuaFramework_JSONObject_putJSONArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"JSONArray",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONObject* self = (JSONObject*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  JSONArray* value = ((JSONArray*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'putJSONArray'", NULL);
#endif
  {
   self->putJSONArray(key,value);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'putJSONArray'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getJSONArray of class  JSONObject */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONObject_getJSONArray00
static int tolua_LuaFramework_JSONObject_getJSONArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONObject* self = (JSONObject*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getJSONArray'", NULL);
#endif
  {
   JSONArray* tolua_ret = (JSONArray*)  self->getJSONArray(key);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONArray");
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getJSONArray'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: put of class  JSONObject */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONObject_put00
static int tolua_LuaFramework_JSONObject_put00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Ref",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONObject* self = (JSONObject*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  Ref* value = ((Ref*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'put'", NULL);
#endif
  {
   self->put(key,value);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'put'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get of class  JSONObject */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONObject_get00
static int tolua_LuaFramework_JSONObject_get00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONObject* self = (JSONObject*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get'", NULL);
#endif
  {
   Ref* tolua_ret = (Ref*)  self->get(key);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ref");
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: allKeys of class  JSONObject */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONObject_allKeys00
static int tolua_LuaFramework_JSONObject_allKeys00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONObject* self = (JSONObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'allKeys'", NULL);
#endif
  {
   __Array* tolua_ret = (__Array*)  self->allKeys();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"__Array");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'allKeys'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: remove of class  JSONObject */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONObject_remove00
static int tolua_LuaFramework_JSONObject_remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONObject* self = (JSONObject*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'remove'", NULL);
#endif
  {
   self->remove(key);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'remove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeAll of class  JSONObject */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONObject_removeAll00
static int tolua_LuaFramework_JSONObject_removeAll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONObject* self = (JSONObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAll'", NULL);
#endif
  {
   self->removeAll();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: toString of class  JSONObject */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONObject_toString00
static int tolua_LuaFramework_JSONObject_toString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONObject* self = (JSONObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'toString'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->toString();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: toPrettyString of class  JSONObject */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONObject_toPrettyString00
static int tolua_LuaFramework_JSONObject_toPrettyString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONObject* self = (JSONObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'toPrettyString'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->toPrettyString();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toPrettyString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: toLuaString of class  JSONObject */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONObject_toLuaString00
static int tolua_LuaFramework_JSONObject_toLuaString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONObject* self = (JSONObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'toLuaString'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->toLuaString();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toLuaString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  JSONArray */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONArray_create00
static int tolua_LuaFramework_JSONArray_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"JSONArray",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   JSONArray* tolua_ret = (JSONArray*)  JSONArray::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONArray");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithString of class  JSONArray */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONArray_createWithString00
static int tolua_LuaFramework_JSONArray_createWithString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"JSONArray",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string jsonStr = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   JSONArray* tolua_ret = (JSONArray*)  JSONArray::createWithString(jsonStr);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONArray");
   tolua_pushcppstring(tolua_S,(const char*)jsonStr);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createWithString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithFile of class  JSONArray */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONArray_createWithFile00
static int tolua_LuaFramework_JSONArray_createWithFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"JSONArray",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string jsonFilePath = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   JSONArray* tolua_ret = (JSONArray*)  JSONArray::createWithFile(jsonFilePath);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONArray");
   tolua_pushcppstring(tolua_S,(const char*)jsonFilePath);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createWithFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: count of class  JSONArray */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONArray_count00
static int tolua_LuaFramework_JSONArray_count00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONArray* self = (JSONArray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'count'", NULL);
#endif
  {
   int tolua_ret = (int)  self->count();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'count'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addBool of class  JSONArray */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONArray_addBool00
static int tolua_LuaFramework_JSONArray_addBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONArray* self = (JSONArray*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addBool'", NULL);
#endif
  {
   self->addBool(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addBool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: insertBool of class  JSONArray */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONArray_insertBool00
static int tolua_LuaFramework_JSONArray_insertBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONArray* self = (JSONArray*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
  unsigned int index = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'insertBool'", NULL);
#endif
  {
   self->insertBool(value,index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'insertBool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBool of class  JSONArray */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONArray_getBool00
static int tolua_LuaFramework_JSONArray_getBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONArray* self = (JSONArray*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBool'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getBool(index);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addNumber of class  JSONArray */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONArray_addNumber00
static int tolua_LuaFramework_JSONArray_addNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONArray* self = (JSONArray*)  tolua_tousertype(tolua_S,1,0);
  double value = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addNumber'", NULL);
#endif
  {
   self->addNumber(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addNumber'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: insertNumber of class  JSONArray */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONArray_insertNumber00
static int tolua_LuaFramework_JSONArray_insertNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONArray* self = (JSONArray*)  tolua_tousertype(tolua_S,1,0);
  double value = ((double)  tolua_tonumber(tolua_S,2,0));
  unsigned int index = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'insertNumber'", NULL);
#endif
  {
   self->insertNumber(value,index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'insertNumber'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNumber of class  JSONArray */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONArray_getNumber00
static int tolua_LuaFramework_JSONArray_getNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONArray* self = (JSONArray*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNumber'", NULL);
#endif
  {
   double tolua_ret = (double)  self->getNumber(index);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNumber'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addString of class  JSONArray */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONArray_addString00
static int tolua_LuaFramework_JSONArray_addString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONArray* self = (JSONArray*)  tolua_tousertype(tolua_S,1,0);
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addString'", NULL);
#endif
  {
   self->addString(value);
   tolua_pushcppstring(tolua_S,(const char*)value);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: insertString of class  JSONArray */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONArray_insertString00
static int tolua_LuaFramework_JSONArray_insertString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONArray* self = (JSONArray*)  tolua_tousertype(tolua_S,1,0);
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  unsigned int index = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'insertString'", NULL);
#endif
  {
   self->insertString(value,index);
   tolua_pushcppstring(tolua_S,(const char*)value);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'insertString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getString of class  JSONArray */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONArray_getString00
static int tolua_LuaFramework_JSONArray_getString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONArray* self = (JSONArray*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getString'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getString(index);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addJSONObject of class  JSONArray */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONArray_addJSONObject00
static int tolua_LuaFramework_JSONArray_addJSONObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"JSONObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONArray* self = (JSONArray*)  tolua_tousertype(tolua_S,1,0);
  JSONObject* value = ((JSONObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addJSONObject'", NULL);
#endif
  {
   self->addJSONObject(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addJSONObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: insertJSONObject of class  JSONArray */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONArray_insertJSONObject00
static int tolua_LuaFramework_JSONArray_insertJSONObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"JSONObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONArray* self = (JSONArray*)  tolua_tousertype(tolua_S,1,0);
  JSONObject* value = ((JSONObject*)  tolua_tousertype(tolua_S,2,0));
  unsigned int index = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'insertJSONObject'", NULL);
#endif
  {
   self->insertJSONObject(value,index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'insertJSONObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getJSONObject of class  JSONArray */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONArray_getJSONObject00
static int tolua_LuaFramework_JSONArray_getJSONObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONArray* self = (JSONArray*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getJSONObject'", NULL);
#endif
  {
   JSONObject* tolua_ret = (JSONObject*)  self->getJSONObject(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getJSONObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addJSONArray of class  JSONArray */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONArray_addJSONArray00
static int tolua_LuaFramework_JSONArray_addJSONArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"JSONArray",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONArray* self = (JSONArray*)  tolua_tousertype(tolua_S,1,0);
  JSONArray* value = ((JSONArray*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addJSONArray'", NULL);
#endif
  {
   self->addJSONArray(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addJSONArray'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: insertJSONArray of class  JSONArray */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONArray_insertJSONArray00
static int tolua_LuaFramework_JSONArray_insertJSONArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"JSONArray",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONArray* self = (JSONArray*)  tolua_tousertype(tolua_S,1,0);
  JSONArray* value = ((JSONArray*)  tolua_tousertype(tolua_S,2,0));
  unsigned int index = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'insertJSONArray'", NULL);
#endif
  {
   self->insertJSONArray(value,index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'insertJSONArray'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getJSONArray of class  JSONArray */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONArray_getJSONArray00
static int tolua_LuaFramework_JSONArray_getJSONArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONArray* self = (JSONArray*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getJSONArray'", NULL);
#endif
  {
   JSONArray* tolua_ret = (JSONArray*)  self->getJSONArray(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONArray");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getJSONArray'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  JSONArray */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONArray_add00
static int tolua_LuaFramework_JSONArray_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ref",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONArray* self = (JSONArray*)  tolua_tousertype(tolua_S,1,0);
  Ref* value = ((Ref*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'", NULL);
#endif
  {
   self->add(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: insert of class  JSONArray */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONArray_insert00
static int tolua_LuaFramework_JSONArray_insert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ref",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONArray* self = (JSONArray*)  tolua_tousertype(tolua_S,1,0);
  Ref* value = ((Ref*)  tolua_tousertype(tolua_S,2,0));
  unsigned int index = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'insert'", NULL);
#endif
  {
   self->insert(value,index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'insert'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get of class  JSONArray */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONArray_get00
static int tolua_LuaFramework_JSONArray_get00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONArray* self = (JSONArray*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get'", NULL);
#endif
  {
   Ref* tolua_ret = (Ref*)  self->get(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ref");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeLast of class  JSONArray */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONArray_removeLast00
static int tolua_LuaFramework_JSONArray_removeLast00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONArray* self = (JSONArray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeLast'", NULL);
#endif
  {
   self->removeLast();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeLast'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: remove of class  JSONArray */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONArray_remove00
static int tolua_LuaFramework_JSONArray_remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONArray* self = (JSONArray*)  tolua_tousertype(tolua_S,1,0);
  unsigned int index = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'remove'", NULL);
#endif
  {
   self->remove(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'remove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeAll of class  JSONArray */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONArray_removeAll00
static int tolua_LuaFramework_JSONArray_removeAll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONArray* self = (JSONArray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAll'", NULL);
#endif
  {
   self->removeAll();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: toString of class  JSONArray */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONArray_toString00
static int tolua_LuaFramework_JSONArray_toString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONArray* self = (JSONArray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'toString'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->toString();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: toPrettyString of class  JSONArray */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONArray_toPrettyString00
static int tolua_LuaFramework_JSONArray_toPrettyString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONArray* self = (JSONArray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'toPrettyString'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->toPrettyString();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toPrettyString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: toLuaString of class  JSONArray */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONArray_toLuaString00
static int tolua_LuaFramework_JSONArray_toLuaString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONArray",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONArray* self = (JSONArray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'toLuaString'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->toLuaString();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toLuaString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: boolValue of class  JSONElement */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONElement_boolValue00
static int tolua_LuaFramework_JSONElement_boolValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONElement* self = (JSONElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'boolValue'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->boolValue();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'boolValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: numberValue of class  JSONElement */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONElement_numberValue00
static int tolua_LuaFramework_JSONElement_numberValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONElement* self = (JSONElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'numberValue'", NULL);
#endif
  {
   double tolua_ret = (double)  self->numberValue();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'numberValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stringValue of class  JSONElement */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONElement_stringValue00
static int tolua_LuaFramework_JSONElement_stringValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONElement* self = (JSONElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stringValue'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->stringValue();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stringValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  JSONBool */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONBool_create00
static int tolua_LuaFramework_JSONBool_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"JSONBool",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
  {
   JSONBool* tolua_ret = (JSONBool*)  JSONBool::create(value);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONBool");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: boolValue of class  JSONBool */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONBool_boolValue00
static int tolua_LuaFramework_JSONBool_boolValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONBool",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONBool* self = (JSONBool*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'boolValue'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->boolValue();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'boolValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: numberValue of class  JSONBool */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONBool_numberValue00
static int tolua_LuaFramework_JSONBool_numberValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONBool",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONBool* self = (JSONBool*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'numberValue'", NULL);
#endif
  {
   double tolua_ret = (double)  self->numberValue();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'numberValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stringValue of class  JSONBool */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONBool_stringValue00
static int tolua_LuaFramework_JSONBool_stringValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONBool",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONBool* self = (JSONBool*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stringValue'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->stringValue();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stringValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  JSONNumber */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONNumber_create00
static int tolua_LuaFramework_JSONNumber_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"JSONNumber",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  double value = ((double)  tolua_tonumber(tolua_S,2,0));
  {
   JSONNumber* tolua_ret = (JSONNumber*)  JSONNumber::create(value);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONNumber");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: boolValue of class  JSONNumber */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONNumber_boolValue00
static int tolua_LuaFramework_JSONNumber_boolValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONNumber",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONNumber* self = (JSONNumber*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'boolValue'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->boolValue();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'boolValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: numberValue of class  JSONNumber */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONNumber_numberValue00
static int tolua_LuaFramework_JSONNumber_numberValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONNumber",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONNumber* self = (JSONNumber*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'numberValue'", NULL);
#endif
  {
   double tolua_ret = (double)  self->numberValue();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'numberValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stringValue of class  JSONNumber */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONNumber_stringValue00
static int tolua_LuaFramework_JSONNumber_stringValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONNumber",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONNumber* self = (JSONNumber*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stringValue'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->stringValue();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stringValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  JSONString */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONString_create00
static int tolua_LuaFramework_JSONString_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"JSONString",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   JSONString* tolua_ret = (JSONString*)  JSONString::create(value);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONString");
   tolua_pushcppstring(tolua_S,(const char*)value);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: boolValue of class  JSONString */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONString_boolValue00
static int tolua_LuaFramework_JSONString_boolValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONString",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONString* self = (JSONString*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'boolValue'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->boolValue();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'boolValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: numberValue of class  JSONString */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONString_numberValue00
static int tolua_LuaFramework_JSONString_numberValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONString",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONString* self = (JSONString*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'numberValue'", NULL);
#endif
  {
   double tolua_ret = (double)  self->numberValue();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'numberValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stringValue of class  JSONString */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_JSONString_stringValue00
static int tolua_LuaFramework_JSONString_stringValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"JSONString",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  JSONString* self = (JSONString*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stringValue'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->stringValue();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stringValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: openSQLite of class  SQLite */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_SQLite_openSQLite00
static int tolua_LuaFramework_SQLite_openSQLite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SQLite",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string dbFile = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   SQLite* tolua_ret = (SQLite*)  SQLite::openSQLite(dbFile);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SQLite");
   tolua_pushcppstring(tolua_S,(const char*)dbFile);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'openSQLite'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearConnectionCache of class  SQLite */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_SQLite_clearConnectionCache00
static int tolua_LuaFramework_SQLite_clearConnectionCache00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SQLite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SQLite::clearConnectionCache();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearConnectionCache'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getValueTypeName of class  SQLite */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_SQLite_getValueTypeName00
static int tolua_LuaFramework_SQLite_getValueTypeName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SQLite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ref",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SQLite* self = (SQLite*)  tolua_tousertype(tolua_S,1,0);
  Ref* value = ((Ref*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getValueTypeName'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getValueTypeName(value);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getValueTypeName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createTable of class  SQLite */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_SQLite_createTable00
static int tolua_LuaFramework_SQLite_createTable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SQLite",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"__Array",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SQLite* self = (SQLite*)  tolua_tousertype(tolua_S,1,0);
  const std::string tableName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  __Array* columnArray = ((__Array*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createTable'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->createTable(tableName,columnArray);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)tableName);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createTable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dropTable of class  SQLite */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_SQLite_dropTable00
static int tolua_LuaFramework_SQLite_dropTable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SQLite",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SQLite* self = (SQLite*)  tolua_tousertype(tolua_S,1,0);
  const std::string tableName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dropTable'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->dropTable(tableName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)tableName);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dropTable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: insertIntoTable of class  SQLite */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_SQLite_insertIntoTable00
static int tolua_LuaFramework_SQLite_insertIntoTable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SQLite",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"__Dictionary",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SQLite* self = (SQLite*)  tolua_tousertype(tolua_S,1,0);
  const std::string tableName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  __Dictionary* keyValueDict = ((__Dictionary*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'insertIntoTable'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->insertIntoTable(tableName,keyValueDict);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)tableName);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'insertIntoTable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearTable of class  SQLite */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_SQLite_clearTable00
static int tolua_LuaFramework_SQLite_clearTable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SQLite",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SQLite* self = (SQLite*)  tolua_tousertype(tolua_S,1,0);
  const std::string tableName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearTable'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->clearTable(tableName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)tableName);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearTable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: deleteFromTable of class  SQLite */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_SQLite_deleteFromTable00
static int tolua_LuaFramework_SQLite_deleteFromTable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SQLite",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"__Dictionary",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SQLite* self = (SQLite*)  tolua_tousertype(tolua_S,1,0);
  const std::string tableName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  __Dictionary* conditionDict = ((__Dictionary*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'deleteFromTable'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->deleteFromTable(tableName,conditionDict);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)tableName);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'deleteFromTable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: deleteFromTable of class  SQLite */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_SQLite_deleteFromTable01
static int tolua_LuaFramework_SQLite_deleteFromTable01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SQLite",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  SQLite* self = (SQLite*)  tolua_tousertype(tolua_S,1,0);
  const std::string tableName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string columnName = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string columnValue = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'deleteFromTable'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->deleteFromTable(tableName,columnName,columnValue);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)tableName);
   tolua_pushcppstring(tolua_S,(const char*)columnName);
   tolua_pushcppstring(tolua_S,(const char*)columnValue);
  }
 }
 return 4;
tolua_lerror:
 return tolua_LuaFramework_SQLite_deleteFromTable00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateTable of class  SQLite */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_SQLite_updateTable00
static int tolua_LuaFramework_SQLite_updateTable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SQLite",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"__Dictionary",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"__Dictionary",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SQLite* self = (SQLite*)  tolua_tousertype(tolua_S,1,0);
  const std::string tableName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  __Dictionary* keyValueDict = ((__Dictionary*)  tolua_tousertype(tolua_S,3,0));
  __Dictionary* conditionDict = ((__Dictionary*)  tolua_tousertype(tolua_S,4,NULL));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateTable'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->updateTable(tableName,keyValueDict,conditionDict);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)tableName);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateTable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateTable of class  SQLite */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_SQLite_updateTable01
static int tolua_LuaFramework_SQLite_updateTable01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SQLite",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"__Dictionary",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  SQLite* self = (SQLite*)  tolua_tousertype(tolua_S,1,0);
  const std::string tableName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  __Dictionary* keyValueDict = ((__Dictionary*)  tolua_tousertype(tolua_S,3,0));
  const std::string columnName = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
  const std::string columnValue = ((const std::string)  tolua_tocppstring(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateTable'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->updateTable(tableName,keyValueDict,columnName,columnValue);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)tableName);
   tolua_pushcppstring(tolua_S,(const char*)columnName);
   tolua_pushcppstring(tolua_S,(const char*)columnValue);
  }
 }
 return 4;
tolua_lerror:
 return tolua_LuaFramework_SQLite_updateTable00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: selectTable of class  SQLite */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_SQLite_selectTable00
static int tolua_LuaFramework_SQLite_selectTable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SQLite",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"__Dictionary",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SQLite* self = (SQLite*)  tolua_tousertype(tolua_S,1,0);
  const std::string tableName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  __Dictionary* conditionDict = ((__Dictionary*)  tolua_tousertype(tolua_S,3,NULL));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'selectTable'", NULL);
#endif
  {
   __Array* tolua_ret = (__Array*)  self->selectTable(tableName,conditionDict);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"__Array");
   tolua_pushcppstring(tolua_S,(const char*)tableName);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'selectTable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: selectTable of class  SQLite */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_SQLite_selectTable01
static int tolua_LuaFramework_SQLite_selectTable01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SQLite",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  SQLite* self = (SQLite*)  tolua_tousertype(tolua_S,1,0);
  const std::string tableName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string columnName = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string columnValue = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'selectTable'", NULL);
#endif
  {
   __Array* tolua_ret = (__Array*)  self->selectTable(tableName,columnName,columnValue);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"__Array");
   tolua_pushcppstring(tolua_S,(const char*)tableName);
   tolua_pushcppstring(tolua_S,(const char*)columnName);
   tolua_pushcppstring(tolua_S,(const char*)columnValue);
  }
 }
 return 4;
tolua_lerror:
 return tolua_LuaFramework_SQLite_selectTable00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: selectTable of class  SQLite */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_SQLite_selectTable02
static int tolua_LuaFramework_SQLite_selectTable02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SQLite",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"__Array",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  SQLite* self = (SQLite*)  tolua_tousertype(tolua_S,1,0);
  const std::string tableName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string columnName = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  __Array* columnValues = ((__Array*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'selectTable'", NULL);
#endif
  {
   __Array* tolua_ret = (__Array*)  self->selectTable(tableName,columnName,columnValues);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"__Array");
   tolua_pushcppstring(tolua_S,(const char*)tableName);
   tolua_pushcppstring(tolua_S,(const char*)columnName);
  }
 }
 return 3;
tolua_lerror:
 return tolua_LuaFramework_SQLite_selectTable01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: selectTable of class  SQLite */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_SQLite_selectTable03
static int tolua_LuaFramework_SQLite_selectTable03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SQLite",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  SQLite* self = (SQLite*)  tolua_tousertype(tolua_S,1,0);
  const std::string tableName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string sql = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'selectTable'", NULL);
#endif
  {
   __Array* tolua_ret = (__Array*)  self->selectTable(tableName,sql);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"__Array");
   tolua_pushcppstring(tolua_S,(const char*)tableName);
   tolua_pushcppstring(tolua_S,(const char*)sql);
  }
 }
 return 3;
tolua_lerror:
 return tolua_LuaFramework_SQLite_selectTable02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRecordCount of class  SQLite */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_SQLite_getRecordCount00
static int tolua_LuaFramework_SQLite_getRecordCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SQLite",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SQLite* self = (SQLite*)  tolua_tousertype(tolua_S,1,0);
  const std::string tableName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRecordCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getRecordCount(tableName);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)tableName);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRecordCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sharedNetCenter of class  NetCenter */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetCenter_sharedNetCenter00
static int tolua_LuaFramework_NetCenter_sharedNetCenter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NetCenter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   NetCenter* tolua_ret = (NetCenter*)  NetCenter::sharedNetCenter();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NetCenter");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sharedNetCenter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addNetService of class  NetCenter */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetCenter_addNetService00
static int tolua_LuaFramework_NetCenter_addNetService00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetCenter",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"NetService",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetCenter* self = (NetCenter*)  tolua_tousertype(tolua_S,1,0);
  const std::string serviceID = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  NetService* service = ((NetService*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addNetService'", NULL);
#endif
  {
   self->addNetService(serviceID,service);
   tolua_pushcppstring(tolua_S,(const char*)serviceID);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addNetService'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeNetService of class  NetCenter */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetCenter_removeNetService00
static int tolua_LuaFramework_NetCenter_removeNetService00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetCenter",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetCenter* self = (NetCenter*)  tolua_tousertype(tolua_S,1,0);
  const std::string serviceID = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeNetService'", NULL);
#endif
  {
   self->removeNetService(serviceID);
   tolua_pushcppstring(tolua_S,(const char*)serviceID);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeNetService'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addNetProtocol of class  NetCenter */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetCenter_addNetProtocol00
static int tolua_LuaFramework_NetCenter_addNetProtocol00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetCenter",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"NetHandler",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetCenter* self = (NetCenter*)  tolua_tousertype(tolua_S,1,0);
  const std::string protocolID = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string serviceID = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  NetHandler* handler = ((NetHandler*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addNetProtocol'", NULL);
#endif
  {
   self->addNetProtocol(protocolID,serviceID,handler);
   tolua_pushcppstring(tolua_S,(const char*)protocolID);
   tolua_pushcppstring(tolua_S,(const char*)serviceID);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addNetProtocol'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addNetProtocol of class  NetCenter */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetCenter_addNetProtocol01
static int tolua_LuaFramework_NetCenter_addNetProtocol01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetCenter",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"NetProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  NetCenter* self = (NetCenter*)  tolua_tousertype(tolua_S,1,0);
  NetProtocol* protocol = ((NetProtocol*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addNetProtocol'", NULL);
#endif
  {
   self->addNetProtocol(protocol);
  }
 }
 return 0;
tolua_lerror:
 return tolua_LuaFramework_NetCenter_addNetProtocol00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeNetProtocol of class  NetCenter */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetCenter_removeNetProtocol00
static int tolua_LuaFramework_NetCenter_removeNetProtocol00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetCenter",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetCenter* self = (NetCenter*)  tolua_tousertype(tolua_S,1,0);
  const std::string protocolID = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeNetProtocol'", NULL);
#endif
  {
   self->removeNetProtocol(protocolID);
   tolua_pushcppstring(tolua_S,(const char*)protocolID);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeNetProtocol'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeNetProtocolForNetService of class  NetCenter */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetCenter_removeNetProtocolForNetService00
static int tolua_LuaFramework_NetCenter_removeNetProtocolForNetService00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetCenter",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetCenter* self = (NetCenter*)  tolua_tousertype(tolua_S,1,0);
  const std::string serviceID = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeNetProtocolForNetService'", NULL);
#endif
  {
   self->removeNetProtocolForNetService(serviceID);
   tolua_pushcppstring(tolua_S,(const char*)serviceID);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeNetProtocolForNetService'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addNetFilter of class  NetCenter */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetCenter_addNetFilter00
static int tolua_LuaFramework_NetCenter_addNetFilter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetCenter",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"NetFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetCenter* self = (NetCenter*)  tolua_tousertype(tolua_S,1,0);
  NetFilter* filter = ((NetFilter*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addNetFilter'", NULL);
#endif
  {
   self->addNetFilter(filter);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addNetFilter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeNetFilter of class  NetCenter */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetCenter_removeNetFilter00
static int tolua_LuaFramework_NetCenter_removeNetFilter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetCenter",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"NetFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetCenter* self = (NetCenter*)  tolua_tousertype(tolua_S,1,0);
  NetFilter* filter = ((NetFilter*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeNetFilter'", NULL);
#endif
  {
   self->removeNetFilter(filter);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeNetFilter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeAllNetFilters of class  NetCenter */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetCenter_removeAllNetFilters00
static int tolua_LuaFramework_NetCenter_removeAllNetFilters00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetCenter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetCenter* self = (NetCenter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAllNetFilters'", NULL);
#endif
  {
   self->removeAllNetFilters();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAllNetFilters'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendMessage of class  NetCenter */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetCenter_sendMessage00
static int tolua_LuaFramework_NetCenter_sendMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetCenter",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"NetRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetCenter* self = (NetCenter*)  tolua_tousertype(tolua_S,1,0);
  NetRequest* request = ((NetRequest*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendMessage'", NULL);
#endif
  {
   self->sendMessage(request);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendMessage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dispatchSuccessfulMessage of class  NetCenter */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetCenter_dispatchSuccessfulMessage00
static int tolua_LuaFramework_NetCenter_dispatchSuccessfulMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetCenter",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"NetResponse",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetCenter* self = (NetCenter*)  tolua_tousertype(tolua_S,1,0);
  NetResponse* response = ((NetResponse*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dispatchSuccessfulMessage'", NULL);
#endif
  {
   self->dispatchSuccessfulMessage(response);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dispatchSuccessfulMessage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dispatchFailedMessage of class  NetCenter */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetCenter_dispatchFailedMessage00
static int tolua_LuaFramework_NetCenter_dispatchFailedMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetCenter",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"NetResponse",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetCenter* self = (NetCenter*)  tolua_tousertype(tolua_S,1,0);
  NetResponse* response = ((NetResponse*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dispatchFailedMessage'", NULL);
#endif
  {
   self->dispatchFailedMessage(response);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dispatchFailedMessage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendCommand of class  NetCenter */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetCenter_sendCommand00
static int tolua_LuaFramework_NetCenter_sendCommand00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetCenter",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"cocos2d::Ref",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetCenter* self = (NetCenter*)  tolua_tousertype(tolua_S,1,0);
  const std::string serviceID = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string command = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  cocos2d::Ref* param = ((cocos2d::Ref*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendCommand'", NULL);
#endif
  {
   self->sendCommand(serviceID,command,param);
   tolua_pushcppstring(tolua_S,(const char*)serviceID);
   tolua_pushcppstring(tolua_S,(const char*)command);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendCommand'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  NetFilter */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetFilter_create00
static int tolua_LuaFramework_NetFilter_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NetFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   NetFilter* tolua_ret = (NetFilter*)  NetFilter::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NetFilter");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: filterSuccessfulMessage of class  NetFilter */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetFilter_filterSuccessfulMessage00
static int tolua_LuaFramework_NetFilter_filterSuccessfulMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetFilter",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"NetResponse",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetFilter* self = (NetFilter*)  tolua_tousertype(tolua_S,1,0);
  NetResponse* response = ((NetResponse*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'filterSuccessfulMessage'", NULL);
#endif
  {
   NetResponse* tolua_ret = (NetResponse*)  self->filterSuccessfulMessage(response);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NetResponse");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'filterSuccessfulMessage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: filterFailedMessage of class  NetFilter */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetFilter_filterFailedMessage00
static int tolua_LuaFramework_NetFilter_filterFailedMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetFilter",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"NetResponse",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetFilter* self = (NetFilter*)  tolua_tousertype(tolua_S,1,0);
  NetResponse* response = ((NetResponse*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'filterFailedMessage'", NULL);
#endif
  {
   NetResponse* tolua_ret = (NetResponse*)  self->filterFailedMessage(response);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NetResponse");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'filterFailedMessage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  NetHandler */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetHandler_create00
static int tolua_LuaFramework_NetHandler_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NetHandler",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   NetHandler* tolua_ret = (NetHandler*)  NetHandler::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NetHandler");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: handleSuccessfulMessage of class  NetHandler */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetHandler_handleSuccessfulMessage00
static int tolua_LuaFramework_NetHandler_handleSuccessfulMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetHandler",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"NetResponse",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetHandler* self = (NetHandler*)  tolua_tousertype(tolua_S,1,0);
  NetResponse* response = ((NetResponse*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'handleSuccessfulMessage'", NULL);
#endif
  {
   self->handleSuccessfulMessage(response);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'handleSuccessfulMessage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: handleFailedMessage of class  NetHandler */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetHandler_handleFailedMessage00
static int tolua_LuaFramework_NetHandler_handleFailedMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetHandler",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"NetResponse",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetHandler* self = (NetHandler*)  tolua_tousertype(tolua_S,1,0);
  NetResponse* response = ((NetResponse*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'handleFailedMessage'", NULL);
#endif
  {
   self->handleFailedMessage(response);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'handleFailedMessage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  NetProtocol */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetProtocol_create00
static int tolua_LuaFramework_NetProtocol_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NetProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   NetProtocol* tolua_ret = (NetProtocol*)  NetProtocol::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NetProtocol");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  NetProtocol */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetProtocol_create01
static int tolua_LuaFramework_NetProtocol_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NetProtocol",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"NetHandler",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const std::string protocolID = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string serviceID = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  NetHandler* handler = ((NetHandler*)  tolua_tousertype(tolua_S,4,0));
  {
   NetProtocol* tolua_ret = (NetProtocol*)  NetProtocol::create(protocolID,serviceID,handler);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NetProtocol");
   tolua_pushcppstring(tolua_S,(const char*)protocolID);
   tolua_pushcppstring(tolua_S,(const char*)serviceID);
  }
 }
 return 3;
tolua_lerror:
 return tolua_LuaFramework_NetProtocol_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setID of class  NetProtocol */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetProtocol_setID00
static int tolua_LuaFramework_NetProtocol_setID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetProtocol",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetProtocol* self = (NetProtocol*)  tolua_tousertype(tolua_S,1,0);
  const std::string protocolID = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setID'", NULL);
#endif
  {
   self->setID(protocolID);
   tolua_pushcppstring(tolua_S,(const char*)protocolID);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getID of class  NetProtocol */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetProtocol_getID00
static int tolua_LuaFramework_NetProtocol_getID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetProtocol* self = (NetProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getID'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->getID();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setServiceID of class  NetProtocol */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetProtocol_setServiceID00
static int tolua_LuaFramework_NetProtocol_setServiceID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetProtocol",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetProtocol* self = (NetProtocol*)  tolua_tousertype(tolua_S,1,0);
  const std::string serviceID = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setServiceID'", NULL);
#endif
  {
   self->setServiceID(serviceID);
   tolua_pushcppstring(tolua_S,(const char*)serviceID);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setServiceID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getServiceID of class  NetProtocol */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetProtocol_getServiceID00
static int tolua_LuaFramework_NetProtocol_getServiceID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetProtocol* self = (NetProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getServiceID'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->getServiceID();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getServiceID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setHandler of class  NetProtocol */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetProtocol_setHandler00
static int tolua_LuaFramework_NetProtocol_setHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetProtocol",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"NetHandler",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetProtocol* self = (NetProtocol*)  tolua_tousertype(tolua_S,1,0);
  NetHandler* handler = ((NetHandler*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setHandler'", NULL);
#endif
  {
   self->setHandler(handler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHandler of class  NetProtocol */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetProtocol_getHandler00
static int tolua_LuaFramework_NetProtocol_getHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetProtocol* self = (NetProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHandler'", NULL);
#endif
  {
   NetHandler* tolua_ret = (NetHandler*)  self->getHandler();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NetHandler");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  NetRequest */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetRequest_create00
static int tolua_LuaFramework_NetRequest_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NetRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   NetRequest* tolua_ret = (NetRequest*)  NetRequest::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NetRequest");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  NetRequest */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetRequest_create01
static int tolua_LuaFramework_NetRequest_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NetRequest",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"JSONObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const std::string protocolID = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  JSONObject* body = ((JSONObject*)  tolua_tousertype(tolua_S,3,0));
  {
   NetRequest* tolua_ret = (NetRequest*)  NetRequest::create(protocolID,body);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NetRequest");
   tolua_pushcppstring(tolua_S,(const char*)protocolID);
  }
 }
 return 2;
tolua_lerror:
 return tolua_LuaFramework_NetRequest_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setProtocolID of class  NetRequest */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetRequest_setProtocolID00
static int tolua_LuaFramework_NetRequest_setProtocolID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetRequest",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetRequest* self = (NetRequest*)  tolua_tousertype(tolua_S,1,0);
  const std::string protocolID = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setProtocolID'", NULL);
#endif
  {
   self->setProtocolID(protocolID);
   tolua_pushcppstring(tolua_S,(const char*)protocolID);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setProtocolID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getProtocolID of class  NetRequest */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetRequest_getProtocolID00
static int tolua_LuaFramework_NetRequest_getProtocolID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetRequest* self = (NetRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getProtocolID'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->getProtocolID();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getProtocolID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBody of class  NetRequest */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetRequest_setBody00
static int tolua_LuaFramework_NetRequest_setBody00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetRequest",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"JSONObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetRequest* self = (NetRequest*)  tolua_tousertype(tolua_S,1,0);
  JSONObject* body = ((JSONObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBody'", NULL);
#endif
  {
   self->setBody(body);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBody'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBody of class  NetRequest */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetRequest_getBody00
static int tolua_LuaFramework_NetRequest_getBody00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetRequest* self = (NetRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBody'", NULL);
#endif
  {
   JSONObject* tolua_ret = (JSONObject*)  self->getBody();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBody'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setConfigInfo of class  NetRequest */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetRequest_setConfigInfo00
static int tolua_LuaFramework_NetRequest_setConfigInfo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetRequest",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"JSONObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetRequest* self = (NetRequest*)  tolua_tousertype(tolua_S,1,0);
  JSONObject* configInfo = ((JSONObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setConfigInfo'", NULL);
#endif
  {
   self->setConfigInfo(configInfo);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setConfigInfo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getConfigInfo of class  NetRequest */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetRequest_getConfigInfo00
static int tolua_LuaFramework_NetRequest_getConfigInfo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetRequest* self = (NetRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getConfigInfo'", NULL);
#endif
  {
   JSONObject* tolua_ret = (JSONObject*)  self->getConfigInfo();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getConfigInfo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  NetResponse */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetResponse_create00
static int tolua_LuaFramework_NetResponse_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NetResponse",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   NetResponse* tolua_ret = (NetResponse*)  NetResponse::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NetResponse");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  NetResponse */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetResponse_create01
static int tolua_LuaFramework_NetResponse_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NetResponse",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"JSONObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"NetRequest",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const std::string protocolID = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  JSONObject* body = ((JSONObject*)  tolua_tousertype(tolua_S,3,0));
  NetRequest* request = ((NetRequest*)  tolua_tousertype(tolua_S,4,NULL));
  {
   NetResponse* tolua_ret = (NetResponse*)  NetResponse::create(protocolID,body,request);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NetResponse");
   tolua_pushcppstring(tolua_S,(const char*)protocolID);
  }
 }
 return 2;
tolua_lerror:
 return tolua_LuaFramework_NetResponse_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setProtocolID of class  NetResponse */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetResponse_setProtocolID00
static int tolua_LuaFramework_NetResponse_setProtocolID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetResponse",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetResponse* self = (NetResponse*)  tolua_tousertype(tolua_S,1,0);
  const std::string protocolID = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setProtocolID'", NULL);
#endif
  {
   self->setProtocolID(protocolID);
   tolua_pushcppstring(tolua_S,(const char*)protocolID);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setProtocolID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getProtocolID of class  NetResponse */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetResponse_getProtocolID00
static int tolua_LuaFramework_NetResponse_getProtocolID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetResponse",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetResponse* self = (NetResponse*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getProtocolID'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->getProtocolID();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getProtocolID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBody of class  NetResponse */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetResponse_setBody00
static int tolua_LuaFramework_NetResponse_setBody00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetResponse",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"JSONObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetResponse* self = (NetResponse*)  tolua_tousertype(tolua_S,1,0);
  JSONObject* body = ((JSONObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBody'", NULL);
#endif
  {
   self->setBody(body);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBody'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBody of class  NetResponse */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetResponse_getBody00
static int tolua_LuaFramework_NetResponse_getBody00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetResponse",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetResponse* self = (NetResponse*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBody'", NULL);
#endif
  {
   JSONObject* tolua_ret = (JSONObject*)  self->getBody();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"JSONObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBody'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRequest of class  NetResponse */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetResponse_setRequest00
static int tolua_LuaFramework_NetResponse_setRequest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetResponse",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"NetRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetResponse* self = (NetResponse*)  tolua_tousertype(tolua_S,1,0);
  NetRequest* request = ((NetRequest*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRequest'", NULL);
#endif
  {
   self->setRequest(request);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRequest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRequest of class  NetResponse */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetResponse_getRequest00
static int tolua_LuaFramework_NetResponse_getRequest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetResponse",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetResponse* self = (NetResponse*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRequest'", NULL);
#endif
  {
   NetRequest* tolua_ret = (NetRequest*)  self->getRequest();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NetRequest");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRequest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendMessage of class  NetService */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetService_sendMessage00
static int tolua_LuaFramework_NetService_sendMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetService",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"NetRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetService* self = (NetService*)  tolua_tousertype(tolua_S,1,0);
  NetRequest* request = ((NetRequest*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendMessage'", NULL);
#endif
  {
   self->sendMessage(request);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendMessage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: executeCommand of class  NetService */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetService_executeCommand00
static int tolua_LuaFramework_NetService_executeCommand00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetService",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Ref",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetService* self = (NetService*)  tolua_tousertype(tolua_S,1,0);
  const std::string command = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  Ref* param = ((Ref*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'executeCommand'", NULL);
#endif
  {
   self->executeCommand(command,param);
   tolua_pushcppstring(tolua_S,(const char*)command);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'executeCommand'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  GameScene */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_GameScene_create00
static int tolua_LuaFramework_GameScene_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GameScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GameScene* tolua_ret = (GameScene*)  GameScene::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameScene");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: putAttribute of class  GameScene */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_GameScene_putAttribute00
static int tolua_LuaFramework_GameScene_putAttribute00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameScene",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameScene* self = (GameScene*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  bool value = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'putAttribute'", NULL);
#endif
  {
   self->putAttribute(key,value);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'putAttribute'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: putAttribute of class  GameScene */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_GameScene_putAttribute01
static int tolua_LuaFramework_GameScene_putAttribute01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameScene",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GameScene* self = (GameScene*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  int value = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'putAttribute'", NULL);
#endif
  {
   self->putAttribute(key,value);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 1;
tolua_lerror:
 return tolua_LuaFramework_GameScene_putAttribute00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: putAttribute of class  GameScene */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_GameScene_putAttribute02
static int tolua_LuaFramework_GameScene_putAttribute02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameScene",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GameScene* self = (GameScene*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  double value = ((double)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'putAttribute'", NULL);
#endif
  {
   self->putAttribute(key,value);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 1;
tolua_lerror:
 return tolua_LuaFramework_GameScene_putAttribute01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: putAttribute of class  GameScene */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_GameScene_putAttribute03
static int tolua_LuaFramework_GameScene_putAttribute03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameScene",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GameScene* self = (GameScene*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'putAttribute'", NULL);
#endif
  {
   self->putAttribute(key,value);
   tolua_pushcppstring(tolua_S,(const char*)key);
   tolua_pushcppstring(tolua_S,(const char*)value);
  }
 }
 return 2;
tolua_lerror:
 return tolua_LuaFramework_GameScene_putAttribute02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: putAttribute of class  GameScene */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_GameScene_putAttribute04
static int tolua_LuaFramework_GameScene_putAttribute04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameScene",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Ref",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GameScene* self = (GameScene*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  Ref* value = ((Ref*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'putAttribute'", NULL);
#endif
  {
   self->putAttribute(key,value);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 1;
tolua_lerror:
 return tolua_LuaFramework_GameScene_putAttribute03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBoolAttribute of class  GameScene */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_GameScene_getBoolAttribute00
static int tolua_LuaFramework_GameScene_getBoolAttribute00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameScene",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameScene* self = (GameScene*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBoolAttribute'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getBoolAttribute(key);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBoolAttribute'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getIntAttribute of class  GameScene */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_GameScene_getIntAttribute00
static int tolua_LuaFramework_GameScene_getIntAttribute00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameScene",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameScene* self = (GameScene*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getIntAttribute'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getIntAttribute(key);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getIntAttribute'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDoubleAttribute of class  GameScene */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_GameScene_getDoubleAttribute00
static int tolua_LuaFramework_GameScene_getDoubleAttribute00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameScene",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameScene* self = (GameScene*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDoubleAttribute'", NULL);
#endif
  {
   double tolua_ret = (double)  self->getDoubleAttribute(key);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDoubleAttribute'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getStringAttribute of class  GameScene */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_GameScene_getStringAttribute00
static int tolua_LuaFramework_GameScene_getStringAttribute00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameScene",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameScene* self = (GameScene*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStringAttribute'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getStringAttribute(key);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStringAttribute'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAttribute of class  GameScene */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_GameScene_getAttribute00
static int tolua_LuaFramework_GameScene_getAttribute00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameScene",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameScene* self = (GameScene*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAttribute'", NULL);
#endif
  {
   Ref* tolua_ret = (Ref*)  self->getAttribute(key);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ref");
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAttribute'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadViewController of class  GameScene */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_GameScene_loadViewController00
static int tolua_LuaFramework_GameScene_loadViewController00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameScene",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ViewController",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameScene* self = (GameScene*)  tolua_tousertype(tolua_S,1,0);
  ViewController* viewCotroller = ((ViewController*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadViewController'", NULL);
#endif
  {
   self->loadViewController(viewCotroller);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadViewController'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unloadViewController of class  GameScene */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_GameScene_unloadViewController00
static int tolua_LuaFramework_GameScene_unloadViewController00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameScene",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ViewController",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameScene* self = (GameScene*)  tolua_tousertype(tolua_S,1,0);
  ViewController* viewCotroller = ((ViewController*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unloadViewController'", NULL);
#endif
  {
   self->unloadViewController(viewCotroller);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unloadViewController'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unloadAllViewController of class  GameScene */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_GameScene_unloadAllViewController00
static int tolua_LuaFramework_GameScene_unloadAllViewController00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameScene* self = (GameScene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unloadAllViewController'", NULL);
#endif
  {
   self->unloadAllViewController();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unloadAllViewController'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  ViewController */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_ViewController_create00
static int tolua_LuaFramework_ViewController_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ViewController",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ViewController* tolua_ret = (ViewController*)  ViewController::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ViewController");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getScene of class  ViewController */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_ViewController_getScene00
static int tolua_LuaFramework_ViewController_getScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ViewController",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ViewController* self = (ViewController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScene'", NULL);
#endif
  {
   GameScene* tolua_ret = (GameScene*)  self->getScene();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameScene");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sharedResourceManager of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_ResourceManager_sharedResourceManager00
static int tolua_LuaFramework_ResourceManager_sharedResourceManager00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ResourceManager* tolua_ret = (ResourceManager*)  ResourceManager::sharedResourceManager();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ResourceManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sharedResourceManager'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDelegate of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_ResourceManager_setDelegate00
static int tolua_LuaFramework_ResourceManager_setDelegate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"ResourceUpdateDelegate",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
  ResourceUpdateDelegate* delegate = ((ResourceUpdateDelegate*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDelegate'", NULL);
#endif
  {
   self->setDelegate(delegate);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDelegate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDelegate of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_ResourceManager_getDelegate00
static int tolua_LuaFramework_ResourceManager_getDelegate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDelegate'", NULL);
#endif
  {
   ResourceUpdateDelegate* tolua_ret = (ResourceUpdateDelegate*)  self->getDelegate();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ResourceUpdateDelegate");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDelegate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScriptDelegate of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_ResourceManager_setScriptDelegate00
static int tolua_LuaFramework_ResourceManager_setScriptDelegate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Ref",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
  Ref* scriptDelegate = ((Ref*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScriptDelegate'", NULL);
#endif
  {
   self->setScriptDelegate(scriptDelegate);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScriptDelegate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getScriptDelegate of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_ResourceManager_getScriptDelegate00
static int tolua_LuaFramework_ResourceManager_getScriptDelegate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScriptDelegate'", NULL);
#endif
  {
   Ref* tolua_ret = (Ref*)  self->getScriptDelegate();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Ref");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScriptDelegate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setProgramVersion of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_ResourceManager_setProgramVersion00
static int tolua_LuaFramework_ResourceManager_setProgramVersion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
  float programVersion = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setProgramVersion'", NULL);
#endif
  {
   self->setProgramVersion(programVersion);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setProgramVersion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getProgramVersion of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_ResourceManager_getProgramVersion00
static int tolua_LuaFramework_ResourceManager_getProgramVersion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getProgramVersion'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getProgramVersion();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getProgramVersion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBundleResourceVersion of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_ResourceManager_setBundleResourceVersion00
static int tolua_LuaFramework_ResourceManager_setBundleResourceVersion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
  float bundleResourceVersion = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBundleResourceVersion'", NULL);
#endif
  {
   self->setBundleResourceVersion(bundleResourceVersion);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBundleResourceVersion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBundleResourceVersion of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_ResourceManager_getBundleResourceVersion00
static int tolua_LuaFramework_ResourceManager_getBundleResourceVersion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBundleResourceVersion'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getBundleResourceVersion();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBundleResourceVersion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDevelopMode of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_ResourceManager_setDevelopMode00
static int tolua_LuaFramework_ResourceManager_setDevelopMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
  bool developMode = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDevelopMode'", NULL);
#endif
  {
   self->setDevelopMode(developMode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDevelopMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isDevelopMode of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_ResourceManager_isDevelopMode00
static int tolua_LuaFramework_ResourceManager_isDevelopMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isDevelopMode'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isDevelopMode();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isDevelopMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRootURL of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_ResourceManager_setRootURL00
static int tolua_LuaFramework_ResourceManager_setRootURL00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string rootUrl = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRootURL'", NULL);
#endif
  {
   self->setRootURL(rootUrl);
   tolua_pushcppstring(tolua_S,(const char*)rootUrl);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRootURL'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRootURL of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_ResourceManager_getRootURL00
static int tolua_LuaFramework_ResourceManager_getRootURL00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRootURL'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getRootURL();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRootURL'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isVersionLatest of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_ResourceManager_isVersionLatest00
static int tolua_LuaFramework_ResourceManager_isVersionLatest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isVersionLatest'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isVersionLatest();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isVersionLatest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getVersion of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_ResourceManager_getVersion00
static int tolua_LuaFramework_ResourceManager_getVersion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getVersion'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getVersion();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getVersion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: configSearchPath of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_ResourceManager_configSearchPath00
static int tolua_LuaFramework_ResourceManager_configSearchPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'configSearchPath'", NULL);
#endif
  {
   self->configSearchPath();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'configSearchPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCopyFileList of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_ResourceManager_setCopyFileList00
static int tolua_LuaFramework_ResourceManager_setCopyFileList00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"__Array",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
  __Array* copyFileList = ((__Array*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCopyFileList'", NULL);
#endif
  {
   self->setCopyFileList(copyFileList);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCopyFileList'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkVersion of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_ResourceManager_checkVersion00
static int tolua_LuaFramework_ResourceManager_checkVersion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkVersion'", NULL);
#endif
  {
   self->checkVersion();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkVersion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateVersion of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_ResourceManager_updateVersion00
static int tolua_LuaFramework_ResourceManager_updateVersion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateVersion'", NULL);
#endif
  {
   self->updateVersion();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateVersion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkModule of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_ResourceManager_checkModule00
static int tolua_LuaFramework_ResourceManager_checkModule00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string moduleName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkModule'", NULL);
#endif
  {
   int tolua_ret = (int)  self->checkModule(moduleName);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)moduleName);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkModule'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateModule of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_ResourceManager_updateModule00
static int tolua_LuaFramework_ResourceManager_updateModule00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string moduleName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateModule'", NULL);
#endif
  {
   self->updateModule(moduleName);
   tolua_pushcppstring(tolua_S,(const char*)moduleName);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateModule'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getVersionUpdateSize of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_ResourceManager_getVersionUpdateSize00
static int tolua_LuaFramework_ResourceManager_getVersionUpdateSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getVersionUpdateSize'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getVersionUpdateSize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getVersionUpdateSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getModuleUpdateSize of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_ResourceManager_getModuleUpdateSize00
static int tolua_LuaFramework_ResourceManager_getModuleUpdateSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string moduleName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getModuleUpdateSize'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getModuleUpdateSize(moduleName);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)moduleName);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getModuleUpdateSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: flush of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_ResourceManager_flush00
static int tolua_LuaFramework_ResourceManager_flush00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'flush'", NULL);
#endif
  {
   self->flush();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'flush'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __HttpDownloaderDelegate__ of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_get_ResourceManager___HttpDownloaderDelegate__
static int tolua_get_ResourceManager___HttpDownloaderDelegate__(lua_State* tolua_S)
{
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__HttpDownloaderDelegate__'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<HttpDownloaderDelegate*>(self), "HttpDownloaderDelegate");
#else
   tolua_pushusertype(tolua_S,(void*)((HttpDownloaderDelegate*)self), "HttpDownloaderDelegate");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: encode of class  Base64Util */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_Base64Util_encode00
static int tolua_LuaFramework_Base64Util_encode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Base64Util",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string str = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   const char* tolua_ret = (const char*)  Base64Util::encode(str);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)str);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'encode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: decode of class  Base64Util */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_Base64Util_decode00
static int tolua_LuaFramework_Base64Util_decode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Base64Util",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string str = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   const char* tolua_ret = (const char*)  Base64Util::decode(str);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)str);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'decode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkNetStatus of class  NetStatusUtil */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_NetStatusUtil_checkNetStatus00
static int tolua_LuaFramework_NetStatusUtil_checkNetStatus00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NetStatusUtil",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   NetStatus tolua_ret = (NetStatus)  NetStatusUtil::checkNetStatus();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkNetStatus'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDecryptKey of class  DBDecryptUtil */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_DBDecryptUtil_setDecryptKey00
static int tolua_LuaFramework_DBDecryptUtil_setDecryptKey00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"DBDecryptUtil",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   DBDecryptUtil::setDecryptKey(key);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDecryptKey'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: decrypt of class  DBDecryptUtil */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_DBDecryptUtil_decrypt00
static int tolua_LuaFramework_DBDecryptUtil_decrypt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"DBDecryptUtil",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string text = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   const char* tolua_ret = (const char*)  DBDecryptUtil::decrypt(text);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)text);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'decrypt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDecryptKey of class  FileDecryptUtil */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_FileDecryptUtil_setDecryptKey00
static int tolua_LuaFramework_FileDecryptUtil_setDecryptKey00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FileDecryptUtil",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   FileDecryptUtil::setDecryptKey(key);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDecryptKey'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: decrypt of class  FileDecryptUtil */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_FileDecryptUtil_decrypt00
static int tolua_LuaFramework_FileDecryptUtil_decrypt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FileDecryptUtil",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string filePath = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   const char* tolua_ret = (const char*)  FileDecryptUtil::decrypt(filePath);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)filePath);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'decrypt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: generate of class  UUIDGenerator */
#ifndef TOLUA_DISABLE_tolua_LuaFramework_UUIDGenerator_generate00
static int tolua_LuaFramework_UUIDGenerator_generate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UUIDGenerator",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   const char* tolua_ret = (const char*)  UUIDGenerator::generate();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'generate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_LuaFramework_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_constant(tolua_S,"The9FrameworkVersion",The9FrameworkVersion);
  tolua_cclass(tolua_S,"JSONObject","JSONObject","Ref",NULL);
  tolua_beginmodule(tolua_S,"JSONObject");
   tolua_function(tolua_S,"create",tolua_LuaFramework_JSONObject_create00);
   tolua_function(tolua_S,"createWithString",tolua_LuaFramework_JSONObject_createWithString00);
   tolua_function(tolua_S,"createWithFile",tolua_LuaFramework_JSONObject_createWithFile00);
   tolua_function(tolua_S,"has",tolua_LuaFramework_JSONObject_has00);
   tolua_function(tolua_S,"count",tolua_LuaFramework_JSONObject_count00);
   tolua_function(tolua_S,"putBool",tolua_LuaFramework_JSONObject_putBool00);
   tolua_function(tolua_S,"getBool",tolua_LuaFramework_JSONObject_getBool00);
   tolua_function(tolua_S,"putNumber",tolua_LuaFramework_JSONObject_putNumber00);
   tolua_function(tolua_S,"getNumber",tolua_LuaFramework_JSONObject_getNumber00);
   tolua_function(tolua_S,"putString",tolua_LuaFramework_JSONObject_putString00);
   tolua_function(tolua_S,"getString",tolua_LuaFramework_JSONObject_getString00);
   tolua_function(tolua_S,"putJSONObject",tolua_LuaFramework_JSONObject_putJSONObject00);
   tolua_function(tolua_S,"getJSONObject",tolua_LuaFramework_JSONObject_getJSONObject00);
   tolua_function(tolua_S,"putJSONArray",tolua_LuaFramework_JSONObject_putJSONArray00);
   tolua_function(tolua_S,"getJSONArray",tolua_LuaFramework_JSONObject_getJSONArray00);
   tolua_function(tolua_S,"put",tolua_LuaFramework_JSONObject_put00);
   tolua_function(tolua_S,"get",tolua_LuaFramework_JSONObject_get00);
   tolua_function(tolua_S,"allKeys",tolua_LuaFramework_JSONObject_allKeys00);
   tolua_function(tolua_S,"remove",tolua_LuaFramework_JSONObject_remove00);
   tolua_function(tolua_S,"removeAll",tolua_LuaFramework_JSONObject_removeAll00);
   tolua_function(tolua_S,"toString",tolua_LuaFramework_JSONObject_toString00);
   tolua_function(tolua_S,"toPrettyString",tolua_LuaFramework_JSONObject_toPrettyString00);
   tolua_function(tolua_S,"toLuaString",tolua_LuaFramework_JSONObject_toLuaString00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"JSONArray","JSONArray","Ref",NULL);
  tolua_beginmodule(tolua_S,"JSONArray");
   tolua_function(tolua_S,"create",tolua_LuaFramework_JSONArray_create00);
   tolua_function(tolua_S,"createWithString",tolua_LuaFramework_JSONArray_createWithString00);
   tolua_function(tolua_S,"createWithFile",tolua_LuaFramework_JSONArray_createWithFile00);
   tolua_function(tolua_S,"count",tolua_LuaFramework_JSONArray_count00);
   tolua_function(tolua_S,"addBool",tolua_LuaFramework_JSONArray_addBool00);
   tolua_function(tolua_S,"insertBool",tolua_LuaFramework_JSONArray_insertBool00);
   tolua_function(tolua_S,"getBool",tolua_LuaFramework_JSONArray_getBool00);
   tolua_function(tolua_S,"addNumber",tolua_LuaFramework_JSONArray_addNumber00);
   tolua_function(tolua_S,"insertNumber",tolua_LuaFramework_JSONArray_insertNumber00);
   tolua_function(tolua_S,"getNumber",tolua_LuaFramework_JSONArray_getNumber00);
   tolua_function(tolua_S,"addString",tolua_LuaFramework_JSONArray_addString00);
   tolua_function(tolua_S,"insertString",tolua_LuaFramework_JSONArray_insertString00);
   tolua_function(tolua_S,"getString",tolua_LuaFramework_JSONArray_getString00);
   tolua_function(tolua_S,"addJSONObject",tolua_LuaFramework_JSONArray_addJSONObject00);
   tolua_function(tolua_S,"insertJSONObject",tolua_LuaFramework_JSONArray_insertJSONObject00);
   tolua_function(tolua_S,"getJSONObject",tolua_LuaFramework_JSONArray_getJSONObject00);
   tolua_function(tolua_S,"addJSONArray",tolua_LuaFramework_JSONArray_addJSONArray00);
   tolua_function(tolua_S,"insertJSONArray",tolua_LuaFramework_JSONArray_insertJSONArray00);
   tolua_function(tolua_S,"getJSONArray",tolua_LuaFramework_JSONArray_getJSONArray00);
   tolua_function(tolua_S,"add",tolua_LuaFramework_JSONArray_add00);
   tolua_function(tolua_S,"insert",tolua_LuaFramework_JSONArray_insert00);
   tolua_function(tolua_S,"get",tolua_LuaFramework_JSONArray_get00);
   tolua_function(tolua_S,"removeLast",tolua_LuaFramework_JSONArray_removeLast00);
   tolua_function(tolua_S,"remove",tolua_LuaFramework_JSONArray_remove00);
   tolua_function(tolua_S,"removeAll",tolua_LuaFramework_JSONArray_removeAll00);
   tolua_function(tolua_S,"toString",tolua_LuaFramework_JSONArray_toString00);
   tolua_function(tolua_S,"toPrettyString",tolua_LuaFramework_JSONArray_toPrettyString00);
   tolua_function(tolua_S,"toLuaString",tolua_LuaFramework_JSONArray_toLuaString00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"JSONElement","JSONElement","Ref",NULL);
  tolua_beginmodule(tolua_S,"JSONElement");
   tolua_function(tolua_S,"boolValue",tolua_LuaFramework_JSONElement_boolValue00);
   tolua_function(tolua_S,"numberValue",tolua_LuaFramework_JSONElement_numberValue00);
   tolua_function(tolua_S,"stringValue",tolua_LuaFramework_JSONElement_stringValue00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"JSONBool","JSONBool","JSONElement",NULL);
  tolua_beginmodule(tolua_S,"JSONBool");
   tolua_function(tolua_S,"create",tolua_LuaFramework_JSONBool_create00);
   tolua_function(tolua_S,"boolValue",tolua_LuaFramework_JSONBool_boolValue00);
   tolua_function(tolua_S,"numberValue",tolua_LuaFramework_JSONBool_numberValue00);
   tolua_function(tolua_S,"stringValue",tolua_LuaFramework_JSONBool_stringValue00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"JSONNumber","JSONNumber","JSONElement",NULL);
  tolua_beginmodule(tolua_S,"JSONNumber");
   tolua_function(tolua_S,"create",tolua_LuaFramework_JSONNumber_create00);
   tolua_function(tolua_S,"boolValue",tolua_LuaFramework_JSONNumber_boolValue00);
   tolua_function(tolua_S,"numberValue",tolua_LuaFramework_JSONNumber_numberValue00);
   tolua_function(tolua_S,"stringValue",tolua_LuaFramework_JSONNumber_stringValue00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"JSONString","JSONString","JSONElement",NULL);
  tolua_beginmodule(tolua_S,"JSONString");
   tolua_function(tolua_S,"create",tolua_LuaFramework_JSONString_create00);
   tolua_function(tolua_S,"boolValue",tolua_LuaFramework_JSONString_boolValue00);
   tolua_function(tolua_S,"numberValue",tolua_LuaFramework_JSONString_numberValue00);
   tolua_function(tolua_S,"stringValue",tolua_LuaFramework_JSONString_stringValue00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"SQLite","SQLite","Ref",NULL);
  tolua_beginmodule(tolua_S,"SQLite");
   tolua_function(tolua_S,"openSQLite",tolua_LuaFramework_SQLite_openSQLite00);
   tolua_function(tolua_S,"clearConnectionCache",tolua_LuaFramework_SQLite_clearConnectionCache00);
   tolua_function(tolua_S,"getValueTypeName",tolua_LuaFramework_SQLite_getValueTypeName00);
   tolua_function(tolua_S,"createTable",tolua_LuaFramework_SQLite_createTable00);
   tolua_function(tolua_S,"dropTable",tolua_LuaFramework_SQLite_dropTable00);
   tolua_function(tolua_S,"insertIntoTable",tolua_LuaFramework_SQLite_insertIntoTable00);
   tolua_function(tolua_S,"clearTable",tolua_LuaFramework_SQLite_clearTable00);
   tolua_function(tolua_S,"deleteFromTable",tolua_LuaFramework_SQLite_deleteFromTable00);
   tolua_function(tolua_S,"deleteFromTable",tolua_LuaFramework_SQLite_deleteFromTable01);
   tolua_function(tolua_S,"updateTable",tolua_LuaFramework_SQLite_updateTable00);
   tolua_function(tolua_S,"updateTable",tolua_LuaFramework_SQLite_updateTable01);
   tolua_function(tolua_S,"selectTable",tolua_LuaFramework_SQLite_selectTable00);
   tolua_function(tolua_S,"selectTable",tolua_LuaFramework_SQLite_selectTable01);
   tolua_function(tolua_S,"selectTable",tolua_LuaFramework_SQLite_selectTable02);
   tolua_function(tolua_S,"selectTable",tolua_LuaFramework_SQLite_selectTable03);
   tolua_function(tolua_S,"getRecordCount",tolua_LuaFramework_SQLite_getRecordCount00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"NetCenter","NetCenter","",NULL);
  tolua_beginmodule(tolua_S,"NetCenter");
   tolua_function(tolua_S,"sharedNetCenter",tolua_LuaFramework_NetCenter_sharedNetCenter00);
   tolua_function(tolua_S,"addNetService",tolua_LuaFramework_NetCenter_addNetService00);
   tolua_function(tolua_S,"removeNetService",tolua_LuaFramework_NetCenter_removeNetService00);
   tolua_function(tolua_S,"addNetProtocol",tolua_LuaFramework_NetCenter_addNetProtocol00);
   tolua_function(tolua_S,"addNetProtocol",tolua_LuaFramework_NetCenter_addNetProtocol01);
   tolua_function(tolua_S,"removeNetProtocol",tolua_LuaFramework_NetCenter_removeNetProtocol00);
   tolua_function(tolua_S,"removeNetProtocolForNetService",tolua_LuaFramework_NetCenter_removeNetProtocolForNetService00);
   tolua_function(tolua_S,"addNetFilter",tolua_LuaFramework_NetCenter_addNetFilter00);
   tolua_function(tolua_S,"removeNetFilter",tolua_LuaFramework_NetCenter_removeNetFilter00);
   tolua_function(tolua_S,"removeAllNetFilters",tolua_LuaFramework_NetCenter_removeAllNetFilters00);
   tolua_function(tolua_S,"sendMessage",tolua_LuaFramework_NetCenter_sendMessage00);
   tolua_function(tolua_S,"dispatchSuccessfulMessage",tolua_LuaFramework_NetCenter_dispatchSuccessfulMessage00);
   tolua_function(tolua_S,"dispatchFailedMessage",tolua_LuaFramework_NetCenter_dispatchFailedMessage00);
   tolua_function(tolua_S,"sendCommand",tolua_LuaFramework_NetCenter_sendCommand00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"NetFilter","NetFilter","Ref",NULL);
  tolua_beginmodule(tolua_S,"NetFilter");
   tolua_function(tolua_S,"create",tolua_LuaFramework_NetFilter_create00);
   tolua_function(tolua_S,"filterSuccessfulMessage",tolua_LuaFramework_NetFilter_filterSuccessfulMessage00);
   tolua_function(tolua_S,"filterFailedMessage",tolua_LuaFramework_NetFilter_filterFailedMessage00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"NetHandler","NetHandler","Ref",NULL);
  tolua_beginmodule(tolua_S,"NetHandler");
   tolua_function(tolua_S,"create",tolua_LuaFramework_NetHandler_create00);
   tolua_function(tolua_S,"handleSuccessfulMessage",tolua_LuaFramework_NetHandler_handleSuccessfulMessage00);
   tolua_function(tolua_S,"handleFailedMessage",tolua_LuaFramework_NetHandler_handleFailedMessage00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"NetProtocol","NetProtocol","Ref",NULL);
  tolua_beginmodule(tolua_S,"NetProtocol");
   tolua_function(tolua_S,"create",tolua_LuaFramework_NetProtocol_create00);
   tolua_function(tolua_S,"create",tolua_LuaFramework_NetProtocol_create01);
   tolua_function(tolua_S,"setID",tolua_LuaFramework_NetProtocol_setID00);
   tolua_function(tolua_S,"getID",tolua_LuaFramework_NetProtocol_getID00);
   tolua_function(tolua_S,"setServiceID",tolua_LuaFramework_NetProtocol_setServiceID00);
   tolua_function(tolua_S,"getServiceID",tolua_LuaFramework_NetProtocol_getServiceID00);
   tolua_function(tolua_S,"setHandler",tolua_LuaFramework_NetProtocol_setHandler00);
   tolua_function(tolua_S,"getHandler",tolua_LuaFramework_NetProtocol_getHandler00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"NetRequest","NetRequest","Ref",NULL);
  tolua_beginmodule(tolua_S,"NetRequest");
   tolua_function(tolua_S,"create",tolua_LuaFramework_NetRequest_create00);
   tolua_function(tolua_S,"create",tolua_LuaFramework_NetRequest_create01);
   tolua_function(tolua_S,"setProtocolID",tolua_LuaFramework_NetRequest_setProtocolID00);
   tolua_function(tolua_S,"getProtocolID",tolua_LuaFramework_NetRequest_getProtocolID00);
   tolua_function(tolua_S,"setBody",tolua_LuaFramework_NetRequest_setBody00);
   tolua_function(tolua_S,"getBody",tolua_LuaFramework_NetRequest_getBody00);
   tolua_function(tolua_S,"setConfigInfo",tolua_LuaFramework_NetRequest_setConfigInfo00);
   tolua_function(tolua_S,"getConfigInfo",tolua_LuaFramework_NetRequest_getConfigInfo00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"NetResponse","NetResponse","Ref",NULL);
  tolua_beginmodule(tolua_S,"NetResponse");
   tolua_function(tolua_S,"create",tolua_LuaFramework_NetResponse_create00);
   tolua_function(tolua_S,"create",tolua_LuaFramework_NetResponse_create01);
   tolua_function(tolua_S,"setProtocolID",tolua_LuaFramework_NetResponse_setProtocolID00);
   tolua_function(tolua_S,"getProtocolID",tolua_LuaFramework_NetResponse_getProtocolID00);
   tolua_function(tolua_S,"setBody",tolua_LuaFramework_NetResponse_setBody00);
   tolua_function(tolua_S,"getBody",tolua_LuaFramework_NetResponse_getBody00);
   tolua_function(tolua_S,"setRequest",tolua_LuaFramework_NetResponse_setRequest00);
   tolua_function(tolua_S,"getRequest",tolua_LuaFramework_NetResponse_getRequest00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"NetService","NetService","Ref",NULL);
  tolua_beginmodule(tolua_S,"NetService");
   tolua_function(tolua_S,"sendMessage",tolua_LuaFramework_NetService_sendMessage00);
   tolua_function(tolua_S,"executeCommand",tolua_LuaFramework_NetService_executeCommand00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"GameScene","GameScene","CCScene",NULL);
  tolua_beginmodule(tolua_S,"GameScene");
   tolua_function(tolua_S,"create",tolua_LuaFramework_GameScene_create00);
   tolua_function(tolua_S,"putAttribute",tolua_LuaFramework_GameScene_putAttribute00);
   tolua_function(tolua_S,"putAttribute",tolua_LuaFramework_GameScene_putAttribute01);
   tolua_function(tolua_S,"putAttribute",tolua_LuaFramework_GameScene_putAttribute02);
   tolua_function(tolua_S,"putAttribute",tolua_LuaFramework_GameScene_putAttribute03);
   tolua_function(tolua_S,"putAttribute",tolua_LuaFramework_GameScene_putAttribute04);
   tolua_function(tolua_S,"getBoolAttribute",tolua_LuaFramework_GameScene_getBoolAttribute00);
   tolua_function(tolua_S,"getIntAttribute",tolua_LuaFramework_GameScene_getIntAttribute00);
   tolua_function(tolua_S,"getDoubleAttribute",tolua_LuaFramework_GameScene_getDoubleAttribute00);
   tolua_function(tolua_S,"getStringAttribute",tolua_LuaFramework_GameScene_getStringAttribute00);
   tolua_function(tolua_S,"getAttribute",tolua_LuaFramework_GameScene_getAttribute00);
   tolua_function(tolua_S,"loadViewController",tolua_LuaFramework_GameScene_loadViewController00);
   tolua_function(tolua_S,"unloadViewController",tolua_LuaFramework_GameScene_unloadViewController00);
   tolua_function(tolua_S,"unloadAllViewController",tolua_LuaFramework_GameScene_unloadAllViewController00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ViewController","ViewController","Ref",NULL);
  tolua_beginmodule(tolua_S,"ViewController");
   tolua_function(tolua_S,"create",tolua_LuaFramework_ViewController_create00);
   tolua_function(tolua_S,"getScene",tolua_LuaFramework_ViewController_getScene00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"kResourceManagerErrorTypeVersionIsLatest",kResourceManagerErrorTypeVersionIsLatest);
  tolua_constant(tolua_S,"kResourceManagerErrorTypeNoSuchModule",kResourceManagerErrorTypeNoSuchModule);
  tolua_constant(tolua_S,"kResourceManagerErrorTypeDownloadFailure",kResourceManagerErrorTypeDownloadFailure);
  tolua_constant(tolua_S,"kResourceManagerErrorTypeVersionUpdateFailure",kResourceManagerErrorTypeVersionUpdateFailure);
  tolua_cclass(tolua_S,"ResourceManager","ResourceManager","Ref",NULL);
  tolua_beginmodule(tolua_S,"ResourceManager");
   tolua_function(tolua_S,"sharedResourceManager",tolua_LuaFramework_ResourceManager_sharedResourceManager00);
   tolua_function(tolua_S,"setDelegate",tolua_LuaFramework_ResourceManager_setDelegate00);
   tolua_function(tolua_S,"getDelegate",tolua_LuaFramework_ResourceManager_getDelegate00);
   tolua_function(tolua_S,"setScriptDelegate",tolua_LuaFramework_ResourceManager_setScriptDelegate00);
   tolua_function(tolua_S,"getScriptDelegate",tolua_LuaFramework_ResourceManager_getScriptDelegate00);
   tolua_function(tolua_S,"setProgramVersion",tolua_LuaFramework_ResourceManager_setProgramVersion00);
   tolua_function(tolua_S,"getProgramVersion",tolua_LuaFramework_ResourceManager_getProgramVersion00);
   tolua_function(tolua_S,"setBundleResourceVersion",tolua_LuaFramework_ResourceManager_setBundleResourceVersion00);
   tolua_function(tolua_S,"getBundleResourceVersion",tolua_LuaFramework_ResourceManager_getBundleResourceVersion00);
   tolua_function(tolua_S,"setDevelopMode",tolua_LuaFramework_ResourceManager_setDevelopMode00);
   tolua_function(tolua_S,"isDevelopMode",tolua_LuaFramework_ResourceManager_isDevelopMode00);
   tolua_function(tolua_S,"setRootURL",tolua_LuaFramework_ResourceManager_setRootURL00);
   tolua_function(tolua_S,"getRootURL",tolua_LuaFramework_ResourceManager_getRootURL00);
   tolua_function(tolua_S,"isVersionLatest",tolua_LuaFramework_ResourceManager_isVersionLatest00);
   tolua_function(tolua_S,"getVersion",tolua_LuaFramework_ResourceManager_getVersion00);
   tolua_function(tolua_S,"configSearchPath",tolua_LuaFramework_ResourceManager_configSearchPath00);
   tolua_function(tolua_S,"setCopyFileList",tolua_LuaFramework_ResourceManager_setCopyFileList00);
   tolua_function(tolua_S,"checkVersion",tolua_LuaFramework_ResourceManager_checkVersion00);
   tolua_function(tolua_S,"updateVersion",tolua_LuaFramework_ResourceManager_updateVersion00);
   tolua_function(tolua_S,"checkModule",tolua_LuaFramework_ResourceManager_checkModule00);
   tolua_function(tolua_S,"updateModule",tolua_LuaFramework_ResourceManager_updateModule00);
   tolua_function(tolua_S,"getVersionUpdateSize",tolua_LuaFramework_ResourceManager_getVersionUpdateSize00);
   tolua_function(tolua_S,"getModuleUpdateSize",tolua_LuaFramework_ResourceManager_getModuleUpdateSize00);
   tolua_function(tolua_S,"flush",tolua_LuaFramework_ResourceManager_flush00);
   tolua_variable(tolua_S,"__HttpDownloaderDelegate__",tolua_get_ResourceManager___HttpDownloaderDelegate__,NULL);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Base64Util","Base64Util","",NULL);
  tolua_beginmodule(tolua_S,"Base64Util");
   tolua_function(tolua_S,"encode",tolua_LuaFramework_Base64Util_encode00);
   tolua_function(tolua_S,"decode",tolua_LuaFramework_Base64Util_decode00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"kNetStatusNotReachable",kNetStatusNotReachable);
  tolua_constant(tolua_S,"kNetStatusReachableViaWiFi",kNetStatusReachableViaWiFi);
  tolua_constant(tolua_S,"kNetStatusReachableViaWWAN",kNetStatusReachableViaWWAN);
  tolua_cclass(tolua_S,"NetStatusUtil","NetStatusUtil","",NULL);
  tolua_beginmodule(tolua_S,"NetStatusUtil");
   tolua_function(tolua_S,"checkNetStatus",tolua_LuaFramework_NetStatusUtil_checkNetStatus00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"DBDecryptUtil","DBDecryptUtil","",NULL);
  tolua_beginmodule(tolua_S,"DBDecryptUtil");
   tolua_function(tolua_S,"setDecryptKey",tolua_LuaFramework_DBDecryptUtil_setDecryptKey00);
   tolua_function(tolua_S,"decrypt",tolua_LuaFramework_DBDecryptUtil_decrypt00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"FileDecryptUtil","FileDecryptUtil","",NULL);
  tolua_beginmodule(tolua_S,"FileDecryptUtil");
   tolua_function(tolua_S,"setDecryptKey",tolua_LuaFramework_FileDecryptUtil_setDecryptKey00);
   tolua_function(tolua_S,"decrypt",tolua_LuaFramework_FileDecryptUtil_decrypt00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"UUIDGenerator","UUIDGenerator","",NULL);
  tolua_beginmodule(tolua_S,"UUIDGenerator");
   tolua_function(tolua_S,"generate",tolua_LuaFramework_UUIDGenerator_generate00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_LuaFramework (lua_State* tolua_S) {
 return tolua_LuaFramework_open(tolua_S);
};
#endif

