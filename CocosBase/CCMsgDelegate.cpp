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
#include "CCMsgDelegate.h"
#if USING_LUA
#include "CCLuaEngine.h"
#endif

NS_CC_BEGIN

CCMsgDelegate::CCMsgDelegate()
#if USING_LUA
:m_nMessageScriptHandler(0)
#endif
{
}

#if USING_LUA

void CCMsgDelegate::executeOnMessageScriptHandler(unsigned int uMsg, Ref* pMsgObj)
{
	if (m_nMessageScriptHandler != 0)
	{
		LuaEngine* pEngine = LuaEngine::getInstance();
		LuaStack* pStack = pEngine->getLuaStack();

		pStack->pushInt(uMsg);
		pStack->pushObject(pMsgObj, "Ref");

		pStack->executeFunctionByHandler(m_nMessageScriptHandler, 2);
		pStack->clean();
	}
}

#endif

NS_CC_END