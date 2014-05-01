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

USING_NS_CC;

//==================== Inner class GameHelper ====================

class GameHelper : public Ref {
    
public:
    
    static GameHelper* getInstance()
    {
        static GameHelper helper;
        return &helper;
    }
    
    void scheduleCallGameDoRestart()
    {
        Director::getInstance()->getScheduler()->schedule(schedule_selector(GameHelper::callGameDoRestart), this, 0, false);
    }
    
    void callGameDoRestart(float)
    {
        Director::getInstance()->getScheduler()->unscheduleAllForTarget(this);
        Game::doRestart();
    }
    
};

//====================          End         ====================

void Game::start()
{
    //C++初始化
    
    //脚本初始化
    auto engine = LuaEngine::getInstance();
	ScriptEngineManager::getInstance()->setScriptEngine(engine);
    
    lua_State* luaState = engine->getLuaStack()->getLuaState();
    
    register_all_framework(luaState);
    
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
    //clean scene
    Director::getInstance()->replaceScene(Scene::create());
    
    GameHelper::getInstance()->scheduleCallGameDoRestart();
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
