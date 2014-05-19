#include "AppDelegate.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"

#include "framework.h"

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
		glview = GLView::createWithRect("template", Rect(0,0,960,640));
		director->setOpenGLView(glview);
	}
    
    glview->setDesignResolutionSize(960, 640, ResolutionPolicy::SHOW_ALL);
    
    // turn on display FPS
    director->setDisplayStats(true);
    
    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    
    //框架版本号
    CCLOG("Framework: version:%.2f",FrameworkVersion);
    
    //配置SearchPath
    ResourceManager::sharedResourceManager()->configSearchPath();
    
    Game::start();
    
    return true;
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
