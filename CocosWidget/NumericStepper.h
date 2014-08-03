#ifndef __NUMERICSTEPPER_H__
#define __NUMERICSTEPPER_H__
#include "cocos2d.h"
#include "Layout.h"
#include "Button.h"
#include "Label.h"
#include "ImageView.h"

NS_CC_WIDGET_BEGIN

class NumericStepper : public CLayout, public CValueChangeableProtocol, public CLongClickableProtocol
{
public:
	NumericStepper();
	virtual bool init(const char *lnormal,const char *lselet,const char *ldisable,
						const char *rnormal,const char *rselet,const char *rdisable,const char* bg);
	virtual bool initSpriteFrameName(const char *lnormal, const char *lselet, const char *ldisable,
		const char *rnormal, const char *rselet, const char *rdisable, const char* bg);

	static NumericStepper *create(const char *lnormal,const char *lselet,const char *ldisable,
									const char *rnormal,const char *rselet,const char *rdisable,const char* bg);
	static NumericStepper *createSpriteFrameName(const char *lnormal, const char *lselet, const char *ldisable,
		const char *rnormal, const char *rselet, const char *rdisable, const char* bg);

	virtual CWidgetTouchModel onTouchBegan(Touch* pTouch);
	void onTouchEnded(Touch* pTouch, float fDuration);
	void onTouchMoved(Touch* pTouch, float fDuration);
	void onTouchCancelled(Touch* pTouch, float fDuration);

	void setValue(int v);
	int getValue();
	void setStep(int v);
	int getStep();
	void setLimit(int min, int max);
	void setAutoRun(bool b);

	CC_WIDGET_LONGCLICK_SCHEDULE(NumericStepper);
private:
	void resetSelf();//reset all position

	bool event_btn_longclick(Ref* pSender, Touch* pTouch);
	void onSchedule(float dt);
	void unSchedule();
protected:
	CButton* m_btnLeft;
	CButton* m_btnRight;
	CLabel* m_labNum;
	CImageView* m_bg;

	void event_btn_left(Ref* s);
	void event_btn_right(Ref* s);
private:
	int m_value;
	int m_step;
	int m_min;
	int m_max;
	Ref *m_curBtnPress;
};

NS_CC_WIDGET_END

#endif