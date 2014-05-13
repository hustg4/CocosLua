//
//  SceneManager.h
//  framework
//
//  Created by wp_g4 on 14-5-4.
//
//

#ifndef __framework__SceneManager__
#define __framework__SceneManager__

#include <iostream>
#include "GameScene.h"

class SceneManager : public cocos2d::Ref{
    
public:
    
    static SceneManager* getInstance();
    
    void runScene(GameScene* scene);
    
    GameScene* getCurrentScene();
    
private:
    
    SceneManager();
    
    ~SceneManager();
    
    GameScene* currentScene;
    
};

#endif /* defined(__framework__SceneManager__) */
