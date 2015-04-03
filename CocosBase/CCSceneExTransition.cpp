/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2008-2010 Ricardo Quesada
Copyright (c) 2011      Zynga Inc.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#include "CCSceneExTransition.h"
#include "CCSceneManager.h"
#include "2d/CCScene.h"

NS_CC_BEGIN

const unsigned int kSceneFade = 0xFADEFADE;

CCSceneExTransition::CCSceneExTransition()
{
}
CCSceneExTransition::~CCSceneExTransition()
{
    m_pInScene->release();
    m_pOutScene->release();
}

CCSceneExTransition * CCSceneExTransition::create(float t, CSceneExtension *scene)
{
    CCSceneExTransition * pScene = new CCSceneExTransition();
    if(pScene && pScene->initWithDuration(t,scene))
    {
        pScene->autorelease();
        return pScene;
    }
    CC_SAFE_DELETE(pScene);
    return NULL;
}

bool CCSceneExTransition::initWithDuration(float t, CSceneExtension *scene)
{
    CCAssert( scene != NULL, "Argument scene must be non-nil");

    if (CSceneExtension::init())
    {
        m_fDuration = t;

        // retain
        m_pInScene = scene;
        m_pInScene->retain();
		m_pOutScene = CSceneManager::getInstance()->getRunningScene();
        if (m_pOutScene == NULL)
        {
            m_pOutScene = CSceneExtension::create();
        }
        m_pOutScene->retain();

        CCAssert( m_pInScene != m_pOutScene, "Incoming scene must be different from the outgoing scene" );
        
        sceneOrder();

        return true;
    }
    else
    {
        return false;
    }
}

void CCSceneExTransition::sceneOrder()
{
    m_bIsInSceneOnTop = true;
}

void CCSceneExTransition::draw(Renderer *renderer, const Mat4& transform, uint32_t flags)
{
    CSceneExtension::draw(renderer, transform, flags);

    if( m_bIsInSceneOnTop ) {
        m_pOutScene->visit(renderer, transform, flags);
        m_pInScene->visit(renderer, transform, flags);
    } else {
        m_pInScene->visit(renderer, transform, flags);
        m_pOutScene->visit(renderer, transform, flags);
    }
}

void CCSceneExTransition::finish()
{
    // clean up     
     m_pInScene->setVisible(true);
     m_pInScene->setPosition(Vec2(0,0));
     m_pInScene->setScale(1.0f);
     m_pInScene->setRotation(0.0f);
     m_pInScene->setAdditionalTransform(nullptr);
 
     m_pOutScene->setVisible(false);
     m_pOutScene->setPosition(Vec2(0,0));
     m_pOutScene->setScale(1.0f);
     m_pOutScene->setRotation(0.0f);
     m_pOutScene->setAdditionalTransform(nullptr);

    //[self schedule:@selector(setNewScene:) interval:0];
    this->schedule(schedule_selector(CCSceneExTransition::setNewScene), 0);

}

void CCSceneExTransition::setNewScene(float dt)
{    
    CC_UNUSED_PARAM(dt);

    this->unschedule(schedule_selector(CCSceneExTransition::setNewScene));
    
    // Before replacing, save the "send cleanup to scene"
	CSceneManager* manager = CSceneManager::getInstance();
    m_bIsSendCleanupToScene = manager->isSendCleanupToScene();
    
    manager->replaceScene(m_pInScene);
    
    // issue #267
    m_pOutScene->setVisible(true);
}

void CCSceneExTransition::hideOutShowIn()
{
    m_pInScene->setVisible(true);
    m_pOutScene->setVisible(false);
}


// custom onEnter
void CCSceneExTransition::onEnter()
{
    CSceneExtension::onEnter();
    
    // disable events while transitions
   _eventDispatcher->setEnabled(false);
    
    // outScene should not receive the onEnter callback
    // only the onExitTransitionDidStart
    m_pOutScene->onExitTransitionDidStart();
    
    m_pInScene->onEnter();
}

// custom onExit
void CCSceneExTransition::onExit()
{
    CSceneExtension::onExit();
    
    // enable events while transitions
   _eventDispatcher->setEnabled(true);
    
    m_pOutScene->onExit();

    // m_pInScene should not receive the onEnter callback
    // only the onEnterTransitionDidFinish
    m_pInScene->onEnterTransitionDidFinish();
}

// custom cleanup
void CCSceneExTransition::cleanup()
{
    CSceneExtension::cleanup();

    if( m_bIsSendCleanupToScene )
        m_pOutScene->cleanup();
}

CSceneExtension* CCSceneExTransition::getInScene()
{
	return m_pInScene;
}

//
// Oriented Transition
//

CCSceneExTransitionOriented::CCSceneExTransitionOriented()
{
}

CCSceneExTransitionOriented::~CCSceneExTransitionOriented()
{
}

CCSceneExTransitionOriented * CCSceneExTransitionOriented::create(float t, CSceneExtension *scene, TransitionScene::Orientation orientation)
{
    CCSceneExTransitionOriented * pScene = new CCSceneExTransitionOriented();
    pScene->initWithDuration(t,scene,orientation);
    pScene->autorelease();
    return pScene;
}

bool CCSceneExTransitionOriented::initWithDuration(float t, CSceneExtension *scene, TransitionScene::Orientation orientation)
{
    if ( CCSceneExTransition::initWithDuration(t, scene) )
    {
        m_eOrientation = orientation;
    }
    return true;
}

//
// RotoZoom
//
CCSceneExTransitionRotoZoom::CCSceneExTransitionRotoZoom()
{
}

CCSceneExTransitionRotoZoom* CCSceneExTransitionRotoZoom::create(float t, CSceneExtension* scene)                   
{                                                               
    CCSceneExTransitionRotoZoom* pScene = new CCSceneExTransitionRotoZoom();                                
    if(pScene && pScene->initWithDuration(t, scene))            
    {                                                           
        pScene->autorelease();                                  
        return pScene;                                          
    }                                                           
    CC_SAFE_DELETE(pScene);                                     
    return NULL;                                                
}

CCSceneExTransitionRotoZoom::~CCSceneExTransitionRotoZoom()
{
}

void CCSceneExTransitionRotoZoom:: onEnter()
{
    CCSceneExTransition::onEnter();

    m_pInScene->setScale(0.001f);
    m_pOutScene->setScale(1.0f);

    m_pInScene->setAnchorPoint(Vec2(0.5f, 0.5f));
    m_pOutScene->setAnchorPoint(Vec2(0.5f, 0.5f));

    ActionInterval *rotozoom = (ActionInterval*)(Sequence::create
    (
        Spawn::create
        (
            ScaleBy::create(m_fDuration/2, 0.001f),
            RotateBy::create(m_fDuration/2, 360 * 2),
            nullptr
        ),
        DelayTime::create(m_fDuration/2),
        nullptr
    ));

    m_pOutScene->runAction(rotozoom);
    m_pInScene->runAction
    (
        Sequence::create
        (
            rotozoom->reverse(),
            CallFunc::create(CC_CALLBACK_0(CCSceneExTransition::finish,this)),
            nullptr
        )
    );
}

//
// JumpZoom
//
CCSceneExTransitionJumpZoom::CCSceneExTransitionJumpZoom()
{
}
CCSceneExTransitionJumpZoom::~CCSceneExTransitionJumpZoom()
{
}

CCSceneExTransitionJumpZoom* CCSceneExTransitionJumpZoom::create(float t, CSceneExtension* scene)
{
    CCSceneExTransitionJumpZoom* pScene = new CCSceneExTransitionJumpZoom();
    if(pScene && pScene->initWithDuration(t, scene))
    {
        pScene->autorelease();
        return pScene;
    }
    CC_SAFE_DELETE(pScene);
    return NULL;
}

void CCSceneExTransitionJumpZoom::onEnter()
{
    CCSceneExTransition::onEnter();
    Size s = Director::getInstance()->getWinSize();

    m_pInScene->setScale(0.5f);
    m_pInScene->setPosition(Vec2(s.width, 0));
    m_pInScene->setAnchorPoint(Vec2(0.5f, 0.5f));
    m_pOutScene->setAnchorPoint(Vec2(0.5f, 0.5f));

    ActionInterval *jump = JumpBy::create(m_fDuration/4, Vec2(-s.width,0), s.width/4, 2);
    ActionInterval *scaleIn = ScaleTo::create(m_fDuration/4, 1.0f);
    ActionInterval *scaleOut = ScaleTo::create(m_fDuration/4, 0.5f);

    ActionInterval *jumpZoomOut = (ActionInterval*)(Sequence::create(scaleOut, jump, NULL));
    ActionInterval *jumpZoomIn = (ActionInterval*)(Sequence::create(jump, scaleIn, NULL));

    ActionInterval *delay = DelayTime::create(m_fDuration/2);

    m_pOutScene->runAction(jumpZoomOut);
    m_pInScene->runAction
    (
        Sequence::create
        (
            delay,
            jumpZoomIn,
             CallFunc::create(CC_CALLBACK_0(CCSceneExTransition::finish,this)),
            NULL
        )
    );
}

//
// MoveInL
//
CCSceneExTransitionMoveInL::CCSceneExTransitionMoveInL()
{
}

CCSceneExTransitionMoveInL::~CCSceneExTransitionMoveInL()
{
}

CCSceneExTransitionMoveInL* CCSceneExTransitionMoveInL::create(float t, CSceneExtension* scene)
{
    CCSceneExTransitionMoveInL* pScene = new CCSceneExTransitionMoveInL();
    if(pScene && pScene->initWithDuration(t, scene))
    {
        pScene->autorelease();
        return pScene;
    }
    CC_SAFE_DELETE(pScene);
    return NULL;
}

void CCSceneExTransitionMoveInL::onEnter()
{
    CCSceneExTransition::onEnter();
    this->initScenes();

    ActionInterval *a = this->action();

    m_pInScene->runAction
    (
        Sequence::create
        (
            this->easeActionWithAction(a),
			CallFunc::create(CC_CALLBACK_0(CCSceneExTransition::finish,this)),
            nullptr
        )
    );
}
 
ActionInterval* CCSceneExTransitionMoveInL::action()
{
    return MoveTo::create(m_fDuration, Vec2(0,0));
}

ActionInterval* CCSceneExTransitionMoveInL::easeActionWithAction(ActionInterval* action)
{
    return EaseOut::create(action, 2.0f);
//    return [EaseElasticOut actionWithAction:action period:0.4f];
}

void CCSceneExTransitionMoveInL::initScenes()
{
    Size s = Director::getInstance()->getWinSize();
    m_pInScene->setPosition(Vec2(-s.width,0));
}

//
// MoveInR
//
CCSceneExTransitionMoveInR::CCSceneExTransitionMoveInR()
{
}
CCSceneExTransitionMoveInR::~CCSceneExTransitionMoveInR()
{
}

CCSceneExTransitionMoveInR* CCSceneExTransitionMoveInR::create(float t, CSceneExtension* scene)
{
    CCSceneExTransitionMoveInR* pScene = new CCSceneExTransitionMoveInR();
    if(pScene && pScene->initWithDuration(t, scene))
    {
        pScene->autorelease();
        return pScene;
    }
    CC_SAFE_DELETE(pScene);
    return NULL;
}

void CCSceneExTransitionMoveInR::initScenes()
{
    Size s = Director::getInstance()->getWinSize();
    m_pInScene->setPosition( Vec2(s.width,0) );
}

//
// MoveInT
//
CCSceneExTransitionMoveInT::CCSceneExTransitionMoveInT()
{
}
CCSceneExTransitionMoveInT::~CCSceneExTransitionMoveInT()
{
}

CCSceneExTransitionMoveInT* CCSceneExTransitionMoveInT::create(float t, CSceneExtension* scene)
{
    CCSceneExTransitionMoveInT* pScene = new CCSceneExTransitionMoveInT();
    if(pScene && pScene->initWithDuration(t, scene))
    {
        pScene->autorelease();
        return pScene;
    }
    CC_SAFE_DELETE(pScene);
    return NULL;
}

void CCSceneExTransitionMoveInT::initScenes()
{
    Size s = Director::getInstance()->getWinSize();
    m_pInScene->setPosition( Vec2(0,s.height) );
}

//
// MoveInB
//
CCSceneExTransitionMoveInB::CCSceneExTransitionMoveInB()
{
}
CCSceneExTransitionMoveInB::~CCSceneExTransitionMoveInB()
{
}

CCSceneExTransitionMoveInB* CCSceneExTransitionMoveInB::create(float t, CSceneExtension* scene)
{
    CCSceneExTransitionMoveInB* pScene = new CCSceneExTransitionMoveInB();
    if(pScene && pScene->initWithDuration(t, scene))
    {
        pScene->autorelease();
        return pScene;
    }
    CC_SAFE_DELETE(pScene);
    return NULL;
}

void CCSceneExTransitionMoveInB::initScenes()
{
    Size s = Director::getInstance()->getWinSize();
    m_pInScene->setPosition( Vec2(0,-s.height) );
}


//
// SlideInL
//

// The adjust factor is needed to prevent issue #442
// One solution is to use DONT_RENDER_IN_SUBPIXELS images, but NO
// The other issue is that in some transitions (and I don't know why)
// the order should be reversed (In in top of Out or vice-versa).
#ifndef ADJUST_FACTOR
#define ADJUST_FACTOR 0.5f
#endif
CCSceneExTransitionSlideInL::CCSceneExTransitionSlideInL()
{
}

CCSceneExTransitionSlideInL::~CCSceneExTransitionSlideInL()
{
}

void CCSceneExTransitionSlideInL::onEnter()
{
    CCSceneExTransition::onEnter();
    this->initScenes();

    ActionInterval *in = this->action();
    ActionInterval *out = this->action();

    ActionInterval* inAction = easeActionWithAction(in);
    ActionInterval* outAction = (ActionInterval*)Sequence::create
    (
        easeActionWithAction(out),
         CallFunc::create(CC_CALLBACK_0(CCSceneExTransition::finish,this)), 
        NULL
    );
    m_pInScene->runAction(inAction);
    m_pOutScene->runAction(outAction);
}

void CCSceneExTransitionSlideInL::sceneOrder()
{
    m_bIsInSceneOnTop = false;
}

void CCSceneExTransitionSlideInL:: initScenes()
{
    Size s = Director::getInstance()->getWinSize();
    m_pInScene->setPosition( Vec2(-(s.width-ADJUST_FACTOR),0) );
}

ActionInterval* CCSceneExTransitionSlideInL::action()
{
    Size s = Director::getInstance()->getWinSize();
    return MoveBy::create(m_fDuration, Vec2(s.width-ADJUST_FACTOR,0));
}

ActionInterval* CCSceneExTransitionSlideInL::easeActionWithAction(ActionInterval* action)
{
    return EaseOut::create(action, 2.0f);
}

CCSceneExTransitionSlideInL* CCSceneExTransitionSlideInL::create(float t, CSceneExtension* scene)
{
    CCSceneExTransitionSlideInL* pScene = new CCSceneExTransitionSlideInL();
    if(pScene && pScene->initWithDuration(t, scene))
    {
        pScene->autorelease();
        return pScene;
    }
    CC_SAFE_DELETE(pScene);
    return NULL;
}

//
// SlideInR
//
CCSceneExTransitionSlideInR::CCSceneExTransitionSlideInR()
{
}
CCSceneExTransitionSlideInR::~CCSceneExTransitionSlideInR()
{
}

CCSceneExTransitionSlideInR* CCSceneExTransitionSlideInR::create(float t, CSceneExtension* scene)
{
    CCSceneExTransitionSlideInR* pScene = new CCSceneExTransitionSlideInR();
    if(pScene && pScene->initWithDuration(t, scene))
    {
        pScene->autorelease();
        return pScene;
    }
    CC_SAFE_DELETE(pScene);
    return NULL;
}

void CCSceneExTransitionSlideInR::sceneOrder()
{
    m_bIsInSceneOnTop = true;
}

void CCSceneExTransitionSlideInR::initScenes()
{
    Size s = Director::getInstance()->getWinSize();
    m_pInScene->setPosition( Vec2(s.width-ADJUST_FACTOR,0) );
}


ActionInterval* CCSceneExTransitionSlideInR:: action()
{
    Size s = Director::getInstance()->getWinSize();
    return MoveBy::create(m_fDuration, Vec2(-(s.width-ADJUST_FACTOR),0));
}


//
// SlideInT
//
CCSceneExTransitionSlideInT::CCSceneExTransitionSlideInT()
{
}
CCSceneExTransitionSlideInT::~CCSceneExTransitionSlideInT()
{
}

CCSceneExTransitionSlideInT* CCSceneExTransitionSlideInT::create(float t, CSceneExtension* scene)
{
    CCSceneExTransitionSlideInT* pScene = new CCSceneExTransitionSlideInT();
    if(pScene && pScene->initWithDuration(t, scene))
    {
        pScene->autorelease();
        return pScene;
    }
    CC_SAFE_DELETE(pScene);
    return NULL;
}

void CCSceneExTransitionSlideInT::sceneOrder()
{
    m_bIsInSceneOnTop = false;
}

void CCSceneExTransitionSlideInT::initScenes()
{
    Size s = Director::getInstance()->getWinSize();
    m_pInScene->setPosition( Vec2(0,s.height-ADJUST_FACTOR) );
}


ActionInterval* CCSceneExTransitionSlideInT::action()
{
    Size s = Director::getInstance()->getWinSize();
    return MoveBy::create(m_fDuration, Vec2(0,-(s.height-ADJUST_FACTOR)));
}

//
// SlideInB
//
CCSceneExTransitionSlideInB::CCSceneExTransitionSlideInB()
{
}
CCSceneExTransitionSlideInB::~CCSceneExTransitionSlideInB()
{
}

CCSceneExTransitionSlideInB* CCSceneExTransitionSlideInB::create(float t, CSceneExtension* scene)
{
    CCSceneExTransitionSlideInB* pScene = new CCSceneExTransitionSlideInB();
    if(pScene && pScene->initWithDuration(t, scene))
    {
        pScene->autorelease();
        return pScene;
    }
    CC_SAFE_DELETE(pScene);
    return NULL;
}

void CCSceneExTransitionSlideInB::sceneOrder()
{
    m_bIsInSceneOnTop = true;
}

void CCSceneExTransitionSlideInB:: initScenes()
{
    Size s = Director::getInstance()->getWinSize();
    m_pInScene->setPosition( Vec2(0,-(s.height-ADJUST_FACTOR)) );
}


ActionInterval* CCSceneExTransitionSlideInB:: action()
{
    Size s = Director::getInstance()->getWinSize();
    return MoveBy::create(m_fDuration, Vec2(0,s.height-ADJUST_FACTOR));
}

//
// ShrinkGrow Transition
//
CCSceneExTransitionShrinkGrow::CCSceneExTransitionShrinkGrow()
{
}
CCSceneExTransitionShrinkGrow::~CCSceneExTransitionShrinkGrow()
{
}

CCSceneExTransitionShrinkGrow* CCSceneExTransitionShrinkGrow::create(float t, CSceneExtension* scene)
{
    CCSceneExTransitionShrinkGrow* pScene = new CCSceneExTransitionShrinkGrow();
    if(pScene && pScene->initWithDuration(t, scene))
    {
        pScene->autorelease();
        return pScene;
    }
    CC_SAFE_DELETE(pScene);
    return NULL;
}

void CCSceneExTransitionShrinkGrow::onEnter()
{
    CCSceneExTransition::onEnter();

    m_pInScene->setScale(0.001f);
    m_pOutScene->setScale(1.0f);

    m_pInScene->setAnchorPoint(Vec2(2/3.0f,0.5f));
    m_pOutScene->setAnchorPoint(Vec2(1/3.0f,0.5f));    

    ActionInterval* scaleOut = ScaleTo::create(m_fDuration, 0.01f);
    ActionInterval* scaleIn = ScaleTo::create(m_fDuration, 1.0f);

    m_pInScene->runAction(this->easeActionWithAction(scaleIn));
    m_pOutScene->runAction
    (
        Sequence::create
        (
            this->easeActionWithAction(scaleOut),
             CallFunc::create(CC_CALLBACK_0(CCSceneExTransition::finish,this)), 
            NULL
        )
    );
}
ActionInterval* CCSceneExTransitionShrinkGrow:: easeActionWithAction(ActionInterval* action)
{
    return EaseOut::create(action, 2.0f);
//    return [EaseElasticOut actionWithAction:action period:0.3f];
}

//
// FlipX Transition
//
CCSceneExTransitionFlipX::CCSceneExTransitionFlipX()
{
}
CCSceneExTransitionFlipX::~CCSceneExTransitionFlipX()
{
}

void CCSceneExTransitionFlipX::onEnter()
{
    CCSceneExTransitionOriented::onEnter();

    ActionInterval *inA, *outA;
    m_pInScene->setVisible(false);

    float inDeltaZ, inAngleZ;
    float outDeltaZ, outAngleZ;

    if( m_eOrientation == TransitionScene::Orientation::RIGHT_OVER )
    {
        inDeltaZ = 90;
        inAngleZ = 270;
        outDeltaZ = 90;
        outAngleZ = 0;
    }
    else
    {
        inDeltaZ = -90;
        inAngleZ = 90;
        outDeltaZ = -90;
        outAngleZ = 0;
    }

    inA = (ActionInterval*)Sequence::create
        (
            DelayTime::create(m_fDuration/2),
            CCShow::create(),
            OrbitCamera::create(m_fDuration/2, 1, 0, inAngleZ, inDeltaZ, 0, 0),
             CallFunc::create(CC_CALLBACK_0(CCSceneExTransition::finish,this)), 
            NULL
        );

    outA = (ActionInterval *)Sequence::create
        (
            OrbitCamera::create(m_fDuration/2, 1, 0, outAngleZ, outDeltaZ, 0, 0),
            CCHide::create(),
            DelayTime::create(m_fDuration/2),                            
            NULL 
        );

    m_pInScene->runAction(inA);
    m_pOutScene->runAction(outA);
}

CCSceneExTransitionFlipX* CCSceneExTransitionFlipX::create(float t, CSceneExtension* s, TransitionScene::Orientation o)
{
    CCSceneExTransitionFlipX* pScene = new CCSceneExTransitionFlipX();
    pScene->initWithDuration(t, s, o);
    pScene->autorelease();

    return pScene;
}

CCSceneExTransitionFlipX* CCSceneExTransitionFlipX::create(float t, CSceneExtension* s)
{
    return CCSceneExTransitionFlipX::create(t, s, TransitionScene::Orientation::RIGHT_OVER);
}

//
// FlipY Transition
//
CCSceneExTransitionFlipY::CCSceneExTransitionFlipY()
{
}
CCSceneExTransitionFlipY::~CCSceneExTransitionFlipY()
{
}

void CCSceneExTransitionFlipY::onEnter()
{
    CCSceneExTransitionOriented::onEnter();

    ActionInterval *inA, *outA;
    m_pInScene->setVisible(false);

    float inDeltaZ, inAngleZ;
    float outDeltaZ, outAngleZ;

    if( m_eOrientation == TransitionScene::Orientation::UP_OVER ) 
    {
        inDeltaZ = 90;
        inAngleZ = 270;
        outDeltaZ = 90;
        outAngleZ = 0;
    } 
    else 
    {
        inDeltaZ = -90;
        inAngleZ = 90;
        outDeltaZ = -90;
        outAngleZ = 0;
    }

    inA = (ActionInterval*)Sequence::create
        (
            DelayTime::create(m_fDuration/2),
            CCShow::create(),
            OrbitCamera::create(m_fDuration/2, 1, 0, inAngleZ, inDeltaZ, 90, 0),
             CallFunc::create(CC_CALLBACK_0(CCSceneExTransition::finish,this)), 
            nullptr
        );
    outA = (ActionInterval*)Sequence::create
        (
            OrbitCamera::create(m_fDuration/2, 1, 0, outAngleZ, outDeltaZ, 90, 0),
            CCHide::create(),
            DelayTime::create(m_fDuration/2),                            
            nullptr
        );

    m_pInScene->runAction(inA);
    m_pOutScene->runAction(outA);

}

CCSceneExTransitionFlipY* CCSceneExTransitionFlipY::create(float t, CSceneExtension* s, TransitionScene::Orientation o)
{
    CCSceneExTransitionFlipY* pScene = new CCSceneExTransitionFlipY();
    pScene->initWithDuration(t, s, o);
    pScene->autorelease();

    return pScene;
}

CCSceneExTransitionFlipY* CCSceneExTransitionFlipY::create(float t, CSceneExtension* s)
{
    return CCSceneExTransitionFlipY::create(t, s, TransitionScene::Orientation::UP_OVER);
}

//
// FlipAngular Transition
//
CCSceneExTransitionFlipAngular::CCSceneExTransitionFlipAngular()
{
}

CCSceneExTransitionFlipAngular::~CCSceneExTransitionFlipAngular()
{
}

void CCSceneExTransitionFlipAngular::onEnter()
{
    CCSceneExTransitionOriented::onEnter();

    ActionInterval *inA, *outA;
    m_pInScene->setVisible(false);

    float inDeltaZ, inAngleZ;
    float outDeltaZ, outAngleZ;

    if( m_eOrientation == TransitionScene::Orientation::RIGHT_OVER ) 
    {
        inDeltaZ = 90;
        inAngleZ = 270;
        outDeltaZ = 90;
        outAngleZ = 0;
    } 
    else 
    {
        inDeltaZ = -90;
        inAngleZ = 90;
        outDeltaZ = -90;
        outAngleZ = 0;
    }

    inA = (ActionInterval *)Sequence::create
        (
            DelayTime::create(m_fDuration/2),
            CCShow::create(),
            OrbitCamera::create(m_fDuration/2, 1, 0, inAngleZ, inDeltaZ, -45, 0),
             CallFunc::create(CC_CALLBACK_0(CCSceneExTransition::finish,this)), 
            NULL
        );
    outA = (ActionInterval *)Sequence::create
        (
            OrbitCamera::create(m_fDuration/2, 1, 0, outAngleZ, outDeltaZ, 45, 0),
            CCHide::create(),
            DelayTime::create(m_fDuration/2),                            
            NULL
        );

    m_pInScene->runAction(inA);
    m_pOutScene->runAction(outA);
}

CCSceneExTransitionFlipAngular* CCSceneExTransitionFlipAngular::create(float t, CSceneExtension* s, TransitionScene::Orientation o)
{
    CCSceneExTransitionFlipAngular* pScene = new CCSceneExTransitionFlipAngular();
    pScene->initWithDuration(t, s, o);
    pScene->autorelease();

    return pScene;
}

CCSceneExTransitionFlipAngular* CCSceneExTransitionFlipAngular::create(float t, CSceneExtension* s)
{
    return CCSceneExTransitionFlipAngular::create(t, s, TransitionScene::Orientation::RIGHT_OVER);
}

//
// ZoomFlipX Transition
//
CCSceneExTransitionZoomFlipX::CCSceneExTransitionZoomFlipX()
{
}
CCSceneExTransitionZoomFlipX::~CCSceneExTransitionZoomFlipX()
{
}

void CCSceneExTransitionZoomFlipX::onEnter()
{
    CCSceneExTransitionOriented::onEnter();

    ActionInterval *inA, *outA;
    m_pInScene->setVisible(false);

    float inDeltaZ, inAngleZ;
    float outDeltaZ, outAngleZ;

    if( m_eOrientation == TransitionScene::Orientation::RIGHT_OVER ) {
        inDeltaZ = 90;
        inAngleZ = 270;
        outDeltaZ = 90;
        outAngleZ = 0;
    } 
    else 
    {
        inDeltaZ = -90;
        inAngleZ = 90;
        outDeltaZ = -90;
        outAngleZ = 0;
    }
    inA = (ActionInterval *)Sequence::create
        (
            DelayTime::create(m_fDuration/2),
            Spawn::create
            (
                OrbitCamera::create(m_fDuration/2, 1, 0, inAngleZ, inDeltaZ, 0, 0),
                ScaleTo::create(m_fDuration/2, 1),
                CCShow::create(),
                NULL
            ),
             CallFunc::create(CC_CALLBACK_0(CCSceneExTransition::finish,this)),
            NULL
        );
    outA = (ActionInterval *)Sequence::create
        (
            Spawn::create
            (
                OrbitCamera::create(m_fDuration/2, 1, 0, outAngleZ, outDeltaZ, 0, 0),
                ScaleTo::create(m_fDuration/2, 0.5f),
                NULL
            ),
            CCHide::create(),
            DelayTime::create(m_fDuration/2),                            
            NULL
        );

    m_pInScene->setScale(0.5f);
    m_pInScene->runAction(inA);
    m_pOutScene->runAction(outA);
}

CCSceneExTransitionZoomFlipX* CCSceneExTransitionZoomFlipX::create(float t, CSceneExtension* s, TransitionScene::Orientation o)
{
    CCSceneExTransitionZoomFlipX* pScene = new CCSceneExTransitionZoomFlipX();
    pScene->initWithDuration(t, s, o);
    pScene->autorelease();

    return pScene;
}

CCSceneExTransitionZoomFlipX* CCSceneExTransitionZoomFlipX::create(float t, CSceneExtension* s)
{
    return CCSceneExTransitionZoomFlipX::create(t, s, TransitionScene::Orientation::RIGHT_OVER);
}

//
// ZoomFlipY Transition
//
CCSceneExTransitionZoomFlipY::CCSceneExTransitionZoomFlipY()
{
}

CCSceneExTransitionZoomFlipY::~CCSceneExTransitionZoomFlipY()
{
}

void CCSceneExTransitionZoomFlipY::onEnter()
{
    CCSceneExTransitionOriented::onEnter();

    ActionInterval *inA, *outA;
    m_pInScene->setVisible(false);

    float inDeltaZ, inAngleZ;
    float outDeltaZ, outAngleZ;

    if( m_eOrientation== TransitionScene::Orientation::UP_OVER ) {
        inDeltaZ = 90;
        inAngleZ = 270;
        outDeltaZ = 90;
        outAngleZ = 0;
    } else {
        inDeltaZ = -90;
        inAngleZ = 90;
        outDeltaZ = -90;
        outAngleZ = 0;
    }

    inA = (ActionInterval *)Sequence::create
        (
            DelayTime::create(m_fDuration/2),
            Spawn::create
            (
                OrbitCamera::create(m_fDuration/2, 1, 0, inAngleZ, inDeltaZ, 90, 0),
                ScaleTo::create(m_fDuration/2, 1),
                CCShow::create(),
                NULL
            ),
             CallFunc::create(CC_CALLBACK_0(CCSceneExTransition::finish,this)),
            NULL
        );

    outA = (ActionInterval *)Sequence::create
        (
            Spawn::create
            (
                OrbitCamera::create(m_fDuration/2, 1, 0, outAngleZ, outDeltaZ, 90, 0),
                ScaleTo::create(m_fDuration/2, 0.5f),
                NULL
            ),                            
            CCHide::create(),
            DelayTime::create(m_fDuration/2),
            NULL
        );

    m_pInScene->setScale(0.5f);
    m_pInScene->runAction(inA);
    m_pOutScene->runAction(outA);
}

CCSceneExTransitionZoomFlipY* CCSceneExTransitionZoomFlipY::create(float t, CSceneExtension* s, TransitionScene::Orientation o)
{
    CCSceneExTransitionZoomFlipY* pScene = new CCSceneExTransitionZoomFlipY();
    pScene->initWithDuration(t, s, o);
    pScene->autorelease();

    return pScene;
}

CCSceneExTransitionZoomFlipY* CCSceneExTransitionZoomFlipY::create(float t, CSceneExtension* s)
{
    return CCSceneExTransitionZoomFlipY::create(t, s, TransitionScene::Orientation::UP_OVER);
}

//
// ZoomFlipAngular Transition
//
CCSceneExTransitionZoomFlipAngular::CCSceneExTransitionZoomFlipAngular()
{
}
CCSceneExTransitionZoomFlipAngular::~CCSceneExTransitionZoomFlipAngular()
{
}


void CCSceneExTransitionZoomFlipAngular::onEnter()
{
    CCSceneExTransitionOriented::onEnter();

    ActionInterval *inA, *outA;
    m_pInScene->setVisible(false);

    float inDeltaZ, inAngleZ;
    float outDeltaZ, outAngleZ;

    if( m_eOrientation == TransitionScene::Orientation::RIGHT_OVER ) {
        inDeltaZ = 90;
        inAngleZ = 270;
        outDeltaZ = 90;
        outAngleZ = 0;
    } 
    else 
    {
        inDeltaZ = -90;
        inAngleZ = 90;
        outDeltaZ = -90;
        outAngleZ = 0;
    }

    inA = (ActionInterval *)Sequence::create
        (
            DelayTime::create(m_fDuration/2),
            Spawn::create
            (
                OrbitCamera::create(m_fDuration/2, 1, 0, inAngleZ, inDeltaZ, -45, 0),
                ScaleTo::create(m_fDuration/2, 1),
                CCShow::create(),
                NULL
            ),
            CCShow::create(),
             CallFunc::create(CC_CALLBACK_0(CCSceneExTransition::finish,this)),
            NULL
        );
    outA = (ActionInterval *)Sequence::create
        (
            Spawn::create
            (
                OrbitCamera::create(m_fDuration/2, 1, 0 , outAngleZ, outDeltaZ, 45, 0),
                ScaleTo::create(m_fDuration/2, 0.5f),
                NULL
            ),                            
            CCHide::create(),
            DelayTime::create(m_fDuration/2),                            
            NULL
        );

    m_pInScene->setScale(0.5f);
    m_pInScene->runAction(inA);
    m_pOutScene->runAction(outA);
}

CCSceneExTransitionZoomFlipAngular* CCSceneExTransitionZoomFlipAngular::create(float t, CSceneExtension* s, TransitionScene::Orientation o)
{
    CCSceneExTransitionZoomFlipAngular* pScene = new CCSceneExTransitionZoomFlipAngular();
    pScene->initWithDuration(t, s, o);
    pScene->autorelease();

    return pScene;
}

CCSceneExTransitionZoomFlipAngular* CCSceneExTransitionZoomFlipAngular::create(float t, CSceneExtension* s)
{
    return CCSceneExTransitionZoomFlipAngular::create(t, s, TransitionScene::Orientation::RIGHT_OVER);
}

//
// Fade Transition
//
CCSceneExTransitionFade::CCSceneExTransitionFade()
{
}
CCSceneExTransitionFade::~CCSceneExTransitionFade()
{
}

CCSceneExTransitionFade * CCSceneExTransitionFade::create(float duration, CSceneExtension *scene, const Color3B& color)
{
    CCSceneExTransitionFade * pTransition = new CCSceneExTransitionFade();
    pTransition->initWithDuration(duration, scene, color);
    pTransition->autorelease();
    return pTransition;
}

CCSceneExTransitionFade* CCSceneExTransitionFade::create(float duration,CSceneExtension* scene)
{
    return CCSceneExTransitionFade::create(duration, scene, Color3B::BLACK);
}

bool CCSceneExTransitionFade::initWithDuration(float duration, CSceneExtension *scene, const Color3B& color)
{
    if (CCSceneExTransition::initWithDuration(duration, scene))
    {
        m_tColor.r = color.r;
        m_tColor.g = color.g;
        m_tColor.b = color.b;
        m_tColor.a = 0;
    }
    return true;
}

bool CCSceneExTransitionFade::initWithDuration(float t, CSceneExtension *scene)
{
    this->initWithDuration(t, scene, Color3B::BLACK);
    return true;
}

void CCSceneExTransitionFade :: onEnter()
{
    CCSceneExTransition::onEnter();

    LayerColor* l = LayerColor::create(m_tColor);
    m_pInScene->setVisible(false);

    addChild(l, 2, kSceneFade);
    Node* f = getChildByTag(kSceneFade);

    ActionInterval* a = (ActionInterval *)Sequence::create
        (
            FadeIn::create(m_fDuration/2),
            CallFunc::create(CC_CALLBACK_0(CCSceneExTransition::hideOutShowIn,this)),//CCCallFunc::create:self selector:@selector(hideOutShowIn)],
            FadeOut::create(m_fDuration/2),
             CallFunc::create(CC_CALLBACK_0(CCSceneExTransition::finish,this)), //:self selector:@selector(finish)],
            NULL
        );
    f->runAction(a);
}

void CCSceneExTransitionFade::onExit()
{
    CCSceneExTransition::onExit();
    this->removeChildByTag(kSceneFade, false);
}

//
// Cross Fade Transition
//
CCSceneExTransitionCrossFade::CCSceneExTransitionCrossFade()
{
}
CCSceneExTransitionCrossFade::~CCSceneExTransitionCrossFade()
{
}

CCSceneExTransitionCrossFade* CCSceneExTransitionCrossFade::create(float t, CSceneExtension* scene)
{
    CCSceneExTransitionCrossFade* pScene = new CCSceneExTransitionCrossFade();
    if(pScene && pScene->initWithDuration(t, scene))
    {
        pScene->autorelease();
        return pScene;
    }
    CC_SAFE_DELETE(pScene);
    return NULL;
}

void CCSceneExTransitionCrossFade:: draw(Renderer *renderer, const Mat4& transform, uint32_t flags)
{
    // override draw since both scenes (textures) are rendered in 1 scene
	CCSceneExTransition::draw(renderer, transform, flags);
}

void CCSceneExTransitionCrossFade::onEnter()
{
    CCSceneExTransition::onEnter();

    // create a transparent color layer
    // in which we are going to add our rendertextures
    Color4B  color (0,0,0,0);
    Size size = Director::getInstance()->getWinSize();
    LayerColor* layer = LayerColor::create(color);

    // create the first render texture for inScene
    RenderTexture* inTexture = RenderTexture::create((int)size.width, (int)size.height);

    if (NULL == inTexture)
    {
        return;
    }

    inTexture->getSprite()->setAnchorPoint( Vec2(0.5f,0.5f) );
    inTexture->setPosition( Vec2(size.width/2, size.height/2) );
    inTexture->setAnchorPoint( Vec2(0.5f,0.5f) );

    // render inScene to its texturebuffer
    inTexture->begin();
    ((Node*)m_pInScene)->visit();
    inTexture->end();

    // create the second render texture for outScene
    RenderTexture* outTexture = RenderTexture::create((int)size.width, (int)size.height);
    outTexture->getSprite()->setAnchorPoint( Vec2(0.5f,0.5f) );
    outTexture->setPosition( Vec2(size.width/2, size.height/2) );
    outTexture->setAnchorPoint( Vec2(0.5f,0.5f) );

    // render outScene to its texturebuffer
    outTexture->begin();
    ((Node*)m_pOutScene)->visit();
    outTexture->end();

    // create blend functions

    BlendFunc blend1 = {GL_ONE, GL_ONE}; // inScene will lay on background and will not be used with alpha
    BlendFunc blend2 = {GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA}; // we are going to blend outScene via alpha 

    // set blendfunctions
    inTexture->getSprite()->setBlendFunc(blend1);
    outTexture->getSprite()->setBlendFunc(blend2);    

    // add render textures to the layer
    layer->addChild(inTexture);
    layer->addChild(outTexture);

    // initial opacity:
    inTexture->getSprite()->setOpacity(255);
    outTexture->getSprite()->setOpacity(255);

    // create the blend action
    Action* layerAction = Sequence::create
    (
        FadeTo::create(m_fDuration, 0),
        CallFunc::create(CC_CALLBACK_0(CCSceneExTransition::hideOutShowIn,this)),
         CallFunc::create(CC_CALLBACK_0(CCSceneExTransition::finish,this)),
        NULL
    );


    // run the blend action
    outTexture->getSprite()->runAction( layerAction );

    // add the layer (which contains our two rendertextures) to the scene
    addChild(layer, 2, kSceneFade);
}

// clean up on exit
void CCSceneExTransitionCrossFade::onExit()
{
    // remove our layer and release all containing objects 
    this->removeChildByTag(kSceneFade, false);
    CCSceneExTransition::onExit();
}

//
// TurnOffTilesTransition
//
CCSceneExTransitionTurnOffTiles::CCSceneExTransitionTurnOffTiles()
{
}

CCSceneExTransitionTurnOffTiles::~CCSceneExTransitionTurnOffTiles()
{
}

CCSceneExTransitionTurnOffTiles* CCSceneExTransitionTurnOffTiles::create(float t, CSceneExtension* scene)
{
    CCSceneExTransitionTurnOffTiles* pScene = new CCSceneExTransitionTurnOffTiles();
    if(pScene && pScene->initWithDuration(t, scene))
    {
        pScene->autorelease();
        return pScene;
    }
    CC_SAFE_DELETE(pScene);
    return NULL;
}

// override addScenes, and change the order
void CCSceneExTransitionTurnOffTiles::sceneOrder()
{
    m_bIsInSceneOnTop = false;
}

void CCSceneExTransitionTurnOffTiles::onEnter()
{
    CCSceneExTransition::onEnter();
	_outSceneProxy->setTarget(m_pOutScene);
	_outSceneProxy->onEnter();

    Size s = Director::getInstance()->getWinSize();
    float aspect = s.width / s.height;
    int x = (int)(12 * aspect);
    int y = 12;

    TurnOffTiles* toff = TurnOffTiles::create(m_fDuration, Size(x,y));
    ActionInterval* action = easeActionWithAction(toff);
    m_pOutScene->runAction
    (
        Sequence::create
        (
            action,
            CallFunc::create(CC_CALLBACK_0(CCSceneExTransition::finish,this)),
            StopGrid::create(),
            NULL
        )
    );
}



void CCSceneExTransitionTurnOffTiles::onExit()
{
	_outSceneProxy->setTarget(nullptr);
	_outSceneProxy->onExit();
	CCSceneExTransition::onExit();
}

void CCSceneExTransitionTurnOffTiles::draw(Renderer *renderer, const Mat4& transform, uint32_t flags)
{
	CCSceneExTransition::draw(renderer, transform, flags);

	if( m_bIsInSceneOnTop )
	{
		_outSceneProxy->visit(renderer, transform, flags);
		m_pInScene->visit(renderer, transform, flags);
	} 
	else
	{
		m_pInScene->visit(renderer, transform, flags);
		_outSceneProxy->visit(renderer, transform, flags);
	}
}

ActionInterval* CCSceneExTransitionTurnOffTiles:: easeActionWithAction(ActionInterval* action)
{
    return action;
}

//
// SplitCols Transition
//
CCSceneExTransitionSplitCols::CCSceneExTransitionSplitCols()
{
}
CCSceneExTransitionSplitCols::~CCSceneExTransitionSplitCols()
{
}

CCSceneExTransitionSplitCols* CCSceneExTransitionSplitCols::create(float t, CSceneExtension* scene)
{
    CCSceneExTransitionSplitCols* pScene = new CCSceneExTransitionSplitCols();
    if(pScene && pScene->initWithDuration(t, scene))
    {
        pScene->autorelease();
        return pScene;
    }
    CC_SAFE_DELETE(pScene);
    return NULL;
}

void CCSceneExTransitionSplitCols::onEnter()
{
    CCSceneExTransition::onEnter();
    m_pInScene->setVisible(false);

    ActionInterval* split = action();
    ActionInterval* seq = (ActionInterval*)Sequence::create
    (
        split,
        CallFunc::create(CC_CALLBACK_0(CCSceneExTransition::hideOutShowIn,this)),
        split->reverse(),
        NULL
    );

    this->runAction
    ( 
        Sequence::create
        (
            easeActionWithAction(seq),
             CallFunc::create(CC_CALLBACK_0(CCSceneExTransition::finish,this)),
            StopGrid::create(),
            NULL
        )
    );
}

ActionInterval* CCSceneExTransitionSplitCols:: action()
{
    return CCSplitCols::create(m_fDuration/2.0f, 3);
}


ActionInterval* CCSceneExTransitionSplitCols::easeActionWithAction(ActionInterval * action)
{
    return EaseInOut::create(action, 3.0f);
}


//
// SplitRows Transition
//
CCSceneExTransitionSplitRows::CCSceneExTransitionSplitRows()
{
}

CCSceneExTransitionSplitRows::~CCSceneExTransitionSplitRows()
{
}

ActionInterval* CCSceneExTransitionSplitRows::action()
{
    return CCSplitRows::create(m_fDuration/2.0f, 3);
}

CCSceneExTransitionSplitRows* CCSceneExTransitionSplitRows::create(float t, CSceneExtension* scene)
{
    CCSceneExTransitionSplitRows* pScene = new CCSceneExTransitionSplitRows();
    if(pScene && pScene->initWithDuration(t, scene))
    {
        pScene->autorelease();
        return pScene;
    }
    CC_SAFE_DELETE(pScene);
    return NULL;
}

//
// FadeTR Transition
//
CCSceneExTransitionFadeTR::CCSceneExTransitionFadeTR()
{
}
CCSceneExTransitionFadeTR::~CCSceneExTransitionFadeTR()
{
}

CCSceneExTransitionFadeTR* CCSceneExTransitionFadeTR::create(float t, CSceneExtension* scene)
{
    CCSceneExTransitionFadeTR* pScene = new CCSceneExTransitionFadeTR();
    if(pScene && pScene->initWithDuration(t, scene))
    {
        pScene->autorelease();
        return pScene;
    }
    CC_SAFE_DELETE(pScene);
    return NULL;
}

void CCSceneExTransitionFadeTR::sceneOrder()
{
    m_bIsInSceneOnTop = false;
}

void CCSceneExTransitionFadeTR::onEnter()
{
    CCSceneExTransition::onEnter();

    Size s = Director::getInstance()->getWinSize();
    float aspect = s.width / s.height;
    int x = (int)(12 * aspect);
    int y = 12;

    ActionInterval* action  = actionWithSize(Size(x,y));

    m_pOutScene->runAction
    (
        Sequence::create
        (
            easeActionWithAction(action),
             CallFunc::create(CC_CALLBACK_0(CCSceneExTransition::finish,this)), 
            StopGrid::create(),
            NULL
        )
    );
}


ActionInterval*  CCSceneExTransitionFadeTR::actionWithSize(const Size& size)
{
    return CCFadeOutTRTiles::create(m_fDuration, size);
}

ActionInterval* CCSceneExTransitionFadeTR:: easeActionWithAction(ActionInterval* action)
{
    return action;
}


//
// FadeBL Transition
//

CCSceneExTransitionFadeBL::CCSceneExTransitionFadeBL()
{
}
CCSceneExTransitionFadeBL::~CCSceneExTransitionFadeBL()
{
}

CCSceneExTransitionFadeBL* CCSceneExTransitionFadeBL::create(float t, CSceneExtension* scene)
{
    CCSceneExTransitionFadeBL* pScene = new CCSceneExTransitionFadeBL();
    if(pScene && pScene->initWithDuration(t, scene))
    {
        pScene->autorelease();
        return pScene;
    }
    CC_SAFE_DELETE(pScene);
    return NULL;
}

ActionInterval*  CCSceneExTransitionFadeBL::actionWithSize(const Size& size)
{
    return CCFadeOutBLTiles::create(m_fDuration, size);
}

//
// FadeUp Transition
//
CCSceneExTransitionFadeUp::CCSceneExTransitionFadeUp()
{
}

CCSceneExTransitionFadeUp::~CCSceneExTransitionFadeUp()
{
}

CCSceneExTransitionFadeUp* CCSceneExTransitionFadeUp::create(float t, CSceneExtension* scene)
{
    CCSceneExTransitionFadeUp* pScene = new CCSceneExTransitionFadeUp();
    if(pScene && pScene->initWithDuration(t, scene))
    {
        pScene->autorelease();
        return pScene;
    }
    CC_SAFE_DELETE(pScene);
    return NULL;
}

ActionInterval* CCSceneExTransitionFadeUp::actionWithSize(const Size& size)
{
    return CCFadeOutUpTiles::create(m_fDuration, size);
}

//
// FadeDown Transition
//
CCSceneExTransitionFadeDown::CCSceneExTransitionFadeDown()
{
}
CCSceneExTransitionFadeDown::~CCSceneExTransitionFadeDown()
{
}

CCSceneExTransitionFadeDown* CCSceneExTransitionFadeDown::create(float t, CSceneExtension* scene)
{
    CCSceneExTransitionFadeDown* pScene = new CCSceneExTransitionFadeDown();
    if(pScene && pScene->initWithDuration(t, scene))
    {
        pScene->autorelease();
        return pScene;
    }
    CC_SAFE_DELETE(pScene);
    return NULL;
}

ActionInterval* CCSceneExTransitionFadeDown::actionWithSize(const Size& size)
{
    return CCFadeOutDownTiles::create(m_fDuration, size);
}


CCSceneExTransitionPageTurn::CCSceneExTransitionPageTurn()
{
}

CCSceneExTransitionPageTurn::~CCSceneExTransitionPageTurn()
{
}

/** creates a base transition with duration and incoming scene */
CCSceneExTransitionPageTurn * CCSceneExTransitionPageTurn::create(float t, CSceneExtension *scene, bool backwards)
{
    CCSceneExTransitionPageTurn * pTransition = new CCSceneExTransitionPageTurn();
    pTransition->initWithDuration(t,scene,backwards);
    pTransition->autorelease();
    return pTransition;
}

/** initializes a transition with duration and incoming scene */
bool CCSceneExTransitionPageTurn::initWithDuration(float t, CSceneExtension *scene, bool backwards)
{
    // XXX: needed before [super init]
    m_bBack = backwards;

    if (CCSceneExTransition::initWithDuration(t, scene))
    {
        // do something
    }
    return true;
}

void CCSceneExTransitionPageTurn::sceneOrder()
{
    m_bIsInSceneOnTop = m_bBack;
}

void CCSceneExTransitionPageTurn::onEnter()
{
    CCSceneExTransition::onEnter();
    Size s = Director::getInstance()->getWinSize();
    int x,y;
    if (s.width > s.height)
    {
        x=16;
        y=12;
    }
    else
    {
        x=12;
        y=16;
    }

    ActionInterval *action  = this->actionWithSize(Size(x,y));

    if (! m_bBack )
    {
        m_pOutScene->runAction
        (
            Sequence::create
            (
                action,
                 CallFunc::create(CC_CALLBACK_0(CCSceneExTransition::finish,this)),
                StopGrid::create(),
                NULL
            )
        );
    }
    else
    {
        // to prevent initial flicker
        m_pInScene->setVisible(false);
        m_pInScene->runAction
        (
            Sequence::create
            (
                CCShow::create(),
                action,
                 CallFunc::create(CC_CALLBACK_0(CCSceneExTransition::finish,this)),
                StopGrid::create(),
                NULL
            )
        );
    }
}

ActionInterval* CCSceneExTransitionPageTurn:: actionWithSize(const Size& vector)
{
    if (m_bBack)
    {
        // Get hold of the PageTurn3DAction
        return ReverseTime::create
        (
            CCPageTurn3D::create(m_fDuration, vector)
        );
    }
    else
    {
        // Get hold of the PageTurn3DAction
        return CCPageTurn3D::create(m_fDuration, vector);
    }
}

enum {
    kCCSceneRadial = 0xc001,
};

CCSceneExTransitionProgress::CCSceneExTransitionProgress()
: m_fTo(0.0f)
, m_fFrom(0.0f)
, m_pSceneToBeModified(NULL)
{

}

CCSceneExTransitionProgress* CCSceneExTransitionProgress::create(float t, CSceneExtension* scene)
{
    CCSceneExTransitionProgress* pScene = new CCSceneExTransitionProgress();
    if(pScene && pScene->initWithDuration(t, scene))
    {
        pScene->autorelease();
        return pScene;
    }
    CC_SAFE_DELETE(pScene);
    return NULL;
}

// CCTransitionProgress
void CCSceneExTransitionProgress::onEnter()
{
    CCSceneExTransition::onEnter();

    setupTransition();
    
    // create a transparent color layer
    // in which we are going to add our rendertextures
    Size size = Director::getInstance()->getWinSize();

    // create the second render texture for outScene
    RenderTexture *texture = RenderTexture::create((int)size.width, (int)size.height);
    texture->getSprite()->setAnchorPoint(Vec2(0.5f,0.5f));
    texture->setPosition(Vec2(size.width/2, size.height/2));
    texture->setAnchorPoint(Vec2(0.5f,0.5f));

    // render outScene to its texturebuffer
    texture->clear(0, 0, 0, 1);
    texture->begin();
   ((Node*) m_pSceneToBeModified)->visit();
    texture->end();


    //    Since we've passed the outScene to the texture we don't need it.
    if (m_pSceneToBeModified == m_pOutScene)
    {
        hideOutShowIn();
    }
    //    We need the texture in RenderTexture.
    ProgressTimer *pNode = progressTimerNodeWithRenderTexture(texture);

    // create the blend action
    ActionInterval* layerAction = (ActionInterval*)Sequence::create(
        CCProgressFromTo::create(m_fDuration, m_fFrom, m_fTo),
        CallFunc::create(CC_CALLBACK_0(CCSceneExTransitionProgress::finish,this)), 
        NULL);
    // run the blend action
    pNode->runAction(layerAction);

    // add the layer (which contains our two rendertextures) to the scene
    addChild(pNode, 2, kCCSceneRadial);
}

// clean up on exit
void CCSceneExTransitionProgress::onExit()
{
    // remove our layer and release all containing objects
    removeChildByTag(kCCSceneRadial, true);
    CCSceneExTransition::onExit();
}

void CCSceneExTransitionProgress::sceneOrder()
{
    m_bIsInSceneOnTop = false;
}

void CCSceneExTransitionProgress::setupTransition()
{
    m_pSceneToBeModified = m_pOutScene;
    m_fFrom = 100;
    m_fTo = 0;
}

ProgressTimer* CCSceneExTransitionProgress::progressTimerNodeWithRenderTexture(RenderTexture* texture)
{
    CCAssert(false, "override me - abstract class");
    return NULL;
}


// CCTransitionProgressRadialCCW

ProgressTimer* CCSceneExTransitionProgressRadialCCW::progressTimerNodeWithRenderTexture(RenderTexture* texture)
{
    Size size = Director::getInstance()->getWinSize();

    ProgressTimer* pNode = ProgressTimer::create(texture->getSprite());

    // but it is flipped upside down so we flip the sprite
    pNode->getSprite()->setFlippedY(true);
    pNode->setType(ProgressTimer::Type::RADIAL);

    //    Return the radial type that we want to use
    pNode->setReverseDirection(false);
    pNode->setPercentage(100);
    pNode->setPosition(Vec2(size.width/2, size.height/2));
    pNode->setAnchorPoint(Vec2(0.5f,0.5f));
    
    return pNode;
}

CCSceneExTransitionProgressRadialCCW* CCSceneExTransitionProgressRadialCCW::create(float t, CSceneExtension* scene)
{
    CCSceneExTransitionProgressRadialCCW* pScene = new CCSceneExTransitionProgressRadialCCW();
    if(pScene && pScene->initWithDuration(t, scene))
    {
        pScene->autorelease();
        return pScene;
    }
    CC_SAFE_DELETE(pScene);
    return NULL;
}

// CCTransitionProgressRadialCW
CCSceneExTransitionProgressRadialCW* CCSceneExTransitionProgressRadialCW::create(float t, CSceneExtension* scene)
{
    CCSceneExTransitionProgressRadialCW* pScene = new CCSceneExTransitionProgressRadialCW();
    if(pScene && pScene->initWithDuration(t, scene))
    {
        pScene->autorelease();
        return pScene;
    }
    CC_SAFE_DELETE(pScene);
    return NULL;
}

ProgressTimer* CCSceneExTransitionProgressRadialCW::progressTimerNodeWithRenderTexture(RenderTexture* texture)
{
    Size size = Director::getInstance()->getWinSize();
    
    ProgressTimer* pNode = ProgressTimer::create(texture->getSprite());
    
    // but it is flipped upside down so we flip the sprite
    pNode->getSprite()->setFlippedY(true);
    pNode->setType( ProgressTimer::Type::RADIAL );
    
    //    Return the radial type that we want to use
    pNode->setReverseDirection(true);
    pNode->setPercentage(100);
    pNode->setPosition(Vec2(size.width/2, size.height/2));
    pNode->setAnchorPoint(Vec2(0.5f,0.5f));
    
    return pNode;
}

// CCTransitionProgressHorizontal
CCSceneExTransitionProgressHorizontal* CCSceneExTransitionProgressHorizontal::create(float t, CSceneExtension* scene)
{
    CCSceneExTransitionProgressHorizontal* pScene = new CCSceneExTransitionProgressHorizontal();
    if(pScene && pScene->initWithDuration(t, scene))
    {
        pScene->autorelease();
        return pScene;
    }
    CC_SAFE_DELETE(pScene);
    return NULL;
}

ProgressTimer* CCSceneExTransitionProgressHorizontal::progressTimerNodeWithRenderTexture(RenderTexture* texture)
{    
    Size size = Director::getInstance()->getWinSize();

    ProgressTimer* pNode = ProgressTimer::create(texture->getSprite());
    
    // but it is flipped upside down so we flip the sprite
    pNode->getSprite()->setFlippedY(true);
    pNode->setType( ProgressTimer::Type::BAR);
    
    pNode->setMidpoint(Vec2(1, 0));
    pNode->setBarChangeRate(Vec2(1,0));
    
    pNode->setPercentage(100);
    pNode->setPosition(Vec2(size.width/2, size.height/2));
    pNode->setAnchorPoint(Vec2(0.5f,0.5f));

    return pNode;
}

// CCTransitionProgressVertical
CCSceneExTransitionProgressVertical* CCSceneExTransitionProgressVertical::create(float t, CSceneExtension* scene)
{
    CCSceneExTransitionProgressVertical* pScene = new CCSceneExTransitionProgressVertical();
    if(pScene && pScene->initWithDuration(t, scene))
    {
        pScene->autorelease();
        return pScene;
    }
    CC_SAFE_DELETE(pScene);
    return NULL;
}

ProgressTimer* CCSceneExTransitionProgressVertical::progressTimerNodeWithRenderTexture(RenderTexture* texture)
{    
    Size size = Director::getInstance()->getWinSize();
    
    ProgressTimer* pNode = ProgressTimer::create(texture->getSprite());
    
    // but it is flipped upside down so we flip the sprite
    pNode->getSprite()->setFlippedY(true);
    pNode->setType(ProgressTimer::Type::BAR);
    
    pNode->setMidpoint(Vec2(0, 0));
    pNode->setBarChangeRate(Vec2(0,1));
    
    pNode->setPercentage(100);
    pNode->setPosition(Vec2(size.width/2, size.height/2));
    pNode->setAnchorPoint(Vec2(0.5f,0.5f));
    
    return pNode;
}


// CCTransitionProgressInOut
CCSceneExTransitionProgressInOut* CCSceneExTransitionProgressInOut::create(float t, CSceneExtension* scene)
{
    CCSceneExTransitionProgressInOut* pScene = new CCSceneExTransitionProgressInOut();
    if(pScene && pScene->initWithDuration(t, scene))
    {
        pScene->autorelease();
        return pScene;
    }
    CC_SAFE_DELETE(pScene);
    return NULL;
}

void CCSceneExTransitionProgressInOut::sceneOrder()
{
    m_bIsInSceneOnTop = false;
}

void CCSceneExTransitionProgressInOut::setupTransition()
{
    m_pSceneToBeModified = m_pInScene;
    m_fFrom = 0;
    m_fTo = 100;    
}

ProgressTimer* CCSceneExTransitionProgressInOut::progressTimerNodeWithRenderTexture(RenderTexture* texture)
{    
    Size size = Director::getInstance()->getWinSize();
    
    ProgressTimer* pNode = ProgressTimer::create(texture->getSprite());
    
    // but it is flipped upside down so we flip the sprite
    pNode->getSprite()->setFlippedY(true);
    pNode->setType( ProgressTimer::Type::BAR);
    
    pNode->setMidpoint(Vec2(0.5f, 0.5f));
    pNode->setBarChangeRate(Vec2(1, 1));
    
    pNode->setPercentage(0);
    pNode->setPosition(Vec2(size.width/2, size.height/2));
    pNode->setAnchorPoint(Vec2(0.5f,0.5f));
    
    return pNode;
}


// CCTransitionProgressOutIn
CCSceneExTransitionProgressOutIn* CCSceneExTransitionProgressOutIn::create(float t, CSceneExtension* scene)
{
    CCSceneExTransitionProgressOutIn* pScene = new CCSceneExTransitionProgressOutIn();
    if(pScene && pScene->initWithDuration(t, scene))
    {
        pScene->autorelease();
        return pScene;
    }
    CC_SAFE_DELETE(pScene);
    return NULL;
}

ProgressTimer* CCSceneExTransitionProgressOutIn::progressTimerNodeWithRenderTexture(RenderTexture* texture)
{    
    Size size = Director::getInstance()->getWinSize();
    
    ProgressTimer* pNode = ProgressTimer::create(texture->getSprite());
    
    // but it is flipped upside down so we flip the sprite
    pNode->getSprite()->setFlippedY(true);
    pNode->setType( ProgressTimer::Type::BAR );
    
    pNode->setMidpoint(Vec2(0.5f, 0.5f));
    pNode->setBarChangeRate(Vec2(1, 1));
    
    pNode->setPercentage(100);
    pNode->setPosition(Vec2(size.width/2, size.height/2));
    pNode->setAnchorPoint(Vec2(0.5f,0.5f));
    
    return pNode;
}

NS_CC_END
