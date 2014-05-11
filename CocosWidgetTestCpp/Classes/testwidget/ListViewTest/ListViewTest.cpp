#include "ListViewTest.h"

void CListViewTestSceneBase::onNextBtnClick(Ref* pSender)
{
	nextCListViewTestScene();
}

void CListViewTestSceneBase::onBackBtnClick(Ref* pSender)
{
	backCListViewTestScene();
}

void CListViewTestSceneBase::onRefBtnClick(Ref* pSender)
{
	refCListViewTestScene();
}

//////////////////////////////////////////////////////

bool CListViewBasicTest::init()
{
	CListViewTestSceneBase::init();
	setTitle("CListViewBasicTest");
	setDescription("ListView Test");

	//test data
	tagItem tag1 = { Size(480, 10), Color3B::WHITE };
	tagItem tag2 = { Size(480, 20), Color3B::RED };
	tagItem tag3 = { Size(480, 30), Color3B::GREEN };
	tagItem tag4 = { Size(100, 40), Color3B::ORANGE };
	tagItem tag5 = { Size(480, 50), Color3B::MAGENTA };
	tagItem tag6 = { Size(400, 60), Color3B::BLUE };
	tagItem tag7 = { Size(300, 80), Color3B::RED };
	tagItem tag8 = { Size(480, 30), Color3B::GRAY };
	tagItem tag9 = { Size(480, 40), Color3B::YELLOW };
	m_lDatas.push_back(tag1);
	m_lDatas.push_back(tag2);
	m_lDatas.push_back(tag3);
	m_lDatas.push_back(tag4);
	m_lDatas.push_back(tag5);
	m_lDatas.push_back(tag6);
	m_lDatas.push_back(tag7);
	m_lDatas.push_back(tag8);
	m_lDatas.push_back(tag9);
	//<<

	m_pListView = CListView::create(Size(480, 320));
	m_pListView->setBackgroundImage("background.png");
	m_pListView->setPosition(Point(480, 320));
	m_pListView->setDirection(eScrollViewDirectionVertical);
	m_pWindow->addChild(m_pListView);

	CButton* pButton = CButton::createWith9Sprite(Size(150, 50),
		"sprite9_btn1.png", "sprite9_btn2.png");
	pButton->setPosition(Point(150, 320));
	pButton->setOnClickListener(this, ccw_click_selector(CListViewBasicTest::onClick));
	pButton->initText("Add", "", 30);
	m_pWindow->addChild(pButton);

	return true;
}

void CListViewBasicTest::onClick(Ref* pSender)
{
	if( !m_lDatas.empty() )
	{
		tagItem& tItem = m_lDatas.front();

		CLayout* pLayout = CLayout::create();
		pLayout->setContentSize(tItem.tSize);
		/*
		pLayout->setBackgroundColor(Color4B(tItem.tColor.r,
			tItem.tColor.g,
			tItem.tColor.b,
			255));
			*/
		pLayout->setBackgroundImage("icon.png");
		pLayout->ignoreAnchorPointForPosition(false);
		pLayout->setAnchorPoint(Point(0.5f, 0.5f));
		pLayout->setContentSize(Size(tItem.tSize.width - 4, tItem.tSize.height - 2));
		pLayout->setPosition(Point(tItem.tSize.width/2, tItem.tSize.height/2));

		m_pListView->insertNodeAtLast(pLayout);
		m_pListView->reloadData();
		m_lDatas.pop_front();
	}
}

//////////////////////////////////////////////////////

bool CListViewOperateTest::init()
{
	CListViewTestSceneBase::init();
	setTitle("CListViewOperateTest");
	setDescription("Add or Remove operate");

	m_pListView = CListView::create(Size(480, 320));
	m_pListView->setBackgroundImage("background.png");
	m_pListView->setPosition(Point(480, 320));
	m_pListView->setDirection(eScrollViewDirectionVertical);
	m_pWindow->addChild(m_pListView);

	CButton* pButton = CButton::createWith9Sprite(Size(150, 50),
		"sprite9_btn1.png", "sprite9_btn2.png");
	pButton->setPosition(Point(150, 450));
	pButton->setUserTag(1);
	pButton->setOnClickListener(this, ccw_click_selector(CListViewOperateTest::onClick));
	pButton->initText("Add Last", "", 30);
	m_pWindow->addChild(pButton);

	CButton* pButton2 = CButton::createWith9Sprite(Size(150, 50),
		"sprite9_btn1.png", "sprite9_btn2.png");
	pButton2->setPosition(Point(150, 380));
	pButton2->setUserTag(2);
	pButton2->setOnClickListener(this, ccw_click_selector(CListViewOperateTest::onClick));
	pButton2->initText("Add Front", "", 30);
	m_pWindow->addChild(pButton2);

	CButton* pButton3 = CButton::createWith9Sprite(Size(150, 50),
		"sprite9_btn1.png", "sprite9_btn2.png");
	pButton3->setPosition(Point(150, 310));
	pButton3->setUserTag(3);
	pButton3->setOnClickListener(this, ccw_click_selector(CListViewOperateTest::onClick));
	pButton3->initText("Remove Last", "", 30);
	m_pWindow->addChild(pButton3);

	CButton* pButton4 = CButton::createWith9Sprite(Size(150, 50),
		"sprite9_btn1.png", "sprite9_btn2.png");
	pButton4->setPosition(Point(150, 240));
	pButton4->setUserTag(4);
	pButton4->setOnClickListener(this, ccw_click_selector(CListViewOperateTest::onClick));
	pButton4->initText("Remove Front", "", 30);
	m_pWindow->addChild(pButton4);

	return true;
}

static int last_add_idx = 0;

void CListViewOperateTest::onClick(Ref* pSender)
{
	CButton* pButton = (CButton*) pSender;
	switch(pButton->getUserTag())
	{
	case 1:
		{
			CLayout* pLayout = CLayout::create();
			pLayout->setContentSize(Size(480, 30));
			/*
			CColorView* pColor = CColorView::create(Color4B(128, 0, 0, 255));
			pColor->setContentSize(Size(478, 28));
			pColor->setPosition(Point(480/2, 30/2));
			pLayout->addChild(pColor);
			*/
			CButton* pButton =  CButton::createWith9Sprite(Size(150, 25),
				"sprite9_btn1.png", "sprite9_btn2.png");
			pButton->setPosition(Point(480 /2, 30 /2));
			char str[64] = {0};
			sprintf(str, "%d", last_add_idx);
			pButton->initText(str, "", 20);
			pLayout->addChild(pButton);
			last_add_idx++;

			m_pListView->insertNodeAtLast(pLayout);
			m_pListView->reloadData();
		}
		break;
	case 2:
		{
			CLayout* pLayout = CLayout::create();
			pLayout->setContentSize(Size(480, 30));
			/*
			CColorView* pColor = CColorView::create(Color4B(0, 128, 0, 255));
			pColor->setContentSize(Size(478, 28));
			pColor->setPosition(Point(480/2, 30/2));
			pLayout->addChild(pColor);
			*/
			CButton* pButton =  CButton::createWith9Sprite(Size(150, 25),
				"sprite9_btn1.png", "sprite9_btn2.png");
			pButton->setPosition(Point(480 /2, 30 /2));
			char str[64] = {0};
			sprintf(str, "%d", last_add_idx);
			pButton->initText(str, "", 20);
			pLayout->addChild(pButton);
			last_add_idx++;

			m_pListView->insertNodeAtFront(pLayout);
			m_pListView->reloadData();
		}
		break;
	case 3:
		{
			m_pListView->removeLastNode();
			m_pListView->reloadData();
		}
		break;
	case 4:
		{
			m_pListView->removeFrontNode();
			m_pListView->reloadData();
		}
		break;
	default:
		break;
	}
}