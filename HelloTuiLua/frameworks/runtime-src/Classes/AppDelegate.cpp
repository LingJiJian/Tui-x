#include "AppDelegate.h"
#include "CCLuaEngine.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"
#include "../../../../CocosWidget/lua_cocos2dx_cocoswidget_auto.hpp"
#include "../../../../CocosBase/lua_cocos2dx_cocosbase_auto.hpp"
#include "../../../../CocosNet/lua_cocos2dx_cocosnet_auto.hpp"
#include "tui/lua_cocos2dx_tui_auto.hpp"
#include "../../../../dragonbones/lua_dragonbones_auto.hpp"

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
		glview = GLView::createWithRect("HelloTuiLua", Rect(0,0,800,480));
		director->setOpenGLView(glview);
	}

    //glview->setDesignResolutionSize(800, 480, ResolutionPolicy::EXACT_FIT);

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

	FileUtils::getInstance()->addSearchPath("src");
	FileUtils::getInstance()->addSearchPath("res");

	auto engine = LuaEngine::getInstance();
	ScriptEngineManager::getInstance()->setScriptEngine(engine);
	
	lua_State *state = engine->getLuaStack()->getLuaState();
	register_all_cocos2dx_cocoswidget(state);
	register_all_cocos2dx_cocosbase(state);
	register_all_cocos2dx_cocosnet(state);
	register_all_cocos2dx_tui(state);
	register_all_dragonbones(state);
	
	engine->executeScriptFile("main.lua");

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
