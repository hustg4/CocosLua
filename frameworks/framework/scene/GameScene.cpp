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
    if (!CCScene::init()) {
        return false;
    }
    paramDict = __Dictionary::create();
    CC_SAFE_RETAIN(paramDict);
    
    viewControllerArray = __Array::create();
    CC_SAFE_RETAIN(viewControllerArray);
    
    return true;
}

void GameScene::onEnter()
{
    CCScene::onEnter();
    LuaUtil::executePeertableFunction(this, "onEnter", NULL, NULL,false);
}

void GameScene::onExit()
{
    LuaUtil::executePeertableFunction(this, "onExit", NULL, NULL,false);
    
    this->unloadAllViewController();
    
    CCScene::onExit();
}

void GameScene::putAttribute(const std::string &key, bool value)
{
    paramDict->setObject(CCBool::create(value), key);
}

void GameScene::putAttribute(const std::string &key, int value)
{
    paramDict->setObject(__Integer::create(value), key);
}

void GameScene::putAttribute(const std::string &key, double value)
{
    paramDict->setObject(__Double::create(value), key);
}

void GameScene::putAttribute(const std::string &key, const std::string &value)
{
    paramDict->setObject(__String::create(value), key);
}

void GameScene::putAttribute(const std::string &key, Ref* value)
{
    paramDict->setObject(value, key);
}

bool GameScene::getBoolAttribute(const std::string &key)
{
    Ref* value = this->getAttribute(key);
    __Bool* boolValue = dynamic_cast<__Bool*>(value);
    if (boolValue) {
        return boolValue->getValue();
    }
    return false;
}

int GameScene::getIntAttribute(const std::string &key)
{
    Ref* value = this->getAttribute(key);
    __Integer* intValue = dynamic_cast<__Integer*>(value);
    if (intValue) {
        return intValue->getValue();
    }
    return 0;
}

double GameScene::getDoubleAttribute(const std::string &key)
{
    Ref* value = this->getAttribute(key);
    __Double* doubleValue = dynamic_cast<__Double*>(value);
    if (doubleValue) {
        return doubleValue->getValue();
    }
    return 0;
}

const char* GameScene::getStringAttribute(const std::string &key)
{
    Ref* value = this->getAttribute(key);
    __String* strValue = dynamic_cast<__String*>(value);
    if (strValue) {
        return strValue->getCString();
    }
    return NULL;
}

Ref* GameScene::getAttribute(const std::string &key)
{
    return paramDict->objectForKey(key);
}

void GameScene::loadViewController(ViewController *viewCotroller)
{
    CCAssert(viewCotroller, "viewCotroller 不能为空");
    
    viewControllerArray->addObject(viewCotroller);
    
    viewCotroller->setScene(this);
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
    CC_SAFE_RELEASE_NULL(paramDict);
    CC_SAFE_RELEASE_NULL(viewControllerArray);
}
