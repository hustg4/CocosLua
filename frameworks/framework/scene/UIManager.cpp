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
, layerScene(nullptr)
, layerUI(nullptr)
{
}

void UIManager::reset()
{
    scene->removeAllChildren();
    this->buildScene();
}

void UIManager::addSceneNode(cocos2d::Node *node)
{
    layerScene->addChild(node);
}

void UIManager::addUINode(cocos2d::Node *node)
{
    layerUI->addChild(node);
}

void UIManager::init()
{
    if (scene == nullptr) {
        scene = Scene::create();
        Director::getInstance()->runWithScene(scene);
        this->buildScene();
    }
}

void UIManager::buildScene()
{
    layerRoot = Layer::create();
    scene->addChild(layerRoot);
    
    layerScene = Layer::create();
    layerRoot->addChild(layerScene);
    
    layerUI = Layer::create();
    layerRoot->addChild(layerUI);
}
