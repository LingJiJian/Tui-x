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
#ifndef __TUIMANAGER_H__
#define __TUIMANAGER_H__

#include "../../../rapidXml/rapidxml.hpp"  
#include "../../../rapidXml/rapidxml_utils.hpp"  
#include "../../../rapidXml/rapidxml_print.hpp"

#include "utils/AnimationUtil.h"
#include "TuiBase.h"
#include "TuiMacros.h"

#include "../../extensions/GUI/CCEditBox/CCEditBox.h"

using namespace cocos2d::extension;
using namespace rapidxml;
using namespace std;

NS_TUI_BEGIN
/**
 * @brief The parser interface
 */
class TuiManager : public Ref{
public:
	SINGLE_INSTANCE_FUNC(TuiManager);
	virtual bool init();

	/**
	 * @brief parse the scene
	 * @details To find the corresponding to the name of the part of the XML to parse the scene	
	 * 
	 * @param pScene parse target
	 * @param sceneName the panel name in the .fla
	 * @param xmlPath target xml file
	 */
	void parseScene(Node* pScene, const char* sceneName, const char* xmlPath);
	/**
	 * @brief parse the cell
	 * @details To find the corresponding to the name of the part of the XML to parse the cell	
	 * 
	 * @param pCell parse target
	 * @param cellName the cell name in the .fla
	 * @param xmlPath target xml file
	 */
	void parseCell(CLayout* pCell, const char* cellName, const char* xmlPath);
	/**
	 * @brief Whether to use SpriteFrame to create controls
	 * 
	 * @param b 
	 */
	void setUseSpriteFrame(bool b);

public:

	CWidgetWindow *createPanel(float tag, float x, float y, int w, int h, float rotation);
	CLayout *createLayout(float tag, float x, float y, float w, float h, float rotation);
	CScrollView *createScrollView(float tag, int direction,int innerWidth,int innerHeight, float x, float y, float w, float h, float rotation);
	CListView *createListView(float tag, const char* img, float x, float y, float w, float h, float rotation);
	CImageView *createImage(float tag, const char* file, float scaleX, float scaleY, float x, float y, float rotation);
	CImageViewScale9 *createImage9(float tag, const char* file, float x, float y, float w, float h, float up, float down, float left, float right, float rotation);
	CButton *createBtn(float tag, const char* normal, const char* select, const char* disable, float x, float y, float w, float h, float rotation);
	CToggleView *createToggleView(float tag, int exclusion, const char* normal, const char* select, const char* disable, float x, float y, float rotation);
	CSlider *createSlider(float tag, const char* bg, const char* progress, const char* thumb, float x, float y, float rotation);
	CProgressBar *createProgress(float tag, const char* bg, const char* progress, float x, float y, float rotation);
	CLabel *createLabel(float tag, const char* text, const char* font, int alignment, float fontSize, int r, int g, int b, float x, float y, float w, float h, int r2, int g2, int b2, float strokeSize, int shadowDistance, float shadowBlur, float rotation);
	CLabelAtlas *createLabelAtlas(float tag, const char* file, float x, float y, float w, float h, float rotation);
	Armature *createArmature(float tag, const char* name, const char* png, const char* plist, const char* xml, float x, float y, float rotation);
	Sprite *createAnim(float tag, const char* name, const char* png, const char* plist, float x, float y, float rotation);
	CControlView *createControl(float tag, const char* baseboard, const char* joystick, float x, float y, float rotation);
	CCheckBox *createCheckBox(float tag, const char* normal1, const char* normal2, const char* select1, const char* select2, const char* disable1, const char* disable2, float x, float y, float rotation);
	ArmatureBtn *createArmatureBtn(float tag, const char* name, const char* png, const char* plist, const char* xml, float x, float y, float rotation);
	NumericStepper *createNumStep(float tag, const char* lnormal, const char* lselect, const char* ldisable, const char* rnormal, const char* rselect, const char* rdisable, const char* stepBg, float x, float y, float rotation);
	ParticleSystemQuad *createParticle(float tag, const char* plist, float x, float y);
	CTableView *createTableView(float tag, const char* img, int dir, int num, int cellWidth, int cellHeight, float x, float y, float w, float h, float rotation);
	CPageView *createPageView(float tag, const char* img, int dir, int num, float x, float y, float w, float h, float rotation);
	CGridView *createGridView(float tag, const char* img, int column, int num, int cellWidth, int cellHeight, float x, float y, float w, float h, float rotation);
	CGridPageView *createGridPageView(float tag, const char* img, int dir, int column, int row, int num, int cellWidth, int cellHeight, float x, float y, float w, float h, float rotation);
	EditBox *createEditBox(float tag, const char* file, int inputMode, int inputFlag, float x, float y, float w, float h, float rotation);
	MovieView *createMovieView(float tag, const char* json, const char* plist, const char* png, float x, float y, float rotation);
	CircleMenu *createCircleMenu(float tag, float x, float y, float w, float h, float rotation);

protected:
	/**
	 * @brief load xml file and cache
	 * 
	 * @param pathXML 
	 */
	void loadXml(const string& pathXML);	
	/**
	 * @brief parse controls
	 * 
	 * @param container 
	 * @param xmlNode 
	 */
	void parseControl(Node* container,xml_node<char>* xmlNode);
private:
	map<string,string> m_DataMap;
	bool m_isUseSpriteFrame;
};


NS_TUI_END

#endif

