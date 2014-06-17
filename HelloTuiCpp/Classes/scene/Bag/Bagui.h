#ifndef __BAG_UI__
#define __BAG_UI__

#include "tui/TuiBase.h"
#include "BagCfg.h"

NS_BAG_BEGIN

class Bagui : public TuiBase
{
public:
	CREATE_SCENE_FUNC(Bagui);

	void onLoadScene();
	Node* getPanel(int tagPanel);
protected:
private:
};

NS_BAG_END

#endif