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
#ifndef __CCWIDGET_TEXTRICH_H__
#define __CCWIDGET_TEXTRICH_H__

#include "cocos2d.h"
#include "WitlsMacros.h"
#include "WidgetMacros.h"
#include "WidgetProtocol.h"
#include "Widget.h"
#include "Layout.h"
#include <vector>

NS_CC_WIDGET_BEGIN

enum class Type
{
	TEXT,
	IMAGE,
	ANIM,
	NEWLINE,
};

enum class RichTextAlign
{
	DESIGN_CENTER,
	REAL_CENTER,
	LEFT_TOP,
};

class RichElement : public Ref
{
public:
	
	RichElement(){};
	virtual ~RichElement(){};
	bool init(int tag, const Color3B& color=Color3B::WHITE, GLubyte opacity=255);
protected:
	Type _type;
	int _tag;
	Color3B _color;
	GLubyte _opacity;
	std::string _data;
	friend class CTextRich;
};

class RichElementText : public RichElement
{
public:
	RichElementText(){_type = Type::TEXT;};
	virtual ~RichElementText(){};
	bool init(int tag, const Color3B& color, const std::string& text, const std::string& fontName, float fontSize,bool isUnderLine,bool isOutLine,const Color4B& outLineColor);
	static RichElementText* create(int tag, const Color3B& color, const std::string& text, const std::string& fontName, float fontSize,bool isUnderLine = false,bool isOutLine = false,const Color4B& outLineColor=Color4B::WHITE);
protected:
	std::string _text;
	std::string _fontName;
	float _fontSize;
	bool _isUnderLine;
	bool _isOutLine;
	Color4B _outLineColor;
	friend class CTextRich;

};

class RichElementImage : public RichElement
{
public:
	RichElementImage(){_type = Type::IMAGE;};
	virtual ~RichElementImage(){};
	bool init(int tag, const std::string& filePath);
	static RichElementImage* create(int tag,const std::string& filePath);
protected:
	std::string _filePath;
	friend class CTextRich;
};

class RichElementNewline : public RichElement
{
public:
	RichElementNewline(){_type = Type::NEWLINE;};
	virtual ~RichElementNewline(){};
	bool init(int tag);
	static RichElementNewline* create(int tag);
protected:
	friend class CTextRich;
};

class RichElementAnim : public RichElement
{
public:
	RichElementAnim(){_type = Type::ANIM;};
	bool init(int tag,const std::string& filePath,bool isLoop,float delay);
	static RichElementAnim* create(int tag,const std::string& filinsertElementePath,bool isLoop,float delay);
protected:
	std::string _filePath;
	bool _isLoop;
	float _delay;
	friend class CTextRich;
};

class RichCacheElement : public Ref
{
public:
	RichCacheElement():_isUse(false),_node(nullptr){};
	virtual ~RichCacheElement();
	bool init(bool isUse, Node* node);
	static RichCacheElement* create(bool isUse, Node* node);
protected:
	bool _isUse;
	Node* _node;
	friend class CTextRich;
};
//////////////////////////////////////////////////////////////////////////

struct RenderElement
{
	Type _type;
	std::string strChar;
	int width;
	int height;
	bool isOutLine;
	bool isUnderLine;
	int fontSize;
	std::string fontName;
	Color3B color;
	std::string data;
	std::string img;
	std::string anim;
	bool isLoop;
	float delay;
	bool isNewLine;
	Vec2 pos;
public:
	RenderElement clone(){
		RenderElement copy;
		copy._type = _type;
		copy.strChar = strChar;
		copy.width = width;
		copy.height = height;
		copy.isOutLine = isOutLine;
		copy.isUnderLine = isUnderLine;
		copy.fontSize = fontSize;
		copy.fontName = fontName;
		copy.color = color;
		copy.data = data;
		copy.img = img;
		copy.anim = anim;
		copy.isLoop = isLoop;
		copy.delay = delay;
		copy.isNewLine = isNewLine;
		copy.pos = pos;
		return copy;
	}
	friend class CTextRich;
};

//////////////////////////////////////////////////////////////////////////
/**
 * class  : CTextRich
 * author : Lingjijian
 * email  : 342854406@qq.com
 * descpt : text rich define
 */
class CTextRich :  public Node, public CWidget, public CTextRichClickableProtocol
{
public:
	CTextRich();
	virtual ~CTextRich();
	static CTextRich* create();

	void insertElement(int tag,const char* pString, const char* pFontName = NULL, float fFontSize = 0.0f, const Color3B& tColor = Color3B::WHITE,bool isUnderLine = false,bool isOutLine = false,const Color4B& outLineColor=Color4B::WHITE);
	void insertElement(int tag,const char* path,float delay,bool isLoop);
	void insertElement(int tag,const char* path);

	CC_SYNTHESIZE(int,_maxLineWidth,MaxLineWidth);
	CC_SYNTHESIZE_READONLY(int,_realLineWidth,RealLineWidth);
	CC_SYNTHESIZE_READONLY(int,_realLineHeight,RealLineHeight);
	CC_SYNTHESIZE(RichTextAlign,_alignType,AlignType)

	void setVerticalSpace(float space);
	void removeAllElements();
	void reloadData();
	Node* getContainer(){ return _innerContainer; };

public:
	virtual CWidgetTouchModel onTouchBegan(Touch* pTouch);
	virtual void onTouchMoved(Touch* pTouch, float fDuration);
	virtual void onTouchEnded(Touch* pTouch, float fDuration);
	virtual void onTouchCancelled(Touch* pTouch, float fDuration);
	
protected:
	virtual bool init() override;
	void formarRenderers();

	Label* getCacheLabel();
	Sprite* getCacheImage();
	Label* _getMesureLabel();
	Size _getMesureSpriteContentSize(const std::string& path);
	DrawNode* _getDrawNode();
	Label* makeLabel(Label* pTarget,RenderElement elem,std::string strChar);
	Sprite* makeImage(Sprite* pTarget, RenderElement elem);
	Sprite* makeAnim(Sprite* pTarget, RenderElement elem);
protected:
	Vector<RichElement*> _richElements;
	std::vector<RenderElement> _elemRenderArr;
	Vector<RichCacheElement*> _cacheLabElements;
	Vector<RichCacheElement*> _cacheImgElements;
	Label* _mesureLabel;
	Sprite* _mesureSprite;
	DrawNode* _drawNode;
	float _verticalSpace;
	Node *_innerContainer;
};

NS_CC_WIDGET_END


#endif //__CCWIDGET_TEXTRICH_H__