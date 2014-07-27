#ifndef __CTableViewTEST_H__
#define __CTableViewTEST_H__

#include "../../MenuScene.h"
#include <vector>
#include <list>

//////////////////////////////////////////////////////

class CTableViewTestSceneBase : public BaseTestScene
{
public:
	virtual void onNextBtnClick(Ref* pSender);
	virtual void onBackBtnClick(Ref* pSender);
	virtual void onRefBtnClick(Ref* pSender);
};

//////////////////////////////////////////////////////

class CTableViewBasicTest : public CTableViewTestSceneBase
{
public:
	CREATE_FUNC(CTableViewBasicTest);
	virtual bool init();
	Ref* tableviewDataSource(Ref* pConvertView, unsigned int idx);
};

//////////////////////////////////////////////////////

class CTableViewBindingDataAndVertical : public CTableViewTestSceneBase
{
public:
	CREATE_FUNC(CTableViewBindingDataAndVertical);
	virtual bool init();
	Ref* tableviewDataSource(Ref* pConvertView, unsigned int idx);
	std::vector<std::string> m_vDatas;
	void onClick(Ref* pSender);
	CLabel* pText;
};

//////////////////////////////////////////////////////

class CTableViewReloadTest : public CTableViewTestSceneBase
{
public:
	CREATE_FUNC(CTableViewReloadTest);
	virtual bool init();
	Ref* tableviewDataSource(Ref* pConvertView, unsigned int idx);
	void onClick(Ref* pSender);
	std::list<string> m_lDataQueue;
	std::vector<string> m_vDatas;
	CTableView* pTable;
};

//////////////////////////////////////////////////////

static int CTableView_test_idx;

static Scene* getCTableViewTestScene()
{
	switch(CTableView_test_idx)
	{
	case 0:
		return CTableViewBasicTest::create();
	case 1:
		return CTableViewBindingDataAndVertical::create();
	case 2:
		return CTableViewReloadTest::create();
	default:
		CTableView_test_idx = 0;
		return CTableViewBasicTest::create();
	}
	return NULL;
} 

static Scene* pushCTableViewTestScene()
{
	CTableView_test_idx = 0;
	Scene* pScene = getCTableViewTestScene();
	Director::getInstance()->pushScene(pScene);
	return pScene;
}

static void nextCTableViewTestScene()
{
	CTableView_test_idx++;
	Scene* pScene = getCTableViewTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void backCTableViewTestScene()
{
	CTableView_test_idx--;
	Scene* pScene = getCTableViewTestScene();
	Director::getInstance()->replaceScene(pScene);
}

static void refCTableViewTestScene()
{
	Scene* pScene = getCTableViewTestScene();
	Director::getInstance()->replaceScene(pScene);
}

#endif //__CTableViewTEST_H__