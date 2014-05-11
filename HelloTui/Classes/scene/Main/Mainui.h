#ifndef __MAIN_UI_H__
#define __MAIN_UI_H__

#include "tui/TuiBase.h"
#include "MainCfg.h"

NS_MAIN_BEGIN

class Mainui : public TuiBase
{
public:
	CREATE_SCENE_FUNC(Mainui);

	void onLoadScene();

	Node* getPanel(int tagPanel);
protected:
	void event_ctlv_left(Ref* pSender, float fx, float fy);
	void event_btn_ok(Ref* pSender);
	void event_btn_go(Ref* pSender);
private:
};


NS_MAIN_END
#endif