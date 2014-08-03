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
#ifndef __CCWIDGET_BUTTON_H__
#define __CCWIDGET_BUTTON_H__

#include "cocos2d.h"
#include "WidgetMacros.h"
#include "Widget.h"
#include "Scale9Sprite.h"
#include "Label.h"
#include "WidgetProtocol.h"

NS_CC_WIDGET_BEGIN

/**
 * class  : CButton
 * author : Jason lee
 * email  : jason.lee.c@foxmail.com
 * descpt : button define
 */
class CButton : public Node, public CWidget, public CClickableProtocol, public CLongClickableProtocol
{
public:
	CButton();
	virtual ~CButton();
	
	virtual bool init();
	virtual bool initWith9Sprite(const Size& tSize, const char* pNormal, const char* pSelected, const char* pDisabled);
	virtual bool initWith9SpriteFrameName(const Size& tSize, const char* pNormal, const char* pSelected, const char* pDisabled);
	virtual bool initWithFile(const char* pNormal, const char* pSelected, const char* pDisabled);
	static CButton* create();
	static CButton* create(const char* pNormal, const char* pSelected = NULL, const char* pDisabled = NULL);
	static CButton* createWith9Sprite(const Size& tSize, const char* pNormal, const char* pSelected = NULL, const char* pDisabled = NULL);
	static CButton* createWith9SpriteFrameName(const Size& tSize, const char* pNormal, const char* pSelected = NULL, const char* pDisabled = NULL);

	virtual void setContentSize(const Size& contentSize);
	virtual void setEnabled(bool bEnabled);
	void setLabelOffset(const Vec2& tOffset);
	void setText(const char* pText);
	const char* getText();

	virtual void initText(const std::string& text, const std::string& fontFile, float fontSize,
		const Size& dimensions = Size::ZERO,const Color3B& color = Color3B::WHITE);
	virtual CLabel* getLabel();
	virtual bool isScale9Enabled();
	virtual void setScale9Enabled(bool bEnabled);
	virtual void setCascadeTextSizeEnabled(bool bEnabled, const Size& tPadding = Size(50, 30));

	virtual void setNormalImage(const char* pFile);
	virtual void setSelectedImage(const char* pFile);
	virtual void setDisabledImage(const char* pFile);
	virtual void setNormalTexture(Texture2D *pTexture);
	virtual void setSelectedTexture(Texture2D *pTexture);
	virtual void setDisabledTexture(Texture2D *pTexture);
	virtual void setNormalSpriteFrameName(const char* pSpriteName);
	virtual void setSelectedSpriteFrameName(const char* pSpriteName);
	virtual void setDisabledSpriteFrameName(const char* pSpriteName);
	virtual void setNormalSpriteFrame(SpriteFrame* pFrame);
	virtual void setSelectedSpriteFrame(SpriteFrame* pFrame);
	virtual void setDisabledSpriteFrame(SpriteFrame* pFrame);
	virtual Node* getNormalImage();
	virtual Node* getSelectedImage();
	virtual Node* getDisabledImage();

	CC_WIDGET_LONGCLICK_SCHEDULE(CButton);

public:
	virtual CWidgetTouchModel onTouchBegan(Touch* pTouch);
	virtual void onTouchMoved(Touch* pTouch, float fDuration);
	virtual void onTouchEnded(Touch* pTouch, float fDuration);
	virtual void onTouchCancelled(Touch* pTouch, float fDuration);

protected:
	void updateCascadeTextSize();

protected:
	Node* m_pNormalImage;
	Node* m_pSelectedImage;
	Node* m_pDisabledImage;
	bool m_bScale9Enabled;
	CLabel* m_pLabel;
	Vec2 m_tTextOffset;
	bool m_bCascadeTextSizeEnabled;
	Size m_tCascadeTextSizePadding;
	
};

NS_CC_WIDGET_END

#endif //__CCWIDGET_BUTTON_H__