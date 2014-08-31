#ifndef __ARMATURE_BTN__
#define __ARMATURE_BTN__
#include "cocos2d.h"
#include "Widget.h"
#include "cocostudio/CCArmature.h"

using namespace cocostudio;

NS_CC_WIDGET_BEGIN

class ArmatureBtn : public Armature, public CWidget, public CClickableProtocol
{
public:
	ArmatureBtn();
	static ArmatureBtn *create(const char *name);
	
	void setNormalAnimName(const std::string& name);
	void setSelectAnimName(const std::string& name){ m_selectName = name; }
public:
	
	virtual CWidgetTouchModel onTouchBegan(Touch *pTouch);
	virtual void onTouchEnded(Touch *pTouch, float fDuration);
	
protected:
	std::string m_normalName;
	std::string m_selectName;
private:
};

NS_CC_WIDGET_END

#endif