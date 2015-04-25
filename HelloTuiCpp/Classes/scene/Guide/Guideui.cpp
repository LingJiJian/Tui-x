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
