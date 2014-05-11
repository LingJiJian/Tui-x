#include "LabelTest.h"
#include "../../action/LabelChange.h"

void CLabelTestSceneBase::onNextBtnClick(Ref* pSender)
{
	nextCLabelTestScene();
}

void CLabelTestSceneBase::onBackBtnClick(Ref* pSender)
{
	backCLabelTestScene();
}

void CLabelTestSceneBase::onRefBtnClick(Ref* pSender)
{
	refCLabelTestScene();
}

//////////////////////////////////////////////////////

bool CLabelBasicTest::init()
{
	CLabelTestSceneBase::init();
	setTitle("CLabelBasicTest");
	setDescription("CLabel extern CCLabelTTF (long click and click)");

	CLabel* pText1 = CLabel::createWithTTF("Hello CCTK And cocoswidget", "fonts/Marker Felt.ttf", 30.0f);
	pText1->enableShadow();
	pText1->setPosition(Point(480, 450));
	m_pWindow->addChild(pText1);

	CLabel* pText2 = CLabel::createWithTTF("Click me test event ", "fonts/Marker Felt.ttf", 30.0f);
	pText2->setTouchEnabled(true);
	pText2->setOnLongClickListener(this, ccw_longclick_selector(CLabelBasicTest::onLongClick));
	pText2->setOnClickListener(this, ccw_click_selector(CLabelBasicTest::onClick));
	pText2->setOnTouchBeganListener(this, ccw_touchbegan_selector(CLabelBasicTest::onTouchBegan));
	pText2->setOnTouchMovedListener(this, ccw_touchevent_selector(CLabelBasicTest::onTouchMoved));
	pText2->setOnTouchEndedListener(this, ccw_touchevent_selector(CLabelBasicTest::onTouchEnded));
	pText2->setOnTouchCancelledListener(this, ccw_touchevent_selector(CLabelBasicTest::onTouchEnded));
	pText2->setColor(Color3B(0, 255, 0));
	pText2->setPosition(Point(480, 380));
	m_pWindow->addChild(pText2);

	pText3 = CLabel::createWithTTF("none", "", 30.0f);
	pText3->setPosition(Point(750, 380));
	m_pWindow->addChild(pText3);

	CLabel* pText4 = CLabel::createWithTTF("Hello","fonts/arial.ttf",25.0f);
	pText4->setMiddleLine(true);
	pText4->setPosition(Point(480,320));
	m_pWindow->addChild(pText4);

	CLabel* pText5 = CLabel::createWithTTF("World","fonts/arial.ttf",25.0f);
	pText5->setUnderLine(true);
	pText5->setPosition(Point(580,320));
	m_pWindow->addChild(pText5);
	
	LabelChange *plabAct = LabelChange::create(2.5f,1,1000);

	CLabel* pText6 = CLabel::createWithTTF("","",25.0f);
	pText6->runAction(plabAct);
	pText6->setPosition(Point(480,270));
	m_pWindow->addChild(pText6);

	CLabel* pText7 = CLabel::createWithTTF("Shadow","fonts/Marker Felt.ttf",25.0f);
	pText7->enableShadow(Color4B::RED);
	pText7->setPosition(Point(300,220));
	m_pWindow->addChild(pText7);

	CLabel* pText8 = CLabel::createWithTTF("Outline","fonts/Marker Felt.ttf",25.0f);
	pText8->enableOutline(Color4B::BLUE,3);
	pText8->setPosition(Point(400,220));
	m_pWindow->addChild(pText8);

	TTFConfig ttfConfig("fonts/arial.ttf", 40, GlyphCollection::DYNAMIC,nullptr,true);
	CLabel* pText9 = CLabel::createWithTTF(ttfConfig,"Glow",TextHAlignment::CENTER);
	pText9->setTextColor(Color4B::RED);
	pText9->enableGlow(Color4B::GREEN);
	pText9->setPosition(Point(500,220));
	m_pWindow->addChild(pText9);

	return true;
}

CWidgetTouchModel CLabelBasicTest::onTouchBegan(Ref* pSender, Touch* pTouch)
{
	CLabel* pText = (CLabel*) pSender;
	pText->stopActionByTag(1);
	ScaleTo* pScaleTo = ScaleTo::create(0.1f, 1.3f);
	pScaleTo->setTag(1);
	pText->runAction(pScaleTo);

	return eWidgetTouchTransient;
}

bool CLabelBasicTest::onTouchMoved(Ref* pSender, Touch* pTouch, float fDuration)
{
	return true;
}

bool CLabelBasicTest::onTouchEnded(Ref* pSender, Touch* pTouch, float fDuration)
{
	CLabel* pText = (CLabel*) pSender;
	pText->stopActionByTag(1);
	ScaleTo* pScaleTo = ScaleTo::create(0.1f, 1.0f);
	pScaleTo->setTag(1);
	pText->runAction(pScaleTo);
	return true;
}

void CLabelBasicTest::onClick(Ref* pSender)
{
	pText3->setString("Clicked");
}

bool CLabelBasicTest::onLongClick(Ref* pSender, Touch* pTouch)
{
	pText3->setString("LongClicked");
	return false;
}

//////////////////////////////////////////////////////

bool CLabelAtlasTest::init()
{
	CLabelTestSceneBase::init();
	setTitle("CLabelBasicTest");
	setDescription("CLabelAtlas extern CCLabelAtlas (test event)");

	CLabelAtlas* pText = CLabelAtlas::create(":;0123456789", "num.png", 26, 34, 48);
	pText->setTouchEnabled(true);
	pText->setAnchorPoint(Point(0.5, 0.5));
	pText->setPosition(Point(480, 320));
	pText->setOnTouchBeganListener(this, ccw_touchbegan_selector(CLabelAtlasTest::onTouchBegan));
	pText->setOnTouchEndedListener(this, ccw_touchevent_selector(CLabelAtlasTest::onTouchEnded));
	pText->setOnTouchCancelledListener(this, ccw_touchevent_selector(CLabelAtlasTest::onTouchEnded));
	m_pWindow->addChild(pText);

	return true;
}

CWidgetTouchModel CLabelAtlasTest::onTouchBegan(Ref* pSender, Touch* pTouch)
{
	CLabelAtlas* pText = (CLabelAtlas*) pSender;
	pText->stopActionByTag(1);
	ScaleTo* pScaleTo = ScaleTo::create(0.1f, 1.3f);
	pScaleTo->setTag(1);
	pText->runAction(pScaleTo);

	return eWidgetTouchTransient;
}

bool CLabelAtlasTest::onTouchEnded(Ref* pSender, Touch* pTouch, float fDuration)
{
	CLabelAtlas* pText = (CLabelAtlas*) pSender;
	pText->stopActionByTag(1);
	ScaleTo* pScaleTo = ScaleTo::create(0.1f, 1.0f);
	pScaleTo->setTag(1);
	pText->runAction(pScaleTo);

	return true;
}

//////////////////////////////////////////////////////

bool CLabelBMFontTest::init()
{
	CLabelTestSceneBase::init();
	setTitle("CLabelBMFontTest");
	setDescription("CLabelBMFont extern CCLabelBMFont");

	CLabelBMFont* pText = CLabelBMFont::create("hello cocos2d-x and cocoswidget", "arial-unicode-26.fnt");
	pText->setPosition(Point(480, 320));
	m_pWindow->addChild(pText);

	return true;
}