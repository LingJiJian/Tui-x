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
#include "Scale9Sprite.h"

NS_CC_WIDGET_BEGIN

enum positions
{
    pCentre = 0,
    pTop,
    pLeft,
    pRight,
    pBottom,
    pTopRight,
    pTopLeft,
    pBottomRight,
    pBottomLeft
};

CScale9Sprite::CScale9Sprite()
: m_insetLeft(0)
, m_insetTop(0)
, m_insetRight(0)
, m_insetBottom(0)
, m_bSpritesGenerated(false)
, m_bSpriteFrameRotated(false)
, m_positionsAreDirty(false)
, _scale9Image(NULL)
, _topLeft(NULL)
, _top(NULL)
, _topRight(NULL)
, _left(NULL)
, _centre(NULL)
, _right(NULL)
, _bottomLeft(NULL)
, _bottom(NULL)
, _bottomRight(NULL)
, _opacityModifyRGB(false)
, _opacity(255)
, _color(Color3B::WHITE)
{

}

CScale9Sprite::~CScale9Sprite()
{
	CC_SAFE_RELEASE(_scale9Image);
}

bool CScale9Sprite::init()
{
    return this->initWithBatchNode(NULL, Rect::ZERO, Rect::ZERO);
}

bool CScale9Sprite::initWithBatchNode(SpriteBatchNode* batchnode, Rect rect, Rect capInsets)
{
    return this->initWithBatchNode(batchnode, rect, false, capInsets);
}

bool CScale9Sprite::initWithBatchNode(SpriteBatchNode* batchnode, Rect rect, bool rotated, Rect capInsets)
{
    if(batchnode)
    {
        this->updateWithBatchNode(batchnode, rect, rotated, capInsets);
        this->setAnchorPoint(Vec2(0.5f, 0.5f));
    }
    this->m_positionsAreDirty = true;
    
    return true;
}

#define    TRANSLATE_X(x, y, xtranslate) \
    x+=xtranslate;                       \

#define    TRANSLATE_Y(x, y, ytranslate) \
    y+=ytranslate;                       \

bool CScale9Sprite::updateWithBatchNode(SpriteBatchNode* batchnode, Rect rect, bool rotated, Rect capInsets)
{
    GLubyte opacity = getOpacity();
    Color3B color = getColor();

    // Release old sprites
    this->removeAllChildrenWithCleanup(true);
    
    if(this->_scale9Image != batchnode)
    {
        CC_SAFE_RELEASE(this->_scale9Image);
        _scale9Image = batchnode;
        CC_SAFE_RETAIN(_scale9Image);
    }

    _scale9Image->removeAllChildrenWithCleanup(true);

    m_capInsets = capInsets;
    
    // If there is no given rect
    if ( rect.equals(Rect::ZERO) )
    {
        // Get the texture size as original
        Size textureSize = _scale9Image->getTextureAtlas()->getTexture()->getContentSize();
    
        rect = Rect(0, 0, textureSize.width, textureSize.height);
    }
    
    // Set the given rect's size as original size
    m_spriteRect = rect;
    m_originalSize = rect.size;
    m_preferredSize = m_originalSize;
    m_capInsetsInternal = capInsets;
    
    float w = rect.size.width;
    float h = rect.size.height;

    // If there is no specified center region
    if ( m_capInsetsInternal.equals(Rect::ZERO) )
    {
        // CCLog("... cap insets not specified : using default cap insets ...");
        m_capInsetsInternal = Rect(w/3, h/3, w/3, h/3);
    }

    float left_w = m_capInsetsInternal.origin.x;
    float center_w = m_capInsetsInternal.size.width;
    float right_w = rect.size.width - (left_w + center_w);

    float top_h = m_capInsetsInternal.origin.y;
    float center_h = m_capInsetsInternal.size.height;
    float bottom_h = rect.size.height - (top_h + center_h);

    // calculate rects

    // ... top row
    float x = 0.0;
    float y = 0.0;

    // top left
    Rect lefttopbounds = Rect(x, y,
                                      left_w, top_h);

    // top center
    TRANSLATE_X(x, y, left_w);
    Rect centertopbounds = Rect(x, y,
                                        center_w, top_h);
        
    // top right
    TRANSLATE_X(x, y, center_w);
    Rect righttopbounds = Rect(x, y,
                                       right_w, top_h);

    // ... center row
    x = 0.0;
    y = 0.0;
    TRANSLATE_Y(x, y, top_h);

    // center left
    Rect leftcenterbounds = Rect(x, y,
                                         left_w, center_h);

    // center center
    TRANSLATE_X(x, y, left_w);
    Rect centerbounds = Rect(x, y,
                                     center_w, center_h);

    // center right
    TRANSLATE_X(x, y, center_w);
    Rect rightcenterbounds = Rect(x, y,
                                          right_w, center_h);

    // ... bottom row
    x = 0.0;
    y = 0.0;
    TRANSLATE_Y(x, y, top_h);
    TRANSLATE_Y(x, y, center_h);

    // bottom left
    Rect leftbottombounds = Rect(x, y,
                                         left_w, bottom_h);

    // bottom center
    TRANSLATE_X(x, y, left_w);
    Rect centerbottombounds = Rect(x, y,
                                           center_w, bottom_h);

    // bottom right
    TRANSLATE_X(x, y, center_w);
    Rect rightbottombounds = Rect(x, y,
                                          right_w, bottom_h);

    if (!rotated) {
        // CCLog("!rotated");

        AffineTransform t = AffineTransformMakeIdentity();
        t = AffineTransformTranslate(t, rect.origin.x, rect.origin.y);

        centerbounds = RectApplyAffineTransform(centerbounds, t);
        rightbottombounds = RectApplyAffineTransform(rightbottombounds, t);
        leftbottombounds = RectApplyAffineTransform(leftbottombounds, t);
        righttopbounds = RectApplyAffineTransform(righttopbounds, t);
        lefttopbounds = RectApplyAffineTransform(lefttopbounds, t);
        rightcenterbounds = RectApplyAffineTransform(rightcenterbounds, t);
        leftcenterbounds = RectApplyAffineTransform(leftcenterbounds, t);
        centerbottombounds = RectApplyAffineTransform(centerbottombounds, t);
        centertopbounds = RectApplyAffineTransform(centertopbounds, t);

        // Centre
        _centre = Sprite::createWithTexture(_scale9Image->getTexture(), centerbounds);
        _scale9Image->addChild(_centre, 0, pCentre);
        
        // Top
        _top = Sprite::createWithTexture(_scale9Image->getTexture(), centertopbounds);
        _scale9Image->addChild(_top, 1, pTop);
        
        // Bottom
        _bottom = Sprite::createWithTexture(_scale9Image->getTexture(), centerbottombounds);
        _scale9Image->addChild(_bottom, 1, pBottom);
        
        // Left
        _left = Sprite::createWithTexture(_scale9Image->getTexture(), leftcenterbounds);
        _scale9Image->addChild(_left, 1, pLeft);
        
        // Right
        _right = Sprite::createWithTexture(_scale9Image->getTexture(), rightcenterbounds);
        _scale9Image->addChild(_right, 1, pRight);
        
        // Top left
        _topLeft = Sprite::createWithTexture(_scale9Image->getTexture(), lefttopbounds);
        _scale9Image->addChild(_topLeft, 2, pTopLeft);
        
        // Top right
        _topRight = Sprite::createWithTexture(_scale9Image->getTexture(), righttopbounds);
        _scale9Image->addChild(_topRight, 2, pTopRight);
        
        // Bottom left
        _bottomLeft = Sprite::createWithTexture(_scale9Image->getTexture(), leftbottombounds);
        _scale9Image->addChild(_bottomLeft, 2, pBottomLeft);
        
        // Bottom right
        _bottomRight = Sprite::createWithTexture(_scale9Image->getTexture(), rightbottombounds);
        _scale9Image->addChild(_bottomRight, 2, pBottomRight);
    } else {
        // set up transformation of coordinates
        // to handle the case where the sprite is stored rotated
        // in the spritesheet
        // CCLog("rotated");

        AffineTransform t = AffineTransformMakeIdentity();

        Rect rotatedcenterbounds = centerbounds;
        Rect rotatedrightbottombounds = rightbottombounds;
        Rect rotatedleftbottombounds = leftbottombounds;
        Rect rotatedrighttopbounds = righttopbounds;
        Rect rotatedlefttopbounds = lefttopbounds;
        Rect rotatedrightcenterbounds = rightcenterbounds;
        Rect rotatedleftcenterbounds = leftcenterbounds;
        Rect rotatedcenterbottombounds = centerbottombounds;
        Rect rotatedcentertopbounds = centertopbounds;
        
        t = AffineTransformTranslate(t, rect.size.height+rect.origin.x, rect.origin.y);
        t = AffineTransformRotate(t, 1.57079633f);
        
        centerbounds = RectApplyAffineTransform(centerbounds, t);
        rightbottombounds = RectApplyAffineTransform(rightbottombounds, t);
        leftbottombounds = RectApplyAffineTransform(leftbottombounds, t);
        righttopbounds = RectApplyAffineTransform(righttopbounds, t);
        lefttopbounds = RectApplyAffineTransform(lefttopbounds, t);
        rightcenterbounds = RectApplyAffineTransform(rightcenterbounds, t);
        leftcenterbounds = RectApplyAffineTransform(leftcenterbounds, t);
        centerbottombounds = RectApplyAffineTransform(centerbottombounds, t);
        centertopbounds = RectApplyAffineTransform(centertopbounds, t);

        rotatedcenterbounds.origin = centerbounds.origin;
        rotatedrightbottombounds.origin = rightbottombounds.origin;
        rotatedleftbottombounds.origin = leftbottombounds.origin;
        rotatedrighttopbounds.origin = righttopbounds.origin;
        rotatedlefttopbounds.origin = lefttopbounds.origin;
        rotatedrightcenterbounds.origin = rightcenterbounds.origin;
        rotatedleftcenterbounds.origin = leftcenterbounds.origin;
        rotatedcenterbottombounds.origin = centerbottombounds.origin;
        rotatedcentertopbounds.origin = centertopbounds.origin;

        // Centre
        _centre = Sprite::createWithTexture(_scale9Image->getTexture(), rotatedcenterbounds, true);
        _scale9Image->addChild(_centre, 0, pCentre);
        
        // Top
        _top = Sprite::createWithTexture(_scale9Image->getTexture(), rotatedcentertopbounds, true);
        _scale9Image->addChild(_top, 1, pTop);
        
        // Bottom
        _bottom = Sprite::createWithTexture(_scale9Image->getTexture(), rotatedcenterbottombounds, true);
        _scale9Image->addChild(_bottom, 1, pBottom);
        
        // Left
        _left = Sprite::createWithTexture(_scale9Image->getTexture(), rotatedleftcenterbounds, true);
        _scale9Image->addChild(_left, 1, pLeft);
        
        // Right
        _right = Sprite::createWithTexture(_scale9Image->getTexture(), rotatedrightcenterbounds, true);
        _scale9Image->addChild(_right, 1, pRight);
        
        // Top left
        _topLeft = Sprite::createWithTexture(_scale9Image->getTexture(), rotatedlefttopbounds, true);
        _scale9Image->addChild(_topLeft, 2, pTopLeft);
        
        // Top right
        _topRight = Sprite::createWithTexture(_scale9Image->getTexture(), rotatedrighttopbounds, true);
        _scale9Image->addChild(_topRight, 2, pTopRight);
        
        // Bottom left
        _bottomLeft = Sprite::createWithTexture(_scale9Image->getTexture(), rotatedleftbottombounds, true);
        _scale9Image->addChild(_bottomLeft, 2, pBottomLeft);
        
        // Bottom right
        _bottomRight = Sprite::createWithTexture(_scale9Image->getTexture(), rotatedrightbottombounds, true);
        _scale9Image->addChild(_bottomRight, 2, pBottomRight);
    }

    this->setContentSize(rect.size);
    this->addChild(_scale9Image);
    
    if (m_bSpritesGenerated)
        {
            // Restore color and opacity
            this->setOpacity(opacity);
            this->setColor(color);
        }
    m_bSpritesGenerated = true;

    return true;
}

void CScale9Sprite::setContentSize(const Size &size)
{
    Node::setContentSize(size);
    this->m_positionsAreDirty = true;
}

void CScale9Sprite::updatePositions()
{
    // Check that instances are non-NULL
    if(!((_topLeft) &&
         (_topRight) &&
         (_bottomRight) &&
         (_bottomLeft) &&
         (_centre))) {
        // if any of the above sprites are NULL, return
        return;
    }

    Size size = this->_contentSize;

    float sizableWidth = size.width - _topLeft->getContentSize().width - _topRight->getContentSize().width;
    float sizableHeight = size.height - _topLeft->getContentSize().height - _bottomRight->getContentSize().height;
    
    float horizontalScale = sizableWidth/_centre->getContentSize().width;
    float verticalScale = sizableHeight/_centre->getContentSize().height;

    _centre->setScaleX(horizontalScale);
    _centre->setScaleY(verticalScale);

    float rescaledWidth = _centre->getContentSize().width * horizontalScale;
    float rescaledHeight = _centre->getContentSize().height * verticalScale;

    float leftWidth = _bottomLeft->getContentSize().width;
    float bottomHeight = _bottomLeft->getContentSize().height;

    _bottomLeft->setAnchorPoint(Vec2(0,0));
    _bottomRight->setAnchorPoint(Vec2(0,0));
    _topLeft->setAnchorPoint(Vec2(0,0));
    _topRight->setAnchorPoint(Vec2(0,0));
    _left->setAnchorPoint(Vec2(0,0));
    _right->setAnchorPoint(Vec2(0,0));
    _top->setAnchorPoint(Vec2(0,0));
    _bottom->setAnchorPoint(Vec2(0,0));
    _centre->setAnchorPoint(Vec2(0,0));

    // Position corners
    _bottomLeft->setPosition(Vec2(0,0));
    _bottomRight->setPosition(Vec2(leftWidth+rescaledWidth,0));
    _topLeft->setPosition(Vec2(0, bottomHeight+rescaledHeight));
    _topRight->setPosition(Vec2(leftWidth+rescaledWidth, bottomHeight+rescaledHeight));

    // Scale and position borders
    _left->setPosition(Vec2(0, bottomHeight));
    _left->setScaleY(verticalScale);
    _right->setPosition(Vec2(leftWidth+rescaledWidth,bottomHeight));
    _right->setScaleY(verticalScale);
    _bottom->setPosition(Vec2(leftWidth,0));
    _bottom->setScaleX(horizontalScale);
    _top->setPosition(Vec2(leftWidth,bottomHeight+rescaledHeight));
    _top->setScaleX(horizontalScale);

    // Position centre
    _centre->setPosition(Vec2(leftWidth, bottomHeight));
}

bool CScale9Sprite::initWithFile(const char* file, Rect rect,  Rect capInsets)
{
    CCAssert(file != NULL, "Invalid file for sprite");
    
    SpriteBatchNode *batchnode = SpriteBatchNode::create(file, 9);
    bool pReturn = this->initWithBatchNode(batchnode, rect, capInsets);
    return pReturn;
}

CScale9Sprite* CScale9Sprite::create(const char* file, Rect rect,  Rect capInsets)
{
    CScale9Sprite* pReturn = new CScale9Sprite();
    if ( pReturn && pReturn->initWithFile(file, rect, capInsets) )
    {
        pReturn->autorelease();
        return pReturn;
    }
    CC_SAFE_DELETE(pReturn);
    return NULL;
}

bool CScale9Sprite::initWithFile(const char* file, Rect rect)
{
    CCAssert(file != NULL, "Invalid file for sprite");
    bool pReturn = this->initWithFile(file, rect, Rect::ZERO);
    return pReturn;
}

CScale9Sprite* CScale9Sprite::create(const char* file, Rect rect)
{
    CScale9Sprite* pReturn = new CScale9Sprite();
    if ( pReturn && pReturn->initWithFile(file, rect) )
    {
        pReturn->autorelease();
        return pReturn;
    }
    CC_SAFE_DELETE(pReturn);
    return NULL;
}


bool CScale9Sprite::initWithFile(Rect capInsets, const char* file)
{
    bool pReturn = this->initWithFile(file, Rect::ZERO, capInsets);
    return pReturn;
}

CScale9Sprite* CScale9Sprite::create(Rect capInsets, const char* file)
{
    CScale9Sprite* pReturn = new CScale9Sprite();
    if ( pReturn && pReturn->initWithFile(capInsets, file) )
    {
        pReturn->autorelease();
        return pReturn;
    }
    CC_SAFE_DELETE(pReturn);
    return NULL;
}

bool CScale9Sprite::initWithFile(const char* file)
{
    bool pReturn = this->initWithFile(file, Rect::ZERO);
    return pReturn;
    
}

CScale9Sprite* CScale9Sprite::create(const char* file)
{
    CScale9Sprite* pReturn = new CScale9Sprite();
    if ( pReturn && pReturn->initWithFile(file) )
    {
        pReturn->autorelease();
        return pReturn;
    }
    CC_SAFE_DELETE(pReturn);
    return NULL;
}

bool CScale9Sprite::initWithSpriteFrame(SpriteFrame* spriteFrame, Rect capInsets)
{
    Texture2D* texture = spriteFrame->getTexture();
    CCAssert(texture != NULL, "CCTexture must be not nil");

    SpriteBatchNode *batchnode = SpriteBatchNode::createWithTexture(texture, 9);
    CCAssert(batchnode != NULL, "CCSpriteBatchNode must be not nil");

    bool pReturn = this->initWithBatchNode(batchnode, spriteFrame->getRect(), spriteFrame->isRotated(), capInsets);
    return pReturn;
}

CScale9Sprite* CScale9Sprite::createWithSpriteFrame(SpriteFrame* spriteFrame, Rect capInsets)
{
    CScale9Sprite* pReturn = new CScale9Sprite();
    if ( pReturn && pReturn->initWithSpriteFrame(spriteFrame, capInsets) )
    {
        pReturn->autorelease();
        return pReturn;
    }
    CC_SAFE_DELETE(pReturn);
    return NULL;
}
bool CScale9Sprite::initWithSpriteFrame(SpriteFrame* spriteFrame)
{
    CCAssert(spriteFrame != NULL, "Invalid spriteFrame for sprite");
    bool pReturn = this->initWithSpriteFrame(spriteFrame, Rect::ZERO);
    return pReturn;
}

CScale9Sprite* CScale9Sprite::createWithSpriteFrame(SpriteFrame* spriteFrame)
{
    CScale9Sprite* pReturn = new CScale9Sprite();
    if ( pReturn && pReturn->initWithSpriteFrame(spriteFrame) )
    {
        pReturn->autorelease();
        return pReturn;
    }
    CC_SAFE_DELETE(pReturn);
    return NULL;
}

bool CScale9Sprite::initWithSpriteFrameName(const char* spriteFrameName, Rect capInsets)
{
    CCAssert((SpriteFrameCache::getInstance()) != NULL, "sharedSpriteFrameCache must be non-NULL");

    SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameName);
    CCAssert(frame != NULL, "CCSpriteFrame must be non-NULL");

    if (NULL == frame) return false;

    bool pReturn = this->initWithSpriteFrame(frame, capInsets);
    return pReturn;
}

CScale9Sprite* CScale9Sprite::createWithSpriteFrameName(const char* spriteFrameName, Rect capInsets)
{
    CScale9Sprite* pReturn = new CScale9Sprite();
    if ( pReturn && pReturn->initWithSpriteFrameName(spriteFrameName, capInsets) )
    {
        pReturn->autorelease();
        return pReturn;
    }
    CC_SAFE_DELETE(pReturn);
    return NULL;
}

bool CScale9Sprite::initWithSpriteFrameName(const char* spriteFrameName)
{
    bool pReturn = this->initWithSpriteFrameName(spriteFrameName, Rect::ZERO);
    return pReturn;
}

CScale9Sprite* CScale9Sprite::createWithSpriteFrameName(const char* spriteFrameName)
{
    CCAssert(spriteFrameName != NULL, "spriteFrameName must be non-NULL");

    CScale9Sprite* pReturn = new CScale9Sprite();
    if ( pReturn && pReturn->initWithSpriteFrameName(spriteFrameName) )
    {
        pReturn->autorelease();
        return pReturn;
    }
    CC_SAFE_DELETE(pReturn);

    log("Could not allocate CScale9Sprite()");
    return NULL;
}

bool CScale9Sprite::initWithTexture(Texture2D* pTexture)
{
	return initWithTexture(pTexture, Rect::ZERO);
}

bool CScale9Sprite::initWithTexture(Texture2D* pTexture, Rect capInsets)
{
	if( pTexture )
	{
		SpriteBatchNode *batchnode = SpriteBatchNode::createWithTexture(pTexture, 9);
		bool pReturn = this->initWithBatchNode(batchnode, Rect::ZERO, capInsets);
		return pReturn;
	}
	return false;
}

CScale9Sprite* CScale9Sprite::createWithTexture(Texture2D* pTexture)
{
	CScale9Sprite* pReturn = new CScale9Sprite();
    if ( pReturn && pReturn->initWithTexture(pTexture) )
    {
        pReturn->autorelease();
        return pReturn;
    }
    CC_SAFE_DELETE(pReturn);
    return NULL;
}

CScale9Sprite* CScale9Sprite::createWithTexture(Texture2D* pTexture, Rect capInsets)
{
	CScale9Sprite* pReturn = new CScale9Sprite();
    if ( pReturn && pReturn->initWithTexture(pTexture, capInsets) )
    {
        pReturn->autorelease();
        return pReturn;
    }
    CC_SAFE_DELETE(pReturn);
    return NULL;
}

void CScale9Sprite::setTexture(Texture2D* pTexture)
{
	if( pTexture )
	{
		SpriteBatchNode *batchnode = SpriteBatchNode::createWithTexture(pTexture, 9);
		this->initWithBatchNode(batchnode, Rect::ZERO, Rect::ZERO);
	}
}

CScale9Sprite* CScale9Sprite::resizableSpriteWithCapInsets(Rect capInsets)
{
    CScale9Sprite* pReturn = new CScale9Sprite();
    if ( pReturn && pReturn->initWithBatchNode(_scale9Image, m_spriteRect, capInsets) )
    {
        pReturn->autorelease();
        return pReturn;
    }
    CC_SAFE_DELETE(pReturn);
    return NULL;
}

CScale9Sprite* CScale9Sprite::create()
{ 
    CScale9Sprite *pReturn = new CScale9Sprite();
    if (pReturn && pReturn->init())
    { 
        pReturn->autorelease();   
        return pReturn;
    } 
    CC_SAFE_DELETE(pReturn);
    return NULL;
}

/** sets the opacity.
 @warning If the the texture has premultiplied alpha then, the R, G and B channels will be modifed.
 Values goes from 0 to 255, where 255 means fully opaque.
 */

void CScale9Sprite::setPreferredSize(Size preferedSize)
{
    this->setContentSize(preferedSize);
    this->m_preferredSize = preferedSize;
}

Size CScale9Sprite::getPreferredSize()
{
    return this->m_preferredSize;
}

void CScale9Sprite::setCapInsets(Rect capInsets)
{
    if (!_scale9Image)
    {
        return;
    }
    Size contentSize = this->_contentSize;
    this->updateWithBatchNode(this->_scale9Image, this->m_spriteRect, m_bSpriteFrameRotated, capInsets);
    this->setContentSize(contentSize);
}

Rect CScale9Sprite::getCapInsets()
{
    return m_capInsets;
}

void CScale9Sprite::updateCapInset()
{
    Rect insets;
    if (this->m_insetLeft == 0 && this->m_insetTop == 0 && this->m_insetRight == 0 && this->m_insetBottom == 0)
    {
        insets = Rect::ZERO;
    }
    else
    {
        if (m_bSpriteFrameRotated)
        {
            insets = Rect(m_insetBottom,
                m_insetLeft,
                m_spriteRect.size.width-m_insetRight-m_insetLeft,
                m_spriteRect.size.height-m_insetTop-m_insetBottom);
        }
        else
        {
            insets = Rect(m_insetLeft,
                m_insetTop,
                m_spriteRect.size.width-m_insetLeft-m_insetRight,
                m_spriteRect.size.height-m_insetTop-m_insetBottom);
        }
    }
    this->setCapInsets(insets);
}

void CScale9Sprite::setOpacityModifyRGB(bool var)
{
    if (!_scale9Image)
    {
        return;
    }
    _opacityModifyRGB = var;

	for(auto child : _scale9Image->getChildren()){
		child->setOpacityModifyRGB(_opacityModifyRGB);
	}
}

bool CScale9Sprite::isOpacityModifyRGB()
{
    return _opacityModifyRGB;
}

void CScale9Sprite::updateDisplayedOpacity(GLubyte parentOpacity)
{
	if (!_scale9Image)
	{
		return;
	}
	Node::updateDisplayedOpacity(parentOpacity);

	for(auto child : _scale9Image->getChildren()){
		child->updateDisplayedOpacity(parentOpacity);
	}
}

void CScale9Sprite::updateDisplayedColor(const Color3B &color)
{
    Node::updateDisplayedColor(color);

	for(auto child : _scale9Image->getChildren()){
		child->updateDisplayedColor(color);
	}
}

void CScale9Sprite::setSpriteFrame(SpriteFrame * spriteFrame)
{
    SpriteBatchNode * batchnode = SpriteBatchNode::createWithTexture(spriteFrame->getTexture(), 9);
    this->updateWithBatchNode(batchnode, spriteFrame->getRect(), spriteFrame->isRotated(), Rect::ZERO);

    // Reset insets
    this->m_insetLeft = 0;
    this->m_insetTop = 0;
    this->m_insetRight = 0;
	this->m_insetBottom = 0;
}

float CScale9Sprite::getInsetLeft()
{
    return this->m_insetLeft;
}

float CScale9Sprite::getInsetTop()
{
    return this->m_insetTop;
}

float CScale9Sprite::getInsetRight()
{
    return this->m_insetRight;
}

float CScale9Sprite::getInsetBottom()
{
    return this->m_insetBottom;
}

void CScale9Sprite::setInsetLeft(float insetLeft)
{
    this->m_insetLeft = insetLeft;
    this->updateCapInset();
}

void CScale9Sprite::setInsetTop(float insetTop)
{
    this->m_insetTop = insetTop;
    this->updateCapInset();
}

void CScale9Sprite::setInsetRight(float insetRight)
{
    this->m_insetRight = insetRight;
    this->updateCapInset();
}

void CScale9Sprite::setInsetBottom(float insetBottom)
{
    this->m_insetBottom = insetBottom;
    this->updateCapInset();
}

void CScale9Sprite::visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags)
{
    if(this->m_positionsAreDirty)
    {
        this->updatePositions();
        this->m_positionsAreDirty = false;
    }
	Node::visit(renderer, parentTransform, parentFlags);
}

void CScale9Sprite::setColor(const Color3B& color)
{
    if (!_scale9Image)
    {
        return;
    }
    _color = color;

	for(auto child : _scale9Image->getChildren()){
		child->setColor(color);
	}
}

const Color3B& CScale9Sprite::getColor()
{
	return _color;
}

void CScale9Sprite::setOpacity(GLubyte opacity)
{
    if (!_scale9Image)
    {
        return;
    }
    _opacity = opacity;

	for(auto child : _scale9Image->getChildren()){
		child->setOpacity(opacity);
	}
}

GLubyte CScale9Sprite::getOpacity()
{
	return _opacity;
}

NS_CC_WIDGET_END
