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

ViewController* ViewController::create(ViewControllerType type)
{
    ViewController* controller = new ViewController(type);
    controller->autorelease();
    return controller;
}

ViewController::ViewController(ViewControllerType type)
: scene(nullptr)
, rootLayer(nullptr)
{
    this->type = type;
    
    rootLayerForScene = Layer::create();
    CC_SAFE_RETAIN(rootLayerForScene);
    rootLayerForScene->setVisible(false);
    
    this->setRootLayer(Layer::create());
}

ViewController::~ViewController()
{
    CC_SAFE_RELEASE_NULL(rootLayerForScene);
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

ViewControllerType ViewController::getType()
{
    return this->type;
}

cocos2d::Layer* ViewController::getRootLayer()
{
    return this->rootLayer;
}

void ViewController::setRootLayer(cocos2d::Layer* rootLayer)
{
    if (rootLayer == this->rootLayer) {
        return;
    }
    if (this->rootLayer) {
        this->rootLayer->removeFromParent();
    }
    if (rootLayer) {
        this->rootLayer = rootLayer;
        this->rootLayerForScene->addChild(this->rootLayer);
    }
}

