#ifndef __CControlViewTEST_H__
#define __CControlViewTEST_H__

#include "../../MenuScene.h"

//////////////////////////////////////////////////////

class CControlViewTestSceneBase : public BaseTestScene
{
public:
	virtual void onNextBtnClick(Ref* pSender);
	virtual void onBackBtnClick(Ref* pSender);
	virtual void onRefBtnClick(Ref* pSender);
};

//////////////////////////////////////////////////////

class CControlViewBasicTest : public CControlViewTestSceneBase
{
public:
	CREATE_FUNC(CControlViewBasicTest);
	virtual bool init();
	void onTouched(Ref* pSender, float fx, float fy);
	Sprite* m_pIcon;
};

//////////////////////////////////////////////////////

static int CControlView_test_idx;

static Scene* getCControlViewTestScene()
{
	switch(CControlView_test_idx)
	{
	case 0:
		return CControlViewBasicTest::create();
	default:
		CControlView_test_idx = 0;
		return CControlViewBasicTest::create();
	}
	return NULL;
} 

static Scene* pushCControlViewTestScene()
{
	CControlView_test_idx = 0;
	Scene* pScene = getCControlViewTestScene();
	Director::getInstance()->pushScene(pScene);
	return pScene;
}

static void nextCControlViewTestScene()
{
	CControlView_test_idx++;
	Scene* pScene = getCControlViewTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void backCControlViewTestScene()
{
	CControlView_test_idx--;
	Scene* pScene = getCControlViewTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void refCControlViewTestScene()
{
	Scene* pScene = getCControlViewTestScene();
	Director::getInstance()->replaceScene(pScene);
}

#endif //__CControlViewTEST_H__