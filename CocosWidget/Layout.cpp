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
#include "Layout.h"

NS_CC_WIDGET_BEGIN

CLayout::CLayout()

: m_pBackgroundImage(NULL)
, m_pBackgroundColor(NULL)
, m_pBackgroundGradient(NULL)
{
	setThisObject(this);
}

CLayout::~CLayout()
{

}

CLayout* CLayout::create()
{
	CLayout* pRet = new CLayout();
	if( pRet && pRet->init() )
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

CLayout* CLayout::create(const Size& tContentSize)
{
	CLayout* pRet = new CLayout();
	if( pRet && pRet->init() )
	{
		pRet->setContentSize(tContentSize);
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

bool CLayout::init()
{
	setCascadeColorEnabled(true);
	setCascadeOpacityEnabled(true);

	setContentSize(CCWIDGET_LAYOUT_DEFAULT_CONTENT_SIZE);
	setAnchorPoint(CCWIDGET_LAYOUT_DEFAULT_ANCHOR_POINT);
	setPosition(Vec2::ZERO);

	return true;
}

void CLayout::setContentSize(const Size& tContentSize)
{ 
	Node::setContentSize(tContentSize);

	CC_WIDGET_UPDATE_BACKGROUND_POS
}

CWidgetTouchModel CLayout::onTouchBegan(Touch* pTouch)
{
	m_pSelectedWidget = NULL;
	m_eSelectedWidgetTouchModel = eWidgetTouchNone;

	Vec2 tNodePoint = convertToNodeSpace(pTouch->getLocation());
	int nCount = _children.size();
	if(nCount > 0 )
	{
		for(int i = nCount-1; i >= 0; --i)
		{
			Node* pNode = _children.at(i);
			CWidget* pWidget = dynamic_cast<CWidget*>(pNode);
			if( pWidget && pNode->isVisible() && pWidget->isEnabled() && pWidget->isTouchEnabled() )
			{
				if( pNode->getBoundingBox().containsPoint(tNodePoint) )
				{
					m_eSelectedWidgetTouchModel = pWidget->executeTouchBeganHandler(pTouch);
					if( m_eSelectedWidgetTouchModel == eWidgetTouchNone )
					{
						m_pSelectedWidget = NULL;
						m_eSelectedWidgetTouchModel = eWidgetTouchNone;
					}
					else
					{
						m_pSelectedWidget = pWidget;
						return m_eSelectedWidgetTouchModel;
					}
				}
			}
		}
	}
	return eWidgetTouchNone;
}

void CLayout::onTouchMoved(Touch* pTouch, float fDuration)
{
	if( m_pSelectedWidget && !m_pSelectedWidget->isTouchInterrupted() )
	{
		m_pSelectedWidget->executeTouchMovedHandler(pTouch, fDuration);
	}
}

void CLayout::onTouchEnded(Touch* pTouch, float fDuration)
{
	if( m_pSelectedWidget && !m_pSelectedWidget->isTouchInterrupted() )
	{
		m_pSelectedWidget->executeTouchEndedHandler(pTouch, fDuration);
	}
	m_pSelectedWidget = NULL;
	m_eSelectedWidgetTouchModel = eWidgetTouchNone;
}

void CLayout::onTouchCancelled(Touch* pTouch, float fDuration)
{
	if( m_pSelectedWidget && !m_pSelectedWidget->isTouchInterrupted() )
	{
		m_pSelectedWidget->executeTouchCancelledHandler(pTouch, fDuration);
	}
	m_pSelectedWidget = NULL;
	m_eSelectedWidgetTouchModel = eWidgetTouchNone;
}

Ref* CLayout::findWidgetById(const char* id)
{
	CCAssert(id && strlen(id), "should not null");

	return find(_children, id);
}

Node* CLayout::find(Vector<Node*> pChild, const char* id)
{
	int nCount = pChild.size();
	if( nCount> 0 )
	{
		for(int i = 0; i < nCount; ++i)
		{
			Node* pObject = pChild.at(i);
			CWidget* pWidget = dynamic_cast<CWidget*>(pObject);
			if( pWidget )
			{
				if( strcmp(pWidget->getId(), id) == 0 )
				{
					return pObject;
				}
				else
				{
					Node* pRet = find(dynamic_cast<Node*>(pObject)->getChildren(), id);
					if( pRet )
					{
						return pRet;
					}
						
				}
			}
		}
	}
	return NULL;
}

void CLayout::visit(Renderer* renderer, const Mat4 &parentTransform, uint32_t parentFlags)
{
	Node::visit(renderer, parentTransform, parentFlags);
}



NS_CC_WIDGET_END