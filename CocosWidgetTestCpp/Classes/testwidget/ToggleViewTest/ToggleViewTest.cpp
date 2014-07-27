#include "ToggleViewTest.h"

void CToggleViewTestSceneBase::onNextBtnClick(Ref* pSender)
{
	nextCToggleViewTestScene();
}

void CToggleViewTestSceneBase::onBackBtnClick(Ref* pSender)
{
	backCToggleViewTestScene();
}

void CToggleViewTestSceneBase::onRefBtnClick(Ref* pSender)
{
	refCToggleViewTestScene();
}

//////////////////////////////////////////////////////

bool CToggleViewBasicTest::init()
{
	CToggleViewTestSceneBase::init();
	setTitle("CToggleViewBasicTest");
	setDescription("toggle button");
	
	CToggleView* pToggle = CToggleView::create("toggle1_2.png", "toggle1_1.png");
	pToggle->setOnClickListener(this, ccw_click_selector(CToggleViewBasicTest::onClick));
	pToggle->setPosition(Vec2(480, 320));
	m_pWindow->addChild(pToggle);

	m_pText = CLabel::createWithSystemFont("none","",35);
	m_pText->setAnchorPoint(Vec2(0, 0.5));
	m_pText->setPosition(Vec2(380, 400));
	m_pText->setString("none");
	m_pWindow->addChild(m_pText);

	return true;
}

void CToggleViewBasicTest::onClick(Ref* pSender)
{
	CToggleView* pToggle = (CToggleView*) pSender;
	if( pToggle->isChecked() )
	{
		m_pText->setString("checked");
	}
	else
	{
		m_pText->setString("unchecked");
	}
}

//////////////////////////////////////////////////////

bool CToggleViewGroupTest::init()
{
	CToggleViewTestSceneBase::init();
	setTitle("CToggleViewGroupTest");
	setDescription("Toggle button in group");

	CToggleView* pToggle1 = CToggleView::create("toggle1_2.png", "toggle1_1.png");
	pToggle1->setOnCheckListener(this, ccw_check_selector(CToggleViewGroupTest::onCheck));
	pToggle1->setPosition(Vec2(200, 450));
	pToggle1->setExclusion(1);
	m_pWindow->addChild(pToggle1);

	CToggleView* pToggle2 = CToggleView::create("toggle1_2.png", "toggle1_1.png");
	pToggle2->setOnCheckListener(this, ccw_check_selector(CToggleViewGroupTest::onCheck));
	pToggle2->setPosition(Vec2(200, 350));
	pToggle2->setExclusion(1);
	m_pWindow->addChild(pToggle2);

	CToggleView* pToggle3 = CToggleView::create("toggle1_2.png", "toggle1_1.png");
	pToggle3->setOnCheckListener(this, ccw_check_selector(CToggleViewGroupTest::onCheck));
	pToggle3->setPosition(Vec2(200, 250));
	pToggle3->setExclusion(1);
	m_pWindow->addChild(pToggle3);

	CLabel* pText1 = CLabel::createWithSystemFont("none","",35);
	pText1->setAnchorPoint(Vec2(0, 0.5));
	pText1->setPosition(Vec2(350, 450));
	pText1->setString("none");
	m_pWindow->addChild(pText1);
	pToggle1->setUserObject(pText1);

	CLabel* pText2 = CLabel::createWithSystemFont("none","",35);
	pText2->setAnchorPoint(Vec2(0, 0.5));
	pText2->setPosition(Vec2(350, 350));
	pText2->setString("none");
	m_pWindow->addChild(pText2);
	pToggle2->setUserObject(pText2);

	CLabel* pText3 = CLabel::createWithSystemFont("none","",35);
	pText3->setAnchorPoint(Vec2(0, 0.5));
	pText3->setPosition(Vec2(350, 250));
	pText3->setString("none");
	m_pWindow->addChild(pText3);
	pToggle3->setUserObject(pText3);


	CToggleView* pToggle4 = CToggleView::create("toggle1_2.png", "toggle1_1.png");
	pToggle4->setPosition(Vec2(700, 250));
	pToggle4->setExclusion(2);
	m_pWindow->addChild(pToggle4);

	CToggleView* pToggle5 = CToggleView::create("toggle1_2.png", "toggle1_1.png");
	pToggle5->setPosition(Vec2(700, 350));
	pToggle5->setExclusion(2);
	m_pWindow->addChild(pToggle5);

	return true;
}

void CToggleViewGroupTest::onCheck(Ref* pSender, bool bChecked)
{
	CToggleView* pToggle = (CToggleView*) pSender;
	CLabel* pText = (CLabel*) pToggle->getUserObject();

	if( bChecked )
	{
		pText->setString("checked");
	}
	else
	{
		pText->setString("unchecked");
	}
}