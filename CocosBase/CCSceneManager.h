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
#ifndef __CCBASE_SCENEMANAGER_H__
#define __CCBASE_SCENEMANAGER_H__

#include "cocos2d.h"
#include "CCBaseMacros.h"
#include "CCMsgDelegate.h"
#include "CCSceneExtension.h"
#include "CCSceneExTransition.h"
#include "CCMsgManager.h"
#include <vector>
#include <list>
#include <map>

NS_CC_BEGIN

/**
 * enum   : SceneSwitchType
 * author : Jason lee
 * email  : jason.lee.c@foxmail.com
 * descpt : the scene switch type
 */
enum SceneSwitchType
{
	// push scene type
	eSceneSwitchPushScene,
	// replace running scene type
	eSceneSwitchReplaceScene,
	// close running scene type
	eSceneSwitchPopScene,
	// pop to stack level type
	eSceneSwitchPopToSceneStackLevel
};

/**
 * enum   : UISceneSwitchType
 * author : Jason lee
 * email  : jason.lee.c@foxmail.com
 * descpt : the ui scene switch type
 */
enum UISceneSwitchType
{
	// just run a new scene
	eUISceneSwitchRunScene,
	// close an exist scene
	eUISceneSwitchPopScene
};

/**
 * struct : ccSCENESWITCH
 * author : Jason lee
 * email  : jason.lee.c@foxmail.com
 * descpt : the scene switch data
 */
struct ccSCENESWITCH
{
	// the next show scene
	CSceneExtension* pNextScene;
	// extra for the next scene
	Ref* pExtra;
	// scene switch type
	SceneSwitchType eType;
	// pop level
	int nPopSceneStackLevel;
	// is locked this switch
	bool bLockedSwitch;
};

/**
 * struct : ccUISCENESWITCH
 * author : Jason lee
 * email  : jason.lee.c@foxmail.com
 * descpt : the ui scene switch data
 */
struct ccUISCENESWITCH
{
	// the switch scene, show or hide
	CSceneExtension* pScene;
	// the type
	UISceneSwitchType eType;
	// is locked this switch
	bool bLockedSwitch;
};

/**
 * class  : CCSceneManager
 * author : Jason lee
 * email  : jason.lee.c@foxmail.com
 * descpt : scene manager 
 */
class CSceneManager : public Scene
{
public:
	virtual ~CSceneManager();

	// the single instance func
	static CSceneManager* getInstance();

	// get the running scene, top of running scene stack
	CSceneExtension* getRunningScene() const;

	// is send clean up
	inline bool isSendCleanupToScene(){ return m_bSendCleanupToScene; }

	// run scene when the game is first enter, just call once
	void runWithScene(CSceneExtension* pScene, Ref* pExtra = NULL);

	// push the scene to top
	void pushScene(CSceneExtension* pScene, Ref* pExtra = NULL);

	// replace running scene, the param scene will be running
	void replaceScene(CSceneExtension* pScene, Ref* pExtra = NULL);

	// pop the top scene, if stack empty, it will end the game
	void popScene(Ref* pExtra = NULL);

	// pop to the stack level 1
	void popToRootScene(Ref* pExtra = NULL);

	// pop to the stack level, if the level < 1, will end the game
	void popToSceneStackLevel(int nLevel, Ref* pExtra = NULL);

	// opan a ui scene
	void runUIScene(CSceneExtension* pScene, Ref* pExtra = NULL,bool isPopup = true);

	// close a ui scene
	void popUIScene(CSceneExtension* pScene);

	// close all ui scene
	void popAllUIScene();

	// is ui scene are running
	bool isSceneRunning(const char* pSceneName);

	// end the game
	void end();
	
	// remove the cached scene from scene pool by scene name
	void removeCachedScene(const char* pSceneName);

	// remove all cached scene from scene pool
	void removeAllCachedScenes();

	// remove all unused ( single reference ) scene from scene pool
	void removeUnusedCachedScenes();

	// registe the scene class when the game is first enter
	void registerSceneClass(const char* pSceneName, Fn_CreateSceneExtension pFn);

	// load scene if it not in scene pool
	CSceneExtension* loadScene(const char* pSceneName);

	// seek the scene from running stack and scene pool
	CSceneExtension* seekScene(const char* pSceneName);

	// get the static touch priority, the touch priority will less 1 while every call
	int getTouchPriority();


public:
	// call main loop
	virtual void visit(Renderer* renderer, const Mat4 &parentTransform, uint32_t parentFlags);
	
protected:
	friend class CSceneExtension;
	
	// the main loop of scene manager, frame called
	void mainLoop(Renderer* renderer, const Mat4 &parentTransform, uint32_t parentFlags);

	// set next scene for running
	void setNextScene();

	// handle the switch event
	void handleSceneSwitch(ccSCENESWITCH& tSceneSwitch);

	// unlock the scene switch event by class name, it will find in switch queue
	void unlockSceneSwitch(const char* pClassName);

	// handle the switch event
	void handleUISceneSwitch(ccUISCENESWITCH& tSceneSwitch);

	// unlock the scene switch event by class name, it will find in switch queue
	void unlockUISceneSwitch(const char* pClassName);

	// visit all ui scene
	void visitUIScenes(Renderer* renderer, const Mat4 &parentTransform, uint32_t parentFlags);

	// let the scene load resources they needed
	bool loadSceneResources(CSceneExtension* pScene);

	// set extra data for this scene
	void setExtraToScene(CSceneExtension* pScene, Ref* pExtra);

	// add to the cachable scene pool if it is cachable
	void addCachableScene(CSceneExtension* pScene);

	// get scene class name, could be a CCSceneExTransition
	const char* getSceneClassName(CSceneExtension* pScene);

protected:
	//is popup state
	bool m_bPopup;

	// is send cleanup to next scene
	bool m_bSendCleanupToScene;

	// the message manager for game
	CCMsgManager* m_pMsgManager;

	// the running scene
	CSceneExtension* m_pRunningScene;

	// the next scene for running
	CSceneExtension* m_pNextScene;

	// running scene stack
	std::vector<CSceneExtension*> m_vRunningSceneStack;

	// scene switch event queue
	std::list<ccSCENESWITCH> m_lSceneSwitchQueue;

	// ui scene switch queue
	std::list<ccUISCENESWITCH> m_lUISceneSwitchQueue;

	// ui scene array
	std::vector<CSceneExtension*> m_vRunningUIScenes;

	// the static pointer of function, it helpful create a new scene
	std::map<std::string, Fn_CreateSceneExtension> m_mFnSceneCreatePointers;

	// scene pool, if it is cachable
	std::map<std::string, CSceneExtension*> m_mSceneCachePool;

#if(COCOS2D_DEBUG >= 1)
	void debugSceneSwitchInfo();
#endif

private:
	CSceneManager();

};

NS_CC_END

#endif //__CCBASE_SCENEMANAGER_H__