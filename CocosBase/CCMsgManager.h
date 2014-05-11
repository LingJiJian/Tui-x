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
#ifndef __CCBASE_MSGMANAGER_H__
#define __CCBASE_MSGMANAGER_H__

#include "cocos2d.h"
#include "CCMsgDelegate.h"
#include "CCBaseMacros.h"

NS_CC_BEGIN

/**
 * struct : ccMESSAGE4
 * author : Jason lee
 * email  : jason.lee.c@foxmail.com
 * descpt : message data
 */
struct ccMESSAGE4
{
	Ref*    pMsgObj;
	void*        wParam;
	void*        lParam;
	unsigned int uMsg;
};

/**
 * struct : ccTARGETMESSAGE4
 * author : Jason lee
 * email  : jason.lee.c@foxmail.com
 * descpt : message data for target delegate
 */
struct ccTARGETMESSAGE4
{
	ccMESSAGE4 tMessage;
	CCMsgDelegate* pDelegate;
};

/**
 * class  : CCMsgManager
 * author : Jason lee
 * email  : jason.lee.c@foxmail.com
 * descpt : message manager
 */
class CCMsgManager : public Ref
{
public:
	virtual ~CCMsgManager();

	// the single instance func
	static CCMsgManager* getInstance();

	// post the message to all delegates of game on next frame
	void PostMessage(unsigned int uMsg, Ref* pMsgObj = NULL, void* wParam = NULL, void* lParam = NULL);

	// post the message to this delegate on next frame
	void PostMessage(CCMsgDelegate* pDelegate, unsigned int uMsg, Ref* pMsgObj = NULL, void* wParam = NULL, void* lParam = NULL);

	// register a new delegate for handle message
	void registerMsgDelegate(CCMsgDelegate* pDelegate);

	// unregister message
	void unregisterMsgDelegate(CCMsgDelegate* pDelegate);

public:
	// frame called
	void update();

private:
	CCMsgManager();

	bool m_bDispatchMsgLocked;
	std::vector<ccMESSAGE4> m_vMsgTemps;
	std::vector<ccMESSAGE4> m_vMsgQueue;
	std::vector<ccTARGETMESSAGE4> m_vTargetMsgTemps;
	std::vector<ccTARGETMESSAGE4> m_vTargetMsgQueue;
	std::vector<CCMsgDelegate*> m_vMsgDelegates;
	std::vector<CCMsgDelegate*> m_vMsgDelegatesRemoved;
	std::vector<CCMsgDelegate*> m_vMsgDelegatesAdded;
	
};

NS_CC_END

#endif //__CCBASE_MSGMANAGER_H__