#include "PageViewTest.h"

void CPageViewTestSceneBase::onNextBtnClick(Ref* pSender)
{
	nextCPageViewTestScene();
}

void CPageViewTestSceneBase::onBackBtnClick(Ref* pSender)
{
	backCPageViewTestScene();
}

void CPageViewTestSceneBase::onRefBtnClick(Ref* pSender)
{
	refCPageViewTestScene();
}

//////////////////////////////////////////////////////

bool CPageViewBasicTest::init()
{
	CPageViewTestSceneBase::init();
	setTitle("CPageViewBasicTest");
	setDescription("PageView basic test");

	CPageView* pPageView = CPageView::create(
		Size(484, 320),
		10, this,
		ccw_datasource_adapter_selector(CPageViewBasicTest::pageviewDataSource));
	pPageView->setOnPageChangedListener(this, ccw_pagechanged_selector(CPageViewBasicTest::onPageChanged));
	pPageView->setPosition(Point(480, 320));
	m_pWindow->addChild(pPageView);
	pPageView->reloadData();

	m_pText = CLabel::create();
	m_pText->setAnchorPoint(Point(0, 0.5));
	m_pText->setPosition(Point(800, 320));
//	m_pText->setFontSize(35.0f);
	m_pText->setString("none");
	m_pWindow->addChild(m_pText);

	return true;
}

Ref* CPageViewBasicTest::pageviewDataSource(Ref* pConvertCell, unsigned int nPageIdx)
{
	CPageViewCell* pPageCell = (CPageViewCell*) pConvertCell;
	CButton* pButton = NULL;

	if( !pPageCell )
	{
		pPageCell = new CPageViewCell();
		pPageCell->autorelease();
		pPageCell->setBackgroundImage("background.png");

		pButton = CButton::createWith9Sprite(Size(150, 50), "sprite9_btn1.png", "sprite9_btn2.png");
//		pButton->getLabel()->setFontSize(30.0f);
		pButton->setPosition(Point(484 / 2, 320 / 2));
		pButton->setTag(1);
		pPageCell->addChild(pButton);
	}
	else
	{
		pButton = (CButton*) pPageCell->getChildByTag(1);
	}

	char buf[48] = {0};
	sprintf(buf, "%u", nPageIdx);
	pButton->getLabel()->setString(buf);

	return pPageCell;
}

void CPageViewBasicTest::onPageChanged(CPageView* pPage, unsigned int nPageIndx)
{
	char buf[48] = {0};
	sprintf(buf, "%u", nPageIndx);
	m_pText->setString(buf);
}

//////////////////////////////////////////////////////

bool CPageViewVerticalTest::init()
{
	CPageViewTestSceneBase::init();
	setTitle("CPageViewVerticalTest");
	setDescription("PageView in vertical");

	CPageView* pPageView = CPageView::create(
		Size(484, 320),
		10, this,
		ccw_datasource_adapter_selector(CPageViewVerticalTest::pageviewDataSource));
	pPageView->setOnPageChangedListener(this, ccw_pagechanged_selector(CPageViewVerticalTest::onPageChanged));
	pPageView->setPosition(Point(480, 320));
	pPageView->setDirection(eScrollViewDirectionVertical);
	m_pWindow->addChild(pPageView);
	pPageView->reloadData();

	m_pText = CLabel::create();
	m_pText->setAnchorPoint(Point(0, 0.5));
	m_pText->setPosition(Point(800, 320));
//	m_pText->setFontSize(35.0f);
	m_pText->setString("none");
	m_pWindow->addChild(m_pText);

	return true;
}

Ref* CPageViewVerticalTest::pageviewDataSource(Ref* pConvertCell, unsigned int nPageIdx)
{
	CPageViewCell* pPageCell = (CPageViewCell*) pConvertCell;
	CButton* pButton = NULL;

	if( !pPageCell )
	{
		pPageCell = new CPageViewCell();
		pPageCell->autorelease();
		pPageCell->setBackgroundImage("background.png");

		pButton = CButton::createWith9Sprite(Size(150, 50), "sprite9_btn1.png", "sprite9_btn2.png");
//		pButton->getLabel()->setFontSize(30.0f);
		pButton->setPosition(Point(484 / 2, 320 / 2));
		pButton->setTag(1);
		pPageCell->addChild(pButton);
	}
	else
	{
		pButton = (CButton*) pPageCell->getChildByTag(1);
	}
	char buf[48] = {0};
	sprintf(buf, "%u", nPageIdx);
	pButton->getLabel()->setString(buf);

	return pPageCell;
}

void CPageViewVerticalTest::onPageChanged(CPageView* pPage, unsigned int nPageIndx)
{
	char buf[48] = {0};
	sprintf(buf, "%u", nPageIndx);
	m_pText->setString(buf);
}