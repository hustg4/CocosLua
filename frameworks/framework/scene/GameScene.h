//
//  GameScene.h
//  Framework
//
//  Created by wp_g4 on 13-2-21.
//
//

#ifndef __Framework__GameScene__
#define __Framework__GameScene__

#include <iostream>
#include "cocos2d.h"
#include "ViewController.h"

class GameScene : public cocos2d::Ref {
    
public:
    
    CREATE_FUNC(GameScene);
    
    virtual ~GameScene();
    
    virtual bool init();
    
    virtual void onEnter();
    
    virtual void onExit();
    
    void putAttribute(const std::string& key,const cocos2d::Value& value);
    
    const cocos2d::Value getAttribute(const std::string& key);
    
    void loadViewController(const std::string& name,ViewController* viewController);
    
    void unloadViewController(const std::string& name);
    
    void unloadAllViewController();
    
    ViewController* getViewController(const std::string name);
    
    void showViewController(const std::string& name);
    
    void hideViewController(const std::string& name);
    
    void addMutexRelation(const std::string& viewControllerName1,const std::string& viewControllerName2);
    
    void removeMutexRelation(const std::string& viewControllerName1,const std::string& viewControllerName2);
    
    cocos2d::ValueVector getMutexRelationArray(const std::string& viewControllerName);
    
private:
    
    cocos2d::ValueMap paramMap;
    
    cocos2d::Map<std::string, ViewController*> viewControllerMap;
    
    cocos2d::ValueMap mutexRelationMapMap;  //{name1:{name2:""}}
    
    void addUnilateralMutexRelation(const std::string& viewControllerName1,const std::string& viewControllerName2);
    
    void removeUnilateralMutexRelation(const std::string& viewControllerName1,const std::string& viewControllerName2);
    
    cocos2d::ValueMap& getMutexRelationMap(const std::string& viewControllerName);
};

#endif /* defined(__Framework__GameScene__) */
