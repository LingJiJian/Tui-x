#include "ArmatureBtn.h"

NS_CC_WIDGET_BEGIN

ArmatureBtn::ArmatureBtn()
:m_normalName("normal"),
m_selectName("select")
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
		return pArmatureBtn;
	}
	CC_SAFE_DELETE(pArmatureBtn);
	return NULL;
}

void ArmatureBtn::setNormalAnimName(const std::string& name)
{
	m_normalName = name;
	getAnimation()->play(m_normalName, 0, 1);
}

CWidgetTouchModel ArmatureBtn::onTouchBegan(Touch *pTouch)
{
	this->getAnimation()->play(m_selectName);
	return eWidgetTouchTransient;
}

void ArmatureBtn::onTouchEnded(Touch *pTouch, float fDuration)
{
	Vec2 touchPointInView = _parent->convertToNodeSpace(pTouch->getLocation());
	if( getBoundingBox().containsPoint(touchPointInView) )
	{
		executeClickHandler(this);
	}
	this->getAnimation()->play(m_normalName, 0, 1);
}


NS_CC_WIDGET_END