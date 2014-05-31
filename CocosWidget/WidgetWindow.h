/****************************************************************************
Copyright (c) 2014 Lijunlin - Jason lee

Created by Lijunlin - Jason lee on 2014

jason.lee.c@foxmail.com
http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#ifndef __CCWIDGET_WIDGETWINDOW_H__
#define __CCWIDGET_WIDGETWINDOW_H__

#include "cocos2d.h"
#include "WidgetMacros.h"
#include "Widget.h"
#include "WidgetProtocol.h"
#include <map>

NS_CC_WIDGET_BEGIN

/**
 * class  : CWidgetWindow
 * author : Jason lee
 * email  : jason.lee.c@foxmail.com
 * descpt : widget window define
 */
class CWidgetWindow : public Node
{
public:
	CWidgetWindow();
	virtual ~CWidgetWindow();

	// init default
	virtual bool init();

	// create and init default
	static CWidgetWindow* create();

	// get touch priority
	virtual int getTouchPriority();

	// set touch priority from widget tree root
	virtual void setTouchPriority(int nTouchPriority);

	// is touch enabled
	virtual bool isTouchEnabled();

	// set touch enabled, if false it is not going to handle event
	virtual void setTouchEnabled(bool bTouchEnabled);
	
	// find a first matching widget in widget tree
	Node* findWidgetById(const char* id);

	// is multi touch enabled
	bool isMultiTouchEnabled() const;

	// set multi touch enabeld
	void setMultiTouchEnabled(bool bEnabled);

	// set modalable for window
	void setModalable(bool bModalable);

	// is modalable
	bool isModalable() const;

	// moved after long click
	virtual void setOnTouchMovedAfterLongClickListener(Ref* pListener, SEL_AfterLongClickHandler pHandler);

	// ended after long click
	virtual void setOnTouchEndedAfterLongClickListener(Ref* pListener, SEL_AfterLongClickHandler pHandler);

	// cancelled after long click
	virtual void setOnTouchCancelledAfterLongClickListener(Ref* pListener, SEL_AfterLongClickHandler pHandler);

public:
	virtual void visit(Renderer *renderer, const kmMat4& parentTransform, bool parentTransformUpdated);
	virtual void onEnter();
	virtual void onExit();

	virtual bool onTouchBegan(Touch *touch, Event *unused_event); 
	virtual void onTouchMoved(Touch *touch, Event *unused_event); 
	virtual void onTouchEnded(Touch *touch, Event *unused_event); 
	virtual void onTouchCancelled(Touch *touch, Event *unused_event);

	virtual void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event);
	virtual void onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event);
	virtual void onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event);
	virtual void onTouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event);

	virtual void setLongClickTouchHandlerWidget(Ref* pWidgetObject, int nTouchId);

	Node* find(Vector<Node*> &pChidren, const char* id);

	virtual void executeTouchMovedAfterLongClickHandler(Ref* pSender, Touch* pTouch, float fDuration);
    virtual void executeTouchEndedAfterLongClickHandler(Ref* pSender, Touch* pTouch, float fDuration);
    virtual void executeTouchCancelledAfterLongClickHandler(Ref* pSender, Touch* pTouch, float fDuration);

protected:
	struct __ccMULTITOUCHTARGET
	{
		CWidget* pWidget;
		Ref* pLongClickedWidgetObject;
		float fTouchedDuration;
	};
	std::map<int, __ccMULTITOUCHTARGET> m_mMultiTouchKeeper;

protected:
	int m_nTouchPriority;
	bool m_bTouchEnabled;
	float m_fTouchedDuration;
	bool m_bIsTouched;
	bool m_bMultiTouchEnabled;
	bool m_bModalable;

	Ref* m_pLongClickedWidgetObject;
	CWidget* m_pSelectedWidget;

	EventListener* m_pEventLister;

    Ref* m_pTouchMovedAfterLongClickListener;
    Ref* m_pTouchEndedAfterLongClickListener;
    Ref* m_pTouchCancelledAfterLongClickListener;

    SEL_AfterLongClickHandler m_pTouchMovedAfterLongClickHandler;
    SEL_AfterLongClickHandler m_pTouchEndedAfterLongClickHandler;
    SEL_AfterLongClickHandler m_pTouchCancelledAfterLongClickHandler;

#if USING_LUA
protected:
	int m_nTouchMovedAfterLongClickScriptHandler;
	int m_nTouchEndedAfterLongClickScriptHandler;
	int m_pTouchCancelledAfterLongClickScriptHandler;
public:
	void setOnTouchMovedAfterLongClickScriptHandler(int nHandler);
	void setOnTouchEndedAfterLongClickScriptHandler(int nHandler);
	void setOnTouchCancelledAfterLongClickScriptHandler(int nHandler);
	void removeOnTouchMovedAfterLongClickScriptHandler();
	void removeOnTouchEndedAfterLongClickScriptHandler();
	void removeOnTouchCancelledAfterLongClickScriptHandler();
#endif

};

NS_CC_WIDGET_END

#endif //__CCWIDGET_WIDGETWINDOW_H__