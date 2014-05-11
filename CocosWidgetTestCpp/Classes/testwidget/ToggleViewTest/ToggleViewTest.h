#ifndef __CToggleViewTEST_H__
#define __CToggleViewTEST_H__

#include "../../MenuScene.h"

//////////////////////////////////////////////////////

class CToggleViewTestSceneBase : public BaseTestScene
{
public:
	virtual void onNextBtnClick(Ref* pSender);
	virtual void onBackBtnClick(Ref* pSender);
	virtual void onRefBtnClick(Ref* pSender);
};

//////////////////////////////////////////////////////

class CToggleViewBasicTest : public CToggleViewTestSceneBase
{
public:
	CREATE_FUNC(CToggleViewBasicTest);
	virtual bool init();
	void onClick(Ref* pSender);
	CLabel* m_pText;
};

//////////////////////////////////////////////////////

class CToggleViewGroupTest : public CToggleViewTestSceneBase
{
public:
	CREATE_FUNC(CToggleViewGroupTest);
	virtual bool init();
	void onCheck(Ref* pSender, bool bChecked);
};

//////////////////////////////////////////////////////

static int CToggleView_test_idx;

static Scene* getCToggleViewTestScene()
{
	switch(CToggleView_test_idx)
	{
	case 0:
		return CToggleViewBasicTest::create();
	case 1:
		return CToggleViewGroupTest::create();
	default:
		CToggleView_test_idx = 0;
		return CToggleViewBasicTest::create();
	}
	return NULL;
} 

static Scene* pushCToggleViewTestScene()
{
	CToggleView_test_idx = 0;
	Scene* pScene = getCToggleViewTestScene();
	Director::getInstance()->pushScene(pScene);
	return pScene;
}

static void nextCToggleViewTestScene()
{
	CToggleView_test_idx++;
	Scene* pScene = getCToggleViewTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void backCToggleViewTestScene()
{
	CToggleView_test_idx--;
	Scene* pScene = getCToggleViewTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void refCToggleViewTestScene()
{
	Scene* pScene = getCToggleViewTestScene();
	Director::getInstance()->replaceScene(pScene);
}

#endif //__CToggleViewTEST_H__