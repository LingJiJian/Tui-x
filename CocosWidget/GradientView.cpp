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
#include "GradientView.h"

NS_CC_WIDGET_BEGIN

CGradientView::CGradientView()
{

}

CGradientView::~CGradientView()
{

}

CGradientView* CGradientView::create()
{
	CGradientView* pRet = new CGradientView();
	if( pRet && pRet->init() )
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

CGradientView* CGradientView::create(const Color4B& tStart, const Color4B& tEnd)
{
	CGradientView* pRet = new CGradientView();
	if( pRet && pRet->initWithColor(tStart, tEnd) )
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

CGradientView* CGradientView::create(const Color4B& tStart, const Color4B& tEnd, const Vec2& v)
{
	CGradientView* pRet = new CGradientView();
	if( pRet && pRet->initWithColor(tStart, tEnd, v) )
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

bool CGradientView::init()
{
	return initWithColor(Color4B(0, 0, 0, 255), Color4B(0, 0, 0, 255));
}

bool CGradientView::initWithColor(const Color4B& tStart, const Color4B& tEnd)
{
	return initWithColor(tStart, tEnd, Vec2(0, -1));
}

bool CGradientView::initWithColor(const Color4B& tStart, const Color4B& tEnd, const Vec2& v)
{
	m_tEndColor.r   = tEnd.r;
	m_tEndColor.g   = tEnd.g;
	m_tEndColor.b   = tEnd.b;

	m_cEndOpacity   = tEnd.a;
	m_cStartOpacity = tStart.a;
	m_tAlongVector  = v;

	m_bCompressedInterpolation = true;

	return CColorView::initWithColor(Color4B(tStart.r, tStart.g, tStart.b, 255));
}

void CGradientView::setStartColor(const Color3B& tColor)
{
	m_tStartColor = tColor;
}

const Color3B& CGradientView::getStartColor()
{
	return m_tStartColor;
}

void CGradientView::setEndColor(const Color3B& tColor)
{
	m_tEndColor = tColor;
	updateColor();
}

const Color3B& CGradientView::getEndColor()
{
	return m_tEndColor;
}

void CGradientView::setStartOpacity(GLubyte cOpacity)
{
	m_cStartOpacity = cOpacity;
	updateColor();
}

GLubyte CGradientView::getStartOpacity()
{
	return m_cStartOpacity;
}

void CGradientView::setEndOpacity(GLubyte cOpacity)
{
	m_cEndOpacity = cOpacity;
	updateColor();
}

GLubyte CGradientView::getEndOpacity()
{
	return m_cEndOpacity;
}

void CGradientView::setVector(const Vec2& tPoint)
{
	m_tAlongVector = tPoint;
	updateColor();
}

const Vec2& CGradientView::getVector()
{
	return m_tAlongVector;
}

void CGradientView::setCompressedInterpolation(bool bCompressedInterpolation)
{
	m_bCompressedInterpolation = bCompressedInterpolation;
	updateColor();
}

bool CGradientView::isCompressedInterpolation()
{
	return m_bCompressedInterpolation;
}

void CGradientView::updateColor()
{
	CColorView::updateColor();

    float h = m_tAlongVector.getLength();
    if( (int)h == 0 )
        return;

    float c = sqrtf(2.0f);
    Vec2 u = Vec2(m_tAlongVector.x / h, m_tAlongVector.y / h);

    // Compressed Interpolation mode
    if( m_bCompressedInterpolation )
    {
        float h2 = 1 / ( fabsf(u.x) + fabsf(u.y) );
        u = u * h2 * (float)c;
    }

    float opacityf = (float)_displayedOpacity / 255.0f;

    Color4F S(
        _displayedColor.r / 255.0f,
        _displayedColor.g / 255.0f,
        _displayedColor.b / 255.0f,
        m_cStartOpacity * opacityf / 255.0f
    );

    Color4F E(
        m_tEndColor.r / 255.0f,
        m_tEndColor.g / 255.0f,
        m_tEndColor.b / 255.0f,
        m_cEndOpacity * opacityf / 255.0f
    );

    // (-1, -1)
    m_pSquareColors[0].r = E.r + (S.r - E.r) * ((c + u.x + u.y) / (2.0f * c));
    m_pSquareColors[0].g = E.g + (S.g - E.g) * ((c + u.x + u.y) / (2.0f * c));
    m_pSquareColors[0].b = E.b + (S.b - E.b) * ((c + u.x + u.y) / (2.0f * c));
    m_pSquareColors[0].a = E.a + (S.a - E.a) * ((c + u.x + u.y) / (2.0f * c));
    // (1, -1)
    m_pSquareColors[1].r = E.r + (S.r - E.r) * ((c - u.x + u.y) / (2.0f * c));
    m_pSquareColors[1].g = E.g + (S.g - E.g) * ((c - u.x + u.y) / (2.0f * c));
    m_pSquareColors[1].b = E.b + (S.b - E.b) * ((c - u.x + u.y) / (2.0f * c));
    m_pSquareColors[1].a = E.a + (S.a - E.a) * ((c - u.x + u.y) / (2.0f * c));
    // (-1, 1)
    m_pSquareColors[2].r = E.r + (S.r - E.r) * ((c + u.x - u.y) / (2.0f * c));
    m_pSquareColors[2].g = E.g + (S.g - E.g) * ((c + u.x - u.y) / (2.0f * c));
    m_pSquareColors[2].b = E.b + (S.b - E.b) * ((c + u.x - u.y) / (2.0f * c));
    m_pSquareColors[2].a = E.a + (S.a - E.a) * ((c + u.x - u.y) / (2.0f * c));
    // (1, 1)
    m_pSquareColors[3].r = E.r + (S.r - E.r) * ((c - u.x - u.y) / (2.0f * c));
    m_pSquareColors[3].g = E.g + (S.g - E.g) * ((c - u.x - u.y) / (2.0f * c));
    m_pSquareColors[3].b = E.b + (S.b - E.b) * ((c - u.x - u.y) / (2.0f * c));
    m_pSquareColors[3].a = E.a + (S.a - E.a) * ((c - u.x - u.y) / (2.0f * c));
}

NS_CC_WIDGET_END