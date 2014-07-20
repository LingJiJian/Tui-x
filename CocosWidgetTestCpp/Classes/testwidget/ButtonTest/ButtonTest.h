#ifndef __CButtonTEST_H__
#define __CButtonTEST_H__

#include "../../MenuScene.h"
#include <string>
#include <list>

//////////////////////////////////////////////////////

class CButtonTestSceneBase : public BaseTestScene
{
public:
	virtual void onNextBtnClick(Ref* pSender);
	virtual void onBackBtnClick(Ref* pSender);
	virtual void onRefBtnClick(Ref* pSender);
};

//////////////////////////////////////////////////////

class CButtonBasicTest : public CButtonTestSceneBase
{
public:
	virtual bool init();
	CREATE_FUNC(CButtonBasicTest);
	void event_armbtn_test(Ref *pSender);
	void event_numStep_test(Ref *pSender,int value);
};

//////////////////////////////////////////////////////

class CButtonEventTest : public CButtonTestSceneBase
{
public:
	virtual bool init();
	CREATE_FUNC(CButtonEventTest);
	void onClick(Ref* pSender);
	CWidgetTouchModel onTouchBegan(Ref* pSender, Touch* pTouch);
	bool onTouchMoved(Ref* pSender, Touch* pTouch, float fDuration);
	bool onTouchEnded(Ref* pSender, Touch* pTouch, float fDuration);
	bool onTouchCancelled(Ref* pSender, Touch* pTouch, float fDuration);

private:
	CLabel* m_pText1;
	CLabel* m_pText2;
	CLabel* m_pDurationText;
	void setDuration(float fDuration);
};


////////////////////////////////////////////////////////

class CButtonLongClickTest : public CButtonTestSceneBase
{
public:
	virtual bool init();
	CREATE_FUNC(CButtonLongClickTest);
	void onClick(Ref* pSender);
	bool onButton1LongClick(Ref* pSender, Touch* pTouch);
	bool onButton2LongClick(Ref* pSender, Touch* pTouch);

	void onLayoutTouchMovedAfterLongClick(Ref* pSender, Touch* pTouch, float fDuration);

private:
	CButton* pButton2;
	CLabel* m_pText1;
	CLabel* m_pText2;
};

////////////////////////////////////////////////////////

class CButtonWithTextTest : public CButtonTestSceneBase
{
public:
	virtual bool init();
	CREATE_FUNC(CButtonWithTextTest);
};

////////////////////////////////////////////////////////

class CButtonAttributeTest : public CButtonTestSceneBase
{
public:
	virtual bool init();
	CREATE_FUNC(CButtonAttributeTest);
};

////////////////////////////////////////////////////////

class CButton9SpriteTest : public CButtonTestSceneBase
{
public:
	virtual bool init();
	CREATE_FUNC(CButton9SpriteTest);
};

////////////////////////////////////////////////////////

class CButtonChangeSizeTest : public CButtonTestSceneBase
{
public:
	virtual bool init();
	CREATE_FUNC(CButtonChangeSizeTest);
	void onClick(Ref* pSender);
	std::list<std::string> m_lData;
	CButton* m_pButton;
};

////////////////////////////////////////////////////////

static int CButton_test_idx;

static Scene* getCButtonTestScene()
{
	switch(CButton_test_idx)
	{
	case 0:
		return CButtonBasicTest::create();
	case 1:
		return CButtonEventTest::create();
	case 2:
		return CButtonLongClickTest::create();
	case 3:
		return CButtonWithTextTest::create();
	case 4:
		return CButtonAttributeTest::create();
	case 5:
		return CButton9SpriteTest::create();
	case 6:
		return CButtonChangeSizeTest::create();
	default:
		CButton_test_idx = 0;
		return CButtonBasicTest::create();
	}
	return NULL;
} 

static Scene* pushCButtonTestScene()
{
	CButton_test_idx = 0;
	Scene* pScene = getCButtonTestScene();
	Director::getInstance()->pushScene(pScene);
	return pScene;
}

static void nextCButtonTestScene()
{
	CButton_test_idx++;
	Scene* pScene = getCButtonTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void backCButtonTestScene()
{
	CButton_test_idx--;
	Scene* pScene = getCButtonTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void refCButtonTestScene()
{
	Scene* pScene = getCButtonTestScene();
	Director::getInstance()->replaceScene(pScene);
}

#endif //__CButtonTEST_H__