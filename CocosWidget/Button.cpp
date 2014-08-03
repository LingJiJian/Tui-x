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
#include "Button.h"

NS_CC_WIDGET_BEGIN

#define CC_CENTER_POS(__SIZE__) Point(__SIZE__.width / 2, __SIZE__.height / 2)
#define CC_SAFE_SET_VISIBLE(__ITEM__, __VAR__) if( __ITEM__ ) __ITEM__->setVisible(__VAR__)
#define CC_SAFE_REMOVE(__ITEM__) if(__ITEM__) removeChild(__ITEM__)
#define CC_SAFE_REMOVE_9ELSE(__ITEM__) if(__ITEM__ && !(dynamic_cast<CScale9Sprite*>(__ITEM__))) removeChild(__ITEM__)
#define CC_SAFE_REMOVE_9SPRITE(__ITEM__) if(__ITEM__ && dynamic_cast<CScale9Sprite*>(__ITEM__)) removeChild(__ITEM__)
#define CC_IS_9SPRITE(__ITEM__) __ITEM__ && dynamic_cast<CScale9Sprite*>(__ITEM__) ? true : false


CButton::CButton()
: m_pNormalImage(NULL)
, m_pDisabledImage(NULL)
, m_pSelectedImage(NULL)
, m_bScale9Enabled(false)
, m_tTextOffset(Vec2::ZERO)
, m_pLabel(NULL)
, m_bCascadeTextSizeEnabled(false)
{
	setThisObject(this);
	setCascadeOpacityEnabled(true);

	setAnchorPoint(CCWIDGET_BASIC_DEFAULT_ANCHOR_POINT);
	setContentSize(CCWIDGET_BASIC_DEFAULT_CONTENT_SIZE);
}

CButton::~CButton()
{
}

CButton* CButton::create()
{
	CButton* pRet = new CButton();
	if( pRet && pRet->init() )
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

CButton* CButton::createWith9Sprite(const Size& tSize, const char* pNormal, const char* pSelected, const char* pDisabled)
{
	CButton* pRet = new CButton();
	if( pRet && pRet->initWith9Sprite(tSize, pNormal, pSelected, pDisabled) )
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

CButton* CButton::create(const char* pNormal, const char* pSelected, const char* pDisabled)
{
	CButton* pRet = new CButton();
	if( pRet && pRet->initWithFile(pNormal, pSelected, pDisabled) )
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

CButton* CButton::createWith9SpriteFrameName(const Size& tSize, const char* pNormal, const char* pSelected, const char* pDisabled)
{
	CButton* pRet = new CButton();
	if (pRet && pRet->initWith9SpriteFrameName(tSize, pNormal, pSelected, pDisabled))
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

bool CButton::init()
{
	setAnchorPoint(CCWIDGET_BASIC_DEFAULT_ANCHOR_POINT);
	setContentSize(CCWIDGET_BASIC_DEFAULT_CONTENT_SIZE);

	return true;
}

bool CButton::initWith9Sprite(const Size& tSize, const char* pNormal, const char* pSelected, const char* pDisabled)
{
	if( !pNormal || !strlen(pNormal) || !init() )
	{
		return false;
	}

	setScale9Enabled(true);
	setContentSize(tSize);
	setNormalImage(pNormal);
	setSelectedImage(pSelected);
	setDisabledImage(pDisabled);

	return true;
}

bool CButton::initWith9SpriteFrameName(const Size& tSize, const char* pNormal, const char* pSelected, const char* pDisabled)
{
	if (!pNormal || !strlen(pNormal) || !init())
	{
		return false;
	}

	setScale9Enabled(true);
	setContentSize(tSize);
	setNormalSpriteFrameName(pNormal);
	setSelectedSpriteFrameName(pSelected);
	setDisabledSpriteFrameName(pDisabled);

	return true;
}

bool CButton::initWithFile(const char* pNormal, const char* pSelected, const char* pDisabled)
{
	if( !pNormal || !strlen(pNormal) || !init() )
	{
		return false;
	}

	setScale9Enabled(false);
	setNormalImage(pNormal);
	setSelectedImage(pSelected);
	setDisabledImage(pDisabled);

	return true;
}

void CButton::setCascadeTextSizeEnabled(bool bEnabled, const Size& tPadding)
{
	m_bCascadeTextSizeEnabled = bEnabled;
	m_tCascadeTextSizePadding = tPadding;

	if( bEnabled ) updateCascadeTextSize();
}

void CButton::updateCascadeTextSize()
{
	if( m_bCascadeTextSizeEnabled && m_bScale9Enabled && m_pLabel )
	{
		const Size& tTextSize = m_pLabel->getContentSize();
		setContentSize(tTextSize + m_tCascadeTextSizePadding);
	}
}

void CButton::setNormalSpriteFrame(SpriteFrame* pFrame)
{
	if( pFrame )
	{
		if( m_pNormalImage )
		{
			if( m_bScale9Enabled )
			{
				CScale9Sprite* pImage = (CScale9Sprite*) m_pNormalImage;
				pImage->initWithSpriteFrame(pFrame);
				pImage->setContentSize(_contentSize);
			}
			else
			{
				Sprite* pImage = (Sprite*) m_pNormalImage;
				pImage->setSpriteFrame(pFrame);
				setContentSize(pImage->getContentSize());
			}
		}
		else
		{
			if( m_bScale9Enabled )
			{
				m_pNormalImage = CScale9Sprite::createWithSpriteFrame(pFrame);
				m_pNormalImage->setContentSize(_contentSize);
			}
			else
			{
				m_pNormalImage = Sprite::createWithSpriteFrame(pFrame);
				setContentSize(m_pNormalImage->getContentSize());
			}

			m_pNormalImage->setPosition(Vec2(_contentSize.width/2, _contentSize.height/2));
			addChild(m_pNormalImage);
		}
	}

	updateCascadeTextSize();
}

void CButton::setSelectedSpriteFrame(SpriteFrame* pFrame)
{
	if( pFrame )
	{
		if( m_pSelectedImage )
		{
			if( m_bScale9Enabled )
			{
				CScale9Sprite* pImage = (CScale9Sprite*) m_pSelectedImage;
				pImage->initWithSpriteFrame(pFrame);
				pImage->setContentSize(_contentSize);
			}
			else
			{
				Sprite* pImage = (Sprite*) m_pSelectedImage;
				pImage->setSpriteFrame(pFrame);
			}
		}
		else
		{
			if( m_bScale9Enabled )
			{
				m_pSelectedImage = CScale9Sprite::createWithSpriteFrame(pFrame);
				m_pSelectedImage->setContentSize(_contentSize);
			}
			else
			{
				m_pSelectedImage = Sprite::createWithSpriteFrame(pFrame);
			}

			m_pSelectedImage->setPosition(Vec2(_contentSize.width/2, _contentSize.height/2));
			m_pSelectedImage->setVisible(false);
			addChild(m_pSelectedImage);
		}
	}

	updateCascadeTextSize();
}

void CButton::setDisabledSpriteFrame(SpriteFrame* pFrame)
{
	if( pFrame )
	{
		if( m_pDisabledImage )
		{
			if( m_bScale9Enabled )
			{
				CScale9Sprite* pImage = (CScale9Sprite*) m_pDisabledImage;
				pImage->initWithSpriteFrame(pFrame);
				pImage->setContentSize(_contentSize);
			}
			else
			{
				Sprite* pImage = (Sprite*) m_pDisabledImage;
				pImage->setSpriteFrame(pFrame);
			}
		}
		else
		{
			if( m_bScale9Enabled )
			{
				m_pDisabledImage = CScale9Sprite::createWithSpriteFrame(pFrame);
				m_pDisabledImage->setContentSize(_contentSize);
			}
			else
			{
				m_pDisabledImage = Sprite::createWithSpriteFrame(pFrame);
			}

			m_pDisabledImage->setPosition(Vec2(_contentSize.width/2, _contentSize.height/2));
			m_pDisabledImage->setVisible(false);
			addChild(m_pDisabledImage);
		}
	}

	updateCascadeTextSize();
}

void CButton::setNormalImage(const char* pFile)
{
	if( pFile && strlen(pFile) )
	{
		Texture2D* pTexture = Director::getInstance()->getTextureCache()->addImage(pFile);
		setNormalTexture(pTexture);
	}
}

void CButton::setSelectedImage(const char* pFile)
{
	if( pFile && strlen(pFile) )
	{
		Texture2D* pTexture = Director::getInstance()->getTextureCache()->addImage(pFile);
		setSelectedTexture(pTexture);
	}
}

void CButton::setDisabledImage(const char* pFile)
{
	if( pFile && strlen(pFile) )
	{
		Texture2D* pTexture = Director::getInstance()->getTextureCache()->addImage(pFile);
		setDisabledTexture(pTexture);
	}
}

void CButton::setNormalTexture(Texture2D *pTexture)
{
	if( pTexture )
	{
		if( m_pNormalImage )
		{
			if( m_bScale9Enabled )
			{
				CScale9Sprite* pImage = (CScale9Sprite*) m_pNormalImage;
				pImage->setTexture(pTexture);
				pImage->setContentSize(_contentSize);
			}
			else
			{
				Rect rect = Rect::ZERO;
				rect.size = pTexture->getContentSize();
				Sprite* pImage = (Sprite*) m_pNormalImage;
				pImage->setTexture(pTexture);
				pImage->setTextureRect(rect);
				setContentSize(pTexture->getContentSize());
			}
		}
		else
		{
			if( m_bScale9Enabled )
			{
				m_pNormalImage = CScale9Sprite::createWithTexture(pTexture);
				m_pNormalImage->setContentSize(_contentSize);
			}
			else
			{
				Rect rect;
				rect.origin = Vec2::ZERO;
				rect.size = pTexture->getContentSize();
				m_pNormalImage = Sprite::createWithTexture(pTexture);
				setContentSize(pTexture->getContentSize());
			}

			m_pNormalImage->setPosition(Vec2(_contentSize.width/2, _contentSize.height/2));
			addChild(m_pNormalImage);
		}
	}

	updateCascadeTextSize();
}

void CButton::setSelectedTexture(Texture2D *pTexture)
{
	if( pTexture )
	{
		if( m_pSelectedImage )
		{
			if( m_bScale9Enabled )
			{
				CScale9Sprite* pImage = (CScale9Sprite*) m_pSelectedImage;
				pImage->setTexture(pTexture);
				pImage->setContentSize(_contentSize);
			}
			else
			{
				Rect rect = Rect::ZERO;
				rect.size = pTexture->getContentSize();
				Sprite* pImage = (Sprite*) m_pSelectedImage;
				pImage->setTexture(pTexture);
				pImage->setTextureRect(rect);
			}
		}
		else
		{
			if( m_bScale9Enabled )
			{
				m_pSelectedImage = CScale9Sprite::createWithTexture(pTexture);
				m_pSelectedImage->setContentSize(_contentSize);
			}
			else
			{
				Rect rect;
				rect.origin = Vec2::ZERO;
				rect.size = pTexture->getContentSize();
				m_pSelectedImage = Sprite::createWithTexture(pTexture);
			}

			m_pSelectedImage->setPosition(Vec2(_contentSize.width/2, _contentSize.height/2));
			m_pSelectedImage->setVisible(false);
			addChild(m_pSelectedImage);
		}
	}

	updateCascadeTextSize();
}

void CButton::setDisabledTexture(Texture2D *pTexture)
{
	if( pTexture )
	{
		if( m_pDisabledImage )
		{
			if( m_bScale9Enabled )
			{
				CScale9Sprite* pImage = (CScale9Sprite*) m_pDisabledImage;
				pImage->setTexture(pTexture);
				pImage->setContentSize(_contentSize);
			}
			else
			{
				Rect rect = Rect::ZERO;
				rect.size = pTexture->getContentSize();
				Sprite* pImage = (Sprite*) m_pDisabledImage;
				pImage->setTexture(pTexture);
				pImage->setTextureRect(rect);
			}
		}
		else
		{
			if( m_bScale9Enabled )
			{
				m_pDisabledImage = CScale9Sprite::createWithTexture(pTexture);
				m_pDisabledImage->setContentSize(_contentSize);
			}
			else
			{
				Rect rect;
				rect.origin = Vec2::ZERO;
				rect.size = pTexture->getContentSize();
				m_pDisabledImage = Sprite::createWithTexture(pTexture);
			}

			m_pDisabledImage->setPosition(Vec2(_contentSize.width/2, _contentSize.height/2));
			m_pDisabledImage->setVisible(false);
			addChild(m_pDisabledImage);
		}
	}

	updateCascadeTextSize();
}

void CButton::setNormalSpriteFrameName(const char* pSpriteName)
{
	SpriteFrame *pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(pSpriteName);

#if COCOS2D_DEBUG > 0
	char msg[256] = {0};
	sprintf(msg, "Invalid spriteFrameName: %s", pSpriteName);
	CCAssert(pFrame != NULL, msg);
#endif

	return setNormalSpriteFrame(pFrame);
}

void CButton::setSelectedSpriteFrameName(const char* pSpriteName)
{
	SpriteFrame *pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(pSpriteName);

#if COCOS2D_DEBUG > 0
	char msg[256] = {0};
	sprintf(msg, "Invalid spriteFrameName: %s", pSpriteName);
	CCAssert(pFrame != NULL, msg);
#endif

	return setSelectedSpriteFrame(pFrame);
}

void CButton::setDisabledSpriteFrameName(const char* pSpriteName)
{
	SpriteFrame *pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(pSpriteName);

#if COCOS2D_DEBUG > 0
	char msg[256] = {0};
	sprintf(msg, "Invalid spriteFrameName: %s", pSpriteName);
	CCAssert(pFrame != NULL, msg);
#endif

	return setDisabledSpriteFrame(pFrame);
}

Node* CButton::getNormalImage()
{
	return m_pNormalImage;
}

Node* CButton::getSelectedImage()
{
	return m_pSelectedImage;
}

Node* CButton::getDisabledImage()
{
	return m_pDisabledImage;
}

void CButton::setContentSize(const Size& contentSize)
{
	Node::setContentSize(contentSize);

	if( m_pNormalImage )
	{
		if( CC_IS_9SPRITE(m_pNormalImage) )
		{
			m_pNormalImage->setContentSize(_contentSize);
		}
		m_pNormalImage->setPosition(CC_CENTER_POS(_contentSize));
	}

	if( m_pSelectedImage )
	{
		if( CC_IS_9SPRITE(m_pSelectedImage) )
		{
			m_pSelectedImage->setContentSize(_contentSize);
		}
		m_pSelectedImage->setPosition(CC_CENTER_POS(_contentSize));
	}

	if( m_pDisabledImage )
	{
		if( CC_IS_9SPRITE(m_pDisabledImage) )
		{
			m_pDisabledImage->setContentSize(_contentSize);
		}
		m_pDisabledImage->setPosition(CC_CENTER_POS(_contentSize));
	}

	if( m_pLabel )
	{
		m_pLabel->setPosition(CC_CENTER_POS(_contentSize) + m_tTextOffset);
	}
}

void CButton::setText(const char* pText)
{
	getLabel()->setString(pText);
	updateCascadeTextSize();
}

const char* CButton::getText()
{
	return getLabel()->getString().c_str();
}

void CButton::initText(const std::string& text, const std::string& fontFile, float fontSize,
					   const Size& dimensions,const Color3B &color)
{
	TTFConfig ttfConfig(fontFile.c_str(),fontSize,GlyphCollection::DYNAMIC);
	getLabel()->setTTFConfig(ttfConfig);
	getLabel()->setString(text);
	getLabel()->setColor(color);
	getLabel()->setDimensions(dimensions.width,dimensions.height);
	updateCascadeTextSize();
}

CLabel* CButton::getLabel()
{
	if(!m_pLabel)
	{
		m_pLabel = CLabel::create();
		m_pLabel->setPosition(CC_CENTER_POS(_contentSize));
		m_pLabel->setLocalZOrder(1);
		addChild(m_pLabel);
	}
	return m_pLabel;
}

bool CButton::isScale9Enabled()
{
	return m_bScale9Enabled;
}

void CButton::setScale9Enabled(bool bEnabled)
{
	if( m_bScale9Enabled != bEnabled )
	{
		if( bEnabled )
		{
			CC_SAFE_REMOVE_9ELSE(m_pNormalImage);
			CC_SAFE_REMOVE_9ELSE(m_pSelectedImage);
			CC_SAFE_REMOVE_9ELSE(m_pDisabledImage);
		}
		else
		{
			CC_SAFE_REMOVE_9SPRITE(m_pNormalImage);
			CC_SAFE_REMOVE_9SPRITE(m_pSelectedImage);
			CC_SAFE_REMOVE_9SPRITE(m_pDisabledImage);
		}
		m_bScale9Enabled = bEnabled;
	}
}

void CButton::setEnabled(bool bEnabled)
{
	if( m_bEnabled != bEnabled )
	{
		m_bEnabled = bEnabled;
		if( bEnabled )
		{
			CC_SAFE_SET_VISIBLE(m_pNormalImage, true);
			CC_SAFE_SET_VISIBLE(m_pSelectedImage, false);
			CC_SAFE_SET_VISIBLE(m_pDisabledImage, false);
		}
		else
		{
			if( m_pDisabledImage )
			{
				CC_SAFE_SET_VISIBLE(m_pNormalImage, false);
				CC_SAFE_SET_VISIBLE(m_pSelectedImage, false);
				CC_SAFE_SET_VISIBLE(m_pDisabledImage, true);
			}
			else
			{
				CC_SAFE_SET_VISIBLE(m_pNormalImage, true);
				CC_SAFE_SET_VISIBLE(m_pSelectedImage, false);
				CC_SAFE_SET_VISIBLE(m_pDisabledImage, false);
			}
		}
	}
}

void CButton::setLabelOffset(const Vec2& tOffset)
{
	if( m_pLabel )
	{
		m_tTextOffset = tOffset;
		m_pLabel->setPosition(m_pLabel->getPosition() + m_tTextOffset);
	}
	else
	{
		getLabel();
		m_tTextOffset = tOffset;
		m_pLabel->setPosition(m_pLabel->getPosition() + m_tTextOffset);
	}
}

CWidgetTouchModel CButton::onTouchBegan(Touch* pTouch)
{
	CC_WIDGET_LONGCLICK_ONTOUCHBEGAN;

	if( m_pSelectedImage )
	{
		CC_SAFE_SET_VISIBLE(m_pNormalImage, false);
		CC_SAFE_SET_VISIBLE(m_pDisabledImage, false);
		m_pSelectedImage->setVisible(true);
	}
	return eWidgetTouchTransient;
}

void CButton::onTouchMoved(Touch* pTouch, float fDuration)
{
	CC_WIDGET_LONGCLICK_ONTOUCHMOVED;

	if( m_pSelectedImage )
	{
		Vec2 touchPointInView = _parent->convertToNodeSpace(pTouch->getLocation());
		if( getBoundingBox().containsPoint(touchPointInView) )
		{
			CC_SAFE_SET_VISIBLE(m_pNormalImage, false);
			m_pSelectedImage->setVisible(true);
		}
		else
		{
			CC_SAFE_SET_VISIBLE(m_pNormalImage, true);
			m_pSelectedImage->setVisible(false);
		}
	}
}

void CButton::onTouchEnded(Touch* pTouch, float fDuration)
{
	CC_WIDGET_LONGCLICK_ONTOUCHENDED;

	if( m_pSelectedImage )
	{
		Vec2 touchPointInView = _parent->convertToNodeSpace(pTouch->getLocation());
		if( getBoundingBox().containsPoint(touchPointInView) )
		{
			CC_SAFE_SET_VISIBLE(m_pNormalImage, true);
			m_pSelectedImage->setVisible(false);
			executeClickHandler(this);
		}
		else
		{
			CC_SAFE_SET_VISIBLE(m_pNormalImage, true);
			m_pSelectedImage->setVisible(false);
		}
	}
	else
	{
		Vec2 touchPointInView = _parent->convertToNodeSpace(pTouch->getLocation());
		if( getBoundingBox().containsPoint(touchPointInView) )
		{
			CC_SAFE_SET_VISIBLE(m_pNormalImage, true);
			executeClickHandler(this);
		}
		CC_SAFE_SET_VISIBLE(m_pNormalImage, true);
	}
}

void CButton::onTouchCancelled(Touch* pTouch, float fDuration)
{
	CC_WIDGET_LONGCLICK_ONTOUCHCANCELLED;

	CC_SAFE_SET_VISIBLE(m_pNormalImage, true);
	CC_SAFE_SET_VISIBLE(m_pSelectedImage, false);
}




NS_CC_WIDGET_END