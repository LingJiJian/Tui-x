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
#include "WidgetProtocol.h"
#if USING_LUA
#include "CCLuaEngine.h"
#endif

NS_CC_WIDGET_BEGIN



CDataSourceAdapterProtocol::CDataSourceAdapterProtocol()
: m_pDataSourceAdapterListener(NULL)
, m_pDataSourceAdapterHandler(NULL)
#if USING_LUA
, m_nDataSourceAdapterScriptHandler(0)
#endif
{
	
}

CDataSourceAdapterProtocol::~CDataSourceAdapterProtocol()
{
#if USING_LUA
	removeDataSourceAdapterScriptHandler();
#endif
}

void CDataSourceAdapterProtocol::setDataSourceAdapter(Ref* pListener, SEL_DataSoucreAdapterHandler pHandler)
{
	m_pDataSourceAdapterListener = pListener;
	m_pDataSourceAdapterHandler = pHandler;
}

Ref* CDataSourceAdapterProtocol::executeDataSourceAdapterHandler(Ref* pConvertCell, unsigned int uIdx)
{
	if( m_pDataSourceAdapterListener && m_pDataSourceAdapterHandler )
	{
		return (m_pDataSourceAdapterListener->*m_pDataSourceAdapterHandler)(pConvertCell, uIdx);
	}
#if USING_LUA
	else if( m_nDataSourceAdapterScriptHandler != 0 )
	{
		return executeDataSourceAdapterScriptHandler(pConvertCell, uIdx);
	}
#endif
	return NULL;
}

#if USING_LUA
Ref* CDataSourceAdapterProtocol::executeDataSourceAdapterScriptHandler(Ref* pConvertCell, unsigned int uIdx)
{
	if( m_nDataSourceAdapterScriptHandler != 0 )
	{
		LuaEngine* pEngine = LuaEngine::getInstance();
		LuaStack* pStack = pEngine->getLuaStack();

		if( pConvertCell )
		{
			pStack->pushObject(pConvertCell, "Ref");
		}
		else
		{
			pStack->pushNil();
		}
		pStack->pushInt(uIdx);

		__Array pRetArray;
		pRetArray.initWithCapacity(1);

		int nRet = pStack->executeFunctionReturnArray(m_nDataSourceAdapterScriptHandler, 2, 1, pRetArray);
		CCAssert(pRetArray.count() > 0, "return num = 0");

		Ref* pReturnObject = pRetArray.getObjectAtIndex(0);
		pStack->clean();

		return pReturnObject;
	}
	return NULL;
}

void CDataSourceAdapterProtocol::setDataSourceAdapterScriptHandler(int nHandler)
{
	removeDataSourceAdapterScriptHandler();
	m_nDataSourceAdapterScriptHandler = nHandler;
}

void CDataSourceAdapterProtocol::removeDataSourceAdapterScriptHandler()
{
	if( m_nDataSourceAdapterScriptHandler != 0 )
	{
		ScriptEngineManager::getInstance()->getScriptEngine()->removeScriptHandler(m_nDataSourceAdapterScriptHandler);
		m_nDataSourceAdapterScriptHandler = 0;
	}
}
#endif


CTextRichClickableProtocol::CTextRichClickableProtocol()
: m_pRichTextClickListener(NULL)
, m_pRichTextClickHandler(NULL)
#if USING_LUA
, m_nRichTextClickScriptHandler(0)
#endif
{

}

CTextRichClickableProtocol::~CTextRichClickableProtocol()
{
#if USING_LUA
	removeOnTextRichClickScriptHandler();
#endif
}

void CTextRichClickableProtocol::setOnTextRichClickListener(Ref* pListener, SEL_TextRichClickHandler pHandler)
{
	m_pRichTextClickListener = pListener;
	m_pRichTextClickHandler = pHandler;
}

void CTextRichClickableProtocol::executeTextRichClickHandler(Ref* pSender, int tag)
{
	if( m_pRichTextClickListener && m_pRichTextClickHandler )
	{
		(m_pRichTextClickListener->*m_pRichTextClickHandler)(pSender, tag);
	}
#if USING_LUA
	else if( m_nRichTextClickScriptHandler != 0 )
	{
		executeTextRichScriptHandler(pSender, tag);
	}
#endif
}

#if USING_LUA
void CTextRichClickableProtocol::executeTextRichScriptHandler(Ref* pSender, int tag)
{
	if( m_nRichTextClickScriptHandler != 0 )
	{
		LuaEngine* pEngine = LuaEngine::getInstance();
		LuaStack* pStack = pEngine->getLuaStack();

		pStack->pushObject(pSender, "Ref");

		if( tag > 0 )
		{
			pStack->pushInt(tag);
		}
		else
		{
			pStack->pushNil();
		}

		pStack->executeFunctionByHandler(m_nRichTextClickScriptHandler, 2);
		pStack->clean();
	}
}

void CTextRichClickableProtocol::setOnTextRichClickScriptHandler(int nHandler)
{
	removeOnTextRichClickScriptHandler();
	m_nRichTextClickScriptHandler = nHandler;
}

void CTextRichClickableProtocol::removeOnTextRichClickScriptHandler()
{
	if( m_nRichTextClickScriptHandler != 0 )
	{
		ScriptEngineManager::getInstance()->getScriptEngine()->removeScriptHandler(m_nRichTextClickScriptHandler);
		m_nRichTextClickScriptHandler = 0;
	}
}
#endif


CLayoutableProtocol::CLayoutableProtocol()
: m_pSelectedWidget(NULL)
, m_eSelectedWidgetTouchModel(eWidgetTouchNone)
{

}

CLayoutableProtocol::~CLayoutableProtocol()
{
	
}

CPageChangeableProtocol::CPageChangeableProtocol()
: m_pPageChangedListener(NULL)
, m_pPageChangedHandler(NULL)
, m_nPageIndex(0)
#if USING_LUA
, m_nPageChangedScriptHandler(0)
#endif
{

}

CPageChangeableProtocol::~CPageChangeableProtocol()
{
#if USING_LUA
	removeOnPageChangedScriptHandler();
#endif
}

void CPageChangeableProtocol::setOnPageChangedListener(Ref* pListener, SEL_PageChangedHandler pHandler)
{
	m_pPageChangedListener = pListener;
	m_pPageChangedHandler = pHandler;
}

void CPageChangeableProtocol::executePageChangedHandler(Ref* pSender, unsigned int uPageIdx)
{
	if( m_pPageChangedListener && m_pPageChangedHandler )
	{
		(m_pPageChangedListener->*m_pPageChangedHandler)(pSender, uPageIdx);
	}
#if USING_LUA
	else if( m_nPageChangedScriptHandler != 0 )
	{
		executePageChangedScriptHandler(pSender, uPageIdx);
	}
#endif
}

#if USING_LUA
void CPageChangeableProtocol::executePageChangedScriptHandler(Ref* pSender, unsigned int uPageIdx)
{
	if( m_nPageChangedScriptHandler != 0 )
	{
		LuaEngine* pEngine = LuaEngine::getInstance();
		LuaStack* pStack = pEngine->getLuaStack();

		pStack->pushObject(pSender, "Ref");
		pStack->pushInt(uPageIdx);

		pStack->executeFunctionByHandler(m_nPageChangedScriptHandler, 2);
		pStack->clean();
	}
}

void CPageChangeableProtocol::setOnPageChangedScriptHandler(int nHandler)
{
	removeOnPageChangedScriptHandler();
	m_nPageChangedScriptHandler = nHandler;
}

void CPageChangeableProtocol::removeOnPageChangedScriptHandler()
{
	if( m_nPageChangedScriptHandler != 0 )
	{
		ScriptEngineManager::getInstance()->getScriptEngine()->removeScriptHandler(m_nPageChangedScriptHandler);
		m_nPageChangedScriptHandler = 0;
	}
}
#endif



CScrollableProtocol::CScrollableProtocol()
: m_pScrollingListener(NULL)
, m_pScrollingHandler(NULL)
#if USING_LUA
, m_nScrollingScriptHandler(0)
#endif
{
	
}

CScrollableProtocol::~CScrollableProtocol()
{
#if USING_LUA
	removeOnScrollingScriptHandler();
#endif
}

void CScrollableProtocol::setOnScrollingListener(Ref* pListener, SEL_ScrollingHandler pHandler)
{
	m_pScrollingListener = pListener;
	m_pScrollingHandler = pHandler;
}

void CScrollableProtocol::executeScrollingHandler(Ref* pSender)
{
	if( m_pScrollingListener && m_pScrollingHandler )
	{
		(m_pScrollingListener->*m_pScrollingHandler)(pSender);
	}
#if USING_LUA
	else if( m_nScrollingScriptHandler != 0 )
	{
		executeScrollingScriptHandler(pSender);
	}
#endif
}

#if USING_LUA
void CScrollableProtocol::executeScrollingScriptHandler(Ref* pSender)
{
	if( m_nScrollingScriptHandler != 0 )
	{
		LuaEngine* pEngine = LuaEngine::getInstance();
		LuaStack* pStack = pEngine->getLuaStack();

		pStack->pushObject(pSender, "Ref");

		pStack->executeFunctionByHandler(m_nScrollingScriptHandler, 1);
		pStack->clean();
	}
}

void CScrollableProtocol::setOnScrollingScriptHandler(int nHandler)
{
	removeOnScrollingScriptHandler();
	m_nScrollingScriptHandler = nHandler;
}

void CScrollableProtocol::removeOnScrollingScriptHandler()
{
	if( m_nScrollingScriptHandler != 0 )
	{
		ScriptEngineManager::getInstance()->getScriptEngine()->removeScriptHandler(m_nScrollingScriptHandler);
		m_nScrollingScriptHandler = 0;
	}
}
#endif

CMoveProtocol::CMoveProtocol()
: m_pMoveingHandler(NULL)
, m_pMoveingListener(NULL)
, m_pMoveEndHandler(nullptr)
, m_pMoveEndListener(nullptr)
#if USING_LUA
, m_nMoveEndScriptHandler(0)
, m_nMoveingScriptHandler(0)
#endif
{
    
}

CMoveProtocol::~CMoveProtocol()
{
#if USING_LUA
    removeOnMoveingScriptHandler();
    removeOnMoveEndScriptHandler();
#endif
}

void CMoveProtocol::setOnMoveingListener(Ref* pListener, SEL_MoveingHandler pHandler)
{
    m_pMoveingListener = pListener;
    m_pMoveingHandler = pHandler;
}

void CMoveProtocol::executeMoveingHandler(Ref* pSender)
{
    if( m_pMoveingListener && m_pMoveingHandler )
    {
        (m_pMoveingListener->*m_pMoveingHandler)(pSender);
    }
#if USING_LUA
    else if( m_nMoveingScriptHandler != 0 )
    {
        executeMoveingScriptHandler(pSender);
    }
#endif
}

void CMoveProtocol::executeMoveEndHandler(Ref* pSender)
{
    if( m_pMoveEndListener && m_pMoveEndHandler )
    {
        (m_pMoveEndListener->*m_pMoveEndHandler)(pSender);
    }
#if USING_LUA
    else if( m_nMoveEndScriptHandler != 0 )
    {
        executeMoveEndScriptHandler(pSender);
    }
#endif
}


#if USING_LUA
void CMoveProtocol::executeMoveingScriptHandler(Ref* pSender)
{
    if( m_nMoveingScriptHandler != 0 )
    {
        LuaEngine* pEngine = LuaEngine::getInstance();
        LuaStack* pStack = pEngine->getLuaStack();
        
        pStack->pushObject(pSender, "Ref");
        
        pStack->executeFunctionByHandler(m_nMoveingScriptHandler, 1);
        pStack->clean();
    }
}

void CMoveProtocol::executeMoveEndScriptHandler(Ref* pSender)
{
    if( m_nMoveEndScriptHandler != 0 )
    {
        LuaEngine* pEngine = LuaEngine::getInstance();
        LuaStack* pStack = pEngine->getLuaStack();
        
        pStack->pushObject(pSender, "Ref");
        
        pStack->executeFunctionByHandler(m_nMoveEndScriptHandler, 1);
        pStack->clean();
    }
}

void CMoveProtocol::setOnMoveIngScriptHandler(int nHandler)
{
    removeOnMoveingScriptHandler();
    m_nMoveingScriptHandler = nHandler;
}

void CMoveProtocol::setOnMoveEndScriptHandler(int nHandler)
{
    removeOnMoveEndScriptHandler();
    m_nMoveEndScriptHandler = nHandler;
}

void CMoveProtocol::removeOnMoveingScriptHandler()
{
    if( m_nMoveingScriptHandler != 0 )
    {
        ScriptEngineManager::getInstance()->getScriptEngine()->removeScriptHandler(m_nMoveingScriptHandler);
        m_nMoveingScriptHandler = 0;
    }
}

void CMoveProtocol::removeOnMoveEndScriptHandler()
{
    if( m_nMoveEndScriptHandler != 0 )
    {
        ScriptEngineManager::getInstance()->getScriptEngine()->removeScriptHandler(m_nMoveEndScriptHandler);
        m_nMoveEndScriptHandler = 0;
    }
}
#endif


CProgressEndedProtocol::CProgressEndedProtocol()
: m_pProgressEndedListener(NULL)
, m_pProgressEndedHandler(NULL)
#if USING_LUA
, m_nProgressEndedScriptHandler(0)
#endif
{
	
}

CProgressEndedProtocol::~CProgressEndedProtocol()
{
#if USING_LUA
	removeOnProgressEndedScriptHandler();
#endif
}

void CProgressEndedProtocol::setOnProgressEndedListener(Ref* pListener, SEL_ProgressEndedHandler pHandler)
{
	m_pProgressEndedListener = pListener;
	m_pProgressEndedHandler = pHandler;
}

void CProgressEndedProtocol::executeProgressEndedHandler(Ref* pSender)
{
	if( m_pProgressEndedListener && m_pProgressEndedHandler )
	{
		(m_pProgressEndedListener->*m_pProgressEndedHandler)(pSender);
	}
#if USING_LUA
	else if( m_nProgressEndedScriptHandler != 0 )
	{
		executeProgressEndedScriptHandler(pSender);
	}
#endif
}

#if USING_LUA
void CProgressEndedProtocol::executeProgressEndedScriptHandler(Ref* pSender)
{
	if( m_nProgressEndedScriptHandler != 0 )
	{
		LuaEngine* pEngine = LuaEngine::getInstance();
		LuaStack* pStack = pEngine->getLuaStack();

		pStack->pushObject(pSender, "Ref");

		pStack->executeFunctionByHandler(m_nProgressEndedScriptHandler, 1);
		pStack->clean();
	}
}

void CProgressEndedProtocol::setOnProgressEndedScriptHandler(int nHandler)
{
	removeOnProgressEndedScriptHandler();
	m_nProgressEndedScriptHandler = nHandler;
}

void CProgressEndedProtocol::removeOnProgressEndedScriptHandler()
{
	if( m_nProgressEndedScriptHandler != 0 )
	{
		ScriptEngineManager::getInstance()->getScriptEngine()->removeScriptHandler(m_nProgressEndedScriptHandler);
		m_nProgressEndedScriptHandler = 0;
	}
}
#endif




CValueChangeableProtocol::CValueChangeableProtocol()
: m_pValueChangedListener(NULL)
, m_pValueChangedHandler(NULL)
, m_nValue(0)
#if USING_LUA
, m_nValueChangedScriptHandler(0)
#endif
{
	
}

CValueChangeableProtocol::~CValueChangeableProtocol()
{
#if USING_LUA
	removeOnValueChangedScriptHandler();
#endif
}

void CValueChangeableProtocol::setOnValueChangedListener(Ref* pListener, SEL_ValueChangedHandler pHandler)
{
	m_pValueChangedListener = pListener;
	m_pValueChangedHandler = pHandler;
}

void CValueChangeableProtocol::executeValueChangedHandler(Ref* pSender, int nValue)
{
	if( m_pValueChangedListener && m_pValueChangedHandler )
	{
		(m_pValueChangedListener->*m_pValueChangedHandler)(pSender, nValue);
	}
#if USING_LUA
	else if( m_nValueChangedScriptHandler != 0 )
	{
		executeValueChangedScriptHandler(pSender, nValue);
	}
#endif
}

#if USING_LUA
void CValueChangeableProtocol::executeValueChangedScriptHandler(Ref* pSender, int nValue)
{
	if( m_nValueChangedScriptHandler != 0 )
	{
		LuaEngine* pEngine =LuaEngine::getInstance();
		LuaStack* pStack = pEngine->getLuaStack();

		pStack->pushObject(pSender, "Ref");
		pStack->pushInt(nValue);

		pStack->executeFunctionByHandler(m_nValueChangedScriptHandler, 2);
		pStack->clean();
	}
}

void CValueChangeableProtocol::setOnValueChangedScriptHandler(int nHandler)
{
	removeOnValueChangedScriptHandler();
	m_nValueChangedScriptHandler = nHandler;
}

void CValueChangeableProtocol::removeOnValueChangedScriptHandler()
{
	if( m_nValueChangedScriptHandler != 0 )
	{
		ScriptEngineManager::getInstance()->getScriptEngine()->removeScriptHandler(m_nValueChangedScriptHandler);
		m_nValueChangedScriptHandler = 0;
	}
}
#endif



CClickableProtocol::CClickableProtocol()
: m_pClickHandler(NULL)
, m_pClickListener(NULL)
#if USING_LUA
, m_nClickScriptHandler(0)
#endif
{
	
}

CClickableProtocol::~CClickableProtocol()
{
#if USING_LUA
	removeOnClickScriptHandler();
#endif
}

void CClickableProtocol::setOnClickListener(Ref* pListener, SEL_ClickHandler pHandler)
{
	m_pClickListener = pListener;
	m_pClickHandler = pHandler;
}

void CClickableProtocol::executeClickHandler(Ref* pSender)
{
	if( m_pClickListener && m_pClickHandler )
	{
		(m_pClickListener->*m_pClickHandler)(pSender);
	}
#if USING_LUA
	else if( m_nClickScriptHandler != 0 )
	{
		executeClickScriptHandler(pSender);
	}
#endif
}

#if USING_LUA
void CClickableProtocol::executeClickScriptHandler(Ref* pSender)
{
	if( m_nClickScriptHandler != 0 )
	{
		LuaEngine* pEngine = LuaEngine::getInstance();
		LuaStack* pStack = pEngine->getLuaStack();

		pStack->pushObject(pSender, "Ref");

		pStack->executeFunctionByHandler(m_nClickScriptHandler, 1);
		pStack->clean();
	}
}

void CClickableProtocol::setOnClickScriptHandler(int nHandler)
{
	removeOnClickScriptHandler();
	m_nClickScriptHandler = nHandler;
}

void CClickableProtocol::removeOnClickScriptHandler()
{
	if( m_nClickScriptHandler != 0 )
	{
		ScriptEngineManager::getInstance()->getScriptEngine()->removeScriptHandler(m_nClickScriptHandler);
		m_nClickScriptHandler = 0;
	}
}
#endif


CLongClickableProtocol::CLongClickableProtocol()
: m_pLongClickListener(NULL)
, m_pLongClickHandler(NULL)
, m_bLongClickedUpdate(false)
, m_fLongClickLastTouchDuration(0.0f)
, m_pLongClickLastTouch(NULL)
, m_bLongClickEnabled(false)
, m_fLongClickTimeCounter(0.0f)
#if USING_LUA
, m_nLongClickScriptHandler(0)
#endif
{

}

CLongClickableProtocol::~CLongClickableProtocol()
{
#if USING_LUA
	removeOnLongClickScriptHandler();
#endif
}

void CLongClickableProtocol::setOnLongClickListener(Ref* pListener, SEL_LongClickHandler pHandler)
{
	m_bLongClickEnabled  = pListener && pHandler;
	m_pLongClickListener = pListener;
	m_pLongClickHandler  = pHandler;
}

bool CLongClickableProtocol::executeLongClickHandler(Ref* pSender, Touch* pTouch)
{
	if( m_pLongClickListener && m_pLongClickHandler )
	{
		return (m_pLongClickListener->*m_pLongClickHandler)(pSender, pTouch);
	}
#if USING_LUA
	else if( m_nLongClickScriptHandler != 0 )
	{
		return executeLongClickScriptHandler(pSender, pTouch);
	}
#endif
	return false;
}

#if USING_LUA
bool CLongClickableProtocol::executeLongClickScriptHandler(Ref* pSender, Touch* pTouch)
{
	if( m_nLongClickScriptHandler != 0 )
	{
		LuaEngine* pEngine = LuaEngine::getInstance();
		LuaStack* pStack = pEngine->getLuaStack();

		pStack->pushObject(pSender, "Ref");
		pStack->pushObject(pTouch, "Touch");

		__Array pRetArray;
		pRetArray.initWithCapacity(1);

		int nRet = pStack->executeFunctionReturnArray(m_nLongClickScriptHandler, 2, 1, pRetArray);
		CCAssert(pRetArray.count() > 0, "return count = 0");

		__Bool* pBool = (__Bool*)pRetArray.getObjectAtIndex(0);
		bool bReturnBool = pBool->getValue();
		pStack->clean();
		return bReturnBool;
	}
	return false;
}

void CLongClickableProtocol::setOnLongClickScriptHandler(int nHandler)
{
	removeOnLongClickScriptHandler();
	m_nLongClickScriptHandler = nHandler;
	m_bLongClickEnabled = true;
}

void CLongClickableProtocol::removeOnLongClickScriptHandler()
{
	if( m_nLongClickScriptHandler != 0 )
	{
		ScriptEngineManager::getInstance()->getScriptEngine()->removeScriptHandler(m_nLongClickScriptHandler);
		m_nLongClickScriptHandler = 0;
		m_bLongClickEnabled = false;
	}
}
#endif




CCheckableProtocol::CCheckableProtocol()
: m_bChecked(false)
, m_pCheckListener(NULL)
, m_pCheckHandler(NULL)
, m_nExclusion(CC_WIDGET_NONE_EXCLUSION)
#if USING_LUA
, m_nCheckScriptHandler(0)
#endif
{

}

CCheckableProtocol::~CCheckableProtocol()
{
#if USING_LUA
	removeCheckScriptHandler();
#endif
}

bool CCheckableProtocol::isChecked() const
{
	return m_bChecked;
}

void CCheckableProtocol::setChecked(bool bChecked)
{
	m_bChecked = bChecked;
}

void CCheckableProtocol::setOnCheckListener(Ref* pListener, SEL_CheckHandler pHandler)
{
	m_pCheckListener = pListener;
	m_pCheckHandler = pHandler;
}

void CCheckableProtocol::setExclusion(int nExclusion)
{
	m_nExclusion = nExclusion;
}

int CCheckableProtocol::getExclusion() const
{
	return m_nExclusion;
}

void CCheckableProtocol::executeCheckHandler(Ref* pSender, bool bChecked)
{
	if( m_pCheckListener && m_pCheckHandler  )
	{
		(m_pCheckListener->*m_pCheckHandler)(pSender, bChecked);
	}
#if USING_LUA
	else if( m_nCheckScriptHandler != 0 )
	{
		executeCheckScriptHandler(pSender, bChecked);
	}
#endif
}

void CCheckableProtocol::setUnCheckedForOtherWidgetsByExclusion(Node* pParent)
{
	if( pParent && m_nExclusion != CC_WIDGET_NONE_EXCLUSION )
	{
		auto nCount = pParent->getChildren().size();
		for(int i=0;i<nCount;i++){
			Node *pChild = pParent->getChildren().at(i);
			CCheckableProtocol* pCheckableWidget = dynamic_cast<CCheckableProtocol*>(pChild);
			if( pCheckableWidget && pCheckableWidget != this )
			{
				if( pCheckableWidget->getExclusion() == m_nExclusion )
				{
					pCheckableWidget->setChecked(false);
				}
			}
		}
	}
}

#if USING_LUA
void CCheckableProtocol::executeCheckScriptHandler(Ref* pSender, bool bChecked)
{
	if( m_nCheckScriptHandler != 0 )
	{
		LuaEngine* pEngine = LuaEngine::getInstance();
		LuaStack* pStack = pEngine->getLuaStack();

		pStack->pushObject(pSender, "Ref");
		pStack->pushBoolean(bChecked);

		pStack->executeFunctionByHandler(m_nCheckScriptHandler, 2);
		pStack->clean();
	}
}

void CCheckableProtocol::setOnCheckScriptHandler(int nHandler)
{
	removeCheckScriptHandler();
	m_nCheckScriptHandler = nHandler;
}

void CCheckableProtocol::removeCheckScriptHandler()
{
	if( m_nCheckScriptHandler != 0 )
	{
		ScriptEngineManager::getInstance()->getScriptEngine()->removeScriptHandler(m_nCheckScriptHandler);
		m_nCheckScriptHandler = 0;
	}
}
#endif



CControlableProtocol::CControlableProtocol()
: m_pControlListener(NULL)
, m_pControlHandler(NULL)
#if USING_LUA
, m_nControlScriptHandler(0)
#endif
{
	
}

CControlableProtocol::~CControlableProtocol()
{
#if USING_LUA
	removeOnControlScriptHandler();
#endif
}

void CControlableProtocol::setOnControlListener(Ref* pListener, SEL_ControlHandler pHandler)
{
	m_pControlListener = pListener;
	m_pControlHandler = pHandler;
}

void CControlableProtocol::executeControlHandler(Ref* pSender, float cx, float cy)
{
	if( m_pControlListener && m_pControlHandler )
	{
		(m_pControlListener->*m_pControlHandler)(pSender, cx, cy);
	}
#if USING_LUA
	else if( m_nControlScriptHandler != 0 )
	{
		executeControlScriptHandler(pSender, cx, cy);
	}
#endif
}

#if USING_LUA
void CControlableProtocol::executeControlScriptHandler(Ref* pSender, float cx, float cy)
{
	if( m_nControlScriptHandler != 0 )
	{
		LuaEngine* pEngine = LuaEngine::getInstance();
		LuaStack* pStack = pEngine->getLuaStack();

		pStack->pushObject(pSender, "Ref");
		pStack->pushFloat(cx);
		pStack->pushFloat(cy);

		pStack->executeFunctionByHandler(m_nControlScriptHandler, 3);
		pStack->clean();
	}
}

void CControlableProtocol::setOnControlScriptHandler(int nHandler)
{
	removeOnControlScriptHandler();
	m_nControlScriptHandler = nHandler;
}

void CControlableProtocol::removeOnControlScriptHandler()
{
	if( m_nControlScriptHandler != 0 )
	{
		ScriptEngineManager::getInstance()->getScriptEngine()->removeScriptHandler(m_nControlScriptHandler);
		m_nControlScriptHandler = 0;
	}
}
#endif


NS_CC_WIDGET_END