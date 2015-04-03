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
#ifndef __CCBASE_CCBASEMACROS_H__
#define __CCBASE_CCBASEMACROS_H__

#include "cocos2d.h"
// if using CocosWidget, go include cocos-widget.h here
 #include "../CocosWidget/cocos-widget.h"
// end

// using CocosWidget that change the USING_COCOSWIDGET to 1
#ifndef USING_COCOSWIDGET
#define USING_COCOSWIDGET 1
#endif 

NS_CC_BEGIN

class CSceneExtension;
class CSceneManager;

typedef CSceneExtension* (*Fn_CreateSceneExtension)();

NS_CC_END

#ifndef CREATE_SCENE_FUNC
#define CREATE_SCENE_FUNC(_CLASS_) \
static CSceneExtension* createThisScene() { return new _CLASS_; }
#endif

#ifndef REGISTER_SCENE_FUNC
#define REGISTER_SCENE_FUNC(_CLASS_) \
cocos2d::CSceneManager::getInstance()->registerSceneClass(#_CLASS_, &_CLASS_::createThisScene)
#endif

#ifndef LoadScene
#define LoadScene(_CLASS_) \
cocos2d::CSceneManager::getInstance()->loadScene(_CLASS_)
#endif

#ifndef SeekScene
#define SeekScene(_CLASS_) \
cocos2d::CSceneManager::getInstance()->seekScene(_CLASS_)
#endif

#define LUA_COCOS2DX_CCB_SCRIPT_REGISTER(__KEY__) \
protected:\
	int m_n##__KEY__##ScriptHandler; \
public:	\
	void remove##__KEY__##ScriptHandler()\
{\
if (m_n##__KEY__##ScriptHandler != 0)\
{\
	ScriptEngineManager::getInstance()->getScriptEngine()->removeScriptHandler(m_n##__KEY__##ScriptHandler); \
	m_n##__KEY__##ScriptHandler = 0; \
}\
}\
	void set##__KEY__##ScriptHandler(int nHandler)\
{\
	remove##__KEY__##ScriptHandler(); \
	m_n##__KEY__##ScriptHandler = nHandler; \
}\
	void execute##__KEY__##ScriptHandler() \
{\
if (m_n##__KEY__##ScriptHandler != 0)\
{\
	LuaEngine* pEngine = LuaEngine::getInstance(); \
	LuaStack* pStack = pEngine->getLuaStack(); \
	pStack->executeFunctionByHandler(m_n##__KEY__##ScriptHandler, 0); \
	pStack->clean(); \
}\
}

#endif //__CCBASE_CCBASEMACROS_H__