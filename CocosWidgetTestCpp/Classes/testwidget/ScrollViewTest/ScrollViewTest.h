#ifndef __CScrollViewTEST_H__
#define __CScrollViewTEST_H__

#include "../../MenuScene.h"

//////////////////////////////////////////////////////

class CScrollViewTestSceneBase : public BaseTestScene
{
public:
	virtual void onNextBtnClick(Ref* pSender);
	virtual void onBackBtnClick(Ref* pSender);
	virtual void onRefBtnClick(Ref* pSender);
};

//////////////////////////////////////////////////////

class CScrollViewBasicTest : public CScrollViewTestSceneBase
{
public:
	CREATE_FUNC(CScrollViewBasicTest);
	virtual bool init();
};

//////////////////////////////////////////////////////

class CScrollViewEventTest : public CScrollViewTestSceneBase
{
public:
	CREATE_FUNC(CScrollViewEventTest);
	virtual bool init();
	void onScrolling(Ref* pSender);

public:
	CLabel* m_pText1;
};

//////////////////////////////////////////////////////

class CScrollViewHorizontalTest : public CScrollViewTestSceneBase
{
public:
	CREATE_FUNC(CScrollViewHorizontalTest);
	virtual bool init();

};

//////////////////////////////////////////////////////

class CScrollViewVerticalTest : public CScrollViewTestSceneBase
{
public:
	CREATE_FUNC(CScrollViewVerticalTest);
	virtual bool init();
};

//////////////////////////////////////////////////////

class CScrollViewAttributeTest : public CScrollViewTestSceneBase
{
public:
	CREATE_FUNC(CScrollViewAttributeTest);
	virtual bool init();
	void onClick(Ref* pSender);
	CScrollView* pScroll;
};

//////////////////////////////////////////////////////

class CScrollViewAnimationTest : public CScrollViewTestSceneBase
{
public:
	CREATE_FUNC(CScrollViewAnimationTest);
	virtual bool init();
	void onClick(Ref* pSender);
	CScrollView* pScroll;
};

//////////////////////////////////////////////////////

class CScrollViewInsideScrollTest : public CScrollViewTestSceneBase
{
public:
	CREATE_FUNC(CScrollViewInsideScrollTest);
	virtual bool init();
};

//////////////////////////////////////////////////////

static int CScrollView_test_idx;

static Scene* getCScrollViewTestScene()
{
	switch(CScrollView_test_idx)
	{
	case 0:
		return CScrollViewBasicTest::create();
	case 1:
		return CScrollViewEventTest::create();
	case 2:
		return CScrollViewHorizontalTest::create();
	case 3:
		return CScrollViewVerticalTest::create();
	case 4:
		return CScrollViewAttributeTest::create();
	case 5:
		return CScrollViewAnimationTest::create();
	case 6:
		return CScrollViewInsideScrollTest::create();
	default:
		CScrollView_test_idx = 0;
		return CScrollViewBasicTest::create();
	}
	return NULL;
} 

static Scene* pushCScrollViewTestScene()
{
	CScrollView_test_idx = 0;
	Scene* pScene = getCScrollViewTestScene();
	Director::getInstance()->pushScene(pScene);
	return pScene;
}

static void nextCScrollViewTestScene()
{
	CScrollView_test_idx++;
	Scene* pScene = getCScrollViewTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void backCScrollViewTestScene()
{
	CScrollView_test_idx--;
	Scene* pScene = getCScrollViewTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void refCScrollViewTestScene()
{
	Scene* pScene = getCScrollViewTestScene();
	Director::getInstance()->replaceScene(pScene);
}

#endif //__CScrollViewTEST_H__