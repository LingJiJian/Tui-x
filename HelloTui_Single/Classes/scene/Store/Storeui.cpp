#include "Storeui.h"
#include "tui/TuiManager.h"

NS_STORE_BEGIN

void Storeui::onLoadScene()
{
	setAutoRemoveUnusedTexture(true);
	TuiManager::getInstance()->parseScene(this,"panel_store");

	ArmatureBtn *pBtn = (ArmatureBtn*)this->getControl(PANEL_STORE,ARMBTN_TEST2);
	pBtn->setOnClickListener(this,ccw_click_selector(Storeui::event_btn_test));
}

void Storeui::event_btn_test( Ref* pSender )
{
	CSceneManager::getInstance()->replaceScene(
		CCSceneExTransitionFade::create(0.5f,LoadScene("Main::Mainui")));
}

/************************************************************************/
//	GET/SET/IS
/************************************************************************/
Node * Storeui::getPanel( int tagPanel )
{
	Node *pPanel = nullptr;
	switch (tagPanel)
	{
	case PANEL_STORE:
		pPanel = this->getChildByTag(PANEL_STORE);
		break;
	}
	return pPanel;
}



NS_STORE_END
