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
#include "CCSceneExtension.h"
#include "CCSceneManager.h"
using namespace std;
#if USING_COCOSWIDGET
using namespace cocos2d::cocoswidget;
#endif


NS_CC_BEGIN

CSceneExtension::CSceneExtension()
: m_bCachable(false)
, m_pExtraObject(NULL)
, m_strClassName("")
, m_bLoaded(false)
, m_nLoadResourcesAsyncCount(0)
, m_nLoadResourcesAsyncIdx(0)
, m_bAutoRemoveUnusedTexture(false)
#if USING_LUA
, m_nOnLoadResourcesScriptHandler(0)
, m_nOnLoadResourcesCompletedScriptHandler(0)
, m_nOnLoadResourcesProgressScriptHandler(0)
, m_nOnLoadSceneScriptHandler(0)
, m_nOnEnterSceneScriptHandler(0)
, m_nOnExitSceneScriptHandler(0)
#endif
#if! USING_COCOSWIDGET
, m_nTouchPriority(0)
#endif
{
	setAnchorPoint(Vec2::ZERO);
	setContentSize(Director::getInstance()->getWinSize());
}

bool CSceneExtension::init(){
	if(!Node::init()) return false;

	return true;
}

CSceneExtension::~CSceneExtension()
{
	Node::onExit();
	CC_SAFE_RELEASE(m_pExtraObject);
#if COCOS2D_DEBUG >= 1
	if( !m_strClassName.empty() )
	{
		CCLOG("CocosBase [DEBUG] : destroy Scene %s", m_strClassName.c_str());
	}
#endif
	if( m_bAutoRemoveUnusedTexture )
	{
		removeAllChildrenWithCleanup(true);
		Director::getInstance()->getTextureCache()->removeUnusedTextures();
	}
}

void CSceneExtension::onEnter()
{
#if USING_COCOSWIDGET
	setTouchPriority(CSceneManager::getInstance()->getTouchPriority());
	
	CCMsgManager::getInstance()->registerMsgDelegate(this);
	onEnterScene();
	CWidgetWindow::onEnter();
#else
	m_nTouchPriority = CSceneManager::getInstance()->getTouchPriority();

	CCMsgManager::getInstance()->registerMsgDelegate(this);
	onEnterScene();
	Node::onEnter();
#endif
}

void CSceneExtension::onExit()
{
	CCMsgManager::getInstance()->unregisterMsgDelegate(this);
#if USING_COCOSWIDGET
	onExitScene();
	CWidgetWindow::onExit();
#else
	onExitScene();
	Node::onExit();
#endif
}

bool CSceneExtension::isAutoRemoveUnusedTexture() const
{
	return m_bAutoRemoveUnusedTexture;
}

void CSceneExtension::setAutoRemoveUnusedTexture(bool bAuto)
{
	m_bAutoRemoveUnusedTexture = bAuto;
}

bool CSceneExtension::isCachable() const
{
	return m_bCachable;
}

void CSceneExtension::setCachable(bool bCachable)
{
	m_bCachable = bCachable;
}

Ref* CSceneExtension::getExtraObject() const
{
	return m_pExtraObject;
}

void CSceneExtension::setExtraObject(Ref* pExtraObject)
{
	CC_SAFE_RETAIN(pExtraObject);
	CC_SAFE_RELEASE(m_pExtraObject);
	m_pExtraObject = pExtraObject;
}

void CSceneExtension::setClassName(const char* pClassName)
{
	m_strClassName = pClassName;
}

const char* CSceneExtension::getClassName()
{
	return m_strClassName.c_str();
}

bool CSceneExtension::isLoaded() const
{
	return m_bLoaded;
}

#if! USING_COCOSWIDGET
int CSceneExtension::getTouchPriority() const
{
	return m_nTouchPriority;
}
#endif

void CSceneExtension::setLoaded(bool bLoaded)
{
	m_bLoaded = bLoaded;
}

void CSceneExtension::addImage(const char* pFile)
{
	CCAssert(pFile && strlen(pFile), "file path invalidate");
	m_vLoadImageFilesSync.push_back(pFile);
}

void CSceneExtension::addImageAsync(const char* pFile)
{
	CCAssert(pFile && strlen(pFile), "file path invalidate");
	m_vLoadImageFilesAsync.push_back(pFile);
}

bool CSceneExtension::isLoadingResourcesAsync()
{
	return !m_vLoadImageFilesAsync.empty();
}

void CSceneExtension::loadResourcesSync()
{
	if( m_vLoadImageFilesSync.empty() )
		return;

	vector<string>::iterator itr = m_vLoadImageFilesSync.begin();
	vector<string>::iterator end = m_vLoadImageFilesSync.end();

	for(; itr != end; ++itr)
	{
		Texture2D* pTexture = Director::getInstance()->getTextureCache()->addImage(itr->c_str());
		CCAssert(pTexture, "load image failed");
#if COCOS2D_DEBUG >= 1
		CCLOG("CocosBase [DEBUG] : Scene [%s] load image sync %s", m_strClassName.c_str(), itr->c_str());
#endif
	}

	m_vLoadImageFilesSync.clear();
}

void CSceneExtension::loadResourcesAsync()
{
	CCAssert(!m_vLoadImageFilesAsync.empty(), "empty");

	_eventDispatcher->setEnabled(false);

	m_nLoadResourcesAsyncCount = m_vLoadImageFilesAsync.size();
	m_nLoadResourcesAsyncIdx = 0;

	vector<string>::iterator itr = m_vLoadImageFilesAsync.begin();
	vector<string>::iterator end = m_vLoadImageFilesAsync.end();

	for(; itr != end; ++itr)
	{
		Director::getInstance()->getTextureCache()->addImageAsync(
			itr->c_str(), 
			CC_CALLBACK_1(CSceneExtension::loadingResourcesCallBack,this));
#if COCOS2D_DEBUG >= 1
		CCLOG("CocosBase [DEBUG] : Scene [%s] load image async %s", m_strClassName.c_str(), itr->c_str());
#endif
	}

	m_vLoadImageFilesAsync.clear();
}

void CSceneExtension::loadingResourcesCallBack(Ref* pTextureObj)
{
	CCAssert(pTextureObj, "load resources async failed");

	m_nLoadResourcesAsyncIdx ++;
    onLoadRescourcesProgress(m_nLoadResourcesAsyncIdx,m_nLoadResourcesAsyncCount);
#if USING_LUA
    executeOnLoadResourcesProgressScriptHandler(m_nLoadResourcesAsyncIdx,m_nLoadResourcesAsyncCount);
#endif
    
	if( m_nLoadResourcesAsyncIdx == m_nLoadResourcesAsyncCount )
	{
		_eventDispatcher->setEnabled(true);

		m_nLoadResourcesAsyncCount = 0;
		m_nLoadResourcesAsyncIdx = 0;
		onLoadResourcesCompleted();
		onLoadScene();

		// there is execute just one
		CSceneManager::getInstance()->unlockSceneSwitch(m_strClassName.c_str());
		CSceneManager::getInstance()->unlockUISceneSwitch(m_strClassName.c_str());
	}
}

#if USING_LUA
void CSceneExtension::executeOnLoadResourcesProgressScriptHandler(int idx,int total)
{
    if( m_nOnLoadResourcesProgressScriptHandler != 0 )
	{
		LuaEngine* pEngine = LuaEngine::getInstance();
		LuaStack* pStack = pEngine->getLuaStack();
        
        pStack->pushInt(idx);
        pStack->pushInt(total);
        
		pStack->executeFunctionByHandler(m_nOnLoadResourcesProgressScriptHandler, 2);
		pStack->clean();
	}
}
#endif

NS_CC_END