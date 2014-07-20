#ifndef __SHOW_PHONE_UI__
#define __SHOW_PHONE_UI__

#include "ShowPhoneCfg.h"
#include "tui/TuiBase.h"

NS_SHOWPHONE_BEGIN

class ShowPhoneui : public TuiBase
{
public:
	CREATE_SCENE_FUNC(ShowPhoneui);
	void onLoadScene();

	Node *getPanel(int tagPanel);
protected:
	void event_menu_phone(Ref* pSender);
private:
};

NS_SHOWPHONE_END

#endif