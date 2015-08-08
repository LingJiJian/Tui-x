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
#include "TextRich.h"
#include "WitlsMacros.h"
using namespace std;

NS_CC_WIDGET_BEGIN

bool RichElement::init(int tag, const Color3B &color, GLubyte opacity)
{
	_tag = tag;
	_color = color;
	_opacity = opacity;
	return true;
}


RichElementText* RichElementText::create(int tag, const Color3B &color,const std::string& text, const std::string& fontName, float fontSize,bool isUnderLine,bool isOutLine,const Color4B& outLineColor)
{
	RichElementText* element = new (std::nothrow) RichElementText();
	if (element && element->init(tag, color, text, fontName, fontSize,isUnderLine,isOutLine,outLineColor))
	{
		element->autorelease();
		return element;
	}
	CC_SAFE_DELETE(element);
	return nullptr;
}

bool RichElementText::init(int tag, const Color3B &color, const std::string& text, const std::string& fontName, float fontSize,bool isUnderLine,bool isOutLine,const Color4B& outLineColor)
{
	if (RichElement::init(tag, color))
	{
		_text = text;
		_fontName = fontName;
		_fontSize = fontSize;
		_isUnderLine = isUnderLine;
		_isOutLine = isOutLine;
		_outLineColor = outLineColor;
		return true;
	}
	return false;
}

RichElementImage* RichElementImage::create(int tag, const std::string& filePath,bool isAnim,float delay,bool isLoop)
{
	RichElementImage* element = new (std::nothrow) RichElementImage();
	if (element && element->init(tag, filePath,isAnim,delay,isLoop))
	{
		element->autorelease();
		return element;
	}
	CC_SAFE_DELETE(element);
	return nullptr;
}

bool RichElementImage::init(int tag, const std::string& filePath,bool isAnim,float delay,bool isLoop)
{
	if (RichElement::init(tag))
	{
		_filePath = filePath;
		_isAnim = isAnim;
		_delay = delay;
		_isLoop = isLoop;
		return true;
	}
	return false;
}

RichElementCustomNode* RichElementCustomNode::create(int tag, Node *customNode)
{
	RichElementCustomNode* element = new (std::nothrow) RichElementCustomNode();
	if (element && element->init(tag, customNode))
	{
		element->autorelease();
		return element;
	}
	CC_SAFE_DELETE(element);
	return nullptr;
}

bool RichElementCustomNode::init(int tag, Node *customNode)
{
	if (RichElement::init(tag))
	{
		_customNode = customNode;
		_customNode->retain();
		return true;
	}
	return false;
}

bool RichCacheElement::init( bool isUse, Node* node )
{
	_isUse = isUse;
	_node = node;
	_node->retain();
	return true;
}

RichCacheElement* RichCacheElement::create( bool isUse, Node* node )
{
	RichCacheElement* element = new (std::nothrow) RichCacheElement();
	if (element && element->init(isUse,node))
	{
		element->autorelease();
		return element;
	}
	CC_SAFE_DELETE(element);
	return nullptr;
}

RichCacheElement::~RichCacheElement()
{
	if (_node) _node->release();
}

CTextRich::CTextRich():
	_leftSpaceWidth(0.0f),
	_verticalSpace(0.0f)
{
}

CTextRich::~CTextRich()
{
	_richElements.clear();
	_cacheLabElements.clear();
	_cacheImgElements.clear();
	_underLineTags.clear();
}

CTextRich* CTextRich::create()
{
	CTextRich* widget = new (std::nothrow) CTextRich();
	if (widget && widget->init())
	{
		widget->autorelease();
		return widget;
	}
	CC_SAFE_DELETE(widget);
	return nullptr;
}

bool CTextRich::init()
{
	if (Node::init())
	{
		return true;
	}
	return false;
}

void CTextRich::removeAllElements()
{
	removeAllChildrenWithCleanup(false);
	auto len = _cacheImgElements.size();
	for (int i=0;i<len;i++)
	{
		_cacheImgElements.at(i)->_isUse = false;
	}
	len = _cacheLabElements.size();
	for (int i=0;i<len;i++)
	{
		_cacheLabElements.at(i)->_isUse = false;
	}
	_underLineTags.clear();
	_elementRenders.clear();
}

void CTextRich::insertElement(int tag,const char* pString, const char* pFontName /* = NULL */, float fFontSize /* = 0.0f */, const Color3B& tColor /* = Color3B::WHITE */,bool isUnderLine /* = false */,bool isOutLine /* = false */,const Color4B& outLineColor/* =Color4B::WHITE */)
{
	_richElements.pushBack(RichElementText::create(tag,tColor,pString,pFontName,fFontSize,isUnderLine,isOutLine,outLineColor));
}

void CTextRich::insertElement( int tag,const char* path, bool isAnim,float delay,bool isLoop )
{
	_richElements.pushBack(RichElementImage::create(tag,path,isAnim,delay,isLoop));
}

void CTextRich::insertElement( int tag,Node* pNode )
{
	_richElements.pushBack(RichElementCustomNode::create(tag,pNode));
}

void CTextRich::reloadData()
{
	removeAllElements();
	
	if (_maxLineWidth == 0)
	{
		addNewLine();
		for (ssize_t i=0; i<_richElements.size(); i++)
		{
			RichElement* element = _richElements.at(i);
			Node* elementRenderer = nullptr;
			switch (element->_type)
			{
			case RichElement::Type::TEXT:
				{
					RichElementText* elmtText = static_cast<RichElementText*>(element);
					elementRenderer = makeLabel(getCacheLabel(),elmtText->_color,elmtText->_text.c_str(), elmtText->_fontName, elmtText->_fontSize,elmtText->_isUnderLine,elmtText->_tag,elmtText->_isOutLine,elmtText->_outLineColor);
					break;
				}
			case RichElement::Type::IMAGE:
				{
					RichElementImage* elmtImage = static_cast<RichElementImage*>(element);
					elementRenderer = makeImage(getCacheImage(),elmtImage->_filePath,elmtImage->_tag,elmtImage->_isAnim,elmtImage->_delay,elmtImage->_isLoop);
					break;
				}
			case RichElement::Type::CUSTOM:
				{
					RichElementCustomNode* elmtCustom = static_cast<RichElementCustomNode*>(element);
					elementRenderer = elmtCustom->_customNode;
					break;
				}
			default:
				break;
			}
			elementRenderer->setOpacity(element->_opacity);
			pushToContainer(elementRenderer);
		}
	}
	else
	{
		addNewLine();
		for (ssize_t i=0; i<_richElements.size(); i++)
		{

			RichElement* element = static_cast<RichElement*>(_richElements.at(i));
			switch (element->_type)
			{
			case RichElement::Type::TEXT:
				{
					RichElementText* elmtText = static_cast<RichElementText*>(element);
					handleTextRenderer(elmtText->_text.c_str(), elmtText->_fontName.c_str(), elmtText->_fontSize,elmtText->_isUnderLine, elmtText->_color, elmtText->_opacity,elmtText->_tag,elmtText->_isOutLine,elmtText->_outLineColor);
					break;
				}
			case RichElement::Type::IMAGE:
				{
					RichElementImage* elmtImage = static_cast<RichElementImage*>(element);
					handleImageRenderer(elmtImage->_filePath.c_str(), elmtImage->_color, elmtImage->_opacity,elmtImage->_tag,elmtImage->_isAnim,elmtImage->_delay,elmtImage->_isLoop);
					break;
				}
			case RichElement::Type::CUSTOM:
				{
					RichElementCustomNode* elmtCustom = static_cast<RichElementCustomNode*>(element);
					handleCustomRenderer(elmtCustom->_customNode,elmtCustom->_tag);
					break;
				}
			default:
				break;
			}
		}
	}
	formarRenderers();
}

void CTextRich::handleTextRenderer(const std::string& text, const std::string& fontName, float fontSize,bool isUnder, const Color3B& color, GLubyte opacity,int tag,bool isOutLine,const Color4B& outLineColor){
	Node* textRenderer = nullptr;
	float textRendererWidth = 0;

	vector< string > vect = split(text,"\n");
	if (vect.size() == 1 ){
		textRenderer = makeLabel(getCacheLabel(),color,text, fontName, fontSize,isUnder,tag,isOutLine,outLineColor);

		textRendererWidth = textRenderer->getContentSize().width;
		_leftSpaceWidth -= textRendererWidth;


		if (_leftSpaceWidth < 0.0f)
		{
			float overstepPercent = (-_leftSpaceWidth) / textRendererWidth;
			std::string curText = text;
			size_t stringLength = StringUtils::getCharacterCountInUTF8String(text);
			int leftLength = stringLength * (1.0f - overstepPercent);
			std::string leftWords = getSubStringOfUTF8String(curText,0,leftLength);
			std::string cutWords = getSubStringOfUTF8String(curText, leftLength, stringLength - leftLength);
			if (leftLength > 0)
			{
				Node* leftRenderer = nullptr;
				leftRenderer = makeLabel(getCacheLabel(),color,leftWords, fontName, fontSize,isUnder,tag,isOutLine,outLineColor);
				if (leftRenderer)
				{
					leftRenderer->setOpacity(opacity);
					pushToContainer(leftRenderer);
				}
			}

			addNewLine();
			handleTextRenderer(cutWords.c_str(), fontName, fontSize,isUnder, color, opacity,tag,isOutLine,outLineColor);
		}
		else
		{
			textRenderer->setOpacity(opacity);
			pushToContainer(textRenderer);
		}

	}else{
		auto len = vect.size();
		for (int i=0;i<len;i++)
		{
			std::string s = vect.at(i);
			textRenderer = makeLabel(getCacheLabel(),color,s, fontName, fontSize,isUnder,tag,isOutLine,outLineColor);
			textRenderer->setTag(tag);

			if (s == "" && i<len - 1) {
				((Label*)textRenderer)->setString(" ");//hold on the new line
				pushToContainer(textRenderer);
				addNewLine();
				continue;
			}

			textRendererWidth = textRenderer->getContentSize().width;
			_leftSpaceWidth -= textRendererWidth;
			if (_leftSpaceWidth < 0.0f)
			{
				float overstepPercent = (-_leftSpaceWidth) / textRendererWidth;
				std::string curText = s;
				size_t stringLength = StringUtils::getCharacterCountInUTF8String(s);
				int leftLength = stringLength * (1.0f - overstepPercent);
				std::string leftWords = getSubStringOfUTF8String(curText,0,leftLength);
				std::string cutWords = getSubStringOfUTF8String(curText, leftLength, stringLength - leftLength);
				if (leftLength > 0)
				{
					Node* leftRenderer = nullptr;
					leftRenderer = makeLabel(getCacheLabel(),color,leftWords, fontName, fontSize,isUnder,tag,isOutLine,outLineColor);
					if (leftRenderer)
					{
						leftRenderer->setOpacity(opacity);
						pushToContainer(leftRenderer);
					}
				}

				addNewLine();
				handleTextRenderer(cutWords.c_str(), fontName, fontSize,isUnder, color, opacity,tag,isOutLine,outLineColor);
			}else{
				textRenderer->setOpacity(opacity);
				pushToContainer(textRenderer);
				if (i<len - 1) addNewLine();//ignore the last new line
			}
		}
	}

}

void CTextRich::draw(Renderer* renderer, const Mat4 &transform, uint32_t flags)
{
	_customCommand.init(_globalZOrder);
	_customCommand.func = CC_CALLBACK_0(CTextRich::onDraw, this, transform, flags);
	renderer->addCommand(&_customCommand);
}

void CTextRich::onDraw(const Mat4 &transform, uint32_t flags)
{
	Director* director = Director::getInstance();
	director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
	director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, transform);

	auto children = this->getChildren();
	auto len = children.size();
	for (int i=0; i<len; i++) {
		Node* pChild = children.at(i);
		if (_underLineTags.count(pChild->getTag()) >= 1){
			DrawPrimitives::setDrawColor4B(pChild->getDisplayedColor().r,
				pChild->getDisplayedColor().g,
				pChild->getDisplayedColor().b,
				pChild->getDisplayedOpacity());
			DrawPrimitives::setPointSize(2);
			DrawPrimitives::drawLine(pChild->getPosition(),
				Vec2(pChild->getContentSize().width+pChild->getPosition().x,pChild->getPosition().y));
		}
	}
	//end draw
	director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
}

void CTextRich::handleImageRenderer(const std::string& fileParh, const Color3B &color, GLubyte opacity,int tag,bool isAnim,float delay,bool isLoop)
{
	Node* imageRenderer = makeImage(getCacheImage(),fileParh,tag,isAnim,delay,isLoop);
	handleCustomRenderer(imageRenderer,tag);
}

void CTextRich::handleCustomRenderer(Node *renderer,int tag)
{
	renderer->setTag(tag);
	Size imgSize = renderer->getContentSize();
	_leftSpaceWidth -= imgSize.width;
	if (_leftSpaceWidth < 0.0f)
	{
		addNewLine();
		pushToContainer(renderer);
		_leftSpaceWidth -= imgSize.width;
	}
	else
	{
		pushToContainer(renderer);
	}
}

void CTextRich::addNewLine()
{
	_leftSpaceWidth = _maxLineWidth;
	_elementRenders.push_back(new Vector<Node*>());
}

void CTextRich::formarRenderers()
{
	if (_maxLineWidth == 0)
	{
		float newContentSizeWidth = 0.0f;
		float newContentSizeHeight = 0.0f;

		Vector<Node*>* row = (_elementRenders[0]);
		float nextPosX = 0.0f;
		for (ssize_t j=0; j<row->size(); j++)
		{
			Node* l = row->at(j);
			l->setAnchorPoint(Vec2::ZERO);
			l->setPosition(nextPosX, 0.0f);
			this->addChild(l, 1);
			Size iSize = l->getContentSize();
			newContentSizeWidth += iSize.width;
			newContentSizeHeight = MAX(newContentSizeHeight, iSize.height);
			nextPosX += iSize.width;
		}
		this->setContentSize(Size(newContentSizeWidth, newContentSizeHeight));
	}
	else
	{
		float newContentSizeHeight = 0.0f;
		float *maxHeights = new float[_elementRenders.size()];

		for (size_t i=0; i<_elementRenders.size(); i++)
		{
			Vector<Node*>* row = (_elementRenders[i]);
			float maxHeight = 0.0f;
			for (ssize_t j=0; j<row->size(); j++)
			{
				Node* l = row->at(j);
				maxHeight = MAX(l->getContentSize().height, maxHeight);
			}
			maxHeights[i] = maxHeight;
			newContentSizeHeight += maxHeights[i];
		}


		float nextPosY = newContentSizeHeight;
		for (size_t i=0; i<_elementRenders.size(); i++)
		{
			Vector<Node*>* row = (_elementRenders[i]);
			float nextPosX = 0.0f;
			nextPosY -= (maxHeights[i] + _verticalSpace);

			for (ssize_t j=0; j<row->size(); j++)
			{
				Node* l = row->at(j);
				l->setAnchorPoint(Vec2::ZERO);
				l->setPosition(nextPosX, nextPosY);
				this->addChild(l, 1);
				nextPosX += l->getContentSize().width;
			}
		}
		this->setContentSize(Size(326,newContentSizeHeight));
		delete [] maxHeights;
	}

	size_t length = _elementRenders.size();
	for (size_t i = 0; i<length; i++)
	{
		Vector<Node*>* l = _elementRenders[i];
		l->clear();
		delete l;
	}    
	_elementRenders.clear();
	_richElements.clear();

}

void CTextRich::pushToContainer(Node *renderer)
{
	if (_elementRenders.size() <= 0)
	{
		return;
	}
	_elementRenders[_elementRenders.size()-1]->pushBack(renderer);
}

void CTextRich::setVerticalSpace(float space)
{
	_verticalSpace = space;
}

Label* CTextRich::getCacheLabel()
{
	Label* ret = nullptr;
	auto len = _cacheLabElements.size();
	for (int i=0;i<len;i++)
	{
		RichCacheElement* pElement = _cacheLabElements.at(i);
		if (pElement->_isUse == false)
		{
			pElement->_isUse = true;
			ret = (Label*)pElement->_node;
			break;
		}
	}
	if (ret == nullptr){
		ret = Label::create();
		_cacheLabElements.pushBack(RichCacheElement::create(true,ret));
	}
	return ret;
}

Sprite* CTextRich::getCacheImage()
{
	Sprite* ret = nullptr;
	auto len = _cacheImgElements.size();
	for (int i=0;i<len;i++)
	{
		RichCacheElement* pElement = _cacheImgElements.at(i);
		if (pElement->_isUse == false)
		{
			pElement->_isUse = true;
			ret = (Sprite*)pElement->_node;
			break;
		}
	}
	if (ret == nullptr){
		ret = Sprite::create();
		_cacheImgElements.pushBack(RichCacheElement::create(true,ret));
	}
	return ret;
}

Node* CTextRich::makeLabel( Label* pTarget,const Color3B& color, const std::string& text, const std::string& fontName, int fontSize,bool isUnder, int tag,bool isOutLine,const Color4B& outLineColor)
{
	bool fileExist = FileUtils::getInstance()->isFileExist(fontName);
	pTarget->disableEffect();
	pTarget->setColor(Color3B::WHITE);
	if (fileExist) {
		TTFConfig ttfConfig(fontName.c_str(),fontSize,GlyphCollection::DYNAMIC);
		pTarget->setTTFConfig(ttfConfig);
		if (isOutLine) {
			pTarget->setTextColor(Color4B(color));
			pTarget->enableOutline(outLineColor,2);
		}else{
			pTarget->setColor(color);
		}

	}else{
		pTarget->setColor(color);
		pTarget->setSystemFontName(fontName);
		pTarget->setSystemFontSize(fontSize);
	}
	if (isUnder) {
		_underLineTags.insert(tag);
	}
	pTarget->setString(text);
	pTarget->setTag(tag);
	return pTarget;
}

Node* CTextRich::makeImage( Sprite* pTarget, const std::string& filePath,int tag,bool isAnim,float delay,bool isLoop )
{
	auto spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(filePath);
	if(spriteFrame && pTarget->isFrameDisplayed(spriteFrame) == false){
		pTarget->setSpriteFrame(spriteFrame);
	}else{
		pTarget->setTexture(filePath);
	}

	if (isAnim) {

		SpriteFrameCache *pCache = SpriteFrameCache::getInstance();
		Vector<SpriteFrame*> v;

		SpriteFrame *pFrame = NULL;
		int index = 1;
		char buf[128] = {0};
		do
		{
			sprintf(buf,"%s%d.png",filePath.c_str(),index++);
			pFrame = pCache->getSpriteFrameByName(buf);
			if(pFrame == NULL){
				break;
			}
			v.pushBack(pFrame);
		} while (true);

		Animation *pAnim = Animation::createWithSpriteFrames(v);
		pAnim->setLoops(isLoop?-1:0);
		pAnim->setRestoreOriginalFrame(true);
		pAnim->setDelayPerUnit(delay);
		pTarget->setContentSize(v.at(0)->getOriginalSize());
		pTarget->stopAllActions();
		pTarget->runAction(Animate::create(pAnim));
	}

	pTarget->setTag(tag);
	return pTarget;
}


CWidgetTouchModel CTextRich::onTouchBegan(Touch* pTouch)
{
	return eWidgetTouchTransient;
}

void CTextRich::onTouchMoved(Touch* pTouch, float fDuration)
{

}

void CTextRich::onTouchEnded(Touch* pTouch, float fDuration)
{
	unsigned int nCount = _children.size();
	Vec2 tPoint = _parent->convertTouchToNodeSpace(pTouch);
	if( getBoundingBox().containsPoint(tPoint) )
	{
		Vec2 tInsidePoint = convertTouchToNodeSpace(pTouch);

		for (int i = nCount - 1; i >= 0; --i)
		{
			Node* pNode = _children.at(i);
			if( pNode->getBoundingBox().containsPoint(tInsidePoint) )
			{
				executeTextRichClickHandler(this,pNode->getTag());
				return;
			}
		}
		executeTextRichClickHandler(this, NULL);
	}
}

void CTextRich::onTouchCancelled(Touch* pTouch, float fDuration)
{

}

//////////////////////////////////////////////////////////////////////////
vector< string > CTextRich::split(const std::string& s,const std::string& delim)
{
	std::vector< std::string > ret;
	size_t last = 0;
	size_t index=s.find_first_of(delim,last);
	while (index!=std::string::npos)
	{
		ret.push_back(s.substr(last,index-last));
		last=index+1;
		index=s.find_first_of(delim,last);
	}
	if (index-last>0)
	{
		ret.push_back(s.substr(last,index-last));
	}
	return ret;
}

std::string CTextRich::getSubStringOfUTF8String(const std::string& str, std::string::size_type start, std::string::size_type length)
{
	if (length==0)
	{
		return "";
	}
	std::string::size_type c, i, ix, q, min=std::string::npos, max=std::string::npos;
	for (q=0, i=0, ix=str.length(); i < ix; i++, q++)
	{
		if (q==start)
		{
			min = i;
		}
		if (q <= start+length || length==std::string::npos)
		{
			max = i;
		}

		c = (unsigned char) str[i];

		if      (c<=127) i+=0;
		else if ((c & 0xE0) == 0xC0) i+=1;
		else if ((c & 0xF0) == 0xE0) i+=2;
		else if ((c & 0xF8) == 0xF0) i+=3;
		else return "";//invalid utf8
	}
	if (q <= start+length || length == std::string::npos)
	{
		max = i;
	}
	if (min==std::string::npos || max==std::string::npos)
	{
		return "";
	}
	return str.substr(min,max);
}

NS_CC_WIDGET_END