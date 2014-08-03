#include "NumericStepper.h"

NS_CC_WIDGET_BEGIN

NumericStepper::NumericStepper()
:m_value(15)
, m_step(1)
, m_max(INT_MAX)
, m_min(INT_MIN)
, m_curBtnPress(nullptr)
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


bool NumericStepper::initSpriteFrameName(const char *lnormal, const char *lselet, const char *ldisable, const char *rnormal, const char *rselet, const char *rdisable, const char* bg)
{
	SpriteFrame *pTmpLeft = SpriteFrameCache::getInstance()->getSpriteFrameByName(lnormal);
	m_btnLeft = CButton::createWith9Sprite(pTmpLeft->getOriginalSize(), lnormal, lselet, ldisable);
	SpriteFrame *pTmpRight = SpriteFrameCache::getInstance()->getSpriteFrameByName(rnormal);
	m_btnRight = CButton::createWith9Sprite(pTmpRight->getOriginalSize(), rnormal, rselet, rdisable);
	m_bg = CImageView::createWithSpriteFrameName(bg);
	m_labNum = CLabel::createWithSystemFont("15", "", m_bg->getContentSize().height - 2, m_bg->getContentSize(), TextHAlignment::CENTER);
	
	m_btnLeft->setOnClickListener(this, ccw_click_selector(NumericStepper::event_btn_left));
	m_btnRight->setOnClickListener(this, ccw_click_selector(NumericStepper::event_btn_right));

	this->addChild(m_btnLeft);
	this->addChild(m_btnRight);
	this->addChild(m_bg);
	this->addChild(m_labNum);
	resetSelf();
	return true;
}

NumericStepper * NumericStepper::createSpriteFrameName(const char *lnormal, const char *lselet, const char *ldisable, const char *rnormal, const char *rselet, const char *rdisable, const char* bg)
{
	NumericStepper *numericStepper = new NumericStepper();
	if (numericStepper && numericStepper->initSpriteFrameName(lnormal, lselet, ldisable, rnormal, rselet, rdisable, bg))
	{
		numericStepper->autorelease();
		return numericStepper;
	}
	CC_SAFE_DELETE(numericStepper);
	return NULL;
}

CWidgetTouchModel NumericStepper::onTouchBegan(Touch* pTouch){

	CC_WIDGET_LONGCLICK_ONTOUCHBEGAN;

	Vec2 touchPointInView = this->convertToNodeSpace(pTouch->getLocation());
	if(m_btnLeft->getBoundingBox().containsPoint(touchPointInView)){
		m_curBtnPress = m_btnLeft;
		m_btnLeft->onTouchBegan(pTouch);
	}else if(m_btnRight->getBoundingBox().containsPoint(touchPointInView)){
		m_curBtnPress = m_btnRight;
		m_btnRight->onTouchBegan(pTouch);
	}
	return eWidgetTouchTransient;
}

void NumericStepper::onTouchEnded(Touch* pTouch, float fDuration){

	CC_WIDGET_LONGCLICK_ONTOUCHENDED;

	Vec2 touchPointInView = this->convertToNodeSpace(pTouch->getLocation());
	if(m_btnLeft->getBoundingBox().containsPoint(touchPointInView)){
		m_btnLeft->onTouchEnded(pTouch,fDuration);
	}else if(m_btnRight->getBoundingBox().containsPoint(touchPointInView)){
		m_btnRight->onTouchEnded(pTouch,fDuration);
	}
	this->unSchedule();
}

void NumericStepper::onTouchMoved(Touch* pTouch, float fDuration){

	CC_WIDGET_LONGCLICK_ONTOUCHMOVED;

	Vec2 touchPointInView = this->convertToNodeSpace(pTouch->getLocation());
	m_btnLeft->onTouchMoved(pTouch,fDuration);
	m_btnRight->onTouchMoved(pTouch,fDuration);
}

void NumericStepper::onTouchCancelled(Touch* pTouch, float fDuration){

	CC_WIDGET_LONGCLICK_ONTOUCHCANCELLED;

	Vec2 touchPointInView = this->convertToNodeSpace(pTouch->getLocation());
	m_btnLeft->onTouchCancelled(pTouch,fDuration);
	m_btnRight->onTouchCancelled(pTouch,fDuration);

	this->unSchedule();
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
	m_bg->setPosition(Vec2(m_btnLeft->getPositionX()+m_btnLeft->getContentSize().width/2+m_bg->getContentSize().width/2,
		m_btnLeft->getPositionY()));
	m_labNum->setPosition(m_bg->getPosition());
	m_btnRight->setPosition((m_bg->getPositionX()+m_bg->getContentSize().width/2+m_btnRight->getContentSize().width/2),m_btnLeft->getPositionY());
	
}

bool NumericStepper::event_btn_longclick(Ref* pSender, Touch* pTouch)
{
	this->unSchedule();
	Director::getInstance()->getScheduler()->schedule(schedule_selector(NumericStepper::onSchedule), this, 0.1f, false);
	return false;
}

void NumericStepper::unSchedule(){
	this->unschedule(schedule_selector(NumericStepper::onSchedule));
}

void NumericStepper::onSchedule(float dt)
{
	if (m_curBtnPress == m_btnLeft){
		setValue(m_value - m_step);
	}else if (m_curBtnPress == m_btnRight){
		setValue(m_value + m_step);
	}
}

/************************************************************************/
//	GET/SET/IS
/************************************************************************/
void NumericStepper::setValue(int v){
	if (v == m_value || v < m_min || v > m_max) return;
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

void NumericStepper::setLimit(int min, int max)
{
	m_min = min;
	m_max = max;
}

void NumericStepper::setAutoRun(bool b)
{
	if (!b || !m_btnLeft || !m_btnRight) return;
	this->setOnLongClickListener(this, ccw_longclick_selector(NumericStepper::event_btn_longclick));
}

NS_CC_WIDGET_END