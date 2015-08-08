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
#ifndef __CCWIDGET_WIDGETPROTOCOL_H__
#define __CCWIDGET_WIDGETPROTOCOL_H__

#include "cocos2d.h"
#include "WidgetMacros.h"

#define CC_WIDGET_LONGPRESS_TIME 0.5f
#define CC_WIDGET_NONE_EXCLUSION -1

NS_CC_WIDGET_BEGIN

class CWidget;

static const Vec2 CCWIDGET_BASIC_DEFAULT_ANCHOR_POINT = Vec2(0.5f, 0.5f);
static const Size CCWIDGET_BASIC_DEFAULT_CONTENT_SIZE = Size(100, 100);

static const Vec2 CCWIDGET_LAYOUT_DEFAULT_ANCHOR_POINT = Vec2(0.5f, 0.5f);
static const Size CCWIDGET_LAYOUT_DEFAULT_CONTENT_SIZE = Size(300, 300);

/**
 * enum   : CWidgetTouchModel
 * author : Jason lee
 * email  : jason.lee.c@foxmail.com
 * descpt : touch model for widget event dispatch
 */
enum CWidgetTouchModel
{
	// no need to handle evnet
	eWidgetTouchNone,
	// need to handle a while, the parent layout can interrupt me.
	eWidgetTouchTransient,
	// need handle event forever, interrupt self only
	eWidgetTouchSustained,
};

typedef void (Ref::*SEL_ClickHandler)(Ref *pSender);
typedef bool (Ref::*SEL_LongClickHandler)(Ref* pSender, Touch* pTouch);
typedef void (Ref::*SEL_AfterLongClickHandler)(Ref* pSender, Touch* pTouch, float fDuration);
typedef void (Ref::*SEL_CheckHandler)(Ref *pSender, bool bChecked);
typedef void (Ref::*SEL_ControlHandler)(Ref* pSender, float fx, float fy);
typedef void (Ref::*SEL_ValueChangedHandler)(Ref* pSender, int nValue);
typedef void (Ref::*SEL_ProgressEndedHandler)(Ref* pSender);
typedef void (Ref::*SEL_ScrollingHandler)(Ref* pSender);
typedef void (Ref::*SEL_MoveingHandler)(Ref* pSender);
typedef void (Ref::*SEL_MoveEndHandler)(Ref* pSender);
typedef void (Ref::*SEL_PageChangedHandler)(Ref* pSender, unsigned int nPageIdx);
typedef Ref* (Ref::*SEL_DataSoucreAdapterHandler)(Ref* pConvertCell, unsigned int uIdx);
typedef CWidgetTouchModel (Ref::*SEL_TouchBeganHandler)(Ref* pSender, Touch* pTouch);
typedef bool (Ref::*SEL_TouchEventHandler)(Ref* pSender, Touch* pTouch, float fDuration);
typedef void (Ref::*SEL_TextRichClickHandler)(Ref* pSender, int tag);


#define ccw_click_selector(_SELECTOR_) (cocos2d::cocoswidget::SEL_ClickHandler)(&_SELECTOR_)
#define ccw_longclick_selector(_SELECTOR_) (cocos2d::cocoswidget::SEL_LongClickHandler)(&_SELECTOR_)
#define ccw_afterlongclick_selector(_SELECTOR_) (cocos2d::cocoswidget::SEL_AfterLongClickHandler)(&_SELECTOR_)
#define ccw_check_selector(_SELECTOR_) (cocos2d::cocoswidget::SEL_CheckHandler)(&_SELECTOR_)
#define ccw_control_selector(_SELECTOR_) (cocos2d::cocoswidget::SEL_ControlHandler)(&_SELECTOR_)
#define ccw_valuechanged_selector(_SELECTOR_) (cocos2d::cocoswidget::SEL_ValueChangedHandler)(&_SELECTOR_)
#define ccw_progressended_selector(_SELECTOR_) (cocos2d::cocoswidget::SEL_ProgressEndedHandler)(&_SELECTOR_)
#define ccw_scrolling_selector(_SELECTOR_) (cocos2d::cocoswidget::SEL_ScrollingHandler)(&_SELECTOR_)
#define ccw_pagechanged_selector(_SELECTOR_) (cocos2d::cocoswidget::SEL_PageChangedHandler)(&_SELECTOR_)
#define ccw_datasource_adapter_selector(__SELECTOR__) (cocos2d::cocoswidget::SEL_DataSoucreAdapterHandler)(&__SELECTOR__)
#define ccw_touchbegan_selector(_SELECTOR_) (cocos2d::cocoswidget::SEL_TouchBeganHandler)(&_SELECTOR_)
#define ccw_touchevent_selector(_SELECTOR_) (cocos2d::cocoswidget::SEL_TouchEventHandler)(&_SELECTOR_)
#define ccw_textrichclick_selector(_SELECTOR_) (cocos2d::cocoswidget::SEL_TextRichClickHandler)(&_SELECTOR_)
#define ccw_moveing_selector(_SELECTOR_) (cocos2d::cocoswidget::SEL_MoveingHandler)(&_SELECTOR_)
#define ccw_moveend_selector(_SELECTOR_) (cocos2d::cocoswidget::SEL_MoveEndHandler)(&_SELECTOR_)


class CWidgetTouchProtocol
{
public:
    virtual CWidgetTouchModel onTouchBegan(Touch* pTouch) = 0;
    virtual void onTouchMoved(Touch* pTouch, float fDuration) = 0;
    virtual void onTouchEnded(Touch* pTouch, float fDuration) = 0;
    virtual void onTouchCancelled(Touch* pTouch, float fDuration) = 0;
};

class CDataSourceAdapterProtocol
{
public:
	CDataSourceAdapterProtocol();
	virtual ~CDataSourceAdapterProtocol();
	virtual void setDataSourceAdapter(Ref* pListener, SEL_DataSoucreAdapterHandler pHandler);

protected:
	Ref* m_pDataSourceAdapterListener;
	SEL_DataSoucreAdapterHandler m_pDataSourceAdapterHandler;
	Ref* executeDataSourceAdapterHandler(Ref* pConvertCell, unsigned int uIdx);

#if USING_LUA
protected:
	int m_nDataSourceAdapterScriptHandler;
	Ref* executeDataSourceAdapterScriptHandler(Ref* pConvertCell, unsigned int uIdx);
public:
	virtual void setDataSourceAdapterScriptHandler(int nHandler);
	virtual void removeDataSourceAdapterScriptHandler();
#endif
};

class CTextRichClickableProtocol
{
public:
	CTextRichClickableProtocol();
	virtual ~CTextRichClickableProtocol();
	void setOnTextRichClickListener(Ref* pListener, SEL_TextRichClickHandler pHandler);

protected:
	Ref* m_pRichTextClickListener;
	SEL_TextRichClickHandler m_pRichTextClickHandler;
	void executeTextRichClickHandler(Ref* pSender, int tag);
#if USING_LUA
protected:
	int m_nRichTextClickScriptHandler;
	void executeTextRichScriptHandler(Ref* pSender, int tag);
public:
	virtual void setOnTextRichClickScriptHandler(int nHandler);
	virtual void removeOnTextRichClickScriptHandler();
#endif
};

class CLayoutableProtocol
{
public:
	CLayoutableProtocol();
	virtual ~CLayoutableProtocol();

protected:
	CWidget* m_pSelectedWidget;
    CWidgetTouchModel m_eSelectedWidgetTouchModel;
};

class CPageChangeableProtocol
{
public:
	CPageChangeableProtocol();
	virtual ~CPageChangeableProtocol();
	void setOnPageChangedListener(Ref* pListener, SEL_PageChangedHandler pHandler);

protected:
	unsigned int m_nPageIndex;
	Ref* m_pPageChangedListener;
	SEL_PageChangedHandler m_pPageChangedHandler;
	void executePageChangedHandler(Ref* pSender, unsigned int uPageIdx);
#if USING_LUA
protected:
	int m_nPageChangedScriptHandler;
	void executePageChangedScriptHandler(Ref* pSender, unsigned int uPageIdx);
public:
	virtual void setOnPageChangedScriptHandler(int nHandler);
	virtual void removeOnPageChangedScriptHandler();
#endif
};

class CScrollableProtocol
{
public:
	CScrollableProtocol();
	virtual ~CScrollableProtocol();
	void setOnScrollingListener(Ref* pListener, SEL_ScrollingHandler pHandler);

protected:
	Ref* m_pScrollingListener;
	SEL_ScrollingHandler m_pScrollingHandler;
	void executeScrollingHandler(Ref* pSender);
#if USING_LUA
protected:
	int m_nScrollingScriptHandler;
	void executeScrollingScriptHandler(Ref* pSender);
public:
	virtual void setOnScrollingScriptHandler(int nHandler);
	virtual void removeOnScrollingScriptHandler();
#endif
};

class CMoveProtocol
{
public:
    CMoveProtocol();
    virtual ~CMoveProtocol();
    void setOnMoveingListener(Ref* pListener, SEL_MoveingHandler pHandler);
    void setOnMoveEndListener(Ref* pListener, SEL_MoveEndHandler pHandler);
protected:
    Ref* m_pMoveingListener;
    SEL_MoveingHandler m_pMoveingHandler;
    void executeMoveingHandler(Ref* pSender);
    Ref* m_pMoveEndListener;
    SEL_MoveEndHandler m_pMoveEndHandler;
    void executeMoveEndHandler(Ref* pSender);
#if USING_LUA
protected:
    int m_nMoveingScriptHandler;
    void executeMoveingScriptHandler(Ref* pSender);
    int m_nMoveEndScriptHandler;
    void executeMoveEndScriptHandler(Ref* pSender);
public:
    virtual void setOnMoveIngScriptHandler(int nHandler);
    virtual void removeOnMoveingScriptHandler();
    virtual void setOnMoveEndScriptHandler(int nHandler);
    virtual void removeOnMoveEndScriptHandler();
#endif
};

class CProgressEndedProtocol
{
public:
	CProgressEndedProtocol();
	virtual ~CProgressEndedProtocol();
	void setOnProgressEndedListener(Ref* pListener, SEL_ProgressEndedHandler pHandler);

protected:
	Ref* m_pProgressEndedListener;
	SEL_ProgressEndedHandler m_pProgressEndedHandler;
	void executeProgressEndedHandler(Ref* pSender);
#if USING_LUA
protected:
	int m_nProgressEndedScriptHandler;
	void executeProgressEndedScriptHandler(Ref* pSender);
public:
	virtual void setOnProgressEndedScriptHandler(int nHandler);
	virtual void removeOnProgressEndedScriptHandler();
#endif
};

class CValueChangeableProtocol
{
public:
	CValueChangeableProtocol();
	virtual ~CValueChangeableProtocol();
	void setOnValueChangedListener(Ref* pListener, SEL_ValueChangedHandler pHandler);

protected:
	int m_nValue;
	Ref* m_pValueChangedListener;
	SEL_ValueChangedHandler m_pValueChangedHandler;
	void executeValueChangedHandler(Ref* pSender, int nValue);
#if USING_LUA
protected:
	int m_nValueChangedScriptHandler;
	void executeValueChangedScriptHandler(Ref* pSender, int nValue);
public:
	virtual void setOnValueChangedScriptHandler(int nHandler);
	virtual void removeOnValueChangedScriptHandler();
#endif
};

class CClickableProtocol
{
public:
	CClickableProtocol();
	virtual ~CClickableProtocol();
	void setOnClickListener(Ref* pListener, SEL_ClickHandler pHandler);

protected:
	Ref* m_pClickListener;
	SEL_ClickHandler m_pClickHandler;
	void executeClickHandler(Ref* pSender);
#if USING_LUA
protected:
	int m_nClickScriptHandler;
	void executeClickScriptHandler(Ref* pSender);
public:
	virtual void setOnClickScriptHandler(int nHandler);
	virtual void removeOnClickScriptHandler();
#endif
};

class CLongClickableProtocol
{
public:
	CLongClickableProtocol();
	virtual ~CLongClickableProtocol();
	void setOnLongClickListener(Ref* pListener, SEL_LongClickHandler pHandler);

protected:
	Ref* m_pLongClickListener;
	SEL_LongClickHandler m_pLongClickHandler;
	bool executeLongClickHandler(Ref* pSender, Touch* pTouch);

protected:
	bool m_bLongClickedUpdate;
	float m_fLongClickTimeCounter;
	bool m_bLongClickEnabled;

	float m_fLongClickLastTouchDuration;
	Touch* m_pLongClickLastTouch;
#if USING_LUA
protected:
	int m_nLongClickScriptHandler;
	bool executeLongClickScriptHandler(Ref* pSender, Touch* pTouch);
public:
	virtual void setOnLongClickScriptHandler(int nHandler);
	virtual void removeOnLongClickScriptHandler();
#endif
};

class CCheckableProtocol
{
public:
	CCheckableProtocol();
	virtual ~CCheckableProtocol();
	virtual void setChecked(bool bChecked);
	bool isChecked() const;
	virtual void setExclusion(int nExclusion);
	int getExclusion() const;
	void setOnCheckListener(Ref* pListener, SEL_CheckHandler pHandler);

protected:
	virtual void executeCheckHandler(Ref* pSender, bool bChecked);
	void setUnCheckedForOtherWidgetsByExclusion(Node* pParent);

protected:
	bool m_bChecked;
	int  m_nExclusion;
	Ref* m_pCheckListener;
	SEL_CheckHandler m_pCheckHandler;
#if USING_LUA
protected:
	int m_nCheckScriptHandler;
	void executeCheckScriptHandler(Ref* pSender, bool bChecked);
public:
	virtual void setOnCheckScriptHandler(int nHandler);
	virtual void removeCheckScriptHandler();
#endif
};

class CControlableProtocol
{
public:
	CControlableProtocol();
	virtual ~CControlableProtocol();
	void setOnControlListener(Ref* pListener, SEL_ControlHandler pHandler);

protected:
	Ref* m_pControlListener;
	SEL_ControlHandler m_pControlHandler;
	void executeControlHandler(Ref* pSender, float cx, float cy);
#if USING_LUA
protected:
	int m_nControlScriptHandler;
	void executeControlScriptHandler(Ref* pSender, float cx, float cy);
public:
	virtual void setOnControlScriptHandler(int nHandler);
	virtual void removeOnControlScriptHandler();
#endif
};

#ifndef CC_WIDGET_LONGCLICK_SCHEDULE
#define CC_WIDGET_LONGCLICK_SCHEDULE(__CHILDE__) \
protected: \
\
void performLongClickUpdate() \
{ \
	schedule(schedule_selector(__CHILDE__::onLongClickUpdate)); \
} \
\
void stopLongClickUpdate() \
{ \
	unschedule(schedule_selector(__CHILDE__::onLongClickUpdate)); \
} \
\
void onLongClickUpdate(float dt) \
{ \
	if( m_bLongClickedUpdate && m_bLongClickEnabled ) \
	{ \
		if( m_fLongClickTimeCounter > CC_WIDGET_LONGPRESS_TIME ) \
		{ \
			Touch* pTempTouch = m_pLongClickLastTouch; \
			interruptTouchCascade(pTempTouch, m_fLongClickLastTouchDuration); \
			if( executeLongClickHandler(this, pTempTouch) ) \
			{ \
				setLongClickTouchHandlerWidget(this, pTempTouch->getID()); \
			} \
			m_bLongClickedUpdate = false; \
			stopLongClickUpdate(); \
		} \
		else \
		{ \
			m_fLongClickTimeCounter += dt; \
		} \
	} \
}
#endif //CC_WIDGET_LONGCLICK_SCHEDULE

#ifndef CC_WIDGET_LONGCLICK_ONTOUCHBEGAN
#define CC_WIDGET_LONGCLICK_ONTOUCHBEGAN \
m_pLongClickLastTouch = NULL; \
m_fLongClickTimeCounter = 0.0f; \
if( m_bLongClickEnabled ) \
{ \
	m_pLongClickLastTouch = pTouch; \
	m_fLongClickLastTouchDuration = 0.0f; \
	m_bLongClickedUpdate = true; \
	performLongClickUpdate(); \
}
#endif //CC_WIDGET_LONGCLICK_ONTOUCHBEGAN

#ifndef CC_WIDGET_LONGCLICK_ONTOUCHMOVED
#define CC_WIDGET_LONGCLICK_ONTOUCHMOVED \
if( m_bLongClickEnabled ) \
{ \
	m_pLongClickLastTouch = pTouch; \
	m_fLongClickLastTouchDuration = fDuration; \
	\
	Point tMovePoint = getParent()->convertToNodeSpace(pTouch->getLocation()); \
	if( !getBoundingBox().containsPoint(tMovePoint) ) \
	{ \
		m_bLongClickedUpdate = false; \
		stopLongClickUpdate(); \
	} \
}
#endif //CC_WIDGET_LONGCLICK_ONTOUCHMOVED

#ifndef CC_WIDGET_LONGCLICK_ONTOUCHENDED
#define CC_WIDGET_LONGCLICK_ONTOUCHENDED \
if( m_bLongClickEnabled ) \
{ \
	m_fLongClickTimeCounter = 0.0f; \
	m_pLongClickLastTouch = NULL; \
	m_bLongClickedUpdate = false; \
	stopLongClickUpdate(); \
}
#endif //CC_WIDGET_LONGCLICK_ONTOUCHENDED

#ifndef CC_WIDGET_LONGCLICK_ONTOUCHCANCELLED
#define CC_WIDGET_LONGCLICK_ONTOUCHCANCELLED \
if( m_bLongClickEnabled ) \
{ \
	m_fLongClickTimeCounter = 0.0f; \
	m_pLongClickLastTouch = NULL; \
	m_bLongClickedUpdate = false; \
	stopLongClickUpdate(); \
}
#endif //CC_WIDGET_LONGCLICK_ONTOUCHCANCELLED


#ifndef CC_WIDGET_UPDATE_BACKGROUND_POS
#define CC_WIDGET_UPDATE_BACKGROUND_POS \
if(m_pBackgroundImage) m_pBackgroundImage->setPosition(Point(_contentSize.width / 2, _contentSize.height / 2)); \
if(m_pBackgroundColor) m_pBackgroundColor->setPosition(Point(_contentSize.width / 2, _contentSize.height / 2)); \
if(m_pBackgroundColor) m_pBackgroundColor->setContentSize(_contentSize); \
if(m_pBackgroundGradient) m_pBackgroundGradient->setPosition(Point(_contentSize.width / 2, _contentSize.height / 2)); \
if(m_pBackgroundGradient) m_pBackgroundGradient->setContentSize(_contentSize);
#endif //CC_WIDGET_UPDATE_BACKGROUND_POS

#ifndef CC_WIDGET_BACKGROUND
#define CC_WIDGET_BACKGROUND \
public: \
	virtual void setBackgroundImage(const char* pFile) \
	{ \
		CCAssert(pFile && strlen(pFile), "file path should not null"); \
		Texture2D* pTexture = Director::getInstance()->getTextureCache()->addImage(pFile); \
		setBackgroundTexture(pTexture); \
	} \
	\
	virtual void setBackgroundTexture(Texture2D* pTexture) \
	{ \
		if( m_pBackgroundColor ) \
		{ \
			removeChild(m_pBackgroundColor); \
			m_pBackgroundColor = NULL; \
		} \
		\
		if( m_pBackgroundGradient ) \
		{ \
			removeChild(m_pBackgroundGradient); \
			m_pBackgroundGradient = NULL; \
		} \
		\
		if( m_pBackgroundImage ) \
		{ \
			Rect rect; \
			rect.origin = Point::ZERO; \
			rect.size = pTexture->getContentSize(); \
			\
			m_pBackgroundImage->setTexture(pTexture); \
			m_pBackgroundImage->setTextureRect(rect); \
		} \
		else \
		{ \
			m_pBackgroundImage = Sprite::createWithTexture(pTexture); \
			m_pBackgroundImage->setLocalZOrder(-128); \
			addChild(m_pBackgroundImage); \
		} \
		m_pBackgroundImage->setPosition(Point(_contentSize.width / 2, _contentSize.height / 2)); \
	} \
	\
	virtual void setBackgroundSpriteFrame(SpriteFrame* pSpriteFrame) \
	{ \
		if( m_pBackgroundColor ) \
		{ \
			removeChild(m_pBackgroundColor); \
			m_pBackgroundColor = NULL; \
		} \
		\
		if( m_pBackgroundGradient ) \
		{ \
			removeChild(m_pBackgroundGradient); \
			m_pBackgroundGradient = NULL; \
		} \
		\
		if( m_pBackgroundImage ) \
		{ \
			m_pBackgroundImage->setSpriteFrame(pSpriteFrame); \
		} \
		else \
		{ \
			m_pBackgroundImage = Sprite::createWithSpriteFrame(pSpriteFrame); \
			m_pBackgroundImage->setLocalZOrder(-128); \
			addChild(m_pBackgroundImage); \
		} \
		m_pBackgroundImage->setPosition(Point(_contentSize.width / 2, _contentSize.height / 2)); \
	} \
	\
	virtual void setBackgroundSpriteFrameName(const char* pFrameName) \
	{ \
		SpriteFrame *pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(pFrameName); \
		return setBackgroundSpriteFrame(pFrame); \
	} \
	\
	virtual Sprite* getBackgroundImage() const \
	{ \
		return m_pBackgroundImage; \
	} \
	\
	virtual void removeBackgroundImage() \
	{ \
		if( m_pBackgroundImage ) \
		{ \
			removeChild(m_pBackgroundImage); \
			m_pBackgroundImage = NULL; \
		} \
	} \
	\
protected: \
	Sprite* m_pBackgroundImage; \
	\
public: \
	virtual void setBackgroundColor(const Color4B& tColor) \
	{ \
		if( m_pBackgroundImage ) \
		{ \
			removeChild(m_pBackgroundImage); \
			m_pBackgroundImage = NULL; \
		} \
		\
		if( m_pBackgroundGradient ) \
		{ \
			removeChild(m_pBackgroundGradient); \
			m_pBackgroundGradient = NULL; \
		} \
		\
		if( m_pBackgroundColor ) \
		{ \
			m_pBackgroundColor->setColor(Color3B(tColor.r, tColor.g, tColor.b)); \
			m_pBackgroundColor->setOpacity(tColor.a); \
		} \
		else \
		{ \
			m_pBackgroundColor = CColorView::create(tColor); \
			m_pBackgroundColor->setTouchEnabled(false); \
			m_pBackgroundColor->setLocalZOrder(-128); \
			m_pBackgroundColor->setContentSize(_contentSize); \
			addChild(m_pBackgroundColor); \
		} \
		m_pBackgroundColor->setPosition(Point(_contentSize.width / 2, _contentSize.height / 2)); \
	} \
	\
	virtual void removeBackgroundColor() \
	{ \
		if( m_pBackgroundColor ) \
		{ \
			removeChild(m_pBackgroundColor); \
			m_pBackgroundColor = NULL; \
		} \
	} \
	\
protected: \
	CColorView* m_pBackgroundColor; \
	\
public: \
	virtual void setBackgroundGradient(const Color4B& tStart, const Color4B& tEnd, const Point& v) \
	{ \
		if( m_pBackgroundImage ) \
		{ \
			removeChild(m_pBackgroundImage); \
			m_pBackgroundImage = NULL; \
		} \
		\
		if( m_pBackgroundColor ) \
		{ \
			removeChild(m_pBackgroundColor); \
			m_pBackgroundColor = NULL; \
		} \
		\
		if( m_pBackgroundGradient ) \
		{ \
			m_pBackgroundGradient->setStartColor(Color3B(tStart.r, tStart.g, tStart.b)); \
			m_pBackgroundGradient->setEndColor(Color3B(tEnd.r, tEnd.g, tEnd.b)); \
			m_pBackgroundGradient->setStartOpacity(tStart.a); \
			m_pBackgroundGradient->setEndOpacity(tEnd.a); \
			m_pBackgroundGradient->setVector(v); \
		} \
		else \
		{ \
			m_pBackgroundGradient = CGradientView::create(tStart, tEnd, v); \
			m_pBackgroundGradient->setTouchEnabled(false); \
			m_pBackgroundGradient->setLocalZOrder(-128); \
			m_pBackgroundGradient->setContentSize(_contentSize); \
			addChild(m_pBackgroundGradient); \
		} \
		m_pBackgroundGradient->setPosition(Point(_contentSize.width / 2, _contentSize.height / 2)); \
	} \
	\
	virtual void removeBackgroundGradient() \
	{ \
		if( m_pBackgroundGradient ) \
		{ \
			removeChild(m_pBackgroundGradient); \
			m_pBackgroundGradient = NULL; \
		} \
	} \
protected: \
	CGradientView* m_pBackgroundGradient; \
	\
public: \
	virtual void setBackgroundOpacity(GLbyte opacity) \
	{ \
		if( m_pBackgroundImage ) \
		{ \
			m_pBackgroundImage->setOpacity(opacity); \
			return; \
		} \
		\
		if( m_pBackgroundColor ) \
		{ \
			m_pBackgroundColor->setOpacity(opacity); \
			return; \
		} \
		\
		if( m_pBackgroundGradient ) \
		{ \
			m_pBackgroundGradient->setOpacity(opacity);\
			return; \
		} \
	}
#endif //CC_WIDGET_BACKGROUND


NS_CC_WIDGET_END

#endif //__CCWIDGET_EVENT_MACROS_H__