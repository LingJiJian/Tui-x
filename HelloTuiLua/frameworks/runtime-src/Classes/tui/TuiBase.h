/************************************************************************
The MIT License(MIT)

Copyright(c) 2014 Lingjijian [B-y]

342854406@qq.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
************************************************************************/
#ifndef __TUI_BASE_H__
#define __TUI_BASE_H__

#include "cocos2d.h"
#include "TuiMacros.h"
#include "../../../CocosWidget/cocos-widget.h"
#include "../../../CocosBase/cocos-base.h"
#include "../../../CocosNet/cocos-net.h"
#include "../../cocos/editor-support/cocostudio/CocoStudio.h"

using namespace cocostudio;
using namespace cocos2d::cocoswidget;

NS_TUI_BEGIN
/**
 * @brief the base of CSceneExtension and CNetDelegate (optional)
 */
class TuiBase :public CSceneExtension
{
public:
	TuiBase();
	virtual ~TuiBase();

	CREATE_FUNC(TuiBase);
	virtual bool init(){ return true; };	

	CC_SYNTHESIZE(bool, m_isAutoRemoveUnusedSpriteFrame, AutoRemoveUnusedSpriteFrame);

protected:
private:
};



NS_TUI_END

#endif

