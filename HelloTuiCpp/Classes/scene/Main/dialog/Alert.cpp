#include "Alert.hpp"
#include <CMisc.hpp>
#include <ScreenUtil.hpp>
#include <Language.hpp>
#include <LockScreen.hpp>

CLIENT_NS_BEGIN

Alert::Alert() :
	m_pBg(nullptr),
	m_pLabel(nullptr),
	m_pScrollView(nullptr),
	m_pConfirmBtn(nullptr),
	m_pCancelBtn(nullptr),
	m_bInitialize(false),
	m_bCancel(false),
	m_bHide(false),
	m_pEventTarget(nullptr),
	m_xConfirmHandler(nullptr),
	m_xCancelHandler(nullptr),
	m_pRunningScene(nullptr)
{
	REGISTER_SCENE_FUNC(Alert);
	
	setCachable(true);
}

Alert::~Alert()
{
}

void Alert::initialize(const char* szContent, bool bCancel /*= false*/, bool bHide /*= true*/, CCNode* pObject /*= nullptr*/, SEL_ALERT_SELECTOR confirmHandler /*= nullptr*/, SEL_ALERT_SELECTOR cancelHandler /*= nullptr*/)
{
	// 背景
	Texture2D* pTexture2D = getNewTexture("Common/dialog_bg.jpg", "Common/dialog_bg_alpha_mask.png");
	m_pBg = CCSprite::createWithTexture(pTexture2D);
	getBg()->setPosition(ScreenUtil::getCenter());
	addChild(getBg());

	// 取消按钮
	m_pCancelBtn = TextButton::create(LANGUAGE_VALUE("btn_yes"), "Common/serverselect_confirm_button_1.png", "Common/serverselect_confirm_button_2.png", nullptr);
	getCancelBtn()->setScale(0.7f);
	getCancelBtn()->setAnchorPoint(ccp(0.5, 0.5));
	getCancelBtn()->setPosition(ccp(getContentSize().width / 4, 240));
	getCancelBtn()->setOnClickListener(this, ccw_click_selector(Alert::cancelBtnClickHandler));
	this->addChild(getCancelBtn());

	// 确定按钮
	m_pConfirmBtn = TextButton::create(LANGUAGE_VALUE("btn_yes"), "Common/serverselect_confirm_button_1.png", "Common/serverselect_confirm_button_2.png", nullptr);
	getConfirmBtn()->setScale(0.7f);
	getConfirmBtn()->setAnchorPoint(ccp(0.5, 0.5));
	getConfirmBtn()->setPosition(ccp(getContentSize().width / 4 * 3, 240));
	getConfirmBtn()->setOnClickListener(this, ccw_click_selector(Alert::confirmBtnClickHandler));
	this->addChild(getConfirmBtn());

	// 显示Lable
	m_pLabel = cocoswidget::CLabel::createWithTTF(szContent, "", 30);
	getLabel()->setDimensions(getBg()->getContentSize().width, 0);
	getLabel()->setAnchorPoint(ccp(0, 0));

	m_pScrollView = cocoswidget::CScrollView::create(\
		CCSize(getBg()->getContentSize().width, 210));
	getScrollView()->setDirection(eScrollViewDirectionVertical);
	getScrollView()->setAnchorPoint(ccp(0.5, 0.5));
	getScrollView()->setPosition(\
		ccp(getBg()->getContentSize().width / 2, getBg()->getContentSize().height / 2));
	getScrollView()->addChild(getLabel());
	getBg()->addChild(getScrollView());

	this->m_pEventTarget = pObject;
}

void Alert::show(const char* szContent, bool bCancel, bool bHide, CCObject* pObject /*= nullptr*/, SEL_ALERT_SELECTOR confirmHandler /*= nullptr*/, SEL_ALERT_SELECTOR cancelHandler /*= nullptr*/)
{
	m_pRunningScene = CSceneManager::getInstance()->getRunningScene();

	g_lockScreen.lock();

	if (nullptr != getRunningScene())
	{
		getRunningScene()->setModalable(true);
	}

	if (false == m_bInitialize)
	{
		initialize(szContent);
		m_bInitialize = true;
	}

	getLabel()->setString(szContent);

	m_bCancel			= bCancel;
	m_bHide				= bHide;
	m_pEventTarget		= pObject;
	m_xConfirmHandler	= confirmHandler;
	m_xCancelHandler		= cancelHandler;

	// 设置文本位置
	if (getLabel()->getContentSize().height < getScrollView()->getContentSize().height)
	{
		getScrollView()->setContainerSize(getScrollView()->getContainerSize());

		// 将文本设置为靠上位置
		getLabel()->setPositionY(getScrollView()->getContainerSize().height - \
			getLabel()->getContentSize().height);
	}
	else
	{
		getScrollView()->setContainerSize(getLabel()->getContentSize());
		getLabel()->setPositionY(0);
		getScrollView()->setContentOffsetToTop();
	}

	if (m_bCancel)
	{
		/*getCancelBtn()->setPositionX(-getCancelBtn()->getContentSize().width + 30);
		getConfirmBtn()->setPositionX(getConfirmBtn()->getContentSize().width - 30);*/
	}
	else
	{
		getConfirmBtn()->setPositionX(getContentSize().width / 2);
		getCancelBtn()->setVisible(m_bCancel);
	}

	this->setPosition(0, 0);
	this->stopAllActions();

	if (false == getParent())
	{
		CSceneManager::getInstance()->runUIScene(this);
	}
	else
	{
		getParent()->addChild(this);
	}
}

void Alert::hide()
{
	g_lockScreen.unlock();

	if (nullptr != getRunningScene() \
		&& getRunningScene() == CSceneManager::getInstance()->getRunningScene())
	{
		getRunningScene()->setModalable(false);
	}

	this->stopAllActions();

	CSceneManager::getInstance()->popUIScene(this);
}

void Alert::confirmBtnClickHandler(CCObject *pSender)
{
	if (NULL == pSender)
	{
		return;
	}

	if (m_pEventTarget && m_xConfirmHandler)
	{
		(m_pEventTarget->*m_xConfirmHandler)();
	}

	if (m_bHide)
	{
		hide();
	}
}

void Alert::cancelBtnClickHandler(CCObject *pSender)
{
	if (NULL == pSender)
	{
		return;
	}

	if (m_pEventTarget && m_xCancelHandler)
	{
		(m_pEventTarget->*m_xCancelHandler)();
	}

	if (m_bHide)
	{
		hide();
	}
}

APP_NS_END
