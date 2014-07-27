#include "DrawOrderTest.h"

void DrawOrderTestSceneBase::onNextBtnClick(Ref* pSender)
{
	nextDrawOrderTestScene();
}

void DrawOrderTestSceneBase::onBackBtnClick(Ref* pSender)
{
	backDrawOrderTestScene();
}

void DrawOrderTestSceneBase::onRefBtnClick(Ref* pSender)
{
	refDrawOrderTestScene();
}

//////////////////////////////////////////////////////

bool DrawOrderBasicTest::init()
{
	DrawOrderTestSceneBase::init();
	setTitle("DrawOrderBasicTest");
	setDescription("swap the zorder for see event dispatch");
	
	CButton* pSwapBtn = CButton::create();
	pSwapBtn->setPosition(Vec2(170, 320));
	pSwapBtn->setScale9Enabled(true);
	pSwapBtn->setNormalImage("sprite9_btn1.png");
	pSwapBtn->setSelectedImage("sprite9_btn2.png");
	pSwapBtn->initText("swap z order", "", 30);
	pSwapBtn->setCascadeTextSizeEnabled(true, Size(50, 30));
	pSwapBtn->setOnClickListener(this, ccw_click_selector(DrawOrderBasicTest::onClick));
	m_pWindow->addChild(pSwapBtn);

	pButton1 = CButton::create("btn1_1.png", "btn1_2.png");
	pButton1->setLocalZOrder(1);
	pButton1->setPosition(Vec2(480, 320));
	m_pWindow->addChild(pButton1);

	pButton2 = CButton::create("btn1_1.png", "btn1_2.png");
	pButton2->setLocalZOrder(2);
	pButton2->setPosition(Vec2(520, 350));
	m_pWindow->addChild(pButton2);

	return true;
}

void DrawOrderBasicTest::onClick(Ref* pSender)
{
	int z = pButton2->getLocalZOrder();
	pButton2->setLocalZOrder(pButton1->getLocalZOrder());
	pButton1->setLocalZOrder(z);
}

//////////////////////////////////////////////////////