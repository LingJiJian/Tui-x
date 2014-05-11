#ifndef __CCheckBoxTEST_H__
#define __CCheckBoxTEST_H__

#include "../../MenuScene.h"

//////////////////////////////////////////////////////

class CCheckBoxTestSceneBase : public BaseTestScene
{
public:
	virtual void onNextBtnClick(Ref* pSender);
	virtual void onBackBtnClick(Ref* pSender);
	virtual void onRefBtnClick(Ref* pSender);
};

//////////////////////////////////////////////////////

class CCheckBoxBasicTest : public CCheckBoxTestSceneBase
{
public:
	CREATE_FUNC(CCheckBoxBasicTest);
	virtual bool init();
	void onClick(Ref* pSender);
	CLabel* m_pText;
};

//////////////////////////////////////////////////////

class CCheckBoxExclusionTest : public CCheckBoxTestSceneBase
{
public:
	CREATE_FUNC(CCheckBoxExclusionTest);
	virtual bool init();
	void onClick(Ref* pSender);
};

//////////////////////////////////////////////////////

static int CCheckBox_test_idx;

static Scene* getCCheckBoxTestScene()
{
	switch(CCheckBox_test_idx)
	{
	case 0:
		return CCheckBoxBasicTest::create();
	case 1:
		return CCheckBoxExclusionTest::create();
	default:
		CCheckBox_test_idx = 0;
		return CCheckBoxBasicTest::create();
	}
	return NULL;
} 

static Scene* pushCCheckBoxTestScene()
{
	CCheckBox_test_idx = 0;
	Scene* pScene = getCCheckBoxTestScene();
	Director::getInstance()->pushScene(pScene);
	return pScene;
}

static void nextCCheckBoxTestScene()
{
	CCheckBox_test_idx++;
	Scene* pScene = getCCheckBoxTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void backCCheckBoxTestScene()
{
	CCheckBox_test_idx--;
	Scene* pScene = getCCheckBoxTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void refCCheckBoxTestScene()
{
	Scene* pScene = getCCheckBoxTestScene();
	Director::getInstance()->replaceScene(pScene);
}

#endif //__CCheckBoxTEST_H__