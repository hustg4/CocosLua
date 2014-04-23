//
//  ViewController.cpp
//  The9Framework
//
//  Created by wp_g4 on 13-3-11.
//
//

#include "ViewController.h"
#include "LuaUtil.h"

using namespace cocos2d;

bool ViewController::init()
{
    return true;
}

ViewController::~ViewController()
{
}


void ViewController::load()
{
    LuaUtil::executePeertableFunction(this, "load", NULL, NULL, false);
}

void ViewController::unload()
{
    LuaUtil::executePeertableFunction(this, "unload", NULL, NULL, false);
}
