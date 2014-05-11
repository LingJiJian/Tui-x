#include "LayoutTest.h"
#include "cocostudio/CocoStudio.h"
#include "extensions/cocos-ext.h"
using namespace cocostudio;

void CLayoutTestSceneBase::onNextBtnClick(Ref* pSender)
{
	nextCLayoutTestScene();
}

void CLayoutTestSceneBase::onBackBtnClick(Ref* pSender)
{
	backCLayoutTestScene();
}

void CLayoutTestSceneBase::onRefBtnClick(Ref* pSender)
{
	refCLayoutTestScene();
}

//////////////////////////////////////////////////////

bool CLayoutBasicTest::init()
{
	CLayoutTestSceneBase::init();
	setTitle("CLayoutBasicTest");
	setDescription("some things in a basic layout");

	CLayout* pLayout = CLayout::create();
	pLayout->setPosition(Point(480 ,320));
	pLayout->setContentSize(Size(480, 320));
	pLayout->setBackgroundImage("background.png");
	m_pWindow->addChild(pLayout);

	CButton* pButton = CButton::createWith9Sprite(Size(150, 50), "sprite9_btn1.png", "sprite9_btn2.png");
	pButton->setPosition(Point(150, 100));
	pLayout->addChild(pButton);

	CImageView* pImage = CImageView::create("icon.png");
	pImage->setPosition(Point(200, 150));
	pLayout->addChild(pImage);

	return true;
}

//////////////////////////////////////////////////////

bool CLayoutColorTest::init()
{
	CLayoutTestSceneBase::init();
	setTitle("CLayoutColorTest");
	setDescription("color back ground");

	CLayout* pLayout = CLayout::create();
	pLayout->setBackgroundColor(Color4B(255, 0, 0, 255));
	pLayout->setPosition(Point(480 ,320));
	pLayout->setContentSize(Size(480, 320));
	m_pWindow->addChild(pLayout);

	return true;
}

//////////////////////////////////////////////////////

bool CLayoutGradientTest::init()
{
	CLayoutTestSceneBase::init();
	setTitle("CLayoutGradientTest");
	setDescription("Gradient back ground");

	CLayout* pLayout = CLayout::create();
	pLayout->setBackgroundGradient(Color4B(255,0,0,255), Color4B(0, 255, 0, 128), Point(1.0f, 0.0f));
	pLayout->setPosition(Point(480 ,320));
	pLayout->setContentSize(Size(480, 320));
	m_pWindow->addChild(pLayout);

	return true;
}