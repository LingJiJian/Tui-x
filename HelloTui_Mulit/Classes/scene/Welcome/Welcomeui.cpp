#include "Welcomeui.h"
#include "tui/TuiManager.h"
#include "tui/tagMap/tuiTag_welcome.h"

NS_WELCOME_BEGIN

void Welcomeui::onLoadScene()
{
	setAutoRemoveUnusedTexture(true);
	TuiManager::getInstance()->parseScene(this,"panel_welcome",PATH_WELCOME);

	DelayTime *pDelayAct = DelayTime::create(1.5f);
	CallFunc *pCallAct = CallFunc::create(std::bind(&Welcomeui::event_anim_finish,this));

	this->runAction(Sequence::create(pDelayAct,pCallAct,NULL));
}

void Welcomeui::event_anim_finish()
{
	CSceneManager::getInstance()->replaceScene(
		CCSceneExTransitionFade::create(0.5f,LoadScene("Main::Mainui")));
}

/************************************************************************/
//	GET/SET/IS
/************************************************************************/
Node * Welcomeui::getPanel( int tagPanel )
{
	Node *pPanel = nullptr;
	switch (tagPanel)
	{
	case PANEL_WELCOME:
		pPanel = this->getChildByTag(PANEL_WELCOME);
		break;
	}
	return pPanel;
}

NS_WELCOME_END