#ifndef __MAIN_UI_H__
#define __MAIN_UI_H__

#include "tui/TuiBase.h"
#include "MainCfg.h"

NS_MAIN_BEGIN

class Mainui : public TuiBase , CEditBoxDelegate
{
public:
	CREATE_SCENE_FUNC(Mainui);

	void onLoadScene();

	Node* getPanel(int tagPanel);
protected:
	void event_btn_showphone(Ref* pSender);
	void event_ctlv_left(Ref* pSender, float fx, float fy);
	void event_btn_ok(Ref* pSender);
	void event_btn_go(Ref* pSender);
	void event_btn_bag(Ref* pSender);
	void event_btn_recombine(Ref* pSender);

	void event_tgvA_check(Ref *pSender, bool bChecked);
	void event_tgvB_check(Ref *pSender, bool bChecked);

	void onMessage(unsigned int uMsg, Ref* pMsgObj, void* wParam, void* lParam);
    
    void editBoxReturn(CEditBox* editBox);
private:
};


NS_MAIN_END
#endif