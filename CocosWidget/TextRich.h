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

class RichElement : public Ref
{
public:
	enum class Type
	{
		TEXT,
		IMAGE,
		CUSTOM
	};
	RichElement(){};
	virtual ~RichElement(){};
	bool init(int tag, const Color3B& color=Color3B::WHITE, GLubyte opacity=255);
protected:
	Type _type;
	int _tag;
	Color3B _color;
	GLubyte _opacity;
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
	bool init(int tag, const std::string& filePath,bool isAnim,float delay,bool isLoop);
	static RichElementImage* create(int tag,const std::string& filePath,bool isAnim=false,float delay=0.0f,bool isLoop=true);
protected:
	std::string _filePath;
	Rect _textureRect;
	int _textureType;
	bool _isAnim;
	bool _isLoop;
	float _delay;
	friend class CTextRich;
};

class RichElementCustomNode : public RichElement
{
public:
	RichElementCustomNode(){_type = Type::CUSTOM;};
	virtual ~RichElementCustomNode(){CC_SAFE_RELEASE(_customNode);};
	bool init(int tag, Node* customNode);
	static RichElementCustomNode* create(int tag, Node* customNode);
protected:
	Node* _customNode;
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
	void insertElement(int tag,const char* path, bool isAnim,float delay,bool isLoop );
	void insertElement(int tag,Node* pNode);

	CC_SYNTHESIZE(int,_maxLineWidth,MaxLineWidth);
	void setVerticalSpace(float space);
	void removeAllElements();
	void reloadData();
	std::vector< std::string > split(const std::string& s,const std::string& delim);
	std::string getSubStringOfUTF8String(const std::string& str,std::string::size_type start,std::string::size_type length);
	virtual void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) override;
public:
	virtual CWidgetTouchModel onTouchBegan(Touch* pTouch);
	virtual void onTouchMoved(Touch* pTouch, float fDuration);
	virtual void onTouchEnded(Touch* pTouch, float fDuration);
	virtual void onTouchCancelled(Touch* pTouch, float fDuration);
	
protected:
	virtual bool init() override;
	void onDraw(const Mat4 &transform, uint32_t flags);
	CustomCommand _customCommand;

	void pushToContainer(Node* renderer);
	void handleTextRenderer(const std::string& text, const std::string& fontName, float fontSize,bool isUnder, const Color3B& color, GLubyte opacity,int tag,bool isOutLine,const Color4B& outLineColor);
	void handleImageRenderer(const std::string& fileParh, const Color3B& color, GLubyte opacity,int tag,bool isAnim,float delay,bool isLoop);
	void handleCustomRenderer(Node* renderer,int tag);
	void formarRenderers();
	void addNewLine();

	Label* getCacheLabel();
	Sprite* getCacheImage();
	Node* makeLabel(Label* pTarget,const Color3B& color, const std::string& text, const std::string& fontName, int fontSize,bool isUnder, int tag,bool isOutLine,const Color4B& outLineColor);
	Node* makeImage(Sprite* pTarget, const std::string& filePath,int tag,bool isAnim,float delay,bool isLoop);
protected:
	Vector<RichElement*> _richElements;
	std::vector<Vector<Node*>*> _elementRenders;
	Vector<RichCacheElement*> _cacheLabElements;
	Vector<RichCacheElement*> _cacheImgElements;
	std::set<int> _underLineTags;
	float _leftSpaceWidth;
	float _verticalSpace;
};

NS_CC_WIDGET_END


#endif //__CCWIDGET_TEXTRICH_H__