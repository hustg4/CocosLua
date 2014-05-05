//
//  SceneManager.cpp
//  framework
//
//  Created by wp_g4 on 14-5-4.
//
//

#include "SceneManager.h"
#include "UIManager.h"
#include "cocos2d.h"

SceneManager* SceneManager::getInstance()
{
    static SceneManager instance;
    return &instance;
}

SceneManager::SceneManager()
: currentScene(nullptr)
{
    
}

SceneManager::~SceneManager()
{
    CC_SAFE_RELEASE_NULL(currentScene);
}

void SceneManager::runScene(GameScene *scene)
{
    if (currentScene != nullptr) {
        currentScene->onExit();
        CC_SAFE_RELEASE_NULL(currentScene);
        UIManager::getInstance()->reset();
    }
    currentScene = scene;
    CC_SAFE_RETAIN(currentScene);
    
    currentScene->onEnter();
}


