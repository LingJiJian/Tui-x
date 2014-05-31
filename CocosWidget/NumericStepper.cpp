#include "NumericStepper.h"

NS_CC_WIDGET_BEGIN

NumericStepper::NumericStepper()
:m_value(15)
,m_step(1)
{
	setThisObject(this);
	setCascadeOpacityEnabled(true);
	setAnchorPoint(CCWIDGET_BASIC_DEFAULT_ANCHOR_POINT);
}

NumericStepper *NumericStepper::create(const char *lnormal,const char *lselet,const char *ldisable, 
									   const char *rnormal,const char *rselet,const char *rdisable,const char* bg)
{
	 NumericStepper *numericStepper = new NumericStepper();
	if (numericStepper && numericStepper->init(lnormal,lselet,ldisable,rnormal,rselet,rdisable,bg))
	{
		numericStepper->autorelease();
		return numericStepper;
	}
	CC_SAFE_DELETE(numericStepper);
	return NULL;
}

NumericStepper* NumericStepper::create()
{
	NumericStepper* pRet = new NumericStepper();
	if( pRet && pRet->init() )
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

bool NumericStepper::init(){
	
	m_btnLeft = CButton::create();
	m_btnRight = CButton::create();
	m_bg = CImageView::create();
	m_labNum = CLabel::createWithSystemFont("15","",m_bg->getContentSize().height-2,m_bg->getContentSize(),TextHAlignment::CENTER);

	m_btnLeft->setOnClickListener(this,ccw_click_selector(NumericStepper::event_btn_left));
	m_btnRight->setOnClickListener(this,ccw_click_selector(NumericStepper::event_btn_right));

	this->addChild(m_btnLeft);
	this->addChild(m_btnRight);
	this->addChild(m_bg);
	this->addChild(m_labNum);
	return true;
}

bool NumericStepper::init(const char *lnormal,const char *lselet,const char *ldisable, 
						  const char *rnormal,const char *rselet,const char *rdisable,const char* bg){

	m_btnLeft = CButton::create(lnormal,lselet,ldisable);
	m_btnRight = CButton::create(rnormal,rselet,rdisable);
	m_bg = CImageView::create(bg);
	m_labNum = CLabel::createWithSystemFont("15","",m_bg->getContentSize().height-2,m_bg->getContentSize(),TextHAlignment::CENTER);

	m_btnLeft->setOnClickListener(this,ccw_click_selector(NumericStepper::event_btn_left));
	m_btnRight->setOnClickListener(this,ccw_click_selector(NumericStepper::event_btn_right));

	this->addChild(m_btnLeft);
	this->addChild(m_btnRight);
	this->addChild(m_bg);
	this->addChild(m_labNum);
	resetSelf();
	return true;
}


void NumericStepper::setlNormalSpriteFrameName( const char* pSpriteName ){
	m_btnLeft->setNormalSpriteFrameName(pSpriteName);
	resetSelf();
}

void NumericStepper::setlSelectedSpriteFrameName( const char* pSpriteName ){
	m_btnLeft->setSelectedSpriteFrameName(pSpriteName);
	resetSelf();
}

void NumericStepper::setlDisabledSpriteFrameName(const char* pSpriteName){
	m_btnLeft->setDisabledSpriteFrameName(pSpriteName);
	resetSelf();
}

void NumericStepper::setrNormalSpriteFrameName(const char* pSpriteName){
	m_btnRight->setNormalSpriteFrameName(pSpriteName);
	resetSelf();
}

void NumericStepper::setrSelectedSpriteFrameName(const char* pSpriteName){
	m_btnRight->setSelectedSpriteFrameName(pSpriteName);
	resetSelf();
}

void NumericStepper::setrDisabledSpriteFrameName(const char* pSpriteName){
	m_btnRight->setDisabledSpriteFrameName(pSpriteName);
	resetSelf();
}

void NumericStepper::setStepBgSpriteFrameName(const char* pSpriteName){
	SpriteFrame *pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(pSpriteName);
	m_bg->setSpriteFrame(pFrame);
	resetSelf();
}

CWidgetTouchModel NumericStepper::onTouchBegan(Touch* pTouch){

	Point touchPointInView = this->convertToNodeSpace(pTouch->getLocation());
	if(m_btnLeft->getBoundingBox().containsPoint(touchPointInView)){
		m_btnLeft->onTouchBegan(pTouch);
	}else if(m_btnRight->getBoundingBox().containsPoint(touchPointInView)){
		m_btnRight->onTouchBegan(pTouch);
	}
	return eWidgetTouchTransient;
}

void NumericStepper::onTouchEnded(Touch* pTouch, float fDuration){

	Point touchPointInView = this->convertToNodeSpace(pTouch->getLocation());
	if(m_btnLeft->getBoundingBox().containsPoint(touchPointInView)){
		m_btnLeft->onTouchEnded(pTouch,fDuration);
	}else if(m_btnRight->getBoundingBox().containsPoint(touchPointInView)){
		m_btnRight->onTouchEnded(pTouch,fDuration);
	}
}

void NumericStepper::onTouchMoved(Touch* pTouch, float fDuration){

	Point touchPointInView = this->convertToNodeSpace(pTouch->getLocation());
	m_btnLeft->onTouchMoved(pTouch,fDuration);
	m_btnRight->onTouchMoved(pTouch,fDuration);
}

void NumericStepper::onTouchCancelled(Touch* pTouch, float fDuration){

	Point touchPointInView = this->convertToNodeSpace(pTouch->getLocation());
	m_btnLeft->onTouchCancelled(pTouch,fDuration);
	m_btnRight->onTouchCancelled(pTouch,fDuration);
}

void NumericStepper::event_btn_left(Ref* s){
	setValue(m_value - m_step);
}

void NumericStepper::event_btn_right(Ref* s){
	setValue(m_value + m_step);
}

void NumericStepper::resetSelf(){
	CLayout::setContentSize(Size(m_btnLeft->getContentSize().width+m_bg->getContentSize().width+m_btnRight->getContentSize().width,
		m_bg->getContentSize().height));
	
	m_btnLeft->setPosition(m_btnLeft->getContentSize().width/2,m_btnLeft->getContentSize().height/2);
	m_bg->setPosition(Point(m_btnLeft->getPositionX()+m_btnLeft->getContentSize().width/2+m_bg->getContentSize().width/2,
		m_btnLeft->getPositionY()));
	m_labNum->setPosition(m_bg->getPosition());
	m_btnRight->setPosition((m_bg->getPositionX()+m_bg->getContentSize().width/2+m_btnRight->getContentSize().width/2),m_btnLeft->getPositionY());
	
}
/************************************************************************/
//	GET/SET/IS
/************************************************************************/
void NumericStepper::setValue(int v){
	if(v == m_value) return;
	m_value = v;
	char buf[128]={0};
	sprintf(buf,"%d",m_value);
	m_labNum->setString(buf);
	executeValueChangedHandler(this,m_value);
}

int NumericStepper::getValue(){
	return m_value;
}

void NumericStepper::setStep(int v){
	if(v == m_step) return;
	m_step = v;
}

int NumericStepper::getStep(){
	return m_step;
}

NS_CC_WIDGET_END