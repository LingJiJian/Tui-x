#include "ShowPhoneui.h"
#include "tui/tagMap/Tag_showPhone.h"
#include "tui/TuiManager.h"

NS_SHOWPHONE_BEGIN

void ShowPhoneui::onLoadScene()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("showphone/showphoneui.plist");
	TuiManager::getInstance()->parseScene(this, "panel_showphone", PATH_SHOWPHONE);

	CircleMenu *menu = (CircleMenu*)this->getControl(PANEL_SHOWPHONE, CIRCLEMENU_SHOWPHONE);
	menu->setOnClickListener(this, ccw_click_selector(ShowPhoneui::event_menu_phone));
}

void ShowPhoneui::event_menu_phone(Ref* pSender)
{
	Node* node = (Node*)pSender;
	CCLOG("tag %d", node->getTag());

	CSceneManager::getInstance()->replaceScene(
		CCSceneExTransitionFade::create(0.5f, LoadScene("Main::Mainui")));
}

Node * ShowPhoneui::getPanel(int tagPanel)
{
	Node *pPanel = nullptr;
	switch (tagPanel)
	{
	case PANEL_SHOWPHONE:
		pPanel = this->getChildByTag(PANEL_SHOWPHONE);
		break;
	}
	return pPanel;
}


NS_SHOWPHONE_END