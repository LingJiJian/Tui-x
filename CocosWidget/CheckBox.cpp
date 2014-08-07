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
#include "CheckBox.h"

NS_CC_WIDGET_BEGIN

CCheckBox::CCheckBox()
: m_pNormal(NULL)
, m_pNormalPress(NULL)
, m_pChecked(NULL)
, m_pCheckedPress(NULL)
, m_pDisabledNormal(NULL)
, m_pDisabledChecked(NULL)
{
	setThisObject(this);
	setCascadeColorEnabled(true);
	setCascadeOpacityEnabled(true);

	setAnchorPoint(CCWIDGET_BASIC_DEFAULT_ANCHOR_POINT);
	setContentSize(CCWIDGET_BASIC_DEFAULT_CONTENT_SIZE);
}

CCheckBox::~CCheckBox()
{
	
}

CCheckBox* CCheckBox::create()
{
	CCheckBox* pRet = new CCheckBox();
	if( pRet && pRet->init() )
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

bool CCheckBox::init()
{
	setAnchorPoint(CCWIDGET_BASIC_DEFAULT_ANCHOR_POINT);
	setContentSize(CCWIDGET_BASIC_DEFAULT_CONTENT_SIZE);

	return true;
}

#define SAFE_SET_VISIBLE(_SPRITE_, _FLAG_) if(_SPRITE_) _SPRITE_->setVisible(_FLAG_)
#define SAFE_SET_CENTER(_SPRITE_, _SIZE_) \
if( _SPRITE_ ) _SPRITE_->setPosition(Point(_SIZE_.width/2, _SIZE_.height/2))

void CCheckBox::setContentSize(const Size& tContentSize)
{
	Node::setContentSize(tContentSize);
	SAFE_SET_CENTER(m_pNormal, _contentSize);
	SAFE_SET_CENTER(m_pNormalPress, _contentSize);
	SAFE_SET_CENTER(m_pChecked, _contentSize);
	SAFE_SET_CENTER(m_pCheckedPress, _contentSize);
	SAFE_SET_CENTER(m_pDisabledNormal, _contentSize);
	SAFE_SET_CENTER(m_pDisabledChecked, _contentSize);
}

CWidgetTouchModel CCheckBox::onTouchBegan(Touch* pTouch)
{
	CC_WIDGET_LONGCLICK_ONTOUCHBEGAN;

	if( isChecked() )
	{
		if( m_pCheckedPress )
		{
			SAFE_SET_VISIBLE(m_pCheckedPress, true);
			SAFE_SET_VISIBLE(m_pChecked, false);
		}
	}
	else
	{
		if( m_pNormalPress )
		{
			SAFE_SET_VISIBLE(m_pNormalPress, true);
			SAFE_SET_VISIBLE(m_pNormal, false);
		}
	}

	return eWidgetTouchTransient;
}

void CCheckBox::onTouchMoved(Touch* pTouch, float fDuration)
{
	CC_WIDGET_LONGCLICK_ONTOUCHMOVED;

	Vec2 tPoint = _parent->convertToNodeSpace(pTouch->getLocation());
	if( getBoundingBox().containsPoint(tPoint) )
	{
		if( isChecked() )
		{
			if( m_pCheckedPress )
			{
				SAFE_SET_VISIBLE(m_pCheckedPress, true);
				SAFE_SET_VISIBLE(m_pChecked, false);
			}
			else
			{
				SAFE_SET_VISIBLE(m_pChecked, true);
			}
		}
		else
		{
			if( m_pNormalPress )
			{
				SAFE_SET_VISIBLE(m_pNormalPress, true);
				SAFE_SET_VISIBLE(m_pNormal, false);
			}
			else
			{
				SAFE_SET_VISIBLE(m_pNormal, true);
			}
		}
	}
	else
	{
		if( isChecked() )
		{
			SAFE_SET_VISIBLE(m_pCheckedPress, false);
			SAFE_SET_VISIBLE(m_pChecked, true);
		}
		else
		{
			SAFE_SET_VISIBLE(m_pNormalPress, false);
			SAFE_SET_VISIBLE(m_pNormal, true);
		}
	}
}

void CCheckBox::onTouchEnded(Touch* pTouch, float fDuration)
{
	CC_WIDGET_LONGCLICK_ONTOUCHENDED;

	Vec2 tPoint = _parent->convertToNodeSpace(pTouch->getLocation());
	if( getBoundingBox().containsPoint(tPoint) )
	{
		if( isChecked() )
		{
			setChecked(false);
		}
		else
		{
			setChecked(true);
		}
		executeClickHandler(this);
	}
	else
	{
		if( isChecked() )
		{
			SAFE_SET_VISIBLE(m_pNormalPress, false);
			SAFE_SET_VISIBLE(m_pNormal, false);
			SAFE_SET_VISIBLE(m_pCheckedPress, false);
			SAFE_SET_VISIBLE(m_pChecked, true);
		}
		else
		{
			SAFE_SET_VISIBLE(m_pNormalPress, false);
			SAFE_SET_VISIBLE(m_pNormal, true);
			SAFE_SET_VISIBLE(m_pCheckedPress, false);
			SAFE_SET_VISIBLE(m_pChecked, false);
		}
	}
}

void CCheckBox::onTouchCancelled(Touch* pTouch, float fDuration)
{
	CC_WIDGET_LONGCLICK_ONTOUCHCANCELLED;

	if( isChecked() )
	{
		SAFE_SET_VISIBLE(m_pCheckedPress, false);
		SAFE_SET_VISIBLE(m_pChecked, true);
	}
	else
	{
		SAFE_SET_VISIBLE(m_pNormalPress, false);
		SAFE_SET_VISIBLE(m_pNormal, true);
	}
}

void CCheckBox::setChecked(bool bChecked)
{
	if( m_bChecked != bChecked )
	{
		if( m_bEnabled )
		{
			if( bChecked )
			{
				SAFE_SET_VISIBLE(m_pNormalPress, false);
				SAFE_SET_VISIBLE(m_pNormal, false);
				SAFE_SET_VISIBLE(m_pCheckedPress, false);
				SAFE_SET_VISIBLE(m_pChecked, true);
				setUnCheckedForOtherWidgetsByExclusion(_parent);
			}
			else
			{
				SAFE_SET_VISIBLE(m_pNormalPress, false);
				SAFE_SET_VISIBLE(m_pNormal, true);
				SAFE_SET_VISIBLE(m_pCheckedPress, false);
				SAFE_SET_VISIBLE(m_pChecked, false);
			}
		}
		else
		{
			if( bChecked )
			{
				if( m_pDisabledChecked )
				{
					m_pDisabledChecked->setVisible(true);
					SAFE_SET_VISIBLE(m_pNormalPress, false);
					SAFE_SET_VISIBLE(m_pNormal, false);
					SAFE_SET_VISIBLE(m_pCheckedPress, false);
					SAFE_SET_VISIBLE(m_pChecked, false);
					SAFE_SET_VISIBLE(m_pDisabledNormal, false);
				}
				else
				{
					SAFE_SET_VISIBLE(m_pNormalPress, false);
					SAFE_SET_VISIBLE(m_pNormal, false);
					SAFE_SET_VISIBLE(m_pCheckedPress, false);
					SAFE_SET_VISIBLE(m_pChecked, true);
					SAFE_SET_VISIBLE(m_pDisabledNormal, false);
				}
				setUnCheckedForOtherWidgetsByExclusion(_parent);
			}
			else
			{
				if( m_pDisabledNormal )
				{
					m_pDisabledNormal->setVisible(true);
					SAFE_SET_VISIBLE(m_pNormalPress, false);
					SAFE_SET_VISIBLE(m_pNormal, false);
					SAFE_SET_VISIBLE(m_pCheckedPress, false);
					SAFE_SET_VISIBLE(m_pChecked, false);
					SAFE_SET_VISIBLE(m_pDisabledChecked, false);
				}
				else
				{
					SAFE_SET_VISIBLE(m_pNormalPress, false);
					SAFE_SET_VISIBLE(m_pNormal, true);
					SAFE_SET_VISIBLE(m_pCheckedPress, false);
					SAFE_SET_VISIBLE(m_pChecked, false);
					SAFE_SET_VISIBLE(m_pDisabledChecked, false);
				}
			}
		}

		m_bChecked = bChecked;
		executeCheckHandler(this, m_bChecked);
	}
}

void CCheckBox::setEnabled(bool bEnabled)
{
	if( m_bEnabled != bEnabled )
	{
		if( bEnabled )
		{
			if( isChecked() )
			{
				SAFE_SET_VISIBLE(m_pNormalPress, false);
				SAFE_SET_VISIBLE(m_pNormal, false);
				SAFE_SET_VISIBLE(m_pCheckedPress, false);
				SAFE_SET_VISIBLE(m_pChecked, true);
				SAFE_SET_VISIBLE(m_pDisabledNormal, false);
				SAFE_SET_VISIBLE(m_pDisabledChecked, false);
			}
			else
			{
				SAFE_SET_VISIBLE(m_pNormalPress, false);
				SAFE_SET_VISIBLE(m_pNormal, true);
				SAFE_SET_VISIBLE(m_pCheckedPress, false);
				SAFE_SET_VISIBLE(m_pChecked, false);
				SAFE_SET_VISIBLE(m_pDisabledNormal, false);
				SAFE_SET_VISIBLE(m_pDisabledChecked, false);
			}
		}
		else
		{
			if( isChecked() )
			{
				if( m_pDisabledChecked )
				{
					SAFE_SET_VISIBLE(m_pNormalPress, false);
					SAFE_SET_VISIBLE(m_pNormal, false);
					SAFE_SET_VISIBLE(m_pCheckedPress, false);
					SAFE_SET_VISIBLE(m_pChecked, false);
					SAFE_SET_VISIBLE(m_pDisabledNormal, false);
					SAFE_SET_VISIBLE(m_pDisabledChecked, true);
				}
				else
				{
					SAFE_SET_VISIBLE(m_pNormalPress, false);
					SAFE_SET_VISIBLE(m_pNormal, false);
					SAFE_SET_VISIBLE(m_pCheckedPress, false);
					SAFE_SET_VISIBLE(m_pChecked, true);
					SAFE_SET_VISIBLE(m_pDisabledNormal, false);
				}
			}
			else
			{
				if( m_pDisabledNormal )
				{
					SAFE_SET_VISIBLE(m_pNormalPress, false);
					SAFE_SET_VISIBLE(m_pNormal, false);
					SAFE_SET_VISIBLE(m_pCheckedPress, false);
					SAFE_SET_VISIBLE(m_pChecked, false);
					SAFE_SET_VISIBLE(m_pDisabledNormal, true);
					SAFE_SET_VISIBLE(m_pDisabledChecked, false);
				}
				else
				{
					SAFE_SET_VISIBLE(m_pNormalPress, true);
					SAFE_SET_VISIBLE(m_pNormal, false);
					SAFE_SET_VISIBLE(m_pCheckedPress, false);
					SAFE_SET_VISIBLE(m_pChecked, false);
					SAFE_SET_VISIBLE(m_pDisabledChecked, false);
				}
			}
		}

		m_bEnabled = bEnabled;
	}
}

void CCheckBox::setNormalImage(const char* pFile)
{
	if( pFile && strlen(pFile) )
	{
		Texture2D* pTexture = Director::getInstance()->getTextureCache()->addImage(pFile);
		setNormalTexture(pTexture);
	}
}

void CCheckBox::setNormalPressImage(const char* pFile)
{
	if( pFile && strlen(pFile) )
	{
		Texture2D* pTexture = Director::getInstance()->getTextureCache()->addImage(pFile);
		setNormalPressTexture(pTexture);
	}
}

void CCheckBox::setCheckedImage(const char* pFile)
{
	if( pFile && strlen(pFile) )
	{
		Texture2D* pTexture = Director::getInstance()->getTextureCache()->addImage(pFile);
		setCheckedTexture(pTexture);
	}
}

void CCheckBox::setCheckedPressImage(const char* pFile)
{
	if( pFile && strlen(pFile) )
	{
		Texture2D* pTexture = Director::getInstance()->getTextureCache()->addImage(pFile);
		setCheckedPressTexture(pTexture);
	}
}

void CCheckBox::setDisabledNormalImage(const char* pFile)
{
	if( pFile && strlen(pFile) )
	{
		Texture2D* pTexture = Director::getInstance()->getTextureCache()->addImage(pFile);
		setDisabledNormalTexture(pTexture);
	}
}

void CCheckBox::setDisabledCheckedImage(const char* pFile)
{
	if( pFile && strlen(pFile) )
	{
		Texture2D* pTexture = Director::getInstance()->getTextureCache()->addImage(pFile);
		setDisabledCheckedTexture(pTexture);
	}
}

void CCheckBox::setNormalSpriteFrame(SpriteFrame* pFrame)
{
	if( pFrame )
	{
		if( m_pNormal )
		{
			m_pNormal->setSpriteFrame(pFrame);
			setContentSize(m_pNormal->getContentSize());
		}
		else
		{
			m_pNormal = Sprite::createWithSpriteFrame(pFrame);
			setContentSize(m_pNormal->getContentSize());
			addChild(m_pNormal);
		}
		m_pNormal->setPosition(Vec2(_contentSize.width/2, _contentSize.height/2));
	}
}

void CCheckBox::setNormalPressSpriteFrame(SpriteFrame* pFrame)
{
	if( pFrame )
	{
		if( m_pNormalPress )
		{
			m_pNormalPress->setSpriteFrame(pFrame);
		}
		else
		{
			m_pNormalPress = Sprite::createWithSpriteFrame(pFrame);
			addChild(m_pNormalPress);
		}
		m_pNormalPress->setVisible(false);
		m_pNormalPress->setPosition(Vec2(_contentSize.width/2, _contentSize.height/2));
	}
}

void CCheckBox::setCheckedSpriteFrame(SpriteFrame* pFrame)
{
	if( pFrame )
	{
		if( m_pChecked )
		{
			m_pChecked->setSpriteFrame(pFrame);
		}
		else
		{
			m_pChecked = Sprite::createWithSpriteFrame(pFrame);
			addChild(m_pChecked);
		}
		m_pChecked->setVisible(false);
		m_pChecked->setPosition(Vec2(_contentSize.width/2, _contentSize.height/2));
	}
}

void CCheckBox::setCheckedPressSpriteFrame(SpriteFrame* pFrame)
{
	if( pFrame )
	{
		if( m_pCheckedPress )
		{
			m_pCheckedPress->setSpriteFrame(pFrame);
		}
		else
		{
			m_pCheckedPress = Sprite::createWithSpriteFrame(pFrame);
			addChild(m_pCheckedPress);
		}
		m_pCheckedPress->setVisible(false);
		m_pCheckedPress->setPosition(Vec2(_contentSize.width/2, _contentSize.height/2));
	}
}

void CCheckBox::setDisabledNormalSpriteFrame(SpriteFrame* pFrame)
{
	if( pFrame )
	{
		if( m_pDisabledNormal )
		{
			m_pDisabledNormal->setSpriteFrame(pFrame);
		}
		else
		{
			m_pDisabledNormal = Sprite::createWithSpriteFrame(pFrame);
			addChild(m_pDisabledNormal);
		}
		m_pDisabledNormal->setVisible(false);
		m_pDisabledNormal->setPosition(Vec2(_contentSize.width/2, _contentSize.height/2));
	}
}

void CCheckBox::setDisabledCheckedSpriteFrame(SpriteFrame* pFrame)
{
	if( pFrame )
	{
		if( m_pDisabledChecked )
		{
			m_pDisabledChecked->setSpriteFrame(pFrame);
		}
		else
		{
			m_pDisabledChecked = Sprite::createWithSpriteFrame(pFrame);
			addChild(m_pDisabledChecked);
		}
		m_pDisabledChecked->setVisible(false);
		m_pDisabledChecked->setPosition(Vec2(_contentSize.width/2, _contentSize.height/2));
	}
}

void CCheckBox::setNormalTexture(Texture2D* pTexture)
{
	if( m_pNormal )
	{
		m_pNormal->setTexture(pTexture);

		Rect tRect = Rect::ZERO;
		tRect.size = pTexture->getContentSize();
		m_pNormal->setTextureRect(tRect);

		setContentSize(pTexture->getContentSize());
	}
	else
	{
		m_pNormal = Sprite::createWithTexture(pTexture);
		setContentSize(m_pNormal->getContentSize());
		addChild(m_pNormal);
	}
	m_pNormal->setPosition(Vec2(_contentSize.width/2, _contentSize.height/2));
}

void CCheckBox::setNormalPressTexture(Texture2D* pTexture)
{
	if( m_pNormalPress )
	{
		m_pNormalPress->setTexture(pTexture);

		Rect tRect = Rect::ZERO;
		tRect.size = pTexture->getContentSize();
		m_pNormalPress->setTextureRect(tRect);
	}
	else
	{
		m_pNormalPress = Sprite::createWithTexture(pTexture);
		addChild(m_pNormalPress);
	}
	m_pNormalPress->setVisible(false);
	m_pNormalPress->setPosition(Vec2(_contentSize.width/2, _contentSize.height/2));
}

void CCheckBox::setCheckedTexture(Texture2D* pTexture)
{
	if( m_pChecked )
	{
		m_pChecked->setTexture(pTexture);

		Rect tRect = Rect::ZERO;
		tRect.size = pTexture->getContentSize();
		m_pChecked->setTextureRect(tRect);
	}
	else
	{
		m_pChecked = Sprite::createWithTexture(pTexture);
		addChild(m_pChecked);
	}
	m_pChecked->setVisible(false);
	m_pChecked->setPosition(Vec2(_contentSize.width/2, _contentSize.height/2));
}

void CCheckBox::setCheckedPressTexture(Texture2D* pTexture)
{
	if( m_pCheckedPress )
	{
		m_pCheckedPress->setTexture(pTexture);

		Rect tRect = Rect::ZERO;
		tRect.size = pTexture->getContentSize();
		m_pCheckedPress->setTextureRect(tRect);
	}
	else
	{
		m_pCheckedPress = Sprite::createWithTexture(pTexture);
		addChild(m_pCheckedPress);
	}
	m_pCheckedPress->setVisible(false);
	m_pCheckedPress->setPosition(Vec2(_contentSize.width/2, _contentSize.height/2));
}

void CCheckBox::setDisabledNormalTexture(Texture2D* pTexture)
{
	if( m_pDisabledNormal )
	{
		m_pDisabledNormal->setTexture(pTexture);

		Rect tRect = Rect::ZERO;
		tRect.size = pTexture->getContentSize();
		m_pDisabledNormal->setTextureRect(tRect);
	}
	else
	{
		m_pDisabledNormal = Sprite::createWithTexture(pTexture);
		addChild(m_pDisabledNormal);
	}
	m_pDisabledNormal->setVisible(false);
	m_pDisabledNormal->setPosition(Vec2(_contentSize.width/2, _contentSize.height/2));
}

void CCheckBox::setDisabledCheckedTexture(Texture2D* pTexture)
{
	if( m_pDisabledChecked )
	{
		m_pDisabledChecked->setTexture(pTexture);

		Rect tRect = Rect::ZERO;
		tRect.size = pTexture->getContentSize();
		m_pDisabledChecked->setTextureRect(tRect);
	}
	else
	{
		m_pDisabledChecked = Sprite::createWithTexture(pTexture);
		addChild(m_pDisabledChecked);
	}
	m_pDisabledChecked->setVisible(false);
	m_pDisabledChecked->setPosition(Vec2(_contentSize.width/2, _contentSize.height/2));
}

void CCheckBox::setNormalSpriteFrameName(const char* pSpriteName)
{
	SpriteFrame *pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(pSpriteName);

#if COCOS2D_DEBUG > 0
	char msg[256] = {0};
	sprintf(msg, "Invalid spriteFrameName: %s", pSpriteName);
	CCAssert(pFrame != NULL, msg);
#endif

	return setNormalSpriteFrame(pFrame);
}

void CCheckBox::setNormalPressSpriteFrameName(const char* pSpriteName)
{
	SpriteFrame *pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(pSpriteName);

	if (!pFrame) CCLOG("cocos2d: SpriteFrameCache: Frame '%s' not found", pSpriteName);
	return setNormalPressSpriteFrame(pFrame);
}

void CCheckBox::setCheckedSpriteFrameName(const char* pSpriteName)
{
	SpriteFrame *pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(pSpriteName);

#if COCOS2D_DEBUG > 0
	char msg[256] = { 0 };
	sprintf(msg, "Invalid spriteFrameName: %s", pSpriteName);
	CCAssert(pFrame != NULL, msg);
#endif

	return setCheckedSpriteFrame(pFrame);
}

void CCheckBox::setCheckedPressSpriteFrameName(const char* pSpriteName)
{
	SpriteFrame *pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(pSpriteName);

	if (!pFrame) CCLOG("cocos2d: SpriteFrameCache: Frame '%s' not found", pSpriteName);
	return setCheckedPressSpriteFrame(pFrame);
}

void CCheckBox::setDisabledNormalSpriteFrameName(const char* pSpriteName)
{
	SpriteFrame *pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(pSpriteName);

	if (!pFrame) CCLOG("cocos2d: SpriteFrameCache: Frame '%s' not found", pSpriteName);
	return setDisabledNormalSpriteFrame(pFrame);
}

void CCheckBox::setDisabledCheckedSpriteFrameName(const char* pSpriteName)
{
	SpriteFrame *pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(pSpriteName);

	if (!pFrame) CCLOG("cocos2d: SpriteFrameCache: Frame '%s' not found", pSpriteName);
	return setDisabledCheckedSpriteFrame(pFrame);
}


NS_CC_WIDGET_END