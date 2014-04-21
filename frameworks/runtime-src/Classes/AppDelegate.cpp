#include "AppDelegate.h"
#include "CCLuaEngine.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"

#include "the9framework.h"
#include "HttpService.h"
#include "SocketService.h"

using namespace CocosDenshion;

USING_NS_CC;
using namespace std;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
    SimpleAudioEngine::end();
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if(!glview) {
		glview = GLView::createWithRect("framework", Rect(0,0,900,640));
		director->setOpenGLView(glview);
	}

    glview->setDesignResolutionSize(480, 320, ResolutionPolicy::NO_BORDER);

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    //框架版本号
    CCLOG("The9Framework: version:%.2f",The9FrameworkVersion);
    
    //配置SearchPath
    ResourceManager::sharedResourceManager()->configSearchPath();
    
    //init network
    this->initNetwork();

	auto engine = LuaEngine::getInstance();
	ScriptEngineManager::getInstance()->setScriptEngine(engine);
//	engine->executeScriptFile("src/main.lua");
    
    // run main lua file
    engine->executeScriptFile("main.lua");

    return true;
}

void AppDelegate::initNetwork()
{
    //添加NetService
    NetCenter* netCenter=NetCenter::sharedNetCenter();
    //   http
    netCenter->addNetService("http", HttpService::create());
    //   socket
    netCenter->addNetService("socket", SocketService::create());
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();

    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();

    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
