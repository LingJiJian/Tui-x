#include "MenuScene.h"
#include "GUI/CCScrollView/CCScrollView.h"

using namespace cocos2d::extension;


MenuScene::MenuScene()
{

}

MenuScene::~MenuScene()
{
}

void MenuScene::onLoadScene()
{
	
	m_vMenuItems.push_back("Basic Test");

	Size tContainerSize = Size(700, 100 * m_vMenuItems.size());

	Layer* pScrollViewContainer = Layer::create();
	pScrollViewContainer->setPosition(Point::ZERO);
	pScrollViewContainer->setContentSize(tContainerSize);

	m_pScrollView = ScrollView::create(Size(700, 640));
	m_pScrollView->ignoreAnchorPointForPosition(false);
	m_pScrollView->setPosition(CCPoint(480, 320));
	m_pScrollView->setContainer(pScrollViewContainer);
	addChild(m_pScrollView);
	
	Vector<MenuItem *> vet;

	float height = tContainerSize.height;

	unsigned int i = 0;
	unsigned int end = m_vMenuItems.size();
	for(; i < end; ++i )
	{
		MenuItemFont* pFont = MenuItemFont::create(m_vMenuItems[i].c_str());
		pFont->setCallback(CC_CALLBACK_1(MenuScene::onClick,this));
		pFont->setFontSizeObj(45.0f);
		pFont->setPosition(Point(700 / 2, height - 100 / 2));
		pFont->setTag(i + 1);
		vet.pushBack(pFont);

		height -= 100;
	}

	Menu* pMenu = Menu::createWithArray(vet);
	pMenu->setPosition(Point(0,0));
	pScrollViewContainer->addChild(pMenu);

	m_pScrollView->setContentOffset(Point(0, -(tContainerSize.height - 640)));
	
}

void MenuScene::onClick(Ref* sender)
{
	MenuItemFont* pFont = (MenuItemFont*) sender;
	switch( pFont->getTag() )
	{
	case 1:
		{
			CSceneManager::getInstance()->pushScene(
				CCSceneExTransitionFade::create(1.0f, LoadScene("BasicSceneTest"))
				);
		}
		break;
	}
}