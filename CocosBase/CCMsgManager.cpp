/****************************************************************************
Copyright (c) 2014 Lijunlin - Jason lee

Created by Lijunlin - Jason lee on 2014

jason.lee.c@foxmail.com

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
#include "CCMsgManager.h"
#include <algorithm>
using namespace std;

NS_CC_BEGIN

CCMsgManager::CCMsgManager()
: m_bDispatchMsgLocked(false)
{

}

CCMsgManager::~CCMsgManager()
{
	if(!m_vMsgQueue.empty())
	{
		vector<ccMESSAGE4>::iterator citr = m_vMsgQueue.begin();
		vector<ccMESSAGE4>::iterator cend = m_vMsgQueue.end();
		for(; citr != cend; ++citr )
		{
			ccMESSAGE4& tagMsg = *citr;
			CC_SAFE_RELEASE(tagMsg.pMsgObj);
		}
	}
	m_vMsgQueue.clear();

	if(!m_vTargetMsgQueue.empty())
	{
		vector<ccTARGETMESSAGE4>::iterator citr = m_vTargetMsgQueue.begin();
		vector<ccTARGETMESSAGE4>::iterator cend = m_vTargetMsgQueue.end();
		for(; citr != cend; ++citr )
		{
			ccTARGETMESSAGE4& tagTarget = *citr;
			ccMESSAGE4& tagMsg = tagTarget.tMessage;
			Ref* pObj = dynamic_cast<Ref*>(tagTarget.pDelegate);
			CC_SAFE_RELEASE(pObj);
			CC_SAFE_RELEASE(tagMsg.pMsgObj);
		}
	}
	m_vTargetMsgQueue.clear();

	if(!m_vMsgDelegates.empty())
	{
		vector<CCMsgDelegate*>::iterator itr = m_vMsgDelegates.begin();
		vector<CCMsgDelegate*>::iterator end = m_vMsgDelegates.end();
		for(; itr != end; ++itr )
		{
			Ref* pObj = dynamic_cast<Ref*>(*itr);
			CC_SAFE_RELEASE(pObj);
		}
	}
	m_vMsgDelegates.clear();

	if(!m_vMsgDelegatesAdded.empty())
	{
		vector<CCMsgDelegate*>::iterator itr = m_vMsgDelegatesAdded.begin();
		vector<CCMsgDelegate*>::iterator end = m_vMsgDelegatesAdded.end();
		for(; itr != end; ++itr )
		{
			Ref* pObj = dynamic_cast<Ref*>(*itr);
			CC_SAFE_RELEASE(pObj);
		}
	}
	m_vMsgDelegatesAdded.clear();
	m_vMsgDelegatesRemoved.clear();
}

CCMsgManager* CCMsgManager::getInstance()
{
	static CCMsgManager* pInstance = NULL;
	if( pInstance == NULL ) {
		pInstance = new CCMsgManager();
	}
	return pInstance;
}

void CCMsgManager::update()
{
// >> locked
	m_bDispatchMsgLocked = true;

	if(!m_vMsgQueue.empty())
	{
		vector<ccMESSAGE4>::iterator citr = m_vMsgQueue.begin();
		vector<ccMESSAGE4>::iterator cend = m_vMsgQueue.end();
		for(; citr != cend; ++citr )
		{
			ccMESSAGE4& tagMsg = *citr;
			vector<CCMsgDelegate*>::iterator hitr = m_vMsgDelegates.begin();
			vector<CCMsgDelegate*>::iterator hend = m_vMsgDelegates.end();
			for(; hitr != hend; ++hitr )
			{
				(*hitr)->onMessage(tagMsg.uMsg, tagMsg.pMsgObj, tagMsg.wParam, tagMsg.lParam);
			}
			CC_SAFE_RELEASE(tagMsg.pMsgObj);
		}
		m_vMsgQueue.clear();
	}

	if(!m_vTargetMsgQueue.empty())
	{
		vector<ccTARGETMESSAGE4>::iterator citr = m_vTargetMsgQueue.begin();
		vector<ccTARGETMESSAGE4>::iterator cend = m_vTargetMsgQueue.end();
		for(; citr != cend; ++citr )
		{
			ccTARGETMESSAGE4& tagTarget = *citr;
			ccMESSAGE4& tagMsg = tagTarget.tMessage;
			tagTarget.pDelegate->onMessage(tagMsg.uMsg, tagMsg.pMsgObj, tagMsg.wParam, tagMsg.lParam);

			Ref* pObj = dynamic_cast<Ref*>(tagTarget.pDelegate);
			CC_SAFE_RELEASE(pObj);
			CC_SAFE_RELEASE(tagMsg.pMsgObj);
		}
		m_vTargetMsgQueue.clear();
	}

	m_bDispatchMsgLocked = false;
// << unlocked

	while(!m_vMsgDelegatesAdded.empty())
	{
		CCMsgDelegate* pDelegate = m_vMsgDelegatesAdded.front();
		m_vMsgDelegates.insert(m_vMsgDelegates.begin(), pDelegate);
		m_vMsgDelegatesAdded.erase(m_vMsgDelegatesAdded.begin());
	}

	while(!m_vMsgDelegatesRemoved.empty())
	{
		CCMsgDelegate* pDelegate = m_vMsgDelegatesRemoved.front();
		
		vector<CCMsgDelegate*>::iterator itr = std::find(m_vMsgDelegates.begin(),m_vMsgDelegates.end(),pDelegate);
		if( itr != m_vMsgDelegates.end() )
		{
			m_vMsgDelegates.erase(itr);
		}

		Ref* pObject = dynamic_cast<Ref*>(pDelegate);
		pObject->release();
		m_vMsgDelegatesRemoved.erase(m_vMsgDelegatesRemoved.begin());
	}

	if(!m_vMsgTemps.empty())
	{
		m_vMsgQueue.insert(m_vMsgQueue.end(), m_vMsgTemps.begin(), m_vMsgTemps.end());
		m_vMsgTemps.clear();
	}

	if(!m_vTargetMsgTemps.empty())
	{
		m_vTargetMsgQueue.insert(m_vTargetMsgQueue.end(), m_vTargetMsgTemps.begin(), m_vTargetMsgTemps.end());
		m_vTargetMsgTemps.clear();
	}
}

void CCMsgManager::PostMessage(unsigned int uMsg, Ref* pMsgObj, void* wParam, void* lParam)
{
	ccMESSAGE4     tagMsg;
	tagMsg.uMsg    = uMsg;
	tagMsg.pMsgObj = pMsgObj;
	tagMsg.wParam  = wParam;
	tagMsg.lParam  = lParam;

	CC_SAFE_RETAIN(pMsgObj);

	if( m_bDispatchMsgLocked )
	{
		m_vMsgTemps.push_back(tagMsg);
	}
	else
	{
		m_vMsgQueue.push_back(tagMsg);
	}
}

void CCMsgManager::PostMessage(CCMsgDelegate* pDelegate, unsigned int uMsg, Ref* pMsgObj, void* wParam, void* lParam)
{
	if( !pDelegate )
		return;

	CCAssert(dynamic_cast<Ref*>(pDelegate), "this target should not null");

	ccTARGETMESSAGE4        tagMsg;
	tagMsg.pDelegate        = pDelegate;
	tagMsg.tMessage.uMsg    = uMsg;
	tagMsg.tMessage.pMsgObj = pMsgObj;
	tagMsg.tMessage.wParam  = wParam;
	tagMsg.tMessage.lParam  = lParam;

	Ref* pObj = dynamic_cast<Ref*>(pDelegate);
	CC_SAFE_RETAIN(pObj);
	CC_SAFE_RETAIN(pMsgObj);
	
	if( m_bDispatchMsgLocked )
	{
		m_vTargetMsgTemps.push_back(tagMsg);
	}
	else
	{
		m_vTargetMsgQueue.push_back(tagMsg);
	}
}


void CCMsgManager::registerMsgDelegate(CCMsgDelegate* pDelegate)
{
	CCAssert(pDelegate && dynamic_cast<Ref*>(pDelegate), "should not null");

	vector<CCMsgDelegate*>::iterator itr;
	itr = std::find(m_vMsgDelegates.begin(), m_vMsgDelegates.end(), pDelegate);

	if( itr != m_vMsgDelegates.end() )
	{
		return;
	}

	Ref* pObj = dynamic_cast<Ref*>(pDelegate);
	CC_SAFE_RETAIN(pObj);

	if( m_bDispatchMsgLocked )
	{
		m_vMsgDelegatesAdded.push_back(pDelegate);
	}
	else
	{
		m_vMsgDelegates.insert(m_vMsgDelegates.begin(), pDelegate);
	}
}

void CCMsgManager::unregisterMsgDelegate(CCMsgDelegate* pDelegate)
{
	CCAssert(pDelegate && dynamic_cast<Ref*>(pDelegate), "should not null");

	if( m_bDispatchMsgLocked )
	{
		m_vMsgDelegatesRemoved.push_back(pDelegate);
	}
	else
	{
		vector<CCMsgDelegate*>::iterator itr;
		itr = std::find(m_vMsgDelegates.begin(), m_vMsgDelegates.end(), pDelegate);

		if( itr != m_vMsgDelegates.end() )
			m_vMsgDelegates.erase(itr);

		Ref* pObj = dynamic_cast<Ref*>(pDelegate);
		CC_SAFE_RELEASE(pObj);
	}
}

NS_CC_END