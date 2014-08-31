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
#include "LabelBMFont.h"

NS_CC_WIDGET_BEGIN

CLabelBMFont::CLabelBMFont()
{
	setThisObject(this);
}

CLabelBMFont::~CLabelBMFont()
{

}

CWidgetTouchModel CLabelBMFont::onTouchBegan(Touch *pTouch)
{
	CC_WIDGET_LONGCLICK_ONTOUCHBEGAN

	return eWidgetTouchTransient;
}

void CLabelBMFont::onTouchMoved(Touch *pTouch, float fDuration)
{
	CC_WIDGET_LONGCLICK_ONTOUCHMOVED;
}

void CLabelBMFont::onTouchEnded(Touch *pTouch, float fDuration)
{
	CC_WIDGET_LONGCLICK_ONTOUCHENDED

	Vec2 touchPointInView = _parent->convertToNodeSpace(pTouch->getLocation());
	if( getBoundingBox().containsPoint(touchPointInView) )
	{
		executeClickHandler(this);
	}
}

void CLabelBMFont::onTouchCancelled(Touch *pTouch, float fDuration)
{
	CC_WIDGET_LONGCLICK_ONTOUCHCANCELLED;
}

bool CLabelBMFont::init()
{
	bool bRet = Label::init();

	setTouchEnabled(false);
	setAnchorPoint(CCWIDGET_BASIC_DEFAULT_ANCHOR_POINT);

	return bRet;
}

CLabelBMFont* CLabelBMFont::create()
{
    CLabelBMFont* pRet = new CLabelBMFont();
    if( pRet && pRet->init() )
    {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return NULL;
}

CLabelBMFont *CLabelBMFont::create(const std::string& text, const std::string& bmfontFilePath, const TextHAlignment& alignment /* = TextHAlignment::LEFT */, int maxLineWidth /* = 0 */, const Vec2& imageOffset /* = Point::ZERO */)
{
	auto ret = new CLabelBMFont();
	ret->_hAlignment = alignment;

	ret->setBMFontFilePath(bmfontFilePath, imageOffset);
	ret->setMaxLineWidth(maxLineWidth);
	ret->setString(text);
	ret->autorelease();

	return ret;
}

NS_CC_WIDGET_END