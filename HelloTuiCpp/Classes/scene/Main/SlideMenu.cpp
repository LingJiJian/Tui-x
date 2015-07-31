#include "SlideMenu.h"
#include "tui/TuiManager.h"
#include "tui/tagMap/Tag_main.h"

NS_MAIN_BEGIN

SlideMenu* SlideMenu::create()
{
	SlideMenu* pRet = new SlideMenu();
	if( pRet && pRet->init() )
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

bool SlideMenu::init()
{
	CLayout::init();
	this->setTouchEnabled(true);
	this->setContentSize(Size(100,50));

	CButton* btn = CButton::create("main/btn_green_normal.png","main/btn_green_select.png");
	this->addChild(btn);

	this->setBackgroundColor(Color4B::RED);
	return true;
}

CWidgetTouchModel SlideMenu::onTouchBegan( Touch* pTouch )
{
	CLayout::onTouchBegan(pTouch);
	return eWidgetTouchTransient;
}

NS_MAIN_END