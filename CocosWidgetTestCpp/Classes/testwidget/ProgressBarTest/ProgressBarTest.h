#ifndef __CProgressBarTEST_H__
#define __CProgressBarTEST_H__

#include "../../MenuScene.h"

//////////////////////////////////////////////////////

class CProgressBarTestSceneBase : public BaseTestScene
{
public:
	virtual void onNextBtnClick(Ref* pSender);
	virtual void onBackBtnClick(Ref* pSender);
	virtual void onRefBtnClick(Ref* pSender);
};

//////////////////////////////////////////////////////

class CProgressBarBasicTest : public CProgressBarTestSceneBase
{
public:
	CREATE_FUNC(CProgressBarBasicTest);
	virtual bool init();
	void onClick(Ref* pSender);
	CProgressBar* m_pProgressBar;
	CLabel* m_pText;
	void onProgressing(Ref* pSender, int nValue);
};

//////////////////////////////////////////////////////

static int CProgressBar_test_idx;

static Scene* getCProgressBarTestScene()
{
	switch(CProgressBar_test_idx)
	{
	case 0:
		return CProgressBarBasicTest::create();
	default:
		CProgressBar_test_idx = 0;
		return CProgressBarBasicTest::create();
	}
	return NULL;
} 

static Scene* pushCProgressBarTestScene()
{
	CProgressBar_test_idx = 0;
	Scene* pScene = getCProgressBarTestScene();
	Director::getInstance()->pushScene(pScene);
	return pScene;
}

static void nextCProgressBarTestScene()
{
	CProgressBar_test_idx++;
	Scene* pScene = getCProgressBarTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void backCProgressBarTestScene()
{
	CProgressBar_test_idx--;
	Scene* pScene = getCProgressBarTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void refCProgressBarTestScene()
{
	Scene* pScene = getCProgressBarTestScene();
	Director::getInstance()->replaceScene(pScene);
}

#endif //__CProgressBarTEST_H__