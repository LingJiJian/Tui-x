#ifndef __TUI_BASE_H__
#define __TUI_BASE_H__

#include "cocos2d.h"
#include "TuiMacros.h"
#include "../../../CocosWidget/cocos-widget.h"
#include "../../cocos/editor-support/cocostudio/CocoStudio.h"

using namespace cocostudio;
using namespace cocos2d::cocoswidget;

NS_TUI_BEGIN

class TuiBase :public Scene
{
public:
	TuiBase();
	virtual ~TuiBase();

	CREATE_FUNC(TuiBase);
	virtual bool init(){ return true; };
	virtual Node *getControl(int tagPanel,int tagControl);
	virtual Node *getPanel(int tagPanel);		

protected:
	CC_SYNTHESIZE(bool, m_isAutoRemoveUnusedSpriteFrame, AutoRemoveUnusedSpriteFrame);
private:
};


NS_TUI_END

#endif

