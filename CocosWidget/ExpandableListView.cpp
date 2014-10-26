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
#include "ExpandableListView.h"
#include <algorithm>
using namespace std;

NS_CC_WIDGET_BEGIN

CExpandableNode::CExpandableNode()
: m_bExpanded(false)
, m_pExpandableListViewParent(NULL)
, m_nIdx(CC_INVALID_INDEX)
{

}

CExpandableNode::~CExpandableNode()
{
	removeAllItemNodes();
}

CExpandableNode* CExpandableNode::create()
{
	CExpandableNode* pRet = new CExpandableNode();
	pRet->init();
	pRet->setContentSize(Size(100, 100));
	pRet->setAnchorPoint(Vec2(0.5f, 0.5f));
	pRet->autorelease();
	return pRet;
}

void CExpandableNode::insertItemNodeAtLast(Node* pNode)
{
	CCAssert(pNode, "should not null");
	m_vExpandableNodeItemList.push_back(pNode);
	pNode->retain();
}

void CExpandableNode::insertItemNodeAtFront(Node* pNode)
{
	CCAssert(pNode, "should not null");
	m_vExpandableNodeItemList.insert(m_vExpandableNodeItemList.begin(), pNode);
	pNode->retain();
}

void CExpandableNode::removeItemNode(Node* pNode)
{
	CCAssert(pNode, "should not null");

	if( m_vExpandableNodeItemList.size() == 0 )
		return;

	vector<Node*>::iterator itr = std::find(
		m_vExpandableNodeItemList.begin(),
		m_vExpandableNodeItemList.end(), 
		pNode);

	if( itr != m_vExpandableNodeItemList.end() )
	{
		pNode->release();
		m_vExpandableNodeItemList.erase(itr);
	}
}

void CExpandableNode::removeItemNodeAtIndex(unsigned int idx)
{
	if( m_vExpandableNodeItemList.size() == 0 )
		return;

	m_vExpandableNodeItemList[idx]->release();
	m_vExpandableNodeItemList.erase(m_vExpandableNodeItemList.begin() + idx);
}

Node *CExpandableNode::getItemNodeAtIndex(unsigned int idx)
{
	if (m_vExpandableNodeItemList.size() == 0)
		return nullptr;
	return m_vExpandableNodeItemList[idx];
}

void CExpandableNode::removeAllItemNodes()
{
	if( m_vExpandableNodeItemList.size() == 0 )
		return;

	vector<Node*>::iterator itr = m_vExpandableNodeItemList.begin();
	vector<Node*>::iterator end = m_vExpandableNodeItemList.end();

	for(; itr != end ; ++itr )
	{
		(*itr)->release();
	}

	m_vExpandableNodeItemList.clear();
}

void CExpandableNode::setExpanded(bool bExpanded)
{
	m_bExpanded = bExpanded;
}

bool CExpandableNode::isExpanded() const
{
	return m_bExpanded;
}

void CExpandableNode::setExpandableListViewParent(CExpandableListView* pListView)
{
	m_pExpandableListViewParent = pListView;
}

std::vector<Node*>& CExpandableNode::getExpandableNodeItemList()
{
	return m_vExpandableNodeItemList;
}

CWidgetTouchModel CExpandableNode::onTouchBegan(Touch* pTouch)
{
	m_pSelectedWidget = NULL;
	m_eSelectedWidgetTouchModel = eWidgetTouchNone;

	Vec2 tNodePoint = convertToNodeSpace(pTouch->getLocation());
	int nCount = _children.size();
	if( nCount > 0 )
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
	return eWidgetTouchTransient;
}

void CExpandableNode::onTouchMoved(Touch* pTouch, float fDuration)
{
	if( m_pSelectedWidget && !m_pSelectedWidget->isTouchInterrupted() )
	{
		m_pSelectedWidget->executeTouchMovedHandler(pTouch, fDuration);
	}
}

void CExpandableNode::onTouchEnded(Touch* pTouch, float fDuration)
{
	if( m_pSelectedWidget && !m_pSelectedWidget->isTouchInterrupted() )
	{
		m_pSelectedWidget->executeTouchEndedHandler(pTouch, fDuration);
	}
	else
	{
		CCAssert(m_pExpandableListViewParent, "parent should not null");

		Vec2 tPoint = _parent->convertToNodeSpace(pTouch->getLocation());
		if( getBoundingBox().containsPoint(tPoint) )
		{
			if( m_bExpanded )
			{
				m_bExpanded = false;
				m_pExpandableListViewParent->reloadData();
			}
			else
			{
				m_bExpanded = true;
				m_pExpandableListViewParent->reloadData();
			}
		}
	}
	m_pSelectedWidget = NULL;
	m_eSelectedWidgetTouchModel = eWidgetTouchNone;
}

void CExpandableNode::onTouchCancelled(Touch* pTouch, float fDuration)
{
	if( m_pSelectedWidget && !m_pSelectedWidget->isTouchInterrupted() )
	{
		m_pSelectedWidget->executeTouchCancelledHandler(pTouch, fDuration);
	}
	m_pSelectedWidget = NULL;
	m_eSelectedWidgetTouchModel = eWidgetTouchNone;
}










CExpandableListView::CExpandableListView()
{
	m_eDirection = eScrollViewDirectionVertical;
}

CExpandableListView::~CExpandableListView()
{
	removeAllExpandableNodes();
}

CExpandableListView* CExpandableListView::create(const Size& contentSize)
{
	CExpandableListView* pRet = new CExpandableListView();
	pRet->initWithSize(contentSize);
	pRet->autorelease();
	return pRet;
}

void CExpandableListView::expand(unsigned int idx)
{
	m_vExpandableNodeList.at(idx)->setExpanded(true);
}

void CExpandableListView::collapse(unsigned int idx)
{
	m_vExpandableNodeList.at(idx)->setExpanded(false);
}

void CExpandableListView::insertExpandableNodeAtLast(CExpandableNode* pNode)
{
	CCAssert(pNode, "should not null");
	m_vExpandableNodeList.pushBack(pNode);
	pNode->retain();
	pNode->setExpandableListViewParent(this);
}

void CExpandableListView::insertExpandableNodeAtFront(CExpandableNode* pNode)
{
	CCAssert(pNode, "should not null");
	m_vExpandableNodeList.insert(0, pNode);
	pNode->retain();
	pNode->setExpandableListViewParent(this);
}

void CExpandableListView::removeExpandableNode(CExpandableNode* pNode)
{
	if( m_vExpandableNodeList.size() == 0 )
		return;

	vector<CExpandableNode*>::iterator itr = std::find(
			m_vExpandableNodeList.begin(),
			m_vExpandableNodeList.end(),
			pNode);

	if( itr != m_vExpandableNodeList.end() )
	{
		pNode->release();
		m_vExpandableNodeList.erase(itr);
	}
}

void CExpandableListView::removeExpandableNodeAtIndex(unsigned int idx)
{
	if( m_vExpandableNodeList.size() == 0 )
		return;

	m_vExpandableNodeList.at(idx)->release();
	m_vExpandableNodeList.erase(m_vExpandableNodeList.begin() + idx);
}

void CExpandableListView::removeLastExpandableNode()
{
	if( m_vExpandableNodeList.size() == 0 )
		return;

	m_vExpandableNodeList.at(m_vExpandableNodeList.size() - 1)->release();
	m_vExpandableNodeList.popBack();
}

void CExpandableListView::removeFrontExpandableNode()
{
	if( m_vExpandableNodeList.size() == 0 )
		return;

	m_vExpandableNodeList.at(0)->release();
	m_vExpandableNodeList.erase(m_vExpandableNodeList.begin());
}

void CExpandableListView::removeAllExpandableNodes()
{
	if( m_vExpandableNodeList.size() == 0 )
		return;

	unsigned int i = 0;
	unsigned int end = m_vExpandableNodeList.size();

	for(; i < end; ++i )
	{
		m_vExpandableNodeList.at(i)->release();
	}

	m_vExpandableNodeList.clear();
}

Vector<CExpandableNode*> CExpandableListView::getExpandableNodes()
{
	return m_vExpandableNodeList;
}

unsigned int CExpandableListView::getExpandableNodeCount()
{
	return m_vExpandableNodeList.size();
}

CExpandableNode* CExpandableListView::getExpandableNodeAtIndex(unsigned int idx)
{
	return m_vExpandableNodeList.at(idx);
}

void CExpandableListView::updateNodesPosition()
{
	m_pContainer->removeAllChildrenWithCleanup(true);

	if( m_vExpandableNodeList.size() == 0 )
		return;

	float fAllNodesHeight = 0.0f;

	unsigned int uBegin = 0;
	unsigned int uEnd = m_vExpandableNodeList.size();

	for(; uBegin < uEnd; ++uBegin )
	{
		CExpandableNode* pExpandableNode = m_vExpandableNodeList.at(uBegin);
		fAllNodesHeight += pExpandableNode->getContentSize().height;

		if( pExpandableNode->isExpanded() )
		{
			vector<Node*>&  vNodeItemList = pExpandableNode->getExpandableNodeItemList();
			if( vNodeItemList.size() != 0 )
			{
				for( unsigned int i = 0; i < vNodeItemList.size(); ++i )
				{
					fAllNodesHeight += (vNodeItemList[i])->getContentSize().height;
				}
			}
		}
	}

	fAllNodesHeight = MAX(_contentSize.height, fAllNodesHeight);
	setContainerSize(Size(_contentSize.width, fAllNodesHeight));

	uBegin = 0;
	uEnd = m_vExpandableNodeList.size();

	for(; uBegin < uEnd; ++uBegin )
	{
		CExpandableNode* pExpandableNode = m_vExpandableNodeList.at(uBegin);
		fAllNodesHeight = fAllNodesHeight - pExpandableNode->getContentSize().height;

		pExpandableNode->setAnchorPoint(Vec2::ZERO);
		pExpandableNode->setPosition(Vec2(0, fAllNodesHeight));
		m_pContainer->addChild(pExpandableNode);

		if( pExpandableNode->isExpanded() )
		{
			vector<Node*>& vNodeItemList = pExpandableNode->getExpandableNodeItemList();
			if( vNodeItemList.size() != 0 )
			{
				for( unsigned int i = 0; i < vNodeItemList.size(); ++i )
				{
					Node* pNode = vNodeItemList[i];
					fAllNodesHeight = fAllNodesHeight - pNode->getContentSize().height;

					pNode->setAnchorPoint(Vec2::ZERO);
					pNode->setPosition(Vec2(0, fAllNodesHeight));
					m_pContainer->addChild(pNode);
				}
			}
		}
	}
}

void CExpandableListView::reloadData()
{
	CCAssert(m_eDirection == eScrollViewDirectionVertical, "should be Vertical");

	float fOldHeight = getContainerSize().height;

	updateNodesPosition();

	float tNewHeight = getContainerSize().height - fOldHeight;

	setContentOffset(getContentOffset() - Vec2(0, tNewHeight));

	relocateContainer();
}

NS_CC_WIDGET_END