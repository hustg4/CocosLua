//
//  UIManager.h
//  framework
//
//  Created by wp_g4 on 14-5-4.
//
//

#ifndef __framework__UIManager__
#define __framework__UIManager__

#include <iostream>
#include "cocos2d.h"

class UIManager {
    
public:
    
    static UIManager* getInstance();
    
    void build();
    
    void clean();
    
    void reset();
    
    void addSceneNode(cocos2d::Node* node);
    
    void addUINode(cocos2d::Node* node);
    
private:
    
    UIManager();
    
    void init();
    
    void buildScene();
    
    cocos2d::Scene* scene; //weak
    
    cocos2d::Layer* layerRoot;//weak
    
    cocos2d::Layer* layerScene;//weak
    
    cocos2d::Layer* layerUI;//weak
    
};

#endif /* defined(__framework__UIManager__) */
