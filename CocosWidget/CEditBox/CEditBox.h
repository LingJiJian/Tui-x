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

#ifndef __CEDIT_BOX_H__
#define __CEDIT_BOX_H__

#include "base/CCIMEDelegate.h"
#include "extensions/ExtensionMacros.h"
#include "../Widget.h"
#include "../Button.h"
#include "../WidgetProtocol.h"

NS_CC_WIDGET_BEGIN

class CEditBox;
class EditBoxImpl;


class CEditBoxDelegate
{
public:
    /**
     * @js NA
     * @lua NA
     */
    virtual ~CEditBoxDelegate() {};
    
    /**
     * This method is called when an edit box gains focus after keyboard is shown.
     * @param editBox The edit box object that generated the event.
     * @js NA
     * @lua NA
     */
    virtual void editBoxEditingDidBegin(CEditBox* editBox) {};
    
    
    /**
     * This method is called when an edit box loses focus after keyboard is hidden.
     * @param editBox The edit box object that generated the event.
     * @js NA
     * @lua NA
     */
    virtual void editBoxEditingDidEnd(CEditBox* editBox) {};
    
    /**
     * This method is called when the edit box text was changed.
     * @param editBox The edit box object that generated the event.
     * @param text The new text.
     * @js NA
     * @lua NA
     */
    virtual void editBoxTextChanged(CEditBox* editBox, const std::string& text) {};
    
    /**
     * This method is called when the return button was pressed or the outside area of keyboard was touched.
     * @param editBox The edit box object that generated the event.
     * @js NA
     * @lua NA
     */
    virtual void editBoxReturn(CEditBox* editBox) = 0;
    
};

/**
 * \brief Class for edit box.
 *
 * You can use this widget to gather small amounts of text from the user.
 * 
 */
 
class CEditBox
: public CButton
, public IMEDelegate
{
public:
    enum class KeyboardReturnType
    {
        DEFAULT,
        DONE,
        SEND,
        SEARCH,
        GO
    };
    
    /**
     * \brief The EditBox::InputMode defines the type of text that the user is allowed
     * to enter.
     */
    enum class InputMode
    {
        /**
         * The user is allowed to enter any text, including line breaks.
         */
        ANY,
        
        /**
         * The user is allowed to enter an e-mail address.
         */
        EMAIL_ADDRESS,
        
        /**
         * The user is allowed to enter an integer value.
         */
        NUMERIC,
        
        /**
         * The user is allowed to enter a phone number.
         */
        PHONE_NUMBER,
        
        /**
         * The user is allowed to enter a URL.
         */
        URL,
        
        /**
         * The user is allowed to enter a real number value.
         * This extends kEditBoxInputModeNumeric by allowing a decimal point.
         */
        DECIMAL,
        
        /**
         * The user is allowed to enter any text, except for line breaks.
         */
        SINGLE_LINE,
    };
    
    /**
     * \brief The EditBox::InputFlag defines how the input text is displayed/formatted.
     */
    enum class InputFlag
    {
        /**
         * Indicates that the text entered is confidential data that should be
         * obscured whenever possible. This implies EDIT_BOX_INPUT_FLAG_SENSITIVE.
         */
        PASSWORD,
        
        /**
         * Indicates that the text entered is sensitive data that the
         * implementation must never store into a dictionary or table for use
         * in predictive, auto-completing, or other accelerated input schemes.
         * A credit card number is an example of sensitive data.
         */
        SENSITIVE,
        
        /**
         * This flag is a hint to the implementation that during text editing,
         * the initial letter of each word should be capitalized.
         */
        INITIAL_CAPS_WORD,
        
        /**
         * This flag is a hint to the implementation that during text editing,
         * the initial letter of each sentence should be capitalized.
         */
        INITIAL_CAPS_SENTENCE,
        
        /**
         * Capitalize all characters automatically.
         */
        INTIAL_CAPS_ALL_CHARACTERS,
    };
    
	static CEditBox* create(const char* pNormal, const char* pSelected = NULL, const char* pDisabled = NULL);
	static CEditBox* createWith9Sprite(const Size& tSize, const char* pNormal, const char* pSelected = NULL, const char* pDisabled = NULL);
	static CEditBox* createWith9SpriteFrameName(const Size& tSize, const char* pNormal, const char* pSelected = NULL, const char* pDisabled = NULL);

	void initEditBoxImpl();

    CEditBox(void);
    virtual ~CEditBox(void);
    
    /**
     * Gets/Sets the delegate for edit box.
     * @lua NA
     */
    void setDelegate(CEditBoxDelegate* pDelegate);
    /**
     * @js NA
     * @lua NA
     */
    CEditBoxDelegate* getDelegate();
    
#if CC_ENABLE_SCRIPT_BINDING

    void registerScriptEditBoxHandler(int handler);
    
    void unregisterScriptEditBoxHandler(void);

    int  getScriptEditBoxHandler(void){ return _scriptEditBoxHandler ;}
    
#endif // #if CC_ENABLE_SCRIPT_BINDING
    
    /**
     * Set the text entered in the edit box.
     * @param pText The given text.
     */
    void setText(const char* pText);
    
    /**
     * Get the text entered in the edit box.
     * @return The text entered in the edit box.
     */
    const char* getText(void);
	
	/**
	 * Set the font.
	 * @param pFontName The font name.
	 * @param fontSize The font size.
	 */
	void setFont(const char* pFontName, int fontSize);
    
	/**
	 * Set the font name.
	 * @param pFontName The font name.
	 */
	void setFontName(const char* pFontName);
    
    /**
	 * Set the font size.
	 * @param fontSize The font size.
	 */
	void setFontSize(int fontSize);
    
    /**
     * Set the font color of the widget's text.
     */
    void setFontColor(const Color3B& color);
    
	/**
	 * Set the placeholder's font.
	 * @param pFontName The font name.
	 * @param fontSize The font size.
	 */
	void setPlaceholderFont(const char* pFontName, int fontSize);
    
    /**
	 * Set the placeholder's font name.
	 * @param pFontName The font name.
	 */
	void setPlaceholderFontName(const char* pFontName);
    
    /**
	 * Set the placeholder's font size.
	 * @param fontSize The font size.
	 */
	void setPlaceholderFontSize(int fontSize);
    
    /**
     * Set the font color of the placeholder text when the edit box is empty.
     * Not supported on IOS.
     */
    void setPlaceholderFontColor(const Color3B& color);
    
    /**
     * Set a text in the edit box that acts as a placeholder when an
     * edit box is empty.
     * @param pText The given text.
     */
    void setPlaceHolder(const char* pText);
    
    /**
     * Get a text in the edit box that acts as a placeholder when an
     * edit box is empty.
     */
    const char* getPlaceHolder(void);
    
    /**
     * Set the input mode of the edit box.
     * @param inputMode One of the EditBox::InputMode constants.
     */
    void setInputMode(InputMode inputMode);
    
    /**
     * Sets the maximum input length of the edit box.
     * Setting this value enables multiline input mode by default.
     * Available on Android, iOS and Windows Phone.
     *
     * @param maxLength The maximum length.
     */
    void setMaxLength(int maxLength);
    
    /**
     * Gets the maximum input length of the edit box.
     *
     * @return Maximum input length.
     */
    int getMaxLength();
    
    /**
     * Set the input flags that are to be applied to the edit box.
     * @param inputFlag One of the EditBox::InputFlag constants.
     */
    void setInputFlag(InputFlag inputFlag);
    
    /**
     * Set the return type that are to be applied to the edit box.
     * @param returnType One of the EditBox::KeyboardReturnType constants.
     */
    void setReturnType(CEditBox::KeyboardReturnType returnType);
    
    /* override functions */
    virtual void setPosition(const Vec2& pos) override;
    virtual void setVisible(bool visible) override;
    virtual void setContentSize(const Size& size) override;
	virtual void setAnchorPoint(const Vec2& anchorPoint) override;
    /**
     * @js NA
     * @lua NA
     */
    virtual void visit(Renderer *renderer, const Mat4 &parentTransform, uint32_t parentFlags) override;
    /**
     * @js NA
     * @lua NA
     */
	virtual void onEnter(void) override;
    /**
     * @js NA
     * @lua NA
     */
    virtual void onExit(void) override;
    /**
     * @js NA
     * @lua NA
     */
    virtual void keyboardWillShow(IMEKeyboardNotificationInfo& info) override;
    /**
     * @js NA
     * @lua NA
     */
    virtual void keyboardDidShow(IMEKeyboardNotificationInfo& info) override;
    /**
     * @js NA
     * @lua NA
     */
    virtual void keyboardWillHide(IMEKeyboardNotificationInfo& info) override;
    /**
     * @js NA
     * @lua NA
     */
    virtual void keyboardDidHide(IMEKeyboardNotificationInfo& info) override;
    
    /* callback funtions
     * @js NA
     * @lua NA
     */
    void touchDownAction(Ref *sender);
    

protected:
    void updatePosition(float dt);
    EditBoxImpl*      _editBoxImpl;
    CEditBoxDelegate*  _delegate;
    
    InputMode    _editBoxInputMode;
    InputFlag    _editBoxInputFlag;
    CEditBox::KeyboardReturnType  _keyboardReturnType;
    
    std::string _text;
    std::string _placeHolder;
    
    std::string _fontName;
    std::string _placeholderFontName;
    
    int _fontSize;
    int _placeholderFontSize;
    
    Color3B _colText;
    Color3B _colPlaceHolder;
    
    int   _maxLength;
    float _adjustHeight;
#if CC_ENABLE_SCRIPT_BINDING
    int   _scriptEditBoxHandler;
#endif
};

NS_CC_WIDGET_END

#endif /* __CEDIT_BOX_H__ */