#include "GridViewTest.h"

void CGridViewTestSceneBase::onNextBtnClick(Ref* pSender)
{
	nextCGridViewTestScene();
}

void CGridViewTestSceneBase::onBackBtnClick(Ref* pSender)
{
	backCGridViewTestScene();
}

void CGridViewTestSceneBase::onRefBtnClick(Ref* pSender)
{
	refCGridViewTestScene();
}

//////////////////////////////////////////////////////

bool CGridViewBasicTest::init()
{
	CGridViewTestSceneBase::init();
	setTitle("CGridViewBasicTest");
	setDescription("GridView basic test (only work in vertical)");

	Sprite* pBg = Sprite::create("background.png");
	pBg->setPosition(Point(480, 320));
	m_pWindow->addChild(pBg);

	CGridView* pGridView = CGridView::create(
		Size(480, 320),
		Size(480 / 5, 320 / 4),
		96, this,
		ccw_datasource_adapter_selector(CGridViewBasicTest::gridviewDataSource));
	pGridView->setColumns(5);
	pGridView->setPosition(Point(480, 320));
	m_pWindow->addChild(pGridView);
	pGridView->setAutoRelocate(true);
	pGridView->reloadData();

	return true;
}

Ref* CGridViewBasicTest::gridviewDataSource(Ref* pConvertView, unsigned int idx)
{
	CGridViewCell* pCell = (CGridViewCell*) pConvertView;
	CButton* pButton = NULL;

	if(!pCell)
	{
		pCell = new CGridViewCell();
		pCell->autorelease();

		pButton = CButton::createWith9Sprite(Size(70, 70), "sprite9_btn1.png", "sprite9_btn2.png");
		pButton->setPosition(Point(480 / 5 / 2, 320 / 4 / 2));
//		pButton->getLabel()->setFontSize(25.0f);
		pButton->setTag(1);
		pCell->addChild(pButton);
	}
	else
	{
		pButton = (CButton*) pCell->getChildByTag(1);
	}

	char buff[64];
	sprintf(buff, "%u", idx);
	pButton->getLabel()->setString(buff);
	pButton->setUserTag(idx);

	return pCell;
}

//////////////////////////////////////////////////////