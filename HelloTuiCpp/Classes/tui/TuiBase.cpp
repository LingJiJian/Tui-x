#include "TuiBase.h"

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
Node* TuiBase::getControl(int tagPanel,int tagControl){
	Node* control = getPanel(tagPanel)->getChildByTag(tagControl);
	return control;
}
Node* TuiBase::getPanel(int tagPanel){
	//Override
	return NULL;
}
