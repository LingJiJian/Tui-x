////////////////////////////////////////////////////////////////////
ExportElementXMLErrorStrings = {};
ExportElementXMLErrorStrings.kNoOpenedFla = "no opened fla document!";
ExportElementXMLErrorStrings.kNullDocument = "export error, empty document!";
ExportElementXMLErrorStrings.kNoSetScheme = "export error, no such scheme!";
ExportElementXMLErrorStrings.kCanNotFindLibraryItem = "can not find library item!";
/////////////////////////////////////////////////////////////////////
/*给函数原型增加一个extend函数，实现继承*/  
Function.prototype.extend = function(superClass){  
	if(typeof superClass !== 'function'){  
		throw new Error('fatal error:Function.prototype.extend expects a constructor of class');  
	}  

	var F = function(){}; //创建一个中间函数对象以获取父类的原型对象  
	F.prototype = superClass.prototype; //设置原型对象  
	this.prototype = new F(); //实例化F, 继承父类的原型中的属性和方法，而无需调用父类的构造函数实例化无关的父类成员  
	this.prototype.constructor = this; //设置构造函数指向自己  
	this.superClass = superClass; //同时，添加一个指向父类构造函数的引用，方便调用父类方法或者调用父类构造函数  

    return this;
};

/**
 @brief 打印
 @param str:string 字符串
 */
function trace( str ){
	fl.outputPanel.trace( str );
}

/** 清屏 */
function cls(){
	fl.outputPanel.clear();
}

/** 保留小数 */
function formatNumber( num, retain){
	retain = retain || 100;
	return Math.round(num * retain) / 100;
}

/** 转化boolean */
function formatBoolean(b){
	var ret = b == "true" ? 1 : 0;
	return ret;
}

/** 把一个库目录里的资源转换为资源的绝对目录 */
function getFilePathByLibraryPath( path ){
	if( path == null || path == "" || path == undefined ){
		alert( "getFilePathByLibraryPath 无效的参数" );
	}
	var lib = fl.getDocumentDOM().library;
	var item_index = lib.findItemIndex( path );
	if( item_index < 0 ){
		alert( ExportElementXMLErrorStrings.kCanNotFindLibraryItem + ": " + path );
	}
	var item = lib.items[item_index];
	var url = item.sourceFilePath;
	url = url.replace( "file:///", "" );
	url = url.replace( "|", ":" );
	//for ( var i in item ){
	//	trace( "" + i + "" + ":" + item[i] );
	//}
	//trace( "转换路径 " + path + "===>>" + url );
	return url;
}

/**
 @brief 获取当前文档的时间轴
 @return Timeline object
 */
getCurrentTimeline = function(){
	try{
		return fl.getDocumentDOM().getTimeline();
	}catch(e){
		alert( ExportElementXMLErrorStrings.kNoOpenedFla );
	}
	return null;
}

/** 
 @brief 判断一个帧是否是关键帧, 原理是每个关键帧总是一序列帧的第一帧
 @param frame:Frame object 帧对象
 @param frameIndex:int 该帧的索引号
 @return boolean
 */
isKeyFrame = function( frame, frameIndex ){
	if( !frame ) return false;
	if( frame.startFrame == frameIndex ){
		return true;
	}
	return false;
}

/**
 @brief 把某个图层的关键帧枚举出来
 @param layer: Layer object 图层对象
 @param startFrameIndex:int 起始帧数，不一定是从0开始
 @param endFrameIndex:int 结束帧数
 @return vector<int>: 范围[startFrameIndex,endFrameIndex)之间的关键帧索引号数组
 */
getKeyframeIndices = function(layer, startFrameIndex, endFrameIndex){
	if( !layer ) return [];
	var list = [];
	for (var frameIndex=startFrameIndex; frameIndex<endFrameIndex; frameIndex++){
		var frame = layer.frames[frameIndex];
		var isFirstFrame = (frameIndex == startFrameIndex);
		var isKeyframe = (isFirstFrame || frame.startFrame == frameIndex);
		if( isKeyframe ){
			list.push( frameIndex );
		}
	}
	return list;
}
/**
 @brief 获取某个图层的所有关键帧
 @param layer:Layer object 图层对象
 @return vector<Frame object>
 */
getKeyframeObjects = function( layer ){
	if( !layer ) return [];
	var list = [];
	var index = 0;
	for each( frame in layer.frames ){
		if( frame.startFrame == index ){
			list.push( frame );
		}
		index++;
	}
	return list;
}
/**
 @brief 获取一个帧上的所有元素
 @param frame:Frame object 帧对象
 @return vector<Element object> 该帧上的所有元素
 */
getElementObjects = function( frame ){
	if( !frame ) return [];
	return frame.elements;
}
/**
 @brief 获取元素的类型
 @param element:Element object 元素对象
 @return string 类型
 */
getElementType = function(element){
	if (!element) return '';

	var elementType = '';
	var libraryItem = element.libraryItem;
	// element.elementType: "shape", "text", "instance", or "shapeObj"
	// item.itemType: "undefined", "component", "movie clip", "graphic", "button", "folder", "font", "sound", "bitmap", "compiled clip", "screen", and "video".
	switch (element.elementType){
	case 'shape' :
		{
			//NOTE: a drawing object is both a group and a drawing object, so check it first
			elementType = element.isRectangleObject ? 'rectangle object'
						: element.isOvalObject ? 'oval object'
						: element.isDrawingObject ? 'drawing object'
						: element.isGroup ? 'group'
						: 'shape';
		}break;
	case 'shapeObj' :
		{
			elementType = 'shape object'; 
		}break;
	case 'text' :
		{
			elementType = 'text'; 
		}break;
	case 'instance' :
		{
			if (element.symbolType)
				elementType = element.symbolType;
			else if (libraryItem.itemType && libraryItem.itemType != 'undefined')
				elementType = libraryItem.itemType;
		}break;
	}
	return elementType;
}

/** 精减小数 */
roundToTwip = function(value){
	return Math.round(value*20) / 20;
}

/** 获取元素的x坐标 */
getX = function(element){
	return roundToTwip(element.transformX);
}

/** 获取元素的y坐标 */
getY = function(element){
	return roundToTwip(element.transformY);
}

/** 设置元素的x坐标 */
setX = function(element, x){
	element.transformX = x;
}

/** 设置元素的y坐标 */
setY = function(element, y){
	element.transformY = y;
}
/////////////////////////////////////////////////////////////////////
/* tag映射头文件 */
TH = function(){
	this.obj = {};			//实体
	this.nameSpaceDic = {};	//组件命名空间集
	this.xmlFile;			//fla文件路径
	this.parseContent = function(tagType){
		
		var sceneName = fl.getDocumentDOM().name.replace(".fla","").toUpperCase();
		
		if (tagType == "cpp"){
			var head = "#ifndef __TAG_"+sceneName+"_H__ \r\n#define __TAG_"+sceneName+"_H__ \r\n\r\n";
			var define = "#define PATH_"+sceneName+" "+"\""+this.xmlFile +"\""+ "\r\n\r\n";
			var middle = "";
			for(var frameName in this.nameSpaceDic){
				middle += "namespace "+frameName+" { \r\n";
				for(var controlName in this.obj){
					var item = this.obj[controlName];
					if(item["frameName"] == frameName){
						middle += "	static const int "+item["controlName"].toUpperCase()+" = "+item["index"]+" ;\r\n";
					}
				}
				middle += "} \r\n\r\n";
			}
			var tail = "#endif";
			return head + define + middle + tail;
			
		}else if(tagType == "lua"){
			
			var path = "PATH_"+sceneName.toUpperCase()+" = "+"\""+this.xmlFile +"\""+ "\r\n\r\n";
			var middle = path+"";
			for(var frameName in this.nameSpaceDic){
				middle += "Tag_"+sceneName.toLowerCase()+" = { \r\n";
				for(var controlName in this.obj){
					var item = this.obj[controlName];
					if(item["frameName"] == frameName){
						middle += item["controlName"].toUpperCase()+" = "+item["index"]+" ,\r\n";
					}
				}
				middle = middle.substring(0,middle.length - 3);
				middle += "} \r\n\r\n";
			}
			return  middle ;
		}
	}
}
/////////////////////////////////////////////////////////////////////
/** 默认的xml 节点名字 */
XMLNode = {};
XMLNode.root = "root";
XMLNode.control = "control";
XMLNode.scheme = "scheme";
/////////////////////////////////////////////////////////////////////
/** xml类 */
TXML = function( nodename ){
	/** 父节点 */
	this.parent = null;
	/** 子节点 */
	this.children = [];
	/** 所有需要输出的属性 */
	this.attributes = {};
	
	this.xml = "";
	//this.nodeName = nodename==null ? XMLNode.root : nodename;
	this.nodeName = nodename;
	
	this.init();
}

TXML.prototype.init = function(){
}

TXML.prototype.setNodeName = function( name ){
	this.nodeName = name;
}

TXML.prototype.getNodeName = function(){
	return this.nodeName;
}

TXML.prototype.addChild = function( o ){
	if( o ){
		o.parent = this;
		this.children.push( o );
	}
}

TXML.prototype.registerAttribute = function( k, v ){
	this.attributes[k] = v;
}

TXML.prototype.setAttribute = function( k, v ){
	if( this.attributes[k] == null ){
		alert( "没有属性: " + k );
	}
	this.attributes[k] = v;
}

TXML.prototype.getAttribute = function( k ){
	if( this.attributes[k] == null ){
		alert( "没有属性: " + k );
	}
	return this.attributes[k];
}

TXML.prototype.getTabCount = function(){
	if( this.parent != null ){
		return this.parent.getTabCount() + 1;
	}
	return 0;
}

TXML.prototype.pushXMLAttribution = function( key, value ){
	if( value == null ) return;
	var str = value.toString();
	if( str=="" ) return;
	this.xml += " " + key + "=" + "\"" + value + "\"";
}


TXML.prototype.pushXML = function( str ){
	this.xml += str;
}

TXML.prototype.outputControlXML = function(){
	//trace( "{" + "name" + ":" + this.attributes["name"] + "}" );
	for( k in this.attributes ){
		this.pushXMLAttribution( k, this.attributes[k] );
	}
}

TXML.prototype.outputChildrenXML = function(){
	for each( c in this.children ){
		//trace( "child: " + c.getAttribute( UIControlAttribute.kName ) + " parent: " + c.parent.getAttribute( UIControlAttribute.kName ) );
		c.outputXML();
		//trace( "child2: " + c.getAttribute( UIControlAttribute.kName ) + " parent: " + c.parent.getAttribute( UIControlAttribute.kName ) );
	}
}

TXML.prototype.outputTabXML = function(){
	var n = this.getTabCount();
	for( var i = 0; i<n; ++i ){
		this.pushXML( "\t" );
	}
}

TXML.prototype.outputXML = function(){
	//trace( "{" + "name" + ":" + this.attributes["name"] + "}" );
	this.outputTabXML(); 
	if(this.nodeName != ""){
		this.pushXML( "<" + this.nodeName ); this.outputControlXML(); this.pushXML( ">" );
	}
	if( this.children.length > 0 ){
		this.pushXML( "\n" );
	}
	this.outputChildrenXML();
	if( this.children.length > 0 ){
		this.outputTabXML(); 
	}
	if(this.nodeName != ""){
		this.pushXML( "</" + this.nodeName + ">\n" );
	}
	if( this.parent ){
		this.parent.pushXML( this.xml );
	}
	return this.xml;
}

UIXML = function(uiname){
	UIXML.superClass.call( this, uiname );
	
	//this.registerAttribute( "name", (uiname == null ? "uipanel" : uiname) );
}

UIXML.extend( TXML );
UIXML.prototype.init = function(){
	UIXML.superClass.prototype.init.call(this);

	//this.registerAttribute( "version", "1.0" );
}

/////////////////////////////////////////////////////////////////////
/** 支持的控件类型 */
UIControlType = {};
UIControlType.kPanel = "panel";
UIControlType.kMovie = "movie Clip";
UIControlType.kImage = "image";
UIControlType.kImage9 = "image9";
UIControlType.kButton = "button";
UIControlType.kSlider = "slider";
UIControlType.kProgress = "progress";
UIControlType.kLabel = "label";
UIControlType.kLabelAtlas = "labelAtlas";
UIControlType.kLabelBMFont = "labelBMFont";
UIControlType.kRichText = "richText";
UIControlType.kCheckBox = "checkBox";
UIControlType.kEditBox = "editBox";
UIControlType.kArmature = "armature";
UIControlType.kAnim = "anim";
UIControlType.kParticle = "particle";
UIControlType.kNumbericStepper = "numStep";
UIControlType.kArmatureBtn = "armatureBtn";
UIControlType.kControlView = "controlView";
UIControlType.kToggleView = "toggleView";
UIControlType.kListView = "listView";
UIControlType.kExpList = "expList";
UIControlType.kPageView = "pageView";
UIControlType.kTableView = "tableView";
UIControlType.kGridView = "gridView";
UIControlType.kScrollView = "scrollView";
UIControlType.kLayout = "layout";
UIControlType.kGridPageView = "gridPageView";
UIControlType.kMoiveView = "movieView";
UIControlType.kCircleMenu = "circleMenu";
UIControlType.kCell = "cell";
/////////////////////////////////////////////////////////////////////
/** 控件的属性 */
UIControlAttribute = {};
/** 控件的唯一标志(以场景为单位) */
UIControlAttribute.kTag = "tag";
/** 控件的类型 */
UIControlAttribute.kType = "type";
/** 控件的文本 */
UIControlAttribute.kText = "text";
/** item数量 */
UIControlAttribute.kNum = "num";
/** 控件文本尺寸 */
UIControlAttribute.kTextAlignment = "alignment";
UIControlAttribute.kTextSize = "textSize";
UIControlAttribute.kTextFont = "textFont";
UIControlAttribute.kPlaceHolder = "placeHolder";
UIControlAttribute.kTextRed = "red";
UIControlAttribute.kTextGreen = "green";
UIControlAttribute.kTextBlue = "blue";
UIControlAttribute.kTextAlpha = "alpha";
UIControlAttribute.kStrokeRed = "strokeRed";
UIControlAttribute.kStrokeGreen = "strokeGreen";
UIControlAttribute.kStrokeBlue = "strokeBlue";
UIControlAttribute.kStrokeSize = "strokeSize";
UIControlAttribute.kShadowDistance = "shadowDistance";
UIControlAttribute.kShadowBlur = "shadowBlur";
/** 滑块内部宽高*/
UIControlAttribute.kInnerWidth = "innerWidth";
UIControlAttribute.kInnerHeight = "innerHeight";
/** 控件的名字,在程序中控制用 */
UIControlAttribute.kName = "name";
/** 是否可托动 */
UIControlAttribute.kEnableDrag = "enable_drag";
/** 用到的图片 */
UIControlAttribute.kImage = "image";
/** 输入框 */
UIControlAttribute.kInputMode = "inputMode";
UIControlAttribute.kInputFlag = "inputFlag";
/** 9宫格方向 */
UIControlAttribute.kUp = "up";
UIControlAttribute.kDown = "down";
UIControlAttribute.kLeft = "left";
UIControlAttribute.kRight = "right";
/** 按钮的三个状态图 */
UIControlAttribute.kbtnImg_normal = "normal";
UIControlAttribute.kbtnImg_select = "select";
UIControlAttribute.kbtnImg_disable = "disable";
UIControlAttribute.kbtnImg_normal1 = "normal1";
UIControlAttribute.kbtnImg_select1 = "select1";
UIControlAttribute.kbtnImg_disable1 = "disable1";
UIControlAttribute.kbtnImg_normal2 = "normal2";
UIControlAttribute.kbtnImg_select2 = "select2";
UIControlAttribute.kbtnImg_disable2 = "disable2";
/** toggleView的排斥值 */
UIControlAttribute.kExclusion = "exclusion";
/** NumberStepper的两个按钮 */
UIControlAttribute.kbtn_lnormal = "lnormal";
UIControlAttribute.kbtn_lselect = "lselect";
UIControlAttribute.kbtn_ldisable = "ldisable";
UIControlAttribute.kbtn_rnormal = "rnormal";
UIControlAttribute.kbtn_rselect = "rselect";
UIControlAttribute.kbtn_rdisable = "rdisable";
UIControlAttribute.kstepbg = "stepBg";
/** 滑动条的三个图片 */
UIControlAttribute.ksliderImg_bg = "bg";
UIControlAttribute.ksliderImg_progress = "progress";
UIControlAttribute.ksliderImg_thumb = "thumb";
UIControlAttribute.ksliderMax = "max";
UIControlAttribute.ksliderMin = "min";
UIControlAttribute.ksliderCur = "cur";
UIControlAttribute.kShowLabel = "showLabel";
/** 文件 */
UIControlAttribute.karmature_xml = "xml";
UIControlAttribute.kPng = "png";
UIControlAttribute.kPlist = "plist";
UIControlAttribute.kJson = "json";
UIControlAttribute.kFnt = "fnt";
/** 纵列数 */
UIControlAttribute.kColumn = "column";
UIControlAttribute.kRow = "row";
/** Cell尺寸 */
UIControlAttribute.kCellWidth = "cellWidth";
UIControlAttribute.kCellHeight = "cellHeight";
/** 摇杆的两个图片 */
UIControlAttribute.kcontrol_baseboard = "baseboard";
UIControlAttribute.kcontrol_joystick = "joystick";
/** 坐标 */
UIControlAttribute.kX = "x";
UIControlAttribute.kY = "y";
UIControlAttribute.kZ = "z";
/** 中心点坐标 */
UIControlAttribute.kOriginX = "ox";
UIControlAttribute.kOriginY = "oy";
/** 宽高 */
UIControlAttribute.kWidth = "width";
UIControlAttribute.kHeight = "height";
/** 缩放 */
UIControlAttribute.kScaleX = "scaleX";
UIControlAttribute.kScaleY = "scaleY";
/** 翻转 */
UIControlAttribute.kFlipX = "flipX";
UIControlAttribute.kFlipY = "flipY";
/** 角度 */
UIControlAttribute.kRotation = "rotation";
/** 方向 */
UIControlAttribute.kDirection = "direction";
/** 是否使用SprieFrame */
UIControlAttribute.kSpriteFrame = "spriteFrame";
/** 初始化播放动作 */
UIControlAttribute.kPlay = "play";
/** 长按自增长 */
UIControlAttribute.kLongClickRun = "longClickRun";
UIControlAttribute.kStep = "step";

/**
 @brief 控件基类
 */
UIControl = function(){
	UIControl.superClass.call(this, XMLNode.control );
}

UIControl.extend( TXML );
UIControl.prototype.init = function(){
	for( k in UIControlAttribute ){
		this.registerAttribute( UIControlAttribute[k], "" );
	}
//	this.setNodeName( "control" );
}
/////////////////面板//////////////////////////////////////////////
UIPanel = function(){
	UIPanel.superClass.call(this);
}

UIPanel.extend( UIControl );
UIPanel.prototype.init = function(){
	UIPanel.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kPanel );
}
/////////////////////滑动条//////////////////////////////////////////
UISlider = function(){
	UISlider.superClass.call(this);
}
UISlider.extend( UIControl );
UISlider.prototype.init = function(){
	UISlider.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kSlider );
}
/////////////////////进度条//////////////////////////////////////////
UIProgress = function(){
	UIProgress.superClass.call(this);
}
UIProgress.extend( UIControl );
UIProgress.prototype.init = function(){
	UIProgress.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kProgress );
}
///////////////骨骼动画/////////////////////////////////////////////////
UIArmature = function(){
	UIArmature.superClass.call(this);
}
UIArmature.extend( UIControl );
UIArmature.prototype.init = function(){
	UIArmature.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kArmature );
}
/////////////逐帧动画/////////////////////////////////////////////////
UIAnim = function(){
	UIAnim.superClass.call(this);
}
UIAnim.extend( UIControl );
UIAnim.prototype.init = function(){
	UIAnim.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kAnim );
}
/////////////////////图片///////////////////////////////////////////
UIImage = function(){
	UIImage.superClass.call(this);
}
UIImage.extend( UIControl );
UIImage.prototype.init = function(){
	UIImage.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kImage );
}
/////////////////////9宫格图片///////////////////////////////////////////
UIImage9 = function(){
	UIImage9.superClass.call(this);
}
UIImage9.extend( UIControl );
UIImage9.prototype.init = function(){
	UIImage9.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kImage9 );
}
/////////////////////按钮/////////////////////////////////////////
UIButton = function(){
	UIButton.superClass.call(this);
}
UIButton.extend( UIControl );
UIButton.prototype.init = function(){
	UIButton.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kButton );
}
///////////////////checkBox///////////////////////////////////////////
UICheckBox = function(){
	UICheckBox.superClass.call(this);
}
UICheckBox.extend( UIControl );
UICheckBox.prototype.init = function(){
	UICheckBox.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kCheckBox );
}
///////////////////toggleView///////////////////////////////////////////
UIToggleView = function(){
	UIToggleView.superClass.call(this);
}
UIToggleView.extend( UIControl );
UIToggleView.prototype.init = function(){
	UIToggleView.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kToggleView );
}
///////////////////文本///////////////////////////////////////////
UILabel = function(){
	UILabel.superClass.call(this);
}
UILabel.extend( UIControl );
UILabel.prototype.init = function(){
	UILabel.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kLabel );
}
///////////////////数字文本///////////////////////////////////////////
UILabelAtlas = function(){
	UILabelAtlas.superClass.call(this);
}
UILabelAtlas.extend(UIControl);
UILabelAtlas.prototype.init = function(){
	UILabelAtlas.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kLabelAtlas );
}
///////////////////位图文本///////////////////////////////////////////
UILabelBMFont = function(){
	UILabelBMFont.superClass.call(this);
}
UILabelBMFont.extend(UIControl);
UILabelBMFont.prototype.init = function(){
	UILabelAtlas.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kLabelBMFont );
}
///////////////////摇杆//////////////////////////////////////////////
UIControlView = function(){
	UIControlView.superClass.call(this);
}
UIControlView.extend( UIControl );
UIControlView.prototype.init = function(){
	UIControlView.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kControlView );
}
/////////////////ListView//////////////////////////////////////////////
UIListView = function(){
	UIListView.superClass.call(this);
}
UIListView.extend( UIControl );
UIListView.prototype.init = function(){
	UIListView.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kListView );
}
/////////////////ExpList//////////////////////////////////////////////
UIExpList = function(){
	UIExpList.superClass.call(this);
}
UIExpList.extend( UIControl );
UIExpList.prototype.init = function(){
	UIListView.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kExpList );
}
/////////////////PageView//////////////////////////////////////////////
UIPageView = function(){
	UIPageView.superClass.call(this);
}
UIPageView.extend( UIControl );
UIPageView.prototype.init = function(){
	UIPageView.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kPageView );
}
/////////////////GridView//////////////////////////////////////////////
UIGridView = function(){
	UIGridView.superClass.call(this);
}
UIGridView.extend( UIControl );
UIGridView.prototype.init = function(){
	UIGridView.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kGridView );
}
/////////////////ArmatureBtn//////////////////////////////////////////////
UIArmatureBtn = function(){
	UIArmatureBtn.superClass.call(this);
}
UIArmatureBtn.extend( UIControl );
UIArmatureBtn.prototype.init = function(){
	UIArmatureBtn.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kArmatureBtn );
}
/////////////////NumbericStepper//////////////////////////////////////////////
UINumbericStepper = function(){
	UINumbericStepper.superClass.call(this);
}
UINumbericStepper.extend( UIControl );
UINumbericStepper.prototype.init = function(){
	UINumbericStepper.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kNumbericStepper );
}
/////////////////ScrollView//////////////////////////////////////////////
UIScrollView = function(){
	UIScrollView.superClass.call(this);
}
UIScrollView.extend( UIControl );
UIScrollView.prototype.init = function(){
	UIScrollView.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kScrollView );
}
/////////////////TableView//////////////////////////////////////////////
UITableView = function(){
	UITableView.superClass.call(this);
}
UITableView.extend( UIControl );
UITableView.prototype.init = function(){
	UITableView.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kTableView );
}
/////////////////Particle//////////////////////////////////////////////
UIParticle = function(){
	UIParticle.superClass.call(this);
}
UIParticle.extend( UIControl );
UIParticle.prototype.init = function(){
	UIParticle.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kParticle );
}
/////////////////EditBox//////////////////////////////////////////////
UIEditBox = function(){
	UIEditBox.superClass.call(this);
}
UIEditBox.extend( UIControl );
UIEditBox.prototype.init = function(){
	UIEditBox.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kEditBox );
}
/////////////////RichText//////////////////////////////////////////////
UIRichText = function(){
	UIRichText.superClass.call(this);
}
UIRichText.extend( UIControl );
UIRichText.prototype.init = function(){
	UIRichText.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kRichText );
}
/////////////////Layout//////////////////////////////////////////////
UILayout = function(){
	UILayout.superClass.call(this);
}
UILayout.extend( UIControl );
UILayout.prototype.init = function(){
	UILayout.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kLayout );
}
/////////////////MovieView//////////////////////////////////////////////
UIMovieView = function(){
	UIMovieView.superClass.call(this);
}
UIMovieView.extend( UIControl );
UIMovieView.prototype.init = function(){
	UIMovieView.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kMoiveView );
}
/////////////////CircleMenu//////////////////////////////////////////////
UICircleMenu = function(){
	UIMovieView.superClass.call(this);
}
UICircleMenu.extend( UIControl );
UICircleMenu.prototype.init = function(){
	UICircleMenu.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kCircleMenu );
}
/////////////////UIGridPageView//////////////////////////////////////////////
UIGridPageView = function(){
	UIMovieView.superClass.call(this);
}
UIGridPageView.extend( UIControl );
UIGridPageView.prototype.init = function(){
	UIGridPageView.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kGridPageView );
}
/////////////////Cell/////////////////////////////////////////////
UICell = function(){
	UICell.superClass.call(this);
}
UICell.extend( UIControl );
UICell.prototype.init = function(){
	UICell.superClass.prototype.init.call(this);
	this.setAttribute( UIControlAttribute.kType, UIControlType.kCell );
}
/////////////////////////////////////////////////////////////////////

ExportUITool = function(){
	this.xml = null;
}

/** 导出UI数据 */
ExportUITool.prototype.exportUIXML = function( doc ){
	if( !doc ){
		alert( ExportElementXMLErrorStrings.kNullDocument );
		return null;
	}

	//取得时间轴,遍历图层
	var timeline = doc.getTimeline();
	var layerindex = 0;
	for each( layer in timeline ){
		this.exportLayer( layer, layerindex++ );
	}
	//trace( this.xml );
	//trace( this.xml.outputXML() );
}

/** 导出一个图层的数据 */
ExportUITool.prototype.exportLayer = function( layer, layerIndex ){
	var frameindex = 0;
	for each( frame in layer ){
		this.exportFrame( frame, frameindex++ );
	}
}

/** 导出一帧的数据 */
ExportUITool.prototype.exportFrame = function( frame, frameIndex ){
	var elementindex = 0;
	for each( element in frame ){
		this.exportElement( element, elementindex );
	}
}

/** 导出一帧的元素 */
ExportUITool.prototype.exportElement = function( element ){
	//判断是什么类型的元素，导出相应元素	
}

/** 导出一个MovieClip的数据 */
ExportUITool.prototype.exprotMovieClip = function( mc ){

}

/////////////////////////////////////////////////////////////////////
/** 
 @brief 把fla文件转换为xml
 */
kExportLayerCurrent = 0; //导出当前层
kExportLayerVisible = 1; //导出可见层
kExportLayerAll = 2;	 //导出所有层

FlaToXML = function(){
	/** TXML,保存xml */
	this.txml = null;
	/** 当前处理的fla文件, Document Object */
	this.obj_fla = null;
	/** TH,保存文件 */
	this.th = null;
	
	/** 导出哪些层,默认为导出所有层 */
	this.export_layer_type = kExportLayerAll;
	
	this.init();
}

FlaToXML.prototype.init = function(){}	//初始化
FlaToXML.prototype.cid = 1;				//组件id(tag)
/**
 @brief 设置导出哪些层
 @param v{ kExportLayerCurrent, kExportLayerVisible, kExportLayerAll }
 */
FlaToXML.prototype.setExportLayerType = function( v ){
	this.export_layer_type = v;
}

FlaToXML.prototype.isExportLayerCurrent = function(){
	return this.export_layer_type == kExportLayerCurrent;
}

FlaToXML.prototype.isExportLayerVisible = function(){
	return this.export_layer_type == kExportLayerVisible;
}

FlaToXML.prototype.isExportLayerAll = function(){
	return this.export_layer_type == kExportLayerAll;
}

/** 判断element是否为movie clip */
FlaToXML.prototype.elementIsMc = function( element ){
	if(element.libraryItem == null) return false;
	var type = element.libraryItem.itemType;
	if( "movie clip" == type ) return true;
	return false;
}

/** 判断element是否为label */
FlaToXML.prototype.elementIsText = function(element){
	return (element.elementType == "text");
}

/** 获取element的xml类型 */
FlaToXML.prototype.getElementUIType = function( element ){
	if( this.elementIsMc( element ) ) return UIControlType.kMovie;
	if( this.elementIsButton( element ) ) return UIControlType.kButton;
	return "undefined";
}

/** 
 @brief 把objfla:Document Object转换为xmlfile:string xml文件 
 @param objfla:Document Object
 @param xmlfile:string 目标文件名
 */
FlaToXML.prototype.convert = function( objfla, xmlfile, uiname ){
	if( objfla == null ){
		alert( ExportElementXMLErrorStrings.kNoOpenedFla );
	}
	this.obj_fla = objfla;
	this.txml = new UIXML( uiname );
	
	this.th = new TH();
	
	if( xmlfile == "" || xmlfile == null ){
		xmlfile = "tui_"+objfla.name.split(".")[0] + ".xml";
	}
	
	var flaname = this.obj_fla.name;
	trace( "FlaToXML: 开始转换fla[" + flaname + "]文件为xml:[" + xmlfile + "] ui文件" );
	
	if( this.isExportLayerCurrent() ){
		//导出当前层
		var timeline = objfla.getTimeline();
		if( timeline.currentLayer < 0 || timeline.currentLayer == undefined ){
			//alert( "当前没有选中的图层!" );
			return;
		}
		var current_layer_index = timeline.currentLayer;
		trace( "当前选中的是第" + timeline.currentLayer + "层" );
		var layer = timeline.layers[current_layer_index];
		this.fetchElementFromLayer( layer, current_layer_index, this.txml );

	}else if( this.isExportLayerVisible() ){
		//导出可见层
		var nlayer = objfla.getTimeline().layerCount;
		for( var layer_index = nlayer-1; layer_index >= 0; --layer_index ){
			var layer = objfla.getTimeline().layers[layer_index];
			if( layer.visible ){
				this.fetchElementFromLayer( layer, layer_index, this.txml );
			}
		}
		
	}else{
		//导出全部
		this.fetchElement( objfla.getTimeline(), this.txml );		
	}
	this.outputXML();
}

/** 转换元素为UICnotrol */
FlaToXML.prototype.convertElement = function( element ,tag ,frameName ){
	var e_xml = null;

	if( this.elementIsMc( element ) ){
		e_xml = this.convertMC( element ,tag ,frameName);
	}else if(element.instanceType == "symbol"){
		if(element.libraryItem && element.libraryItem.itemType == "component"){
			e_xml = this.convertMC( element ,tag ,frameName);
		}
	}else if( this.elementIsText( element )){
		e_xml = this.convertText( element,tag ,frameName);
	}else if(element.instanceType == "bitmap"){
		//bitmap 不处理
	}else{
		if(element.libraryItem && element.libraryItem.itemType){
			trace( "未知的类型: " + element.instanceType + " " + element.libraryItem );
		}
	}
	return e_xml;
}

/** 填充一般属性 */
FlaToXML.prototype.fullNormalAttirbute = function( xml,th, element ,tag,frameName){
	
	//var ox = element.x - element.left;
	//var oy = element.y - element.top;
	//xml.setAttribute( UIControlAttribute.kOriginX, formatNumber(ox) );
	//xml.setAttribute( UIControlAttribute.kOriginY, formatNumber(oy) );
	
	//xml.setAttribute( UIControlAttribute.kName,element.name);
	xml.setAttribute( UIControlAttribute.kX, formatNumber( element.x ) );
	xml.setAttribute( UIControlAttribute.kY, formatNumber( element.y) );
	if(element.parameters && element.parameters.spriteFrame){
		xml.setAttribute( UIControlAttribute.kSpriteFrame, formatBoolean(element.parameters.spriteFrame.value));
	}
	xml.setAttribute( UIControlAttribute.kRotation, formatNumber(element.rotation) );
	
	th.obj[element.name] = {"controlName":element.name,"index":tag,"frameName":frameName};

	xml.setAttribute( UIControlAttribute.kWidth, formatNumber(element.width) );
	xml.setAttribute( UIControlAttribute.kHeight, formatNumber(element.height) );
	xml.setAttribute( UIControlAttribute.kTag, formatNumber(tag));
}
/** 转换movie clip 或 组件 */
FlaToXML.prototype.convertMC = function( mc ,tag ,frameName){
	var control_xml = null;
	switch(mc.name.split("_")[0]){//获取mc的类型
		case "panel":		control_xml = this.convertPanel(mc,tag ,frameName);				break;
		case "layout":		control_xml = this.convertLayout(mc,tag ,frameName);			break;
		case "img":			control_xml = this.convertImg(mc,tag ,frameName);				break;
		case "img9":		control_xml = this.convertImg9(mc,tag ,frameName);				break;
		case "ckb":			control_xml = this.convertCheckBox(mc,tag ,frameName);			break;
		case "slider":		control_xml = this.convertSlider(mc,tag ,frameName);			break;
		case "prog":		control_xml = this.converProgress(mc,tag ,frameName);			break;
		case "armature":	control_xml = this.convertArmature(mc,tag ,frameName);			break;
		case "anim":		control_xml = this.convertAnim(mc,tag ,frameName);				break;
		case "ctlv":		control_xml = this.convertControlView(mc,tag ,frameName);		break;
		case "tgv":			control_xml = this.convertToggleView(mc,tag ,frameName);		break;
		case "list":		control_xml = this.convertListView(mc,tag ,frameName);			break;
		case "pv":			control_xml = this.convertPageView(mc,tag ,frameName);			break;
		case "scrol":		control_xml = this.convertScrollView(mc,tag ,frameName);		break;
		case "gv":			control_xml = this.convertGridView(mc,tag ,frameName);			break;
		case "gpv":			control_xml = this.convertGridPageView(mc,tag ,frameName);		break;
		case "labAtlas":	control_xml = this.convertLabAtlas(mc,tag ,frameName);			break;
		case "labBmf":		control_xml = this.convertLabBmf(mc,tag ,frameName);  			break;
		case "armBtn":		control_xml = this.convertArmatureBtn(mc,tag ,frameName);		break;
		case "btn":			control_xml = this.convertButton(mc,tag ,frameName);			break;
		case "numStep":		control_xml = this.convertNumberStepper(mc,tag ,frameName);		break;
		case "ptl":			control_xml = this.convertParticle(mc,tag ,frameName);			break;
		case "tbl":			control_xml = this.convertTableView(mc,tag ,frameName);			break;
		case "edit":		control_xml = this.convertEditBox(mc,tag ,frameName);			break;
		case "rtf":			control_xml = this.convertRichText(mc,tag ,frameName);			break;
		//case "movie":		control_xml = this.convertMovie(mc,tag ,frameName);				break;
		case "circlemenu":	control_xml = this.convertCirclemenu(mc,tag ,frameName);		break;
		case "cell":		control_xml = this.convertCell(mc,tag ,frameName);				break;
		case "expList":		control_xml = this.convertExpList(mc,tag ,frameName);			break;
	}
	return control_xml;
}

/** 转换panel */
FlaToXML.prototype.convertPanel = function(panel,tag ,frameName){
	var panel_xml = new UIPanel();
	panel_xml.setAttribute(UIControlAttribute.kName,panel.name);
	this.fullNormalAttirbute( panel_xml,this.th, panel, tag ,frameName);
	//获取mc的timeline
	var timeline = panel.libraryItem.timeline;
	this.fetchElement( timeline, panel_xml ,frameName);

	return panel_xml;
}
/** 转换Layout */
FlaToXML.prototype.convertLayout = function(layout,tag ,frameName){
	var xml_Layout = new UILayout();
	var params = layout.parameters;
	xml_Layout.setAttribute(UIControlAttribute.kTextAlpha,params.bgAlpha.value);
	xml_Layout.setAttribute(UIControlAttribute.kTextRed,parseInt(params.bgColor.value.substr(1,2),16));
	xml_Layout.setAttribute(UIControlAttribute.kTextGreen,parseInt(params.bgColor.value.substr(3,2),16));
	xml_Layout.setAttribute(UIControlAttribute.kTextBlue,parseInt(params.bgColor.value.substr(5,2),16));
	
	this.fullNormalAttirbute( xml_Layout,this.th, layout ,tag ,frameName);
	//获取mc的timeline
	var timeline = layout.libraryItem.timeline;
	this.fetchElement( timeline, xml_Layout,frameName);
	return xml_Layout;
}
/** 转换Cell */
FlaToXML.prototype.convertCell = function(cell,tag ,frameName){
	var xml_cell = new UICell();
	xml_cell.setAttribute(UIControlAttribute.kName,cell.name);
	this.fullNormalAttirbute(xml_cell,this.th,cell,tag ,frameName);
	//获取mc的timeline
	var timeline = cell.libraryItem.timeline;
	this.fetchElement( timeline, xml_cell,frameName );
	return xml_cell;
}
/** 转换image */
FlaToXML.prototype.convertImg = function( image , tag ,frameName){
	var suffix = ".png"
	if(image.parameters.suffix != null){
		suffix = image.parameters.suffix.value;
	}
	var xml_img = new UIImage();
	xml_img.setAttribute( UIControlAttribute.kScaleX,formatNumber(image.scaleX));
	xml_img.setAttribute( UIControlAttribute.kScaleY,formatNumber(image.scaleY));
	xml_img.setAttribute( UIControlAttribute.kFlipX,formatBoolean(image.parameters.flipX.value));
	xml_img.setAttribute( UIControlAttribute.kFlipY,formatBoolean(image.parameters.flipY.value));
	xml_img.setAttribute( UIControlAttribute.kImage, image.libraryItem.name + suffix );
	
	this.fullNormalAttirbute( xml_img,this.th, image ,tag ,frameName);
	return xml_img;
}
/** 转换image9 */
FlaToXML.prototype.convertImg9 = function( image9 , tag ,frameName){
	var xml_img9 = new UIImage9();
	xml_img9.setAttribute( UIControlAttribute.kUp,image9.parameters.up.value);
	xml_img9.setAttribute( UIControlAttribute.kDown,image9.parameters.down.value);
	xml_img9.setAttribute( UIControlAttribute.kLeft,image9.parameters.left.value);
	xml_img9.setAttribute( UIControlAttribute.kRight,image9.parameters.right.value);
	xml_img9.setAttribute( UIControlAttribute.kImage, image9.libraryItem.name + ".png" );

	this.fullNormalAttirbute( xml_img9,this.th, image9 ,tag ,frameName);
	return xml_img9;
}
/** 转换anim */
FlaToXML.prototype.convertAnim = function(anim ,tag ,frameName){
	var xml_anim = new UIAnim();
	xml_anim.setAttribute(UIControlAttribute.kName,anim.name);
	xml_anim.setAttribute(UIControlAttribute.kPlist,anim.libraryItem.name + ".plist");
	xml_anim.setAttribute(UIControlAttribute.kPng,anim.libraryItem.name + ".png");
	this.fullNormalAttirbute( xml_anim,this.th, anim ,tag ,frameName);
	return xml_anim;
}
/** 转换button */
FlaToXML.prototype.convertButton = function( button ,tag ,frameName){
	var xml_btn = new UIButton();
	var params = button.parameters;
	xml_btn.setAttribute( UIControlAttribute.kText, params.lab.value );
	xml_btn.setAttribute( UIControlAttribute.kTextSize, params.fontSize.value );
	xml_btn.setAttribute( UIControlAttribute.kTextFont, params.fontName.value );
	xml_btn.setAttribute( UIControlAttribute.kTextRed,parseInt(params.color.value.substr(1,2),16));
	xml_btn.setAttribute( UIControlAttribute.kTextGreen,parseInt(params.color.value.substr(3,2),16));
	xml_btn.setAttribute( UIControlAttribute.kTextBlue,parseInt(params.color.value.substr(5,2),16));
	xml_btn.setAttribute( UIControlAttribute.kbtnImg_normal, button.libraryItem.name + "_normal.png" );
	xml_btn.setAttribute( UIControlAttribute.kbtnImg_select, button.libraryItem.name + "_select.png" );
	xml_btn.setAttribute( UIControlAttribute.kbtnImg_disable, button.libraryItem.name + "_disable.png" );
	this.fullNormalAttirbute( xml_btn,this.th, button ,tag ,frameName);
	return xml_btn;
}
/** 转换checkBox */
FlaToXML.prototype.convertCheckBox = function(checkBox,tag ,frameName){
	var xml_checkBox = new UICheckBox();
	this.fullNormalAttirbute( xml_checkBox,this.th, checkBox ,tag ,frameName);
	xml_checkBox.setAttribute( UIControlAttribute.kbtnImg_normal1, checkBox.libraryItem.name + "_normal1.png" );
	xml_checkBox.setAttribute( UIControlAttribute.kbtnImg_normal2, checkBox.libraryItem.name + "_normal2.png" );
	xml_checkBox.setAttribute( UIControlAttribute.kbtnImg_select1, checkBox.libraryItem.name + "_select1.png" );
	xml_checkBox.setAttribute( UIControlAttribute.kbtnImg_select2, checkBox.libraryItem.name + "_select2.png" );
	xml_checkBox.setAttribute( UIControlAttribute.kbtnImg_disable1, checkBox.libraryItem.name + "_disable1.png" );
	xml_checkBox.setAttribute( UIControlAttribute.kbtnImg_disable2, checkBox.libraryItem.name + "_disable2.png" );
	return xml_checkBox;
}
/** 转换slider */
FlaToXML.prototype.convertSlider = function(slider,tag ,frameName){
	var xml_slider = new UISlider();
	xml_slider.setAttribute(UIControlAttribute.ksliderMax,slider.parameters.maxValue.value);
	xml_slider.setAttribute(UIControlAttribute.ksliderMin,slider.parameters.minValue.value);
	xml_slider.setAttribute(UIControlAttribute.ksliderCur,slider.parameters.value.value);
	xml_slider.setAttribute(UIControlAttribute.ksliderImg_bg,slider.libraryItem.name + "_bg.png");
	xml_slider.setAttribute(UIControlAttribute.ksliderImg_progress,slider.libraryItem.name + "_progress.png");
	xml_slider.setAttribute(UIControlAttribute.ksliderImg_thumb,slider.libraryItem.name + "_thumb.png");
	this.fullNormalAttirbute( xml_slider,this.th, slider ,tag ,frameName);
	return xml_slider;
}
/** 转换progress */
FlaToXML.prototype.converProgress = function(prog,tag ,frameName){
	var xml_prog = new UIProgress();
	var params = prog.parameters;
	xml_prog.setAttribute(UIControlAttribute.ksliderMax,params.maxValue.value);
	xml_prog.setAttribute(UIControlAttribute.ksliderMin,params.minValue.value);
	xml_prog.setAttribute(UIControlAttribute.ksliderCur,params.value.value);
	xml_prog.setAttribute(UIControlAttribute.kShowLabel,formatBoolean(params.showLabel.value));
	xml_prog.setAttribute(UIControlAttribute.ksliderImg_bg,prog.libraryItem.name + "_bg.png");
	xml_prog.setAttribute(UIControlAttribute.ksliderImg_progress,prog.libraryItem.name + "_progress.png");
	this.fullNormalAttirbute( xml_prog,this.th, prog ,tag ,frameName);
	return xml_prog;
}
/** 转换armature */
FlaToXML.prototype.convertArmature = function(armature,tag ,frameName){
	var xml_armature = new UIArmature();
	this.fullNormalAttirbute( xml_armature, this.th,armature ,tag ,frameName);
	xml_armature.setAttribute(UIControlAttribute.kName,armature.name);
	xml_armature.setAttribute(UIControlAttribute.kPlay,armature.parameters.play.value);
	xml_armature.setAttribute(UIControlAttribute.karmature_xml,armature.libraryItem.name + ".xml");
	xml_armature.setAttribute(UIControlAttribute.kPng,armature.libraryItem.name + ".png");
	xml_armature.setAttribute(UIControlAttribute.kPlist,armature.libraryItem.name + ".plist");
	return xml_armature;
}
/** 转换label */
FlaToXML.prototype.convertText = function(label,tag ,frameName){
	var xml_label = new UILabel();
	this.fullNormalAttirbute( xml_label,this.th, label ,tag ,frameName);
	//for(var k in label.textRuns[0].textAttrs){
	//	trace("key:"+k + "  "+label.textRuns[0].textAttrs[k]);
	//}
var align = 1;
switch(label.textRuns[0].textAttrs.alignment){
	case "left": 	align = 0; break;
	case "center": 	align = 1; break;
	case "right": 	align = 2; break;
}

var strokeSize = 0;
var shadowBlur = 0;
var shadowDistance = 0;
var r2=0;var g2=0;var b2=0;
if(label.filters != undefined){
	for(var k in label.filters){
		var itemFilter = label.filters[k];
		if(itemFilter.name == "glowFilter"){//描边
			strokeSize = (itemFilter.blurX + itemFilter.blurY) / 2;
			var strokeColor = itemFilter.color;
			r2 = parseInt(strokeColor.substr(1,2),16);
			g2 = parseInt(strokeColor.substr(3,2),16);
			b2 = parseInt(strokeColor.substr(5,2),16);
		}
		if(itemFilter.name == "dropShadowFilter"){//阴影
			shadowBlur = (itemFilter.blurX + itemFilter.blurY) / 2;
			shadowDistance = itemFilter.distance;
		}
	}
}
	var fontFile = "fonts/"+label.textRuns[0].textAttrs.face.replace("-","/").replace("*","")+".ttf";

	var text = "";
	for(var j=0; j<label.textRuns.length; j++){
		var item = label.textRuns[j];
		for(var i=0; i<item.characters.length; i++){
			text += item.characters[i];
		}
	}
	var hexColor = label.textRuns[0].textAttrs.fillColor;
	
	var r = parseInt(hexColor.substr(1,2),16);
	var g = parseInt(hexColor.substr(3,2),16);
	var b = parseInt(hexColor.substr(5,2),16);
	xml_label.setAttribute(UIControlAttribute.kTextAlignment,align);
	xml_label.setAttribute(UIControlAttribute.kText,text);
	xml_label.setAttribute(UIControlAttribute.kTextSize,label.textRuns[0].textAttrs.size);
	xml_label.setAttribute(UIControlAttribute.kTextFont,fontFile);
	xml_label.setAttribute(UIControlAttribute.kTextRed,r);
	xml_label.setAttribute(UIControlAttribute.kTextGreen,g);
	xml_label.setAttribute(UIControlAttribute.kTextBlue,b);
	//描边和阴影
	xml_label.setAttribute(UIControlAttribute.kStrokeRed,r2);
	xml_label.setAttribute(UIControlAttribute.kStrokeGreen,g2);
	xml_label.setAttribute(UIControlAttribute.kStrokeBlue,b2);
	xml_label.setAttribute(UIControlAttribute.kStrokeSize,strokeSize);
	xml_label.setAttribute(UIControlAttribute.kShadowDistance,shadowDistance);
	xml_label.setAttribute(UIControlAttribute.kShadowBlur,shadowBlur);
	return xml_label;
}
/** 转换LabelAtlas */
FlaToXML.prototype.convertLabAtlas = function(labAtlas,tag ,frameName){
	var xml_labAtlas = new UILabelAtlas();
	var imgPath = labAtlas.libraryItem.name + ".png";
	xml_labAtlas.setAttribute( UIControlAttribute.kImage, imgPath );
	xml_labAtlas.setAttribute( UIControlAttribute.kNum, labAtlas.parameters.num.value);
	this.fullNormalAttirbute( xml_labAtlas,this.th,labAtlas ,tag ,frameName);
	return xml_labAtlas;
}
/** 转换LabelBMFont */
FlaToXML.prototype.convertLabBmf = function(labBmfont,tag ,frameName){
	var xml_labBmf = new UILabelBMFont();
	xml_labBmf.setAttribute( UIControlAttribute.kText, labBmfont.parameters.text.value);
	xml_labBmf.setAttribute( UIControlAttribute.kFnt,labBmfont.libraryItem.name + ".fnt")
	this.fullNormalAttirbute( xml_labBmf,this.th,labBmfont ,tag ,frameName);
	return xml_labBmf;
}
/** 转换controlView */
FlaToXML.prototype.convertControlView = function(control,tag ,frameName){
	var xml_control = new UIControlView();
	xml_control.setAttribute(UIControlAttribute.kcontrol_baseboard,control.libraryItem.name + "_baseboard.png");
	xml_control.setAttribute(UIControlAttribute.kcontrol_joystick,control.libraryItem.name + "_joystick.png");
	this.fullNormalAttirbute( xml_control,this.th, control ,tag ,frameName);
	return xml_control;
}
/** 转换toggleView */
FlaToXML.prototype.convertToggleView = function(toggleView,tag ,frameName){
	var xml_toggleView = new UIToggleView();
	xml_toggleView.setAttribute(UIControlAttribute.kExclusion,toggleView.parameters.exclusion.value);
	xml_toggleView.setAttribute( UIControlAttribute.kbtnImg_normal, toggleView.libraryItem.name + "_normal.png" );
	xml_toggleView.setAttribute( UIControlAttribute.kbtnImg_select, toggleView.libraryItem.name + "_select.png" );
	xml_toggleView.setAttribute( UIControlAttribute.kbtnImg_disable, toggleView.libraryItem.name + "_disable.png" );
	this.fullNormalAttirbute( xml_toggleView, this.th,toggleView ,tag ,frameName);
	return xml_toggleView;
}
/** 转换listView */
FlaToXML.prototype.convertListView = function(listView,tag ,frameName){
	var xml_listView = new UIListView();
	var params = listView.parameters;
	xml_listView.setAttribute(UIControlAttribute.kNum,params.num.value);
	xml_listView.setAttribute(UIControlAttribute.kTextAlpha,params.bgAlpha.value);
	xml_listView.setAttribute(UIControlAttribute.kTextRed,parseInt(params.bgColor.value.substr(1,2),16));
	xml_listView.setAttribute(UIControlAttribute.kTextGreen,parseInt(params.bgColor.value.substr(3,2),16));
	xml_listView.setAttribute(UIControlAttribute.kTextBlue,parseInt(params.bgColor.value.substr(5,2),16));
	
	this.fullNormalAttirbute( xml_listView,this.th, listView ,tag ,frameName);

	//获取mc的timeline
	var timeline = listView.libraryItem.timeline;
	this.fetchElement( timeline, xml_listView , frameName);
	return xml_listView;
}
/** 转换expListView */
FlaToXML.prototype.convertExpList = function(expList,tag ,frameName){
	var xml_expList = new UIExpList();
	var params = expList.parameters;
	xml_expList.setAttribute(UIControlAttribute.kNum,params.num.value);
	xml_expList.setAttribute(UIControlAttribute.kTextAlpha,params.bgAlpha.value);
	xml_expList.setAttribute(UIControlAttribute.kTextRed,parseInt(params.bgColor.value.substr(1,2),16));
	xml_expList.setAttribute(UIControlAttribute.kTextGreen,parseInt(params.bgColor.value.substr(3,2),16));
	xml_expList.setAttribute(UIControlAttribute.kTextBlue,parseInt(params.bgColor.value.substr(5,2),16));
	
	this.fullNormalAttirbute( xml_expList,this.th, expList ,tag ,frameName);

	//获取mc的timeline
	var timeline = expList.libraryItem.timeline;
	this.fetchElement( timeline, xml_expList , frameName);
	return xml_expList;
}
/** 转换pageView  */
FlaToXML.prototype.convertPageView = function(pageView,tag ,frameName){
	var xml_pageView = new UIPageView();
	var params = pageView.parameters;
	xml_pageView.setAttribute(UIControlAttribute.kTextAlpha,params.bgAlpha.value);
	xml_pageView.setAttribute(UIControlAttribute.kTextRed,parseInt(params.bgColor.value.substr(1,2),16));
	xml_pageView.setAttribute(UIControlAttribute.kTextGreen,parseInt(params.bgColor.value.substr(3,2),16));
	xml_pageView.setAttribute(UIControlAttribute.kTextBlue,parseInt(params.bgColor.value.substr(5,2),16));
	
	xml_pageView.setAttribute(UIControlAttribute.kDirection,params.dir.listIndex);
	xml_pageView.setAttribute(UIControlAttribute.kNum,params.num.value);

	this.fullNormalAttirbute( xml_pageView,this.th, pageView ,tag ,frameName);
	return xml_pageView;
}
/** 转换tableView */
FlaToXML.prototype.convertTableView = function(tableView,tag ,frameName){
	var xml_tableView = new UITableView();
	var params = tableView.parameters;
	xml_tableView.setAttribute(UIControlAttribute.kTextAlpha,params.bgAlpha.value);
	xml_tableView.setAttribute(UIControlAttribute.kTextRed,parseInt(params.bgColor.value.substr(1,2),16));
	xml_tableView.setAttribute(UIControlAttribute.kTextGreen,parseInt(params.bgColor.value.substr(3,2),16));
	xml_tableView.setAttribute(UIControlAttribute.kTextBlue,parseInt(params.bgColor.value.substr(5,2),16));
	
	xml_tableView.setAttribute(UIControlAttribute.kDirection,params.dir.listIndex);
	xml_tableView.setAttribute(UIControlAttribute.kNum,params.num.value);
	xml_tableView.setAttribute(UIControlAttribute.kCellWidth,params.cellWidth.value);
	xml_tableView.setAttribute(UIControlAttribute.kCellHeight,params.cellHeight.value);

	this.fullNormalAttirbute( xml_tableView,this.th, tableView ,tag ,frameName);
	return xml_tableView;
}
/** 转换gridView */
FlaToXML.prototype.convertGridView = function(gridView,tag,frameName){
	var xml_gridView = new UIGridView();
	var params = gridView.parameters;
	xml_gridView.setAttribute(UIControlAttribute.kTextAlpha,params.bgAlpha.value);
	xml_gridView.setAttribute(UIControlAttribute.kTextRed,parseInt(params.bgColor.value.substr(1,2),16));
	xml_gridView.setAttribute(UIControlAttribute.kTextGreen,parseInt(params.bgColor.value.substr(3,2),16));
	xml_gridView.setAttribute(UIControlAttribute.kTextBlue,parseInt(params.bgColor.value.substr(5,2),16));
	
	xml_gridView.setAttribute(UIControlAttribute.kColumn,params.col.value);
	xml_gridView.setAttribute(UIControlAttribute.kNum,params.num.value);
	xml_gridView.setAttribute(UIControlAttribute.kCellWidth,params.cellWidth.value);
	xml_gridView.setAttribute(UIControlAttribute.kCellHeight,params.cellHeight.value);

	this.fullNormalAttirbute(xml_gridView,this.th, gridView,tag ,frameName);
	return xml_gridView;
}
/** 转换GridPageView */
FlaToXML.prototype.convertGridPageView = function(gridPageView,tag,frameName){
	var xml_gridPageView = new UIGridPageView();
	var params = gridPageView.parameters;
	xml_gridPageView.setAttribute(UIControlAttribute.kTextAlpha,params.bgAlpha.value);
	xml_gridPageView.setAttribute(UIControlAttribute.kTextRed,parseInt(params.bgColor.value.substr(1,2),16));
	xml_gridPageView.setAttribute(UIControlAttribute.kTextGreen,parseInt(params.bgColor.value.substr(3,2),16));
	xml_gridPageView.setAttribute(UIControlAttribute.kTextBlue,parseInt(params.bgColor.value.substr(5,2),16));
	
	xml_gridPageView.setAttribute(UIControlAttribute.kDirection,params.dir.listIndex);
	xml_gridPageView.setAttribute(UIControlAttribute.kColumn,params.col.value);
	xml_gridPageView.setAttribute(UIControlAttribute.kRow,params.row.value);
	xml_gridPageView.setAttribute(UIControlAttribute.kNum,params.num.value);
	xml_gridPageView.setAttribute(UIControlAttribute.kCellWidth,params.cellWidth.value);
	xml_gridPageView.setAttribute(UIControlAttribute.kCellHeight,params.cellHeight.value);
	
	this.fullNormalAttirbute(xml_gridPageView,this.th, gridPageView,tag ,frameName);
	return xml_gridPageView;
}
/** 转换armatureBtn */
FlaToXML.prototype.convertArmatureBtn = function(armatureBtn,tag ,frameName){
	var xml_armatureBtn = new UIArmatureBtn();
	xml_armatureBtn.setAttribute( UIControlAttribute.kName,armatureBtn.name);
	xml_armatureBtn.setAttribute(UIControlAttribute.kbtnImg_normal,armatureBtn.parameters.normal.value);
	xml_armatureBtn.setAttribute(UIControlAttribute.kbtnImg_select,armatureBtn.parameters.select.value);
	xml_armatureBtn.setAttribute(UIControlAttribute.karmature_xml,armatureBtn.libraryItem.name + ".xml");
	xml_armatureBtn.setAttribute(UIControlAttribute.kPng,armatureBtn.libraryItem.name + ".png");
	xml_armatureBtn.setAttribute(UIControlAttribute.kPlist,armatureBtn.libraryItem.name + ".plist");
	this.fullNormalAttirbute( xml_armatureBtn,this.th, armatureBtn ,tag ,frameName);
	return xml_armatureBtn;
}
/** 转换numberStepper */
FlaToXML.prototype.convertNumberStepper = function(numStep,tag ,frameName){
	var xml_numStep = new UINumbericStepper();
	var params = numStep.parameters;
	xml_numStep.setAttribute(UIControlAttribute.kbtn_lnormal,numStep.libraryItem.name + "_lnomal.png");
	xml_numStep.setAttribute(UIControlAttribute.kbtn_lselect,numStep.libraryItem.name + "_lselect.png");
	xml_numStep.setAttribute(UIControlAttribute.kbtn_ldisable,numStep.libraryItem.name + "_ldisable.png");
	xml_numStep.setAttribute(UIControlAttribute.kbtn_rnormal,numStep.libraryItem.name + "_rnomal.png");
	xml_numStep.setAttribute(UIControlAttribute.kbtn_rselect,numStep.libraryItem.name + "_rselect.png");
	xml_numStep.setAttribute(UIControlAttribute.kbtn_rdisable,numStep.libraryItem.name + "_rdisable.png");
	xml_numStep.setAttribute(UIControlAttribute.kstepbg,numStep.libraryItem.name + "_stepbg.png");
	xml_numStep.setAttribute(UIControlAttribute.kLongClickRun,formatBoolean(params.longClickRun.value));
	xml_numStep.setAttribute(UIControlAttribute.ksliderMax,params.maxValue.value);
	xml_numStep.setAttribute(UIControlAttribute.ksliderMin,params.minValue.value);
	xml_numStep.setAttribute(UIControlAttribute.ksliderCur,params.value.value);
	xml_numStep.setAttribute(UIControlAttribute.kStep,params.step.value);
	this.fullNormalAttirbute( xml_numStep,this.th, numStep ,tag ,frameName);
	return xml_numStep;
}
/** 转换scrollView */
FlaToXML.prototype.convertScrollView = function(scrollView,tag ,frameName){
	var xml_scrollView = new UIScrollView();
	var params = scrollView.parameters;
	xml_scrollView.setAttribute( UIControlAttribute.kDirection,params.dir.listIndex);
	xml_scrollView.setAttribute( UIControlAttribute.kInnerWidth,scrollView.width);
	xml_scrollView.setAttribute( UIControlAttribute.kInnerHeight,scrollView.height);
	
	xml_scrollView.setAttribute(UIControlAttribute.kTextAlpha,params.bgAlpha.value);
	xml_scrollView.setAttribute(UIControlAttribute.kTextRed,parseInt(params.bgColor.value.substr(1,2),16));
	xml_scrollView.setAttribute(UIControlAttribute.kTextGreen,parseInt(params.bgColor.value.substr(3,2),16));
	xml_scrollView.setAttribute(UIControlAttribute.kTextBlue,parseInt(params.bgColor.value.substr(5,2),16));

	this.fullNormalAttirbute( xml_scrollView,this.th, scrollView ,tag ,frameName);
	
	xml_scrollView.setAttribute( UIControlAttribute.kWidth,params.innerWidth.value);
	xml_scrollView.setAttribute( UIControlAttribute.kHeight,params.innerHeight.value);
	//获取mc的timeline
	var timeline = scrollView.libraryItem.timeline;
	this.fetchElement( timeline, xml_scrollView ,frameName);
	
	return xml_scrollView;
}
/** 转换粒子 */
FlaToXML.prototype.convertParticle = function(particle,tag ,frameName){
	var xml_particle = new UIParticle();
	xml_particle.setAttribute(UIControlAttribute.kPlist,particle.libraryItem.name + ".plist");
	this.fullNormalAttirbute( xml_particle,this.th, particle ,tag ,frameName);
	return xml_particle;
}
/** 转换EditBox */
FlaToXML.prototype.convertEditBox = function(editBox,tag ,frameName){
	var xml_editBox = new UIEditBox();
	var params = editBox.parameters;
	xml_editBox.setAttribute( UIControlAttribute.kPlaceHolder,params.placeHolder.value);
	xml_editBox.setAttribute( UIControlAttribute.kInputMode,params.inputMode.listIndex);
	xml_editBox.setAttribute( UIControlAttribute.kInputFlag,params.inputFlag.listIndex);
	xml_editBox.setAttribute( UIControlAttribute.kImage, editBox.libraryItem.name + ".png" );
	
	this.fullNormalAttirbute( xml_editBox,this.th, editBox ,tag ,frameName);
	return xml_editBox;
}
/** 转换RichText */
FlaToXML.prototype.convertRichText = function(richText,tag ,frameName){
	var xml_richText = new UIRichText();
	var params = richText.parameters;
	xml_richText.setAttribute( UIControlAttribute.kText,params.text.value);
	xml_richText.setAttribute( UIControlAttribute.ksliderMax,params.maxLen.value);
	this.fullNormalAttirbute( xml_richText,this.th, richText ,tag ,frameName);
	return xml_richText;
}
/** 转换MovieView */
FlaToXML.prototype.convertMovie = function(movie,tag,frameName){
	var xml_movie = new UIMovieView();
	xml_movie.setAttribute(UIControlAttribute.kJson,movie.libraryItem.name+".json");
	xml_movie.setAttribute(UIControlAttribute.kPng,movie.libraryItem.name+".png");
	xml_movie.setAttribute(UIControlAttribute.kPlist,movie.libraryItem.name+".plist");
	this.fullNormalAttirbute( xml_movie,this.th, movie ,tag ,frameName);
	return xml_movie;
}
/** 转换Circlemenu */
FlaToXML.prototype.convertCirclemenu = function(menu,tag,frameName){
	var xml_menu = new UICircleMenu();
	this.fullNormalAttirbute( xml_menu,this.th, menu ,tag ,frameName);
	
	//获取mc的timeline
	var timeline = menu.libraryItem.timeline;
	this.fetchElement( timeline, xml_menu ,frameName);
	return xml_menu;
}
/**
 @brief 从某个layer里提取元素
 */
FlaToXML.prototype.fetchElementFromLayer = function( layer, layer_index, parentxml ){
	var nframe = layer.frameCount;
	
	for( var frame_index = 0; frame_index < nframe; ++frame_index ){
		var frame = layer.frames[frame_index];
		this.th.nameSpaceDic[frame.name] = 0;// 记录每帧的名字
		var nelement = frame.elements.length;
		for( var element_index = 0; element_index < nelement; ++element_index ){
			
			var element = frame.elements[element_index];
			var exml = this.convertElement( element ,this.cid++,frame.name ,element_index);
			parentxml.addChild( exml );
		}
	}
}

/**
 @brief 从timeline里提取element,并填加到父节点 
 @param parentxml:TXML 父节点
 */
FlaToXML.prototype.fetchElement = function( timeline, parentxml ,frameName ,resetTag){
	//trace( "FlaToXML: 提取fla里的元素" );
	//获取时间轴
	var time_line = timeline;
	var nlayer = time_line.layerCount;
	for( var layer_index = nlayer-1; layer_index >= 0; --layer_index ){
		var layer = time_line.layers[layer_index];

		var nframe = layer.frameCount;
		
		for( var frame_index = 0; frame_index < nframe; ++frame_index ){
			var frame = layer.frames[frame_index];
			
			var nelement = frame.elements.length;
			for( var element_index = 0; element_index < nelement; ++element_index ){
				var element = frame.elements[element_index];
				trace( "第" + layer_index + "层" + layer.name + ",第" + frame_index + "帧,第" + element_index + "个元素是:" + element.name);
				//var tag = resetTag == "resetTag" ? (element_index+1) : this.cid++ ;//重置tag
				var exml = this.convertElement( element , this.cid++ ,frameName ,element_index);
				parentxml.addChild( exml );
			}
		}
	}
}

FlaToXML.prototype.outputXML = function(){
	//trace( "FlaToXML: 输出xml文件" );
	this.txml.outputXML();
	//trace( this.txml.xml );
}

//导出当前fla
export_current_layer = function( uiname ){

	var convert = new FlaToXML();
	convert.setExportLayerType( kExportLayerCurrent );
	convert.convert( fl.getDocumentDOM(), null, uiname );
	return convert;
}
//修改资源路径
changeResPath = function(){
	var resPath = fl.browseForFolderURL("选择资源目录");
	if (!FLfile.exists(resPath + "/tui")) {
		FLfile.createFolder(resPath + "/tui");
	}
	return resPath;
}
//修改tag路径
changeTagPath = function(){
	var tagPath = fl.browseForFolderURL("选择tag目录");
	if (!FLfile.exists(tagPath + "/tagMap")) {
		FLfile.createFolder(tagPath + "/tagMap");
	}
	return tagPath;
}
//导出所有资源
exportAll = function(resPath,tagPath,tagType){
	
	var sceneName = fl.getDocumentDOM().name.replace(".fla","");
	var xmlFile = "tui/tui_"+sceneName+".xml";//xml资源路径
	
	if (!FLfile.exists(tagPath + "/tagMap")) {
		FLfile.createFolder(tagPath + "/tagMap");
	}
	if (!FLfile.exists(resPath + "/tui")) {
		FLfile.createFolder(resPath + "/tui");
	}
	var saveXmlPath = resPath + "/" + xmlFile;
	var saveTagPath = tagPath + "/" ;
	
	if (tagType == "cpp"){
		saveTagPath += "tagMap/Tag_" + sceneName + ".h"; //cpp
	}else if(tagType == "lua"){
		saveTagPath += "tagMap/Tag_" + sceneName + ".lua";  //lua
	}
	var tui = export_current_layer("");//根节点名字
	
	tui.th.xmlFile = xmlFile;
	
	FLfile.write(saveXmlPath,tui.txml.xml);
	FLfile.write(saveTagPath,tui.th.parseContent(tagType));
	trace(tui.txml.xml);
}
//加载xml配置表
loadConfig = function() {
	var filePath = fl.getDocumentDOM().path;
	var uriPath = FLfile.platformPathToURI(filePath)
	var uri = uriPath.substring(0,uriPath.lastIndexOf("/")) + "/tuiconfig.xml";
	if(FLfile.exists(uri)==false){
		alert(fileName + " not found.");
		return null;
	}
	var context = FLfile.read(uri);
	context = XML(context);
	if(context==null){
		alert("load xml failed.");
		return null;
	}
	var configs = {};
	var children = context.elements();
	configs.type = context.@type;
	for(var j = 0; j < children.length(); j++){
		configs[children[j].@name] = children[j].@value;
	}
	return configs;
}
//把该jsfl放到 C:\Users\Administrator\AppData\Local\Adobe\Flash CS6\zh_CN\Configuration\Commands 下
//即可使用 FlashCS中的命令版TuiEditer(Commands)
//配置请参考tuiconfig.xml
cls();
var configs = loadConfig();
var uriResPath = decodeURI(FLfile.platformPathToURI(configs.resPath))
var uriTagPath = decodeURI(FLfile.platformPathToURI(configs.tagPath))
exportAll( uriResPath ,uriTagPath ,configs.type);