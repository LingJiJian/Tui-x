#include "ScrollViewTest.h"

void CScrollViewTestSceneBase::onNextBtnClick(Ref* pSender)
{
	nextCScrollViewTestScene();
}

void CScrollViewTestSceneBase::onBackBtnClick(Ref* pSender)
{
	backCScrollViewTestScene();
}

void CScrollViewTestSceneBase::onRefBtnClick(Ref* pSender)
{
	refCScrollViewTestScene();
}

//////////////////////////////////////////////////////

bool CScrollViewBasicTest::init()
{
	CScrollViewTestSceneBase::init();
	setTitle("CScrollViewBasicTest");
	setDescription("ScrollView basic test");

	CScrollView* pScroll = CScrollView::create(Size(480, 320));
	pScroll->setPosition(Point(480, 320));
	pScroll->setDirection(eScrollViewDirectionBoth);
	pScroll->setBackgroundImage("background.png");
	m_pWindow->addChild(pScroll);


	Sprite* pSprite = Sprite::create("scrollcontent.png");
	pSprite->setAnchorPoint(Point::ZERO);
	pSprite->setPosition(Point::ZERO);
	pScroll->setContainerSize(pSprite->getContentSize());
	pScroll->getContainer()->addChild(pSprite);

	return true;
}

//////////////////////////////////////////////////////

bool CScrollViewEventTest::init()
{
	CScrollViewTestSceneBase::init();
	setTitle("CScrollViewEventTest");
	setDescription("test event");

	Sprite* pBg = Sprite::create("background.png");
	pBg->setPosition(Point(680, 320));
	m_pWindow->addChild(pBg);

	CScrollView* pScroll = CScrollView::create(Size(480, 320));
	pScroll->setOnScrollingListener(this, ccw_scrolling_selector(CScrollViewEventTest::onScrolling));
	pScroll->setPosition(Point(680, 320));
	pScroll->setDirection(eScrollViewDirectionBoth);
	m_pWindow->addChild(pScroll);

	Sprite* pSprite = Sprite::create("scrollcontent.png");
	pSprite->setAnchorPoint(Point::ZERO);
	pSprite->setPosition(Point::ZERO);
	pScroll->setContainerSize(pSprite->getContentSize());
	pScroll->getContainer()->addChild(pSprite);

	m_pText1 = CLabel::create();
	m_pText1->setAnchorPoint(Point(0, 0.5));
	m_pText1->setPosition(Point(35, 460));
	//m_pText1->setFontSize(35.0f);
	m_pText1->setString("contentOffset:");
	m_pWindow->addChild(m_pText1);

	return true;
}

void CScrollViewEventTest::onScrolling(Ref* pSender)
{
	CScrollView* pScroll = (CScrollView*) pSender;

	char buff[64];
	sprintf(buff, "contentOffset:[%d][%d]", (int)pScroll->getContentOffset().x, (int)pScroll->getContentOffset().y);
	m_pText1->setString(buff);
}

//////////////////////////////////////////////////////

bool CScrollViewHorizontalTest::init()
{
	CScrollViewTestSceneBase::init();
	setTitle("CScrollViewHorizontalTest");
	setDescription("direction by horizontal\n add some buttons and sprites ");

	Sprite* pBg = Sprite::create("background.png");
	pBg->setPosition(Point(480, 320));
	m_pWindow->addChild(pBg);

	CScrollView* pScroll = CScrollView::create(Size(480, 320));
	pScroll->setPosition(Point(480, 320));
	pScroll->setDirection(eScrollViewDirectionHorizontal);
	m_pWindow->addChild(pScroll);

	Sprite* pSprite = Sprite::create("scrollcontent.png");
	pSprite->setAnchorPoint(Point::ZERO);
	pSprite->setPosition(Point::ZERO);
	pScroll->setContainerSize(pSprite->getContentSize());
	pScroll->getContainer()->addChild(pSprite);
	
	for(int i = 0; i < 10; i++)
	{
		Sprite* pIcon = Sprite::create("icon.png");
		pIcon->setAnchorPoint(Point::ZERO);
		pIcon->setPosition(Point(i * 100, 0));
		pScroll->getContainer()->addChild(pIcon);
	}

	for(int i = 0; i < 5; i++)
	{
		CButton* pButton = CButton::createWith9Sprite(Size(150, 50), "sprite9_btn1.png", "sprite9_btn2.png");
		pButton->setAnchorPoint(Point::ZERO);
		pButton->setPosition(Point(i * 200, 200));
		pScroll->getContainer()->addChild(pButton);
	}
	
	return true;
}

//////////////////////////////////////////////////////

bool CScrollViewVerticalTest::init()
{
	CScrollViewTestSceneBase::init();
	setTitle("CScrollViewVerticalTest");
	setDescription("direction by vertical\n add some toggle button in the same group");

	Sprite* pBg = Sprite::create("background.png");
	pBg->setPosition(Point(480, 320));
	m_pWindow->addChild(pBg);

	CScrollView* pScroll = CScrollView::create(Size(480, 320));
	pScroll->setPosition(Point(480, 320));
	pScroll->setDirection(eScrollViewDirectionVertical);
	m_pWindow->addChild(pScroll);

	Sprite* pSprite = Sprite::create("scrollcontent.png");
	pSprite->setAnchorPoint(Point::ZERO);
	pSprite->setPosition(Point::ZERO);
	pScroll->setContainerSize(pSprite->getContentSize());
	pScroll->getContainer()->addChild(pSprite);

	for(int i = 0; i < 5; i++)
	{
		CToggleView* pToggleButton = CToggleView::create("toggle1_1.png", "toggle1_2.png");
		pToggleButton->setAnchorPoint(Point::ZERO);
		pToggleButton->setPosition(Point(130, i * 130));
		pToggleButton->setExclusion(1);
		pScroll->getContainer()->addChild(pToggleButton);
	}

	return true;
}

//////////////////////////////////////////////////////

bool CScrollViewAttributeTest::init()
{
	CScrollViewTestSceneBase::init();
	setTitle("CScrollViewAttributeTest");
	setDescription("test attribute of scroll");

	Sprite* pBg = Sprite::create("background.png");
	pBg->setPosition(Point(680, 320));
	m_pWindow->addChild(pBg);

	pScroll = CScrollView::create(Size(480, 320));
	pScroll->setPosition(Point(680, 320));
	pScroll->setDirection(eScrollViewDirectionVertical);
	m_pWindow->addChild(pScroll);

	Sprite* pSprite = Sprite::create("scrollcontent.png");
	pSprite->setAnchorPoint(Point::ZERO);
	pSprite->setPosition(Point::ZERO);
	pScroll->setContainerSize(pSprite->getContentSize());
	pScroll->getContainer()->addChild(pSprite);

	for(int i = 0; i < 5; i++)
	{
		CToggleView* pToggleButton = CToggleView::create("toggle1_1.png", "toggle1_2.png");
		pToggleButton->setAnchorPoint(Point::ZERO);
		pToggleButton->setPosition(Point(130, i * 130));
		pToggleButton->setExclusion(1);
		pScroll->getContainer()->addChild(pToggleButton);
	}

	CToggleView* pToggle1 = CToggleView::createWith9Sprite(Size(150, 50), "sprite9_btn1.png", "sprite9_btn2.png");
	pToggle1->initText("setDeaccelerateable", "", 28);
	pToggle1->setPosition(150, 480);
	pToggle1->setChecked(true);
	pToggle1->setOnClickListener(this, ccw_click_selector(CScrollViewAttributeTest::onClick));
	pToggle1->setUserTag(1);
	m_pWindow->addChild(pToggle1);

	CLabel* pText1 = CLabel::create();
	pText1->setAnchorPoint(Point(0, 0.5));
	pText1->setPosition(Point(300, 480));
	//pText1->setFontSize(35.0f);
	pText1->setString("true");
	m_pWindow->addChild(pText1);
	pToggle1->setUserObject(pText1);

	CToggleView* pToggle2 = CToggleView::createWith9Sprite(Size(150, 50), "sprite9_btn1.png", "sprite9_btn2.png");
	pToggle2->initText("setBounceable", "", 28);
	pToggle2->setPosition(150, 400);
	pToggle2->setChecked(true);
	pToggle2->setOnClickListener(this, ccw_click_selector(CScrollViewAttributeTest::onClick));
	pToggle2->setUserTag(2);
	m_pWindow->addChild(pToggle2);

	CLabel* pText2 = CLabel::create();
	pText2->setAnchorPoint(Point(0, 0.5));
	pText2->setPosition(Point(300, 400));
//	pText2->setFontSize(35.0f);
	pText2->setString("true");
	m_pWindow->addChild(pText2);
	pToggle2->setUserObject(pText2);


	CToggleView* pToggle3 = CToggleView::createWith9Sprite(Size(150, 50), "sprite9_btn1.png", "sprite9_btn2.png");
	pToggle3->initText("setDragable", "", 28);
	pToggle3->setPosition(150, 320);
	pToggle3->setChecked(true);
	pToggle3->setOnClickListener(this, ccw_click_selector(CScrollViewAttributeTest::onClick));
	pToggle3->setUserTag(3);
	m_pWindow->addChild(pToggle3);

	CLabel* pText3 = CLabel::create();
	pText3->setAnchorPoint(Point(0, 0.5));
	pText3->setPosition(Point(300, 320));
	//pText3->setFontSize(35.0f);
	pText3->setString("true");
	m_pWindow->addChild(pText3);
	pToggle3->setUserObject(pText3);


	CToggleView* pToggle4 = CToggleView::createWith9Sprite(Size(150, 50), "sprite9_btn1.png", "sprite9_btn2.png");
	pToggle4->initText("setTouchEnabled", "", 28);
	pToggle4->setPosition(150, 240);
	pToggle4->setChecked(true);
	pToggle4->setOnClickListener(this, ccw_click_selector(CScrollViewAttributeTest::onClick));
	pToggle4->setUserTag(4);
	m_pWindow->addChild(pToggle4);

	CLabel* pText4 = CLabel::create();
	pText4->setAnchorPoint(Point(0, 0.5));
	pText4->setPosition(Point(300, 240));
	//pText4->setFontSize(35.0f);
	pText4->setString("true");
	m_pWindow->addChild(pText4);
	pToggle4->setUserObject(pText4);

	return true;
}

void CScrollViewAttributeTest::onClick(Ref* pSender)
{
	CToggleView* pToggle = (CToggleView*) pSender;
	CLabel* pText = (CLabel*) pToggle->getUserObject();
	
	if( pToggle->isChecked() )
	{
		pText->setString("true");
	}
	else
	{
		pText->setString("false");
	}

	if( pToggle->getUserTag() == 1 )
	{
		pScroll->setDeaccelerateable(pToggle->isChecked());
	}
	else if( pToggle->getUserTag() == 2 )
	{
		pScroll->setBounceable(pToggle->isChecked());
	}
	else if( pToggle->getUserTag() == 3 )
	{
		pScroll->setDragable(pToggle->isChecked());
	}
	else if( pToggle->getUserTag() == 4 )
	{
		pScroll->setTouchEnabled(pToggle->isChecked());
	}
}

//////////////////////////////////////////////////////

bool CScrollViewAnimationTest::init()
{
	CScrollViewTestSceneBase::init();
	setTitle("CScrollViewAnimationTest");
	setDescription("test animation");

	Sprite* pBg = Sprite::create("background.png");
	pBg->setPosition(Point(680, 320));
	m_pWindow->addChild(pBg);

	pScroll = CScrollView::create(Size(480, 320));
	pScroll->setPosition(Point(680, 320));
	pScroll->setDirection(eScrollViewDirectionHorizontal);
	m_pWindow->addChild(pScroll);

	Sprite* pSprite = Sprite::create("scrollcontent.png");
	pSprite->setAnchorPoint(Point::ZERO);
	pSprite->setPosition(Point::ZERO);
	pScroll->setContainerSize(pSprite->getContentSize());
	pScroll->getContainer()->addChild(pSprite);

	for(int i = 0; i < 10; i++)
	{
		Sprite* pIcon = Sprite::create("icon.png");
		pIcon->setAnchorPoint(Point::ZERO);
		pIcon->setPosition(Point(i * 100, 100));
		pScroll->getContainer()->addChild(pIcon);
	}


	CButton* pButton1 = CButton::createWith9Sprite(Size(150, 50), "sprite9_btn1.png", "sprite9_btn2.png");
	pButton1->initText("scrollToRight", "", 28);
	pButton1->setPosition(120, 480);
	pButton1->setOnClickListener(this, ccw_click_selector(CScrollViewAnimationTest::onClick));
	pButton1->setUserTag(1);
	m_pWindow->addChild(pButton1);

	CLabel* pText1 = CLabel::create();
	pText1->setAnchorPoint(Point(0, 0.5));
	pText1->setPosition(Point(240, 480));
	//pText1->setFontSize(35.0f);
	pText1->setString("setContentOffsetInDuration");
	m_pWindow->addChild(pText1);


	CButton* pButton2 = CButton::createWith9Sprite(Size(150, 50), "sprite9_btn1.png", "sprite9_btn2.png");
	pButton2->initText("scrollToLeft", "", 28);
	pButton2->setPosition(120, 400);
	pButton2->setOnClickListener(this, ccw_click_selector(CScrollViewAnimationTest::onClick));
	pButton2->setUserTag(2);
	m_pWindow->addChild(pButton2);

	CLabel* pText2 = CLabel::create();
	pText2->setAnchorPoint(Point(0, 0.5));
	pText2->setPosition(Point(240, 400));
	//pText2->setFontSize(35.0f);
	pText2->setString("setContentOffsetEaseIn");
	m_pWindow->addChild(pText2);

	CButton* pButton3 = CButton::createWith9Sprite(Size(150, 50), "sprite9_btn1.png", "sprite9_btn2.png");
	pButton3->initText("scrollToRight", "", 28);
	pButton3->setPosition(120, 320);
	pButton3->setOnClickListener(this, ccw_click_selector(CScrollViewAnimationTest::onClick));
	pButton3->setUserTag(3);
	m_pWindow->addChild(pButton3);

	CLabel* pText3 = CLabel::create();
	pText3->setAnchorPoint(Point(0, 0.5));
	pText3->setPosition(Point(240, 320));
	//pText3->setFontSize(35.0f);
	pText3->setString("setContentOffset");
	m_pWindow->addChild(pText3);

	return true;
}

void CScrollViewAnimationTest::onClick(Ref* pSender)
{
	CButton* pBtn = (CButton*) pSender;
	if( pBtn->getUserTag() == 1 )
	{
		pScroll->setContentOffsetInDuration(pScroll->getMinOffset(), 1.0f);
	}
	else if( pBtn->getUserTag() == 2 )
	{
		pScroll->setContentOffsetEaseIn(pScroll->getMaxOffset(), 1.0f, 0.2f);
	}
	else if( pBtn->getUserTag() == 3 )
	{
		pScroll->setContentOffset(pScroll->getMinOffset());
	}
}

//////////////////////////////////////////////////////

bool CScrollViewInsideScrollTest::init()
{
	CScrollViewTestSceneBase::init();
	setTitle("CScrollViewInsideScrollTest");
	setDescription("Scroll view inside the other one");

	CScrollView* pScroll = CScrollView::create(Size(480, 320));
	pScroll->setBackgroundImage("background.png");
	pScroll->setPosition(Point(480, 320));
	pScroll->setDirection(eScrollViewDirectionBoth);
	m_pWindow->addChild(pScroll);

	Sprite* pSprite = Sprite::create("scrollcontent.png");
	pSprite->setAnchorPoint(Point::ZERO);
	pSprite->setPosition(Point::ZERO);
	pScroll->setContainerSize(pSprite->getContentSize());
	pScroll->getContainer()->addChild(pSprite);

	CScrollView* pScroll2 = CScrollView::create(Size(272, 76));
	pScroll2->setDirection(eScrollViewDirectionHorizontal);
	pScroll2->setBackgroundImage("background3.png");
	pScroll2->setPosition(Point(480 /2, 320 / 2));
	pScroll->getContainer()->addChild(pScroll2);

	pScroll2->setContainerSize(Size(62 * 20, 76));
	for( int i = 0; i < 20; ++i )
	{
		Sprite* pSp = Sprite::create("icon.png");
		pSp->setAnchorPoint(Point::ZERO);
		pSp->setPosition(Point(i * 62, 0));
		pScroll2->getContainer()->addChild(pSp);
	}

	return true;
}