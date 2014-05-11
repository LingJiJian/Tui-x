#ifndef __CGridViewTEST_H__
#define __CGridViewTEST_H__

#include "../../MenuScene.h"
#include <vector>
#include <list>

//////////////////////////////////////////////////////

class CGridViewTestSceneBase : public BaseTestScene
{
public:
	virtual void onNextBtnClick(Ref* pSender);
	virtual void onBackBtnClick(Ref* pSender);
	virtual void onRefBtnClick(Ref* pSender);
};

//////////////////////////////////////////////////////

class CGridViewBasicTest : public CGridViewTestSceneBase
{
public:
	CREATE_FUNC(CGridViewBasicTest);
	virtual bool init();
	Ref* gridviewDataSource(Ref* pConvertView, unsigned int idx);
};

//////////////////////////////////////////////////////

static int CGridView_test_idx;

static Scene* getCGridViewTestScene()
{
	switch(CGridView_test_idx)
	{
	case 0:
		return CGridViewBasicTest::create();
	default:
		CGridView_test_idx = 0;
		return CGridViewBasicTest::create();
	}
	return NULL;
} 

static Scene* pushCGridViewTestScene()
{
	CGridView_test_idx = 0;
	Scene* pScene = getCGridViewTestScene();
	Director::getInstance()->pushScene(pScene);
	return pScene;
}

static void nextCGridViewTestScene()
{
	CGridView_test_idx++;
	Scene* pScene = getCGridViewTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void backCGridViewTestScene()
{
	CGridView_test_idx--;
	Scene* pScene = getCGridViewTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void refCGridViewTestScene()
{
	Scene* pScene = getCGridViewTestScene();
	Director::getInstance()->replaceScene(pScene);
}

#endif //__CGridViewTEST_H__