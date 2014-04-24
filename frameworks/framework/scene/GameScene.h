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

class GameScene : public cocos2d::Scene {
    
private:
    
    cocos2d::__Dictionary* paramDict;
    
    cocos2d::__Array* viewControllerArray;
    
public:
    
    
    CREATE_FUNC(GameScene);
    
    virtual ~GameScene();
    
    virtual bool init();
    
    virtual void onEnter();
    
    virtual void onExit();
    
    void putAttribute(const std::string& key,bool value);
    
    void putAttribute(const std::string& key,int value);
    
    void putAttribute(const std::string& key,double value);
    
    void putAttribute(const std::string& key,const std::string& value);
    
    void putAttribute(const std::string& key,Ref* value);
    
    bool getBoolAttribute(const std::string& key);
    
    int getIntAttribute(const std::string& key);
    
    double getDoubleAttribute(const std::string& key);
    
    const char* getStringAttribute(const std::string& key);
    
    Ref* getAttribute(const std::string& key);
    
    void loadViewController(ViewController* viewCotroller);
    
    void unloadViewController(ViewController* viewCotroller);
    
    void unloadAllViewController();
    
};

#endif /* defined(__Framework__GameScene__) */
