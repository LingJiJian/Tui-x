#ifndef __CPageViewTEST_H__
#define __CPageViewTEST_H__

#include "../../MenuScene.h"

//////////////////////////////////////////////////////

class CPageViewTestSceneBase : public BaseTestScene
{
public:
	virtual void onNextBtnClick(Ref* pSender);
	virtual void onBackBtnClick(Ref* pSender);
	virtual void onRefBtnClick(Ref* pSender);
};

//////////////////////////////////////////////////////

class CPageViewBasicTest : public CPageViewTestSceneBase
{
public:
	CREATE_FUNC(CPageViewBasicTest);
	virtual bool init();
	CLabel* m_pText;
	Ref* pageviewDataSource(Ref* pConvertCell, unsigned int nPageIdx);
	void onPageChanged(CPageView* pPage, unsigned int nPageIndx);
};

//////////////////////////////////////////////////////

class CPageViewVerticalTest : public CPageViewTestSceneBase
{
public:
	CREATE_FUNC(CPageViewVerticalTest);
	virtual bool init();
	CLabel* m_pText;
	Ref* pageviewDataSource(Ref* pConvertCell, unsigned int nPageIdx);
	void onPageChanged(CPageView* pPage, unsigned int nPageIndx);
};

//////////////////////////////////////////////////////

static int CPageView_test_idx;

static Scene* getCPageViewTestScene()
{
	switch(CPageView_test_idx)
	{
	case 0:
		return CPageViewBasicTest::create();
	case 1:
		return CPageViewVerticalTest::create();
	default:
		CPageView_test_idx = 0;
		return CPageViewBasicTest::create();
	}
	return NULL;
} 

static Scene* pushCPageViewTestScene()
{
	CPageView_test_idx = 0;
	Scene* pScene = getCPageViewTestScene();
	Director::getInstance()->pushScene(pScene);
	return pScene;
}

static void nextCPageViewTestScene()
{
	CPageView_test_idx++;
	Scene* pScene = getCPageViewTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void backCPageViewTestScene()
{
	CPageView_test_idx--;
	Scene* pScene = getCPageViewTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void refCPageViewTestScene()
{
	Scene* pScene = getCPageViewTestScene();
	Director::getInstance()->replaceScene(pScene);
}

#endif //__CPageViewTEST_H__