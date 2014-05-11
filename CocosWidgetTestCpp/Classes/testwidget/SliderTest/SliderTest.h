#ifndef __CSliderTEST_H__
#define __CSliderTEST_H__

#include "../../MenuScene.h"

//////////////////////////////////////////////////////

class CSliderTestSceneBase : public BaseTestScene
{
public:
	virtual void onNextBtnClick(Ref* pSender);
	virtual void onBackBtnClick(Ref* pSender);
	virtual void onRefBtnClick(Ref* pSender);
};

//////////////////////////////////////////////////////

class CSliderBasicTest : public CSliderTestSceneBase
{
public:
	CREATE_FUNC(CSliderBasicTest);
	virtual bool init();
	CLabel* m_pText;
	CSlider* m_pSlider;
	void onValueChanged(Ref* pSender, int nValue);
};

//////////////////////////////////////////////////////

class CSliderWithScrollTest : public CSliderTestSceneBase
{
public:
	CREATE_FUNC(CSliderWithScrollTest);
	virtual bool init();
	CScrollView* m_pScrollView;
	CSlider* m_pSlider;

	void onValueChanged(Ref* pSender, int nValue);
};


//////////////////////////////////////////////////////

static int CSlider_test_idx;

static Scene* getCSliderTestScene()
{
	switch(CSlider_test_idx)
	{
	case 0:
		return CSliderBasicTest::create();
	case 1:
		return CSliderWithScrollTest::create();
	default:
		CSlider_test_idx = 0;
		return CSliderBasicTest::create();
	}
	return NULL;
} 

static Scene* pushCSliderTestScene()
{
	CSlider_test_idx = 0;
	Scene* pScene = getCSliderTestScene();
	Director::getInstance()->pushScene(pScene);
	return pScene;
}

static void nextCSliderTestScene()
{
	CSlider_test_idx++;
	Scene* pScene = getCSliderTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void backCSliderTestScene()
{
	CSlider_test_idx--;
	Scene* pScene = getCSliderTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void refCSliderTestScene()
{
	Scene* pScene = getCSliderTestScene();
	Director::getInstance()->replaceScene(pScene);
}

#endif //__CSliderTEST_H__