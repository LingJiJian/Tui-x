#include "GridPageViewTest.h"

void CGridPageViewTestSceneBase::onNextBtnClick(Ref* pSender)
{
	nextCGridPageViewTestScene();
}

void CGridPageViewTestSceneBase::onBackBtnClick(Ref* pSender)
{
	backCGridPageViewTestScene();
}

void CGridPageViewTestSceneBase::onRefBtnClick(Ref* pSender)
{
	refCGridPageViewTestScene();
}

//////////////////////////////////////////////////////

bool CGridPageViewBasicTest::init()
{
	CGridPageViewTestSceneBase::init();
	setTitle("CGridPageViewBasicTest");
	setDescription("GridPageView basic test");

	Sprite* pBg = Sprite::create("background2.png");
	pBg->setPosition(Point(480, 320));
	m_pWindow->addChild(pBg);

	CGridPageView* pTable = CGridPageView::create(
		Size(320, 390),
		Size(320 / 4, 390 / 5),
		72, this, 
		ccw_datasource_adapter_selector(CGridPageViewBasicTest::gridpageviewDataSource));
	pTable->setColumns(4);
	pTable->setRows(5);
	pTable->setAutoRelocate(true);
	pTable->setPosition(Point(480, 320));
	m_pWindow->addChild(pTable);
	pTable->reloadData();

	return true;
}

Ref* CGridPageViewBasicTest::gridpageviewDataSource(Ref* pConvertCell, unsigned int idx)
{
	CGridPageViewCell* pCell = (CGridPageViewCell*) pConvertCell;
	CButton* pButton = NULL;

	if(!pCell)
	{
		pCell = new CGridPageViewCell();
		pCell->autorelease();

		pButton = CButton::createWith9Sprite(Size(70, 70), "sprite9_btn1.png", "sprite9_btn2.png");
		pButton->setPosition(Point(320 / 4 / 2, 390 / 5 / 2));
		//pButton->getLabel()->setFontSize(25.0f);
		pButton->setTag(1);
		pCell->addChild(pButton);
	}
	else
	{
		pButton = (CButton*) pCell->getChildByTag(1);
	}

	if( idx != CC_INVALID_INDEX )
	{
		pButton->setVisible(true);

		char buff[64];
		sprintf(buff, "%u", idx);
		pButton->getLabel()->setString(buff);
		pButton->setUserTag(idx);
	}
	else
	{
		pButton->setVisible(false);
	}

	return pCell;
}

//////////////////////////////////////////////////////

bool CGridPageViewBackPackTest::init()
{
	CGridPageViewTestSceneBase::init();
	setTitle("CGridPageViewBackPackTest");
	setDescription("backpack test, long click item and drag into circle for remove");

	for(int i = 0 ; i < 72; i++)
	{
		char buff[64];
		sprintf(buff, "%d", i);
		m_vData.push_back(buff);
	}

	Sprite* pBg = Sprite::create("background2.png");
	pBg->setPosition(Point(480, 320));
	m_pWindow->addChild(pBg);

	pTable = CGridPageView::create(
		Size(320, 390),
		Size(320 / 4, 390 / 5),
		m_vData.size(), this, 
		ccw_datasource_adapter_selector(CGridPageViewBackPackTest::gridpageviewDataSource));
	pTable->setColumns(4);
	pTable->setRows(5);
	pTable->setAutoRelocate(true);
	pTable->setPosition(Point(480, 320));
	m_pWindow->addChild(pTable);
	pTable->reloadData();

	m_pSelectedSprite = Sprite::create("icon.png");
	m_pSelectedSprite->setOpacity(170);
	m_pSelectedSprite->setLocalZOrder(1);
	m_pSelectedSprite->setVisible(false);
	m_pWindow->addChild(m_pSelectedSprite);

	m_pWindow->setOnTouchMovedAfterLongClickListener(this, ccw_afterlongclick_selector(CGridPageViewBackPackTest::onLayoutTouchMovedAfterLongClick));
	m_pWindow->setOnTouchEndedAfterLongClickListener(this, ccw_afterlongclick_selector(CGridPageViewBackPackTest::onLayoutTouchEndedAfterLongClick));
	m_pWindow->setOnTouchCancelledAfterLongClickListener(this, ccw_afterlongclick_selector(CGridPageViewBackPackTest::onLayoutTouchEndedAfterLongClick));

	m_pToggleImage = CToggleView::create("circle1.png", "circle2.png");
	m_pToggleImage->setPosition(Point(200, 320));
	m_pWindow->addChild(m_pToggleImage);

	return true;
}

Ref* CGridPageViewBackPackTest::gridpageviewDataSource(Ref* pConvertCell, unsigned int idx)
{
	CGridPageViewCell* pCell = (CGridPageViewCell*) pConvertCell;
	CButton* pIconButton = NULL;

	if(!pCell)
	{
		pCell = new CGridPageViewCell();
		pCell->autorelease();

		CScale9Sprite* pBg = CScale9Sprite::create("sprite9_btn1.png");
		pBg->setContentSize(Size(70, 70));
		pBg->setPosition(Point(320 / 4 / 2, 390 / 5 / 2));
		pCell->addChild(pBg);

		pIconButton = CButton::create("icon.png");
		pIconButton->setOnLongClickListener(this, ccw_longclick_selector(CGridPageViewBackPackTest::onItemLongClick));
		//pIconButton->getLabel()->setFontSize(25);
		pIconButton->setPosition(Point(320 / 4 / 2, 390 / 5 / 2));
		pIconButton->setLabelOffset(Point(-15, -15));
		pIconButton->setTag(1);
		pCell->addChild(pIconButton);
	}
	else
	{
		pIconButton = (CButton*) pCell->getChildByTag(1);
	}

	if( idx != CC_INVALID_INDEX )
	{
		pIconButton->setVisible(true);

		pIconButton->getLabel()->setString(m_vData[idx].c_str());
		pIconButton->setUserTag(idx);
	}
	else
	{
		pIconButton->setVisible(false);
	}

	return pCell;
}

bool CGridPageViewBackPackTest::onItemLongClick(Ref* pSender, Touch* pTouch)
{
	CButton* pIconButton = (CButton*) pSender;
	pIconButton->setVisible(false);
	Point tPoint = pIconButton->getParent()->convertToWorldSpace(pIconButton->getPosition());

	m_pSelectedSprite->setVisible(true);
	m_pSelectedSprite->setPosition(pTouch->getLocation());

	return true;
}

void CGridPageViewBackPackTest::onLayoutTouchMovedAfterLongClick(Ref* pSender, Touch* pTouch, float fDuration)
{
	m_pSelectedSprite->setPosition(pTouch->getLocation());

	Point tLayoutPoint = m_pWindow->convertTouchToNodeSpace(pTouch);
	if( m_pToggleImage->getBoundingBox().containsPoint(tLayoutPoint) )
	{
		m_pToggleImage->setChecked(true);
	}
	else
	{
		m_pToggleImage->setChecked(false);
	}
}

void CGridPageViewBackPackTest::onLayoutTouchEndedAfterLongClick(Ref* pSender, Touch* pTouch, float fDuration)
{
	CButton* pIconButton = (CButton*) pSender;
	
	m_pSelectedSprite->setPosition(pTouch->getLocation());

	pIconButton->setVisible(true); //back to the same as before drag
	m_pSelectedSprite->setVisible(false);
	m_pToggleImage->setChecked(false);

	Point tLayoutPoint = m_pWindow->convertTouchToNodeSpace(pTouch);
	if( m_pToggleImage->getBoundingBox().containsPoint(tLayoutPoint) )
	{
		m_vData.erase(m_vData.begin() + pIconButton->getUserTag());
		pTable->setCountOfCell(m_vData.size());
		pTable->reloadData();
		return;
	}
}
