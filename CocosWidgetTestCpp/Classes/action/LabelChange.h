#ifndef __LabelChange__
#define __LabelChange__

#include "cocos2d.h"
USING_NS_CC;

class LabelChange : public ActionInterval
{
public:
	LabelChange();

public:
	/** creates the action */
	static LabelChange* create(float duration, int fromNum, int toNum);

	/** initializes the action */
	bool initWithDuration(float duration, int fromNum, int toNum);

	virtual LabelChange* clone() const override;
	virtual ActionInterval* reverse(void) const override;
	virtual void startWithTarget(Node *pTarget) override;
	virtual void update(float time) override;

protected:

	int m_nFromNum;
	int m_nToNum;
};

#endif