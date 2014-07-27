#ifndef __MENUSCENE_H__
#define __MENUSCENE_H__

#include "cocos2d.h"
#include "../../CocosWidget/cocos-widget.h"
using namespace cocos2d;
using namespace cocos2d::cocoswidget;
#include <vector>
using namespace std;

class MenuScene : public Scene
{
public:
	CREATE_FUNC(MenuScene);
	MenuScene();
	virtual ~MenuScene();
	virtual bool init();

private:
	CTableView* m_pMenuTableView;
	Ref* menuTableDataSource(Ref* pConvertCell, unsigned int idx);
	CWidgetTouchModel onTextTouchDown(Ref* pSender, Touch* pTouch);
	bool onTextTouchEnd(Ref* pSender, Touch* pTouch, float fDuration);
	bool onTextTouchCancelled(Ref* pSender, Touch* pTouch, float fDuration);
	void onTextClick(Ref* pSender);

private:
	std::vector<string> m_vMenuItems;
};

class BaseTestScene : public Scene
{
public:
	BaseTestScene();
	CREATE_FUNC(BaseTestScene);
	virtual bool init();

protected:
	CWidgetWindow* m_pWindow;
	CButton* m_pNextBtn;
	CButton* m_pBackBtn;
	CButton* m_pRefBtn;
	CLabel* m_pTitleText;
	CLabel* m_pDescriptionText;
	CLabel* m_pMenuText;

protected:
	virtual void setDescription(const char* str);
	virtual void setTitle(const char* str);
	virtual void onNextBtnClick(Ref* pSender){};
	virtual void onBackBtnClick(Ref* pSender){};
	virtual void onRefBtnClick(Ref* pSender){};
	virtual void onMenuBtnClick(Ref* pSender);
};


#endif //__MENUSCENE_H__