//
//  GameScene.cpp
//  Framework
//
//  Created by wp_g4 on 13-2-21.
//
//

#include "GameScene.h"
#include "LuaUtil.h"
#include "UIManager.h"

using namespace cocos2d;

bool GameScene::init()
{
    return true;
}

void GameScene::onEnter()
{
    LuaUtil::executePeertableFunction(this, "onEnter", NULL, NULL,false);
}

void GameScene::onExit()
{
    LuaUtil::executePeertableFunction(this, "onExit", NULL, NULL,false);
    
    this->unloadAllViewController();
}

void GameScene::putAttribute(const std::string &key, const cocos2d::Value &value)
{
    paramMap[key] = value;
}

const Value GameScene::getAttribute(const std::string &key)
{
    return paramMap[key];
}

void GameScene::loadViewController(const std::string &name, ViewController *viewController)
{
    CCAssert(viewController, "viewController 不能为空");
    
    viewControllerMap.insert(name, viewController);
    
    viewController->scene = this;
    
    if (viewController->getType() == ViewControllerTypeScene) {
        UIManager::getInstance()->addSceneNode(viewController->rootLayerForScene);
    }else if (viewController->getType() == ViewControllerTypeUI){
        UIManager::getInstance()->addUINode(viewController->rootLayerForScene);
    }
    
    viewController->load();
}

void GameScene::unloadViewController(const std::string &name)
{
    ViewController* viewController = this->getViewController(name);
    
    if (viewController) {
        
        viewController->unload();
        viewController->rootLayerForScene->removeFromParent();
        viewController->scene = nullptr;
        
        viewControllerMap.erase(name);
    }
}

void GameScene::unloadAllViewController()
{
    std::vector<std::string> keys = viewControllerMap.keys();
    for_each( keys.begin(), keys.end(), [this] (std::string val)
    {
        this->unloadViewController(val);
    });
}

ViewController* GameScene::getViewController(const std::string name)
{
    return viewControllerMap.at(name);
}

void GameScene::showViewController(const std::string &name)
{
    ViewController* viewController = this->getViewController(name);
    if (viewController) {
        //TODO 调整ZOrder
        viewController->layerWillAppear();
        viewController->rootLayerForScene->setVisible(true);
        viewController->layerDidAppear();
    }
}

void GameScene::hideViewController(const std::string &name)
{
    ViewController* viewController = this->getViewController(name);
    if (viewController) {
        viewController->layerWillDisappear();
        viewController->rootLayerForScene->setVisible(false);
        viewController->layerDidDisappear();
    }
}

GameScene::~GameScene()
{
}
