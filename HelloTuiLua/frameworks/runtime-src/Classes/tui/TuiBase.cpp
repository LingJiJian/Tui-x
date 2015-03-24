#include "TuiBase.h"

NS_TUI_BEGIN

bool TuiBase::init(){
    return CSceneExtension::init();
}

TuiBase::TuiBase()
:m_isAutoRemoveUnusedSpriteFrame(false)
{
}

TuiBase::~TuiBase(){
    
    if(m_isAutoRemoveUnusedSpriteFrame){
        removeAllChildrenWithCleanup(true);
        SpriteFrameCache::getInstance()->removeUnusedSpriteFrames();
    }
}

/************************************************************************/
// GET/SET/IS
/************************************************************************/
Node* TuiBase::getControlByTag(int tag)
{
    return findNode(_children, tag);
}

Node* TuiBase::findNode(Vector<Node*> &pChidren, int tag)
{
    if(pChidren.size() > 0 )
    {
        unsigned int nCount = pChidren.size();
        for(unsigned int i = 0; i < nCount; ++i)
        {
            Node* pObject = pChidren.at(i);
            if( pObject )
            {
                if( pObject->getTag() == tag )
                {
                    return pObject;
                }
                else
                {
                    Node* pRet = findNode(dynamic_cast<Node*>(pObject)->getChildren(), tag);
                    if( pRet )
                    {
                        return pRet;
                    }
                }
            }
        }
    }
    return NULL;
}

NS_TUI_END