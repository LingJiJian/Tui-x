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


NS_TUI_END