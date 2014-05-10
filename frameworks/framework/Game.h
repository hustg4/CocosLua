//
//  Game.h
//  framework
//
//  Created by wp_g4 on 14-4-29.
//
//

#ifndef __framework__Game__
#define __framework__Game__

#include <iostream>
#include "cocos2d.h"

class Game {
    
public:
    
    static void start();
    
    static void stop();
    
    static void restart();
    
private:
    
    static void doRestart();
    
    //******************** call lua func ********************
    
    static void callLuaFuncOnStart();
    
    static void callLuaFuncOnStop();
    
    //********************      end       ********************
     
};

#endif /* defined(__framework__Game__) */
