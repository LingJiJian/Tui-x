#include "HelloWorldScene.h"

GameNetDelegate::GameNetDelegate()
{

}

GameNetDelegate::~GameNetDelegate()
{
	
}


void GameNetDelegate::onMessageReceived(CBuffer& oBuffer)
{
	CCLOG("onMessageReceived");

	switch( oBuffer.readInt() )
	{
	case 10:
		{
			CCLOG("%d", oBuffer.readInt());
			CCLOG("%d", oBuffer.readShort());
			CCLOG("%lld", oBuffer.readLongLong());
			CCLOG("%c", oBuffer.readChar());
			CCLOG("%f", oBuffer.readFloat());
			CCLOG("%lf", oBuffer.readDouble());
			CCLOG("%s", oBuffer.readLengthAndString().c_str());
		}
		break;
	case 5:
		{
			// large data
			CCLOG("large data length = %d", oBuffer.length());
		}
		break;
	}
}

void GameNetDelegate::onConnected()
{
	CCLOG("onConnected");
}

void GameNetDelegate::onConnectTimeout()
{
	CCLOG("onConnectTimeout");
}

void GameNetDelegate::onDisconnected()
{
	CCLOG("onDisconnected");
}

void GameNetDelegate::onExceptionCaught(CCSocketStatus eStatus)
{
	CCLOG("onExceptionCaught %d", (int)eStatus);
}

void GameNetDelegate::CS_Test()
{
	CBuffer buffer;
	buffer.writeInt(10);
	buffer.writeLongLong(999999999L);
	buffer.writeFloat(77.7f);
	buffer.writeDouble(99.9);
	buffer.writeChar('h');
	buffer.writeLengthAndString("hahahahaha");

	this->send(&buffer);
}

void GameNetDelegate::CS_LargePackage()
{
	CBuffer buffer;
	buffer.writeInt(5);

	this->send(&buffer);
}



bool AlphaScene::init()
{
	Scene::init();

	MenuItemFont* pConnect = MenuItemFont::create("Connect", this, menu_selector(AlphaScene::onConnectClick));
	pConnect->setFontSize(30);
	pConnect->setPosition(ccp(200, 200));

	MenuItemFont* pDisconnect = MenuItemFont::create("Disconnect", this, menu_selector(AlphaScene::onDisconnectClick));
	pDisconnect->setFontSize(30);
	pDisconnect->setPosition(ccp(350, 200));

	MenuItemFont* pLargeData = MenuItemFont::create("LargeDataTest", this, menu_selector(AlphaScene::onLargeDataClick));
	pLargeData->setFontSize(30);
	pLargeData->setPosition(ccp(500, 300));

	MenuItemFont* pTest = MenuItemFont::create("Test", this, menu_selector(AlphaScene::onTestClick));
	pTest->setFontSize(30);
	pTest->setPosition(ccp(500, 200));

	Menu* pMenu = Menu::create(pConnect, pDisconnect, pTest, pLargeData, NULL);
	pMenu->setPosition(CCPointZero);
	addChild(pMenu);

	//test frame 
	Sprite* picon = Sprite::create("Icon.png");
	picon->setPosition(ccp(150, 400));

	MoveBy* pMoveRight = MoveBy::create(0.5f, ccp(500, 0));
	MoveBy* pMoveLeft = MoveBy::create(0.5f, ccp(-500, 0));
	Sequence* pSeq = Sequence::create(pMoveRight, pMoveLeft, NULL);
	picon->runAction(CCRepeatForever::create(pSeq));


	addChild(picon);
	
	return true;
}

void AlphaScene::onConnectClick(Ref* pSender)
{
	CInetAddress oAddres;
	oAddres.setIp("192.168.0.100");
	oAddres.setPort(7789);

	GameNetDelegate::sharedDelegate()->setInetAddress(oAddres);
	GameNetDelegate::sharedDelegate()->connect();
}

void AlphaScene::onDisconnectClick(Ref* pSender)
{
	GameNetDelegate::sharedDelegate()->disconnect();
}

void AlphaScene::onTestClick(Ref* pSender)
{
	GameNetDelegate::sharedDelegate()->CS_Test();
}

void AlphaScene::onLargeDataClick(Ref* pSender)
{
	GameNetDelegate::sharedDelegate()->CS_LargePackage();
}