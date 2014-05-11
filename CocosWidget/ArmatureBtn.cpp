#include "ArmatureBtn.h"

NS_CC_WIDGET_BEGIN

ArmatureBtn::ArmatureBtn()
{
	setThisObject(this);
	setCascadeOpacityEnabled(true);
}

ArmatureBtn *ArmatureBtn::create(const char *name)
{
	ArmatureBtn *pArmatureBtn = new ArmatureBtn();
	if (pArmatureBtn && pArmatureBtn->init(name))
	{
		pArmatureBtn->autorelease();
		pArmatureBtn->getAnimation()->play("normal",0,1);
		return pArmatureBtn;
	}
	CC_SAFE_DELETE(pArmatureBtn);
	return NULL;
}

CWidgetTouchModel ArmatureBtn::onTouchBegan(Touch *pTouch)
{
	this->getAnimation()->play("select");
	return eWidgetTouchTransient;
}

void ArmatureBtn::onTouchEnded(Touch *pTouch, float fDuration)
{
	Point touchPointInView = _parent->convertToNodeSpace(pTouch->getLocation());
	if( getBoundingBox().containsPoint(touchPointInView) )
	{
		executeClickHandler(this);
	}
	this->getAnimation()->play("normal",0,1);
}


NS_CC_WIDGET_END