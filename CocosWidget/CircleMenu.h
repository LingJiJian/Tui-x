#ifndef __CIRECLE_MENU__	
#define __CIRECLE_MENU__

#include "Layout.h"

NS_CC_WIDGET_BEGIN

class CircleMenu : public CLayout, public CClickableProtocol
{
public:
	~CircleMenu();
	CircleMenu();
	static CircleMenu* create(Vector<Node*> vet, Size contentSize);
	virtual bool init(Vector<Node*> vet, Size contentSize);

	static CircleMenu* create(Size contentSize);
	virtual bool init(Size contentSize);
	void reloadData();

	virtual CWidgetTouchModel onTouchBegan(Touch* pTouch);
	virtual void onTouchMoved(Touch* pTouch, float fDuration);
	virtual void onTouchEnded(Touch* pTouch, float fDuration);

	void update(float dt);

	CC_SYNTHESIZE(float, m_noFocusOpacity, NoFocusOpacity);
	CC_SYNTHESIZE(float, m_itemScaleA, ItemScaleA);
	CC_SYNTHESIZE(float, m_itemScaleB, ItemScaleB);

protected:
	static bool sortOnDepth(Node* itemA, Node* itemB);

private:
	bool m_isMouseDown;
	float m_vx;
	float m_maxVx;
	float m_mouseMove;
	float m_easing;
	Vec2 m_prePoint;
	Vec2 m_nowPoint;
};

NS_CC_WIDGET_END

#endif