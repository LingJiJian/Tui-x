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
#ifndef __CCWIDGET_CONTROLVIEW_H__
#define __CCWIDGET_CONTROLVIEW_H__

#include "cocos2d.h"
#include "WidgetMacros.h"
#include "Widget.h"
#include "WidgetProtocol.h"

NS_CC_WIDGET_BEGIN

/**
 * class  : CColorView
 * author : Jason lee
 * email  : jason.lee.c@foxmail.com
 * descpt : controlview define
 */
class CControlView : public Node, public CWidget, public CControlableProtocol
{
public:
	CControlView();
	virtual ~CControlView();
	virtual bool init();
	virtual bool initWithFile(const char* pBaseBoard, const char* pJoystick);
	static CControlView* create();
	static CControlView* create(const char* pBaseBoard, const char* pJoystick);

	virtual void setContentSize(const Size& tContentSize);
	void setRadius(float fRadius);
	float getRadius() const;
	void setRelocateWithAnimation(bool bAni);
	bool isRelocateWithAnimation() const;

	virtual void setBaseBoardImage(const char* pFile);
	virtual void setJoystickImage(const char* pFile);
	virtual void setBaseBoardSpriteFrame(SpriteFrame* pFrame);
	virtual void setJoystickSpriteFrame(SpriteFrame* pFrame);
	virtual void setBaseBoardTexture(Texture2D *pTexture);
	virtual void setJoystickTexture(Texture2D *pTexture);
	virtual void setBaseBoardSpriteFrameName(const char* pSpriteName);
	virtual void setJoystickSpriteFrameName(const char* pSpriteName);

public:
	virtual CWidgetTouchModel onTouchBegan(Touch *pTouch);
	virtual void onTouchMoved(Touch *pTouch, float fDuration);
    virtual void onTouchEnded(Touch *pTouch, float fDuration);
    virtual void onTouchCancelled(Touch *pTouch, float fDuration);

protected:
	void relocateJoystick(bool bAni);
	virtual void onAnimateUpdate(float dt);
	void performAnimateUpdate();
	void stopAnimateUpdate();
	virtual void onExecuteEventUpdate(float dt);
	void performExecuteUpdate();
	void stopExecuteUpdate();

protected:
	Sprite* m_pBaseBoard;
	Sprite* m_pJoystick;
	float m_fRadius;

	bool m_bExecuteEventUpdate;
	bool m_bAnimationUpdate;
	bool m_bRelocateWithAnimation;
	Vec2 m_tCenterPoint;
	Vec2 m_tLastPoint;
};

NS_CC_WIDGET_END

#endif //__CCWIDGET_CONTROLVIEW_H__