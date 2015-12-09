/****************************************************************************
Copyright (c) 2015 Lingjijian

Created by Lingjijian on 2015

342854406@qq.com
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

bool RichElement::init(const Color3B &color, GLubyte opacity)
{
	_color = color;
	_opacity = opacity;
	return true;
}


RichElementText* RichElementText::create(const Color3B &color,const std::string& text, const std::string& fontName, float fontSize,bool isUnderLine,bool isOutLine,const Color4B& outLineColor,const char* data)
{
	RichElementText* element = new (std::nothrow) RichElementText();
	if (element && element->init(color, text, fontName, fontSize,isUnderLine,isOutLine,outLineColor,data))
	{
		element->autorelease();
		return element;
	}
	CC_SAFE_DELETE(element);
	return nullptr;
}

bool RichElementText::init(const Color3B &color, const std::string& text, const std::string& fontName, float fontSize,bool isUnderLine,bool isOutLine,const Color4B& outLineColor,const char* data)
{
	if (RichElement::init(color))
	{
		_text = text;
		_fontName = fontName;
		_fontSize = fontSize;
		_isUnderLine = isUnderLine;
		_isOutLine = isOutLine;
		_outLineColor = outLineColor;
        _data = data;
		return true;
	}
	return false;
}

RichElementImage* RichElementImage::create(const std::string& filePath,const char* data)
{
	RichElementImage* element = new (std::nothrow) RichElementImage();
	if (element && element->init( filePath,data))
	{
		element->autorelease();
		return element;
	}
	CC_SAFE_DELETE(element);
	return nullptr;
}

bool RichElementImage::init(const std::string& filePath,const char* data)
{
	if (RichElement::init())
	{
		_filePath = filePath;
        _data = data;
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

RichElementAnim* RichElementAnim::create(const std::string& filePath,bool isLoop,float delay,const char* data)
{
	RichElementAnim* element = new (std::nothrow) RichElementAnim();
	if (element && element->init(filePath,isLoop,delay,data))
	{
		element->autorelease();
		return element;
	}
	CC_SAFE_DELETE(element);
	return nullptr;
}

bool RichElementAnim::init(const std::string& filePath,bool isLoop,float delay,const char* data)
{
	if (RichElement::init())
	{
		_filePath = filePath;
		_isLoop = isLoop;
		_delay = delay;
        _data = data;
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
    _alignType(RichTextAlign::LEFT_TOP),
    _drawNode(nullptr),
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
        widget->setTouchEnabled(true);
		widget->autorelease();
		return widget;
	}
	CC_SAFE_DELETE(widget);
	return nullptr;
}

bool CTextRich::init()
{
    if (Node::init()) {
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

void CTextRich::insertElement(const char* pString, const char* pFontName, float fFontSize, const Color3B& tColor,bool isUnderLine,bool isOutLine,const Color4B& outLineColor,const char* data)
{
	_richElements.pushBack(RichElementText::create(tColor,pString,pFontName,fFontSize,isUnderLine,isOutLine,outLineColor,data));
}

void CTextRich::insertElement(const char* path,float delay,bool isLoop,const char* data )
{
	_richElements.pushBack(RichElementAnim::create(path,isLoop,delay,data));
}

void CTextRich::insertElement(const char* path,const char* data)
{
	_richElements.pushBack(RichElementImage::create(path,data));
}

void CTextRich::insertElement(int newline)
{
    _richElements.pushBack(RichElementNewline::create());
}

void CTextRich::reloadData()
{
	removeAllElements();
	
	for (auto& elem : _richElements)
	{
		if (elem->_type == Type::TEXT)
		{
			RichElementText* elemText = dynamic_cast<RichElementText*>(elem);
			std::vector<std::string> _charArr = CTextRich::separateUtf8(elemText->_text);
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
                rendElem.color = elemText->_color;

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
            rendElem.delay = elemAnim->_delay;
            rendElem.isLoop = elemAnim->_isLoop;
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
			elem.width = 0;
			elem.height = 27;
			elem.pos = Vec2(oneLine,-lines*27);

		}else{ // other elements

			if( oneLine + elem.width > _maxLineWidth )
			{
				if (elem._type == Type::TEXT)
				{
					if (CTextRich::isChinese(elem.strChar) || elem.strChar == " " )
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
        
        _elemRenderArr[i] = elem;
	}

	//sort all lines
	std::map< int, std::vector<RenderElement> > rendElemLineMap;
	std::set< int > linePosYSet;
	len = _elemRenderArr.size();
	for (int i=0;i<len;i++)
	{
		RenderElement elem = _elemRenderArr.at(i);
		auto it = rendElemLineMap.find(elem.pos.y);
		if(it == rendElemLineMap.end()) {
			rendElemLineMap[ elem.pos.y ] = std::vector<RenderElement>();
		}
		rendElemLineMap[ elem.pos.y ].push_back( elem );
		linePosYSet.insert( -1 * (elem.pos.y) );
	}
	// all lines in arr
	std::vector< std::vector<RenderElement> > rendLineArrs;
	std::set<int>::const_iterator it=linePosYSet.begin();
	for(; it!=linePosYSet.end(); ++it)
	{
		int posY = -1 * (*it);
		std::string oneLine = "";
		RenderElement _lastEleme = rendElemLineMap[posY][0];
		RenderElement _lastDiffStarEleme = rendElemLineMap[posY][0];
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
					
				}else if ( elem._type == Type::NEWLINE )
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
			// the last elementText
			if (_lastDiffStarEleme._type == Type::TEXT )
			{
				RenderElement _newElem = _lastDiffStarEleme.clone();
				_newElem.strChar = oneLine;
				_arr.push_back(_newElem);
			}
			rendLineArrs.push_back(_arr);
		}
	}

	// offset position
	int _offsetLineY = 0;
	_realLineHeight = 0;
    
    for (int i=0; i<rendLineArrs.size(); i++) {
        auto lines = rendLineArrs[i];
		int _lineHeight = 0;
        
        for(auto& elem : lines){
			_lineHeight = MAX( _lineHeight,elem.height );
		}
		_realLineHeight = _realLineHeight + _lineHeight;
		_offsetLineY = _offsetLineY + (_lineHeight - 27);
        
        for(int j=0;j<lines.size();j++)
		{
            auto elem = lines[j];
			elem.pos = Vec2(elem.pos.x,elem.pos.y - _offsetLineY);
            lines[j] = elem;
            _realLineHeight = MAX(_realLineHeight,abs(elem.pos.y));
		}
        rendLineArrs[i] = lines;
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
        setAnchorPoint(Vec2(0.5,0.5));
        setContentSize(Size(getMaxLineWidth(),getRealLineHeight()) );
		
	}else if (_alignType == RichTextAlign::REAL_CENTER)
	{
        setAnchorPoint(Vec2(0.5,0.5));
		setContentSize(Size(getRealLineWidth(),getRealLineHeight()) );
		
	}else if (_alignType == RichTextAlign::LEFT_TOP)
	{
        setAnchorPoint(Vec2(0,1));
		setContentSize(Size(getRealLineWidth(),getRealLineHeight()) );
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
    pTarget->setTTFConfig(config);
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


std::vector< std::string > CTextRich::separateUtf8( const std::string & sin )
{
    int l = sin.length();
    std::vector<std::string> ret;
    ret.clear();
    for(int p = 0; p < l; ) {
        int size, n = l - p;
        unsigned char c = sin[p], cc = sin[p + 1];
        if(c < 0x80) {
            size = 1;
        } else if(c < 0xc2) {
            return ret;
        } else if(c < 0xe0) {
            if(n < 2) {
                return ret;
            }
            if(!((sin[p + 1] ^ 0x80) < 0x40)) {
                return ret;
            }
            size = 2;
        } else if(c < 0xf0) {
            if(n < 3) {
                return ret;
            }
            if(!((sin[p + 1] ^ 0x80) < 0x40 &&
                 (sin[p + 2] ^ 0x80) < 0x40 &&
                 (c >= 0xe1 || cc >= 0xa0))) {
                return ret;
            }
            size = 3;
        } else if(c < 0xf8) {
            if(n < 4) {
                return ret;
            }
            if(!((sin[p + 1] ^ 0x80) < 0x40 &&
                 (sin[p + 2] ^ 0x80) < 0x40 &&
                 (sin[p + 3] ^ 0x80) < 0x40 &&
                 (c >= 0xf1 || cc >= 0x90))) {
                return ret;
            }
            size = 4;
        } else if (c < 0xfc) {
            if(n < 5) {
                return ret;
            }
            if(!((sin[p + 1] ^ 0x80) < 0x40 &&
                 (sin[p + 2] ^ 0x80) < 0x40 &&
                 (sin[p + 3] ^ 0x80) < 0x40 &&
                 (sin[p + 4] ^ 0x80) < 0x40 &&
                 (c >= 0xfd || cc >= 0x88))) {
                return ret;
            }
            size = 5;
        } else if (c < 0xfe) {
            if(n < 6) {
                return ret;
            }
            if(!((sin[p + 1] ^ 0x80) < 0x40 &&
                 (sin[p + 2] ^ 0x80) < 0x40 &&
                 (sin[p + 3] ^ 0x80) < 0x40 &&
                 (sin[p + 4] ^ 0x80) < 0x40 &&
                 (sin[p + 5] ^ 0x80) < 0x40 &&
                 (c >= 0xfd || cc >= 0x84))) {
                return ret;
            }
            size = 6;
        } else {
            return ret;
        }
        std::string temp = "";
        temp = sin.substr(p, size);
        ret.push_back(temp);
        p += size;
    }
    return ret;
}

bool CTextRich::isChinese(const std::string &inStr)
{
    unsigned char *str = (unsigned char *)inStr.c_str();
    size_t length = inStr.length();
    for (size_t i=0; i< length; ++i)
    {
        if (str[i] > 160)
        {
            return true;
        }
    }
    return false;
}

NS_CC_WIDGET_END
