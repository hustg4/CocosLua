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

enum ViewControllerType{
    ViewControllerTypeScene,
    ViewControllerTypeUI
};

class ViewController : public cocos2d::Ref{
    
public:
    
    static ViewController* create(ViewControllerType type);
    
    ViewController(ViewControllerType type);
    
    virtual ~ViewController();
    
    virtual void load();
    
    virtual void unload();
    
    GameScene* getScene();
    
    ViewControllerType getType();
    
    cocos2d::Layer* getRootLayer();
    
    void setRootLayer(cocos2d::Layer* rootLayer);
    
private:
    
    friend class GameScene;
    
    ViewControllerType type;
    
    GameScene* scene;
    
    cocos2d::Layer* rootLayerForScene;//strong,for scene use
    
    cocos2d::Layer* rootLayer;//weak,child of rootLayerForScene,for logic use
    
};

#endif /* defined(__Framework__ViewController__) */
