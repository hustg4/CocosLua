//
//  LuaFramework.h
//  The9Framework
//
//  Created by wp_g4 on 13-3-21.
//
//

#ifndef The9Framework_LuaFramework_h
#define The9Framework_LuaFramework_h

extern "C" {
#include "tolua++.h"
#include "tolua_fix.h"
}

#include <map>
#include <string>
#include "tolua_fix.h"
#include "CCLuaValue.h"
#include "cocos2d.h"
#include "the9framework.h"

using namespace cocos2d;

TOLUA_API int tolua_LuaFramework_open(lua_State* tolua_S);

#endif
