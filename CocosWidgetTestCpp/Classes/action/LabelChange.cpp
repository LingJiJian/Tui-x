#include "LabelChange.h"

LabelChange::LabelChange():
	m_nFromNum(0),
	m_nToNum(0)
{

}

LabelChange* LabelChange::create(float duration, int fromNum, int toNum)
{
	LabelChange *pRet = new LabelChange();
	pRet->initWithDuration(duration, fromNum, toNum);
	pRet->autorelease();

	return pRet;
}

bool LabelChange::initWithDuration(float duration, int fromNum, int toNum)
{
	if (ActionInterval::initWithDuration(duration))
	{
		m_nFromNum = fromNum;
		m_nToNum = toNum;
		return true;
	}

	return false;
}

LabelChange* LabelChange::clone() const
{
	LabelChange* pCopy = NULL;
	pCopy = new LabelChange();
	pCopy->initWithDuration(_duration, m_nFromNum, m_nToNum);

	return pCopy;
}

void LabelChange::startWithTarget(Node *pTarget)
{
	ActionInterval::startWithTarget(pTarget);

	LabelProtocol *pLabel = dynamic_cast<LabelProtocol*>(_target);
	if (pLabel)
	{
		char buf[128] = {0};
		sprintf(buf,"%d",m_nFromNum);
		pLabel->setString(buf);
	}

}

ActionInterval* LabelChange::reverse(void) const
{
	return LabelChange::create(_duration, m_nToNum, m_nFromNum);
}


void LabelChange::update(float t)
{

	LabelProtocol *pLabel = dynamic_cast<LabelProtocol*>(_target);
	if (pLabel)
	{
		int num = m_nFromNum + (m_nToNum - m_nFromNum) * t;
		char buf[128] = {0};
		sprintf(buf,"%d",num);
		pLabel->setString(buf);
	}

}