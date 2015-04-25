#include "Welcomeui.h"
#include "tui/TuiManager.h"
#include "tui/tagMap/Tag_welcome.h"

NS_WELCOME_BEGIN

void Welcomeui::onLoadScene()
{
	//setAutoRemoveUnusedSpriteFrame(true);
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("welcome/welcomeui.plist");
	TuiManager::getInstance()->parseScene(this,"panel_welcome",PATH_WELCOME);
	
	this->runAction(
		Sequence::create(
		DelayTime::create(1.5f), 
		CallFunc::create(
		[](){
		CSceneManager::getInstance()->replaceScene(
			CCSceneExTransitionFade::create(0.5f, LoadScene("Main::Mainui")));
		}), NULL));
		
}

/************************************************************************/
//	GET/SET/IS
/************************************************************************/


NS_WELCOME_END