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
#include "CCSceneManager.h"
#if USING_LUA
#include "CCLuaEngine.h"
#endif
#include <algorithm>
using namespace std;

NS_CC_BEGIN

CSceneManager::CSceneManager()
: m_bSendCleanupToScene(false)
, m_pRunningScene(NULL)
, m_pNextScene(NULL)
{
	m_pMsgManager = CCMsgManager::getInstance();
}

CSceneManager::~CSceneManager()
{
	m_pMsgManager->release();

	if(!m_lSceneSwitchQueue.empty())
	{
		list<ccSCENESWITCH>::iterator itr = m_lSceneSwitchQueue.begin();
		list<ccSCENESWITCH>::iterator end = m_lSceneSwitchQueue.end();

		for(; itr != end; ++itr )
		{
			CC_SAFE_RELEASE(itr->pNextScene);
			CC_SAFE_RELEASE(itr->pExtra);
		}
	}
	m_lSceneSwitchQueue.clear();

	removeAllCachedScenes();

	if(!m_vRunningSceneStack.empty())
	{
		vector<CSceneExtension*>::iterator itr = m_vRunningSceneStack.begin();
		vector<CSceneExtension*>::iterator end = m_vRunningSceneStack.end();

		for(; itr != end; ++itr )
		{
			CC_SAFE_RELEASE(*itr);
		}
	}
	m_vRunningSceneStack.clear();

	if(!m_vRunningUIScenes.empty())
	{
		vector<CSceneExtension*>::iterator itr = m_vRunningUIScenes.begin();
		vector<CSceneExtension*>::iterator end = m_vRunningUIScenes.end();

		for(; itr != end; ++itr )
		{
			CC_SAFE_RELEASE(*itr);
		}
	}
	m_vRunningUIScenes.clear();
#if USING_LUA
	m_mFnSceneCreateScriptFunc.clear();
#else
	m_mFnSceneCreatePointers.clear();
#endif
	CC_SAFE_RELEASE(m_pRunningScene);
}

CSceneManager* CSceneManager::getInstance()
{
	static CSceneManager* pInstance = NULL;
	if( pInstance == NULL ) {
		pInstance = new CSceneManager();
		pInstance->init();
		Director::getInstance()->runWithScene(pInstance);
		pInstance->release();
	}
	return pInstance;
}

void CSceneManager::visit(Renderer* renderer, const Mat4 &parentTransform, uint32_t parentFlags)
{
	Node::visit(renderer, parentTransform, parentFlags);
	mainLoop(renderer, parentTransform, parentFlags);
}

void CSceneManager::mainLoop(Renderer* renderer, const Mat4 &parentTransform, uint32_t parentFlags)
{
// << message

	m_pMsgManager->update();

// << switch

	do {
		CC_BREAK_IF(m_lSceneSwitchQueue.empty());
		ccSCENESWITCH& tSceneSwitch = m_lSceneSwitchQueue.front();
		
		CC_BREAK_IF(tSceneSwitch.bLockedSwitch);
		handleSceneSwitch(tSceneSwitch);
		m_lSceneSwitchQueue.pop_front();
	}
	while(0);
	
	do {
		CC_BREAK_IF(m_lUISceneSwitchQueue.empty());
		ccUISCENESWITCH& tSceneSwitch = m_lUISceneSwitchQueue.front();
		
		CC_BREAK_IF(tSceneSwitch.bLockedSwitch);
		handleUISceneSwitch(tSceneSwitch);
		m_lUISceneSwitchQueue.pop_front();
	}
	while(1);

	do {
		CC_BREAK_IF(m_lSuspendSceneSwitchQueue.empty());
		ccUISCENESWITCH& tSceneSwitch = m_lSuspendSceneSwitchQueue.front();

		CC_BREAK_IF(tSceneSwitch.bLockedSwitch);
		handleSuspendSceneSwitch(tSceneSwitch);
		m_lSuspendSceneSwitchQueue.pop_front();
	} while (1);

// << draw scene

	if( m_pNextScene )
    {
        setNextScene();
    }

    if( m_pRunningScene )
    {
		m_pRunningScene->visit(renderer, parentTransform, parentFlags);
    }

// << draw ui scene

	visitUIScenes(renderer, parentTransform, parentFlags);

// << draw suspend scene

	visitSuspendScenes(renderer, parentTransform, parentFlags);
}

void CSceneManager::runWithScene(CSceneExtension* pScene, Ref* pExtra)
{
	CCAssert(pScene != NULL, "This command can only be used to start the CCDirector. There is already a scene present.");
    CCAssert(m_pRunningScene == NULL, "m_pRunningScene should be null");

    pushScene(pScene, pExtra);
}

void CSceneManager::pushScene(CSceneExtension* pScene, Ref* pExtra)
{
	CCAssert(pScene, "the scene should not null");

	if( isSceneRunning(getSceneClassName(pScene)) )
		return;

	ccSCENESWITCH tSceneSwitch;
	tSceneSwitch.pNextScene = pScene;
	tSceneSwitch.pExtra = pExtra;
	tSceneSwitch.eType = eSceneSwitchPushScene;
	tSceneSwitch.bLockedSwitch = true;

	setExtraToScene(pScene, tSceneSwitch.pExtra);
	m_lSceneSwitchQueue.push_back(tSceneSwitch);
	
	CC_SAFE_RETAIN(pScene);

	if( !loadSceneResources(pScene) )
	{
		m_lSceneSwitchQueue.back().bLockedSwitch = false;
	}
}

void CSceneManager::replaceScene(CSceneExtension* pScene, Ref* pExtra)
{
	CCAssert(m_pRunningScene, "Use runWithScene: instead to start the director");
	CCAssert(pScene != NULL, "the scene should not be null");

	if( isSceneRunning(getSceneClassName(pScene)) )
		return;

	ccSCENESWITCH tSceneSwitch;
	tSceneSwitch.pNextScene = pScene;
	tSceneSwitch.pExtra = pExtra;
	tSceneSwitch.eType = eSceneSwitchReplaceScene;
	tSceneSwitch.bLockedSwitch = true;

	setExtraToScene(pScene, tSceneSwitch.pExtra);
	m_lSceneSwitchQueue.push_back(tSceneSwitch);

	CC_SAFE_RETAIN(pScene);

	if( !loadSceneResources(pScene) )
	{
		m_lSceneSwitchQueue.back().bLockedSwitch = false;
	}
}

void CSceneManager::popScene(Ref* pExtra)
{
	CCAssert(m_pRunningScene != NULL, "running scene should not null");

	ccSCENESWITCH tSceneSwitch;
	tSceneSwitch.pNextScene = NULL;
	tSceneSwitch.pExtra = pExtra;
	tSceneSwitch.eType = eSceneSwitchPopScene;
	tSceneSwitch.bLockedSwitch = false;

	CC_SAFE_RETAIN(pExtra);

	m_lSceneSwitchQueue.push_back(tSceneSwitch);
}

void CSceneManager::popToRootScene(Ref* pExtra)
{
	popToSceneStackLevel(1, pExtra);
}

void CSceneManager::popToSceneStackLevel(int nLevel, Ref* pExtra)
{
    CCAssert(m_pRunningScene != NULL, "A running Scene is needed");

	ccSCENESWITCH tSceneSwitch;
	tSceneSwitch.pNextScene = NULL;
	tSceneSwitch.pExtra = pExtra;
	tSceneSwitch.eType = eSceneSwitchPopToSceneStackLevel;
	tSceneSwitch.nPopSceneStackLevel = nLevel;

	CC_SAFE_RETAIN(pExtra);

	m_lSceneSwitchQueue.push_back(tSceneSwitch);
}

void CSceneManager::end()
{
	autorelease();
	Director::getInstance()->end();
}

void CSceneManager::runUIScene(CSceneExtension* pScene, Ref* pExtra /* = NULL */)
{
	CCAssert(pScene != NULL && !dynamic_cast<CCSceneExTransition*>(pScene), "should not null and not transition");

	if( isSceneRunning(getSceneClassName(pScene)) )
		return;

	ccUISCENESWITCH tSceneSwitch;
	tSceneSwitch.pScene = pScene;
	tSceneSwitch.eType = eUISceneSwitchRunScene;
	tSceneSwitch.bLockedSwitch = true;
	m_lUISceneSwitchQueue.push_back(tSceneSwitch);

	CC_SAFE_RETAIN(pScene);
	setExtraToScene(pScene, pExtra);

	if( !loadSceneResources(pScene) )
	{
		m_lUISceneSwitchQueue.back().bLockedSwitch = false;
	}
}

void CSceneManager::popUIScene(CSceneExtension* pScene)
{
	CCAssert(pScene != NULL, "A running Scene is needed");

	if(!isSceneRunning(getSceneClassName(pScene)) )
		return;

	ccUISCENESWITCH tSceneSwitch;
	tSceneSwitch.pScene = pScene;
	tSceneSwitch.eType = eUISceneSwitchPopScene;
	tSceneSwitch.bLockedSwitch = false;
	m_lUISceneSwitchQueue.push_back(tSceneSwitch);
}

void CSceneManager::popAllUIScene()
{
	unsigned int i = 0;
	unsigned int c = m_vRunningUIScenes.size();

	for(; i < c; ++i )
	{
		ccUISCENESWITCH tSceneSwitch;
		tSceneSwitch.pScene = m_vRunningUIScenes[i];
		tSceneSwitch.eType = eUISceneSwitchPopScene;
		tSceneSwitch.bLockedSwitch = false;
		m_lUISceneSwitchQueue.push_back(tSceneSwitch);
	}
}

bool CSceneManager::isSceneRunning(const char* pSceneName)
{
	vector<CSceneExtension*>::iterator ritr = m_vRunningSceneStack.begin();
	vector<CSceneExtension*>::iterator rend = m_vRunningSceneStack.end();
	for(; ritr != rend; ++ritr )
	{
		if( strcmp((*ritr)->getClassName(), pSceneName) == 0 )
		{
			return true;
		}
	}

	vector<CSceneExtension*>::iterator uitr = m_vRunningUIScenes.begin();
	vector<CSceneExtension*>::iterator uend = m_vRunningUIScenes.end();
	for(; uitr != uend; ++uitr )
	{
		if( strcmp((*uitr)->getClassName(), pSceneName) == 0 )
		{
			return true;
		}
	}

	vector<CSceneExtension*>::iterator sitr = m_vRunningSuspendScenes.begin();
	vector<CSceneExtension*>::iterator send = m_vRunningSuspendScenes.end();
	for (; sitr != send; ++sitr)
	{
		if (strcmp((*sitr)->getClassName(), pSceneName) == 0)
		{
			return true;
		}
	}

	return false;
}

CSceneExtension* CSceneManager::getRunningScene() const
{
	return m_pRunningScene;
}

void CSceneManager::setNextScene()
{
	bool runningIsTransition = dynamic_cast<CCSceneExTransition*>(m_pRunningScene) != NULL;
	bool newIsTransition = dynamic_cast<CCSceneExTransition*>(m_pNextScene) != NULL;

	// If it is not a transition, call onExit/cleanup
	if (! newIsTransition)
	{
		if (m_pRunningScene)
		{
			m_pRunningScene->onExitTransitionDidStart();
			m_pRunningScene->onExit();
		}

		// issue #709. the root node (scene) should receive the cleanup message too
		// otherwise it might be leaked.
		if (m_bSendCleanupToScene && m_pRunningScene)
		{
			m_pRunningScene->cleanup();
		}
	}

	if (m_pRunningScene)
	{
		m_pRunningScene->release();
	}
	m_pRunningScene = m_pNextScene;
	m_pNextScene->retain();
	m_pNextScene = NULL;

	if ((! runningIsTransition) && m_pRunningScene)
	{
		m_pRunningScene->onEnter();
		m_pRunningScene->onEnterTransitionDidFinish();
	}
}

void CSceneManager::handleSceneSwitch(ccSCENESWITCH& tSceneSwitch)
{
	switch( tSceneSwitch.eType )
	{
	case eSceneSwitchPushScene:
		{
			CCAssert(tSceneSwitch.pNextScene, "the scene should not null");
			CSceneExtension* pScene = tSceneSwitch.pNextScene;
			pScene->autorelease();

			addCachableScene(pScene);

			m_bSendCleanupToScene = false;

			m_vRunningSceneStack.push_back(pScene);
			pScene->retain();
			m_pNextScene = pScene;

#if(COCOS2D_DEBUG >= 1)
			debugSceneSwitchInfo();
#endif
		}
		break;
	case eSceneSwitchReplaceScene:
		{
			CCAssert(m_pRunningScene, "Use runWithScene: instead to start the director");
			CCAssert(tSceneSwitch.pNextScene != NULL, "the scene should not be null");
			CSceneExtension* pScene = tSceneSwitch.pNextScene;
			pScene->autorelease();

			addCachableScene(pScene);

			m_bSendCleanupToScene = true;
			m_vRunningSceneStack.back()->release();
			m_vRunningSceneStack.pop_back();
			m_vRunningSceneStack.push_back(pScene);
			pScene->retain();

			m_pNextScene = pScene;

#if(COCOS2D_DEBUG >= 1)
			debugSceneSwitchInfo();
#endif
		}
		break;
	case eSceneSwitchPopScene:
		{
			CCAssert(m_pRunningScene != NULL, "running scene should not null");

			m_vRunningSceneStack.back()->release();
			m_vRunningSceneStack.pop_back();
			unsigned int c = m_vRunningSceneStack.size();

			if (c == 0)
			{
				CC_SAFE_RELEASE(tSceneSwitch.pExtra);
				end();
			}
			else
			{
				setExtraToScene(m_vRunningSceneStack.back(), tSceneSwitch.pExtra);
				CC_SAFE_RELEASE(tSceneSwitch.pExtra);

				m_bSendCleanupToScene = true;
				m_pNextScene = m_vRunningSceneStack[c - 1];
			}

#if(COCOS2D_DEBUG >= 1)
			debugSceneSwitchInfo();
#endif
		}
		break;
	case eSceneSwitchPopToSceneStackLevel:
		{
			 CCAssert(m_pRunningScene != NULL, "A running Scene is needed");
			 int c = (int) m_vRunningSceneStack.size();
			 int level = tSceneSwitch.nPopSceneStackLevel;

			 // level 0? -> end
			 if (level == 0)
			 {
				 CC_SAFE_RELEASE(tSceneSwitch.pExtra);
				 end();
				 return;
			 }

			 // current level or lower -> nothing
			 if (level >= c)
			 {
				 CC_SAFE_RELEASE(tSceneSwitch.pExtra);
				 return;
			 }

			 // pop stack until reaching desired level
			 while (c > level)
			 {
				 CSceneExtension* current = m_vRunningSceneStack.back();

				 if (current->isRunning())
				 {
					 current->onExitTransitionDidStart();
					 current->onExit();
				 }

				 current->cleanup();
				 m_vRunningSceneStack.back()->release();
				 m_vRunningSceneStack.pop_back();
				 c--;
			 }

			 setExtraToScene(m_vRunningSceneStack.back(), tSceneSwitch.pExtra);
			 CC_SAFE_RELEASE(tSceneSwitch.pExtra);

			 m_pNextScene = m_vRunningSceneStack.back();
			 m_bSendCleanupToScene = false;

#if(COCOS2D_DEBUG >= 1)
			debugSceneSwitchInfo();
#endif
		}
		break;
	}
}

void CSceneManager::unlockSceneSwitch(const char* pClassName)
{
	if( m_lSceneSwitchQueue.empty() )
		return;

	list<ccSCENESWITCH>::iterator itr = m_lSceneSwitchQueue.begin();
	list<ccSCENESWITCH>::iterator end = m_lSceneSwitchQueue.end();

	for(; itr != end; ++itr )
	{
		CCSceneExTransition* pTransitionScene = dynamic_cast<CCSceneExTransition*>(itr->pNextScene);
		CSceneExtension* pInScene = itr->pNextScene;

		if( pTransitionScene )
		{
			pInScene = pTransitionScene->getInScene();
		}

		if( strcmp(pInScene->getClassName(), pClassName) == 0 )
		{
			itr->bLockedSwitch = false;
			return;
		}
	}
}

void CSceneManager::handleUISceneSwitch(ccUISCENESWITCH& tSceneSwitch)
{
	switch( tSceneSwitch.eType )
	{
	case eUISceneSwitchRunScene:
		{
			tSceneSwitch.pScene->autorelease();
			addCachableScene(tSceneSwitch.pScene);

			tSceneSwitch.pScene->retain();
			tSceneSwitch.pScene->onEnter();
			tSceneSwitch.pScene->onEnterTransitionDidFinish();
			m_vRunningUIScenes.push_back(tSceneSwitch.pScene);

			for (auto uiScene : m_vRunningUIScenes)
				uiScene->setModalable( tSceneSwitch.pScene != uiScene );
			m_pRunningScene->setModalable(true);
		}
		break;
	case eUISceneSwitchPopScene:
		{
			vector<CSceneExtension*>::iterator itr = std::find(m_vRunningUIScenes.begin(), m_vRunningUIScenes.end(), tSceneSwitch.pScene);
			if( itr != m_vRunningUIScenes.end() )
			{
				(*itr)->setModalable(false); //reset modalable 

				tSceneSwitch.pScene->onExitTransitionDidStart();
				tSceneSwitch.pScene->onExit();
				tSceneSwitch.pScene->release();
				m_vRunningUIScenes.erase(itr);
			}
			if (m_vRunningUIScenes.size() == 0)
				m_pRunningScene->setModalable(false);
		}
		break;
	}
}

void CSceneManager::unlockUISceneSwitch(const char* pClassName)
{
	if( m_lUISceneSwitchQueue.empty() )
		return;

	list<ccUISCENESWITCH>::iterator itr = m_lUISceneSwitchQueue.begin();
	list<ccUISCENESWITCH>::iterator end = m_lUISceneSwitchQueue.end();

	for(; itr != end; ++itr )
	{
		if( strcmp(itr->pScene->getClassName(), pClassName) == 0 )
		{
			itr->bLockedSwitch = false;
			return;
		}
	}
}

void CSceneManager::visitUIScenes(Renderer* renderer, const Mat4 &parentTransform, uint32_t parentFlags)
{
	unsigned int i = 0;
	unsigned int c = m_vRunningUIScenes.size();

	for(; i < c; ++i )
	{
		m_vRunningUIScenes[i]->visit(renderer, parentTransform, parentFlags);
	}
}

void CSceneManager::removeCachedScene(const char* pSceneName)
{
	map<string, CSceneExtension*>::iterator itr = m_mSceneCachePool.find(pSceneName);
	if( itr != m_mSceneCachePool.end() )
	{
		itr->second->release();
		m_mSceneCachePool.erase(itr);
	}
}

void CSceneManager::removeAllCachedScenes()
{
	if( m_mSceneCachePool.empty() )
		return;

	map<string, CSceneExtension*>::iterator itr = m_mSceneCachePool.begin();
	for(; itr != m_mSceneCachePool.end(); ++itr)
	{
		itr->second->release();
	}
	m_mSceneCachePool.clear();
}

void CSceneManager::removeUnusedCachedScenes()
{
	if( m_mSceneCachePool.empty() )
		return;

	vector<map<string, CSceneExtension*>::iterator> removeStack;
	map<string, CSceneExtension*>::iterator itr = m_mSceneCachePool.begin();
	map<string, CSceneExtension*>::iterator end = m_mSceneCachePool.end();

	for(; itr != end; ++itr )
	{
		if( itr->second->getReferenceCount() == 1 )
		{
			itr->second->release();
			removeStack.push_back(itr);
		}
	}

	unsigned int i = 0;
	unsigned int c = m_mSceneCachePool.size();

	for(; i < c; ++i )
	{
		m_mSceneCachePool.erase(removeStack[i]);
	}
}

void CSceneManager::registerSceneClass(const char* pSceneName, Fn_CreateSceneExtension pFn)
{
	if( pFn && pSceneName && strlen(pSceneName) )
	{
		m_mFnSceneCreatePointers[pSceneName] = pFn;
	}
}

#if USING_LUA
void CSceneManager::registerSceneClassScriptFunc(const char* pSceneName, int nCreateFunc)
{
	if (nCreateFunc && pSceneName && strlen(pSceneName))
	{
		m_mFnSceneCreateScriptFunc[pSceneName] = nCreateFunc;
	}
}
#endif

CSceneExtension* CSceneManager::loadScene(const char* pSceneName)
{
	CCAssert(pSceneName && strlen(pSceneName), "should not null");

	map<string, CSceneExtension*>::iterator mitr = m_mSceneCachePool.find(pSceneName);
	if( mitr != m_mSceneCachePool.end() )
	{
		return mitr->second;
	}
#if USING_LUA
	map<string,int>::iterator itr = m_mFnSceneCreateScriptFunc.find(pSceneName);
	if(itr!=m_mFnSceneCreateScriptFunc.end())
	{
		LuaEngine* pEngine = LuaEngine::getInstance();
		LuaStack* pStack = pEngine->getLuaStack();

		__Array pRetArray;
		pRetArray.initWithCapacity(1);

		int nRet = pStack->executeFunctionReturnArray(itr->second, 0, 1, pRetArray);
		CCAssert(pRetArray.count() > 0, "return num = 0");

		Ref* pReturnObject = pRetArray.getObjectAtIndex(0);
		pStack->clean();

		CSceneExtension* pSceneExt = dynamic_cast<CSceneExtension*>(pReturnObject);
		pSceneExt->setClassName(pSceneName);
		return pSceneExt;
	}
#else
	map<string, Fn_CreateSceneExtension>::iterator itr = m_mFnSceneCreatePointers.find(pSceneName);
	if( itr != m_mFnSceneCreatePointers.end() )
	{
		CSceneExtension* pScene = (*itr->second)();
		pScene->setClassName(pSceneName);
		pScene->init();
		pScene->autorelease();
		return pScene;
	}
#endif
	return NULL;
}

CSceneExtension* CSceneManager::seekScene(const char* pSceneName)
{
	CCAssert(pSceneName && strlen(pSceneName), "should not null");

	vector<CSceneExtension*>::iterator ritr = m_vRunningSceneStack.begin();
	vector<CSceneExtension*>::iterator rend = m_vRunningSceneStack.end();
	for(; ritr != rend; ++ritr )
	{
		if( strcmp((*ritr)->getClassName(), pSceneName) == 0 )
		{
			return (*ritr);
		}
	}

	vector<CSceneExtension*>::iterator uitr = m_vRunningUIScenes.begin();
	vector<CSceneExtension*>::iterator uend = m_vRunningUIScenes.end();
	for(; uitr != uend; ++uitr )
	{
		if( strcmp((*uitr)->getClassName(), pSceneName) == 0 )
		{
			return (*uitr);
		}
	}

	vector<CSceneExtension*>::iterator sitr = m_vRunningSuspendScenes.begin();
	vector<CSceneExtension*>::iterator send = m_vRunningSuspendScenes.end();
	for (; sitr != send; ++sitr)
	{
		if (strcmp((*sitr)->getClassName(), pSceneName) == 0)
		{
			return (*sitr);
		}
	}

	map<string, CSceneExtension*>::iterator mitr = m_mSceneCachePool.find(pSceneName);
	if( mitr != m_mSceneCachePool.end() )
	{
		return mitr->second;
	}

	return NULL;
}

bool CSceneManager::loadSceneResources(CSceneExtension* pScene)
{
	CCSceneExTransition* pTransitionScene = dynamic_cast<CCSceneExTransition*>(pScene);
	CSceneExtension* pInScene = pScene;

	if( pTransitionScene )
	{
		pInScene = pTransitionScene->getInScene();
	}

	if( !pInScene->isLoaded() )
	{
		pInScene->onLoadResources();
		pInScene->loadResourcesSync();

		if( pInScene->isLoadingResourcesAsync() )
		{
			pInScene->loadResourcesAsync();
			pInScene->setLoaded(true);
			return true;
		}
		else
		{
			pInScene->onLoadResourcesCompleted();
			pInScene->onLoadScene();
		}

		pInScene->setLoaded(true);
	}

	return false;
}

void CSceneManager::setExtraToScene(CSceneExtension* pScene, Ref* pExtra)
{
	CCSceneExTransition* pTransitionScene = dynamic_cast<CCSceneExTransition*>(pScene);
	CSceneExtension* pInScene = pScene;

	if( pTransitionScene )
	{
		pInScene = pTransitionScene->getInScene();
	}

	if( pExtra )
	{
		pInScene->setExtraObject(pExtra);
	}
}

void CSceneManager::addCachableScene(CSceneExtension* pScene)
{
	CCSceneExTransition* pTransitionScene = dynamic_cast<CCSceneExTransition*>(pScene);
	CSceneExtension* pInScene = pScene;

	if( pTransitionScene )
	{
		pInScene = pTransitionScene->getInScene();
	}

	map<string, CSceneExtension*>::iterator mitr = m_mSceneCachePool.find(pInScene->getClassName());
	if( mitr == m_mSceneCachePool.end() && pInScene->isCachable() )
	{
		m_mSceneCachePool.insert(make_pair(pInScene->getClassName(), pInScene));
		pInScene->retain();
	}
}

const char* CSceneManager::getSceneClassName(CSceneExtension* pScene)
{
	CCSceneExTransition* pTransitionScene = dynamic_cast<CCSceneExTransition*>(pScene);
	CSceneExtension* pInScene = pScene;

	if( pTransitionScene )
	{
		pInScene = pTransitionScene->getInScene();
	}

	return pInScene->getClassName();
}

int CSceneManager::getTouchPriority()
{
	static int nTouchPriority = 0;
	return nTouchPriority--;
}

#if(COCOS2D_DEBUG >= 1)
void CSceneManager::debugSceneSwitchInfo()
{
	string strStackText = "Running Scene : ";
	vector<CSceneExtension*>::iterator itr = m_vRunningSceneStack.begin();
	vector<CSceneExtension*>::iterator end = m_vRunningSceneStack.end();

	for(; itr != end; ++itr )
	{
		if( dynamic_cast<CCSceneExTransition*>(*itr) )
		{
			strStackText.append("Transition -> ");
		}
		else
		{
			const char* pClassName = (*itr)->getClassName();
			strStackText.append(pClassName).append(" -> ");
		}
	}
	strStackText.erase(strStackText.size() - 4);

#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	CCLOG("%s",strStackText.c_str());
#else
	CCLOG("%s",strStackText.c_str());
#endif
}

void CSceneManager::handleSuspendSceneSwitch(ccUISCENESWITCH& tSceneSwitch)
{
	switch( tSceneSwitch.eType )
	{
	case eUISceneSwitchRunScene:
		{
			tSceneSwitch.pScene->autorelease();
			addCachableScene(tSceneSwitch.pScene);

			tSceneSwitch.pScene->retain();
			tSceneSwitch.pScene->onEnter();
			tSceneSwitch.pScene->onEnterTransitionDidFinish();
			m_vRunningSuspendScenes.push_back(tSceneSwitch.pScene);
		}
		break;
	case eUISceneSwitchPopScene:
		{
			vector<CSceneExtension*>::iterator itr = std::find(m_vRunningSuspendScenes.begin(), m_vRunningSuspendScenes.end(), tSceneSwitch.pScene);
			if (itr != m_vRunningSuspendScenes.end())
			{
				tSceneSwitch.pScene->onExitTransitionDidStart();
				tSceneSwitch.pScene->onExit();
				tSceneSwitch.pScene->release();
				m_vRunningSuspendScenes.erase(itr);
			}
		}
		break;
	}
}

void CSceneManager::unlockSuspendSceneSwitch(const char* pClassName)
{
	if (m_lSuspendSceneSwitchQueue.empty())
		return;

	list<ccUISCENESWITCH>::iterator itr = m_lSuspendSceneSwitchQueue.begin();
	list<ccUISCENESWITCH>::iterator end = m_lSuspendSceneSwitchQueue.end();

	for (; itr != end; ++itr)
	{
		if (strcmp(itr->pScene->getClassName(), pClassName) == 0)
		{
			itr->bLockedSwitch = false;
			return;
		}
	}
}

void CSceneManager::visitSuspendScenes(Renderer* renderer, const Mat4 &parentTransform, uint32_t parentFlags)
{
	unsigned int i = 0;
	unsigned int c = m_vRunningSuspendScenes.size();

	for (; i < c; ++i)
	{
		m_vRunningSuspendScenes[i]->visit(renderer, parentTransform, parentFlags);
	}
}

void CSceneManager::runSuspendScene(CSceneExtension* pScene, Ref* pExtra /*= NULL*/)
{
	CCAssert(pScene != NULL && !dynamic_cast<CCSceneExTransition*>(pScene), "should not null and not transition");

	if (isSceneRunning(getSceneClassName(pScene)))
		return;

	ccUISCENESWITCH tSceneSwitch;
	tSceneSwitch.pScene = pScene;
	tSceneSwitch.eType = eUISceneSwitchRunScene;
	tSceneSwitch.bLockedSwitch = true;
	m_lSuspendSceneSwitchQueue.push_back(tSceneSwitch);

	CC_SAFE_RETAIN(pScene);
	setExtraToScene(pScene, pExtra);

	if (!loadSceneResources(pScene))
	{
		m_lSuspendSceneSwitchQueue.back().bLockedSwitch = false;
	}
}

void CSceneManager::popSuspendScene(CSceneExtension* pScene)
{
	CCAssert(pScene != NULL, "A running Scene is needed");

	if (!isSceneRunning(getSceneClassName(pScene)))
		return;

	ccUISCENESWITCH tSceneSwitch;
	tSceneSwitch.pScene = pScene;
	tSceneSwitch.eType = eUISceneSwitchPopScene;
	tSceneSwitch.bLockedSwitch = false;
	m_lSuspendSceneSwitchQueue.push_back(tSceneSwitch);
}

void CSceneManager::popAllSuspendScene()
{
	unsigned int i = 0;
	unsigned int c = m_vRunningSuspendScenes.size();

	for (; i < c; ++i)
	{
		ccUISCENESWITCH tSceneSwitch;
		tSceneSwitch.pScene = m_vRunningSuspendScenes[i];
		tSceneSwitch.eType = eUISceneSwitchPopScene;
		tSceneSwitch.bLockedSwitch = false;
		m_lSuspendSceneSwitchQueue.push_back(tSceneSwitch);
	}
}

#endif

NS_CC_END