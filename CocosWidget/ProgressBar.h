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
#ifndef __CCWIDGET_PROGRESSBAR_H__
#define __CCWIDGET_PROGRESSBAR_H__

#include "cocos2d.h"
#include "WidgetMacros.h"
#include "Widget.h"
#include "WidgetProtocol.h"
#include "ColorView.h"
#include "GradientView.h"
#include "Label.h"

NS_CC_WIDGET_BEGIN

/**
 * enum   : CProgressBarDirection
 * author : Jason lee
 * email  : jason.lee.c@foxmail.com
 * descpt : progress bar direction
 */
enum CProgressBarDirection
{
	eProgressBarDirectionLeftToRight,
	eProgressBarDirectionRightToLeft,
	eProgressBarDirectionBottomToTop,
	eProgressBarDirectionTopToBottom
};
//文本格式
enum eLabFormat
{
	kPercent,
	kRatio
};

/**
 * class  : CProgressBar
 * author : Jason lee
 * email  : jason.lee.c@foxmail.com
 * descpt : progress bar define, 4 direction
 */
class CProgressBar : public Node
, public CProgressEndedProtocol
, public CValueChangeableProtocol
{
public:
	CProgressBar();
	virtual ~CProgressBar();
	virtual bool init();
	virtual bool initWithFile(const char* pProgress);
	static CProgressBar* create();
	static CProgressBar* create(const char* pProgress);

	virtual bool initWithFileSpriteFrame(const char* pProgress);
	static CProgressBar* createSpriteFrame(const char* pProgress);

	virtual void initText(const std::string& text, const std::string& fontFile, float fontSize,
		const Size& dimensions,const Color3B &color);
	CLabel* getLabel();
	CC_SYNTHESIZE(eLabFormat,m_eLabelFormat,LabelFormat);

	virtual void setContentSize(const Size& tSize);
	void setValue(int nValue);
	int getValue() const;
	void setMaxValue(int nMaxValue);
	int getMaxValue() const;
	void setMinValue(int nMinValue);
	int getMinValue() const;
	void setDirection(CProgressBarDirection eDirection);
	CProgressBarDirection getDirection() const;
	void startProgress(int nValue, float fDuration);
	void startProgressFromTo(int nFromValue, int nToValue, float fDuration);
	void stopProgress();
	float getPercentage() const;
	bool isProgressEnded() const;

	void setShowValueLabel(bool b);
	virtual void setProgressImage(const char* pFile);
	virtual void setProgressTexture(Texture2D* pTexture);
	virtual void setProgressSpriteFrame(SpriteFrame* pFrame);
	virtual void setProgressSpriteFrameName(const char* pSpriteName);

	CC_WIDGET_BACKGROUND;
	
protected:
	void performProgressing();
	void onProgressing(float dt);
	void stoppedProgressing();

	void getScissorRectByPercentage(Rect& tRect);
	virtual void changeValueAndExecuteEvent(int nValue, bool bExeEvent);	

protected:
	int m_nMaxValue;
	int m_nMinValue;
	int m_nValue;

	bool m_bProgressing;

	bool m_bFirstTick;
	float m_fLapsed;
	float m_fDuration;
	int m_nToValue;
	int m_nFromValue;

	Size m_tProgressSize;
	Vec2 m_tCenterPoint;

	Sprite* m_pProgressSprite;
	CProgressBarDirection m_eDirection;

private:
	CLabel *m_pLabel;
};


NS_CC_WIDGET_END

#endif //__CCWIDGET_PROGRESSBAR_H__