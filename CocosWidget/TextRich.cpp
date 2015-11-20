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
#include "tui/TuiUtil.h"
using namespace std;

NS_CC_WIDGET_BEGIN

bool RichElement::init(const Color3B &color, GLubyte opacity)
{
	_color = color;
	_opacity = opacity;
	return true;
}


RichElementText* RichElementText::create(const Color3B &color,const std::string& text, const std::string& fontName, float fontSize,bool isUnderLine,bool isOutLine,const Color4B& outLineColor)
{
	RichElementText* element = new (std::nothrow) RichElementText();
	if (element && element->init(color, text, fontName, fontSize,isUnderLine,isOutLine,outLineColor))
	{
		element->autorelease();
		return element;
	}
	CC_SAFE_DELETE(element);
	return nullptr;
}

bool RichElementText::init(const Color3B &color, const std::string& text, const std::string& fontName, float fontSize,bool isUnderLine,bool isOutLine,const Color4B& outLineColor)
{
	if (RichElement::init(color))
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

RichElementImage* RichElementImage::create(const std::string& filePath)
{
	RichElementImage* element = new (std::nothrow) RichElementImage();
	if (element && element->init( filePath))
	{
		element->autorelease();
		return element;
	}
	CC_SAFE_DELETE(element);
	return nullptr;
}

bool RichElementImage::init(const std::string& filePath)
{
	if (RichElement::init())
	{
		_filePath = filePath;
		return true;
	}
	return false;
}

RichElementNewline* RichElementNewline::create()
{
	RichElementNewline* element = new (std::nothrow) RichElementNewline();
	if (element && element->init())
	{
		element->autorelease();
		return element;
	}
	CC_SAFE_DELETE(element);
	return nullptr;
}

bool RichElementNewline::init()
{
	if (RichElement::init())
	{
		return true;
	}
	return false;
}

RichElementAnim* RichElementAnim::create(const std::string& filePath,bool isLoop,float delay)
{
	RichElementAnim* element = new (std::nothrow) RichElementAnim();
	if (element && element->init(filePath,isLoop,delay))
	{
		element->autorelease();
		return element;
	}
	CC_SAFE_DELETE(element);
	return nullptr;
}

bool RichElementAnim::init(const std::string& filePath,bool isLoop,float delay)
{
	if (RichElement::init())
	{
		_filePath = filePath;
		_isLoop = isLoop;
		_delay = delay;
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
	_verticalSpace(0.0f),
	_maxLineWidth(300),
	_mesureLabel(nullptr),
	_mesureSprite(nullptr)
{
}

CTextRich::~CTextRich()
{
	_richElements.clear();
	_elemRenderArr.clear();
	_cacheLabElements.clear();
	_cacheImgElements.clear();
	CC_SAFE_RELEASE(_mesureSprite);
	CC_SAFE_RELEASE(_mesureLabel);
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
	if(_drawNode) _drawNode->clear();
	_elemRenderArr.clear();
}

void CTextRich::insertElement(const char* pString, const char* pFontName /* = NULL */, float fFontSize /* = 0.0f */, const Color3B& tColor /* = Color3B::WHITE */,bool isUnderLine /* = false */,bool isOutLine /* = false */,const Color4B& outLineColor/* =Color4B::WHITE */)
{
	_richElements.pushBack(RichElementText::create(tColor,pString,pFontName,fFontSize,isUnderLine,isOutLine,outLineColor));
}

void CTextRich::insertElement(const char* path,float delay,bool isLoop )
{
	_richElements.pushBack(RichElementAnim::create(path,isLoop,delay));
}

void CTextRich::insertElement(const char* path )
{
	_richElements.pushBack(RichElementImage::create(path));
}

void CTextRich::reloadData()
{
	removeAllElements();
	
	for (auto& elem : _richElements)
	{
		if (elem->_type == Type::TEXT)
		{
			RichElementText* elemText = dynamic_cast<RichElementText*>(elem);
			std::vector<std::string> _charArr = tui::TuiUtil::separateUtf8(elemText->_text);
			for (std::vector<std::string>::iterator iter = _charArr.begin(); iter != _charArr.end(); iter++)
			{
				RenderElement rendElem;
				rendElem._type = Type::TEXT;
				rendElem.strChar = (*iter);
				rendElem.isOutLine = elemText->_isOutLine;
				rendElem.isUnderLine = elemText->_isUnderLine;
				rendElem.fontSize = elemText->_fontSize;
				rendElem.fontName = elemText->_fontName;
				rendElem.data = elemText->_data;

				Label* lab = this->_getMesureLabel();
				this->makeLabel(lab,rendElem,(*iter));
				Size size = lab->getContentSize();
				rendElem.width = size.width;
				rendElem.height = size.height;
				_elemRenderArr.push_back( rendElem );
			}

		}else if(elem->_type == Type::IMAGE ){

			RichElementImage* elemImg = dynamic_cast<RichElementImage*>(elem);
			Size size = this->_getMesureSpriteContentSize(elemImg->_filePath);
			RenderElement rendElem;
			rendElem._type = Type::IMAGE;
			rendElem.img = elemImg->_filePath;
			rendElem.width = size.width;
			rendElem.height = size.height;
			rendElem.data = elemImg->_data;

			_elemRenderArr.push_back( rendElem );

		}else if (elem->_type == Type::ANIM)
		{
			RichElementAnim* elemAnim = dynamic_cast<RichElementAnim*>(elem);
			Size size = this->_getMesureSpriteContentSize(elemAnim->_filePath + std::string("1.png"));
			RenderElement rendElem;
			rendElem._type = Type::ANIM;
			rendElem.anim = elemAnim->_filePath;
			rendElem.width = size.width;
			rendElem.height = size.height;
			rendElem.data = elemAnim->_data;

			_elemRenderArr.push_back( rendElem );

		}else if(elem->_type == Type::NEWLINE ){

			RenderElement rendElem;
			rendElem.isNewLine = true;
			_elemRenderArr.push_back( rendElem );
		}
	}

	formarRenderers();
}

void CTextRich::formarRenderers()
{
	int charWidth = 0;
	int oneLine = 0;
	int lines = 1;
	int len = _elemRenderArr.size();
	for (int i=0;i<len;i++)
	{
		RenderElement elem = _elemRenderArr[i];

		if (elem.isNewLine){ //new line

			oneLine = 0;
			lines++;

		}else{ // other elements

			if( oneLine + elem.width > _maxLineWidth )
			{
				if (elem._type == Type::TEXT)
				{
					if (tui::TuiUtil::isChinese(elem.strChar) || elem.strChar == " " )
					{
						oneLine = 0;
						lines++;

						elem.pos = Vec2( oneLine,-lines * 27 );
						oneLine = elem.width;
					} else { // en

						int spaceIdx = 0;
						int idx = i;
						while( idx > 0) {
							idx = idx - 1;
							if ( _elemRenderArr.at(idx).strChar == " " )
							{
								spaceIdx = idx;
								break;
							}
						}
						// can't find space , force new line
						if (spaceIdx == 0){
							oneLine = 0;
							lines++;
							elem.pos = Vec2( oneLine,-lines * 27 );

							oneLine = elem.width;
						} else {

							oneLine = 0;
							lines++;

							for (int _i = spaceIdx + 1; _i <= i; ++_i)
							{
								RenderElement _elem = _elemRenderArr.at(_i);
								_elem.pos = Vec2( oneLine,-lines * 27 );
								oneLine += elem.width;
							}

						}
					}
				}else if (elem.img != "" || elem.anim != "" ) {
					lines++;
					elem.pos = Vec2( 0,-lines * 27 );
					oneLine = elem.width;
				}

			}else{
				elem.pos = Vec2( oneLine,-lines * 27 );
				oneLine += elem.width;
			}
		}
	}

	//sort all lines
	std::map< int, std::vector<RenderElement> > rendElemLineMap;
	std::set< int > linePosYSet;
	len = _elemRenderArr.size();
	for (int i=0;i<len;i++)
	{
		RenderElement elem = _elemRenderArr.at(i);
		if ( !elem.isNewLine ){
			
			auto it = rendElemLineMap.find(elem.pos.y);
			if(it == rendElemLineMap.end()) {
				rendElemLineMap[ elem.pos.y ] = std::vector<RenderElement>();
			}
			rendElemLineMap[ elem.pos.y ].push_back( elem );
			linePosYSet.insert( elem.pos.y );
		}
	}
	// all lines in arr
	std::vector< std::vector<RenderElement> > rendLineArrs;
	std::set<int>::const_iterator it=linePosYSet.begin();
	for(; it!=linePosYSet.end(); ++it)
	{
		int posY = (*it);
		std::string oneLine = "";
		RenderElement _lastEleme = rendElemLineMap[posY][1];
		RenderElement _lastDiffStarEleme = rendElemLineMap[posY][1];
		if( rendElemLineMap[posY].size() > 0 )
		{
			std::vector<RenderElement> _arr;

			for(auto& elem : rendElemLineMap[posY])
			{
				if( _lastEleme._type == Type::TEXT && elem._type == Type::TEXT )
				{
					if (_lastEleme.color == elem.color)
					{
						// the same color can mergin one string
						oneLine += elem.strChar;
					}else{
						// diff color
						if (_lastDiffStarEleme._type == Type::TEXT)
						{
							RenderElement _newElem = _lastDiffStarEleme.clone();
							_newElem.strChar = oneLine;
							_arr.push_back(_newElem);

							_lastDiffStarEleme = elem;
							oneLine = elem.strChar;
						}
					}
				}else if( elem._type == Type::IMAGE )
				{
					//interrupt
					if (_lastDiffStarEleme._type == Type::TEXT )
					{
						RenderElement _newElem = _lastDiffStarEleme.clone();
						_newElem.strChar = oneLine;
						oneLine = "";
						_arr.push_back(_newElem);
					}
					_arr.push_back(elem);

				}else if ( elem._type == Type::ANIM )
				{
					//interrupt
					if (_lastDiffStarEleme._type == Type::TEXT )
					{
						RenderElement _newElem = _lastDiffStarEleme.clone();
						_newElem.strChar = oneLine;
						oneLine = "";
						_arr.push_back(_newElem);
					}
					_arr.push_back(elem);

				}else if ( _lastEleme._type != Type::TEXT )
				{
					//interrupt
					_lastDiffStarEleme = elem;
					if ( elem._type == Type::TEXT )
					{
						oneLine = elem.strChar;
					}
				}
				_lastEleme = elem;
			}
			RenderElement _newElem = _lastDiffStarEleme.clone();
			_newElem.strChar = oneLine;
			_arr.push_back(_newElem);
			rendLineArrs.push_back(_arr);
		}
	}

	// offset position
	int _offsetLineY = 0;
	_realLineHeight = 0;
	for(auto& lines : rendLineArrs)
	{
		int _lineHeight = 0;
		for(auto& elem : lines)
		{
			_lineHeight = MAX( _lineHeight,elem.height );
		}
		_realLineHeight = _realLineHeight + _lineHeight;
		_offsetLineY = _offsetLineY + (_lineHeight - 27);
		for(auto& elem : lines)
		{
			elem.pos.y = elem.pos.y - _offsetLineY;
		}
	}

	//place all position
	_realLineWidth = 0;
	Node* _obj = nullptr;
	for(auto& lines : rendLineArrs)
	{
		int _lineWidth = 0;
		for(auto& elem : lines)
		{
			if ( elem._type == Type::TEXT )
			{
				_obj = getCacheLabel();
				makeLabel((Label*)_obj,elem,elem.strChar);
				_lineWidth += _obj->getContentSize().width;
			}else if (elem._type == Type::IMAGE){
				_obj = getCacheImage();
				makeImage((Sprite*)_obj,elem);
				_lineWidth += _obj->getContentSize().width;
			}else if (elem._type == Type::ANIM){
				_obj = getCacheImage();
				makeAnim((Sprite*)_obj,elem);
				_lineWidth += elem.width;
			}
			this->addChild(_obj);
			_obj->setPosition(Vec2(elem.pos.x,elem.pos.y + _realLineHeight));
		}
		_realLineWidth = MAX(_lineWidth,_realLineWidth);
	}

	// align
	if (_alignType == RichTextAlign::DESIGN_CENTER)
	{
		this->setContentSize(Size(getMaxLineWidth()/2,getRealLineHeight()/2) );
		this->setAnchorPoint(Vec2(0.5,0.5));
	}else if (_alignType == RichTextAlign::REAL_CENTER)
	{
		this->setContentSize(Size(getRealLineWidth()/2,getRealLineHeight()/2) );
		this->setAnchorPoint(Vec2(0.5,0.5));
	}else if (_alignType == RichTextAlign::LEFT_TOP)
	{
		this->setContentSize(Size(getRealLineWidth()/2,getRealLineHeight()/2) );
		this->setAnchorPoint(Vec2(0,1));
	}
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
		ret->setAnchorPoint(Vec2::ZERO);
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
		ret->setAnchorPoint(Vec2::ZERO);
		_cacheImgElements.pushBack(RichCacheElement::create(true,ret));
	}
	return ret;
}

DrawNode* CTextRich::_getDrawNode()
{
	if (_drawNode == nullptr)
	{
		_drawNode = DrawNode::create();
		this->addChild(_drawNode);
	}
	return _drawNode;
}

Label* CTextRich::makeLabel( Label* pTarget,RenderElement elem ,std::string strChar)
{

	TTFConfig config;
	config.fontFilePath = elem.fontName;
	config.fontSize = elem.fontSize;
	
	pTarget->disableEffect();
	if (elem.isOutLine)
	{
		pTarget->setTextColor(Color4B(elem.color));
		pTarget->enableShadow(Color4B(0,0,0,255),Size(1,-1));
	}else{
		pTarget->setTextColor(Color4B(elem.color));
	}
	pTarget->setString(strChar);
	if (elem.isUnderLine)
	{
		_getDrawNode()->drawLine(Vec2(elem.pos.x,elem.pos.y + _realLineHeight),
			Vec2(elem.pos.x + pTarget->getContentSize().width,elem.pos.y + _realLineHeight),
			Color4F(1,1,1,1));
	}
	pTarget->setUserData(  elem.data != "" ?  new std::string(elem.data) : nullptr );
	return pTarget;
}

Sprite* CTextRich::makeImage( Sprite* pTarget,RenderElement elem )
{
	pTarget->stopAllActions();
	auto spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(elem.img);
	if(spriteFrame && pTarget->isFrameDisplayed(spriteFrame) == false){
		pTarget->setSpriteFrame(spriteFrame);
	}else{
		pTarget->setTexture(elem.img);
	}
	pTarget->setUserData(  elem.data != "" ?  new std::string(elem.data) : nullptr );
	return pTarget;
}

Sprite* CTextRich::makeAnim( Sprite* pTarget,RenderElement elem )
{
	SpriteFrameCache *pCache = SpriteFrameCache::getInstance();
	Vector<SpriteFrame*> v;

	SpriteFrame *pFrame = NULL;
	int index = 1;
	char buf[128] = {0};
	do
	{
		sprintf(buf,"%s%d.png",elem.anim.c_str(),index++);
		pFrame = pCache->getSpriteFrameByName(buf);
		if(pFrame == NULL){
			break;
		}
		v.pushBack(pFrame);
	} while (true);

	Animation *pAnim = Animation::createWithSpriteFrames(v);
	pAnim->setLoops(elem.isLoop?-1:0);
	pAnim->setRestoreOriginalFrame(true);
	pAnim->setDelayPerUnit(elem.delay);
	pTarget->setContentSize(v.at(0)->getOriginalSize());
	pTarget->stopAllActions();
	pTarget->runAction(Animate::create(pAnim));
	pTarget->setUserData(  elem.data != "" ?  new std::string(elem.data) : nullptr );
    return pTarget;
}

CWidgetTouchModel CTextRich::onTouchBegan(Touch* pTouch)
{
	return eWidgetTouchTransient;
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
				std::string *data = static_cast<std::string*>( pNode->getUserData() );
				if(data != nullptr)
					executeTextRichClickHandler(pNode,(*data).c_str());
				return;
			}
		}
		executeTextRichClickHandler(this, NULL);
	}
}

Label* CTextRich::_getMesureLabel()
{
	if (_mesureLabel == nullptr){
		_mesureLabel = Label::create();
		_mesureLabel->retain();
	}
	return _mesureLabel;
}

Size CTextRich::_getMesureSpriteContentSize(const std::string& path)
{
	if (_mesureSprite == nullptr)
	{
		_mesureSprite = Sprite::create();
		_mesureSprite->retain();
	}

	SpriteFrameCache *cache = SpriteFrameCache::getInstance();
	SpriteFrame *spriteFrame = cache->getSpriteFrameByName(path);
	if (spriteFrame)
	{
		_mesureSprite->setSpriteFrame(spriteFrame);
		return _mesureSprite->getContentSize();
	}else{
		CCLOG("miss SpriteFrame: ",path.c_str());
		return Size();
	}
}


NS_CC_WIDGET_END
