#ifndef __CTextRichTEST_H__
#define __CTextRichTEST_H__

#include "../../MenuScene.h"

//////////////////////////////////////////////////////

class CTextRichTestSceneBase : public BaseTestScene
{
public:
	virtual void onNextBtnClick(Ref* pSender);
	virtual void onBackBtnClick(Ref* pSender);
	virtual void onRefBtnClick(Ref* pSender);
};

//////////////////////////////////////////////////////

class CTextRichBasicTest : public CTextRichTestSceneBase
{
public:
	CREATE_FUNC(CTextRichBasicTest);
	virtual bool init();
};

//////////////////////////////////////////////////////

class CTextRichEventTest : public CTextRichTestSceneBase
{
public:
	CREATE_FUNC(CTextRichEventTest);
	virtual bool init();
	void onClickTextRich(Ref* pSender, const char* pDescription);
	CLabel* m_pLabel;
};


//////////////////////////////////////////////////////

static int CTextRich_test_idx;

static Scene* getCTextRichTestScene()
{
	switch(CTextRich_test_idx)
	{
	case 0:
		return CTextRichBasicTest::create();
	case 1:
		return CTextRichEventTest::create();
	default:
		CTextRich_test_idx = 0;
		return CTextRichBasicTest::create();
	}
	return NULL;
} 

static Scene* pushCTextRichTestScene()
{
	CTextRich_test_idx = 0;
	Scene* pScene = getCTextRichTestScene();
	Director::getInstance()->pushScene(pScene);
	return pScene;
}

static void nextCTextRichTestScene()
{
	CTextRich_test_idx++;
	Scene* pScene = getCTextRichTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void backCTextRichTestScene()
{
	CTextRich_test_idx--;
	Scene* pScene = getCTextRichTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void refCTextRichTestScene()
{
	Scene* pScene = getCTextRichTestScene();
	Director::getInstance()->replaceScene(pScene);
}

#endif //__CTextRichTEST_H__