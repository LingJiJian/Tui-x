#include "Mapui.h"
#include "tui/TuiManager.h"
#include "tui/tagMap/Tag_map.h"

void Mapui::onLoadScene()
{
	TuiManager::getInstance()->parseScene(this,"panel_map",PATH_MAP);

    CMapView* pMapView = (CMapView*)this->getControl(PANEL_MAP,MAP_TEST);
	pMapView->setRole(Sprite::create("map/img_icon.png"),Vec2(0,0),1);
    
    CButton* pBtnBack = (CButton*)this->getControl(PANEL_MAP,BTN_BACK);
    pBtnBack->setOnClickListener(this, ccw_click_selector(Mapui::event_btn_back));
}

void Mapui::event_btn_back(Ref* pSender)
{
    CSceneManager::getInstance()->replaceScene(CCSceneExTransitionFade::create(0.5f, LoadScene("Main::Mainui")));
}


Node* Mapui::getPanel( int tagPanel )
{
    Node *pPanel = nullptr;
    switch (tagPanel)
    {
        case PANEL_MAP:
            pPanel = this->getChildByTag(PANEL_MAP);
            break;
    }
    return pPanel;
}