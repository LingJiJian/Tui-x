#include "Mainui.h"
#include "tui/TuiManager.h"
#include "tui/tagMap/Tag_main.h"
#include "dialog/MsgBox.h"

NS_MAIN_BEGIN

void Mainui::onLoadScene()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("main/mainui.plist");
	TuiManager::getInstance()->parseScene(this,"panel_main",PATH_MAIN);

	Vec2 area = Arp(Vec2(618, 10));
	CWidgetWindow *panel = (CWidgetWindow*)getPanel(PANEL_MAIN);
	panel->setTouchAreaEnabled(true);
    panel->setTouchArea(cocos2d::Rect(area.x, area.y, 92, 36));

	//注册事件
	CControlView *ctlv = (CControlView*)this->getControl(PANEL_MAIN,CTLV_LEFT);
	ctlv->setOnControlListener(this,ccw_control_selector(Mainui::event_ctlv_left));

	CButton *pBtnOk = (CButton*)this->getControl(PANEL_MAIN,BTN_OK);
	pBtnOk->setOnClickListener(this,ccw_click_selector(Mainui::event_btn_ok));

	CButton *pBtnGo = (CButton*)this->getControl(PANEL_MAIN,BTN_GO);
	pBtnGo->setOnClickListener(this,ccw_click_selector(Mainui::event_btn_go));

	CButton *pBtnPhone = (CButton*) this->getControl(PANEL_MAIN, BTN_SHOWPHONE);
	pBtnPhone->setOnClickListener(this, ccw_click_selector(Mainui::event_btn_showphone));

    CButton* pBtnBag = (CButton*)this->getChildByTag(PANEL_MAIN)->getChildByTag(BTN_BAG);
	pBtnBag->setOnClickListener(this, ccw_click_selector(Mainui::event_btn_bag));

    CButton *pBtnMap = (CButton*)this->getControl(PANEL_MAIN, BTN_MAP);
    pBtnMap->setOnClickListener(this, ccw_click_selector(Mainui::event_btn_map));
    
	CButton *pBtnRecombine = (CButton*)this->getControl(PANEL_MAIN, BTN_RECOMBINE);
	pBtnRecombine->setOnClickListener(this, ccw_click_selector(Mainui::event_btn_recombine));

	CToggleView *pTgvA = (CToggleView*)this->getControl(PANEL_MAIN, TGV_A);
	pTgvA->setOnCheckListener(this, ccw_check_selector(Mainui::event_tgvA_check));

	CToggleView *pTgvB = (CToggleView*)this->getControl(PANEL_MAIN, TGV_B);
	pTgvB->setOnCheckListener(this, ccw_check_selector(Mainui::event_tgvB_check));
    
    CEditBox *pEditBox = (CEditBox*)this->getControl(PANEL_MAIN, EDIT_LOGIN);
    pEditBox->setDelegate(this);
	
	CSceneManager::getInstance()->runSuspendScene(LoadScene("Guideui"));
}

void Mainui::editBoxReturn(CEditBox *pEditBox)
{

}

void Mainui::event_ctlv_left( Ref* pSender, float fx, float fy )
{
	Sprite *pIcon = (Sprite*)this->getControl(PANEL_MAIN,ANIM_COIN);
	pIcon->setPosition(pIcon->getPosition() + Arp(Vec2(fx, fy)));
}

void Mainui::event_tgvA_check(Ref *pSender, bool bChecked)
{

}

void Mainui::event_tgvB_check(Ref *pSender, bool bChecked)
{

}

void Mainui::event_btn_ok(Ref* pSender)
{
	CSceneManager::getInstance()->runUIScene(LoadScene("Main::MsgBox"));
}

void Mainui::event_btn_map(Ref* pSender)
{
    CSceneManager::getInstance()->replaceScene(CCSceneExTransitionFade::create(0.5f, LoadScene("Mapui")));
}

void Mainui::event_btn_showphone(Ref* pSender)
{
	CSceneManager::getInstance()->replaceScene(
		CCSceneExTransitionFade::create(0.5f, LoadScene("ShowPhone::ShowPhoneui")));
}

void Mainui::event_btn_go(Ref* pSender)
{
	CSceneManager::getInstance()->replaceScene(
		CCSceneExTransitionFade::create(0.5f, LoadScene("Store::Storeui")));
	
}

void Mainui::event_btn_bag(Ref* pSender)
{
	CSceneManager::getInstance()->replaceScene(
		CCSceneExTransitionFade::create(0.5f, LoadScene("Bag::Bagui")));
}

void Mainui::event_btn_recombine(Ref* pSender)
{
	CSceneManager::getInstance()->replaceScene(
		CCSceneExTransitionFade::create(0.5f, LoadScene("Recomebineui")));
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


void Mainui::onMessage(unsigned int uMsg, Ref* pMsgObj, void* wParam, void* lParam)
{
	switch (uMsg)
	{
	case FINISH_GUIDE:
	{
		CWidgetWindow *panel = (CWidgetWindow*)getPanel(PANEL_MAIN);
		panel->setTouchAreaEnabled(false);
	}
		break;
	default:
		break;
	}
}

NS_MAIN_END