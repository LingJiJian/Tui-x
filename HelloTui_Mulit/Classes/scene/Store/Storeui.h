#ifndef __STORE_UI_H__
#define __STORE_UI_H__

#include "tui/TuiBase.h"
#include "StoreCfg.h"

NS_STORE_BEGIN

class Storeui : public TuiBase
{
public:
	CREATE_SCENE_FUNC(Storeui);

	void onLoadScene();

	Node *getPanel(int tagPanel);
protected:
	void event_btn_test(Ref* pSender);
private:
};

NS_STORE_END

#endif