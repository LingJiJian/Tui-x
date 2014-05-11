#ifndef __CGridPageViewGRIDTEST_H__
#define __CGridPageViewGRIDTEST_H__

#include "../../MenuScene.h"
#include <vector>

//////////////////////////////////////////////////////

class CGridPageViewTestSceneBase : public BaseTestScene
{
public:
	virtual void onNextBtnClick(Ref* pSender);
	virtual void onBackBtnClick(Ref* pSender);
	virtual void onRefBtnClick(Ref* pSender);
};

//////////////////////////////////////////////////////

class CGridPageViewBasicTest : public CGridPageViewTestSceneBase
{
public:
	CREATE_FUNC(CGridPageViewBasicTest);
	virtual bool init();
	Ref* gridpageviewDataSource(Ref* pConvertCell, unsigned int idx);
};

//////////////////////////////////////////////////////

class CGridPageViewBackPackTest : public CGridPageViewTestSceneBase
{
public:
	CREATE_FUNC(CGridPageViewBackPackTest);
	virtual bool init();
	Ref* gridpageviewDataSource(Ref* pConvertCell, unsigned int idx);
	std::vector<std::string> m_vData;
	CGridPageView* pTable;

public:
	CToggleView* m_pToggleImage;
	Sprite* m_pSelectedSprite;
	bool onItemLongClick(Ref* pSender, Touch* pTouch);
	void onLayoutTouchMovedAfterLongClick(Ref* pSender, Touch* pTouch, float fDuration);
	void onLayoutTouchEndedAfterLongClick(Ref* pSender, Touch* pTouch, float fDuration);
};

//////////////////////////////////////////////////////

static int CGridPageView_test_idx = 0;

static Scene* getCGridPageViewTestScene()
{
	CCLOG("get %d", CGridPageView_test_idx);

	switch(CGridPageView_test_idx)
	{
	case 0:
		return CGridPageViewBasicTest::create();
	case 1:
		return CGridPageViewBackPackTest::create();
	default:
		CGridPageView_test_idx = 0;
		return CGridPageViewBasicTest::create();
	}
	return NULL;
} 

static Scene* pushCGridPageViewTestScene()
{
	CGridPageView_test_idx = 0;

	CCLOG("push %d", CGridPageView_test_idx);
	Scene* pScene = getCGridPageViewTestScene();
	Director::getInstance()->pushScene(pScene);
	return pScene;
}

static void nextCGridPageViewTestScene()
{
	CGridPageView_test_idx++;
	CCLOG("next is %d", CGridPageView_test_idx);
	Scene* pScene = getCGridPageViewTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void backCGridPageViewTestScene()
{
	CGridPageView_test_idx--;
	Scene* pScene = getCGridPageViewTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void refCGridPageViewTestScene()
{
	Scene* pScene = getCGridPageViewTestScene();
	Director::getInstance()->replaceScene(pScene);
}

#endif //__CGridPageViewGRIDTEST_H__