#include "Bagui.h"
#include "tui/tagMap/tuiTag_bag.h"
#include "tui/TuiManager.h"

NS_BAG_BEGIN

void Bagui::onLoadScene()
{
	TuiManager::getInstance()->parseScene(this, "panel_bag", PATH_BAG);
}

/************************************************************************/
//	GET/SET/IS
/************************************************************************/
Node* Bagui::getPanel(int tagPanel)
{
	Node* pPanel = nullptr;
	switch (tagPanel)
	{
	case PANEL_BAG:
		pPanel = this->getChildByTag(PANEL_BAG);
		break;
	}
	return pPanel;
}

NS_BAG_END