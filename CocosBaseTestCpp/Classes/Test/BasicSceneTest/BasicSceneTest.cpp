#include "BasicSceneTest.h"

BasicSceneTest::BasicSceneTest()
{

}

BasicSceneTest::~BasicSceneTest()
{

}

void BasicSceneTest::onLoadResources()
{
	addImageAsync("startMenuBG.png");
	addImageAsync("btn1_1.png");
	addImageAsync("btn1_2.png");
}

void BasicSceneTest::onLoadScene()
{
	setAutoRemoveUnusedTexture(true);

	Sprite* bg = Sprite::create("startMenuBG.png");
	bg->setPosition(Point(480, 320));
	addChild(bg);

	m_pMenu = Menu::create();
	m_pMenu->setPosition(Point::ZERO);
	addChild(m_pMenu);

	MenuItemFont* pFont = MenuItemFont::create("Back");
	pFont->setCallback(CC_CALLBACK_1(BasicSceneTest::onClick,this));
	pFont->setFontSizeObj(45.0f);
	pFont->setPosition(CCPoint(893, 35));
	pFont->setTag(1);
	m_pMenu->addChild(pFont);

	MenuItemImage* pUiSceneBtn = MenuItemImage::create("btn1_1.png", "btn1_2.png");
	pUiSceneBtn->setCallback(CC_CALLBACK_1(BasicSceneTest::onClick,this));
	pUiSceneBtn->setPosition(CCPoint(600, 200));
	pUiSceneBtn->setTag(2);
	m_pMenu->addChild(pUiSceneBtn);

	Label* pLabel1 = Label::createWithSystemFont("runUIScene", "", 30);
	pLabel1->setColor(Color3B::RED);
	pLabel1->setPosition(CCPoint(600, 200));
	addChild(pLabel1);

	Label* pLabel = Label::createWithSystemFont("hello CocosBase and Cocos2d-x", "", 30);
	pLabel->setColor(Color3B::RED);
	pLabel->setPosition(Point(480, 320));
	addChild(pLabel);
}

void BasicSceneTest::onEnterScene()
{
	//m_pMenu->setTouchPriority(CSceneManager::getInstance()->getTouchPriority());
}

void BasicSceneTest::onClick(Ref* sender)
{
	Node* pNode = (Node*) sender;
	switch( pNode->getTag() )
	{
	case 1:
		{
			CSceneManager::getInstance()->popScene();
		}
		break;
	case 2:
		{
			CSceneManager::getInstance()->runUIScene(LoadScene("BasicUIScene"));
		}
		break;
	}
}




void BasicUIScene::onLoadResources()
{
	addImage("background.png");
}

void BasicUIScene::onLoadScene()
{
	setAutoRemoveUnusedTexture(true);

	Sprite* bg = Sprite::create("background.png");
	bg->setPosition(Point(480, 320));
	addChild(bg);

	m_pMenu = Menu::create();
	m_pMenu->setPosition(Point::ZERO);
	addChild(m_pMenu);

	MenuItemImage* pBtn = MenuItemImage::create("CloseNormal.png", "CloseSelected.png");
	pBtn->setCallback(CC_CALLBACK_1(BasicUIScene::onClick,this));
	pBtn->setPosition(Point(480, 320));
	m_pMenu->addChild(pBtn);
}

void BasicUIScene::onEnterScene()
{
	//m_pMenu->setTouchPriority(CSceneManager::getInstance()->getTouchPriority());
	//m_pMenu
}

void BasicUIScene::onClick(Ref* sender)
{
	CSceneManager::getInstance()->popUIScene(this);
}