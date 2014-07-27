#ifndef __CExpandableListViewTEST_H__
#define __CExpandableListViewTEST_H__

#include "../../MenuScene.h"

//////////////////////////////////////////////////////

class CExpandableListViewTestSceneBase : public BaseTestScene
{
public:
	virtual void onNextBtnClick(Ref* pSender);
	virtual void onBackBtnClick(Ref* pSender);
	virtual void onRefBtnClick(Ref* pSender);
};

//////////////////////////////////////////////////////

class CExpandableListViewBasicTest : public CExpandableListViewTestSceneBase
{
public:
	CREATE_FUNC(CExpandableListViewBasicTest);
	virtual bool init();
	void onClickExpand(Ref* pSender);
	void onClickCollapse(Ref *pSender);
	CExpandableListView* pListView;
};


//////////////////////////////////////////////////////

static int CExpandableListView_test_idx;

static Scene* getCExpandableListViewTestScene()
{
	switch(CExpandableListView_test_idx)
	{
	case 0:
		return CExpandableListViewBasicTest::create();
	default:
		CExpandableListView_test_idx = 0;
		return CExpandableListViewBasicTest::create();
	}
	return NULL;
} 

static Scene* pushCExpandableListViewTestScene()
{
	CExpandableListView_test_idx = 0;
	Scene* pScene = getCExpandableListViewTestScene();
	Director::getInstance()->pushScene(pScene);
	return pScene;
}

static void nextCExpandableListViewTestScene()
{
	CExpandableListView_test_idx++;
	Scene* pScene = getCExpandableListViewTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void backCExpandableListViewTestScene()
{
	CExpandableListView_test_idx--;
	Scene* pScene = getCExpandableListViewTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void refCExpandableListViewTestScene()
{
	Scene* pScene = getCExpandableListViewTestScene();
	Director::getInstance()->replaceScene(pScene);
}

#endif //__CExpandableListViewTEST_H__