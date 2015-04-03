//
//  TestScene.h
//  MyGame
//
//  Created by B-y on 15/3/30.
//
//

#ifndef __MyGame__TestScene__
#define __MyGame__TestScene__

#include "cocos2d.h"
#include "CocosGUI.h"
USING_NS_CC;
using namespace ui;

class TestScene : public Scene
{
public:
    static TestScene* create();
    virtual bool init();
    void evn_btn_test(Ref *pSender, ui::Widget::TouchEventType type);
};

#endif /* defined(__MyGame__TestScene__) */
