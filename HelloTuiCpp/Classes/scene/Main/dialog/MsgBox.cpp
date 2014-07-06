#include "MsgBox.h"
#include "tui/TuiManager.h"
#include "tui/tagMap/tuiTag_main.h"

NS_MAIN_BEGIN


void MsgBox::onLoadScene()
{
	//setAutoRemoveUnusedTexture(true);
	TuiManager::getInstance()->parseScene(this,"panel_msgbox",PATH_MAIN);
	//注册事件
	CButton *pBtnClose = (CButton*)getControl(PANEL_MSGBOX,BTN_CLOSE);
	pBtnClose->setOnClickListener(this,ccw_click_selector(MsgBox::event_btn_close));
	
	CSlider *pSlider = (CSlider*)getControl(PANEL_MSGBOX,SLIDER_TEST);
	pSlider->setOnValueChangedListener(this,ccw_valuechanged_selector(MsgBox::event_slider_test));

	CProgressBar *pProg = (CProgressBar*)this->getControl(PANEL_MSGBOX,PROG_HP);
	pProg->setShowValueLabel(true);
}

void MsgBox::event_btn_close( Ref *pSender )
{
	//解除塑形
	//CSceneManager::getInstance()->getRunningScene()->setModalable(false);
	CSceneManager::getInstance()->popUIScene(this);
}

void MsgBox::event_slider_test(Ref *pSender,int value)
{
	char buf[128] = {0};
	sprintf(buf,"%d",value);
	CLabelAtlas *pLab = (CLabelAtlas*)this->getControl(PANEL_MSGBOX,LABATLAS_NUM);
	pLab->setString(buf);

	CProgressBar *pProg = (CProgressBar*)this->getControl(PANEL_MSGBOX,PROG_HP);
	pProg->setValue(value);

}

/************************************************************************/
//	GET/SET/IS
/************************************************************************/
Node* MsgBox::getControl(int tagPanel, int tagControl){
	Node* control = getPanel(tagPanel)->getChildByTag(tagControl);
	return control;
}

Node *MsgBox::getPanel( int tagPanel )
{
	Node *pPanel = nullptr;
	switch (tagPanel)
	{
	case PANEL_MSGBOX:
		pPanel = this->getChildByTag(PANEL_MSGBOX);
		break;
	}
	return pPanel;
}


NS_MAIN_END