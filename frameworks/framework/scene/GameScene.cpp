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

GameScene::~GameScene()
{
}

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
    
    UIManager::getInstance()->addNode(viewController->rootLayerForScene);
    
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

ViewController* GameScene::getViewController(const std::string &name)
{
    return viewControllerMap.at(name);
}

void GameScene::showViewController(const std::string &name)
{
    ViewController* viewController = this->getViewController(name);
    if (viewController) {
        
        //(1)隐藏互斥的viewController
        ValueVector mutexRelationArray = this->getMutexRelationArray(name);
        for (auto it = mutexRelationArray.begin(); it != mutexRelationArray.end(); it++) {
            this->hideViewController((*it).asString());
        }
        
        //(2) TODO 调整所有可见ViewController的ZOrder
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

void GameScene::addMutexRelation(const std::string &viewControllerName1, const std::string &viewControllerName2)
{
    this->addUnilateralMutexRelation(viewControllerName1, viewControllerName2);
    this->addUnilateralMutexRelation(viewControllerName2, viewControllerName1);
}

void GameScene::removeMutexRelation(const std::string &viewControllerName1, const std::string &viewControllerName2)
{
    this->removeUnilateralMutexRelation(viewControllerName1, viewControllerName2);
    this->removeUnilateralMutexRelation(viewControllerName2, viewControllerName1);
}

ValueVector GameScene::getMutexRelationArray(const std::string &viewControllerName)
{
    ValueVector keyVector;
    ValueMap& mutexRelationMap = this->getMutexRelationMap(viewControllerName);
    for (auto it = mutexRelationMap.begin(); it != mutexRelationMap.end(); it ++) {
        keyVector.push_back(Value((*it).first));
    }
    return keyVector;
}

void GameScene::addUnilateralMutexRelation(const std::string &viewControllerName1, const std::string &viewControllerName2)
{
    this->getMutexRelationMap(viewControllerName1)[viewControllerName2] = "";
}

void GameScene::removeUnilateralMutexRelation(const std::string &viewControllerName1, const std::string &viewControllerName2)
{
    this->getMutexRelationMap(viewControllerName1).erase(viewControllerName2);
}

ValueMap& GameScene::getMutexRelationMap(const std::string &viewControllerName)
{
    if (mutexRelationMapMap.find(viewControllerName) == mutexRelationMapMap.end()) {
        mutexRelationMapMap[viewControllerName] = ValueMap();
    }
    return mutexRelationMapMap[viewControllerName].asValueMap();
}
