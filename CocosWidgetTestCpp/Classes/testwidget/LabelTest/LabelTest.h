#ifndef __CLabelTEST_H__
#define __CLabelTEST_H__

#include "../../MenuScene.h"

//////////////////////////////////////////////////////

class CLabelTestSceneBase : public BaseTestScene
{
public:
	virtual void onNextBtnClick(Ref* pSender);
	virtual void onBackBtnClick(Ref* pSender);
	virtual void onRefBtnClick(Ref* pSender);
};

//////////////////////////////////////////////////////

class CLabelBasicTest : public CLabelTestSceneBase
{
public:
	CREATE_FUNC(CLabelBasicTest);
	virtual bool init();
	CWidgetTouchModel onTouchBegan(Ref* pSender, Touch* pTouch);
	bool onTouchMoved(Ref* pSender, Touch* pTouch, float fDuration);
	bool onTouchEnded(Ref* pSender, Touch* pTouch, float fDuration);
	void onClick(Ref* pSender);
	bool onLongClick(Ref* pSender, Touch* pTouch);
	CLabel* pText3;
};

//////////////////////////////////////////////////////

class CLabelAtlasTest : public CLabelTestSceneBase
{
public:
	CREATE_FUNC(CLabelAtlasTest);
	virtual bool init();
	CWidgetTouchModel onTouchBegan(Ref* pSender, Touch* pTouch);
	bool onTouchEnded(Ref* pSender, Touch* pTouch, float fDuration);
};

//////////////////////////////////////////////////////

class CLabelBMFontTest : public CLabelTestSceneBase
{
public:
	CREATE_FUNC(CLabelBMFontTest);
	virtual bool init();
};

//////////////////////////////////////////////////////

static int CLabel_test_idx;

static Scene* getCLabelTestScene()
{
	switch(CLabel_test_idx)
	{
	case 0:
		return CLabelBasicTest::create();
	case 1:
		return CLabelAtlasTest::create();
	case 2:
		return CLabelBMFontTest::create();
	default:
		CLabel_test_idx = 0;
		return CLabelBasicTest::create();
	}
	return NULL;
} 

static Scene* pushCLabelTestScene()
{
	CLabel_test_idx = 0;
	Scene* pScene = getCLabelTestScene();
	Director::getInstance()->pushScene(pScene);
	return pScene;
}

static void nextCLabelTestScene()
{
	CLabel_test_idx++;
	Scene* pScene = getCLabelTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void backCLabelTestScene()
{
	CLabel_test_idx--;
	Scene* pScene = getCLabelTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void refCLabelTestScene()
{
	Scene* pScene = getCLabelTestScene();
	Director::getInstance()->replaceScene(pScene);
}

#endif //__CLabelTEST_H__