//
//  ViewController.h
//  Framework
//
//  Created by wp_g4 on 13-3-11.
//
//

#ifndef __Framework__ViewController__
#define __Framework__ViewController__

#include <iostream>
#include "cocos2d.h"

class GameScene;

class ViewController : public cocos2d::Ref{
    
public:
    
    CREATE_FUNC(ViewController);
    
    virtual ~ViewController();
    
    virtual bool init();
    
    virtual void load();
    
    virtual void unload();
    
    CC_SYNTHESIZE(GameScene*, scene, Scene);
    
};

#endif /* defined(__Framework__ViewController__) */
