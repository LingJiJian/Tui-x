#include "ResoureMgr.h"

#include "scene/Welcome/Welcomeui.h"
#include "scene/Main/Mainui.h"
#include "scene/Main/dialog/MessageBox.h"
#include "scene/Store/Storeui.h"

bool ResoureMgr::init(){
	return true;
}

void ResoureMgr::registScene(){

	REGISTER_SCENE_FUNC(Welcome::Welcomeui);				//欢迎页

	REGISTER_SCENE_FUNC(Main::Mainui);						//主界面
	REGISTER_SCENE_FUNC(Main::MessageBox);					//消息框

	REGISTER_SCENE_FUNC(Store::Storeui);					//商店
}