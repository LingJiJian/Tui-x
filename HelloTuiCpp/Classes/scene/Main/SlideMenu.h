#ifndef __SlideMenu_H__
#define __SlideMenu_H__

#include "../../tui/TuiBase.h"
#include "MainCfg.h"

NS_MAIN_BEGIN

class SlideMenu : public CLayout
{
public:
	static SlideMenu* create();
	bool init();

	virtual CWidgetTouchModel onTouchBegan(Touch* pTouch);

private:
};


NS_MAIN_END
#endif