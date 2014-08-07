#include "CircleMenu.h"

NS_CC_WIDGET_BEGIN

CircleMenu::CircleMenu()
:m_isMouseDown(false)
, m_mouseMove(0.25f)
, m_vx(0)
, m_maxVx(25)
, m_easing(0.95f)
, m_itemScaleA(20)
, m_itemScaleB(50)
, m_noFocusOpacity(0.6f)
{
	setThisObject(this);
	setCascadeOpacityEnabled(true);
	setAnchorPoint(CCWIDGET_BASIC_DEFAULT_ANCHOR_POINT);
}

CircleMenu* CircleMenu::create(Vector<Node*> vet, Size contentSize)
{
	CircleMenu *pRet = new CircleMenu();
	if (pRet && pRet->init(vet, contentSize)){
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

CircleMenu* CircleMenu::create(Size contentSize)
{
	CircleMenu *pRet = new CircleMenu();
	if (pRet && pRet->init(contentSize)){
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

bool CircleMenu::init(Vector<Node*> vet, Size contentSize)
{
	this->setContentSize(contentSize);
	int length = vet.size();
	for (int i = 0; i < length; i++)
	{
		Node *node = vet.at(i);
		float angel = (i + 1) * (360 / length);
		node->setUserData(new float(angel));
		this->addChild(node);
	}

	unscheduleUpdate();
	scheduleUpdate();
	return true;
}	

bool CircleMenu::init(Size contentSize)
{
	this->setContentSize(contentSize);
	return true;
}

void CircleMenu::reloadData()
{
	Vector<Node*> vet = this->getChildren();
	int length = vet.size();
	for (int i = 0; i < length; i++)
	{
		Node *node = vet.at(i);
		float angel = (i + 1) * (360 / length);
		node->setUserData(new float(angel));
	}

	unscheduleUpdate();
	scheduleUpdate();
}

void CircleMenu::update(float dt)
{
	if (m_isMouseDown){
		m_vx = (m_nowPoint.x - m_prePoint.x) * m_mouseMove;
		if (m_vx > m_maxVx){
			m_vx = m_maxVx;
		}
		if (m_vx < -m_maxVx){
			m_vx = -m_maxVx;
		}
		m_prePoint = m_nowPoint;
	}
	else{
		m_vx *= m_easing;
		if (abs(m_vx) < 0.5) m_vx = 0;
	}

	Vector<Node*> vet = this->getChildren();
	int length = vet.size();
	for (int i = 0; i < length; i++)
	{
		Node* node = vet.at(i);
		float *angel = static_cast<float*>(node->getUserData());
		(*angel) += m_vx;
		
		float angelValue = (*angel);
		if (angelValue > 360){
			angelValue -= 360;
		}
		else if (angelValue < -360){
			angelValue += 360;
		}

		Size size = this->getContentSize();
		node->setScale(0.3f + ((m_itemScaleA + m_itemScaleB * sin(CC_DEGREES_TO_RADIANS(angelValue)) / length) * 0.05f));
		node->setPositionX(size.width / 2 - cos(CC_DEGREES_TO_RADIANS(angelValue)) * size.width / 2);
		node->setPositionY(size.height / 2);
	}

	sort(vet.begin(), vet.end(), CircleMenu::sortOnDepth);
	
	for (int i = length-1; i >=0; i--)
	{
		Node *pChild = vet.at(i);
		float opacity = i == length - 1 ? 1 : m_noFocusOpacity;
		pChild->setOpacity((GLubyte)255 * opacity);
		pChild->setLocalZOrder(i);
	}
}

bool CircleMenu::sortOnDepth(Node* itemA, Node* itemB)
{
	return (itemA->getScaleX() < itemB->getScaleX());
}

CWidgetTouchModel CircleMenu::onTouchBegan(Touch *touch)
{
	m_isMouseDown = true;
	m_prePoint = touch->getLocation();
	m_nowPoint = touch->getLocation();

	return eWidgetTouchTransient;
}

void CircleMenu::onTouchEnded(Touch *touch, float fDuration)
{
	m_isMouseDown = false;
	
	Vector<Node*> vet = this->getChildren();
	int length = vet.size();
	Node *pChild = nullptr;
	for (int j = 0; j < length; j++){
		if (vet.at(j)->getLocalZOrder() == length - 1){
			pChild = vet.at(j);
			break;
		}
	}
	if (pChild->getBoundingBox().containsPoint(convertToNodeSpace(touch->getLocation()))){
		executeClickHandler(pChild);
	}
}

void CircleMenu::onTouchMoved(Touch *touch, float fDuration)
{
	m_nowPoint = touch->getLocation();
}

CircleMenu::~CircleMenu()
{
	for (auto& child : _children)
	{
		delete child->getUserData();
		child->setUserData(nullptr);
	}
	removeAllChildrenWithCleanup(true);
}


NS_CC_WIDGET_END