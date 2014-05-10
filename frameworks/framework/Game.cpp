//
//  Game.cpp
//  framework
//
//  Created by wp_g4 on 14-4-29.
//
//

#include "Game.h"
#include "CCLuaEngine.h"
#include "utils/LuaUtil.h"
#include "lua-bindings/lua_framework_auto.hpp"
#include "net/NetCenter.h"
#include "sqlite/SQLite.h"
#include "scene/UIManager.h"

USING_NS_CC;

void Game::start()
{
    //C++初始化
    UIManager::getInstance()->build();
    
    //脚本初始化
    auto engine = LuaEngine::getInstance();
    ScriptEngineManager::getInstance()->setScriptEngine(engine);
    
    lua_State* luaState = engine->getLuaStack()->getLuaState();
    
    register_all_framework(luaState);
    
    //加载脚本主程序
    engine->executeScriptFile("main.lua");
    
    Game::callLuaFuncOnStart();
}

void Game::stop()
{
    Game::callLuaFuncOnStop();
    
    //C++清理
    NetCenter::sharedNetCenter()->removeAllNetFilters();
    
    SQLite::clearConnectionCache();
    
    //脚本清理
    ScriptEngineManager::getInstance()->setScriptEngine(NULL);
}

void Game::restart()
{
    UIManager::getInstance()->clean();
    
    Node* tmpNode = Node::create();
    CC_SAFE_RETAIN(tmpNode);
    
    Director::getInstance()->getScheduler()->schedule([tmpNode] (float val){
        Director::getInstance()->getScheduler()->unscheduleAllForTarget(tmpNode);
        tmpNode->release();
        Game::doRestart();
    },tmpNode , 0, false, "doRestart");
}

void Game::doRestart()
{
    Game::stop();
    
    Game::start();
}

//******************** call lua func ********************

void Game::callLuaFuncOnStart()
{
    LuaUtil::executeTableFunction("Game", "onStart", NULL, NULL, false);
}

void Game::callLuaFuncOnStop()
{
    LuaUtil::executeTableFunction("Game", "onStop", NULL, NULL, false);
}

//********************      end       ********************
