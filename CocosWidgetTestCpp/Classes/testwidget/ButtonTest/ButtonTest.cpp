#include "ButtonTest.h"

void CButtonTestSceneBase::onNextBtnClick(Ref* pSender)
{
	nextCButtonTestScene();
}

void CButtonTestSceneBase::onBackBtnClick(Ref* pSender)
{
	backCButtonTestScene();
}

void CButtonTestSceneBase::onRefBtnClick(Ref* pSender)
{
	refCButtonTestScene();
}

//////////////////////////////////////////////////////

bool CButtonBasicTest::init()
{
	CButtonTestSceneBase::init();
	setTitle("CButtonBasicTest");
	setDescription("button by create");

	CButton* pButton = CButton::create("btn1_1.png", "btn1_2.png", "btn1_3.png");
	pButton->setPosition(Vec2(480, 320));
	m_pWindow->addChild(pButton);

	ArmatureDataManager::getInstance()->addArmatureFileInfo("armBtn_test2.png","armBtn_test2.plist","armBtn_test2.xml");
	ArmatureBtn *pArmBtn = ArmatureBtn::create("armBtn_test2");
	pArmBtn->setPosition(Vec2(100, 270));
	pArmBtn->setOnClickListener(this,ccw_click_selector(CButtonBasicTest::event_armbtn_test));
	m_pWindow->addChild(pArmBtn);

	NumericStepper *pStep = NumericStepper::create(
		"numStep_test_lnomal.png","numStep_test_lselect.png","numStep_test_ldisable.png",
		"numStep_test_rnomal.png","numStep_test_rselect.png","numStep_test_rdisable.png",
		"numStep_test_stepbg.png");
	pStep->setOnValueChangedListener(this,ccw_valuechanged_selector(CButtonBasicTest::event_numStep_test));
	pStep->setPosition(Vec2(650,320));
	m_pWindow->addChild(pStep);

	return true;
}

void CButtonBasicTest::event_armbtn_test(Ref *pSender)
{
	CCLOG("%s","click!");
}

void CButtonBasicTest::event_numStep_test(Ref *pSender,int value)
{
	CCLOG("%d",value);
}

//////////////////////////////////////////////////////

bool CButtonEventTest::init()
{
	CButtonTestSceneBase::init();
	setTitle("CButtonEventTest");
	setDescription("button events");

	CButton* pButton1 = CButton::create("btn1_1.png", "btn1_2.png", "btn1_3.png");
	pButton1->setOnTouchBeganListener(this, ccw_touchbegan_selector(CButtonEventTest::onTouchBegan));
	pButton1->setOnTouchMovedListener(this, ccw_touchevent_selector(CButtonEventTest::onTouchMoved));
	pButton1->setOnTouchEndedListener(this, ccw_touchevent_selector(CButtonEventTest::onTouchEnded));
	pButton1->setOnTouchCancelledListener(this, ccw_touchevent_selector(CButtonEventTest::onTouchCancelled));
	pButton1->setPosition(Vec2(350, 320));
	m_pWindow->addChild(pButton1);

	m_pText1 = CLabel::create();
	m_pText1->setAnchorPoint(Vec2(0, 0.5));
	m_pText1->setPosition(Vec2(260, 430));
	m_pText1->setString("none");
	m_pWindow->addChild(m_pText1);

	m_pDurationText = CLabel::create();
	m_pDurationText->setPosition(Vec2(260, 390));
	m_pDurationText->setString("ms:0");
	m_pDurationText->setAnchorPoint(Vec2(0, 0.5));
	m_pWindow->addChild(m_pDurationText);

	CButton* pButton2 = CButton::create("btn1_1.png", "btn1_2.png", "btn1_3.png");
	pButton2->setOnClickListener(this, ccw_click_selector(CButtonEventTest::onClick));
	pButton2->setPosition(Vec2(610, 320));
	m_pWindow->addChild(pButton2);

	m_pText2 = CLabel::create();
	m_pText2->setAnchorPoint(Vec2(0, 0.5));
	m_pText2->setPosition(Vec2(520, 430));
	m_pText2->setString("none");
	m_pWindow->addChild(m_pText2);

	return true;
}

void CButtonEventTest::setDuration(float fDuration)
{
	char buff[48] = {0};
	sprintf(buff, "ms:%f", fDuration);
	m_pDurationText->setString(buff);
}

void CButtonEventTest::onClick(Ref* pSender)
{
	m_pText2->setString("Clicked");
}

CWidgetTouchModel CButtonEventTest::onTouchBegan(Ref* pSender, Touch* pTouch)
{
	m_pText1->setString("Down");
	return eWidgetTouchTransient;
}

bool CButtonEventTest::onTouchMoved(Ref* pSender, Touch* pTouch, float fDuration)
{
	m_pText1->setString("Moved");
	setDuration(fDuration);
	return true;
}

bool CButtonEventTest::onTouchEnded(Ref* pSender, Touch* pTouch, float fDuration)
{
	m_pText1->setString("Ended");
	setDuration(fDuration);
	return true;
}

bool CButtonEventTest::onTouchCancelled(Ref* pSender, Touch* pTouch, float fDuration)
{
	m_pText1->setString("Cancelled");
	setDuration(fDuration);
	return true;
}

////////////////////////////////////////////////////////

bool CButtonLongClickTest::init()
{
	CButtonTestSceneBase::init();
	setTitle("CButtonLongClickTest");
	setDescription("drag the 2s button after long click\n (the touch event will back to WidgetWindow after long click)");

	CButton* pButton1 = CButton::create("btn1_1.png", "btn1_2.png", "btn1_3.png");
	pButton1->setOnClickListener(this, ccw_click_selector(CButtonLongClickTest::onClick));
	pButton1->setOnLongClickListener(this, ccw_longclick_selector(CButtonLongClickTest::onButton1LongClick));
	pButton1->setPosition(Vec2(350, 320));
	m_pWindow->addChild(pButton1);

	m_pText1 = CLabel::create();
	m_pText1->setAnchorPoint(Vec2(0, 0.5));
	m_pText1->setPosition(Vec2(260, 430));
	m_pText1->setString("none");
	m_pWindow->addChild(m_pText1);

	m_pWindow->setOnTouchMovedAfterLongClickListener(this, ccw_afterlongclick_selector(CButtonLongClickTest::onLayoutTouchMovedAfterLongClick));

	m_pText2 = CLabel::create();
	m_pText2->setAnchorPoint(Vec2(0, 0.5));
	m_pText2->setPosition(Vec2(520, 430));
	m_pText2->setString("drag after long click!");
	m_pWindow->addChild(m_pText2);

	pButton2 = CButton::create("btn1_1.png", "btn1_2.png", "btn1_3.png");
	pButton2->setOnLongClickListener(this, ccw_longclick_selector(CButtonLongClickTest::onButton2LongClick));
	pButton2->setPosition(Vec2(610, 320));
	m_pWindow->addChild(pButton2);

	return true;
}

void CButtonLongClickTest::onClick(Ref* pSender)
{
	m_pText1->setString("Clicked");
}

bool CButtonLongClickTest::onButton1LongClick(Ref* pSender, Touch* pTouch)
{
	m_pText1->setString("Long Clicked");
	return false;
}

bool CButtonLongClickTest::onButton2LongClick(Ref* pSender, Touch* pTouch)
{
	pButton2->setPosition(m_pWindow->convertTouchToNodeSpace(pTouch));
	return true;
}

void CButtonLongClickTest::onLayoutTouchMovedAfterLongClick(Ref* pSender, Touch* pTouch, float fDuration)
{
	Vec2 tPoint = m_pWindow->convertTouchToNodeSpace(pTouch);
	
	if( pSender == pButton2 )
	{
		pButton2->setPosition(tPoint);
	}
}

////////////////////////////////////////////////////////

bool CButtonWithTextTest::init()
{
	CButtonTestSceneBase::init();
	setTitle("CButtonWithTextTest");
	setDescription("TextButton and offset for text");

	CButton* pButton1 = CButton::create("btn1_1.png", "btn1_2.png", "btn1_3.png");
	pButton1->setPosition(Vec2(350, 320));
	pButton1->initText("Cocos2d-x","fonts/arial.ttf",22);
	pButton1->getLabel()->enableShadow(Color4B::GREEN,Size(2,2),1);
	m_pWindow->addChild(pButton1);

	CLabel* pText1 = CLabel::create();
	pText1->setAnchorPoint(Vec2(0, 0.5));
	pText1->setPosition(Vec2(260, 430));
	pText1->setString("Shadow Text");
	m_pWindow->addChild(pText1);

	CButton* pButton2 = CButton::create("btn1_1.png", "btn1_2.png", "btn1_3.png");
	pButton2->initText("CocosWidget", "fonts/arial.ttf", 32.0f);
	pButton2->getLabel()->enableOutline(Color4B::BLUE,2);
	pButton2->setLabelOffset(Vec2(0, 10));
	pButton2->setPosition(Vec2(610, 320));
	m_pWindow->addChild(pButton2);

	CLabel* pText2 = CLabel::create();
	pText2->setAnchorPoint(Vec2(0, 0.5));
	pText2->setPosition(Vec2(520, 430));
	pText2->setString("Text With Offset and outline");
	m_pWindow->addChild(pText2);

	return true;
}

////////////////////////////////////////////////////////

bool CButtonAttributeTest::init()
{
	CButtonTestSceneBase::init();
	setTitle("CButtonAttributeTest");
	setDescription("");

	CButton* pButton1 = CButton::create("btn1_1.png", "btn1_2.png", "btn1_3.png");
	pButton1->initText("true", "", 30.0f);
	pButton1->setPosition(Vec2(480, 500));
	pButton1->setEnabled(true);
	m_pWindow->addChild(pButton1);

	CButton* pButton1ex = CButton::create("btn1_1.png", "btn1_2.png", "btn1_3.png");
	pButton1ex->initText("false", "", 30.0f);
	pButton1ex->setPosition(Vec2(680, 500));
	pButton1ex->setEnabled(false);
	m_pWindow->addChild(pButton1ex);

	CLabel* pText1 = CLabel::create();
	pText1->setAnchorPoint(Vec2(1, 0.5));
	pText1->setPosition(Vec2(350, 500));
	pText1->setString("setEnabled()");
	m_pWindow->addChild(pText1);


	CButton* pButton2 = CButton::create("btn1_1.png", "btn1_2.png", "btn1_3.png");
	pButton2->initText("true", "", 30.0f);
	pButton2->setPosition(Vec2(480, 400));
	pButton2->setTouchEnabled(true);
	m_pWindow->addChild(pButton2);

	CButton* pButton2ex = CButton::create("btn1_1.png", "btn1_2.png", "btn1_3.png");
	pButton2ex->initText("false", "", 30.0f);
	pButton2ex->setPosition(Vec2(680, 400));
	pButton2ex->setTouchEnabled(false);
	m_pWindow->addChild(pButton2ex);

	CLabel* pText2 = CLabel::create();
	pText2->setAnchorPoint(Vec2(1, 0.5));
	pText2->setPosition(Vec2(350, 400));
	pText2->setString("setTouchEnabled()");
	m_pWindow->addChild(pText2);


	CButton* pButton3 = CButton::create("btn1_1.png", "btn1_2.png", "btn1_3.png");
	pButton3->initText("true", "", 30.0f);
	pButton3->setPosition(Vec2(480, 300));
	pButton3->setVisible(true);
	m_pWindow->addChild(pButton3);

	CButton* pButton3ex = CButton::create("btn1_1.png", "btn1_2.png", "btn1_3.png");
	pButton3ex->initText("false", "", 30.0f);
	pButton3ex->setPosition(Vec2(680, 300));
	pButton3ex->setVisible(false);
	m_pWindow->addChild(pButton3ex);

	CLabel* pText3 = CLabel::create();
	pText3->setAnchorPoint(Vec2(1, 0.5));
	pText3->setPosition(Vec2(350, 300));
	pText3->setString("setVisible()");
	m_pWindow->addChild(pText3);

	return true;
}

////////////////////////////////////////////////////////

bool CButton9SpriteTest::init()
{
	CButtonTestSceneBase::init();
	setTitle("CButton9SpriteTest");
	setDescription("9PatchSprite by create");

	CButton* pButton = CButton::createWith9Sprite(Size(196, 68),"sprite9_btn1.png", "sprite9_btn2.png");
	pButton->initText("one", "", 30.0f);
	pButton->setPosition(Vec2(480, 370));
	m_pWindow->addChild(pButton);

	CButton* pButton2 = CButton::create();
	pButton2->setContentSize(Size(196, 68));
	pButton2->setScale9Enabled(true);
	pButton2->setNormalImage("sprite9_btn1.png");
	pButton2->setSelectedImage("sprite9_btn2.png");
	pButton2->initText("two", "", 30.0f);
	pButton2->setPosition(Vec2(480, 270));
	m_pWindow->addChild(pButton2);

	return true;
}

////////////////////////////////////////////////////////

bool CButtonChangeSizeTest::init()
{
	CButtonTestSceneBase::init();
	setTitle("CButtonChangeSizeTest");
	setDescription("click the button for change anothor one");

	m_lData.push_back("a");
	m_lData.push_back("ab");
	m_lData.push_back("abc");
	m_lData.push_back("abcd");
	m_lData.push_back("abcde");
	m_lData.push_back("abcdef");
	m_lData.push_back("abcdefg");
	m_lData.push_back("abcdefgi");
	m_lData.push_back("abcdefgj");
	m_lData.push_back("hahahahaha\nhehehehehe");
	m_lData.push_back("hahahahaha\nhehehehehe\nkukukukukukukuku");

	m_pButton = CButton::create();
	m_pButton->setScale9Enabled(true);
	m_pButton->setNormalImage("sprite9_btn1.png");
	m_pButton->setSelectedImage("sprite9_btn2.png");
	m_pButton->initText("none", "", 30.0f);
	m_pButton->setCascadeTextSizeEnabled(true, Size(50, 30));
	m_pButton->setPosition(Vec2(480, 320));
	m_pWindow->addChild(m_pButton);

	CButton* pBtn = CButton::createWith9Sprite(Size(150, 50), "sprite9_btn1.png", "sprite9_btn2.png");
	pBtn->setPosition(Vec2(250, 320));
	pBtn->initText("click me", "", 27.0f);
	pBtn->setOnClickListener(this, ccw_click_selector(CButtonChangeSizeTest::onClick));
	m_pWindow->addChild(pBtn);

	return true;
}

void CButtonChangeSizeTest::onClick(Ref* pSender)
{
	if( !m_lData.empty() )
	{
		string& str = m_lData.front();
		m_pButton->setText(str.c_str());
		m_lData.pop_front();
	}
}