#include "Storeui.h"
#include "tui/TuiManager.h"
#include "tui/tagMap/Tag_store.h"

NS_STORE_BEGIN

void Storeui::onLoadScene()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("store/storeui.plist");
	TuiManager::getInstance()->parseScene(this,"panel_store",PATH_STORE);

	CListView *pListGoods = (CListView*)this->getControl(PANEL_STORE, LIST_GOODS);
	Vector<Node*> vet = pListGoods->getContainer()->getChildren();
	for (Node *pNode : vet){
		CButton *pBtnPay = dynamic_cast<CButton*>(pNode->getChildByTag(BTN_PAY));
		pBtnPay->setOnClickListener(this, ccw_click_selector(Storeui::event_btn_pay));
	}

	ArmatureBtn *pBtn = (ArmatureBtn*)this->getControl(PANEL_STORE,ARMBTN_TEST2);
	pBtn->setOnClickListener(this,ccw_click_selector(Storeui::event_btn_test));
	
	CExpandableListView *pExpList = (CExpandableListView*)this->getControl(PANEL_STORE, EXPLIST_TEST);
	CButton *pBtnExp1 = (CButton *)pExpList->getExpandableNodeAtIndex(0)->getItemNodeAtIndex(0)->getChildByTag(BTN_EXPPAY1);
	pBtnExp1->setOnClickListener(this, ccw_click_selector(Storeui::event_explist_btn));
}

void Storeui::event_explist_btn(Ref* pSender)
{
	CCLOG("click explist btnpay1 ");
}

void Storeui::event_btn_test( Ref* pSender )
{
	CSceneManager::getInstance()->replaceScene(
		CCSceneExTransitionFade::create(0.5f, LoadScene("Main::Mainui")));
}

void Storeui::event_btn_pay(Ref* pSender)
{
	Node *pBtn = (Node*)pSender;
	CCLOG("pay index :%d", pBtn->getParent()->getTag());
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
