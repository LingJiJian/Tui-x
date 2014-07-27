#ifndef __TUI_MACROS__
#define __TUI_MACROS__

#define NS_TUI_BEGIN namespace cocos2d {namespace tui{
#define NS_TUI_END   }}
#define US_NS_TUI	 using namespace cocos2d::tui;

#ifndef SINGLE_INSTANCE_FUNC
#define SINGLE_INSTANCE_FUNC(__CLASS__)\
public: static __CLASS__* getInstance(){\
	static __CLASS__* m_instance = NULL;\
	if(m_instance == NULL){\
		m_instance = new __CLASS__();\
		if(m_instance && m_instance->init()){\
			m_instance->retain();\
		}else{\
			CC_SAFE_DELETE(m_instance);\
			m_instance = NULL;\
		}\
	}\
	return m_instance;\
}
#endif

#define Arp(_p_) Vec2((float)(_p_.x * TuiManager::getInstance()->getScaleResolutionX()), \
					  (float)(_p_.y * TuiManager::getInstance()->getScaleResolutionY()))

#endif