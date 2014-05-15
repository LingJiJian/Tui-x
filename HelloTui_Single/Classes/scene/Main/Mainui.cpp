#include "Mainui.h"
#include "tui/TuiManager.h"

NS_MAIN_BEGIN

void Mainui::onLoadScene()
{
	setAutoRemoveUnusedTexture(true);
	TuiManager::getInstance()->parseScene(this,"panel_main");
	//注册事件
	CControlView *ctlv = (CControlView*)this->getControl(PANEL_MAIN,CTLV_LEFT);
	ctlv->setOnControlListener(this,ccw_control_selector(Mainui::event_ctlv_left));

	CButton *pBtnOk = (CButton*)this->getControl(PANEL_MAIN,BTN_OK);
	pBtnOk->setOnClickListener(this,ccw_click_selector(Mainui::event_btn_ok));

	CButton *pBtnGo = (CButton*)this->getControl(PANEL_MAIN,BTN_GO);
	pBtnGo->setOnClickListener(this,ccw_click_selector(Mainui::event_btn_go));

	//播放骨骼动画(默认不播放)
	Armature *armature = (Armature*)this->getControl(PANEL_MAIN,ARMATURE_BOSS1);
	armature->getAnimation()->play("live",0,1);
}

void Mainui::event_ctlv_left( Ref* pSender, float fx, float fy )
{
	Sprite *pIcon = (Sprite*)this->getControl(PANEL_MAIN,ANIM_COIN);
	pIcon->setPosition(pIcon->getPosition() + Point(fx,fy));
}

void Mainui::event_btn_ok(Ref* pSender)
{
	//开启塑形
	((CWidgetWindow*)getPanel(PANEL_MAIN))->setModalable(true);

	CSceneManager::getInstance()->runUIScene(LoadScene("Main::MessageBox"));
}

void Mainui::event_btn_go(Ref* pSender)
{
	CSceneManager::getInstance()->replaceScene(
		CCSceneExTransitionFade::create(0.5f,LoadScene("Store::Storeui")));
}

/************************************************************************/
//	GET/SET/IS
/************************************************************************/
Node* Mainui::getPanel( int tagPanel )
{
	Node *pPanel = nullptr;
	switch (tagPanel)
	{
	case PANEL_MAIN:
		pPanel = this->getChildByTag(PANEL_MAIN);
		break;
	}
	return pPanel;
}



NS_MAIN_END