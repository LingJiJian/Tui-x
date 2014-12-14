#include "Guideui.h"
#include "tui/TuiManager.h"
#include "tui/tagMap/Tag_main.h"

void Guideui::onLoadScene()
{
	TuiManager::getInstance()->parseScene(this,"panel_guide",PATH_MAIN);
	
}

/************************************************************************/
//	GET/SET/IS
/************************************************************************/
Node * Guideui::getPanel( int tagPanel )
{
	Node *pPanel = nullptr;
	switch (tagPanel)
	{
	case PANEL_GUIDE:
		pPanel = this->getChildByTag(PANEL_GUIDE);
		break;
	}
	return pPanel;
}