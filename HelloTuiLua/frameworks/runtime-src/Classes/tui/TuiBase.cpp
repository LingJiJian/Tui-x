#include "TuiBase.h"

NS_TUI_BEGIN

TuiBase::TuiBase()
:m_isAutoRemoveUnusedSpriteFrame(false)
{
}

TuiBase::~TuiBase(){
	if(m_isAutoRemoveUnusedSpriteFrame){
		removeAllChildrenWithCleanup(true);
		SpriteFrameCache::getInstance()->removeUnusedSpriteFrames();
	}
}

/************************************************************************/
// GET/SET/IS
/************************************************************************/
void TuiBase::setOnMessageScriptHandler(int nHandler)
{
	removeOnMessageScriptHandler();
	m_nMessageScriptHandler = nHandler;
}

void TuiBase::removeOnMessageScriptHandler()
{
	if (m_nMessageScriptHandler != 0)
	{
		ScriptEngineManager::getInstance()->getScriptEngine()->removeScriptHandler(m_nMessageScriptHandler);
		m_nMessageScriptHandler = 0;
	}
}

NS_TUI_END