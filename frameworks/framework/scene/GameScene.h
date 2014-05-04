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
    
private:
    
    cocos2d::ValueMap paramMap;
    
    cocos2d::__Array* viewControllerArray;
    
public:
    
    
    CREATE_FUNC(GameScene);
    
    virtual ~GameScene();
    
    virtual bool init();
    
    virtual void onEnter();
    
    virtual void onExit();
    
    void putAttribute(const std::string& key,const cocos2d::Value& value);
    
    const cocos2d::Value getAttribute(const std::string& key);
    
    void loadViewController(ViewController* viewCotroller);
    
    void unloadViewController(ViewController* viewCotroller);
    
    void unloadAllViewController();
    
};

#endif /* defined(__Framework__GameScene__) */
