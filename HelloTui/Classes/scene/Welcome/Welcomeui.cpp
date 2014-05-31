#include "Welcomeui.h"
#include "tui/TuiManager.h"
#include "tui/tagMap/tuiTag_welcome.h"

NS_WELCOME_BEGIN

void Welcomeui::onLoadScene()
{
	setAutoRemoveUnusedTexture(true);
	TuiManager::getInstance()->parseScene(this,"panel_welcome",PATH_WELCOME);
	
	Size size = Director::getInstance()->getOpenGLView()->getFrameSize();
	float psX = (float) size.width / 800;
	float psY = (float) size.height / 480;
	for (Node *pChild : this->getChildren()){
		pChild->setPosition(pChild->getPositionX()*psX, pChild->getPositionY()*psY);
		CWidgetWindow *pWindow = dynamic_cast<CWidgetWindow*>(pChild);
		if (pWindow != nullptr){
			for (Node *pChild : pWindow->getChildren()){
				pChild->setPosition(pChild->getPositionX()*psX, pChild->getPositionY()*psY);
			}
		}
	}
	

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