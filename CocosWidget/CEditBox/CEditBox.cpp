/****************************************************************************
 Copyright (c) 2010-2012 cocos2d-x.org
 Copyright (c) 2012 James Chen
 
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

#include "CEditBox.h"
#include "CEditBoxImpl.h"

NS_CC_WIDGET_BEGIN

static const float CHECK_EDITBOX_POSITION_INTERVAL = 0.1f;

CEditBox::CEditBox(void)
: _editBoxImpl(nullptr)
, _delegate(nullptr)
, _editBoxInputMode(CEditBox::InputMode::SINGLE_LINE)
, _editBoxInputFlag(CEditBox::InputFlag::INTIAL_CAPS_ALL_CHARACTERS)
, _keyboardReturnType(KeyboardReturnType::DEFAULT)
, _fontSize(-1)
, _placeholderFontSize(-1)
, _colText(Color3B::WHITE)
, _colPlaceHolder(Color3B::GRAY)
, _maxLength(0)
, _adjustHeight(0.0f)
#if CC_ENABLE_SCRIPT_BINDING
, _scriptEditBoxHandler(0)
#endif
{
}

CEditBox::~CEditBox(void)
{
    CC_SAFE_DELETE(_editBoxImpl);
#if CC_ENABLE_SCRIPT_BINDING
    unregisterScriptEditBoxHandler();
#endif
}

void CEditBox::touchDownAction(Ref *sender)
{
    _editBoxImpl->openKeyboard();
}

CEditBox* CEditBox::create(const char* pNormal, const char* pSelected, const char* pDisabled)
{
	CEditBox* pRet = new CEditBox();

	if (pRet && pRet->initWithFile(pNormal, pSelected, pDisabled))
	{
		pRet->autorelease();
		pRet->initEditBoxImpl();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

CEditBox* CEditBox::createWith9Sprite(const Size& tSize, const char* pNormal, const char* pSelected, const char* pDisabled)
{
    CEditBox* pRet = new CEditBox();

	if (pRet && pRet->initWith9Sprite(tSize, pNormal, pSelected, pDisabled))
	{
		pRet->autorelease();
		pRet->initEditBoxImpl();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

CEditBox* CEditBox::createWith9SpriteFrameName(const Size& tSize, const char* pNormal, const char* pSelected, const char* pDisabled)
{
	CEditBox* pRet = new CEditBox();

	if (pRet && pRet->initWith9SpriteFrameName(tSize, pNormal, pSelected, pDisabled))
	{
		pRet->autorelease();
		pRet->initEditBoxImpl();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

void CEditBox::initEditBoxImpl()
{
	_editBoxImpl = __createSystemEditBox(this);
	_editBoxImpl->initWithSize(this->getContentSize());
	_editBoxImpl->setInputMode(CEditBox::InputMode::ANY);
	this->setOnClickListener(this, ccw_click_selector(CEditBox::touchDownAction));
}
/*
bool EditBox::initWithSizeAndBackgroundSprite(const Size& size, CScale9Sprite* pPressed9SpriteBg)
{
    if (ControlButton::initWithBackgroundSprite(pPressed9SpriteBg))
    {
        _editBoxImpl = __createSystemEditBox(this);
        _editBoxImpl->initWithSize(size);
        _editBoxImpl->setInputMode(EditBox::InputMode::ANY);
        
        this->setZoomOnTouchDown(false);
        this->setPreferredSize(size);
        this->setPosition(Vec2(0, 0));
        this->addTargetWithActionForControlEvent(this, cccontrol_selector(EditBox::touchDownAction), Control::EventType::TOUCH_UP_INSIDE);
        
        return true;
    }
    return false;
}
*/
void CEditBox::setDelegate(CEditBoxDelegate* pDelegate)
{
    _delegate = pDelegate;
    if (_editBoxImpl != nullptr)
    {
        _editBoxImpl->setDelegate(pDelegate);
    }
}

CEditBoxDelegate* CEditBox::getDelegate()
{
    return _delegate;
}

void CEditBox::setText(const char* pText)
{
    if (pText != nullptr)
    {
        _text = pText;
        if (_editBoxImpl != nullptr)
        {
            _editBoxImpl->setText(pText);
        }
    }
}

const char* CEditBox::getText(void)
{
    if (_editBoxImpl != nullptr)
    {
		const char* pText = _editBoxImpl->getText();
		if(pText != nullptr)
			return pText;
    }
    
    return "";
}

void CEditBox::setFont(const char* pFontName, int fontSize)
{
    _fontName = pFontName;
    _fontSize = fontSize;
    if (pFontName != nullptr)
    {
        if (_editBoxImpl != nullptr)
        {
            _editBoxImpl->setFont(pFontName, fontSize);
        }
    }
}

void CEditBox::setFontName(const char* pFontName)
{
    _fontName = pFontName;
    if (_editBoxImpl != nullptr && _fontSize != -1)
    {
        _editBoxImpl->setFont(pFontName, _fontSize);
    }
}

void CEditBox::setFontSize(int fontSize)
{
    _fontSize = fontSize;
    if (_editBoxImpl != nullptr && _fontName.length() > 0)
    {
        _editBoxImpl->setFont(_fontName.c_str(), _fontSize);
    }
}

void CEditBox::setFontColor(const Color3B& color)
{
    _colText = color;
    if (_editBoxImpl != nullptr)
    {
        _editBoxImpl->setFontColor(color);
    }
}

void CEditBox::setPlaceholderFont(const char* pFontName, int fontSize)
{
    _placeholderFontName = pFontName;
    _placeholderFontSize = fontSize;
    if (pFontName != nullptr)
    {
        if (_editBoxImpl != nullptr)
        {
            _editBoxImpl->setPlaceholderFont(pFontName, fontSize);
        }
    }
}

void CEditBox::setPlaceholderFontName(const char* pFontName)
{
    _placeholderFontName = pFontName;
    if (_editBoxImpl != nullptr && _placeholderFontSize != -1)
    {
        _editBoxImpl->setPlaceholderFont(pFontName, _fontSize);
    }
}

void CEditBox::setPlaceholderFontSize(int fontSize)
{
    _placeholderFontSize = fontSize;
    if (_editBoxImpl != nullptr && _placeholderFontName.length() > 0)
    {
        _editBoxImpl->setPlaceholderFont(_placeholderFontName.c_str(), _fontSize);
    }
}

void CEditBox::setPlaceholderFontColor(const Color3B& color)
{
    _colText = color;
    if (_editBoxImpl != nullptr)
    {
        _editBoxImpl->setPlaceholderFontColor(color);
    }
}

void CEditBox::setPlaceHolder(const char* pText)
{
    if (pText != nullptr)
    {
        _placeHolder = pText;
        if (_editBoxImpl != nullptr)
        {
            _editBoxImpl->setPlaceHolder(pText);
        }
    }
}

const char* CEditBox::getPlaceHolder(void)
{
    return _placeHolder.c_str();
}

void CEditBox::setInputMode(CEditBox::InputMode inputMode)
{
    _editBoxInputMode = inputMode;
    if (_editBoxImpl != nullptr)
    {
        _editBoxImpl->setInputMode(inputMode);
    }
}

void CEditBox::setMaxLength(int maxLength)
{
    _maxLength = maxLength;
    if (_editBoxImpl != nullptr)
    {
        _editBoxImpl->setMaxLength(maxLength);
    }
}


int CEditBox::getMaxLength()
{
    return _maxLength;
}

void CEditBox::setInputFlag(CEditBox::InputFlag inputFlag)
{
    _editBoxInputFlag = inputFlag;
    if (_editBoxImpl != nullptr)
    {
        _editBoxImpl->setInputFlag(inputFlag);
    }
}

void CEditBox::setReturnType(CEditBox::KeyboardReturnType returnType)
{
    if (_editBoxImpl != nullptr)
    {
        _editBoxImpl->setReturnType(returnType);
    }
}

/* override function */
void CEditBox::setPosition(const Vec2& pos)
{
	CButton::setPosition(pos);
    if (_editBoxImpl != nullptr)
    {
        _editBoxImpl->setPosition(pos);
    }
}

void CEditBox::setVisible(bool visible)
{
    CButton::setVisible(visible);
    if (_editBoxImpl != nullptr)
    {
        _editBoxImpl->setVisible(visible);
    }
}

void CEditBox::setContentSize(const Size& size)
{
	CButton::setContentSize(size);
    if (_editBoxImpl != nullptr)
    {
        _editBoxImpl->setContentSize(size);
    }
}

void CEditBox::setAnchorPoint(const Vec2& anchorPoint)
{
	CButton::setAnchorPoint(anchorPoint);
    if (_editBoxImpl != nullptr)
    {
        _editBoxImpl->setAnchorPoint(anchorPoint);
    }
}

void CEditBox::visit(Renderer *renderer, const Mat4 &parentTransform, uint32_t parentFlags)
{
	CButton::visit(renderer, parentTransform, parentFlags);
    if (_editBoxImpl != nullptr)
    {
        _editBoxImpl->visit();
    }
}

void CEditBox::onEnter(void)
{
#if CC_ENABLE_SCRIPT_BINDING
    if (_scriptType == kScriptTypeJavascript)
    {
        if (ScriptEngineManager::sendNodeEventToJSExtended(this, kNodeOnEnter))
            return;
    }
#endif
    
	CButton::onEnter();
    if (_editBoxImpl != nullptr)
    {
        _editBoxImpl->onEnter();
    }
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
    this->schedule(schedule_selector(CEditBox::updatePosition), CHECK_EDITBOX_POSITION_INTERVAL);
#endif
}

void CEditBox::updatePosition(float dt)
{
    if (nullptr != _editBoxImpl) {
        _editBoxImpl->updatePosition(dt);
    }
}


void CEditBox::onExit(void)
{
	CButton::onExit();
    if (_editBoxImpl != nullptr)
    {
        // remove system edit control
        _editBoxImpl->closeKeyboard();
    }
}

static Rect getRect(Node * pNode)
{
	Size contentSize = pNode->getContentSize();
	Rect rect = Rect(0, 0, contentSize.width, contentSize.height);
	return RectApplyTransform(rect, pNode->getNodeToWorldTransform());
}

void CEditBox::keyboardWillShow(IMEKeyboardNotificationInfo& info)
{
    // CCLOG("CCEditBox::keyboardWillShow");
    Rect rectTracked = getRect(this);
	// some adjustment for margin between the keyboard and the edit box.
	rectTracked.origin.y -= 4;

    // if the keyboard area doesn't intersect with the tracking node area, nothing needs to be done.
    if (!rectTracked.intersectsRect(info.end))
    {
        CCLOG("needn't to adjust view layout.");
        return;
    }
    
    // assume keyboard at the bottom of screen, calculate the vertical adjustment.
    _adjustHeight = info.end.getMaxY() - rectTracked.getMinY();
    // CCLOG("CCEditBox:needAdjustVerticalPosition(%f)", _adjustHeight);
    
    if (_editBoxImpl != nullptr)
    {
        _editBoxImpl->doAnimationWhenKeyboardMove(info.duration, _adjustHeight);
    }
}

void CEditBox::keyboardDidShow(IMEKeyboardNotificationInfo& info)
{
	
}

void CEditBox::keyboardWillHide(IMEKeyboardNotificationInfo& info)
{
    // CCLOG("CCEditBox::keyboardWillHide");
    if (_editBoxImpl != nullptr)
    {
        _editBoxImpl->doAnimationWhenKeyboardMove(info.duration, -_adjustHeight);
    }
}

void CEditBox::keyboardDidHide(IMEKeyboardNotificationInfo& info)
{
	
}

#if CC_ENABLE_SCRIPT_BINDING
void CEditBox::registerScriptEditBoxHandler(int handler)
{
    unregisterScriptEditBoxHandler();
    _scriptEditBoxHandler = handler;
}

void CEditBox::unregisterScriptEditBoxHandler(void)
{
    if (0 != _scriptEditBoxHandler)
    {
        ScriptEngineManager::getInstance()->getScriptEngine()->removeScriptHandler(_scriptEditBoxHandler);
        _scriptEditBoxHandler = 0;
    }
}
#endif

NS_CC_WIDGET_END
