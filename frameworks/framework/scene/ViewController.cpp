//
//  ViewController.cpp
//  Framework
//
//  Created by wp_g4 on 13-3-11.
//
//

#include "ViewController.h"
#include "LuaUtil.h"
#include "UIManager.h"

using namespace cocos2d;

bool ViewController::init()
{
    scene = nullptr;
    return true;
}

ViewController::~ViewController()
{
}


void ViewController::load()
{
    LuaUtil::executePeertableFunction(this, "load", NULL, NULL, false);
    LuaUtil::executePeertableFunction(this, "registerEvents", NULL, NULL, false);
}

void ViewController::unload()
{
    LuaUtil::executePeertableFunction(this, "unregisterEvents", NULL, NULL, false);
    LuaUtil::executePeertableFunction(this, "unload", NULL, NULL, false);
}

GameScene* ViewController::getScene()
{
    return this->scene;
}

void ViewController::addSceneNode(cocos2d::Node *node)
{
    UIManager::getInstance()->addSceneNode(node);
}

void ViewController::addUINode(cocos2d::Node *node)
{
    UIManager::getInstance()->addUINode(node);
}
