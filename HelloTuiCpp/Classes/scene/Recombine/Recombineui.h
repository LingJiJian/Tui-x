#ifndef __RECOMBINE_UI_H__
#define __RECOMBINE_UI_H__

#include "tui/TuiBase.h"

class Recomebineui : public TuiBase
{
public:
	CREATE_SCENE_FUNC(Recomebineui);

	virtual void onLoadScene();
    Node* getPanel( int tagPanel );
protected:
	Ref* adapt_gpv_bag(Ref* pConvertCell, unsigned int uIdx);

	void event_btn_click(Ref* pSender);
	void event_btn_back(Ref* pSender);
private:
	

};


#endif 
