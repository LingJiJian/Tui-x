#ifndef __TUIMANAGER_H__
#define __TUIMANAGER_H__

#include "../rapidXml/rapidxml.hpp"  
#include "../rapidXml/rapidxml_utils.hpp"  
#include "../rapidXml/rapidxml_print.hpp"

#include "utils/AnimationUtil.h"
#include "TuiBase.h"
#include "TuiMacros.h"

#include "GUI/CCEditBox/CCEditBox.h"

using namespace cocos2d::extension;
using namespace rapidxml;
using namespace std;
using namespace cocos2d;

class TuiManager : public Ref{
public:
	SINGLE_INSTANCE_FUNC(TuiManager);
	virtual bool init();

	void parseScene(Node* pScene ,const char* sceneName,const char* xmlPath);//解析场景
	void parseCell(CLayout* pCell, const char* cellName, const char* xmlPath);//解析格子

	void setUseSpriteFrame(bool b);//是否使用SpriteFrame

public:

	CWidgetWindow *createPanel(float tag,float x,float y,int w,int h,float rotation);
	CLayout *createLayout(float tag,float x,float y,float w,float h,float rotation);
	CScrollView *createScrollView(float tag,int direction,float x,float y,float w,float h,float rotation);
	CListView *createListView(float tag,const char* img,float x,float y,float w,float h,float rotation);
	CImageView *createImage(float tag,const char* file,float scaleX,float scaleY ,float x,float y,float rotation);
	CImageViewScale9 *createImage9(float tag,const char* file,float x,float y,float w,float h,float up,float down,float left, float right,float rotation);
	CButton *createBtn(float tag,const char* normal,const char* select,const char* disable,float x,float y, float w,float h,float rotation);
	CToggleView *createToggleView(float tag,int exclusion,const char* normal,const char* select,const char* disable,float x,float y,float rotation);
	CSlider *createSlider(float tag, const char* bg,const char* progress,const char* thumb,float x,float y,float rotation);
	CProgressBar *createProgress(float tag, const char* bg,const char* progress,float x,float y,float rotation);
	CLabel *createLabel(float tag, const char* text, const char* font,int alignment, float fontSize, int r, int g, int b, float x, float y, float w, float h, int r2, int g2, int b2, float strokeSize, int shadowDistance, float shadowBlur, float rotation);
	CLabelAtlas *createLabelAtlas(float tag,const char* file,float x,float y,float w,float h,float rotation);
	Armature *createArmature(float tag,const char* name,const char* png,const char* plist,const char* xml,float x,float y,float rotation);
	Sprite *createAnim(float tag,const char* name,const char* png,const char* plist,float x,float y,float rotation);
	CControlView *createControl(float tag,const char* baseboard,const char* joystick,float x,float y,float rotation);
	CCheckBox *createCheckBox(float tag,const char* normal1,const char* normal2,const char* select1,const char* select2,const char* disable1,const char* disable2,float x,float y,float rotation);
	ArmatureBtn *createArmatureBtn(float tag,const char* name,const char* png,const char* plist,const char* xml,float x,float y,float rotation);
	NumericStepper *createNumStep(float tag,const char* lnormal,const char* lselect,const char* ldisable,const char* rnormal,const char* rselect,const char* rdisable,const char* stepBg,float x,float y,float rotation);
	ParticleSystemQuad *createParticle(float tag,const char* plist,float x,float y);
	CTableView *createTableView(float tag, const char* img,int dir, int num, int cellWidth, int cellHeight, float x, float y, float w, float h, float rotation);
	CPageView *createPageView(float tag, const char* img, int dir, int num, float x, float y, float w, float h, float rotation);
	CGridView *createGridView(float tag, const char* img,int column, int num, int cellWidth, int cellHeight, float x, float y, float w, float h, float rotation);
	CGridPageView *createGridPageView(float tag, const char* img, int dir, int column, int row, int num, int cellWidth, int cellHeight, float x, float y, float w, float h, float rotation);
	EditBox *createEditBox(float tag, const char* file, int inputMode, int inputFlag, float x, float y, float w, float h, float rotation);
	MovieView *createMovieView(float tag, const char* json, const char* plist, const char* png, float x, float y, float rotation);
	CircleMenu *createCircleMenu(float tag, float x, float y, float w, float h, float rotation);

protected:
	void loadXml(const string& pathXML);	//加载xml
	void parseControl(Node* container,xml_node<char>*);//解析组件
private:
	map<string,string> m_DataMap;//xml映射内容
	bool m_isUseSpriteFrame;
};

#endif

