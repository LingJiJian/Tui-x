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
#include "ScrollView.h"

NS_CC_WIDGET_BEGIN

#define CSCORLLVIEW_RELOCATE_DURATION 0.2f
#define CSCROLLVIEW_DEACCELERATE_VA 2000.0f
#define CSCROLLVIEW_DEACCELERATE_MAX 400.0f
#define CSCROLLVIEW_DEACCELERATE_INTERVAL 0.245f
#define CSCROLLVIEW_DEACCELERATE_PERCENTAGE 0.955f
#define CSCROLLVIEW_MOVE_INCH 7.0f/160.0f
#define CSCROLLVIEW_MOVE_ACTION_TAG 1
#define CSCROLLVIEW_MOVE_EASEIN_RATE 0.5f

float ccScrollconvertPointToInch(float pointDis)
{
	auto glView = Director::getInstance()->getOpenGLView();
    float factor = ( glView->getScaleX() + glView->getScaleY() ) / 2;
	
    return pointDis * factor / Device::getDPI();
}

void CScrollViewContainer::reset()
{
	removeAllChildrenWithCleanup(true);
	ignoreAnchorPointForPosition(true);
	setAnchorPoint(Vec2::ZERO);
	setPosition(Vec2::ZERO);
}

CScrollView::CScrollView()
: m_pContainer(NULL)
, m_eDirection(eScrollViewDirectionBoth)
, m_tLastMovePoint(Vec2::ZERO)
, m_bBounceable(true)
, _clippingToBounds(true)
, m_bDragging(false)
, m_bDeaccelerateable(true)
, m_fDragSpeed(0.0f)
, m_tScrollDistance(Vec2::ZERO)
, m_tTouchBeganPoint(Vec2::ZERO)
, m_bDragable(true)
, m_bTouchMoved(false)
, m_tMaxOffset(Vec2::ZERO)
, m_tMinOffset(Vec2::ZERO)
, m_bDeaccelerateScrolling(false)
, m_bAnimatedScrolling(false)
{
	m_pContainer = new CScrollViewContainer();
	m_pContainer->init();
	m_pContainer->setAnchorPoint(Vec2::ZERO);
	m_pContainer->ignoreAnchorPointForPosition(true);
	m_pContainer->setContentSize(CCWIDGET_LAYOUT_DEFAULT_CONTENT_SIZE);
	addChild(m_pContainer);
	m_pContainer->release();
}

CScrollView::~CScrollView()
{
	
}

void CScrollView::setContainerSize(Size tSize)
{
	tSize.width  = MAX(tSize.width, _contentSize.width);
	tSize.height = MAX(tSize.height, _contentSize.height);

	m_pContainer->setContentSize(tSize);
	updateLimitOffset();
}

const Size& CScrollView::getContainerSize() const
{
	return m_pContainer->getContentSize();
}

CScrollViewDirection CScrollView::getDirection()
{
	return m_eDirection;
}

void CScrollView::setDirection(CScrollViewDirection eDirection)
{
	m_eDirection = eDirection;
}

CScrollViewContainer* CScrollView::getContainer()
{
	return m_pContainer;
}

void CScrollView::setContentSize(const Size& contentSize)
{
	CLayout::setContentSize(contentSize);
	updateLimitOffset();
}

bool CScrollView::init()
{
	if( CLayout::init() )
	{
		setContentSize(CCWIDGET_LAYOUT_DEFAULT_CONTENT_SIZE);
		setAnchorPoint(CCWIDGET_LAYOUT_DEFAULT_ANCHOR_POINT);
		return true;
	}
	return false;
}

void CScrollView::onExit()
{
	stoppedAnimatedScroll();
	stoppedDeaccelerateScroll();
    CLayout::onExit();
}

bool CScrollView::initWithSize(const Size& tSize)
{
	if( init() )
	{
		setContentSize(tSize);
		setContainerSize(tSize);
		m_pContainer->setPosition(Vec2::ZERO);
		updateLimitOffset();
		return true;
	}
	return false;
}

CWidgetTouchModel CScrollView::onTouchBegan(Touch *pTouch)
{
    Vec2 tNodePoint = convertToNodeSpace(pTouch->getLocation());

	if( m_pContainer->getBoundingBox().containsPoint(tNodePoint) )
    {
		m_pSelectedWidget = m_pContainer;
    }
	else
	{
		m_pSelectedWidget = NULL;
	}
    
    if( m_pSelectedWidget )
    {
		m_eSelectedWidgetTouchModel = m_pSelectedWidget->executeTouchBeganHandler(pTouch);
        if( m_eSelectedWidgetTouchModel == eWidgetTouchNone )
        {
			m_pSelectedWidget = NULL;
        }
    }
    
    m_tTouchBeganPoint = tNodePoint;
    
    if( m_eSelectedWidgetTouchModel == eWidgetTouchNone && m_bDragable )
    {
        m_tLastMovePoint = tNodePoint;
        m_bDragging = true;
		stoppedDeaccelerateScroll();
		stoppedAnimatedScroll();
    }

    return eWidgetTouchSustained;
}

void CScrollView::onTouchMoved(Touch *pTouch, float fDuration)
{
    Vec2 tNodePoint = convertToNodeSpace(pTouch->getLocation());
    
    if( m_pSelectedWidget )
    {
        if( m_eSelectedWidgetTouchModel == eWidgetTouchTransient && !m_bTouchMoved )
        {
            float fDistance = tNodePoint.getDistance(m_tTouchBeganPoint);   

            if(!m_bTouchMoved && fabs(ccScrollconvertPointToInch(fDistance)) < CSCROLLVIEW_MOVE_INCH)
            {
                m_pSelectedWidget->executeTouchMovedHandler(pTouch, fDuration);
                return;
            }

            m_bTouchMoved = true;
            m_pSelectedWidget->interruptTouch(pTouch, fDuration);
        }
        
        if(!m_pSelectedWidget->isTouchInterrupted())
        {
            m_pSelectedWidget->executeTouchMovedHandler(pTouch, fDuration);

            if(!m_pSelectedWidget->isTouchInterrupted())
            {
                return;
            }
        }
    }
    
    if( !m_bDragging )
    {
        m_tTouchBeganPoint = tNodePoint;
        m_tLastMovePoint = tNodePoint;
        m_bDragging = true;
		stoppedDeaccelerateScroll();
		stoppedAnimatedScroll();
    }
    
    if( m_bDragable )
    {
        m_tScrollDistance = tNodePoint - m_tLastMovePoint;
        m_tLastMovePoint = tNodePoint;
        
        switch( m_eDirection )
        {
            case eScrollViewDirectionHorizontal:
                m_tScrollDistance.y = 0;
                break;
            case eScrollViewDirectionVertical:
                m_tScrollDistance.x = 0;
                break;
            default:
                break;
        }
        
        setContentOffset( getContentOffset() + m_tScrollDistance );
    }
}

void CScrollView::onTouchEnded(Touch *pTouch, float fDuration)
{
    if( m_pSelectedWidget && !m_bTouchMoved && !m_pSelectedWidget->isTouchInterrupted() )
    {
        m_pSelectedWidget->executeTouchEndedHandler(pTouch, fDuration);
		m_bTouchMoved = false;
		m_bDragging = false;
        return;
    }
	
    if( m_bDragable )
    {
        if( m_bDeaccelerateable && m_eDirection != eScrollViewDirectionBoth && fDuration < CSCROLLVIEW_DEACCELERATE_INTERVAL )
        {
            Vec2 tEndPoint = convertToNodeSpace(pTouch->getLocation());
            switch( m_eDirection )
            {
                case eScrollViewDirectionHorizontal:
                    m_fDragSpeed = abs( m_tTouchBeganPoint.x - tEndPoint.x ) / fDuration;
                    break;
                default:
					m_fDragSpeed = abs( m_tTouchBeganPoint.y - tEndPoint.y ) / fDuration;
                    break;
            }
			perpareDeaccelerateScroll();
        }
        else
        {
			Vec2 tOffset = getContentOffset();
			if( validateOffset(tOffset) )
			{
				relocateContainerWithoutCheck(tOffset);
			}
			else
			{
				onDraggingScrollEnded();
			}
        }
    }
    
    m_bTouchMoved = false;
    m_bDragging = false;
}

void CScrollView::onTouchCancelled(Touch *pTouch, float fDuration)
{
    if( m_pSelectedWidget && !m_pSelectedWidget->isTouchInterrupted() )
    {
        m_pSelectedWidget->executeTouchCancelledHandler(pTouch, fDuration);
    }
    
    m_bTouchMoved = false;
    m_bDragging = false;
}

void CScrollView::setDeaccelerateable(bool bDeaccelerateable)
{
	m_bDeaccelerateable = bDeaccelerateable;
}

bool CScrollView::isDeaccelerateable()
{
	return m_bDeaccelerateable;
}

const Vec2& CScrollView::getContentOffset() const
{
	return m_pContainer->getPosition();
}

void CScrollView::setBounceable(bool bBounceable)
{
	m_bBounceable = bBounceable;
}

bool CScrollView::isBounceable()
{
	return m_bBounceable;
}

void CScrollView::setDragable(bool bDragable)
{
	m_bDragable = bDragable;
}

bool CScrollView::isDragable()
{
	return m_bDragable;
}

bool CScrollView::isTouchMoved() 
{
	return m_bTouchMoved; 
}

void CScrollView::stopContainerAnimation()
{
	if( m_pContainer )
	{
		m_pContainer->stopActionByTag(CSCROLLVIEW_MOVE_ACTION_TAG);
	}
}

const Vec2& CScrollView::getMaxOffset() const
{
	return m_tMaxOffset;
}

const Vec2& CScrollView::getMinOffset() const
{
	return m_tMinOffset;
}

void CScrollView::beforeDraw()
{
	_beforeDrawCommand.init(_globalZOrder);
	_beforeDrawCommand.func = CC_CALLBACK_0(CScrollView::onBeforeDraw, this);
	Director::getInstance()->getRenderer()->addCommand(&_beforeDrawCommand);
}

void CScrollView::onBeforeDraw()
{
	if (_clippingToBounds)
	{
		_scissorRestored = false;
		Rect frame = getViewRect();
		auto glview = Director::getInstance()->getOpenGLView();

		if (glview->isScissorEnabled()) {
			_scissorRestored = true;
			_parentScissorRect = glview->getScissorRect();
			//set the intersection of _parentScissorRect and frame as the new scissor rect
			if (frame.intersectsRect(_parentScissorRect)) {
				float x = MAX(frame.origin.x, _parentScissorRect.origin.x);
				float y = MAX(frame.origin.y, _parentScissorRect.origin.y);
				float xx = MIN(frame.origin.x+frame.size.width, _parentScissorRect.origin.x+_parentScissorRect.size.width);
				float yy = MIN(frame.origin.y+frame.size.height, _parentScissorRect.origin.y+_parentScissorRect.size.height);
				glview->setScissorInPoints(x, y, xx-x, yy-y);
			}
		}
		else {
			glEnable(GL_SCISSOR_TEST);
			glview->setScissorInPoints(frame.origin.x, frame.origin.y, frame.size.width, frame.size.height);
		}
	}
}

void CScrollView::afterDraw()
{
    _afterDrawCommand.init(_globalZOrder);
    _afterDrawCommand.func = CC_CALLBACK_0(CScrollView::onAfterDraw, this);
    Director::getInstance()->getRenderer()->addCommand(&_afterDrawCommand);
}

/**
 * retract what's done in beforeDraw so that there's no side effect to
 * other nodes.
 */
void CScrollView::onAfterDraw()
{
	if (_clippingToBounds)
	{
        if (_scissorRestored) {//restore the parent's scissor rect
            auto glview = Director::getInstance()->getOpenGLView();

			glview->setScissorInPoints(_parentScissorRect.origin.x, _parentScissorRect.origin.y, _parentScissorRect.size.width, _parentScissorRect.size.height);
        }
        else {
            glDisable(GL_SCISSOR_TEST);
        }
	}
}

void CScrollView::visit(Renderer* renderer, const Mat4 &parentTransform, uint32_t parentFlags)
{
	// quick return if not visible
	if (!isVisible())
	{
		return;
	}

	uint32_t flags = processParentFlags(parentTransform, parentFlags);

	// IMPORTANT:
	// To ease the migration to v3.0, we still support the Mat4 stack,
	// but it is deprecated and your code should not rely on it
	Director* director = Director::getInstance();
	CCASSERT(nullptr != director, "Director is null when seting matrix stack");
	director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
	director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, _modelViewTransform);

	this->beforeDraw();

	if (!_children.empty())
	{
		int i=0;

		sortAllChildren();
		// draw children zOrder < 0
		for( ; i < _children.size(); i++ )
		{
			Node *child = _children.at(i);
			if ( child->getLocalZOrder() < 0 )
			{
				child->visit(renderer, _modelViewTransform, flags);
			}
			else
			{
				break;
			}
		}
		
		// this draw
		this->draw(renderer, _modelViewTransform, flags);

		// draw children zOrder >= 0
		for( ; i < _children.size(); i++ )
		{
			Node *child = _children.at(i);
			child->visit(renderer, _modelViewTransform, flags);
		}

	}
	else
	{
		this->draw(renderer, _modelViewTransform, flags);
	}

	this->afterDraw();

	director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
}

CScrollView* CScrollView::create(const Size& contentSize)
{
	CScrollView * pRet = new CScrollView();
	if( pRet && pRet->initWithSize(contentSize) )
    {
		pRet->autorelease();
		return pRet;
    }
	CC_SAFE_DELETE(pRet);
	return NULL;
}

void CScrollView::perpareDeaccelerateScroll()
{
	if(!m_bDeaccelerateScrolling && m_bDeaccelerateable)
	{
		schedule(schedule_selector(CScrollView::performedDeaccelerateScrolling));
		m_bDeaccelerateScrolling = true;
	}
}

void CScrollView::performedDeaccelerateScrolling(float dt)
{
	if( m_bDragging )
	{
		stoppedDeaccelerateScroll();
		return;
	}

	Vec2 tOldOffset;
	Vec2 tNewOffset;
	float fDistance = m_fDragSpeed * dt;
	switch( m_eDirection )
	{
		case eScrollViewDirectionHorizontal:
			fDistance  = m_tScrollDistance.x < 0 ? -fDistance : fDistance;
			tNewOffset = getContentOffset() + Vec2(fDistance, 0);
			break;
		default:
			fDistance  = m_tScrollDistance.y < 0 ? -fDistance : fDistance;
			tNewOffset = getContentOffset() + Vec2(0, fDistance);
			break;
	}
	tOldOffset = tNewOffset;
	bool bOutOfView = validateOffset(tNewOffset);

	if( bOutOfView && !m_bBounceable )
	{
		setContentOffsetWithoutCheck(tNewOffset);
		stoppedDeaccelerateScroll();
		return;
	}

	setContentOffsetWithoutCheck(tOldOffset);

	if( bOutOfView )
	{
		m_fDragSpeed = MIN(CSCROLLVIEW_DEACCELERATE_MAX, m_fDragSpeed);
		m_fDragSpeed = m_fDragSpeed - CSCROLLVIEW_DEACCELERATE_VA * dt;
	}
	else
	{
		m_fDragSpeed = CSCROLLVIEW_DEACCELERATE_PERCENTAGE * m_fDragSpeed - CSCROLLVIEW_DEACCELERATE_VA * dt;
	}

	if( m_fDragSpeed <= 0 )
	{
		stoppedDeaccelerateScroll();
		
		if( bOutOfView )
		{
			relocateContainerWithoutCheck(tNewOffset);
		}
		else
		{
			onDeaccelerateScrollEnded();
		}
	}
}

void CScrollView::stoppedDeaccelerateScroll()
{
	if( m_bDeaccelerateScrolling )
	{
		unschedule(schedule_selector(CScrollView::performedDeaccelerateScrolling));
		m_bDeaccelerateScrolling = false;
	}
}

void CScrollView::perpareAnimatedScroll()
{
	if( !m_bAnimatedScrolling )
	{
		schedule(schedule_selector(CScrollView::performedAnimatedScrolling));
		m_bAnimatedScrolling = true;
	}
}

void CScrollView::performedAnimatedScrolling(float dt)
{
	if( m_bDragging )
    {
		m_pContainer->stopActionByTag(CSCROLLVIEW_MOVE_ACTION_TAG);
		stoppedAnimatedScroll();
        return;
    }
    this->onScrolling();
	this->executeScrollingHandler(this);
}

void CScrollView::stoppedAnimatedScroll()
{
	if( m_bAnimatedScrolling )
	{
		unschedule(schedule_selector(CScrollView::performedAnimatedScrolling));
		m_bAnimatedScrolling = false;

		this->onScrolling();
		this->executeScrollingHandler(this);
	}
}

void CScrollView::relocateContainerWithoutCheck(const Vec2& tOffset)
{
	setContentOffsetEaseInWithoutCheck(tOffset, CSCORLLVIEW_RELOCATE_DURATION, CSCROLLVIEW_MOVE_EASEIN_RATE);
}

void CScrollView::relocateContainer()
{
	Vec2 tOffset = getContentOffset();
	if( validateOffset(tOffset) )
	{
		setContentOffsetEaseInWithoutCheck(tOffset, CSCORLLVIEW_RELOCATE_DURATION, CSCROLLVIEW_MOVE_EASEIN_RATE);
	}
}

void CScrollView::setContentOffsetToTop()
{
	if( m_eDirection == eScrollViewDirectionVertical )
	{
		Vec2 tPoint(0, -(m_pContainer->getContentSize().height - _contentSize.height));
		setContentOffset(tPoint);
	}
}

void CScrollView::setContentOffsetToTopInDuration(float fDuration)
{
	if( m_eDirection == eScrollViewDirectionVertical )
	{
		Vec2 tPoint(0, -(m_pContainer->getContentSize().height - _contentSize.height));
		setContentOffsetInDuration(tPoint, fDuration);
	}
}

void CScrollView::setContentOffsetToTopEaseIn(float fDuration, float fRate)
{
	if( m_eDirection == eScrollViewDirectionVertical )
	{
		Vec2 tPoint(0, -(m_pContainer->getContentSize().height - _contentSize.height));
		setContentOffsetEaseIn(tPoint, fDuration, fRate);
	}
}

void CScrollView::setContentOffsetToBottom()
{
	if( m_eDirection == eScrollViewDirectionVertical )
	{
		setContentOffset(m_tMaxOffset);
	}
}

void CScrollView::setContentOffsetToRight()
{
	if( m_eDirection == eScrollViewDirectionHorizontal )
	{
		setContentOffset(m_tMinOffset);
	}
}

void CScrollView::setContentOffsetToLeft()
{
	if( m_eDirection == eScrollViewDirectionHorizontal )
	{
		setContentOffset(m_tMaxOffset);
	}
}

void CScrollView::setContentOffsetWithoutCheck(const Vec2& tOffset)
{
	m_pContainer->setPosition(tOffset);
	this->onScrolling();
	this->executeScrollingHandler(this);
}

void CScrollView::setContentOffset(Vec2 tOffset)
{
	if( !m_bBounceable )
	{
		validateOffset(tOffset);
	}
	m_pContainer->stopActionByTag(CSCROLLVIEW_MOVE_ACTION_TAG);
	m_pContainer->setPosition(tOffset);
    this->onScrolling();
	this->executeScrollingHandler(this);
}

void CScrollView::setContentOffsetInDurationWithoutCheck(const Vec2& tOffset, float fDuration)
{
	m_pContainer->stopActionByTag(CSCROLLVIEW_MOVE_ACTION_TAG);
    Sequence* pSequence = Sequence::create(
		MoveTo::create(fDuration, tOffset),
		CallFunc::create(std::bind(&CScrollView::stoppedAnimatedScroll, this)),
		NULL);
	pSequence->setTag(CSCROLLVIEW_MOVE_ACTION_TAG);
	m_pContainer->runAction(pSequence);

	perpareAnimatedScroll();
	this->onScrolling();
	this->executeScrollingHandler(this);
}

void CScrollView::setContentOffsetInDuration(Vec2 tOffset, float fDuration)
{
	if( !m_bBounceable )
	{
		validateOffset(tOffset);
	}
	setContentOffsetInDurationWithoutCheck(tOffset, fDuration);
}

void CScrollView::setContentOffsetEaseInWithoutCheck(const Vec2& tOffset, float fDuration, float fRate)
{
	m_pContainer->stopActionByTag(CSCROLLVIEW_MOVE_ACTION_TAG);
	Sequence* pSequence = Sequence::create(
		EaseIn::create(
			MoveTo::create(fDuration, tOffset),
			fRate
		),
		CallFunc::create(std::bind(&CScrollView::stoppedAnimatedScroll, this)), NULL
	);
	pSequence->setTag(CSCROLLVIEW_MOVE_ACTION_TAG);
	m_pContainer->runAction(pSequence);

	perpareAnimatedScroll();
	this->onScrolling();
	this->executeScrollingHandler(this);
}

void CScrollView::setContentOffsetEaseIn(Vec2 tOffset, float fDuration, float fRate)
{
	if( !m_bBounceable )
	{
		validateOffset(tOffset);
	}
	setContentOffsetEaseInWithoutCheck(tOffset, fDuration, fRate);
}

void CScrollView::updateLimitOffset()
{
	m_tMaxOffset.x = 0;
	m_tMinOffset.x = _contentSize.width - m_pContainer->_contentSize.width;

	m_tMaxOffset.y = 0;
	m_tMinOffset.y = _contentSize.height - m_pContainer->_contentSize.height;

	if( m_eDirection == eScrollViewDirectionHorizontal )
	{
		m_tMinOffset.y = 0;
	}
	else if( m_eDirection == eScrollViewDirectionVertical )
	{
		m_tMinOffset.x = 0;
	}
}

bool CScrollView::validateOffset(Vec2& tPoint)
{
	float x = tPoint.x, y = tPoint.y;
	x = MAX(x, m_tMinOffset.x);
	x = MIN(x, m_tMaxOffset.x);
	y = MAX(y, m_tMinOffset.y);
	y = MIN(y, m_tMaxOffset.y);

	if( tPoint.x != x || tPoint.y != y )
	{
		tPoint.x = x;
		tPoint.y = y;
		return true;
	}

	tPoint.x = x;
	tPoint.y = y;
	return false;
}

Rect CScrollView::getViewRect()
{
	Vec2 screenPos = this->convertToWorldSpace(Vec2::ZERO);

	float scaleX = this->getScaleX();
	float scaleY = this->getScaleY();

	for (Node *p = _parent; p != NULL; p = p->getParent()) {
		scaleX *= p->getScaleX();
		scaleY *= p->getScaleY();
	}

	Size viewSize = _contentSize;
	if(scaleX<0.f) {
		screenPos.x += viewSize.width*scaleX;
		scaleX = -scaleX;
	}
	if(scaleY<0.f) {
		screenPos.y += viewSize.height*scaleY;
		scaleY = -scaleY;
	}

	return Rect(screenPos.x, screenPos.y, viewSize.width*scaleX, viewSize.height*scaleY);
}

NS_CC_WIDGET_END