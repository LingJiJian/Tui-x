#ifndef __CListViewTEST_H__
#define __CListViewTEST_H__

#include "../../MenuScene.h"

//////////////////////////////////////////////////////

class CListViewTestSceneBase : public BaseTestScene
{
public:
	virtual void onNextBtnClick(Ref* pSender);
	virtual void onBackBtnClick(Ref* pSender);
	virtual void onRefBtnClick(Ref* pSender);
};

//////////////////////////////////////////////////////

class CListViewBasicTest : public CListViewTestSceneBase
{
public:
	struct tagItem
	{
		Size tSize;
		Color3B tColor;
	};
public:
	CREATE_FUNC(CListViewBasicTest);
	virtual bool init();
	CListView* m_pListView;
	list<tagItem> m_lDatas;
	void onClick(Ref* pSender);
};

//////////////////////////////////////////////////////

class CListViewOperateTest : public CListViewTestSceneBase
{
public:
	CREATE_FUNC(CListViewOperateTest);
	virtual bool init();
	CListView* m_pListView;
	void onClick(Ref* pSender);
};

//////////////////////////////////////////////////////

static int CListView_test_idx;

static Scene* getCListViewTestScene()
{
	switch(CListView_test_idx)
	{
	case 0:
		return CListViewBasicTest::create();
	case 1:
		return CListViewOperateTest::create();
	default:
		CListView_test_idx = 0;
		return CListViewBasicTest::create();
	}
	return NULL;
} 

static Scene* pushCListViewTestScene()
{
	CListView_test_idx = 0;
	Scene* pScene = getCListViewTestScene();
	Director::getInstance()->pushScene(pScene);
	return pScene;
}

static void nextCListViewTestScene()
{
	CListView_test_idx++;
	Scene* pScene = getCListViewTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void backCListViewTestScene()
{
	CListView_test_idx--;
	Scene* pScene = getCListViewTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void refCListViewTestScene()
{
	Scene* pScene = getCListViewTestScene();
	Director::getInstance()->replaceScene(pScene);
}

#endif //__CListViewTEST_H__