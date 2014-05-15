#ifndef __TUI_BASE_H__
#define __TUI_BASE_H__

#include "cocos2d.h"

#include "../../../CocosWidget/cocos-widget.h"
#include "../../../CocosBase/cocos-base.h"
#include "cocostudio/CocoStudio.h"

using namespace cocostudio;
using namespace cocos2d::cocoswidget;
USING_NS_CC;

class TuiBase : public CSceneExtension {
public:
	TuiBase();
	virtual ~TuiBase();
	virtual Node *getControl(int tagPanel,int tagControl);
	virtual Node *getPanel(int tagPanel) = 0;		

protected:
	CC_SYNTHESIZE(bool, m_isAutoRemoveUnusedSpriteFrame, AutoRemoveUnusedSpriteFrame);
private:
};

#endif

