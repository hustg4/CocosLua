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

ViewController* ViewController::create()
{
    ViewController* controller = new ViewController();
    controller->autorelease();
    return controller;
}

ViewController::ViewController()
: scene(nullptr)
, rootLayer(nullptr)
{
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

void  ViewController::layerWillAppear()
{
    LuaUtil::executePeertableFunction(this, "layerWillAppear", NULL, NULL, false);
}

void  ViewController::layerDidAppear()
{
    LuaUtil::executePeertableFunction(this, "layerDidAppear", NULL, NULL, false);
}

void  ViewController::layerWillDisappear()
{
    LuaUtil::executePeertableFunction(this, "layerWillDisappear", NULL, NULL, false);
}

void  ViewController::layerDidDisappear()
{
    LuaUtil::executePeertableFunction(this, "layerDidDisappear", NULL, NULL, false);
}

GameScene* ViewController::getScene()
{
    return this->scene;
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

