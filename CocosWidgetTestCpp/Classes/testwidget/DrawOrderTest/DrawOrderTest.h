#ifndef __DrawOrderTEST_H__
#define __DrawOrderTEST_H__

#include "../../MenuScene.h"

//////////////////////////////////////////////////////

class DrawOrderTestSceneBase : public BaseTestScene
{
public:
	virtual void onNextBtnClick(Ref* pSender);
	virtual void onBackBtnClick(Ref* pSender);
	virtual void onRefBtnClick(Ref* pSender);
};

//////////////////////////////////////////////////////

class DrawOrderBasicTest : public DrawOrderTestSceneBase
{
public:
	CREATE_FUNC(DrawOrderBasicTest);
	virtual bool init();
	void onClick(Ref* pSender);
	CButton* pButton1;
	CButton* pButton2;
};

//////////////////////////////////////////////////////

static int DrawOrder_test_idx;

static Scene* getDrawOrderTestScene()
{
	switch(DrawOrder_test_idx)
	{
	case 0:
		return DrawOrderBasicTest::create();
	default:
		DrawOrder_test_idx = 0;
		return DrawOrderBasicTest::create();
	}
	return NULL;
} 

static Scene* pushDrawOrderTestScene()
{
	DrawOrder_test_idx = 0;
	Scene* pScene = getDrawOrderTestScene();
	Director::getInstance()->pushScene(pScene);
	return pScene;
}

static void nextDrawOrderTestScene()
{
	DrawOrder_test_idx++;
	Scene* pScene = getDrawOrderTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void backDrawOrderTestScene()
{
	DrawOrder_test_idx--;
	Scene* pScene = getDrawOrderTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void refDrawOrderTestScene()
{
	Scene* pScene = getDrawOrderTestScene();
	Director::getInstance()->replaceScene(pScene);
}

#endif //__DrawOrderTEST_H__