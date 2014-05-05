//
//  GameScene.cpp
//  Framework
//
//  Created by wp_g4 on 13-2-21.
//
//

#include "GameScene.h"
#include "LuaUtil.h"

using namespace cocos2d;

bool GameScene::init()
{
    viewControllerArray = __Array::create();
    CC_SAFE_RETAIN(viewControllerArray);
    
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

void GameScene::loadViewController(ViewController *viewCotroller)
{
    CCAssert(viewCotroller, "viewCotroller 不能为空");
    
    viewControllerArray->addObject(viewCotroller);
    
    viewCotroller->scene = this;
    viewCotroller->load();
}

void GameScene::unloadViewController(ViewController *viewCotroller)
{
    CCAssert(viewControllerArray->containsObject(viewCotroller), "viewCotroller 不存在");
    viewCotroller->unload();
    viewControllerArray->removeObject(viewCotroller);
}

void GameScene::unloadAllViewController()
{
    int count=viewControllerArray->count();
    for (int i=0; i<count; i++) {
        ViewController* viewController=(ViewController*)viewControllerArray->getObjectAtIndex(i);
        viewController->unload();
    }
    viewControllerArray->removeAllObjects();
}

GameScene::~GameScene()
{
    CC_SAFE_RELEASE_NULL(viewControllerArray);
}
