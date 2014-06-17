#ifndef __TUI_BASE_H__
#define __TUI_BASE_H__

#include "cocos2d.h"
#include "TuiMacros.h"
#include "../../CocosWidget/cocos-widget.h"
#include "../../CocosBase/cocos-base.h"
#include "../editor-support/cocostudio/CocoStudio.h"

using namespace cocos2d;
using namespace cocostudio;
using namespace cocos2d::cocoswidget;

class TuiBase : public CSceneExtension {
public:
	
	TuiBase();
	virtual ~TuiBase();
	virtual Node *getControl(int tagPanel,int tagControl);
	virtual Node *getPanel(int tagPanel);		

protected:
	CC_SYNTHESIZE(bool, m_isAutoRemoveUnusedSpriteFrame, AutoRemoveUnusedSpriteFrame);
private:
};


#endif

