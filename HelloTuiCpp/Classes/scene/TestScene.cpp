//
//  TestScene.cpp
//  MyGame
//
//  Created by B-y on 15/3/30.
//
//

#include "TestScene.h"

bool TestScene::init(){
    if(!Node::init()) return false;
    
    Layout* pLayout = Layout::create();
    this->addChild(pLayout);
    
//    Button* pBtn = Button::create("main/btn_ok_normal.png");
//    pBtn->setPosition(Vec2(100,100));
//    pLayout->addChild(pBtn);
    
    Text* pLabel = Text::create();
    pLabel->setString("XXXXFEFEFEEEE\nEEXXXX");
    pLabel->setTouchEnabled(true);
    pLabel->addTouchEventListener(CC_CALLBACK_2(TestScene::evn_btn_test,this));
//    pBtn->addTouchEventListener(CC_CALLBACK_2(TestScene::evn_btn_test,this));
    
    RichText* _richText = RichText::create();
    _richText = RichText::create();
    _richText->ignoreContentAdaptWithSize(false);
    _richText->setContentSize(Size(100, 100));
    
    RichElementText* re1 = RichElementText::create(1, Color3B::WHITE, 255, "aaaaaa", "Marker Felt", 10);
    RichElementText* re2 = RichElementText::create(2, Color3B::YELLOW, 255, "And this is yellow. ", "Helvetica", 10);
    RichElementText* re3 = RichElementText::create(3, Color3B::GRAY, 255, "bbbbbb", "Helvetica", 10);
    RichElementText* re4 = RichElementText::create(4, Color3B::GREEN, 255, "And green with TTF support. ", "", 10);
    RichElementText* re5 = RichElementText::create(5, Color3B::RED, 255, "Last one is red ", "Helvetica", 10);
    
    RichElementCustomNode* recustom = RichElementCustomNode::create(1, Color3B::WHITE, 255, pLabel);
    RichElementText* re6 = RichElementText::create(7, Color3B::ORANGE, 255, "Have fun!! ", "Helvetica", 10);
    _richText->pushBackElement(re1);
    _richText->insertElement(re2, 1);
    _richText->pushBackElement(re3);
    _richText->pushBackElement(re4);
    _richText->pushBackElement(recustom);
    _richText->pushBackElement(re5);
//    _richText->insertElement(reimg, 2);
    
    _richText->pushBackElement(re6);
    _richText->setPosition(Vec2(100,100));
    _richText->ignoreContentAdaptWithSize(false);
    _richText->setContentSize(Size(100, 100));
    pLayout->addChild(_richText);
    
//    pRtf->addTouchEventListener(CC_CALLBACK_2(TestScene::evn_btn_test,this));
    
    return true;
}

void TestScene::evn_btn_test(Ref *pSender, ui::Widget::TouchEventType type)
{
    
}

TestScene *TestScene::create()
{
    TestScene *pScene = new TestScene();
    if (pScene && pScene->init())
    {
        pScene->autorelease();
        return pScene;
    }
    CC_SAFE_DELETE(pScene);
    return NULL;
}
