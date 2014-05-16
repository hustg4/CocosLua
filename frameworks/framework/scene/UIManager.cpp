//
//  UIManager.cpp
//  framework
//
//  Created by wp_g4 on 14-5-4.
//
//

#include "UIManager.h"

USING_NS_CC;

static UIManager* instance = nullptr;

UIManager* UIManager::getInstance()
{
    if (!instance) {
        instance = new UIManager();
        instance->init();
    }
    return instance;
}

UIManager::UIManager()
: scene(nullptr)
, layerRoot(nullptr)
{
}

void UIManager::build()
{
    layerRoot = Layer::create();
    scene->addChild(layerRoot);
}

void UIManager::clean()
{
    scene->removeAllChildren();
}

void UIManager::reset()
{
    this->clean();
    this->build();
}

void UIManager::addNode(cocos2d::Node *node)
{
    layerRoot->addChild(node);
}

void UIManager::init()
{
    if (scene == nullptr) {
        scene = Scene::create();
        Director::getInstance()->runWithScene(scene);
    }
}

