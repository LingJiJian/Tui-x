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
#include "Label.h"

NS_CC_WIDGET_BEGIN

CLabel::CLabel()
:m_bUnderLine(false)
,m_bMiddleLine(false)
{
	setThisObject(this);
}

CLabel::~CLabel()
{
}

CLabel* CLabel::create()
{
	auto ret = new CLabel();
	if (ret)
	{
		ret->autorelease();
	}
	return ret;
}

CLabel* CLabel::createWithTTF(const TTFConfig& ttfConfig, const std::string& text, TextHAlignment alignment /* = TextHAlignment::CENTER */, int maxLineWidth /* = 0 */)
{
	auto ret = new CLabel();
	ret->autorelease();
	ret->_hAlignment = alignment;

	ret->setTTFConfig(ttfConfig);

	ret->setMaxLineWidth(maxLineWidth);
	ret->setString(text);
	
	ret->setTouchEnabled(false);
	ret->setAnchorPoint(CCWIDGET_BASIC_DEFAULT_ANCHOR_POINT);
	return ret;
}

CLabel* CLabel::createWithTTF(const std::string& text, const std::string& fontFile, float fontSize, const Size& dimensions /* = Size::ZERO */, TextHAlignment hAlignment /* = TextHAlignment::CENTER */, TextVAlignment vAlignment /* = TextVAlignment::TOP */)
{
	CLabel *ret = NULL;
	if(FileUtils::getInstance()->isFileExist(fontFile)){
		ret = new CLabel();
		ret->autorelease();
		ret->_hAlignment = hAlignment;
		ret->_vAlignment = vAlignment;

		TTFConfig ttfConfig(fontFile.c_str(),fontSize,GlyphCollection::DYNAMIC);
		ret->setTTFConfig(ttfConfig);

		ret->setDimensions(dimensions.width,dimensions.height);
		ret->setString(text.c_str());
		ret->setTouchEnabled(false);
		ret->setAnchorPoint(CCWIDGET_BASIC_DEFAULT_ANCHOR_POINT);
	}else{
		ret = createWithSystemFont(text,fontFile,fontSize,dimensions,hAlignment,vAlignment);
	}
	return ret;
}

CLabel* CLabel::createWithSystemFont(const std::string& text, const std::string& font, float fontSize, const Size& dimensions /* = Size::ZERO */, TextHAlignment hAlignment /* = TextHAlignment::CENTER */, TextVAlignment vAlignment /* = TextVAlignment::TOP */)
{
	auto ret = new CLabel();
	ret->autorelease();
	ret->_hAlignment = hAlignment;
	ret->_vAlignment = vAlignment;
	ret->setSystemFontName(font);
	ret->setSystemFontSize(fontSize);
	ret->setDimensions(dimensions.width, dimensions.height);
	ret->setString(text);

	ret->setTouchEnabled(false);
	ret->setAnchorPoint(CCWIDGET_BASIC_DEFAULT_ANCHOR_POINT);
	
	return ret;
}

void CLabel::draw(Renderer* renderer, const Mat4 &parentTransform, uint32_t parentFlags)
{
	Label::draw(renderer, parentTransform, parentFlags);
	if(!m_bUnderLine && !m_bMiddleLine)return;

	DrawPrimitives::setDrawColor4B(_displayedColor.r,_displayedColor.g,_displayedColor.b,_displayedOpacity);
	DrawPrimitives::setPointSize(2);
	Size contentSize = this->getContentSize();
	if(m_bUnderLine){
		DrawPrimitives::drawLine(Vec2::ZERO, Vec2(contentSize.width,0));
	}
	if(m_bMiddleLine){
		DrawPrimitives::drawLine(Vec2(0,contentSize.height/2), Vec2(contentSize.width,contentSize.height/2));
	}
}

CWidgetTouchModel CLabel::onTouchBegan(Touch* pTouch)
{
	CC_WIDGET_LONGCLICK_ONTOUCHBEGAN;

	return eWidgetTouchTransient;
}

void CLabel::onTouchMoved(Touch* pTouch, float fDuration)
{
	CC_WIDGET_LONGCLICK_ONTOUCHMOVED;
}

void CLabel::onTouchEnded(Touch* pTouch, float fDuration)
{
	CC_WIDGET_LONGCLICK_ONTOUCHENDED;

	Vec2 tPoint = _parent->convertTouchToNodeSpace(pTouch);
	if( getBoundingBox().containsPoint(tPoint) )
	{
		executeClickHandler(this);
	}
}

void CLabel::onTouchCancelled(Touch* pTouch, float fDuration)
{
	CC_WIDGET_LONGCLICK_ONTOUCHCANCELLED;
}


NS_CC_WIDGET_END