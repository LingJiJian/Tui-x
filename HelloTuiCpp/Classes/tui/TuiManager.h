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

#include "TuiUtil.h"
#include "TuiBase.h"
#include "TuiMacros.h"

using namespace rapidxml;
using namespace std;
using namespace cocos2d;

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
	void parseScene(Node* pScene ,const char* sceneName,const char* xmlPath);
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
	* @brief adaptive multi resolution
	*
	* @param b
	*/
	void setAdaptResolution(bool b, float designWidth = 800, float designHeight = 480);

	CC_SYNTHESIZE_READONLY(float, m_fScaleResolutionX, ScaleResolutionX);
	CC_SYNTHESIZE_READONLY(float, m_fScaleResolutionY, ScaleResolutionY);
public:

	CWidgetWindow *createPanel(float tag,float x,float y,int w,int h,float rotation);
	CLayout *createLayout(float tag,float x,float y,float w,float h,float rotation);
	CExpandableNode *createExpandNode(float tag, float x, float y, float w, float h, float rotation);
	CScrollView *createScrollView(float tag,Color4B color,int direction,int innerWidth,int innerHeight,float x,float y,float w,float h,float rotation);
	CListView *createListView(float tag,Color4B color,float x,float y,float w,float h,float rotation);
	CExpandableListView *createExpandableListView(float tag, Color4B color, float x, float y, float w, float h, float rotation);
	CImageView *createImage(float tag, const char* file, float scaleX, float scaleY, int flipX, int flipY, float x, float y, float rotation, int isUseFrame);
	CImageViewScale9 *createImage9(float tag, const char* file, float x, float y, float w, float h, float up, float down, float left, float right, float rotation, int isUseFrame);
	CButton *createBtn(float tag, Color3B color, int fontSize, const char* font, const char* lab, const char* normal, const char* select, const char* disable, float x, float y, float w, float h, float rotation, int isUseFrame);
	CToggleView *createToggleView(float tag, int exclusion, const char* normal, const char* select, const char* disable, float x, float y, float rotation, int isUseFrame);
	CSlider *createSlider(float tag,int max,int min,int cur, const char* bg, const char* progress, const char* thumb, float x, float y, float rotation, int isUseFrame);
	CProgressBar *createProgress(float tag, int max, int min, int cur, const char* bg, const char* progress,int isShowLabel, float x, float y, float rotation, int isUseFrame);
	CLabel *createLabel(float tag, const char* text, const char* font,int alignment, float fontSize, int r, int g, int b, float x, float y, float w, float h, int r2, int g2, int b2, float strokeSize, int shadowDistance, float shadowBlur, float rotation);
	CLabelAtlas *createLabelAtlas(float tag,const char* num, const char* file,float x,float y,float w,float h,float rotation);
	CLabelBMFont *createLabelBMFont(float tag, const char* text, const char* file, float x, float y, float w, float h, float rotation);
	Armature *createArmature(float tag, const char* name, const char* actionName,const char* png, const char* plist, const char* xml, float x, float y, float rotation);
	Sprite *createAnim(float tag,const char* name,const char* plist,float x,float y,float rotation);
	CControlView *createControl(float tag, const char* baseboard, const char* joystick, float x, float y, float rotation, int isUseFrame);
	CCheckBox *createCheckBox(float tag, const char* normal1, const char* normal2, const char* select1, const char* select2, const char* disable1, const char* disable2, float x, float y, float rotation, int isUseFrame);
	ArmatureBtn *createArmatureBtn(float tag,const char* name,const char* normal,const char* select, const char* png,const char* plist,const char* xml,float x,float y,float rotation);
	NumericStepper *createNumStep(float tag, int isLongClickRun, int max, int min, int cur,int step, const char* lnormal, const char* lselect, const char* ldisable, const char* rnormal, const char* rselect, const char* rdisable, const char* stepBg, float x, float y, float rotation, int isUseFrame);
	ParticleSystemQuad *createParticle(float tag,const char* plist,float x,float y);
	CTableView *createTableView(float tag,Color4B color , int dir, int num, int cellWidth, int cellHeight, float x, float y, float w, float h, float rotation);
	CPageView *createPageView(float tag, Color4B color, int dir, int num, float x, float y, float w, float h, float rotation);
	CGridView *createGridView(float tag, Color4B color, int column, int num, int cellWidth, int cellHeight, float x, float y, float w, float h, float rotation);
	CGridPageView *createGridPageView(float tag, Color4B color, int dir, int column, int row, int num, int cellWidth, int cellHeight, float x, float y, float w, float h, float rotation);
	CEditBox *createEditBox(float tag, const char* placeHolder, const char* file, int inputMode, int inputFlag, float x, float y, float w, float h, float rotation, int isUseFrame);
	CircleMenu *createCircleMenu(float tag, float x, float y, float w, float h, float rotation);
	CTextRich *createTextRich(float tag, const char *text, int maxLen, float x, float y, float w, float h, float rotation, int isUseFrame);
	
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
	void parseControl(Node* container,xml_node<char>*);

	void doAdapterResolution(Node* container);
private:
	map<string,string> m_DataMap;
	
	bool m_isAdaptResolution;
};

#endif

