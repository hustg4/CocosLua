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
    
    static ViewController* create();
    
    ViewController();
    
    virtual ~ViewController();
    
    const std::string& getName();
    
    virtual void load();
    
    virtual void unload();
    
    virtual void  onShow();
    
    virtual void  onHide();
    
    GameScene* getScene();
    
    cocos2d::Layer* getRootLayer();
    
    void setRootLayer(cocos2d::Layer* rootLayer);
    
private:
    
    friend class GameScene;
    
    GameScene* scene;
    
    std::string name;
    
    cocos2d::Layer* rootLayerForScene;//strong,for scene use
    
    cocos2d::Layer* rootLayer;//weak,child of rootLayerForScene,for logic use
    
};

#endif /* defined(__Framework__ViewController__) */
