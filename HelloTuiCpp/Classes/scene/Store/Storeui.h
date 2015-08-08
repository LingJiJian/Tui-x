#ifndef __STORE_UI_H__
#define __STORE_UI_H__

#include "../../tui/TuiBase.h"
#include "StoreCfg.h"

NS_STORE_BEGIN

class Storeui : public TuiBase
{
public:
	CREATE_SCENE_FUNC(Storeui);
    Node* getPanel( int tagPanel );
	void onLoadScene();

protected:
	void event_btn_test(Ref* pSender);
	void event_btn_pay(Ref* pSender);
	void event_explist_btn(Ref* pSender);
	void event_rtf_test(Ref* pSender,int tag);
private:
};

NS_STORE_END

#endif