#include "TuiManager.h"
#include "tuiconsts.h"

bool TuiManager::init()
{
	m_isAdaptResolution = true;
	m_fScaleResolutionX = 1.0f;
	m_fScaleResolutionY = 1.0f;

	setAdaptResolution(true);
	return true;
}

void TuiManager::parseScene(Node* pScene ,const char* sceneName,const char* xmlPath){

	loadXml(xmlPath);
	string xmlContent = m_DataMap.at(xmlPath);
	char* buf = new char[ xmlContent.size()+1 ];
	memcpy( buf, xmlContent.c_str(), xmlContent.size()+1 );
	
	xml_document<> doc;
	doc.parse<0>(buf);

	for(xml_node<char> *item = doc.first_node("control");item != NULL;item = item->next_sibling()){
		
		if( strcmp(item->first_attribute("type")->value(),kTuiContainerPanel) == 0){//panel

			if(strcmp(item->first_attribute("name")->value(),sceneName) != 0) continue;//only parse the key panel

			this->parseControl(pScene,item);
		}
	}

	if (m_isAdaptResolution)
		doAdapterResolution(pScene);

	delete[] buf;
}

void TuiManager::parseCell(CLayout* pCell, const char* cellName, const char* xmlPath)
{
	string xmlContent = m_DataMap.at(xmlPath);
	char* buf = new char[xmlContent.size() + 1];
	memcpy(buf, xmlContent.c_str(), xmlContent.size() + 1);

	xml_document<> doc;
	doc.parse<0>(buf);

	for (xml_node<char> *item = doc.first_node("control"); item != NULL; item = item->next_sibling()){

		if (strcmp(item->first_attribute("type")->value(), kTuiControlCell) == 0){//cell

			if (strcmp(item->first_attribute("name")->value(), cellName) != 0) continue;//only parse the key cell

			this->parseControl(pCell, item);
		}
	}

	delete[] buf;
}

/////////////////////////////////////////////////////////////////
void TuiManager::parseControl(Node* container,xml_node<char> *item)
{ 
	int tag = atof(item->first_attribute("tag")->value());
	int x = atof(item->first_attribute("x")->value());
	int y = atof(item->first_attribute("y")->value());
	int w = atoi(item->first_attribute("width")->value());
	int h = atoi(item->first_attribute("height")->value());
	int rotation = atof(item->first_attribute("rotation")->value());

	if (strcmp(item->first_attribute("type")->value(), kTuiContainerPanel) == 0){//panel
		CWidgetWindow* pPanel = createPanel(tag, x, y, w, h, rotation);
		container->addChild(pPanel);
		//recursive
		for (xml_node<char> *iitem = item->first_node(kTuiNodeControl); iitem != NULL; iitem = iitem->next_sibling()){
			parseControl(pPanel, iitem);
		}

	}else if (strcmp(item->first_attribute("type")->value(),kTuiControlCell) == 0){//cell
		//recursive
		for (xml_node<char> *iitem = item->first_node(kTuiNodeControl); iitem != NULL; iitem = iitem->next_sibling()){
			parseControl(container, iitem);
		}

	}else if(strcmp(item->first_attribute("type")->value(),kTuiControlImage) == 0){//image
		const char* file = item->first_attribute("image")->value();
		float scaleX = atof(item->first_attribute("scaleX")->value());
		float scaleY = atof(item->first_attribute("scaleY")->value());
		int flipX = atoi(item->first_attribute("flipX")->value());
		int flipY = atoi(item->first_attribute("flipY")->value());
		int isUseFrame = atoi(item->first_attribute("spriteFrame")->value());
		CImageView *pImg = createImage(tag, file, scaleX, scaleY, flipX, flipY, x, y, rotation, isUseFrame);
		container->addChild(pImg);
	
	}else if(strcmp(item->first_attribute("type")->value(),kTuiControlImage9) == 0){//image9
		const char* file = item->first_attribute("image")->value();
		float w = atof(item->first_attribute("width")->value());
		float h = atof(item->first_attribute("height")->value());
		float up = atof(item->first_attribute("up")->value());
		float down = atof(item->first_attribute("down")->value());
		float left = atof(item->first_attribute("left")->value());
		float right = atof(item->first_attribute("right")->value());
		int isUseFrame = atoi(item->first_attribute("spriteFrame")->value());
		CImageViewScale9 *pImg = createImage9(tag,file,x,y,w,h,up,down,left,right,rotation,isUseFrame);
		container->addChild(pImg);

	}else if(strcmp(item->first_attribute("type")->value(),kTuiControlButton) == 0){//button
		const char* normal = item->first_attribute("normal")->value();
		const char* select = item->first_attribute("select")->value();
		const char* disable = item->first_attribute("disable")->value();
		float w = atof(item->first_attribute("width")->value());
		float h = atof(item->first_attribute("height")->value());
		int isUseFrame = atoi(item->first_attribute("spriteFrame")->value());
		CButton *pBtn = NULL;
		if (item->first_attribute("text")){
			const char* lab = item->first_attribute("text")->value();
			int r = atoi(item->first_attribute("red")->value());
			int g = atoi(item->first_attribute("green")->value());
			int b = atoi(item->first_attribute("blue")->value());
			int fontSize = atoi(item->first_attribute("textSize")->value());
			const char* font = item->first_attribute("textFont")->value();
			
			pBtn = createBtn(tag, Color3B(r, g, b), fontSize, font, lab, normal, select, disable, x, y, w, h, rotation,isUseFrame);
		}else{
			pBtn = createBtn(tag, Color3B(), 0, nullptr, nullptr, normal, select, disable, x, y, w, h, rotation,isUseFrame);
		}
		container->addChild(pBtn);

	}else if(strcmp(item->first_attribute("type")->value(),kTuiControlToggleView) == 0){//toggleView
		const char* normal = item->first_attribute("normal")->value();
		const char* select = item->first_attribute("select")->value();
		const char* disable = item->first_attribute("disable")->value();
		float exclusion = atof(item->first_attribute("exclusion")->value());
		int isUseFrame = atoi(item->first_attribute("spriteFrame")->value());
		CToggleView* toggle = createToggleView(tag, exclusion, normal, select, disable, x, y, rotation, isUseFrame);
		container->addChild(toggle);

	}else if(strcmp(item->first_attribute("type")->value(),kTuiControlSlider) == 0){//slider
		const char* bg = item->first_attribute("bg")->value();
		const char* progress = item->first_attribute("progress")->value();
		const char* thumb = item->first_attribute("thumb")->value();
		int max = atoi(item->first_attribute("max")->value());
		int min = atoi(item->first_attribute("min")->value());
		int cur = atoi(item->first_attribute("cur")->value());
		int isUseFrame = atoi(item->first_attribute("spriteFrame")->value());
		CSlider *pSlider = createSlider(tag,max,min,cur,bg,progress,thumb,x,y,rotation,isUseFrame);
		container->addChild(pSlider);

	}else if(strcmp(item->first_attribute("type")->value(),kTuiControlProgress) == 0){//progress
		const char* bg = item->first_attribute("bg")->value();
		const char* progress = item->first_attribute("progress")->value();
		int isShowLabel = atoi(item->first_attribute("showLabel")->value());
		int max = atoi(item->first_attribute("max")->value());
		int min = atoi(item->first_attribute("min")->value());
		int cur = atoi(item->first_attribute("cur")->value());
		int isUseFrame = atoi(item->first_attribute("spriteFrame")->value());
		CProgressBar *pProgress = createProgress(tag, max, min, cur, bg, progress, isShowLabel, x, y, rotation, isUseFrame);
		container->addChild(pProgress);

	}else if(strcmp(item->first_attribute("type")->value(),kTuiControlLabel) == 0){//label
		float size = atof(item->first_attribute("textSize")->value());
		int alignment = atoi(item->first_attribute("alignment")->value());
		const char* text = item->first_attribute("text")->value();
		const char* font = item->first_attribute("textFont")->value();
		float w = atof(item->first_attribute("width")->value());
		float h = atof(item->first_attribute("height")->value());
		
		int r = atoi(item->first_attribute("red")->value());
		int g = atoi(item->first_attribute("green")->value());
		int b = atoi(item->first_attribute("blue")->value());
		int r2 = atoi(item->first_attribute("strokeRed")->value());
		int g2 = atoi(item->first_attribute("strokeGreen")->value());
		int b2 = atoi(item->first_attribute("strokeBlue")->value());
		int strokeSize = atoi(item->first_attribute("strokeSize")->value());
		int shadowDistance = atoi(item->first_attribute("shadowDistance")->value());
		int shadowBlur = atoi(item->first_attribute("shadowBlur")->value());
		CLabel *pLabel = createLabel(tag, text, font, alignment, size, r, g, b, x, y, w, h,
									r2,g2,b2,strokeSize,shadowDistance,shadowBlur,rotation);
		container->addChild(pLabel);

	}else if (strcmp(item->first_attribute("type")->value(), kTuiControlLabelAtlas) == 0){//labelAtlas
		const char* imgPath = item->first_attribute("image")->value();
		const char* num = item->first_attribute("num")->value();
		float w = atof(item->first_attribute("width")->value());
		float h = atof(item->first_attribute("height")->value());
		CLabelAtlas *pLabAtlas = createLabelAtlas(tag, num, imgPath, x, y, w, h, rotation);
		container->addChild(pLabAtlas);

	}else if (strcmp(item->first_attribute("type")->value(),kTuiControlLabelBMFont) == 0){//labelBmfont
		const char* file = item->first_attribute("fnt")->value();
		const char* text = item->first_attribute("text")->value();
		float w = atof(item->first_attribute("width")->value());
		float h = atof(item->first_attribute("height")->value());
		CLabelBMFont *pLabBMFont = createLabelBMFont(tag, text, file, x, y, w, h, rotation);
		container->addChild(pLabBMFont);

	}else if(strcmp(item->first_attribute("type")->value(),kTuiControlArmature) == 0){//armature
		const char* xml = item->first_attribute("xml")->value();
		const char* png = item->first_attribute("png")->value();
		const char* plist = item->first_attribute("plist")->value();
		const char* name = item->first_attribute("name")->value();
		const char* actionName = NULL;
		if (item->first_attribute("play")) actionName = item->first_attribute("play")->value();
		Armature *pArmature = createArmature(tag, name,actionName,png, plist, xml, x, y, rotation);
		container->addChild(pArmature);

	}else if(strcmp(item->first_attribute("type")->value(),kTuiControlAnim) == 0){//animation
		const char* plist = item->first_attribute("plist")->value();
		const char* name = item->first_attribute("name")->value();
		Sprite *pSprite = createAnim(tag,name,plist,x,y,rotation);
		container->addChild(pSprite);

	}else if(strcmp(item->first_attribute("type")->value(),kTuiControlControl) == 0){//controlView
		const char* baseboard = item->first_attribute("baseboard")->value();
		const char* joystick = item->first_attribute("joystick")->value();
		int isUseFrame = atoi(item->first_attribute("spriteFrame")->value());
		CControlView *pControl = createControl(tag, baseboard, joystick, x, y, rotation, isUseFrame);
		container->addChild(pControl);

	}else if (strcmp(item->first_attribute("type")->value(), kTuiContainerScroll) == 0){//scrollView
		float w = atof(item->first_attribute("width")->value());
		float h = atof(item->first_attribute("height")->value());
		int innerWidth = atoi(item->first_attribute("innerWidth")->value());
		int innerHeight = atoi(item->first_attribute("innerHeight")->value());
		int direction = atof(item->first_attribute("direction")->value());
		int r = atoi(item->first_attribute("red")->value());
		int g = atoi(item->first_attribute("green")->value());
		int b = atoi(item->first_attribute("blue")->value());
		int a = atoi(item->first_attribute("alpha")->value());
		CScrollView *pView = createScrollView(tag,Color4B(r,g,b,a), direction, innerWidth, innerHeight, x, y, w, h, rotation);
		container->addChild(pView);
		//recursive
		for (xml_node<char> *iitem = item->first_node(kTuiNodeControl); iitem != NULL; iitem = iitem->next_sibling()){
			parseControl(pView->getContainer(), iitem);
		}

	}else if (strcmp(item->first_attribute("type")->value(), kTuiContainerLayout) == 0){//layout
		float w = atof(item->first_attribute("width")->value());
		float h = atof(item->first_attribute("height")->value());
		CLayout *pLayout = createLayout(tag, x, y, w, h, rotation);
		container->addChild(pLayout);
		//recursive
		for (xml_node<char> *iitem = item->first_node(kTuiNodeControl); iitem != NULL; iitem = iitem->next_sibling()){
			parseControl(pLayout, iitem);
		}
		Vector<Node*> vet = pLayout->getChildren();
		for (Node *pChild : vet){//Offset coordinates Because CLayout zero point in the lower left corner
			pChild->setPosition(pChild->getPosition() + Vec2(w / 2, h / 2));
		}

	}else if (strcmp(item->first_attribute("type")->value(), kTuiControlListView) == 0){//listView
		float w = atof(item->first_attribute("width")->value());
		float h = atof(item->first_attribute("height")->value());
		float num = atof(item->first_attribute("num")->value());
		int r = atoi(item->first_attribute("red")->value());
		int g = atoi(item->first_attribute("green")->value());
		int b = atoi(item->first_attribute("blue")->value());
		int a = atoi(item->first_attribute("alpha")->value());
		CListView* pList = createListView(tag, Color4B(r, g, b, a), x, y, w, h, rotation);
		container->addChild(pList);

		for (int i = 0; i < num; i++){//add item
			xml_node<char> *iitem = item->first_node(kTuiNodeControl);
			w = atof(iitem->first_attribute("width")->value());
			h = atof(iitem->first_attribute("height")->value());

			CLayout *pLayout = createLayout(i, 0, 0, w, h, rotation);
			for (xml_node<char> *iiitem = iitem->first_node(kTuiNodeControl); iiitem != NULL; iiitem = iiitem->next_sibling()){
				parseControl(pLayout, iiitem);
			}
			Vector<Node*> vet = pLayout->getChildren();
			for (Node *pChild : vet){//Offset coordinates Because CLayout zero point in the lower left corner
				if (pChild->getTag() > 0)
					pChild->setPosition(pChild->getPosition() + Vec2(w / 2, h / 2));
			}
			pList->insertNodeAtLast(pLayout);
		}
		pList->reloadData();

	}else if (strcmp(item->first_attribute("type")->value(), kTuiControlExpList) == 0){//explist
		float w = atof(item->first_attribute("width")->value());
		float h = atof(item->first_attribute("height")->value());
		float num = atof(item->first_attribute("num")->value());
		int r = atoi(item->first_attribute("red")->value());
		int g = atoi(item->first_attribute("green")->value());
		int b = atoi(item->first_attribute("blue")->value());
		int a = atoi(item->first_attribute("alpha")->value());
		CExpandableListView* pList = createExpandableListView(tag, Color4B(r, g, b, a), x, y, w, h, rotation);
		container->addChild(pList);

		for (int i = 0; i < num; i++){//add item
			xml_node<char> *iitem = item->first_node(kTuiNodeControl);
			w = atof(iitem->first_attribute("width")->value());
			h = atof(iitem->first_attribute("height")->value());

			int iw, ih = 0;
			CExpandableNode *pExpNode = createExpandNode(i, 0, 0, w, h, rotation);
			CLayout *pExpNodeItem = nullptr;
			for (xml_node<char> *iiitem = iitem->first_node(kTuiNodeControl); iiitem != NULL; iiitem = iiitem->next_sibling()){
				if (strcmp(iiitem->first_attribute("type")->value(), kTuiContainerLayout) != 0){
					parseControl(pExpNode, iiitem);
				}else{
					pExpNodeItem = createLayout(0, 0, 0, w, h, rotation);
					iw = atof(iiitem->first_attribute("width")->value());
					ih = atof(iiitem->first_attribute("height")->value());
                    pExpNodeItem->setContentSize(Size(iw, ih));
					for (xml_node<char> *iiiitem = iiitem->first_node(kTuiNodeControl); iiiitem != NULL; iiiitem = iiiitem->next_sibling()){
						parseControl(pExpNodeItem, iiiitem);
					}
				}
			}
			for (Node *c : pExpNode->getChildren())
			{
				if (c->getTag() > 0)
					c->setPosition(c->getPosition() + Vec2(w / 2, h / 2));
			}
			for (Node *c : pExpNodeItem->getChildren())
			{
				c->setPosition(c->getPosition() + Vec2(iw/2, ih / 2));
			}
			pExpNode->insertItemNodeAtLast(pExpNodeItem);
			pList->insertExpandableNodeAtLast(pExpNode);
		}
		pList->reloadData();

	}else if(strcmp(item->first_attribute("type")->value(),kTuiControlCheckBox) == 0){//checkBox
		const char* normal1 = item->first_attribute("normal1")->value();
		const char* normal2 = item->first_attribute("normal2")->value();
		const char* select1 = item->first_attribute("select1")->value();
		const char* select2 = item->first_attribute("select2")->value();
		const char* disable1 = item->first_attribute("disable1")->value();
		const char* disable2 = item->first_attribute("disable2")->value();
		int isUseFrame = atoi(item->first_attribute("spriteFrame")->value());
		CCheckBox *pCheckBox = createCheckBox(tag,normal1,normal2,select1,select2,disable1,disable2,x,y,rotation,isUseFrame);
		container->addChild(pCheckBox);

	}else if(strcmp(item->first_attribute("type")->value(),kTuiControlArmatureBtn) == 0){//ArmatureBtn
		const char* png = item->first_attribute("png")->value();
		const char* plist = item->first_attribute("plist")->value();
		const char* name = item->first_attribute("name")->value();
		const char* xml = item->first_attribute("xml")->value();
		const char* normal = item->first_attribute("normal")->value();
		const char* select = item->first_attribute("select")->value();
		ArmatureBtn *pArmBtn = createArmatureBtn(tag, name, normal, select, png, plist, xml, x, y, rotation);
		container->addChild(pArmBtn);

	}else if(strcmp(item->first_attribute("type")->value(),kTuiControlNumbericStepper) == 0){//NumbericStepper
		const char* lnormal = item->first_attribute("lnormal")->value();
		const char* rnormal = item->first_attribute("rnormal")->value();
		const char* lselect = item->first_attribute("lselect")->value();
		const char* rselect = item->first_attribute("rselect")->value();
		const char* ldisable = item->first_attribute("ldisable")->value();
		const char* rdisable = item->first_attribute("rdisable")->value();
		const char* stepBg = item->first_attribute("stepBg")->value();
		int isLongClickRun = atoi(item->first_attribute("longClickRun")->value());
		int max = atoi(item->first_attribute("max")->value());
		int min = atoi(item->first_attribute("min")->value());
		int cur = atoi(item->first_attribute("cur")->value());
		int step = atoi(item->first_attribute("step")->value());
		int isUseFrame = atoi(item->first_attribute("spriteFrame")->value());
		NumericStepper *pNumStep = createNumStep(tag, isLongClickRun,max,min,cur,step,lnormal, lselect, ldisable, rnormal, rselect, rdisable, stepBg, x, y, rotation, isUseFrame);
		container->addChild(pNumStep);

	}else if(strcmp(item->first_attribute("type")->value(),kTuiControlPaticle) == 0){//Particle
		const char* plist = item->first_attribute("plist")->value();
		ParticleSystem *pPartical = createParticle(tag,plist,x,y);
		container->addChild(pPartical);
	
	}else if (strcmp(item->first_attribute("type")->value(), kTuiControlPageView) == 0){//pageView
		float w = atof(item->first_attribute("width")->value());
		float h = atof(item->first_attribute("height")->value());
		float num = atoi(item->first_attribute("num")->value());
		int dir = atoi(item->first_attribute("direction")->value());
		int r = atoi(item->first_attribute("red")->value());
		int g = atoi(item->first_attribute("green")->value());
		int b = atoi(item->first_attribute("blue")->value());
		int a = atoi(item->first_attribute("alpha")->value());
		CPageView *pPageView = createPageView(tag, Color4B(r,g,b,a), dir, num, x, y, w, h, rotation);
		container->addChild(pPageView);

	}else if (strcmp(item->first_attribute("type")->value(), kTuiControlTable) == 0){//TableView
		float w = atof(item->first_attribute("width")->value());
		float h = atof(item->first_attribute("height")->value());
		float num = atoi(item->first_attribute("num")->value());
		int dir = atoi(item->first_attribute("direction")->value());
		int cellWidth = atoi(item->first_attribute("cellWidth")->value());
		int cellHeight = atoi(item->first_attribute("cellHeight")->value());
		int r = atoi(item->first_attribute("red")->value());
		int g = atoi(item->first_attribute("green")->value());
		int b = atoi(item->first_attribute("blue")->value());
		int a = atoi(item->first_attribute("alpha")->value());
		CTableView *pView = createTableView(tag, Color4B(r, g, b, a), dir, num, cellWidth, cellHeight, x, y, w, h, rotation);
		container->addChild(pView);

	}else if (strcmp(item->first_attribute("type")->value(), kTuiControlGridView) == 0){//GridView
		float w = atof(item->first_attribute("width")->value());
		float h = atof(item->first_attribute("height")->value());
		int cellWidth = atoi(item->first_attribute("cellWidth")->value());
		int cellHeight = atoi(item->first_attribute("cellHeight")->value());
		int column = atoi(item->first_attribute("column")->value());
		int num = atoi(item->first_attribute("num")->value());
		int r = atoi(item->first_attribute("red")->value());
		int g = atoi(item->first_attribute("green")->value());
		int b = atoi(item->first_attribute("blue")->value());
		int a = atoi(item->first_attribute("alpha")->value());
		CGridView *pView = createGridView(tag, Color4B(r, g, b, a), column, num, cellWidth, cellHeight, x, y, w, h, rotation);
		container->addChild(pView);

	}else if (strcmp(item->first_attribute("type")->value(), kTuiControlGridPageView) == 0){//GridPageView
		float w = atof(item->first_attribute("width")->value());
		float h = atof(item->first_attribute("height")->value());
		int cellWidth = atoi(item->first_attribute("cellWidth")->value());
		int cellHeight = atoi(item->first_attribute("cellHeight")->value());
		int column = atoi(item->first_attribute("column")->value());
		int row = atoi(item->first_attribute("row")->value());
		int num = atoi(item->first_attribute("num")->value());
		int dir = atoi(item->first_attribute("direction")->value());
		int r = atoi(item->first_attribute("red")->value());
		int g = atoi(item->first_attribute("green")->value());
		int b = atoi(item->first_attribute("blue")->value());
		int a = atoi(item->first_attribute("alpha")->value());
		CGridPageView *pView = createGridPageView(tag, Color4B(r, g, b, a), dir, column, row, num, cellWidth, cellHeight, x, y, w, h, rotation);
		container->addChild(pView);

	}else if(strcmp(item->first_attribute("type")->value(),kTuiControlEditBox) == 0){//EditBox
		float w = atof(item->first_attribute("width")->value());
		float h = atof(item->first_attribute("height")->value());
		const char* img = item->first_attribute("image")->value();
		int inputMode = atoi(item->first_attribute("inputMode")->value());
		int inputFlag = atoi(item->first_attribute("inputFlag")->value());
		const char* placeHolder = item->first_attribute("placeHolder")->value();
		int isUseFrame = atoi(item->first_attribute("spriteFrame")->value());
		CEditBox *pEdit = createEditBox(tag, placeHolder, img, inputMode, inputFlag, x, y, w, h, rotation,isUseFrame);
		container->addChild(pEdit);

	}else if (strcmp(item->first_attribute("type")->value(), kTuiContainerCircleMenu) == 0){//CircleMenu
		float w = atof(item->first_attribute("width")->value());
		float h = atof(item->first_attribute("height")->value());
		CircleMenu *pMenu = createCircleMenu(tag, x, y, w, h, rotation);
		container->addChild(pMenu);
		//recursive
		for (xml_node<char> *iitem = item->first_node(kTuiNodeControl); iitem != NULL; iitem = iitem->next_sibling()){
			parseControl(pMenu, iitem);
		}
		pMenu->reloadData();

	}else if (strcmp(item->first_attribute("type")->value(), kTuiControlRichText) == 0){
		const char* text = item->first_attribute("text")->value();
		int maxLen = atoi(item->first_attribute("max")->value());
		int isSpriteFrame = atoi(item->first_attribute("spriteFrame")->value());
		CTextRich *pTextRich = createTextRich(tag, text, maxLen, x, y, w, h, rotation, isSpriteFrame);
		container->addChild(pTextRich);
	}
}

///////////////////////////////////////////////////////////////////
CWidgetWindow *TuiManager::createPanel(float tag, float x, float y, int w, int h,float rotation){
	CWidgetWindow *pPanel = CWidgetWindow::create();
	pPanel->setContentSize(Size(w, h));
	pPanel->setPosition(Vec2(x,y));
	pPanel->setRotation(rotation);
	pPanel->setTag(tag);
	return pPanel;
}

CLayout *TuiManager::createLayout(float tag,float x,float y,float w,float h,float rotation){
	CLayout *pLayout = CLayout::create(Size(w,h));
	pLayout->setPosition(Vec2(x,-y));
	pLayout->setRotation(rotation);
	pLayout->setTag(tag);
	return pLayout;
}

CExpandableNode *TuiManager::createExpandNode(float tag, float x, float y, float w, float h, float rotation){
	CExpandableNode *pNode = CExpandableNode::create();
	pNode->setContentSize(Size(w, h));
	pNode->setPosition(Vec2(x, -y));
	pNode->setRotation(rotation);
	pNode->setTag(tag);
	return pNode;
}

CScrollView *TuiManager::createScrollView(float tag, Color4B color, int direction, int innerWidth, int innerHeight, float x, float y, float w, float h, float rotation){
	CScrollView *pView = CScrollView::create(Size(w,h));
	if (color.a != 0) pView->setBackgroundColor(color);
	pView->setPosition(Vec2(x,-y));
	pView->setContainerSize(Size(innerWidth, innerHeight));
	pView->setDirection((CScrollViewDirection)direction);
	pView->setRotation(rotation);
	pView->setTag(tag);
	return pView;
}

CListView *TuiManager::createListView(float tag, Color4B color, float x, float y, float w, float h, float rotation){
	CListView *pView = CListView::create(Size(w, h));
	if (color.a != 0) pView->setBackgroundColor(color);
	pView->setDirection(eScrollViewDirectionVertical);
	pView->setPosition(Vec2(x, -y));
	pView->setRotation(rotation);
	pView->setTag(tag);
	return pView;
}

CExpandableListView *TuiManager::createExpandableListView(float tag, Color4B color, float x, float y, float w, float h, float rotation){
	CExpandableListView *pView = CExpandableListView::create(Size(w, h));
	if (color.a != 0) pView->setBackgroundColor(color);
	pView->setDirection(eScrollViewDirectionVertical);
	pView->setPosition(Vec2(x, -y));
	pView->setRotation(rotation);
	pView->setTag(tag);
	return pView;
}

CImageView *TuiManager::createImage(float tag, const char* file, float scaleX, float scaleY, int flipX, int flipY, float x, float y, float rotation, int isUseFrame){
	CImageView *pImg = isUseFrame ? CImageView::createWithSpriteFrameName(file) : CImageView::create(file);
	Size size = pImg->getContentSize();
	pImg->setPosition(Vec2(x,-y));
	pImg->setFlippedX(flipX == 1);
	pImg->setFlippedY(flipY == 1);
	pImg->setScale(scaleX, scaleY);
	pImg->setRotation(rotation);
	pImg->setTag(tag);
	return pImg;
}

CImageViewScale9 *TuiManager::createImage9(float tag,const char* file,float x,float y,float w,float h,float up,float down,float left, float right,float rotation,int isUseFrame){
	CImageViewScale9* pSprite = NULL;
	if (isUseFrame){
		pSprite = CImageViewScale9::createWithSpriteFrameName(file,Rect(up,down,left,right));
	}else{
		CImageView *temp = CImageView::create(file);
		Size size = temp->getContentSize();
		pSprite = CImageViewScale9::create(file, Rect(0,0,size.width,size.height),Rect(up,down,left,right));
	}
	pSprite->setContentSize(Size(w * m_fScaleResolutionX,h * m_fScaleResolutionY));
	pSprite->setPosition(Vec2(x,-y));
	pSprite->setRotation(rotation);
	pSprite->setTag(tag);
	return pSprite;
}

CButton* TuiManager::createBtn(float tag, Color3B color, int fontSize, const char* font, const char* lab, const char* normal, const char* select, const char* disable, float x, float y, float w, float h, float rotation, int isUseFrame){
	CButton * pBtn = NULL;
	if(isUseFrame){
		pBtn = CButton::createWith9SpriteFrameName(Size(w, h), normal, select, disable);
	}else{
		pBtn = CButton::createWith9Sprite(Size(w,h),normal,select,disable);
	}
	if (lab) pBtn->initText(lab, font, fontSize, Size::ZERO, color);
	pBtn->setRotation(rotation);
	pBtn->setPosition(Vec2(x,-y));
	pBtn->setTag(tag);
	return pBtn;
}

CToggleView* TuiManager::createToggleView(float tag, int exclusion, const char* normal, const char* select, const char* disable, float x, float y, float rotation, int isUseFrame){
	CToggleView *pToggle = NULL;
	if(isUseFrame){
		pToggle = CToggleView::create();
		pToggle->setNormalSpriteFrameName(normal);
		pToggle->setSelectedSpriteFrameName(select);
		pToggle->setDisabledSpriteFrameName(disable);
	}else{
		pToggle = CToggleView::create(normal,select,disable);
	}
	pToggle->setRotation(rotation);
	pToggle->setExclusion(exclusion);
	pToggle->setPosition(x,-y);
	pToggle->setTag(tag);
	return pToggle;
}

CSlider* TuiManager::createSlider(float tag,int max,int min,int cur, const char* bg, const char* progress, const char* thumb, float x, float y, float rotation, int isUseFrame){
	CSlider *pSlider = NULL;
	if (isUseFrame){
		pSlider = CSlider::createSpriteFrame(thumb, progress);
		pSlider->setBackgroundSpriteFrameName(bg);
	}else{
		pSlider = CSlider::create(thumb,progress);
		pSlider->setBackgroundImage(bg);
	}
	pSlider->setRotation(rotation);
	pSlider->setPosition(Vec2(x,-y));
	pSlider->setMinValue(min);
	pSlider->setMaxValue(max);
	pSlider->setValue(cur);
	pSlider->setTag(tag);
	return pSlider;
}

CProgressBar* TuiManager::createProgress(float tag, int max, int min, int cur, const char* bg, const char* progress,int isShowLabel, float x, float y, float rotation, int isUseFrame){
	CProgressBar *pProgress = NULL;
	if (isUseFrame){
		pProgress = CProgressBar::createSpriteFrame(progress);
		pProgress->setBackgroundSpriteFrameName(bg);
	}else{
		pProgress = CProgressBar::create(progress);
		pProgress->setBackgroundImage(bg);
	}
	pProgress->setShowValueLabel(isShowLabel == 1);
	pProgress->setRotation(rotation);
	pProgress->setPosition(Vec2(x,-y));
	pProgress->setMaxValue(max);
	pProgress->setMinValue(min);
	pProgress->setValue(cur);
	pProgress->setTag(tag);
	return pProgress;
}

CLabel* TuiManager::createLabel(float tag, const char* text, const char* font, int alignment, float fontSize, int r, int g, int b, float x, float y, float w, float h,
							int r2,int g2,int b2,float strokeSize,int shadowDistance,float shadowBlur,float rotation)
{
	CLabel *pLabel = CLabel::createWithTTF(text,font,fontSize);

	if(shadowDistance != 0){
		pLabel->setTextColor(Color4B(r,g,b,255));
		pLabel->enableShadow(Color4B(r2,g2,b2,255),Size(shadowDistance,shadowDistance),shadowBlur);
	}
	if(strokeSize != 0){
		pLabel->setTextColor(Color4B(r,g,b,255));
		pLabel->enableOutline(Color4B(r2,g2,b2,255),strokeSize);
	}
	if(shadowDistance == 0 && strokeSize == 0){
		pLabel->setColor(Color3B(r,g,b));
	}
	pLabel->setAlignment((TextHAlignment)alignment);
	pLabel->setDimensions(w,h);
	pLabel->setRotation(rotation);
	pLabel->setPosition(Vec2(x+w/2,-(y + h/2)));
	pLabel->setTag(tag);
	return pLabel;
}

CLabelAtlas* TuiManager::createLabelAtlas(float tag, const char* num, const char* imgPath,float x,float y,float w,float h,float rotation){
	CLabelAtlas *pLabAtlas = CLabelAtlas::create(num, imgPath, w / 12, h, 48);
	pLabAtlas->setRotation(rotation);
	pLabAtlas->setPosition(Vec2(x,-y));
	pLabAtlas->setTag(tag);
	return pLabAtlas;
}

CLabelBMFont* TuiManager::createLabelBMFont(float tag, const char* text, const char* file, float x, float y, float w, float h, float rotation){
	CLabelBMFont *pLabBMFont = CLabelBMFont::create(TuiUtil::replace_all(text,"\\n","\n"), file, TextHAlignment::LEFT);
	pLabBMFont->setAnchorPoint(Vec2(0, 1));
	pLabBMFont->setRotation(rotation);
	pLabBMFont->setPosition(Vec2(x, -y));
	pLabBMFont->setTag(tag);
	return pLabBMFont;
}

Armature* TuiManager::createArmature(float tag,const char* name,const char* actionName, const char* png,const char* plist,const char* xml,float x,float y,float rotation){
	ArmatureDataManager::getInstance()->addArmatureFileInfo(png,plist,xml);
	Armature *pArmature = Armature::create(name);
	if (actionName) pArmature->getAnimation()->play(actionName,0,1);
	pArmature->setPosition(Vec2(x,-y));
	pArmature->setRotation(rotation);
	pArmature->setTag(tag);
	return pArmature;
}

Sprite* TuiManager::createAnim(float tag,const char* name,const char* plist,float x,float y,float rotation){
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(plist);
	Animation* pAnim = TuiUtil::createAnimWithName(name,0.05f,-1);
	SpriteFrame *pTmpFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(string(name) + "1.png");
	Sprite* pSprite = Sprite::create();
	pSprite->runAction(Animate::create(pAnim));
	pSprite->setPosition(Vec2(x,-y));
	pSprite->setRotation(rotation);
	pSprite->setContentSize(pTmpFrame->getOriginalSize());
	pSprite->setTag(tag);
	return pSprite;
}

CControlView* TuiManager::createControl(float tag, const char* baseboard, const char* joystick, float x, float y, float rotation, int isUseFrame){
	CControlView* pView = NULL;
	if(isUseFrame){
		pView = CControlView::create();
		pView->setBaseBoardSpriteFrameName(baseboard);
		pView->setJoystickSpriteFrameName(joystick);
	}else{
		pView = CControlView::create(baseboard,joystick);
	}
	pView->setPosition(Vec2(x, -y));
	pView->setRadius(pView->getContentSize().width / 2);
	pView->setRotation(rotation);
	pView->setTag(tag);
	return pView;
}

CCheckBox* TuiManager::createCheckBox(float tag, const char* normal1, const char* normal2, const char* select1, const char* select2, const char* disable1, const char* disable2, float x, float y, float rotation, int isUseFrame){
	CCheckBox* pCheckBox = NULL;
	if(isUseFrame){
		pCheckBox = CCheckBox::create();
		pCheckBox->setNormalSpriteFrameName(normal1);
		pCheckBox->setNormalPressSpriteFrameName(normal2);
		pCheckBox->setCheckedSpriteFrameName(select1);
		pCheckBox->setCheckedPressSpriteFrameName(select2);
		pCheckBox->setDisabledNormalSpriteFrameName(disable1);
		pCheckBox->setDisabledCheckedSpriteFrameName(disable2);
	}else{
		pCheckBox = CCheckBox::create(); 
		pCheckBox->setNormalImage(normal1); 
		pCheckBox->setNormalPressImage(normal2); 
		pCheckBox->setCheckedImage(select1); 
		pCheckBox->setCheckedPressImage(select2); 
		pCheckBox->setDisabledNormalImage(disable1); 
		pCheckBox->setDisabledCheckedImage(disable2); 
	}
	pCheckBox->setRotation(rotation);
	pCheckBox->setPosition(Vec2(x,-y));
	pCheckBox->setTag(tag);
	return pCheckBox;
}

ArmatureBtn* TuiManager::createArmatureBtn(float tag,const char* name,const char* normal,const char* select, const char* png,const char* plist,const char* xml,float x,float y,float rotation){
	ArmatureDataManager::getInstance()->addArmatureFileInfo(png,plist,xml);
	ArmatureBtn *pArmBtn = ArmatureBtn::create(name);
	pArmBtn->setNormalAnimName(normal);
	pArmBtn->setSelectAnimName(select);
	Size size = pArmBtn->getContentSize();
	pArmBtn->setRotation(rotation);
	pArmBtn->setPosition(Vec2(x - size.width/2,-y - size.height/2));
	pArmBtn->setTag(tag);
	return pArmBtn;
}

NumericStepper* TuiManager::createNumStep(float tag, int isLongClickRun, int max, int min, int cur,int step, const char* lnormal, const char* lselect, const char* ldisable, const char* rnormal, const char* rselect, const char* rdisable, const char* stepBg, float x, float y, float rotation, int isUseFrame){
	NumericStepper* pNumStep = NULL;
	if(isUseFrame){
		pNumStep = NumericStepper::createSpriteFrameName(lnormal, lselect, ldisable, rnormal, rselect, rdisable, stepBg);
	}else{
		pNumStep = NumericStepper::create(lnormal,lselect,ldisable,rnormal,rselect,rdisable,stepBg);
	}
	Size size = pNumStep->getContentSize();
	pNumStep->setLimit(min, max);
	pNumStep->setValue(cur);
	pNumStep->setStep(step);
	pNumStep->setAutoRun(isLongClickRun == 1);
	pNumStep->setRotation(rotation);
	pNumStep->setPosition(Vec2(x,-y));
	pNumStep->setTag(tag);
	return pNumStep;
}

ParticleSystemQuad* TuiManager::createParticle(float tag,const char* plist,float x,float y){
	ParticleSystemQuad *pPartical = ParticleSystemQuad::create(plist);
	pPartical->setPosition(x,-y);
	pPartical->setTag(tag);
	return pPartical;
}

CTableView* TuiManager::createTableView(float tag, Color4B color, int dir, int num, int cellWidth, int cellHeight, float x, float y, float w, float h, float rotation){
	CTableView *pView = CTableView::create(Size(w,h));
	if (color.a != 0) pView->setBackgroundColor(color);
	pView->setAutoRelocate(true);
	pView->setRotation(rotation);
	pView->setDirection((CScrollViewDirection)dir);
	pView->setCountOfCell(num);
	pView->setSizeOfCell(Size(cellWidth, cellHeight));
	pView->setRotation(rotation);
	pView->setPosition(x,-y);
	pView->setTag(tag);
	return pView;
}

CGridView* TuiManager::createGridView(float tag, Color4B color, int column, int num, int cellWidth, int cellHeight, float x, float y, float w, float h, float rotation){
	CGridView* pView = CGridView::create(Size(w, h));
	if (color.a != 0) pView->setBackgroundColor(color);
	pView->setAutoRelocate(true);
	pView->setRotation(rotation);
	pView->setPosition(x, -y);
	pView->setColumns(column);
	pView->setCountOfCell(num);
	pView->setSizeOfCell(Size(cellWidth, cellHeight));
	pView->setTag(tag);
	return pView;
}

CPageView *TuiManager::createPageView(float tag, Color4B color, int dir, int num, float x, float y, float w, float h, float rotation){
	CPageView *pView = CPageView::create(Size(w, h));
	if (color.a != 0) pView->setBackgroundColor(color);
	pView->setAutoRelocate(true);
	pView->setRotation(rotation);
	pView->setDirection((CScrollViewDirection)dir);
	pView->setCountOfCell(num);
	pView->setSizeOfCell(Size(w, h));
	pView->setPosition(Vec2(x, -y));
	pView->setTag(tag);
	return pView;
}

CGridPageView* TuiManager::createGridPageView(float tag, Color4B color, int dir, int column, int row, int num, int cellWidth, int cellHeight, float x, float y, float w, float h, float rotation){
	CGridPageView *pView = CGridPageView::create(Size(w, h));
	if (color.a != 0) pView->setBackgroundColor(color);
	pView->setAutoRelocate(true);
	pView->setRotation(rotation);
	pView->setDirection((CScrollViewDirection)dir);
	pView->setCountOfCell(num);
	pView->setColumns(column);
	pView->setRows(row);
	pView->setSizeOfCell(Size(cellWidth, cellHeight));
	pView->setPosition(Vec2(x, -y));
	pView->setTag(tag);
	return pView;
}

CEditBox* TuiManager::createEditBox(float tag, const char* placeHolder, const char* file, int inputMode, int inputFlag, float x, float y, float w, float h, float rotation, int isUseFrame){
	CEditBox *pEditBox = NULL;
	if(isUseFrame){
		pEditBox = CEditBox::createWith9SpriteFrameName(Size(w,h),file);
	}else{
		pEditBox = CEditBox::createWith9Sprite(Size(w,h),file);
	}
	pEditBox->setPlaceHolder(placeHolder);
	pEditBox->setInputMode((CEditBox::InputMode)inputMode);
	pEditBox->setInputFlag((CEditBox::InputFlag)inputFlag);
	pEditBox->setRotation(rotation);
	pEditBox->setPosition(Vec2(x,-y));
	pEditBox->setTag(tag);
	return pEditBox;
}
CircleMenu *TuiManager::createCircleMenu(float tag, float x, float y, float w, float h, float rotation){
	CircleMenu *pMenu = CircleMenu::create(Size(w, h));
	pMenu->setRotation(rotation);
	pMenu->setPosition(Vec2(x, -y));
	pMenu->setTag(tag);
	return pMenu;
}

CTextRich *TuiManager::createTextRich(float tag, const char *text, int maxLen, float x, float y, float w, float h, float rotation, int isUseFrame){
	CTextRich *pTextRich = CTextRich::create();
	pTextRich->setMaxLineLength(maxLen);

	char* buf = new char[string(text).size() + 1];
	memcpy(buf, text, string(text).size() + 1);

	xml_document<> doc;
	doc.parse<0>(buf);
	
	for (xml_node<char> *item = doc.first_node("e"); item != NULL; item = item->next_sibling()){
		if (strcmp(item->first_attribute("type")->value(), kTuiControlLabel) == 0){ //label
			const char *text = item->first_attribute("text")->value();
			float textSize = 22;
			const char *fontName = "";
			int r = 255, g = 255, b = 255;
			if (item->first_attribute("size"))		textSize = atof(item->first_attribute("size")->value());
			if (item->first_attribute("font"))		fontName = item->first_attribute("font")->value();
			if (item->first_attribute("r"))			r = atoi(item->first_attribute("r")->value());
			if (item->first_attribute("g"))			g = atoi(item->first_attribute("g")->value());
			if (item->first_attribute("b"))			b = atoi(item->first_attribute("b")->value());
			pTextRich->insertElement(TuiUtil::replace_all(text, "\\n", "\n").c_str(), fontName, textSize, Color3B(r, g, b));

		}else if (strcmp(item->first_attribute("type")->value(), kTuiControlImage) == 0){//image
			const char *imgSrc = item->first_attribute("src")->value();
			int len = atoi(item->first_attribute("len")->value());
			if (isUseFrame){
				pTextRich->insertElement(CImageView::createWithSpriteFrameName(imgSrc), len);
			}else{
				pTextRich->insertElement(CImageView::create(imgSrc), len);
			}
		}else if (strcmp(item->first_attribute("type")->value(), kTuiControlAnim) == 0){//anim
			const char *name = item->first_attribute("name")->value();
			const char *plist = item->first_attribute("src")->value();
			int len = atoi(item->first_attribute("len")->value());
			Sprite *pAnim = createAnim(0, name, plist, 0, 0, 0);
			pTextRich->insertElement(pAnim, len);
		}
	}
	delete[] buf;

	pTextRich->reloadData();
	pTextRich->setAnchorPoint(Vec2(0, 1));
	pTextRich->setRotation(rotation);
	pTextRich->setPosition(Vec2(x, -y));
	pTextRich->setTag(tag);
	return pTextRich;
}

void TuiManager::loadXml(const string& path)
{
	if(m_DataMap.find(path) == m_DataMap.end())
	{
		string pathAbs = FileUtils::getInstance()->fullPathForFilename(path);
		m_DataMap[path] = FileUtils::getInstance()->getStringFromFile(pathAbs);
	}
}

void TuiManager::doAdapterResolution(Node* pScene){
	for (auto node : pScene->getChildren()) {
		CWidgetWindow *pWindow = dynamic_cast<CWidgetWindow*>(node);
		if (pWindow != nullptr){
			pWindow->setPosition(Arp(pWindow->getPosition()));
			for (auto child : pWindow->getChildren()) {
				child->setPosition(Arp(child->getPosition()));
			}
		}
	}
}
/************************************************************************/
//	GET/SET/IS
/************************************************************************/
void TuiManager::setAdaptResolution(bool b, float designWidth/* =800 */, float designHeight/* =480 */){
	m_isAdaptResolution = b;
	if (b){
		Size winSize = Director::getInstance()->getWinSize();
		Size desSize = Size(designWidth, designHeight);
		m_fScaleResolutionX = winSize.width / desSize.width;
		m_fScaleResolutionY = winSize.height / desSize.height;
	}
	else{
		m_fScaleResolutionX = 1.0f;
		m_fScaleResolutionY = 1.0f;
	}
}
