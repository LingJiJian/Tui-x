#ifndef __TUI_MACROS__
#define __TUI_MACROS__

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

#endif