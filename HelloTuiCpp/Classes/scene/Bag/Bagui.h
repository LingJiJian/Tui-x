#ifndef __BAG_UI__
#define __BAG_UI__

#include "tui/TuiBase.h"
#include "BagCfg.h"

NS_BAG_BEGIN

class Bagui : public TuiBase
{
public:
	CREATE_SCENE_FUNC(Bagui);
    Node* getPanel( int tagPanel );
	void onLoadScene();
protected:
	Ref* event_adapt_gvBag(Ref* pConvertCell, unsigned int uIdx);
	Ref* event_adapt_tblBag(Ref* pConvertCell, unsigned int uIdx);
	Ref* event_adapt_pageBag(Ref* pConvertCell, unsigned int uIdx);
	void event_btn_back(Ref* pSender);

	void event_btn_gv(Ref* pSender);
private:

};

NS_BAG_END

#endif