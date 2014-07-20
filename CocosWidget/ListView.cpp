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
#include "ListView.h"
#include <algorithm>
using namespace std;

NS_CC_WIDGET_BEGIN

static const Vec2 ListViewHorizontalNodeAnchorPoint = Vec2(0, 0);
static const Vec2 ListViewVerticalNodeAnchorPoint = Vec2(0, 0);


CListView::CListView()
: m_fLayoutIndexSize(0.0f)
{
	m_eDirection = eScrollViewDirectionVertical;
}

CListView::~CListView()
{
	removeAllNodes();
}

CListView* CListView::create(const Size& contentSize)
{
	CListView* pRet = new CListView();
	if( pRet && pRet->initWithSize(contentSize) )
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

unsigned int CListView::getNodeCount() const
{
	return m_vNodeList.size();
}

Vector<Node*> CListView::getNodes()
{
	return m_vNodeList;
}

Node* CListView::getNodeAtIndex(unsigned int idx)
{
	return m_vNodeList.at(idx);
}

void CListView::insertNodeAtLast(Node* pNode)
{
	CCAssert(pNode, "should not null");
	m_vNodeList.pushBack(pNode);
	pNode->retain();
}

void CListView::insertNodeAtFront(Node* pNode)
{
	CCAssert(pNode, "should not null");
	m_vNodeList.insert(0, pNode);
	pNode->retain();
}

void CListView::insertNode(Node* pNode, Node* pTarget)
{
	CCAssert(pTarget && pNode, "should not null");

	unsigned int idx = 0;
	unsigned int end = m_vNodeList.size();

	for(; idx < end; ++idx )
	{
		if( pTarget == m_vNodeList.at(idx) )
		{
			m_vNodeList.insert(idx, pNode);
			pNode->retain();
		}
	}
}

void CListView::insertNode(Node* pNode, unsigned int idx)
{
	CCAssert(pNode, "should not null");

	if( idx >= m_vNodeList.size() )
	{
		insertNodeAtLast(pNode);
		return;
	}

	m_vNodeList.insert(idx, pNode);
	pNode->retain();
}

void CListView::removeNodeAtIndex(unsigned int idx)
{
	if( m_vNodeList.size() == 0 )
		return;

	m_vNodeList.at(idx)->release();
	m_vNodeList.erase(m_vNodeList.begin() + idx);
}

void CListView::removeNode(Node* pNode)
{
	CCAssert(pNode, "should not null");

	if( m_vNodeList.size() == 0 )
		return;

	Vector<Node*>::iterator itr = std::find(
		m_vNodeList.begin(),
		m_vNodeList.end(),
		pNode);

	if( itr != m_vNodeList.end() )
	{
		pNode->release();
		m_vNodeList.erase(itr);
	}
}

void CListView::removeFrontNode()
{
	if( m_vNodeList.size() == 0 )
		return;

	m_vNodeList.at(0)->release();
	m_vNodeList.erase(m_vNodeList.begin());
}

void CListView::removeLastNode()
{
	if( m_vNodeList.size() == 0 )
		return;

	m_vNodeList.at(m_vNodeList.size() - 1)->release();
	m_vNodeList.popBack();
}

void CListView::removeAllNodes()
{
	if( m_vNodeList.size() == 0 )
		return;

	unsigned int i = 0;
	unsigned int end = m_vNodeList.size();

	for(; i < end; ++i )
	{
		m_vNodeList.at(i)->release();
	}

	m_vNodeList.clear();
}

void CListView::updateNodesPosition()
{
	m_pContainer->removeAllChildrenWithCleanup(true);

	if( m_vNodeList.size() == 0 )
		return;

	m_fLayoutIndexSize = 0.0f;

	switch( m_eDirection )
	{
	case eScrollViewDirectionHorizontal:
		{
			unsigned int i = 0;
			unsigned int end = m_vNodeList.size();
			Node* pNode = NULL;

			for(; i < end; ++i )
			{
				pNode = m_vNodeList.at(i);
				pNode->setAnchorPoint(ListViewHorizontalNodeAnchorPoint);
				pNode->setPosition(Vec2(m_fLayoutIndexSize, 0));
				m_fLayoutIndexSize += pNode->getContentSize().width;
			}

			setContainerSize(Size(m_fLayoutIndexSize, _contentSize.height));
		}
		break;
	case eScrollViewDirectionVertical:
		{
			float fAllNodesSize = 0.0f;

			unsigned int i = 0;
			unsigned int end = m_vNodeList.size();
			Node* pNode = NULL;

			for(; i < end; ++i )
			{
				pNode = m_vNodeList.at(i);
				fAllNodesSize += pNode->getContentSize().height;
			}

			m_fLayoutIndexSize = fAllNodesSize;
			fAllNodesSize = MAX(_contentSize.height, fAllNodesSize);
			setContainerSize(Size(_contentSize.width, fAllNodesSize));
			
			i = 0;
			end = m_vNodeList.size();

			for(; i < end; ++i )
			{
				pNode = m_vNodeList.at(i);
				fAllNodesSize = fAllNodesSize - pNode->getContentSize().height;
				pNode->setAnchorPoint(ListViewVerticalNodeAnchorPoint);
				pNode->setPosition(Vec2(0, fAllNodesSize));

				m_pContainer->addChild(pNode);
			}
		}
		break;
	default:
		break;
	}
}

void CListView::reloadData()
{
	CCAssert( m_eDirection != eScrollViewDirectionBoth, "reloadData");

	if( m_eDirection == eScrollViewDirectionVertical )
	{
		float fOldHeight = getContainerSize().height;

		updateNodesPosition();

		float tNewHeight = getContainerSize().height - fOldHeight;

		setContentOffset(getContentOffset() - Vec2(0, tNewHeight));
	}
	else
	{
		updateNodesPosition();
	}

	relocateContainer();
}

NS_CC_WIDGET_END