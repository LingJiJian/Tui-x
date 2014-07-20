#include "AppDelegate.h"
#include "../../CocosBase/cocos-base.h"
#include "MenuScene.h"
#include "Test/BasicSceneTest/BasicSceneTest.h"

USING_NS_CC;

AppDelegate::AppDelegate() 
{

}

AppDelegate::~AppDelegate() 
{
	
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if(!glview) {
		glview = GLView::create("Cpp Tests");
		director->setOpenGLView(glview);
	}

    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
	//pEGLView->setDesignResolutionSize(960, 640, kResolutionShowAll);

	REGISTER_SCENE_FUNC(MenuScene);
	REGISTER_SCENE_FUNC(BasicSceneTest);
	REGISTER_SCENE_FUNC(BasicUIScene);

	CSceneManager::getInstance()->runWithScene(LoadScene("MenuScene"));

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
