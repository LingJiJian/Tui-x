#include "ControlViewTest.h"

void CControlViewTestSceneBase::onNextBtnClick(Ref* pSender)
{
	nextCControlViewTestScene();
}

void CControlViewTestSceneBase::onBackBtnClick(Ref* pSender)
{
	backCControlViewTestScene();
}

void CControlViewTestSceneBase::onRefBtnClick(Ref* pSender)
{
	refCControlViewTestScene();
}

//////////////////////////////////////////////////////

bool CControlViewBasicTest::init()
{
	CControlViewTestSceneBase::init();
	setTitle("CControlViewBasicTest");
	setDescription("control the icon to move");

	m_pIcon = Sprite::create("icon.png");
	m_pIcon->setPosition(Point(480, 320));
	m_pWindow->addChild(m_pIcon);

	CControlView* pView = CControlView::create(
		"control_baseboard.png", "control_joystick.png");
	pView->setPosition(Point(100, 100));
	pView->setRadius(pView->getContentSize().width / 2);
	pView->setOnControlListener(this, ccw_control_selector(CControlViewBasicTest::onTouched));
	pView->setAnchorPoint(Point::ZERO);
	pView->setScale(1.5f);
	pView->setOpacity(200);
	m_pWindow->addChild(pView);

	CControlView* pView2 = CControlView::create();
	pView2->setBaseBoardImage("control_baseboard.png");
	pView2->setPosition(Point(860, 100));
	pView2->setRadius(pView2->getContentSize().width / 2);
	pView2->setOnControlListener(this, ccw_control_selector(CControlViewBasicTest::onTouched));
	pView2->setAnchorPoint(Point(1, 0));
	pView2->setScale(1.5f);
	pView2->setOpacity(200);
	m_pWindow->addChild(pView2);

	return true;
}
void CControlViewBasicTest::onTouched(Ref* pSender, float fx, float fy)
{
	m_pIcon->setPosition(m_pIcon->getPosition() + Point(fx, fy));
}


//////////////////////////////////////////////////////

