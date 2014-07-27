#ifndef __CLayoutTEST_H__
#define __CLayoutTEST_H__

#include "../../MenuScene.h"

//////////////////////////////////////////////////////

class CLayoutTestSceneBase : public BaseTestScene
{
public:
	virtual void onNextBtnClick(Ref* pSender);
	virtual void onBackBtnClick(Ref* pSender);
	virtual void onRefBtnClick(Ref* pSender);
};

//////////////////////////////////////////////////////

class CLayoutBasicTest : public CLayoutTestSceneBase
{
public:
	CREATE_FUNC(CLayoutBasicTest);
	virtual bool init();
};

//////////////////////////////////////////////////////

class CLayoutColorTest : public CLayoutTestSceneBase
{
public:
	CREATE_FUNC(CLayoutColorTest);
	virtual bool init();
};

//////////////////////////////////////////////////////

class CLayoutGradientTest : public CLayoutTestSceneBase
{
public:
	CREATE_FUNC(CLayoutGradientTest);
	virtual bool init();
};

//////////////////////////////////////////////////////

static int CLayout_test_idx;

static Scene* getCLayoutTestScene()
{
	switch(CLayout_test_idx)
	{
	case 0:
		return CLayoutBasicTest::create();
	case 1:
		return CLayoutColorTest::create();
	case 2:
		return CLayoutGradientTest::create();
	default:
		CLayout_test_idx = 0;
		return CLayoutBasicTest::create();
	}
	return NULL;
} 

static Scene* pushCLayoutTestScene()
{
	CLayout_test_idx = 0;
	Scene* pScene = getCLayoutTestScene();
	Director::getInstance()->pushScene(pScene);
	return pScene;
}

static void nextCLayoutTestScene()
{
	CLayout_test_idx++;
	Scene* pScene = getCLayoutTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void backCLayoutTestScene()
{
	CLayout_test_idx--;
	Scene* pScene = getCLayoutTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void refCLayoutTestScene()
{
	Scene* pScene = getCLayoutTestScene();
	Director::getInstance()->replaceScene(pScene);
}

#endif //__CLayoutTEST_H__