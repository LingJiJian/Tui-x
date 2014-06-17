#include "lua_cocos2dx_cocoswidget_auto.hpp"
#include "cocos-widget.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"
#include "CCLuaValue.h"

/////////////////×¢²á»Øµ÷/////////////////////////////////////////////////

#define LUA_COCOS2DX_CCW_SCRIPT_HANDLER(__WIDGET__, __SET_HANDLER__) \
	int lua_cocos2dx_cocoswidget_##__WIDGET__##_##__SET_HANDLER__##(lua_State* tolua_S) \
{ \
	int argc = 0;							\
	cocos2d::cocoswidget::__WIDGET__* cobj = nullptr;	\
	cobj = (cocos2d::cocoswidget::__WIDGET__*)tolua_tousertype(tolua_S, 1, 0); \
	argc = lua_gettop(tolua_S) - 1; \
	if (1 == argc) \
	{ \
	LUA_FUNCTION nHandler = toluafix_ref_function(tolua_S, 2, 0); \
	cobj->__SET_HANDLER__(nHandler); \
	} \
	return 0; \
}

int lua_cocos2dx_cocoswidget_MovieView_setOnCallBackScriptHandle(lua_State* tolua_S)
{ 
	int argc = 0;	
	bool ok = true;
	cocos2d::cocoswidget::MovieView* cobj = nullptr;
	cobj = (cocos2d::cocoswidget::MovieView*)tolua_tousertype(tolua_S, 1, 0);
	argc = lua_gettop(tolua_S) - 1; 
	if (2 == argc)
	{
		const char* key;

		std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); key = arg0_tmp.c_str();
		if (!ok)
			return 0;

		LUA_FUNCTION nHandler = toluafix_ref_function(tolua_S, 3, 0);
		cobj->setOnCallBackScriptHandle(key, nHandler);
	}
	return 0; 
}


LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CTextRich, setOnTextRichClickScriptHandler)

LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CPageView, setOnPageChangedScriptHandler)
LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CGridPageView, setOnPageChangedScriptHandler)

LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CScrollView, setOnScrollingScriptHandler)

LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CProgressBar, setOnProgressEndedScriptHandler)

LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CProgressBar, setOnValueChangedScriptHandler)
LUA_COCOS2DX_CCW_SCRIPT_HANDLER(NumericStepper, setOnValueChangedScriptHandler)
LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CSlider, setOnValueChangedScriptHandler)

LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CLabelBMFont, setOnClickScriptHandler)
LUA_COCOS2DX_CCW_SCRIPT_HANDLER(ArmatureBtn, setOnClickScriptHandler)
LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CButton, setOnClickScriptHandler)
LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CCheckBox, setOnClickScriptHandler)
LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CImageView, setOnClickScriptHandler)
LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CColorView, setOnClickScriptHandler)
LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CLabel, setOnClickScriptHandler)
LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CLabelAtlas, setOnClickScriptHandler)
LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CImageViewScale9, setOnClickScriptHandler)
LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CToggleView, setOnClickScriptHandler)
LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CircleMenu, setOnClickScriptHandler)

LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CButton, setOnLongClickScriptHandler)
LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CCheckBox, setOnLongClickScriptHandler)
LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CColorView, setOnLongClickScriptHandler)
LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CLabel, setOnLongClickScriptHandler)
LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CLabelAtlas, setOnLongClickScriptHandler)
LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CLabelBMFont, setOnLongClickScriptHandler)
LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CImageView, setOnLongClickScriptHandler)
LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CImageViewScale9, setOnLongClickScriptHandler)

LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CCheckBox, setOnCheckScriptHandler)
LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CToggleView, setOnCheckScriptHandler)

LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CControlView, setOnControlScriptHandler)

LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CGridView, setDataSourceAdapterScriptHandler)
LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CTableView, setDataSourceAdapterScriptHandler)
LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CGridPageView, setDataSourceAdapterScriptHandler)
LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CPageView, setDataSourceAdapterScriptHandler)

LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CWidgetWindow, setOnTouchMovedAfterLongClickScriptHandler);
LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CWidgetWindow, setOnTouchEndedAfterLongClickScriptHandler);
LUA_COCOS2DX_CCW_SCRIPT_HANDLER(CWidgetWindow, setOnTouchCancelledAfterLongClickScriptHandler);

//////////////////////////////////////////////////////////////////////////


int lua_cocos2dx_cocoswidget_CWidgetTouchProtocol_onTouchMoved(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidgetTouchProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidgetTouchProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidgetTouchProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidgetTouchProtocol_onTouchMoved'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchMoved(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchMoved",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidgetTouchProtocol_onTouchMoved'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidgetTouchProtocol_onTouchEnded(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidgetTouchProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidgetTouchProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidgetTouchProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidgetTouchProtocol_onTouchEnded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchEnded(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchEnded",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidgetTouchProtocol_onTouchEnded'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidgetTouchProtocol_onTouchCancelled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidgetTouchProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidgetTouchProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidgetTouchProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidgetTouchProtocol_onTouchCancelled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchCancelled(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchCancelled",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidgetTouchProtocol_onTouchCancelled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidgetTouchProtocol_onTouchBegan(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidgetTouchProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidgetTouchProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidgetTouchProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidgetTouchProtocol_onTouchBegan'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Touch* arg0;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);
        if(!ok)
            return 0;
        int ret = (int)cobj->onTouchBegan(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchBegan",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidgetTouchProtocol_onTouchBegan'.",&tolua_err);
#endif

    return 0;
}
static int lua_cocos2dx_cocoswidget_CWidgetTouchProtocol_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CWidgetTouchProtocol)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CWidgetTouchProtocol(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CWidgetTouchProtocol");
    tolua_cclass(tolua_S,"CWidgetTouchProtocol","cc.cocoswidget::CWidgetTouchProtocol","",nullptr);

    tolua_beginmodule(tolua_S,"CWidgetTouchProtocol");
        tolua_function(tolua_S,"onTouchMoved",lua_cocos2dx_cocoswidget_CWidgetTouchProtocol_onTouchMoved);
        tolua_function(tolua_S,"onTouchEnded",lua_cocos2dx_cocoswidget_CWidgetTouchProtocol_onTouchEnded);
        tolua_function(tolua_S,"onTouchCancelled",lua_cocos2dx_cocoswidget_CWidgetTouchProtocol_onTouchCancelled);
        tolua_function(tolua_S,"onTouchBegan",lua_cocos2dx_cocoswidget_CWidgetTouchProtocol_onTouchBegan);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CWidgetTouchProtocol).name();
    g_luaType[typeName] = "cc.cocoswidget::CWidgetTouchProtocol";
    g_typeCast["CWidgetTouchProtocol"] = "cc.cocoswidget::CWidgetTouchProtocol";
    return 1;
}

int lua_cocos2dx_cocoswidget_CDataSourceAdapterProtocol_setDataSourceAdapterScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CDataSourceAdapterProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CDataSourceAdapterProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CDataSourceAdapterProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CDataSourceAdapterProtocol_setDataSourceAdapterScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setDataSourceAdapterScriptHandler(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDataSourceAdapterScriptHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CDataSourceAdapterProtocol_setDataSourceAdapterScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CDataSourceAdapterProtocol_removeDataSourceAdapterScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CDataSourceAdapterProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CDataSourceAdapterProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CDataSourceAdapterProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CDataSourceAdapterProtocol_removeDataSourceAdapterScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeDataSourceAdapterScriptHandler();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeDataSourceAdapterScriptHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CDataSourceAdapterProtocol_removeDataSourceAdapterScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CDataSourceAdapterProtocol_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CDataSourceAdapterProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CDataSourceAdapterProtocol();
        tolua_pushusertype(tolua_S,(void*)cobj,"cc.cocoswidget::CDataSourceAdapterProtocol");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CDataSourceAdapterProtocol",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CDataSourceAdapterProtocol_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CDataSourceAdapterProtocol_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CDataSourceAdapterProtocol)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CDataSourceAdapterProtocol(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CDataSourceAdapterProtocol");
    tolua_cclass(tolua_S,"CDataSourceAdapterProtocol","cc.cocoswidget::CDataSourceAdapterProtocol","",nullptr);

    tolua_beginmodule(tolua_S,"CDataSourceAdapterProtocol");
        tolua_function(tolua_S,"setDataSourceAdapterScriptHandler",lua_cocos2dx_cocoswidget_CDataSourceAdapterProtocol_setDataSourceAdapterScriptHandler);
        tolua_function(tolua_S,"removeDataSourceAdapterScriptHandler",lua_cocos2dx_cocoswidget_CDataSourceAdapterProtocol_removeDataSourceAdapterScriptHandler);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CDataSourceAdapterProtocol_constructor);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CDataSourceAdapterProtocol).name();
    g_luaType[typeName] = "cc.cocoswidget::CDataSourceAdapterProtocol";
    g_typeCast["CDataSourceAdapterProtocol"] = "cc.cocoswidget::CDataSourceAdapterProtocol";
    return 1;
}

int lua_cocos2dx_cocoswidget_CTextRichClickableProtocol_setOnTextRichClickScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTextRichClickableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTextRichClickableProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTextRichClickableProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTextRichClickableProtocol_setOnTextRichClickScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setOnTextRichClickScriptHandler(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOnTextRichClickScriptHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTextRichClickableProtocol_setOnTextRichClickScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTextRichClickableProtocol_removeOnTextRichClickScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTextRichClickableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTextRichClickableProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTextRichClickableProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTextRichClickableProtocol_removeOnTextRichClickScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeOnTextRichClickScriptHandler();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeOnTextRichClickScriptHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTextRichClickableProtocol_removeOnTextRichClickScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTextRichClickableProtocol_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTextRichClickableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CTextRichClickableProtocol();
        tolua_pushusertype(tolua_S,(void*)cobj,"cc.cocoswidget::CTextRichClickableProtocol");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CTextRichClickableProtocol",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTextRichClickableProtocol_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CTextRichClickableProtocol_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CTextRichClickableProtocol)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CTextRichClickableProtocol(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CTextRichClickableProtocol");
    tolua_cclass(tolua_S,"CTextRichClickableProtocol","cc.cocoswidget::CTextRichClickableProtocol","",nullptr);

    tolua_beginmodule(tolua_S,"CTextRichClickableProtocol");
        tolua_function(tolua_S,"setOnTextRichClickScriptHandler",lua_cocos2dx_cocoswidget_CTextRichClickableProtocol_setOnTextRichClickScriptHandler);
        tolua_function(tolua_S,"removeOnTextRichClickScriptHandler",lua_cocos2dx_cocoswidget_CTextRichClickableProtocol_removeOnTextRichClickScriptHandler);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CTextRichClickableProtocol_constructor);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CTextRichClickableProtocol).name();
    g_luaType[typeName] = "cc.cocoswidget::CTextRichClickableProtocol";
    g_typeCast["CTextRichClickableProtocol"] = "cc.cocoswidget::CTextRichClickableProtocol";
    return 1;
}

int lua_cocos2dx_cocoswidget_CLayoutableProtocol_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLayoutableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CLayoutableProtocol();
        tolua_pushusertype(tolua_S,(void*)cobj,"cc.cocoswidget::CLayoutableProtocol");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CLayoutableProtocol",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLayoutableProtocol_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CLayoutableProtocol_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CLayoutableProtocol)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CLayoutableProtocol(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CLayoutableProtocol");
    tolua_cclass(tolua_S,"CLayoutableProtocol","cc.cocoswidget::CLayoutableProtocol","",nullptr);

    tolua_beginmodule(tolua_S,"CLayoutableProtocol");
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CLayoutableProtocol).name();
    g_luaType[typeName] = "cc.cocoswidget::CLayoutableProtocol";
    g_typeCast["CLayoutableProtocol"] = "cc.cocoswidget::CLayoutableProtocol";
    return 1;
}

int lua_cocos2dx_cocoswidget_CPageChangeableProtocol_removeOnPageChangedScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CPageChangeableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CPageChangeableProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CPageChangeableProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CPageChangeableProtocol_removeOnPageChangedScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeOnPageChangedScriptHandler();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeOnPageChangedScriptHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CPageChangeableProtocol_removeOnPageChangedScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CPageChangeableProtocol_setOnPageChangedScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CPageChangeableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CPageChangeableProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CPageChangeableProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CPageChangeableProtocol_setOnPageChangedScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setOnPageChangedScriptHandler(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOnPageChangedScriptHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CPageChangeableProtocol_setOnPageChangedScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CPageChangeableProtocol_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CPageChangeableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CPageChangeableProtocol();
        tolua_pushusertype(tolua_S,(void*)cobj,"cc.cocoswidget::CPageChangeableProtocol");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CPageChangeableProtocol",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CPageChangeableProtocol_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CPageChangeableProtocol_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CPageChangeableProtocol)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CPageChangeableProtocol(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CPageChangeableProtocol");
    tolua_cclass(tolua_S,"CPageChangeableProtocol","cc.cocoswidget::CPageChangeableProtocol","",nullptr);

    tolua_beginmodule(tolua_S,"CPageChangeableProtocol");
        tolua_function(tolua_S,"removeOnPageChangedScriptHandler",lua_cocos2dx_cocoswidget_CPageChangeableProtocol_removeOnPageChangedScriptHandler);
        tolua_function(tolua_S,"setOnPageChangedScriptHandler",lua_cocos2dx_cocoswidget_CPageChangeableProtocol_setOnPageChangedScriptHandler);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CPageChangeableProtocol_constructor);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CPageChangeableProtocol).name();
    g_luaType[typeName] = "cc.cocoswidget::CPageChangeableProtocol";
    g_typeCast["CPageChangeableProtocol"] = "cc.cocoswidget::CPageChangeableProtocol";
    return 1;
}

int lua_cocos2dx_cocoswidget_CScrollableProtocol_removeOnScrollingScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollableProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollableProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollableProtocol_removeOnScrollingScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeOnScrollingScriptHandler();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeOnScrollingScriptHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollableProtocol_removeOnScrollingScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollableProtocol_setOnScrollingScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollableProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollableProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollableProtocol_setOnScrollingScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setOnScrollingScriptHandler(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOnScrollingScriptHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollableProtocol_setOnScrollingScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollableProtocol_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CScrollableProtocol();
        tolua_pushusertype(tolua_S,(void*)cobj,"cc.cocoswidget::CScrollableProtocol");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CScrollableProtocol",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollableProtocol_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CScrollableProtocol_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CScrollableProtocol)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CScrollableProtocol(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CScrollableProtocol");
    tolua_cclass(tolua_S,"CScrollableProtocol","cc.cocoswidget::CScrollableProtocol","",nullptr);

    tolua_beginmodule(tolua_S,"CScrollableProtocol");
        tolua_function(tolua_S,"removeOnScrollingScriptHandler",lua_cocos2dx_cocoswidget_CScrollableProtocol_removeOnScrollingScriptHandler);
        tolua_function(tolua_S,"setOnScrollingScriptHandler",lua_cocos2dx_cocoswidget_CScrollableProtocol_setOnScrollingScriptHandler);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CScrollableProtocol_constructor);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CScrollableProtocol).name();
    g_luaType[typeName] = "cc.cocoswidget::CScrollableProtocol";
    g_typeCast["CScrollableProtocol"] = "cc.cocoswidget::CScrollableProtocol";
    return 1;
}

int lua_cocos2dx_cocoswidget_CProgressEndedProtocol_removeOnProgressEndedScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressEndedProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressEndedProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressEndedProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressEndedProtocol_removeOnProgressEndedScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeOnProgressEndedScriptHandler();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeOnProgressEndedScriptHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressEndedProtocol_removeOnProgressEndedScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressEndedProtocol_setOnProgressEndedScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressEndedProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressEndedProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressEndedProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressEndedProtocol_setOnProgressEndedScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setOnProgressEndedScriptHandler(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOnProgressEndedScriptHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressEndedProtocol_setOnProgressEndedScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressEndedProtocol_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressEndedProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CProgressEndedProtocol();
        tolua_pushusertype(tolua_S,(void*)cobj,"cc.cocoswidget::CProgressEndedProtocol");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CProgressEndedProtocol",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressEndedProtocol_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CProgressEndedProtocol_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CProgressEndedProtocol)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CProgressEndedProtocol(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CProgressEndedProtocol");
    tolua_cclass(tolua_S,"CProgressEndedProtocol","cc.cocoswidget::CProgressEndedProtocol","",nullptr);

    tolua_beginmodule(tolua_S,"CProgressEndedProtocol");
        tolua_function(tolua_S,"removeOnProgressEndedScriptHandler",lua_cocos2dx_cocoswidget_CProgressEndedProtocol_removeOnProgressEndedScriptHandler);
        tolua_function(tolua_S,"setOnProgressEndedScriptHandler",lua_cocos2dx_cocoswidget_CProgressEndedProtocol_setOnProgressEndedScriptHandler);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CProgressEndedProtocol_constructor);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CProgressEndedProtocol).name();
    g_luaType[typeName] = "cc.cocoswidget::CProgressEndedProtocol";
    g_typeCast["CProgressEndedProtocol"] = "cc.cocoswidget::CProgressEndedProtocol";
    return 1;
}

int lua_cocos2dx_cocoswidget_CValueChangeableProtocol_setOnValueChangedScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CValueChangeableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CValueChangeableProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CValueChangeableProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CValueChangeableProtocol_setOnValueChangedScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setOnValueChangedScriptHandler(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOnValueChangedScriptHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CValueChangeableProtocol_setOnValueChangedScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CValueChangeableProtocol_removeOnValueChangedScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CValueChangeableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CValueChangeableProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CValueChangeableProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CValueChangeableProtocol_removeOnValueChangedScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeOnValueChangedScriptHandler();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeOnValueChangedScriptHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CValueChangeableProtocol_removeOnValueChangedScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CValueChangeableProtocol_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CValueChangeableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CValueChangeableProtocol();
        tolua_pushusertype(tolua_S,(void*)cobj,"cc.cocoswidget::CValueChangeableProtocol");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CValueChangeableProtocol",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CValueChangeableProtocol_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CValueChangeableProtocol_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CValueChangeableProtocol)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CValueChangeableProtocol(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CValueChangeableProtocol");
    tolua_cclass(tolua_S,"CValueChangeableProtocol","cc.cocoswidget::CValueChangeableProtocol","",nullptr);

    tolua_beginmodule(tolua_S,"CValueChangeableProtocol");
        tolua_function(tolua_S,"setOnValueChangedScriptHandler",lua_cocos2dx_cocoswidget_CValueChangeableProtocol_setOnValueChangedScriptHandler);
        tolua_function(tolua_S,"removeOnValueChangedScriptHandler",lua_cocos2dx_cocoswidget_CValueChangeableProtocol_removeOnValueChangedScriptHandler);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CValueChangeableProtocol_constructor);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CValueChangeableProtocol).name();
    g_luaType[typeName] = "cc.cocoswidget::CValueChangeableProtocol";
    g_typeCast["CValueChangeableProtocol"] = "cc.cocoswidget::CValueChangeableProtocol";
    return 1;
}

int lua_cocos2dx_cocoswidget_CClickableProtocol_removeOnClickScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CClickableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CClickableProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CClickableProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CClickableProtocol_removeOnClickScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeOnClickScriptHandler();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeOnClickScriptHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CClickableProtocol_removeOnClickScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CClickableProtocol_setOnClickScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CClickableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CClickableProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CClickableProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CClickableProtocol_setOnClickScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setOnClickScriptHandler(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOnClickScriptHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CClickableProtocol_setOnClickScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CClickableProtocol_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CClickableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CClickableProtocol();
        tolua_pushusertype(tolua_S,(void*)cobj,"cc.cocoswidget::CClickableProtocol");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CClickableProtocol",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CClickableProtocol_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CClickableProtocol_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CClickableProtocol)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CClickableProtocol(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CClickableProtocol");
    tolua_cclass(tolua_S,"CClickableProtocol","cc.cocoswidget::CClickableProtocol","",nullptr);

    tolua_beginmodule(tolua_S,"CClickableProtocol");
        tolua_function(tolua_S,"removeOnClickScriptHandler",lua_cocos2dx_cocoswidget_CClickableProtocol_removeOnClickScriptHandler);
        tolua_function(tolua_S,"setOnClickScriptHandler",lua_cocos2dx_cocoswidget_CClickableProtocol_setOnClickScriptHandler);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CClickableProtocol_constructor);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CClickableProtocol).name();
    g_luaType[typeName] = "cc.cocoswidget::CClickableProtocol";
    g_typeCast["CClickableProtocol"] = "cc.cocoswidget::CClickableProtocol";
    return 1;
}

int lua_cocos2dx_cocoswidget_CLongClickableProtocol_setOnLongClickScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLongClickableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLongClickableProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLongClickableProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLongClickableProtocol_setOnLongClickScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setOnLongClickScriptHandler(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOnLongClickScriptHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLongClickableProtocol_setOnLongClickScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLongClickableProtocol_removeOnLongClickScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLongClickableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLongClickableProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLongClickableProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLongClickableProtocol_removeOnLongClickScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeOnLongClickScriptHandler();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeOnLongClickScriptHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLongClickableProtocol_removeOnLongClickScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLongClickableProtocol_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLongClickableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CLongClickableProtocol();
        tolua_pushusertype(tolua_S,(void*)cobj,"cc.cocoswidget::CLongClickableProtocol");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CLongClickableProtocol",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLongClickableProtocol_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CLongClickableProtocol_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CLongClickableProtocol)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CLongClickableProtocol(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CLongClickableProtocol");
    tolua_cclass(tolua_S,"CLongClickableProtocol","cc.cocoswidget::CLongClickableProtocol","",nullptr);

    tolua_beginmodule(tolua_S,"CLongClickableProtocol");
        tolua_function(tolua_S,"setOnLongClickScriptHandler",lua_cocos2dx_cocoswidget_CLongClickableProtocol_setOnLongClickScriptHandler);
        tolua_function(tolua_S,"removeOnLongClickScriptHandler",lua_cocos2dx_cocoswidget_CLongClickableProtocol_removeOnLongClickScriptHandler);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CLongClickableProtocol_constructor);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CLongClickableProtocol).name();
    g_luaType[typeName] = "cc.cocoswidget::CLongClickableProtocol";
    g_typeCast["CLongClickableProtocol"] = "cc.cocoswidget::CLongClickableProtocol";
    return 1;
}

int lua_cocos2dx_cocoswidget_CCheckableProtocol_setExclusion(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckableProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckableProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckableProtocol_setExclusion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setExclusion(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setExclusion",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckableProtocol_setExclusion'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckableProtocol_setOnCheckScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckableProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckableProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckableProtocol_setOnCheckScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setOnCheckScriptHandler(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOnCheckScriptHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckableProtocol_setOnCheckScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckableProtocol_setChecked(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckableProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckableProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckableProtocol_setChecked'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setChecked(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setChecked",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckableProtocol_setChecked'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckableProtocol_getExclusion(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckableProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckableProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckableProtocol_getExclusion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getExclusion();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getExclusion",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckableProtocol_getExclusion'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckableProtocol_isChecked(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckableProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckableProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckableProtocol_isChecked'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isChecked();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isChecked",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckableProtocol_isChecked'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckableProtocol_removeCheckScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckableProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckableProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckableProtocol_removeCheckScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeCheckScriptHandler();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeCheckScriptHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckableProtocol_removeCheckScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckableProtocol_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CCheckableProtocol();
        tolua_pushusertype(tolua_S,(void*)cobj,"cc.cocoswidget::CCheckableProtocol");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCheckableProtocol",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckableProtocol_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CCheckableProtocol_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCheckableProtocol)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CCheckableProtocol(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CCheckableProtocol");
    tolua_cclass(tolua_S,"CCheckableProtocol","cc.cocoswidget::CCheckableProtocol","",nullptr);

    tolua_beginmodule(tolua_S,"CCheckableProtocol");
        tolua_function(tolua_S,"setExclusion",lua_cocos2dx_cocoswidget_CCheckableProtocol_setExclusion);
        tolua_function(tolua_S,"setOnCheckScriptHandler",lua_cocos2dx_cocoswidget_CCheckableProtocol_setOnCheckScriptHandler);
        tolua_function(tolua_S,"setChecked",lua_cocos2dx_cocoswidget_CCheckableProtocol_setChecked);
        tolua_function(tolua_S,"getExclusion",lua_cocos2dx_cocoswidget_CCheckableProtocol_getExclusion);
        tolua_function(tolua_S,"isChecked",lua_cocos2dx_cocoswidget_CCheckableProtocol_isChecked);
        tolua_function(tolua_S,"removeCheckScriptHandler",lua_cocos2dx_cocoswidget_CCheckableProtocol_removeCheckScriptHandler);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CCheckableProtocol_constructor);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CCheckableProtocol).name();
    g_luaType[typeName] = "cc.cocoswidget::CCheckableProtocol";
    g_typeCast["CCheckableProtocol"] = "cc.cocoswidget::CCheckableProtocol";
    return 1;
}

int lua_cocos2dx_cocoswidget_CControlableProtocol_removeOnControlScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CControlableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CControlableProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CControlableProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CControlableProtocol_removeOnControlScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeOnControlScriptHandler();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeOnControlScriptHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CControlableProtocol_removeOnControlScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CControlableProtocol_setOnControlScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CControlableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CControlableProtocol",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CControlableProtocol*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CControlableProtocol_setOnControlScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setOnControlScriptHandler(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOnControlScriptHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CControlableProtocol_setOnControlScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CControlableProtocol_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CControlableProtocol* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CControlableProtocol();
        tolua_pushusertype(tolua_S,(void*)cobj,"cc.cocoswidget::CControlableProtocol");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CControlableProtocol",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CControlableProtocol_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CControlableProtocol_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CControlableProtocol)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CControlableProtocol(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CControlableProtocol");
    tolua_cclass(tolua_S,"CControlableProtocol","cc.cocoswidget::CControlableProtocol","",nullptr);

    tolua_beginmodule(tolua_S,"CControlableProtocol");
        tolua_function(tolua_S,"removeOnControlScriptHandler",lua_cocos2dx_cocoswidget_CControlableProtocol_removeOnControlScriptHandler);
        tolua_function(tolua_S,"setOnControlScriptHandler",lua_cocos2dx_cocoswidget_CControlableProtocol_setOnControlScriptHandler);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CControlableProtocol_constructor);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CControlableProtocol).name();
    g_luaType[typeName] = "cc.cocoswidget::CControlableProtocol";
    g_typeCast["CControlableProtocol"] = "cc.cocoswidget::CControlableProtocol";
    return 1;
}

int lua_cocos2dx_cocoswidget_CWidget_onTouchEnded(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_onTouchEnded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchEnded(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchEnded",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_onTouchEnded'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_onTouchMoved(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_onTouchMoved'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchMoved(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchMoved",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_onTouchMoved'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_removeOnTouchEndedScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_removeOnTouchEndedScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeOnTouchEndedScriptHandler();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeOnTouchEndedScriptHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_removeOnTouchEndedScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_getDescription(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_getDescription'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getDescription();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDescription",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_getDescription'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_getUserTag(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_getUserTag'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getUserTag();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getUserTag",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_getUserTag'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_setOnTouchBeganScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_setOnTouchBeganScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setOnTouchBeganScriptHandler(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOnTouchBeganScriptHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_setOnTouchBeganScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_removeOnTouchMovedScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_removeOnTouchMovedScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeOnTouchMovedScriptHandler();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeOnTouchMovedScriptHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_removeOnTouchMovedScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_interruptTouchCascade(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_interruptTouchCascade'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->interruptTouchCascade(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "interruptTouchCascade",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_interruptTouchCascade'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_setDescription(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_setDescription'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setDescription(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDescription",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_setDescription'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_removeOnTouchBeganScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_removeOnTouchBeganScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeOnTouchBeganScriptHandler();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeOnTouchBeganScriptHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_removeOnTouchBeganScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_executeTouchEndedHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_executeTouchEndedHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->executeTouchEndedHandler(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "executeTouchEndedHandler",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_executeTouchEndedHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_isEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_isEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isEnabled",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_isEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_getId(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_getId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getId();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getId",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_getId'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_isTouchEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_isTouchEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isTouchEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isTouchEnabled",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_isTouchEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_setTouchEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_setTouchEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setTouchEnabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTouchEnabled",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_setTouchEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_setEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_setEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setEnabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setEnabled",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_setEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_isTouchInterrupted(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_isTouchInterrupted'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isTouchInterrupted();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isTouchInterrupted",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_isTouchInterrupted'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_onTouchCancelled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_onTouchCancelled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchCancelled(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchCancelled",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_onTouchCancelled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_onTouchBegan(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_onTouchBegan'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Touch* arg0;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);
        if(!ok)
            return 0;
        int ret = (int)cobj->onTouchBegan(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchBegan",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_onTouchBegan'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_interruptTouch(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_interruptTouch'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->interruptTouch(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "interruptTouch",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_interruptTouch'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_executeTouchCancelledHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_executeTouchCancelledHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->executeTouchCancelledHandler(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "executeTouchCancelledHandler",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_executeTouchCancelledHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_setOnTouchEndedScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_setOnTouchEndedScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setOnTouchEndedScriptHandler(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOnTouchEndedScriptHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_setOnTouchEndedScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_executeTouchBeganHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_executeTouchBeganHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Touch* arg0;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);
        if(!ok)
            return 0;
        int ret = (int)cobj->executeTouchBeganHandler(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "executeTouchBeganHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_executeTouchBeganHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_setLongClickTouchHandlerWidget(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_setLongClickTouchHandlerWidget'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Node* arg0;
        int arg1;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        cobj->setLongClickTouchHandlerWidget(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setLongClickTouchHandlerWidget",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_setLongClickTouchHandlerWidget'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_setOnTouchCancelledScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_setOnTouchCancelledScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setOnTouchCancelledScriptHandler(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOnTouchCancelledScriptHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_setOnTouchCancelledScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_setOnTouchMovedScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_setOnTouchMovedScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setOnTouchMovedScriptHandler(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOnTouchMovedScriptHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_setOnTouchMovedScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_removeOnTouchCancelledScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_removeOnTouchCancelledScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeOnTouchCancelledScriptHandler();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeOnTouchCancelledScriptHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_removeOnTouchCancelledScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_setUserTag(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_setUserTag'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setUserTag(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setUserTag",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_setUserTag'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_executeTouchMovedHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_executeTouchMovedHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->executeTouchMovedHandler(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "executeTouchMovedHandler",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_executeTouchMovedHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_setId(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidget_setId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setId(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setId",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_setId'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidget_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CWidget();
        tolua_pushusertype(tolua_S,(void*)cobj,"cc.cocoswidget::CWidget");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CWidget",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidget_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CWidget_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CWidget)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CWidget(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CWidget");
    tolua_cclass(tolua_S,"CWidget","cc.cocoswidget::CWidget","cc.cocoswidget::CWidgetTouchProtocol",nullptr);

    tolua_beginmodule(tolua_S,"CWidget");
        tolua_function(tolua_S,"onTouchEnded",lua_cocos2dx_cocoswidget_CWidget_onTouchEnded);
        tolua_function(tolua_S,"onTouchMoved",lua_cocos2dx_cocoswidget_CWidget_onTouchMoved);
        tolua_function(tolua_S,"removeOnTouchEndedScriptHandler",lua_cocos2dx_cocoswidget_CWidget_removeOnTouchEndedScriptHandler);
        tolua_function(tolua_S,"getDescription",lua_cocos2dx_cocoswidget_CWidget_getDescription);
        tolua_function(tolua_S,"getUserTag",lua_cocos2dx_cocoswidget_CWidget_getUserTag);
        tolua_function(tolua_S,"setOnTouchBeganScriptHandler",lua_cocos2dx_cocoswidget_CWidget_setOnTouchBeganScriptHandler);
        tolua_function(tolua_S,"removeOnTouchMovedScriptHandler",lua_cocos2dx_cocoswidget_CWidget_removeOnTouchMovedScriptHandler);
        tolua_function(tolua_S,"interruptTouchCascade",lua_cocos2dx_cocoswidget_CWidget_interruptTouchCascade);
        tolua_function(tolua_S,"setDescription",lua_cocos2dx_cocoswidget_CWidget_setDescription);
        tolua_function(tolua_S,"removeOnTouchBeganScriptHandler",lua_cocos2dx_cocoswidget_CWidget_removeOnTouchBeganScriptHandler);
        tolua_function(tolua_S,"executeTouchEndedHandler",lua_cocos2dx_cocoswidget_CWidget_executeTouchEndedHandler);
        tolua_function(tolua_S,"isEnabled",lua_cocos2dx_cocoswidget_CWidget_isEnabled);
        tolua_function(tolua_S,"getId",lua_cocos2dx_cocoswidget_CWidget_getId);
        tolua_function(tolua_S,"isTouchEnabled",lua_cocos2dx_cocoswidget_CWidget_isTouchEnabled);
        tolua_function(tolua_S,"setTouchEnabled",lua_cocos2dx_cocoswidget_CWidget_setTouchEnabled);
        tolua_function(tolua_S,"setEnabled",lua_cocos2dx_cocoswidget_CWidget_setEnabled);
        tolua_function(tolua_S,"isTouchInterrupted",lua_cocos2dx_cocoswidget_CWidget_isTouchInterrupted);
        tolua_function(tolua_S,"onTouchCancelled",lua_cocos2dx_cocoswidget_CWidget_onTouchCancelled);
        tolua_function(tolua_S,"onTouchBegan",lua_cocos2dx_cocoswidget_CWidget_onTouchBegan);
        tolua_function(tolua_S,"interruptTouch",lua_cocos2dx_cocoswidget_CWidget_interruptTouch);
        tolua_function(tolua_S,"executeTouchCancelledHandler",lua_cocos2dx_cocoswidget_CWidget_executeTouchCancelledHandler);
        tolua_function(tolua_S,"setOnTouchEndedScriptHandler",lua_cocos2dx_cocoswidget_CWidget_setOnTouchEndedScriptHandler);
        tolua_function(tolua_S,"executeTouchBeganHandler",lua_cocos2dx_cocoswidget_CWidget_executeTouchBeganHandler);
        tolua_function(tolua_S,"setLongClickTouchHandlerWidget",lua_cocos2dx_cocoswidget_CWidget_setLongClickTouchHandlerWidget);
        tolua_function(tolua_S,"setOnTouchCancelledScriptHandler",lua_cocos2dx_cocoswidget_CWidget_setOnTouchCancelledScriptHandler);
        tolua_function(tolua_S,"setOnTouchMovedScriptHandler",lua_cocos2dx_cocoswidget_CWidget_setOnTouchMovedScriptHandler);
        tolua_function(tolua_S,"removeOnTouchCancelledScriptHandler",lua_cocos2dx_cocoswidget_CWidget_removeOnTouchCancelledScriptHandler);
        tolua_function(tolua_S,"setUserTag",lua_cocos2dx_cocoswidget_CWidget_setUserTag);
        tolua_function(tolua_S,"executeTouchMovedHandler",lua_cocos2dx_cocoswidget_CWidget_executeTouchMovedHandler);
        tolua_function(tolua_S,"setId",lua_cocos2dx_cocoswidget_CWidget_setId);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CWidget_constructor);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CWidget).name();
    g_luaType[typeName] = "cc.cocoswidget::CWidget";
    g_typeCast["CWidget"] = "cc.cocoswidget::CWidget";
    return 1;
}


int lua_cocos2dx_cocoswidget_CWidgetWindow_executeTouchEndedAfterLongClickHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidgetWindow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidgetWindow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidgetWindow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_executeTouchEndedAfterLongClickHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Ref* arg0;
        cocos2d::Touch* arg1;
        double arg2;

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0);

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 3, "cc.Touch",&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cobj->executeTouchEndedAfterLongClickHandler(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "executeTouchEndedAfterLongClickHandler",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_executeTouchEndedAfterLongClickHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidgetWindow_setModalable(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidgetWindow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidgetWindow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidgetWindow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_setModalable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setModalable(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setModalable",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_setModalable'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidgetWindow_isModalable(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidgetWindow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidgetWindow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidgetWindow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_isModalable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isModalable();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isModalable",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_isModalable'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidgetWindow_removeOnTouchEndedAfterLongClickScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidgetWindow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidgetWindow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidgetWindow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_removeOnTouchEndedAfterLongClickScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeOnTouchEndedAfterLongClickScriptHandler();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeOnTouchEndedAfterLongClickScriptHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_removeOnTouchEndedAfterLongClickScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidgetWindow_executeTouchCancelledAfterLongClickHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidgetWindow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidgetWindow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidgetWindow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_executeTouchCancelledAfterLongClickHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Ref* arg0;
        cocos2d::Touch* arg1;
        double arg2;

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0);

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 3, "cc.Touch",&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cobj->executeTouchCancelledAfterLongClickHandler(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "executeTouchCancelledAfterLongClickHandler",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_executeTouchCancelledAfterLongClickHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidgetWindow_isTouchEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidgetWindow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidgetWindow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidgetWindow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_isTouchEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isTouchEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isTouchEnabled",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_isTouchEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidgetWindow_init(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidgetWindow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidgetWindow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidgetWindow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidgetWindow_setTouchEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidgetWindow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidgetWindow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidgetWindow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_setTouchEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setTouchEnabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTouchEnabled",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_setTouchEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidgetWindow_removeOnTouchMovedAfterLongClickScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidgetWindow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidgetWindow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidgetWindow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_removeOnTouchMovedAfterLongClickScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeOnTouchMovedAfterLongClickScriptHandler();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeOnTouchMovedAfterLongClickScriptHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_removeOnTouchMovedAfterLongClickScriptHandler'.",&tolua_err);
#endif

    return 0;
}

int lua_cocos2dx_cocoswidget_CWidgetWindow_isMultiTouchEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidgetWindow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidgetWindow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidgetWindow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_isMultiTouchEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isMultiTouchEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isMultiTouchEnabled",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_isMultiTouchEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidgetWindow_removeOnTouchCancelledAfterLongClickScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidgetWindow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidgetWindow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidgetWindow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_removeOnTouchCancelledAfterLongClickScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeOnTouchCancelledAfterLongClickScriptHandler();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeOnTouchCancelledAfterLongClickScriptHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_removeOnTouchCancelledAfterLongClickScriptHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidgetWindow_setMultiTouchEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidgetWindow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidgetWindow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidgetWindow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_setMultiTouchEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setMultiTouchEnabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setMultiTouchEnabled",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_setMultiTouchEnabled'.",&tolua_err);
#endif

    return 0;
}

int lua_cocos2dx_cocoswidget_CWidgetWindow_executeTouchMovedAfterLongClickHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidgetWindow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidgetWindow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidgetWindow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_executeTouchMovedAfterLongClickHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Ref* arg0;
        cocos2d::Touch* arg1;
        double arg2;

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0);

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 3, "cc.Touch",&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cobj->executeTouchMovedAfterLongClickHandler(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "executeTouchMovedAfterLongClickHandler",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_executeTouchMovedAfterLongClickHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidgetWindow_setTouchPriority(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidgetWindow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidgetWindow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidgetWindow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_setTouchPriority'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setTouchPriority(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTouchPriority",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_setTouchPriority'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidgetWindow_getTouchPriority(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidgetWindow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CWidgetWindow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CWidgetWindow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_getTouchPriority'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getTouchPriority();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getTouchPriority",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_getTouchPriority'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CWidgetWindow_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CWidgetWindow",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CWidgetWindow* ret = cocos2d::cocoswidget::CWidgetWindow::create();
        object_to_luaval<cocos2d::cocoswidget::CWidgetWindow>(tolua_S, "cc.cocoswidget::CWidgetWindow",(cocos2d::cocoswidget::CWidgetWindow*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CWidgetWindow_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CWidgetWindow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CWidgetWindow();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CWidgetWindow");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CWidgetWindow",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CWidgetWindow_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CWidgetWindow_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CWidgetWindow)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CWidgetWindow(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CWidgetWindow");
    tolua_cclass(tolua_S,"CWidgetWindow","cc.cocoswidget::CWidgetWindow","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"CWidgetWindow");
       
        tolua_function(tolua_S,"executeTouchEndedAfterLongClickHandler",lua_cocos2dx_cocoswidget_CWidgetWindow_executeTouchEndedAfterLongClickHandler);
        tolua_function(tolua_S,"setModalable",lua_cocos2dx_cocoswidget_CWidgetWindow_setModalable);
        tolua_function(tolua_S,"isModalable",lua_cocos2dx_cocoswidget_CWidgetWindow_isModalable);
        tolua_function(tolua_S,"removeOnTouchEndedAfterLongClickScriptHandler",lua_cocos2dx_cocoswidget_CWidgetWindow_removeOnTouchEndedAfterLongClickScriptHandler);
        tolua_function(tolua_S,"executeTouchCancelledAfterLongClickHandler",lua_cocos2dx_cocoswidget_CWidgetWindow_executeTouchCancelledAfterLongClickHandler);
        tolua_function(tolua_S,"isTouchEnabled",lua_cocos2dx_cocoswidget_CWidgetWindow_isTouchEnabled);
        tolua_function(tolua_S,"init",lua_cocos2dx_cocoswidget_CWidgetWindow_init);
        tolua_function(tolua_S,"setTouchEnabled",lua_cocos2dx_cocoswidget_CWidgetWindow_setTouchEnabled);
        tolua_function(tolua_S,"removeOnTouchMovedAfterLongClickScriptHandler",lua_cocos2dx_cocoswidget_CWidgetWindow_removeOnTouchMovedAfterLongClickScriptHandler);  
        tolua_function(tolua_S,"isMultiTouchEnabled",lua_cocos2dx_cocoswidget_CWidgetWindow_isMultiTouchEnabled);
        tolua_function(tolua_S,"removeOnTouchCancelledAfterLongClickScriptHandler",lua_cocos2dx_cocoswidget_CWidgetWindow_removeOnTouchCancelledAfterLongClickScriptHandler);
        tolua_function(tolua_S,"setMultiTouchEnabled",lua_cocos2dx_cocoswidget_CWidgetWindow_setMultiTouchEnabled);     
        tolua_function(tolua_S,"executeTouchMovedAfterLongClickHandler",lua_cocos2dx_cocoswidget_CWidgetWindow_executeTouchMovedAfterLongClickHandler);
        tolua_function(tolua_S,"setTouchPriority",lua_cocos2dx_cocoswidget_CWidgetWindow_setTouchPriority);
        tolua_function(tolua_S,"getTouchPriority",lua_cocos2dx_cocoswidget_CWidgetWindow_getTouchPriority);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CWidgetWindow_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_CWidgetWindow_create);
		
		tolua_function(tolua_S, "setOnTouchEndedAfterLongClickScriptHandler", lua_cocos2dx_cocoswidget_CWidgetWindow_setOnTouchEndedAfterLongClickScriptHandler);
		tolua_function(tolua_S, "setOnTouchMovedAfterLongClickScriptHandler", lua_cocos2dx_cocoswidget_CWidgetWindow_setOnTouchMovedAfterLongClickScriptHandler);
		tolua_function(tolua_S, "setOnTouchCancelledAfterLongClickScriptHandler", lua_cocos2dx_cocoswidget_CWidgetWindow_setOnTouchCancelledAfterLongClickScriptHandler);

		tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CWidgetWindow).name();
    g_luaType[typeName] = "cc.cocoswidget::CWidgetWindow";
    g_typeCast["CWidgetWindow"] = "cc.cocoswidget::CWidgetWindow";
    return 1;
}

int lua_cocos2dx_cocoswidget_CScale9Sprite_setTexture(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_setTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Texture2D* arg0;

        ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);
        if(!ok)
            return 0;
        cobj->setTexture(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTexture",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_setTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_getCapInsets(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_getCapInsets'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Rect ret = cobj->getCapInsets();
        rect_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCapInsets",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_getCapInsets'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_setOpacityModifyRGB(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_setOpacityModifyRGB'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setOpacityModifyRGB(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOpacityModifyRGB",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_setOpacityModifyRGB'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_updateWithBatchNode(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_updateWithBatchNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        cocos2d::SpriteBatchNode* arg0;
        cocos2d::Rect arg1;
        bool arg2;
        cocos2d::Rect arg3;

        ok &= luaval_to_object<cocos2d::SpriteBatchNode>(tolua_S, 2, "cc.SpriteBatchNode",&arg0);

        ok &= luaval_to_rect(tolua_S, 3, &arg1);

        ok &= luaval_to_boolean(tolua_S, 4,&arg2);

        ok &= luaval_to_rect(tolua_S, 5, &arg3);
        if(!ok)
            return 0;
        bool ret = cobj->updateWithBatchNode(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "updateWithBatchNode",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_updateWithBatchNode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_setInsetBottom(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_setInsetBottom'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setInsetBottom(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setInsetBottom",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_setInsetBottom'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_isOpacityModifyRGB(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_isOpacityModifyRGB'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isOpacityModifyRGB();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isOpacityModifyRGB",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_isOpacityModifyRGB'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_visit(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_visit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Renderer* arg0;
        kmMat4 arg1;
        bool arg2;

        ok &= luaval_to_object<cocos2d::Renderer>(tolua_S, 2, "cc.Renderer",&arg0);

        ok &= luaval_to_kmMat4(tolua_S, 3, &arg1);

        ok &= luaval_to_boolean(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cobj->visit(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "visit",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_visit'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_initWithSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_initWithSpriteFrameName'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            bool ret = cobj->initWithSpriteFrameName(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1);

            if (!ok) { break; }
            bool ret = cobj->initWithSpriteFrameName(arg0, arg1);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWithSpriteFrameName",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_initWithSpriteFrameName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_setInsetTop(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_setInsetTop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setInsetTop(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setInsetTop",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_setInsetTop'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_updateDisplayedOpacity(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_updateDisplayedOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->updateDisplayedOpacity(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "updateDisplayedOpacity",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_updateDisplayedOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_init(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_setPreferredSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_setPreferredSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setPreferredSize(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setPreferredSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_setPreferredSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_getOpacity(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_getOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        uint16_t ret = cobj->getOpacity();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getOpacity",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_getOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_setSpriteFrame(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_setSpriteFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::SpriteFrame* arg0;

        ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);
        if(!ok)
            return 0;
        cobj->setSpriteFrame(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSpriteFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_setSpriteFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_initWithTexture(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_initWithTexture'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);

            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1);

            if (!ok) { break; }
            bool ret = cobj->initWithTexture(arg0, arg1);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);

            if (!ok) { break; }
            bool ret = cobj->initWithTexture(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWithTexture",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_initWithTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_getColor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_getColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Color3B& ret = cobj->getColor();
        color3b_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_getColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_initWithBatchNode(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_initWithBatchNode'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 3) {
            cocos2d::SpriteBatchNode* arg0;
            ok &= luaval_to_object<cocos2d::SpriteBatchNode>(tolua_S, 2, "cc.SpriteBatchNode",&arg0);

            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1);

            if (!ok) { break; }
            cocos2d::Rect arg2;
            ok &= luaval_to_rect(tolua_S, 4, &arg2);

            if (!ok) { break; }
            bool ret = cobj->initWithBatchNode(arg0, arg1, arg2);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 4) {
            cocos2d::SpriteBatchNode* arg0;
            ok &= luaval_to_object<cocos2d::SpriteBatchNode>(tolua_S, 2, "cc.SpriteBatchNode",&arg0);

            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1);

            if (!ok) { break; }
            bool arg2;
            ok &= luaval_to_boolean(tolua_S, 4,&arg2);

            if (!ok) { break; }
            cocos2d::Rect arg3;
            ok &= luaval_to_rect(tolua_S, 5, &arg3);

            if (!ok) { break; }
            bool ret = cobj->initWithBatchNode(arg0, arg1, arg2, arg3);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWithBatchNode",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_initWithBatchNode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_getInsetBottom(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_getInsetBottom'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getInsetBottom();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getInsetBottom",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_getInsetBottom'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_resizableSpriteWithCapInsets(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_resizableSpriteWithCapInsets'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Rect arg0;

        ok &= luaval_to_rect(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CScale9Sprite* ret = cobj->resizableSpriteWithCapInsets(arg0);
        object_to_luaval<cocos2d::cocoswidget::CScale9Sprite>(tolua_S, "cc.cocoswidget::CScale9Sprite",(cocos2d::cocoswidget::CScale9Sprite*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "resizableSpriteWithCapInsets",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_resizableSpriteWithCapInsets'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_setOpacity(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_setOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setOpacity(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOpacity",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_setOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_setContentSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_setContentSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setContentSize(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setContentSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_setContentSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_getInsetRight(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_getInsetRight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getInsetRight();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getInsetRight",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_getInsetRight'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_getOriginalSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_getOriginalSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Size ret = cobj->getOriginalSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getOriginalSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_getOriginalSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_initWithFile(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_initWithFile'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1);

            if (!ok) { break; }
            bool ret = cobj->initWithFile(arg0, arg1);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 3) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1);

            if (!ok) { break; }
            cocos2d::Rect arg2;
            ok &= luaval_to_rect(tolua_S, 4, &arg2);

            if (!ok) { break; }
            bool ret = cobj->initWithFile(arg0, arg1, arg2);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            cocos2d::Rect arg0;
            ok &= luaval_to_rect(tolua_S, 2, &arg0);

            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

            if (!ok) { break; }
            bool ret = cobj->initWithFile(arg0, arg1);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            bool ret = cobj->initWithFile(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWithFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_initWithFile'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_setColor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_setColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setColor(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_setColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_getInsetTop(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_getInsetTop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getInsetTop();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getInsetTop",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_getInsetTop'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_setInsetLeft(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_setInsetLeft'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setInsetLeft(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setInsetLeft",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_setInsetLeft'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_initWithSpriteFrame(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_initWithSpriteFrame'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            cocos2d::SpriteFrame* arg0;
            ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);

            if (!ok) { break; }
            bool ret = cobj->initWithSpriteFrame(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            cocos2d::SpriteFrame* arg0;
            ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);

            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1);

            if (!ok) { break; }
            bool ret = cobj->initWithSpriteFrame(arg0, arg1);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWithSpriteFrame",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_initWithSpriteFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_getPreferredSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_getPreferredSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Size ret = cobj->getPreferredSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getPreferredSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_getPreferredSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_setCapInsets(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_setCapInsets'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Rect arg0;

        ok &= luaval_to_rect(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setCapInsets(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCapInsets",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_setCapInsets'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_getInsetLeft(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_getInsetLeft'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getInsetLeft();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getInsetLeft",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_getInsetLeft'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_updateDisplayedColor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_updateDisplayedColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->updateDisplayedColor(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "updateDisplayedColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_updateDisplayedColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_setInsetRight(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScale9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_setInsetRight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setInsetRight(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setInsetRight",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_setInsetRight'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1);
            if (!ok) { break; }
            cocos2d::cocoswidget::CScale9Sprite* ret = cocos2d::cocoswidget::CScale9Sprite::create(arg0, arg1);
            object_to_luaval<cocos2d::cocoswidget::CScale9Sprite>(tolua_S, "cc.cocoswidget::CScale9Sprite",(cocos2d::cocoswidget::CScale9Sprite*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1);
            if (!ok) { break; }
            cocos2d::Rect arg2;
            ok &= luaval_to_rect(tolua_S, 4, &arg2);
            if (!ok) { break; }
            cocos2d::cocoswidget::CScale9Sprite* ret = cocos2d::cocoswidget::CScale9Sprite::create(arg0, arg1, arg2);
            object_to_luaval<cocos2d::cocoswidget::CScale9Sprite>(tolua_S, "cc.cocoswidget::CScale9Sprite",(cocos2d::cocoswidget::CScale9Sprite*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            cocos2d::Rect arg0;
            ok &= luaval_to_rect(tolua_S, 2, &arg0);
            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
            if (!ok) { break; }
            cocos2d::cocoswidget::CScale9Sprite* ret = cocos2d::cocoswidget::CScale9Sprite::create(arg0, arg1);
            object_to_luaval<cocos2d::cocoswidget::CScale9Sprite>(tolua_S, "cc.cocoswidget::CScale9Sprite",(cocos2d::cocoswidget::CScale9Sprite*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 1)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            cocos2d::cocoswidget::CScale9Sprite* ret = cocos2d::cocoswidget::CScale9Sprite::create(arg0);
            object_to_luaval<cocos2d::cocoswidget::CScale9Sprite>(tolua_S, "cc.cocoswidget::CScale9Sprite",(cocos2d::cocoswidget::CScale9Sprite*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            cocos2d::cocoswidget::CScale9Sprite* ret = cocos2d::cocoswidget::CScale9Sprite::create();
            object_to_luaval<cocos2d::cocoswidget::CScale9Sprite>(tolua_S, "cc.cocoswidget::CScale9Sprite",(cocos2d::cocoswidget::CScale9Sprite*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_createWithTexture(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);
            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1);
            if (!ok) { break; }
            cocos2d::cocoswidget::CScale9Sprite* ret = cocos2d::cocoswidget::CScale9Sprite::createWithTexture(arg0, arg1);
            object_to_luaval<cocos2d::cocoswidget::CScale9Sprite>(tolua_S, "cc.cocoswidget::CScale9Sprite",(cocos2d::cocoswidget::CScale9Sprite*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 1)
        {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);
            if (!ok) { break; }
            cocos2d::cocoswidget::CScale9Sprite* ret = cocos2d::cocoswidget::CScale9Sprite::createWithTexture(arg0);
            object_to_luaval<cocos2d::cocoswidget::CScale9Sprite>(tolua_S, "cc.cocoswidget::CScale9Sprite",(cocos2d::cocoswidget::CScale9Sprite*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "createWithTexture",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_createWithTexture'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_createWithSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            cocos2d::cocoswidget::CScale9Sprite* ret = cocos2d::cocoswidget::CScale9Sprite::createWithSpriteFrameName(arg0);
            object_to_luaval<cocos2d::cocoswidget::CScale9Sprite>(tolua_S, "cc.cocoswidget::CScale9Sprite",(cocos2d::cocoswidget::CScale9Sprite*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1);
            if (!ok) { break; }
            cocos2d::cocoswidget::CScale9Sprite* ret = cocos2d::cocoswidget::CScale9Sprite::createWithSpriteFrameName(arg0, arg1);
            object_to_luaval<cocos2d::cocoswidget::CScale9Sprite>(tolua_S, "cc.cocoswidget::CScale9Sprite",(cocos2d::cocoswidget::CScale9Sprite*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "createWithSpriteFrameName",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_createWithSpriteFrameName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_createWithSpriteFrame(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CScale9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            cocos2d::SpriteFrame* arg0;
            ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);
            if (!ok) { break; }
            cocos2d::cocoswidget::CScale9Sprite* ret = cocos2d::cocoswidget::CScale9Sprite::createWithSpriteFrame(arg0);
            object_to_luaval<cocos2d::cocoswidget::CScale9Sprite>(tolua_S, "cc.cocoswidget::CScale9Sprite",(cocos2d::cocoswidget::CScale9Sprite*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            cocos2d::SpriteFrame* arg0;
            ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);
            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1);
            if (!ok) { break; }
            cocos2d::cocoswidget::CScale9Sprite* ret = cocos2d::cocoswidget::CScale9Sprite::createWithSpriteFrame(arg0, arg1);
            object_to_luaval<cocos2d::cocoswidget::CScale9Sprite>(tolua_S, "cc.cocoswidget::CScale9Sprite",(cocos2d::cocoswidget::CScale9Sprite*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "createWithSpriteFrame",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_createWithSpriteFrame'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CScale9Sprite_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScale9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CScale9Sprite();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CScale9Sprite");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CScale9Sprite",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScale9Sprite_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CScale9Sprite_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CScale9Sprite)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CScale9Sprite(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CScale9Sprite");
    tolua_cclass(tolua_S,"CScale9Sprite","cc.cocoswidget::CScale9Sprite","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"CScale9Sprite");
        tolua_function(tolua_S,"setTexture",lua_cocos2dx_cocoswidget_CScale9Sprite_setTexture);
        tolua_function(tolua_S,"getCapInsets",lua_cocos2dx_cocoswidget_CScale9Sprite_getCapInsets);
        tolua_function(tolua_S,"setOpacityModifyRGB",lua_cocos2dx_cocoswidget_CScale9Sprite_setOpacityModifyRGB);
        tolua_function(tolua_S,"updateWithBatchNode",lua_cocos2dx_cocoswidget_CScale9Sprite_updateWithBatchNode);
        tolua_function(tolua_S,"setInsetBottom",lua_cocos2dx_cocoswidget_CScale9Sprite_setInsetBottom);
        tolua_function(tolua_S,"isOpacityModifyRGB",lua_cocos2dx_cocoswidget_CScale9Sprite_isOpacityModifyRGB);
        tolua_function(tolua_S,"visit",lua_cocos2dx_cocoswidget_CScale9Sprite_visit);
        tolua_function(tolua_S,"initWithSpriteFrameName",lua_cocos2dx_cocoswidget_CScale9Sprite_initWithSpriteFrameName);
        tolua_function(tolua_S,"setInsetTop",lua_cocos2dx_cocoswidget_CScale9Sprite_setInsetTop);
        tolua_function(tolua_S,"updateDisplayedOpacity",lua_cocos2dx_cocoswidget_CScale9Sprite_updateDisplayedOpacity);
        tolua_function(tolua_S,"init",lua_cocos2dx_cocoswidget_CScale9Sprite_init);
        tolua_function(tolua_S,"setPreferredSize",lua_cocos2dx_cocoswidget_CScale9Sprite_setPreferredSize);
        tolua_function(tolua_S,"getOpacity",lua_cocos2dx_cocoswidget_CScale9Sprite_getOpacity);
        tolua_function(tolua_S,"setSpriteFrame",lua_cocos2dx_cocoswidget_CScale9Sprite_setSpriteFrame);
        tolua_function(tolua_S,"initWithTexture",lua_cocos2dx_cocoswidget_CScale9Sprite_initWithTexture);
        tolua_function(tolua_S,"getColor",lua_cocos2dx_cocoswidget_CScale9Sprite_getColor);
        tolua_function(tolua_S,"initWithBatchNode",lua_cocos2dx_cocoswidget_CScale9Sprite_initWithBatchNode);
        tolua_function(tolua_S,"getInsetBottom",lua_cocos2dx_cocoswidget_CScale9Sprite_getInsetBottom);
        tolua_function(tolua_S,"resizableSpriteWithCapInsets",lua_cocos2dx_cocoswidget_CScale9Sprite_resizableSpriteWithCapInsets);
        tolua_function(tolua_S,"setOpacity",lua_cocos2dx_cocoswidget_CScale9Sprite_setOpacity);
        tolua_function(tolua_S,"setContentSize",lua_cocos2dx_cocoswidget_CScale9Sprite_setContentSize);
        tolua_function(tolua_S,"getInsetRight",lua_cocos2dx_cocoswidget_CScale9Sprite_getInsetRight);
        tolua_function(tolua_S,"getOriginalSize",lua_cocos2dx_cocoswidget_CScale9Sprite_getOriginalSize);
        tolua_function(tolua_S,"initWithFile",lua_cocos2dx_cocoswidget_CScale9Sprite_initWithFile);
        tolua_function(tolua_S,"setColor",lua_cocos2dx_cocoswidget_CScale9Sprite_setColor);
        tolua_function(tolua_S,"getInsetTop",lua_cocos2dx_cocoswidget_CScale9Sprite_getInsetTop);
        tolua_function(tolua_S,"setInsetLeft",lua_cocos2dx_cocoswidget_CScale9Sprite_setInsetLeft);
        tolua_function(tolua_S,"initWithSpriteFrame",lua_cocos2dx_cocoswidget_CScale9Sprite_initWithSpriteFrame);
        tolua_function(tolua_S,"getPreferredSize",lua_cocos2dx_cocoswidget_CScale9Sprite_getPreferredSize);
        tolua_function(tolua_S,"setCapInsets",lua_cocos2dx_cocoswidget_CScale9Sprite_setCapInsets);
        tolua_function(tolua_S,"getInsetLeft",lua_cocos2dx_cocoswidget_CScale9Sprite_getInsetLeft);
        tolua_function(tolua_S,"updateDisplayedColor",lua_cocos2dx_cocoswidget_CScale9Sprite_updateDisplayedColor);
        tolua_function(tolua_S,"setInsetRight",lua_cocos2dx_cocoswidget_CScale9Sprite_setInsetRight);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CScale9Sprite_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_CScale9Sprite_create);
        tolua_function(tolua_S,"createWithTexture", lua_cocos2dx_cocoswidget_CScale9Sprite_createWithTexture);
        tolua_function(tolua_S,"createWithSpriteFrameName", lua_cocos2dx_cocoswidget_CScale9Sprite_createWithSpriteFrameName);
        tolua_function(tolua_S,"createWithSpriteFrame", lua_cocos2dx_cocoswidget_CScale9Sprite_createWithSpriteFrame);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CScale9Sprite).name();
    g_luaType[typeName] = "cc.cocoswidget::CScale9Sprite";
    g_typeCast["CScale9Sprite"] = "cc.cocoswidget::CScale9Sprite";
    return 1;
}

int lua_cocos2dx_cocoswidget_CLabel_setMiddleLine(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLabel_setMiddleLine'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setMiddleLine(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setMiddleLine",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLabel_setMiddleLine'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLabel_onTouchMoved(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLabel_onTouchMoved'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchMoved(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchMoved",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLabel_onTouchMoved'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLabel_draw(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLabel_draw'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Renderer* arg0;
        kmMat4 arg1;
        bool arg2;

        ok &= luaval_to_object<cocos2d::Renderer>(tolua_S, 2, "cc.Renderer",&arg0);

        ok &= luaval_to_kmMat4(tolua_S, 3, &arg1);

        ok &= luaval_to_boolean(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cobj->draw(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "draw",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLabel_draw'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLabel_getUnderLine(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLabel_getUnderLine'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->getUnderLine();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getUnderLine",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLabel_getUnderLine'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLabel_getMiddleLine(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLabel_getMiddleLine'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->getMiddleLine();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getMiddleLine",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLabel_getMiddleLine'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLabel_onTouchCancelled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLabel_onTouchCancelled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchCancelled(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchCancelled",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLabel_onTouchCancelled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLabel_onTouchBegan(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLabel_onTouchBegan'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Touch* arg0;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);
        if(!ok)
            return 0;
        int ret = (int)cobj->onTouchBegan(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchBegan",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLabel_onTouchBegan'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLabel_setUnderLine(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLabel_setUnderLine'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setUnderLine(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setUnderLine",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLabel_setUnderLine'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLabel_onTouchEnded(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLabel_onTouchEnded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchEnded(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchEnded",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLabel_onTouchEnded'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLabel_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CLabel* ret = cocos2d::cocoswidget::CLabel::create();
        object_to_luaval<cocos2d::cocoswidget::CLabel>(tolua_S, "cc.cocoswidget::CLabel",(cocos2d::cocoswidget::CLabel*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLabel_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CLabel_createWithSystemFont(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        std::string arg0;
        std::string arg1;
        double arg2;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        ok &= luaval_to_std_string(tolua_S, 3,&arg1);
        ok &= luaval_to_number(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CLabel* ret = cocos2d::cocoswidget::CLabel::createWithSystemFont(arg0, arg1, arg2);
        object_to_luaval<cocos2d::cocoswidget::CLabel>(tolua_S, "cc.cocoswidget::CLabel",(cocos2d::cocoswidget::CLabel*)ret);
        return 1;
    }
    if (argc == 4)
    {
        std::string arg0;
        std::string arg1;
        double arg2;
        cocos2d::Size arg3;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        ok &= luaval_to_std_string(tolua_S, 3,&arg1);
        ok &= luaval_to_number(tolua_S, 4,&arg2);
        ok &= luaval_to_size(tolua_S, 5, &arg3);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CLabel* ret = cocos2d::cocoswidget::CLabel::createWithSystemFont(arg0, arg1, arg2, arg3);
        object_to_luaval<cocos2d::cocoswidget::CLabel>(tolua_S, "cc.cocoswidget::CLabel",(cocos2d::cocoswidget::CLabel*)ret);
        return 1;
    }
    if (argc == 5)
    {
        std::string arg0;
        std::string arg1;
        double arg2;
        cocos2d::Size arg3;
        cocos2d::TextHAlignment arg4;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        ok &= luaval_to_std_string(tolua_S, 3,&arg1);
        ok &= luaval_to_number(tolua_S, 4,&arg2);
        ok &= luaval_to_size(tolua_S, 5, &arg3);
        ok &= luaval_to_int32(tolua_S, 6,(int *)&arg4);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CLabel* ret = cocos2d::cocoswidget::CLabel::createWithSystemFont(arg0, arg1, arg2, arg3, arg4);
        object_to_luaval<cocos2d::cocoswidget::CLabel>(tolua_S, "cc.cocoswidget::CLabel",(cocos2d::cocoswidget::CLabel*)ret);
        return 1;
    }
    if (argc == 6)
    {
        std::string arg0;
        std::string arg1;
        double arg2;
        cocos2d::Size arg3;
        cocos2d::TextHAlignment arg4;
        cocos2d::TextVAlignment arg5;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        ok &= luaval_to_std_string(tolua_S, 3,&arg1);
        ok &= luaval_to_number(tolua_S, 4,&arg2);
        ok &= luaval_to_size(tolua_S, 5, &arg3);
        ok &= luaval_to_int32(tolua_S, 6,(int *)&arg4);
        ok &= luaval_to_int32(tolua_S, 7,(int *)&arg5);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CLabel* ret = cocos2d::cocoswidget::CLabel::createWithSystemFont(arg0, arg1, arg2, arg3, arg4, arg5);
        object_to_luaval<cocos2d::cocoswidget::CLabel>(tolua_S, "cc.cocoswidget::CLabel",(cocos2d::cocoswidget::CLabel*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createWithSystemFont",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLabel_createWithSystemFont'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CLabel_createWithTTF(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 3)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);
            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1);
            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2);
            if (!ok) { break; }
            cocos2d::cocoswidget::CLabel* ret = cocos2d::cocoswidget::CLabel::createWithTTF(arg0, arg1, arg2);
            object_to_luaval<cocos2d::cocoswidget::CLabel>(tolua_S, "cc.cocoswidget::CLabel",(cocos2d::cocoswidget::CLabel*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 4)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);
            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1);
            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2);
            if (!ok) { break; }
            cocos2d::Size arg3;
            ok &= luaval_to_size(tolua_S, 5, &arg3);
            if (!ok) { break; }
            cocos2d::cocoswidget::CLabel* ret = cocos2d::cocoswidget::CLabel::createWithTTF(arg0, arg1, arg2, arg3);
            object_to_luaval<cocos2d::cocoswidget::CLabel>(tolua_S, "cc.cocoswidget::CLabel",(cocos2d::cocoswidget::CLabel*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 5)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);
            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1);
            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2);
            if (!ok) { break; }
            cocos2d::Size arg3;
            ok &= luaval_to_size(tolua_S, 5, &arg3);
            if (!ok) { break; }
            cocos2d::TextHAlignment arg4;
            ok &= luaval_to_int32(tolua_S, 6,(int *)&arg4);
            if (!ok) { break; }
            cocos2d::cocoswidget::CLabel* ret = cocos2d::cocoswidget::CLabel::createWithTTF(arg0, arg1, arg2, arg3, arg4);
            object_to_luaval<cocos2d::cocoswidget::CLabel>(tolua_S, "cc.cocoswidget::CLabel",(cocos2d::cocoswidget::CLabel*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 6)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);
            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1);
            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2);
            if (!ok) { break; }
            cocos2d::Size arg3;
            ok &= luaval_to_size(tolua_S, 5, &arg3);
            if (!ok) { break; }
            cocos2d::TextHAlignment arg4;
            ok &= luaval_to_int32(tolua_S, 6,(int *)&arg4);
            if (!ok) { break; }
            cocos2d::TextVAlignment arg5;
            ok &= luaval_to_int32(tolua_S, 7,(int *)&arg5);
            if (!ok) { break; }
            cocos2d::cocoswidget::CLabel* ret = cocos2d::cocoswidget::CLabel::createWithTTF(arg0, arg1, arg2, arg3, arg4, arg5);
            object_to_luaval<cocos2d::cocoswidget::CLabel>(tolua_S, "cc.cocoswidget::CLabel",(cocos2d::cocoswidget::CLabel*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            cocos2d::_ttfConfig arg0;
            #pragma warning NO CONVERSION TO NATIVE FOR _ttfConfig;
            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1);
            if (!ok) { break; }
            cocos2d::cocoswidget::CLabel* ret = cocos2d::cocoswidget::CLabel::createWithTTF(arg0, arg1);
            object_to_luaval<cocos2d::cocoswidget::CLabel>(tolua_S, "cc.cocoswidget::CLabel",(cocos2d::cocoswidget::CLabel*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            cocos2d::_ttfConfig arg0;
            #pragma warning NO CONVERSION TO NATIVE FOR _ttfConfig;
            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1);
            if (!ok) { break; }
            cocos2d::TextHAlignment arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);
            if (!ok) { break; }
            cocos2d::cocoswidget::CLabel* ret = cocos2d::cocoswidget::CLabel::createWithTTF(arg0, arg1, arg2);
            object_to_luaval<cocos2d::cocoswidget::CLabel>(tolua_S, "cc.cocoswidget::CLabel",(cocos2d::cocoswidget::CLabel*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 4)
        {
            cocos2d::_ttfConfig arg0;
            #pragma warning NO CONVERSION TO NATIVE FOR _ttfConfig;
            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1);
            if (!ok) { break; }
            cocos2d::TextHAlignment arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);
            if (!ok) { break; }
            int arg3;
            ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3);
            if (!ok) { break; }
            cocos2d::cocoswidget::CLabel* ret = cocos2d::cocoswidget::CLabel::createWithTTF(arg0, arg1, arg2, arg3);
            object_to_luaval<cocos2d::cocoswidget::CLabel>(tolua_S, "cc.cocoswidget::CLabel",(cocos2d::cocoswidget::CLabel*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "createWithTTF",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLabel_createWithTTF'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CLabel_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CLabel();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CLabel");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CLabel",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLabel_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CLabel_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CLabel)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CLabel(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CLabel");
    tolua_cclass(tolua_S,"CLabel","cc.cocoswidget::CLabel","cc.Label",nullptr);

    tolua_beginmodule(tolua_S,"CLabel");
        tolua_function(tolua_S,"setMiddleLine",lua_cocos2dx_cocoswidget_CLabel_setMiddleLine);
        tolua_function(tolua_S,"onTouchMoved",lua_cocos2dx_cocoswidget_CLabel_onTouchMoved);
        tolua_function(tolua_S,"draw",lua_cocos2dx_cocoswidget_CLabel_draw);
        tolua_function(tolua_S,"getUnderLine",lua_cocos2dx_cocoswidget_CLabel_getUnderLine);
        tolua_function(tolua_S,"getMiddleLine",lua_cocos2dx_cocoswidget_CLabel_getMiddleLine);
        tolua_function(tolua_S,"onTouchCancelled",lua_cocos2dx_cocoswidget_CLabel_onTouchCancelled);
        tolua_function(tolua_S,"onTouchBegan",lua_cocos2dx_cocoswidget_CLabel_onTouchBegan);
        tolua_function(tolua_S,"setUnderLine",lua_cocos2dx_cocoswidget_CLabel_setUnderLine);
        tolua_function(tolua_S,"onTouchEnded",lua_cocos2dx_cocoswidget_CLabel_onTouchEnded);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CLabel_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_CLabel_create);
        tolua_function(tolua_S,"createWithSystemFont", lua_cocos2dx_cocoswidget_CLabel_createWithSystemFont);
        tolua_function(tolua_S,"createWithTTF", lua_cocos2dx_cocoswidget_CLabel_createWithTTF);
		tolua_function(tolua_S, "setOnClickScriptHandler", lua_cocos2dx_cocoswidget_CLabel_setOnClickScriptHandler);
		tolua_function(tolua_S, "setOnLongClickScriptHandler", lua_cocos2dx_cocoswidget_CLabel_setOnLongClickScriptHandler);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CLabel).name();
    g_luaType[typeName] = "cc.cocoswidget::CLabel";
    g_typeCast["CLabel"] = "cc.cocoswidget::CLabel";
    return 1;
}

int lua_cocos2dx_cocoswidget_CButton_onTouchEnded(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_onTouchEnded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchEnded(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchEnded",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_onTouchEnded'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_setNormalTexture(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_setNormalTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Texture2D* arg0;

        ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);
        if(!ok)
            return 0;
        cobj->setNormalTexture(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setNormalTexture",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_setNormalTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_onTouchMoved(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_onTouchMoved'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchMoved(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchMoved",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_onTouchMoved'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_setCascadeTextSizeEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_setCascadeTextSizeEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setCascadeTextSizeEnabled(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        bool arg0;
        cocos2d::Size arg1;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);

        ok &= luaval_to_size(tolua_S, 3, &arg1);
        if(!ok)
            return 0;
        cobj->setCascadeTextSizeEnabled(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCascadeTextSizeEnabled",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_setCascadeTextSizeEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_getDisabledImage(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_getDisabledImage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->getDisabledImage();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDisabledImage",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_getDisabledImage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_setNormalSpriteFrame(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_setNormalSpriteFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::SpriteFrame* arg0;

        ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);
        if(!ok)
            return 0;
        cobj->setNormalSpriteFrame(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setNormalSpriteFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_setNormalSpriteFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_getText(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_getText'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getText();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getText",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_getText'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_getNormalImage(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_getNormalImage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->getNormalImage();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getNormalImage",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_getNormalImage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_getLabel(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_getLabel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CLabel* ret = cobj->getLabel();
        object_to_luaval<cocos2d::cocoswidget::CLabel>(tolua_S, "cc.cocoswidget::CLabel",(cocos2d::cocoswidget::CLabel*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getLabel",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_getLabel'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_setDisabledSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_setDisabledSpriteFrameName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setDisabledSpriteFrameName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDisabledSpriteFrameName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_setDisabledSpriteFrameName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_setSelectedSpriteFrame(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_setSelectedSpriteFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::SpriteFrame* arg0;

        ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);
        if(!ok)
            return 0;
        cobj->setSelectedSpriteFrame(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSelectedSpriteFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_setSelectedSpriteFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_getSelectedImage(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_getSelectedImage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->getSelectedImage();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getSelectedImage",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_getSelectedImage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_init(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_initText(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_initText'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        std::string arg0;
        std::string arg1;
        double arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_std_string(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cobj->initText(arg0, arg1, arg2);
        return 0;
    }
    if (argc == 4) 
    {
        std::string arg0;
        std::string arg1;
        double arg2;
        cocos2d::Size arg3;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_std_string(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_size(tolua_S, 5, &arg3);
        if(!ok)
            return 0;
        cobj->initText(arg0, arg1, arg2, arg3);
        return 0;
    }
    if (argc == 5) 
    {
        std::string arg0;
        std::string arg1;
        double arg2;
        cocos2d::Size arg3;
        cocos2d::Color3B arg4;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_std_string(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_size(tolua_S, 5, &arg3);

        ok &= luaval_to_color3b(tolua_S, 6, &arg4);
        if(!ok)
            return 0;
        cobj->initText(arg0, arg1, arg2, arg3, arg4);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initText",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_initText'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_setDisabledSpriteFrame(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_setDisabledSpriteFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::SpriteFrame* arg0;

        ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);
        if(!ok)
            return 0;
        cobj->setDisabledSpriteFrame(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDisabledSpriteFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_setDisabledSpriteFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_setEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_setEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setEnabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setEnabled",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_setEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_setNormalSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_setNormalSpriteFrameName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setNormalSpriteFrameName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setNormalSpriteFrameName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_setNormalSpriteFrameName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_setSelectedImage(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_setSelectedImage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setSelectedImage(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSelectedImage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_setSelectedImage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_initWith9Sprite(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_initWith9Sprite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        cocos2d::Size arg0;
        const char* arg1;
        const char* arg2;
        const char* arg3;

        ok &= luaval_to_size(tolua_S, 2, &arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();

        std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp); arg3 = arg3_tmp.c_str();
        if(!ok)
            return 0;
        bool ret = cobj->initWith9Sprite(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWith9Sprite",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_initWith9Sprite'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_onTouchCancelled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_onTouchCancelled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchCancelled(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchCancelled",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_onTouchCancelled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_onTouchBegan(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_onTouchBegan'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Touch* arg0;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);
        if(!ok)
            return 0;
        int ret = (int)cobj->onTouchBegan(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchBegan",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_onTouchBegan'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_setScale9Enabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_setScale9Enabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setScale9Enabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setScale9Enabled",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_setScale9Enabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_isScale9Enabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_isScale9Enabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isScale9Enabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isScale9Enabled",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_isScale9Enabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_setContentSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_setContentSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setContentSize(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setContentSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_setContentSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_setLabelOffset(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_setLabelOffset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setLabelOffset(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setLabelOffset",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_setLabelOffset'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_initWithFile(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_initWithFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        const char* arg0;
        const char* arg1;
        const char* arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();
        if(!ok)
            return 0;
        bool ret = cobj->initWithFile(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWithFile",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_initWithFile'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_setNormalImage(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_setNormalImage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setNormalImage(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setNormalImage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_setNormalImage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_setDisabledImage(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_setDisabledImage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setDisabledImage(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDisabledImage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_setDisabledImage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_setSelectedTexture(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_setSelectedTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Texture2D* arg0;

        ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);
        if(!ok)
            return 0;
        cobj->setSelectedTexture(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSelectedTexture",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_setSelectedTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_setSelectedSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_setSelectedSpriteFrameName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setSelectedSpriteFrameName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSelectedSpriteFrameName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_setSelectedSpriteFrameName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_setDisabledTexture(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_setDisabledTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Texture2D* arg0;

        ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);
        if(!ok)
            return 0;
        cobj->setDisabledTexture(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDisabledTexture",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_setDisabledTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_setText(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CButton_setText'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setText(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setText",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_setText'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            cocos2d::cocoswidget::CButton* ret = cocos2d::cocoswidget::CButton::create(arg0);
            object_to_luaval<cocos2d::cocoswidget::CButton>(tolua_S, "cc.cocoswidget::CButton",(cocos2d::cocoswidget::CButton*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
            if (!ok) { break; }
            cocos2d::cocoswidget::CButton* ret = cocos2d::cocoswidget::CButton::create(arg0, arg1);
            object_to_luaval<cocos2d::cocoswidget::CButton>(tolua_S, "cc.cocoswidget::CButton",(cocos2d::cocoswidget::CButton*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
            if (!ok) { break; }
            const char* arg2;
            std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();
            if (!ok) { break; }
            cocos2d::cocoswidget::CButton* ret = cocos2d::cocoswidget::CButton::create(arg0, arg1, arg2);
            object_to_luaval<cocos2d::cocoswidget::CButton>(tolua_S, "cc.cocoswidget::CButton",(cocos2d::cocoswidget::CButton*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            cocos2d::cocoswidget::CButton* ret = cocos2d::cocoswidget::CButton::create();
            object_to_luaval<cocos2d::cocoswidget::CButton>(tolua_S, "cc.cocoswidget::CButton",(cocos2d::cocoswidget::CButton*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_createWith9Sprite(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CButton",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        cocos2d::Size arg0;
        const char* arg1;
        ok &= luaval_to_size(tolua_S, 2, &arg0);
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CButton* ret = cocos2d::cocoswidget::CButton::createWith9Sprite(arg0, arg1);
        object_to_luaval<cocos2d::cocoswidget::CButton>(tolua_S, "cc.cocoswidget::CButton",(cocos2d::cocoswidget::CButton*)ret);
        return 1;
    }
    if (argc == 3)
    {
        cocos2d::Size arg0;
        const char* arg1;
        const char* arg2;
        ok &= luaval_to_size(tolua_S, 2, &arg0);
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CButton* ret = cocos2d::cocoswidget::CButton::createWith9Sprite(arg0, arg1, arg2);
        object_to_luaval<cocos2d::cocoswidget::CButton>(tolua_S, "cc.cocoswidget::CButton",(cocos2d::cocoswidget::CButton*)ret);
        return 1;
    }
    if (argc == 4)
    {
        cocos2d::Size arg0;
        const char* arg1;
        const char* arg2;
        const char* arg3;
        ok &= luaval_to_size(tolua_S, 2, &arg0);
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();
        std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp); arg3 = arg3_tmp.c_str();
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CButton* ret = cocos2d::cocoswidget::CButton::createWith9Sprite(arg0, arg1, arg2, arg3);
        object_to_luaval<cocos2d::cocoswidget::CButton>(tolua_S, "cc.cocoswidget::CButton",(cocos2d::cocoswidget::CButton*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createWith9Sprite",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_createWith9Sprite'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CButton_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CButton();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CButton");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CButton",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CButton_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CButton_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CButton)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CButton(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CButton");
    tolua_cclass(tolua_S,"CButton","cc.cocoswidget::CButton","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"CButton");
        tolua_function(tolua_S,"onTouchEnded",lua_cocos2dx_cocoswidget_CButton_onTouchEnded);
        tolua_function(tolua_S,"setNormalTexture",lua_cocos2dx_cocoswidget_CButton_setNormalTexture);
        tolua_function(tolua_S,"onTouchMoved",lua_cocos2dx_cocoswidget_CButton_onTouchMoved);
        tolua_function(tolua_S,"setCascadeTextSizeEnabled",lua_cocos2dx_cocoswidget_CButton_setCascadeTextSizeEnabled);
        tolua_function(tolua_S,"getDisabledImage",lua_cocos2dx_cocoswidget_CButton_getDisabledImage);
        tolua_function(tolua_S,"setNormalSpriteFrame",lua_cocos2dx_cocoswidget_CButton_setNormalSpriteFrame);
        tolua_function(tolua_S,"getText",lua_cocos2dx_cocoswidget_CButton_getText);
        tolua_function(tolua_S,"getNormalImage",lua_cocos2dx_cocoswidget_CButton_getNormalImage);
        tolua_function(tolua_S,"getLabel",lua_cocos2dx_cocoswidget_CButton_getLabel);
        tolua_function(tolua_S,"setDisabledSpriteFrameName",lua_cocos2dx_cocoswidget_CButton_setDisabledSpriteFrameName);
        tolua_function(tolua_S,"setSelectedSpriteFrame",lua_cocos2dx_cocoswidget_CButton_setSelectedSpriteFrame);
        tolua_function(tolua_S,"getSelectedImage",lua_cocos2dx_cocoswidget_CButton_getSelectedImage);
        tolua_function(tolua_S,"init",lua_cocos2dx_cocoswidget_CButton_init);
        tolua_function(tolua_S,"initText",lua_cocos2dx_cocoswidget_CButton_initText);
        tolua_function(tolua_S,"setDisabledSpriteFrame",lua_cocos2dx_cocoswidget_CButton_setDisabledSpriteFrame);
        tolua_function(tolua_S,"setEnabled",lua_cocos2dx_cocoswidget_CButton_setEnabled);
        tolua_function(tolua_S,"setNormalSpriteFrameName",lua_cocos2dx_cocoswidget_CButton_setNormalSpriteFrameName);
        tolua_function(tolua_S,"setSelectedImage",lua_cocos2dx_cocoswidget_CButton_setSelectedImage);
        tolua_function(tolua_S,"initWith9Sprite",lua_cocos2dx_cocoswidget_CButton_initWith9Sprite);
        tolua_function(tolua_S,"onTouchCancelled",lua_cocos2dx_cocoswidget_CButton_onTouchCancelled);
        tolua_function(tolua_S,"onTouchBegan",lua_cocos2dx_cocoswidget_CButton_onTouchBegan);
        tolua_function(tolua_S,"setScale9Enabled",lua_cocos2dx_cocoswidget_CButton_setScale9Enabled);
        tolua_function(tolua_S,"isScale9Enabled",lua_cocos2dx_cocoswidget_CButton_isScale9Enabled);
        tolua_function(tolua_S,"setContentSize",lua_cocos2dx_cocoswidget_CButton_setContentSize);
        tolua_function(tolua_S,"setLabelOffset",lua_cocos2dx_cocoswidget_CButton_setLabelOffset);
        tolua_function(tolua_S,"initWithFile",lua_cocos2dx_cocoswidget_CButton_initWithFile);
        tolua_function(tolua_S,"setNormalImage",lua_cocos2dx_cocoswidget_CButton_setNormalImage);
        tolua_function(tolua_S,"setDisabledImage",lua_cocos2dx_cocoswidget_CButton_setDisabledImage);
        tolua_function(tolua_S,"setSelectedTexture",lua_cocos2dx_cocoswidget_CButton_setSelectedTexture);
        tolua_function(tolua_S,"setSelectedSpriteFrameName",lua_cocos2dx_cocoswidget_CButton_setSelectedSpriteFrameName);
        tolua_function(tolua_S,"setDisabledTexture",lua_cocos2dx_cocoswidget_CButton_setDisabledTexture);
        tolua_function(tolua_S,"setText",lua_cocos2dx_cocoswidget_CButton_setText);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CButton_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_CButton_create);
        tolua_function(tolua_S,"createWith9Sprite", lua_cocos2dx_cocoswidget_CButton_createWith9Sprite);
		tolua_function(tolua_S, "setOnClickScriptHandler", lua_cocos2dx_cocoswidget_CButton_setOnClickScriptHandler);
		tolua_function(tolua_S, "setOnLongClickScriptHandler", lua_cocos2dx_cocoswidget_CButton_setOnLongClickScriptHandler);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CButton).name();
    g_luaType[typeName] = "cc.cocoswidget::CButton";
    g_typeCast["CButton"] = "cc.cocoswidget::CButton";
    return 1;
}

int lua_cocos2dx_cocoswidget_CToggleView_setEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CToggleView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CToggleView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CToggleView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CToggleView_setEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setEnabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setEnabled",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CToggleView_setEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CToggleView_onTouchEnded(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CToggleView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CToggleView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CToggleView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CToggleView_onTouchEnded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchEnded(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchEnded",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CToggleView_onTouchEnded'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CToggleView_onTouchMoved(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CToggleView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CToggleView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CToggleView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CToggleView_onTouchMoved'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchMoved(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchMoved",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CToggleView_onTouchMoved'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CToggleView_setChecked(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CToggleView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CToggleView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CToggleView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CToggleView_setChecked'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setChecked(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setChecked",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CToggleView_setChecked'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CToggleView_onTouchCancelled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CToggleView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CToggleView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CToggleView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CToggleView_onTouchCancelled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchCancelled(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchCancelled",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CToggleView_onTouchCancelled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CToggleView_onTouchBegan(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CToggleView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CToggleView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CToggleView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CToggleView_onTouchBegan'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Touch* arg0;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);
        if(!ok)
            return 0;
        int ret = (int)cobj->onTouchBegan(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchBegan",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CToggleView_onTouchBegan'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CToggleView_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CToggleView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            cocos2d::cocoswidget::CToggleView* ret = cocos2d::cocoswidget::CToggleView::create(arg0);
            object_to_luaval<cocos2d::cocoswidget::CToggleView>(tolua_S, "cc.cocoswidget::CToggleView",(cocos2d::cocoswidget::CToggleView*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
            if (!ok) { break; }
            cocos2d::cocoswidget::CToggleView* ret = cocos2d::cocoswidget::CToggleView::create(arg0, arg1);
            object_to_luaval<cocos2d::cocoswidget::CToggleView>(tolua_S, "cc.cocoswidget::CToggleView",(cocos2d::cocoswidget::CToggleView*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
            if (!ok) { break; }
            const char* arg2;
            std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();
            if (!ok) { break; }
            cocos2d::cocoswidget::CToggleView* ret = cocos2d::cocoswidget::CToggleView::create(arg0, arg1, arg2);
            object_to_luaval<cocos2d::cocoswidget::CToggleView>(tolua_S, "cc.cocoswidget::CToggleView",(cocos2d::cocoswidget::CToggleView*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            cocos2d::cocoswidget::CToggleView* ret = cocos2d::cocoswidget::CToggleView::create();
            object_to_luaval<cocos2d::cocoswidget::CToggleView>(tolua_S, "cc.cocoswidget::CToggleView",(cocos2d::cocoswidget::CToggleView*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CToggleView_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CToggleView_createWith9Sprite(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CToggleView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        cocos2d::Size arg0;
        const char* arg1;
        ok &= luaval_to_size(tolua_S, 2, &arg0);
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CToggleView* ret = cocos2d::cocoswidget::CToggleView::createWith9Sprite(arg0, arg1);
        object_to_luaval<cocos2d::cocoswidget::CToggleView>(tolua_S, "cc.cocoswidget::CToggleView",(cocos2d::cocoswidget::CToggleView*)ret);
        return 1;
    }
    if (argc == 3)
    {
        cocos2d::Size arg0;
        const char* arg1;
        const char* arg2;
        ok &= luaval_to_size(tolua_S, 2, &arg0);
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CToggleView* ret = cocos2d::cocoswidget::CToggleView::createWith9Sprite(arg0, arg1, arg2);
        object_to_luaval<cocos2d::cocoswidget::CToggleView>(tolua_S, "cc.cocoswidget::CToggleView",(cocos2d::cocoswidget::CToggleView*)ret);
        return 1;
    }
    if (argc == 4)
    {
        cocos2d::Size arg0;
        const char* arg1;
        const char* arg2;
        const char* arg3;
        ok &= luaval_to_size(tolua_S, 2, &arg0);
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();
        std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp); arg3 = arg3_tmp.c_str();
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CToggleView* ret = cocos2d::cocoswidget::CToggleView::createWith9Sprite(arg0, arg1, arg2, arg3);
        object_to_luaval<cocos2d::cocoswidget::CToggleView>(tolua_S, "cc.cocoswidget::CToggleView",(cocos2d::cocoswidget::CToggleView*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createWith9Sprite",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CToggleView_createWith9Sprite'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CToggleView_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CToggleView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CToggleView();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CToggleView");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CToggleView",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CToggleView_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CToggleView_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CToggleView)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CToggleView(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CToggleView");
    tolua_cclass(tolua_S,"CToggleView","cc.cocoswidget::CToggleView","cc.cocoswidget::CButton",nullptr);

    tolua_beginmodule(tolua_S,"CToggleView");
        tolua_function(tolua_S,"setEnabled",lua_cocos2dx_cocoswidget_CToggleView_setEnabled);
        tolua_function(tolua_S,"onTouchEnded",lua_cocos2dx_cocoswidget_CToggleView_onTouchEnded);
        tolua_function(tolua_S,"onTouchMoved",lua_cocos2dx_cocoswidget_CToggleView_onTouchMoved);
        tolua_function(tolua_S,"setChecked",lua_cocos2dx_cocoswidget_CToggleView_setChecked);
        tolua_function(tolua_S,"onTouchCancelled",lua_cocos2dx_cocoswidget_CToggleView_onTouchCancelled);
        tolua_function(tolua_S,"onTouchBegan",lua_cocos2dx_cocoswidget_CToggleView_onTouchBegan);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CToggleView_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_CToggleView_create);
        tolua_function(tolua_S,"createWith9Sprite", lua_cocos2dx_cocoswidget_CToggleView_createWith9Sprite);
		tolua_function(tolua_S, "setOnCheckScriptHandler", lua_cocos2dx_cocoswidget_CToggleView_setOnCheckScriptHandler);
		tolua_function(tolua_S, "setOnClickScriptHandler", lua_cocos2dx_cocoswidget_CToggleView_setOnClickScriptHandler);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CToggleView).name();
    g_luaType[typeName] = "cc.cocoswidget::CToggleView";
    g_typeCast["CToggleView"] = "cc.cocoswidget::CToggleView";
    return 1;
}

int lua_cocos2dx_cocoswidget_CLabelAtlas_onTouchMoved(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLabelAtlas* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLabelAtlas",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLabelAtlas*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLabelAtlas_onTouchMoved'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchMoved(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchMoved",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLabelAtlas_onTouchMoved'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLabelAtlas_onTouchEnded(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLabelAtlas* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLabelAtlas",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLabelAtlas*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLabelAtlas_onTouchEnded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchEnded(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchEnded",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLabelAtlas_onTouchEnded'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLabelAtlas_onTouchCancelled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLabelAtlas* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLabelAtlas",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLabelAtlas*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLabelAtlas_onTouchCancelled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchCancelled(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchCancelled",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLabelAtlas_onTouchCancelled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLabelAtlas_onTouchBegan(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLabelAtlas* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLabelAtlas",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLabelAtlas*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLabelAtlas_onTouchBegan'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Touch* arg0;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);
        if(!ok)
            return 0;
        int ret = (int)cobj->onTouchBegan(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchBegan",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLabelAtlas_onTouchBegan'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLabelAtlas_init(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLabelAtlas* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLabelAtlas",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLabelAtlas*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLabelAtlas_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLabelAtlas_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLabelAtlas_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CLabelAtlas",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
            if (!ok) { break; }
            cocos2d::cocoswidget::CLabelAtlas* ret = cocos2d::cocoswidget::CLabelAtlas::create(arg0, arg1);
            object_to_luaval<cocos2d::cocoswidget::CLabelAtlas>(tolua_S, "cc.cocoswidget::CLabelAtlas",(cocos2d::cocoswidget::CLabelAtlas*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 5)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
            if (!ok) { break; }
            unsigned int arg2;
            ok &= luaval_to_uint32(tolua_S, 4,&arg2);
            if (!ok) { break; }
            unsigned int arg3;
            ok &= luaval_to_uint32(tolua_S, 5,&arg3);
            if (!ok) { break; }
            unsigned int arg4;
            ok &= luaval_to_uint32(tolua_S, 6,&arg4);
            if (!ok) { break; }
            cocos2d::cocoswidget::CLabelAtlas* ret = cocos2d::cocoswidget::CLabelAtlas::create(arg0, arg1, arg2, arg3, arg4);
            object_to_luaval<cocos2d::cocoswidget::CLabelAtlas>(tolua_S, "cc.cocoswidget::CLabelAtlas",(cocos2d::cocoswidget::CLabelAtlas*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 5);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLabelAtlas_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CLabelAtlas_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLabelAtlas* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CLabelAtlas();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CLabelAtlas");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CLabelAtlas",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLabelAtlas_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CLabelAtlas_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CLabelAtlas)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CLabelAtlas(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CLabelAtlas");
    tolua_cclass(tolua_S,"CLabelAtlas","cc.cocoswidget::CLabelAtlas","cc.LabelAtlas",nullptr);

    tolua_beginmodule(tolua_S,"CLabelAtlas");
        tolua_function(tolua_S,"onTouchMoved",lua_cocos2dx_cocoswidget_CLabelAtlas_onTouchMoved);
        tolua_function(tolua_S,"onTouchEnded",lua_cocos2dx_cocoswidget_CLabelAtlas_onTouchEnded);
        tolua_function(tolua_S,"onTouchCancelled",lua_cocos2dx_cocoswidget_CLabelAtlas_onTouchCancelled);
        tolua_function(tolua_S,"onTouchBegan",lua_cocos2dx_cocoswidget_CLabelAtlas_onTouchBegan);
        tolua_function(tolua_S,"init",lua_cocos2dx_cocoswidget_CLabelAtlas_init);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CLabelAtlas_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_CLabelAtlas_create);
		tolua_function(tolua_S, "setOnClickScriptHandler", lua_cocos2dx_cocoswidget_CLabelAtlas_setOnClickScriptHandler);
		tolua_function(tolua_S, "setOnLongClickScriptHandler", lua_cocos2dx_cocoswidget_CLabelAtlas_setOnLongClickScriptHandler);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CLabelAtlas).name();
    g_luaType[typeName] = "cc.cocoswidget::CLabelAtlas";
    g_typeCast["CLabelAtlas"] = "cc.cocoswidget::CLabelAtlas";
    return 1;
}

int lua_cocos2dx_cocoswidget_CLabelBMFont_onTouchMoved(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLabelBMFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLabelBMFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLabelBMFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLabelBMFont_onTouchMoved'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchMoved(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchMoved",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLabelBMFont_onTouchMoved'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLabelBMFont_onTouchEnded(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLabelBMFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLabelBMFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLabelBMFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLabelBMFont_onTouchEnded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchEnded(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchEnded",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLabelBMFont_onTouchEnded'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLabelBMFont_onTouchCancelled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLabelBMFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLabelBMFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLabelBMFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLabelBMFont_onTouchCancelled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchCancelled(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchCancelled",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLabelBMFont_onTouchCancelled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLabelBMFont_onTouchBegan(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLabelBMFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLabelBMFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLabelBMFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLabelBMFont_onTouchBegan'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Touch* arg0;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);
        if(!ok)
            return 0;
        int ret = (int)cobj->onTouchBegan(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchBegan",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLabelBMFont_onTouchBegan'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLabelBMFont_init(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLabelBMFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLabelBMFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLabelBMFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLabelBMFont_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLabelBMFont_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLabelBMFont_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CLabelBMFont",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);
            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1);
            if (!ok) { break; }
            cocos2d::cocoswidget::CLabelBMFont* ret = cocos2d::cocoswidget::CLabelBMFont::create(arg0, arg1);
            object_to_luaval<cocos2d::cocoswidget::CLabelBMFont>(tolua_S, "cc.cocoswidget::CLabelBMFont",(cocos2d::cocoswidget::CLabelBMFont*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);
            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1);
            if (!ok) { break; }
            cocos2d::TextHAlignment arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);
            if (!ok) { break; }
            cocos2d::cocoswidget::CLabelBMFont* ret = cocos2d::cocoswidget::CLabelBMFont::create(arg0, arg1, arg2);
            object_to_luaval<cocos2d::cocoswidget::CLabelBMFont>(tolua_S, "cc.cocoswidget::CLabelBMFont",(cocos2d::cocoswidget::CLabelBMFont*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 4)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);
            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1);
            if (!ok) { break; }
            cocos2d::TextHAlignment arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);
            if (!ok) { break; }
            int arg3;
            ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3);
            if (!ok) { break; }
            cocos2d::cocoswidget::CLabelBMFont* ret = cocos2d::cocoswidget::CLabelBMFont::create(arg0, arg1, arg2, arg3);
            object_to_luaval<cocos2d::cocoswidget::CLabelBMFont>(tolua_S, "cc.cocoswidget::CLabelBMFont",(cocos2d::cocoswidget::CLabelBMFont*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 5)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);
            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1);
            if (!ok) { break; }
            cocos2d::TextHAlignment arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);
            if (!ok) { break; }
            int arg3;
            ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3);
            if (!ok) { break; }
            cocos2d::Point arg4;
            ok &= luaval_to_point(tolua_S, 6, &arg4);
            if (!ok) { break; }
            cocos2d::cocoswidget::CLabelBMFont* ret = cocos2d::cocoswidget::CLabelBMFont::create(arg0, arg1, arg2, arg3, arg4);
            object_to_luaval<cocos2d::cocoswidget::CLabelBMFont>(tolua_S, "cc.cocoswidget::CLabelBMFont",(cocos2d::cocoswidget::CLabelBMFont*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            cocos2d::cocoswidget::CLabelBMFont* ret = cocos2d::cocoswidget::CLabelBMFont::create();
            object_to_luaval<cocos2d::cocoswidget::CLabelBMFont>(tolua_S, "cc.cocoswidget::CLabelBMFont",(cocos2d::cocoswidget::CLabelBMFont*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLabelBMFont_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CLabelBMFont_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLabelBMFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CLabelBMFont();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CLabelBMFont");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CLabelBMFont",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLabelBMFont_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CLabelBMFont_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CLabelBMFont)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CLabelBMFont(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CLabelBMFont");
    tolua_cclass(tolua_S,"CLabelBMFont","cc.cocoswidget::CLabelBMFont","cc.Label",nullptr);

    tolua_beginmodule(tolua_S,"CLabelBMFont");
        tolua_function(tolua_S,"onTouchMoved",lua_cocos2dx_cocoswidget_CLabelBMFont_onTouchMoved);
        tolua_function(tolua_S,"onTouchEnded",lua_cocos2dx_cocoswidget_CLabelBMFont_onTouchEnded);
        tolua_function(tolua_S,"onTouchCancelled",lua_cocos2dx_cocoswidget_CLabelBMFont_onTouchCancelled);
        tolua_function(tolua_S,"onTouchBegan",lua_cocos2dx_cocoswidget_CLabelBMFont_onTouchBegan);
        tolua_function(tolua_S,"init",lua_cocos2dx_cocoswidget_CLabelBMFont_init);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CLabelBMFont_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_CLabelBMFont_create);
		tolua_function(tolua_S, "setOnClickScriptHandler", lua_cocos2dx_cocoswidget_CLabelBMFont_setOnClickScriptHandler);
		tolua_function(tolua_S, "setOnLongClickScriptHandler", lua_cocos2dx_cocoswidget_CLabelBMFont_setOnLongClickScriptHandler);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CLabelBMFont).name();
    g_luaType[typeName] = "cc.cocoswidget::CLabelBMFont";
    g_typeCast["CLabelBMFont"] = "cc.cocoswidget::CLabelBMFont";
    return 1;
}

int lua_cocos2dx_cocoswidget_CColorView_onTouchEnded(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CColorView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CColorView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CColorView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CColorView_onTouchEnded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchEnded(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchEnded",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CColorView_onTouchEnded'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CColorView_setOpacityModifyRGB(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CColorView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CColorView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CColorView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CColorView_setOpacityModifyRGB'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setOpacityModifyRGB(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOpacityModifyRGB",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CColorView_setOpacityModifyRGB'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CColorView_setCascadeOpacityEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CColorView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CColorView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CColorView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CColorView_setCascadeOpacityEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setCascadeOpacityEnabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCascadeOpacityEnabled",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CColorView_setCascadeOpacityEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CColorView_isOpacityModifyRGB(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CColorView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CColorView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CColorView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CColorView_isOpacityModifyRGB'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isOpacityModifyRGB();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isOpacityModifyRGB",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CColorView_isOpacityModifyRGB'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CColorView_isCascadeOpacityEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CColorView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CColorView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CColorView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CColorView_isCascadeOpacityEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isCascadeOpacityEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isCascadeOpacityEnabled",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CColorView_isCascadeOpacityEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CColorView_setCascadeColorEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CColorView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CColorView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CColorView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CColorView_setCascadeColorEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setCascadeColorEnabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCascadeColorEnabled",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CColorView_setCascadeColorEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CColorView_setOpacity(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CColorView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CColorView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CColorView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CColorView_setOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setOpacity(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOpacity",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CColorView_setOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CColorView_updateDisplayedOpacity(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CColorView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CColorView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CColorView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CColorView_updateDisplayedOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->updateDisplayedOpacity(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "updateDisplayedOpacity",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CColorView_updateDisplayedOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CColorView_init(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CColorView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CColorView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CColorView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CColorView_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CColorView_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CColorView_initWithColor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CColorView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CColorView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CColorView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CColorView_initWithColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color4B arg0;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        bool ret = cobj->initWithColor(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWithColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CColorView_initWithColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CColorView_getOpacity(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CColorView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CColorView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CColorView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CColorView_getOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        uint16_t ret = cobj->getOpacity();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getOpacity",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CColorView_getOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CColorView_onTouchMoved(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CColorView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CColorView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CColorView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CColorView_onTouchMoved'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchMoved(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchMoved",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CColorView_onTouchMoved'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CColorView_draw(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CColorView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CColorView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CColorView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CColorView_draw'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Renderer* arg0;
        kmMat4 arg1;
        bool arg2;

        ok &= luaval_to_object<cocos2d::Renderer>(tolua_S, 2, "cc.Renderer",&arg0);

        ok &= luaval_to_kmMat4(tolua_S, 3, &arg1);

        ok &= luaval_to_boolean(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cobj->draw(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "draw",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CColorView_draw'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CColorView_getBlendFunc(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CColorView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CColorView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CColorView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CColorView_getBlendFunc'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::BlendFunc& ret = cobj->getBlendFunc();
        #pragma warning NO CONVERSION FROM NATIVE FOR BlendFunc;
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBlendFunc",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CColorView_getBlendFunc'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CColorView_getColor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CColorView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CColorView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CColorView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CColorView_getColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Color3B& ret = cobj->getColor();
        color3b_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CColorView_getColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CColorView_getDisplayedOpacity(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CColorView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CColorView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CColorView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CColorView_getDisplayedOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        uint16_t ret = cobj->getDisplayedOpacity();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDisplayedOpacity",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CColorView_getDisplayedOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CColorView_onTouchCancelled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CColorView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CColorView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CColorView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CColorView_onTouchCancelled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchCancelled(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchCancelled",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CColorView_onTouchCancelled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CColorView_onTouchBegan(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CColorView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CColorView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CColorView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CColorView_onTouchBegan'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Touch* arg0;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);
        if(!ok)
            return 0;
        int ret = (int)cobj->onTouchBegan(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchBegan",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CColorView_onTouchBegan'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CColorView_setContentSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CColorView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CColorView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CColorView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CColorView_setContentSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setContentSize(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setContentSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CColorView_setContentSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CColorView_setColor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CColorView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CColorView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CColorView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CColorView_setColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setColor(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CColorView_setColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CColorView_getDisplayedColor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CColorView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CColorView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CColorView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CColorView_getDisplayedColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Color3B& ret = cobj->getDisplayedColor();
        color3b_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDisplayedColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CColorView_getDisplayedColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CColorView_setBlendFunc(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CColorView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CColorView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CColorView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CColorView_setBlendFunc'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::BlendFunc arg0;

        #pragma warning NO CONVERSION TO NATIVE FOR BlendFunc;
        if(!ok)
            return 0;
        cobj->setBlendFunc(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBlendFunc",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CColorView_setBlendFunc'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CColorView_isCascadeColorEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CColorView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CColorView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CColorView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CColorView_isCascadeColorEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isCascadeColorEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isCascadeColorEnabled",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CColorView_isCascadeColorEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CColorView_updateDisplayedColor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CColorView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CColorView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CColorView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CColorView_updateDisplayedColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->updateDisplayedColor(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "updateDisplayedColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CColorView_updateDisplayedColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CColorView_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CColorView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            cocos2d::Color4B arg0;
            ok &=luaval_to_color4b(tolua_S, 2, &arg0);
            if (!ok) { break; }
            cocos2d::cocoswidget::CColorView* ret = cocos2d::cocoswidget::CColorView::create(arg0);
            object_to_luaval<cocos2d::cocoswidget::CColorView>(tolua_S, "cc.cocoswidget::CColorView",(cocos2d::cocoswidget::CColorView*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            cocos2d::cocoswidget::CColorView* ret = cocos2d::cocoswidget::CColorView::create();
            object_to_luaval<cocos2d::cocoswidget::CColorView>(tolua_S, "cc.cocoswidget::CColorView",(cocos2d::cocoswidget::CColorView*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CColorView_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CColorView_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CColorView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CColorView();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CColorView");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CColorView",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CColorView_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CColorView_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CColorView)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CColorView(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CColorView");
    tolua_cclass(tolua_S,"CColorView","cc.cocoswidget::CColorView","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"CColorView");
        tolua_function(tolua_S,"onTouchEnded",lua_cocos2dx_cocoswidget_CColorView_onTouchEnded);
        tolua_function(tolua_S,"setOpacityModifyRGB",lua_cocos2dx_cocoswidget_CColorView_setOpacityModifyRGB);
        tolua_function(tolua_S,"setCascadeOpacityEnabled",lua_cocos2dx_cocoswidget_CColorView_setCascadeOpacityEnabled);
        tolua_function(tolua_S,"isOpacityModifyRGB",lua_cocos2dx_cocoswidget_CColorView_isOpacityModifyRGB);
        tolua_function(tolua_S,"isCascadeOpacityEnabled",lua_cocos2dx_cocoswidget_CColorView_isCascadeOpacityEnabled);
        tolua_function(tolua_S,"setCascadeColorEnabled",lua_cocos2dx_cocoswidget_CColorView_setCascadeColorEnabled);
        tolua_function(tolua_S,"setOpacity",lua_cocos2dx_cocoswidget_CColorView_setOpacity);
        tolua_function(tolua_S,"updateDisplayedOpacity",lua_cocos2dx_cocoswidget_CColorView_updateDisplayedOpacity);
        tolua_function(tolua_S,"init",lua_cocos2dx_cocoswidget_CColorView_init);
        tolua_function(tolua_S,"initWithColor",lua_cocos2dx_cocoswidget_CColorView_initWithColor);
        tolua_function(tolua_S,"getOpacity",lua_cocos2dx_cocoswidget_CColorView_getOpacity);
        tolua_function(tolua_S,"onTouchMoved",lua_cocos2dx_cocoswidget_CColorView_onTouchMoved);
        tolua_function(tolua_S,"draw",lua_cocos2dx_cocoswidget_CColorView_draw);
        tolua_function(tolua_S,"getBlendFunc",lua_cocos2dx_cocoswidget_CColorView_getBlendFunc);
        tolua_function(tolua_S,"getColor",lua_cocos2dx_cocoswidget_CColorView_getColor);
        tolua_function(tolua_S,"getDisplayedOpacity",lua_cocos2dx_cocoswidget_CColorView_getDisplayedOpacity);
        tolua_function(tolua_S,"onTouchCancelled",lua_cocos2dx_cocoswidget_CColorView_onTouchCancelled);
        tolua_function(tolua_S,"onTouchBegan",lua_cocos2dx_cocoswidget_CColorView_onTouchBegan);
        tolua_function(tolua_S,"setContentSize",lua_cocos2dx_cocoswidget_CColorView_setContentSize);
        tolua_function(tolua_S,"setColor",lua_cocos2dx_cocoswidget_CColorView_setColor);
        tolua_function(tolua_S,"getDisplayedColor",lua_cocos2dx_cocoswidget_CColorView_getDisplayedColor);
        tolua_function(tolua_S,"setBlendFunc",lua_cocos2dx_cocoswidget_CColorView_setBlendFunc);
        tolua_function(tolua_S,"isCascadeColorEnabled",lua_cocos2dx_cocoswidget_CColorView_isCascadeColorEnabled);
        tolua_function(tolua_S,"updateDisplayedColor",lua_cocos2dx_cocoswidget_CColorView_updateDisplayedColor);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CColorView_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_CColorView_create);
		tolua_function(tolua_S, "setOnClickScriptHandler", lua_cocos2dx_cocoswidget_CColorView_setOnClickScriptHandler);
		tolua_function(tolua_S, "setOnLongClickScriptHandler", lua_cocos2dx_cocoswidget_CColorView_setOnLongClickScriptHandler);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CColorView).name();
    g_luaType[typeName] = "cc.cocoswidget::CColorView";
    g_typeCast["CColorView"] = "cc.cocoswidget::CColorView";
    return 1;
}

int lua_cocos2dx_cocoswidget_CGradientView_getStartColor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGradientView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGradientView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGradientView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGradientView_getStartColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Color3B& ret = cobj->getStartColor();
        color3b_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getStartColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGradientView_getStartColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGradientView_isCompressedInterpolation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGradientView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGradientView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGradientView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGradientView_isCompressedInterpolation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isCompressedInterpolation();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isCompressedInterpolation",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGradientView_isCompressedInterpolation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGradientView_getStartOpacity(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGradientView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGradientView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGradientView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGradientView_getStartOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        uint16_t ret = cobj->getStartOpacity();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getStartOpacity",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGradientView_getStartOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGradientView_setVector(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGradientView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGradientView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGradientView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGradientView_setVector'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setVector(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setVector",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGradientView_setVector'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGradientView_getEndColor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGradientView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGradientView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGradientView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGradientView_getEndColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Color3B& ret = cobj->getEndColor();
        color3b_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getEndColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGradientView_getEndColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGradientView_setStartOpacity(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGradientView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGradientView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGradientView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGradientView_setStartOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setStartOpacity(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setStartOpacity",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGradientView_setStartOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGradientView_setCompressedInterpolation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGradientView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGradientView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGradientView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGradientView_setCompressedInterpolation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setCompressedInterpolation(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCompressedInterpolation",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGradientView_setCompressedInterpolation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGradientView_setEndOpacity(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGradientView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGradientView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGradientView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGradientView_setEndOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setEndOpacity(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setEndOpacity",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGradientView_setEndOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGradientView_getVector(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGradientView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGradientView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGradientView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGradientView_getVector'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Point& ret = cobj->getVector();
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getVector",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGradientView_getVector'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGradientView_init(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGradientView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGradientView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGradientView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGradientView_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGradientView_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGradientView_setEndColor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGradientView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGradientView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGradientView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGradientView_setEndColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setEndColor(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setEndColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGradientView_setEndColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGradientView_initWithColor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGradientView* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGradientView",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::cocoswidget::CGradientView*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGradientView_initWithColor'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 3) {
            cocos2d::Color4B arg0;
            ok &=luaval_to_color4b(tolua_S, 2, &arg0);

            if (!ok) { break; }
            cocos2d::Color4B arg1;
            ok &=luaval_to_color4b(tolua_S, 3, &arg1);

            if (!ok) { break; }
            cocos2d::Point arg2;
            ok &= luaval_to_point(tolua_S, 4, &arg2);

            if (!ok) { break; }
            bool ret = cobj->initWithColor(arg0, arg1, arg2);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            cocos2d::Color4B arg0;
            ok &=luaval_to_color4b(tolua_S, 2, &arg0);

            if (!ok) { break; }
            cocos2d::Color4B arg1;
            ok &=luaval_to_color4b(tolua_S, 3, &arg1);

            if (!ok) { break; }
            bool ret = cobj->initWithColor(arg0, arg1);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWithColor",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGradientView_initWithColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGradientView_getEndOpacity(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGradientView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGradientView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGradientView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGradientView_getEndOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        uint16_t ret = cobj->getEndOpacity();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getEndOpacity",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGradientView_getEndOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGradientView_setStartColor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGradientView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGradientView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGradientView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGradientView_setStartColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setStartColor(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setStartColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGradientView_setStartColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGradientView_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CGradientView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            cocos2d::Color4B arg0;
            ok &=luaval_to_color4b(tolua_S, 2, &arg0);
            if (!ok) { break; }
            cocos2d::Color4B arg1;
            ok &=luaval_to_color4b(tolua_S, 3, &arg1);
            if (!ok) { break; }
            cocos2d::cocoswidget::CGradientView* ret = cocos2d::cocoswidget::CGradientView::create(arg0, arg1);
            object_to_luaval<cocos2d::cocoswidget::CGradientView>(tolua_S, "cc.cocoswidget::CGradientView",(cocos2d::cocoswidget::CGradientView*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            cocos2d::cocoswidget::CGradientView* ret = cocos2d::cocoswidget::CGradientView::create();
            object_to_luaval<cocos2d::cocoswidget::CGradientView>(tolua_S, "cc.cocoswidget::CGradientView",(cocos2d::cocoswidget::CGradientView*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            cocos2d::Color4B arg0;
            ok &=luaval_to_color4b(tolua_S, 2, &arg0);
            if (!ok) { break; }
            cocos2d::Color4B arg1;
            ok &=luaval_to_color4b(tolua_S, 3, &arg1);
            if (!ok) { break; }
            cocos2d::Point arg2;
            ok &= luaval_to_point(tolua_S, 4, &arg2);
            if (!ok) { break; }
            cocos2d::cocoswidget::CGradientView* ret = cocos2d::cocoswidget::CGradientView::create(arg0, arg1, arg2);
            object_to_luaval<cocos2d::cocoswidget::CGradientView>(tolua_S, "cc.cocoswidget::CGradientView",(cocos2d::cocoswidget::CGradientView*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGradientView_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CGradientView_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGradientView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CGradientView();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CGradientView");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CGradientView",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGradientView_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CGradientView_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CGradientView)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CGradientView(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CGradientView");
    tolua_cclass(tolua_S,"CGradientView","cc.cocoswidget::CGradientView","cc.cocoswidget::CColorView",nullptr);

    tolua_beginmodule(tolua_S,"CGradientView");
        tolua_function(tolua_S,"getStartColor",lua_cocos2dx_cocoswidget_CGradientView_getStartColor);
        tolua_function(tolua_S,"isCompressedInterpolation",lua_cocos2dx_cocoswidget_CGradientView_isCompressedInterpolation);
        tolua_function(tolua_S,"getStartOpacity",lua_cocos2dx_cocoswidget_CGradientView_getStartOpacity);
        tolua_function(tolua_S,"setVector",lua_cocos2dx_cocoswidget_CGradientView_setVector);
        tolua_function(tolua_S,"getEndColor",lua_cocos2dx_cocoswidget_CGradientView_getEndColor);
        tolua_function(tolua_S,"setStartOpacity",lua_cocos2dx_cocoswidget_CGradientView_setStartOpacity);
        tolua_function(tolua_S,"setCompressedInterpolation",lua_cocos2dx_cocoswidget_CGradientView_setCompressedInterpolation);
        tolua_function(tolua_S,"setEndOpacity",lua_cocos2dx_cocoswidget_CGradientView_setEndOpacity);
        tolua_function(tolua_S,"getVector",lua_cocos2dx_cocoswidget_CGradientView_getVector);
        tolua_function(tolua_S,"init",lua_cocos2dx_cocoswidget_CGradientView_init);
        tolua_function(tolua_S,"setEndColor",lua_cocos2dx_cocoswidget_CGradientView_setEndColor);
        tolua_function(tolua_S,"initWithColor",lua_cocos2dx_cocoswidget_CGradientView_initWithColor);
        tolua_function(tolua_S,"getEndOpacity",lua_cocos2dx_cocoswidget_CGradientView_getEndOpacity);
        tolua_function(tolua_S,"setStartColor",lua_cocos2dx_cocoswidget_CGradientView_setStartColor);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CGradientView_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_CGradientView_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CGradientView).name();
    g_luaType[typeName] = "cc.cocoswidget::CGradientView";
    g_typeCast["CGradientView"] = "cc.cocoswidget::CGradientView";
    return 1;
}

int lua_cocos2dx_cocoswidget_CLayout_onTouchMoved(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLayout_onTouchMoved'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchMoved(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchMoved",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLayout_onTouchMoved'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLayout_onTouchEnded(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLayout_onTouchEnded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchEnded(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchEnded",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLayout_onTouchEnded'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLayout_setBackgroundSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLayout_setBackgroundSpriteFrameName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setBackgroundSpriteFrameName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBackgroundSpriteFrameName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLayout_setBackgroundSpriteFrameName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLayout_removeBackgroundColor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLayout_removeBackgroundColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeBackgroundColor();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeBackgroundColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLayout_removeBackgroundColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLayout_getBackgroundImage(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLayout_getBackgroundImage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Sprite* ret = cobj->getBackgroundImage();
        object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBackgroundImage",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLayout_getBackgroundImage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLayout_setBackgroundGradient(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLayout_setBackgroundGradient'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Color4B arg0;
        cocos2d::Color4B arg1;
        cocos2d::Point arg2;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0);

        ok &=luaval_to_color4b(tolua_S, 3, &arg1);

        ok &= luaval_to_point(tolua_S, 4, &arg2);
        if(!ok)
            return 0;
        cobj->setBackgroundGradient(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBackgroundGradient",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLayout_setBackgroundGradient'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLayout_setBackgroundImage(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLayout_setBackgroundImage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setBackgroundImage(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBackgroundImage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLayout_setBackgroundImage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLayout_setBackgroundColor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLayout_setBackgroundColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color4B arg0;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setBackgroundColor(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBackgroundColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLayout_setBackgroundColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLayout_visit(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLayout_visit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Renderer* arg0;
        kmMat4 arg1;
        bool arg2;

        ok &= luaval_to_object<cocos2d::Renderer>(tolua_S, 2, "cc.Renderer",&arg0);

        ok &= luaval_to_kmMat4(tolua_S, 3, &arg1);

        ok &= luaval_to_boolean(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cobj->visit(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "visit",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLayout_visit'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLayout_setBackgroundSpriteFrame(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLayout_setBackgroundSpriteFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::SpriteFrame* arg0;

        ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);
        if(!ok)
            return 0;
        cobj->setBackgroundSpriteFrame(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBackgroundSpriteFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLayout_setBackgroundSpriteFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLayout_onTouchBegan(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLayout_onTouchBegan'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Touch* arg0;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);
        if(!ok)
            return 0;
        int ret = (int)cobj->onTouchBegan(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchBegan",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLayout_onTouchBegan'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLayout_setBackgroundTexture(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLayout_setBackgroundTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Texture2D* arg0;

        ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);
        if(!ok)
            return 0;
        cobj->setBackgroundTexture(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBackgroundTexture",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLayout_setBackgroundTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLayout_init(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLayout_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLayout_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLayout_removeBackgroundImage(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLayout_removeBackgroundImage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeBackgroundImage();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeBackgroundImage",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLayout_removeBackgroundImage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLayout_findWidgetById(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLayout_findWidgetById'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cocos2d::Ref* ret = cobj->findWidgetById(arg0);
        object_to_luaval<cocos2d::Ref>(tolua_S, "cc.Ref",(cocos2d::Ref*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "findWidgetById",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLayout_findWidgetById'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLayout_onTouchCancelled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLayout_onTouchCancelled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchCancelled(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchCancelled",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLayout_onTouchCancelled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLayout_removeBackgroundGradient(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLayout_removeBackgroundGradient'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeBackgroundGradient();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeBackgroundGradient",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLayout_removeBackgroundGradient'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLayout_setContentSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLayout_setContentSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setContentSize(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setContentSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLayout_setContentSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLayout_setBackgroundOpacity(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CLayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CLayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CLayout_setBackgroundOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setBackgroundOpacity(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBackgroundOpacity",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLayout_setBackgroundOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CLayout_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CLayout",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            cocos2d::Size arg0;
            ok &= luaval_to_size(tolua_S, 2, &arg0);
            if (!ok) { break; }
            cocos2d::cocoswidget::CLayout* ret = cocos2d::cocoswidget::CLayout::create(arg0);
            object_to_luaval<cocos2d::cocoswidget::CLayout>(tolua_S, "cc.cocoswidget::CLayout",(cocos2d::cocoswidget::CLayout*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            cocos2d::cocoswidget::CLayout* ret = cocos2d::cocoswidget::CLayout::create();
            object_to_luaval<cocos2d::cocoswidget::CLayout>(tolua_S, "cc.cocoswidget::CLayout",(cocos2d::cocoswidget::CLayout*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLayout_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CLayout_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CLayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CLayout();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CLayout");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CLayout",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CLayout_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CLayout_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CLayout)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CLayout(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CLayout");
    tolua_cclass(tolua_S,"CLayout","cc.cocoswidget::CLayout","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"CLayout");
        tolua_function(tolua_S,"onTouchMoved",lua_cocos2dx_cocoswidget_CLayout_onTouchMoved);
        tolua_function(tolua_S,"onTouchEnded",lua_cocos2dx_cocoswidget_CLayout_onTouchEnded);
        tolua_function(tolua_S,"setBackgroundSpriteFrameName",lua_cocos2dx_cocoswidget_CLayout_setBackgroundSpriteFrameName);
        tolua_function(tolua_S,"removeBackgroundColor",lua_cocos2dx_cocoswidget_CLayout_removeBackgroundColor);
        tolua_function(tolua_S,"getBackgroundImage",lua_cocos2dx_cocoswidget_CLayout_getBackgroundImage);
        tolua_function(tolua_S,"setBackgroundGradient",lua_cocos2dx_cocoswidget_CLayout_setBackgroundGradient);
        tolua_function(tolua_S,"setBackgroundImage",lua_cocos2dx_cocoswidget_CLayout_setBackgroundImage);
        tolua_function(tolua_S,"setBackgroundColor",lua_cocos2dx_cocoswidget_CLayout_setBackgroundColor);
        tolua_function(tolua_S,"visit",lua_cocos2dx_cocoswidget_CLayout_visit);
        tolua_function(tolua_S,"setBackgroundSpriteFrame",lua_cocos2dx_cocoswidget_CLayout_setBackgroundSpriteFrame);
        tolua_function(tolua_S,"onTouchBegan",lua_cocos2dx_cocoswidget_CLayout_onTouchBegan);
        tolua_function(tolua_S,"setBackgroundTexture",lua_cocos2dx_cocoswidget_CLayout_setBackgroundTexture);
        tolua_function(tolua_S,"init",lua_cocos2dx_cocoswidget_CLayout_init);
        tolua_function(tolua_S,"removeBackgroundImage",lua_cocos2dx_cocoswidget_CLayout_removeBackgroundImage);
        tolua_function(tolua_S,"findWidgetById",lua_cocos2dx_cocoswidget_CLayout_findWidgetById);
        tolua_function(tolua_S,"onTouchCancelled",lua_cocos2dx_cocoswidget_CLayout_onTouchCancelled);
        tolua_function(tolua_S,"removeBackgroundGradient",lua_cocos2dx_cocoswidget_CLayout_removeBackgroundGradient);
        tolua_function(tolua_S,"setContentSize",lua_cocos2dx_cocoswidget_CLayout_setContentSize);
        tolua_function(tolua_S,"setBackgroundOpacity",lua_cocos2dx_cocoswidget_CLayout_setBackgroundOpacity);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CLayout_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_CLayout_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CLayout).name();
    g_luaType[typeName] = "cc.cocoswidget::CLayout";
    g_typeCast["CLayout"] = "cc.cocoswidget::CLayout";
    return 1;
}

int lua_cocos2dx_cocoswidget_CScrollViewContainer_reset(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollViewContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollViewContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollViewContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollViewContainer_reset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->reset();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "reset",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollViewContainer_reset'.",&tolua_err);
#endif

    return 0;
}
static int lua_cocos2dx_cocoswidget_CScrollViewContainer_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CScrollViewContainer)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CScrollViewContainer(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CScrollViewContainer");
    tolua_cclass(tolua_S,"CScrollViewContainer","cc.cocoswidget::CScrollViewContainer","cc.cocoswidget::CLayout",nullptr);

    tolua_beginmodule(tolua_S,"CScrollViewContainer");
        tolua_function(tolua_S,"reset",lua_cocos2dx_cocoswidget_CScrollViewContainer_reset);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CScrollViewContainer).name();
    g_luaType[typeName] = "cc.cocoswidget::CScrollViewContainer";
    g_typeCast["CScrollViewContainer"] = "cc.cocoswidget::CScrollViewContainer";
    return 1;
}

int lua_cocos2dx_cocoswidget_CScrollView_onAfterDraw(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_onAfterDraw'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->onAfterDraw();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onAfterDraw",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_onAfterDraw'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_onTouchEnded(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_onTouchEnded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchEnded(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchEnded",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_onTouchEnded'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetInDuration(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetInDuration'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Point arg0;
        double arg1;

        ok &= luaval_to_point(tolua_S, 2, &arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->setContentOffsetInDuration(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setContentOffsetInDuration",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetInDuration'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_getContainerSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_getContainerSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Size& ret = cobj->getContainerSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getContainerSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_getContainerSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_setBounceable(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_setBounceable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setBounceable(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBounceable",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_setBounceable'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_setDeaccelerateable(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_setDeaccelerateable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setDeaccelerateable(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDeaccelerateable",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_setDeaccelerateable'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_getMaxOffset(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_getMaxOffset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Point& ret = cobj->getMaxOffset();
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getMaxOffset",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_getMaxOffset'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetToTopInDuration(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetToTopInDuration'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setContentOffsetToTopInDuration(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setContentOffsetToTopInDuration",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetToTopInDuration'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_setContainerSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_setContainerSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setContainerSize(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setContainerSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_setContainerSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetToLeft(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetToLeft'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->setContentOffsetToLeft();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setContentOffsetToLeft",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetToLeft'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_afterDraw(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_afterDraw'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->afterDraw();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "afterDraw",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_afterDraw'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_setDirection(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_setDirection'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::cocoswidget::CScrollViewDirection arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setDirection(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDirection",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_setDirection'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetToBottom(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetToBottom'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->setContentOffsetToBottom();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setContentOffsetToBottom",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetToBottom'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_stopContainerAnimation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_stopContainerAnimation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->stopContainerAnimation();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "stopContainerAnimation",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_stopContainerAnimation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_visit(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_visit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Renderer* arg0;
        kmMat4 arg1;
        bool arg2;

        ok &= luaval_to_object<cocos2d::Renderer>(tolua_S, 2, "cc.Renderer",&arg0);

        ok &= luaval_to_kmMat4(tolua_S, 3, &arg1);

        ok &= luaval_to_boolean(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cobj->visit(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "visit",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_visit'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_getContainer(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_getContainer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CScrollViewContainer* ret = cobj->getContainer();
        object_to_luaval<cocos2d::cocoswidget::CScrollViewContainer>(tolua_S, "cc.cocoswidget::CScrollViewContainer",(cocos2d::cocoswidget::CScrollViewContainer*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getContainer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_getContainer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_setContentOffset(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_setContentOffset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setContentOffset(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setContentOffset",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_setContentOffset'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_init(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_isBounceable(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_isBounceable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isBounceable();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isBounceable",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_isBounceable'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_onTouchCancelled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_onTouchCancelled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchCancelled(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchCancelled",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_onTouchCancelled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_initWithSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_initWithSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        bool ret = cobj->initWithSize(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWithSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_initWithSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetToRight(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetToRight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->setContentOffsetToRight();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setContentOffsetToRight",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetToRight'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_onTouchMoved(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_onTouchMoved'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchMoved(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchMoved",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_onTouchMoved'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_getContentOffset(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_getContentOffset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Point& ret = cobj->getContentOffset();
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getContentOffset",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_getContentOffset'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_beforeDraw(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_beforeDraw'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->beforeDraw();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "beforeDraw",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_beforeDraw'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_getMinOffset(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_getMinOffset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Point& ret = cobj->getMinOffset();
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getMinOffset",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_getMinOffset'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_onTouchBegan(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_onTouchBegan'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Touch* arg0;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);
        if(!ok)
            return 0;
        int ret = (int)cobj->onTouchBegan(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchBegan",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_onTouchBegan'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_isDragable(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_isDragable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isDragable();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isDragable",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_isDragable'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetToTopEaseIn(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetToTopEaseIn'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->setContentOffsetToTopEaseIn(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setContentOffsetToTopEaseIn",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetToTopEaseIn'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetEaseIn(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetEaseIn'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Point arg0;
        double arg1;
        double arg2;

        ok &= luaval_to_point(tolua_S, 2, &arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cobj->setContentOffsetEaseIn(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setContentOffsetEaseIn",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetEaseIn'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_isDeaccelerateable(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_isDeaccelerateable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isDeaccelerateable();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isDeaccelerateable",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_isDeaccelerateable'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_setContentSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_setContentSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setContentSize(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setContentSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_setContentSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_isTouchMoved(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_isTouchMoved'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isTouchMoved();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isTouchMoved",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_isTouchMoved'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_onExit(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_onExit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->onExit();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onExit",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_onExit'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_setDragable(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_setDragable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setDragable(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDragable",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_setDragable'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_relocateContainer(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_relocateContainer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->relocateContainer();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "relocateContainer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_relocateContainer'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_onBeforeDraw(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_onBeforeDraw'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->onBeforeDraw();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onBeforeDraw",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_onBeforeDraw'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_getDirection(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_getDirection'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = (int)cobj->getDirection();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDirection",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_getDirection'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetToTop(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetToTop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->setContentOffsetToTop();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setContentOffsetToTop",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetToTop'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::Size arg0;
        ok &= luaval_to_size(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CScrollView* ret = cocos2d::cocoswidget::CScrollView::create(arg0);
        object_to_luaval<cocos2d::cocoswidget::CScrollView>(tolua_S, "cc.cocoswidget::CScrollView",(cocos2d::cocoswidget::CScrollView*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CScrollView_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CScrollView();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CScrollView");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CScrollView",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CScrollView_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CScrollView_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CScrollView)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CScrollView(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CScrollView");
    tolua_cclass(tolua_S,"CScrollView","cc.cocoswidget::CScrollView","cc.cocoswidget::CLayout",nullptr);

    tolua_beginmodule(tolua_S,"CScrollView");
        tolua_function(tolua_S,"onAfterDraw",lua_cocos2dx_cocoswidget_CScrollView_onAfterDraw);
        tolua_function(tolua_S,"onTouchEnded",lua_cocos2dx_cocoswidget_CScrollView_onTouchEnded);
        tolua_function(tolua_S,"setContentOffsetInDuration",lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetInDuration);
        tolua_function(tolua_S,"getContainerSize",lua_cocos2dx_cocoswidget_CScrollView_getContainerSize);
        tolua_function(tolua_S,"setBounceable",lua_cocos2dx_cocoswidget_CScrollView_setBounceable);
        tolua_function(tolua_S,"setDeaccelerateable",lua_cocos2dx_cocoswidget_CScrollView_setDeaccelerateable);
        tolua_function(tolua_S,"getMaxOffset",lua_cocos2dx_cocoswidget_CScrollView_getMaxOffset);
        tolua_function(tolua_S,"setContentOffsetToTopInDuration",lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetToTopInDuration);
        tolua_function(tolua_S,"setContainerSize",lua_cocos2dx_cocoswidget_CScrollView_setContainerSize);
        tolua_function(tolua_S,"setContentOffsetToLeft",lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetToLeft);
        tolua_function(tolua_S,"afterDraw",lua_cocos2dx_cocoswidget_CScrollView_afterDraw);
        tolua_function(tolua_S,"setDirection",lua_cocos2dx_cocoswidget_CScrollView_setDirection);
        tolua_function(tolua_S,"setContentOffsetToBottom",lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetToBottom);
        tolua_function(tolua_S,"stopContainerAnimation",lua_cocos2dx_cocoswidget_CScrollView_stopContainerAnimation);
        tolua_function(tolua_S,"visit",lua_cocos2dx_cocoswidget_CScrollView_visit);
        tolua_function(tolua_S,"getContainer",lua_cocos2dx_cocoswidget_CScrollView_getContainer);
        tolua_function(tolua_S,"setContentOffset",lua_cocos2dx_cocoswidget_CScrollView_setContentOffset);
        tolua_function(tolua_S,"init",lua_cocos2dx_cocoswidget_CScrollView_init);
        tolua_function(tolua_S,"isBounceable",lua_cocos2dx_cocoswidget_CScrollView_isBounceable);
        tolua_function(tolua_S,"onTouchCancelled",lua_cocos2dx_cocoswidget_CScrollView_onTouchCancelled);
        tolua_function(tolua_S,"initWithSize",lua_cocos2dx_cocoswidget_CScrollView_initWithSize);
        tolua_function(tolua_S,"setContentOffsetToRight",lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetToRight);
        tolua_function(tolua_S,"onTouchMoved",lua_cocos2dx_cocoswidget_CScrollView_onTouchMoved);
        tolua_function(tolua_S,"getContentOffset",lua_cocos2dx_cocoswidget_CScrollView_getContentOffset);
        tolua_function(tolua_S,"beforeDraw",lua_cocos2dx_cocoswidget_CScrollView_beforeDraw);
        tolua_function(tolua_S,"getMinOffset",lua_cocos2dx_cocoswidget_CScrollView_getMinOffset);
        tolua_function(tolua_S,"onTouchBegan",lua_cocos2dx_cocoswidget_CScrollView_onTouchBegan);
        tolua_function(tolua_S,"isDragable",lua_cocos2dx_cocoswidget_CScrollView_isDragable);
        tolua_function(tolua_S,"setContentOffsetToTopEaseIn",lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetToTopEaseIn);
        tolua_function(tolua_S,"setContentOffsetEaseIn",lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetEaseIn);
        tolua_function(tolua_S,"isDeaccelerateable",lua_cocos2dx_cocoswidget_CScrollView_isDeaccelerateable);
        tolua_function(tolua_S,"setContentSize",lua_cocos2dx_cocoswidget_CScrollView_setContentSize);
        tolua_function(tolua_S,"isTouchMoved",lua_cocos2dx_cocoswidget_CScrollView_isTouchMoved);
        tolua_function(tolua_S,"onExit",lua_cocos2dx_cocoswidget_CScrollView_onExit);
        tolua_function(tolua_S,"setDragable",lua_cocos2dx_cocoswidget_CScrollView_setDragable);
        tolua_function(tolua_S,"relocateContainer",lua_cocos2dx_cocoswidget_CScrollView_relocateContainer);
        tolua_function(tolua_S,"onBeforeDraw",lua_cocos2dx_cocoswidget_CScrollView_onBeforeDraw);
        tolua_function(tolua_S,"getDirection",lua_cocos2dx_cocoswidget_CScrollView_getDirection);
        tolua_function(tolua_S,"setContentOffsetToTop",lua_cocos2dx_cocoswidget_CScrollView_setContentOffsetToTop);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CScrollView_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_CScrollView_create);
		tolua_function(tolua_S, "setOnScrollingScriptHandler", lua_cocos2dx_cocoswidget_CScrollView_setOnScrollingScriptHandler);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CScrollView).name();
    g_luaType[typeName] = "cc.cocoswidget::CScrollView";
    g_typeCast["CScrollView"] = "cc.cocoswidget::CScrollView";
    return 1;
}

int lua_cocos2dx_cocoswidget_CTableViewCell_reset(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTableViewCell* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTableViewCell",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTableViewCell*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTableViewCell_reset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->reset();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "reset",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTableViewCell_reset'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTableViewCell_getIdx(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTableViewCell* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTableViewCell",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTableViewCell*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTableViewCell_getIdx'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        unsigned int ret = cobj->getIdx();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getIdx",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTableViewCell_getIdx'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTableViewCell_setIdx(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTableViewCell* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTableViewCell",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTableViewCell*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTableViewCell_setIdx'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setIdx(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setIdx",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTableViewCell_setIdx'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTableViewCell_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTableViewCell* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CTableViewCell();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CTableViewCell");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CTableViewCell",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTableViewCell_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CTableViewCell_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CTableViewCell)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CTableViewCell(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CTableViewCell");
    tolua_cclass(tolua_S,"CTableViewCell","cc.cocoswidget::CTableViewCell","cc.cocoswidget::CLayout",nullptr);

    tolua_beginmodule(tolua_S,"CTableViewCell");
        tolua_function(tolua_S,"reset",lua_cocos2dx_cocoswidget_CTableViewCell_reset);
        tolua_function(tolua_S,"getIdx",lua_cocos2dx_cocoswidget_CTableViewCell_getIdx);
        tolua_function(tolua_S,"setIdx",lua_cocos2dx_cocoswidget_CTableViewCell_setIdx);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CTableViewCell_constructor);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CTableViewCell).name();
    g_luaType[typeName] = "cc.cocoswidget::CTableViewCell";
    g_typeCast["CTableViewCell"] = "cc.cocoswidget::CTableViewCell";
    return 1;
}

int lua_cocos2dx_cocoswidget_CTableView_getSizeOfCell(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTableView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTableView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTableView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTableView_getSizeOfCell'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Size& ret = cobj->getSizeOfCell();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getSizeOfCell",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTableView_getSizeOfCell'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTableView_dequeueCell(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTableView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTableView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTableView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTableView_dequeueCell'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CTableViewCell* ret = cobj->dequeueCell();
        object_to_luaval<cocos2d::cocoswidget::CTableViewCell>(tolua_S, "cc.cocoswidget::CTableViewCell",(cocos2d::cocoswidget::CTableViewCell*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "dequeueCell",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTableView_dequeueCell'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTableView_getCountOfCell(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTableView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTableView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTableView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTableView_getCountOfCell'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        unsigned int ret = cobj->getCountOfCell();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCountOfCell",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTableView_getCountOfCell'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTableView_setSizeOfCell(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTableView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTableView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTableView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTableView_setSizeOfCell'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setSizeOfCell(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSizeOfCell",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTableView_setSizeOfCell'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTableView_setAutoRelocate(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTableView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTableView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTableView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTableView_setAutoRelocate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setAutoRelocate(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAutoRelocate",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTableView_setAutoRelocate'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTableView_setCountOfCell(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTableView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTableView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTableView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTableView_setCountOfCell'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setCountOfCell(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCountOfCell",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTableView_setCountOfCell'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTableView_getCells(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTableView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTableView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTableView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTableView_getCells'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Vector<cocos2d::cocoswidget::CTableViewCell *> ret = cobj->getCells();
        ccvector_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCells",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTableView_getCells'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTableView_isAutoRelocate(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTableView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTableView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTableView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTableView_isAutoRelocate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isAutoRelocate();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isAutoRelocate",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTableView_isAutoRelocate'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTableView_getAutoRelocateSpeed(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTableView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTableView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTableView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTableView_getAutoRelocateSpeed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getAutoRelocateSpeed();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAutoRelocateSpeed",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTableView_getAutoRelocateSpeed'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTableView_reloadData(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTableView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTableView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTableView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTableView_reloadData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->reloadData();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "reloadData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTableView_reloadData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTableView_cellAtIndex(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTableView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTableView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTableView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTableView_cellAtIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CTableViewCell* ret = cobj->cellAtIndex(arg0);
        object_to_luaval<cocos2d::cocoswidget::CTableViewCell>(tolua_S, "cc.cocoswidget::CTableViewCell",(cocos2d::cocoswidget::CTableViewCell*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cellAtIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTableView_cellAtIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTableView_setAutoRelocateSpeed(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTableView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTableView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTableView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTableView_setAutoRelocateSpeed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setAutoRelocateSpeed(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAutoRelocateSpeed",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTableView_setAutoRelocateSpeed'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTableView_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CTableView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::Size arg0;
        ok &= luaval_to_size(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CTableView* ret = cocos2d::cocoswidget::CTableView::create(arg0);
        object_to_luaval<cocos2d::cocoswidget::CTableView>(tolua_S, "cc.cocoswidget::CTableView",(cocos2d::cocoswidget::CTableView*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTableView_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CTableView_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTableView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CTableView();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CTableView");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CTableView",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTableView_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CTableView_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CTableView)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CTableView(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CTableView");
    tolua_cclass(tolua_S,"CTableView","cc.cocoswidget::CTableView","cc.cocoswidget::CScrollView",nullptr);

    tolua_beginmodule(tolua_S,"CTableView");
        tolua_function(tolua_S,"getSizeOfCell",lua_cocos2dx_cocoswidget_CTableView_getSizeOfCell);
        tolua_function(tolua_S,"dequeueCell",lua_cocos2dx_cocoswidget_CTableView_dequeueCell);
        tolua_function(tolua_S,"getCountOfCell",lua_cocos2dx_cocoswidget_CTableView_getCountOfCell);
        tolua_function(tolua_S,"setSizeOfCell",lua_cocos2dx_cocoswidget_CTableView_setSizeOfCell);
        tolua_function(tolua_S,"setAutoRelocate",lua_cocos2dx_cocoswidget_CTableView_setAutoRelocate);
        tolua_function(tolua_S,"setCountOfCell",lua_cocos2dx_cocoswidget_CTableView_setCountOfCell);
        tolua_function(tolua_S,"getCells",lua_cocos2dx_cocoswidget_CTableView_getCells);
        tolua_function(tolua_S,"isAutoRelocate",lua_cocos2dx_cocoswidget_CTableView_isAutoRelocate);
        tolua_function(tolua_S,"getAutoRelocateSpeed",lua_cocos2dx_cocoswidget_CTableView_getAutoRelocateSpeed);
        tolua_function(tolua_S,"reloadData",lua_cocos2dx_cocoswidget_CTableView_reloadData);
        tolua_function(tolua_S,"cellAtIndex",lua_cocos2dx_cocoswidget_CTableView_cellAtIndex);
        tolua_function(tolua_S,"setAutoRelocateSpeed",lua_cocos2dx_cocoswidget_CTableView_setAutoRelocateSpeed);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CTableView_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_CTableView_create);
		tolua_function(tolua_S, "setDataSourceAdapterScriptHandler", lua_cocos2dx_cocoswidget_CTableView_setDataSourceAdapterScriptHandler);
		
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CTableView).name();
    g_luaType[typeName] = "cc.cocoswidget::CTableView";
    g_typeCast["CTableView"] = "cc.cocoswidget::CTableView";
    return 1;
}

int lua_cocos2dx_cocoswidget_CGridPageViewPage_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridPageViewPage* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CGridPageViewPage();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CGridPageViewPage");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CGridPageViewPage",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridPageViewPage_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CGridPageViewPage_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CGridPageViewPage)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CGridPageViewPage(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CGridPageViewPage");
    tolua_cclass(tolua_S,"CGridPageViewPage","cc.cocoswidget::CGridPageViewPage","cc.cocoswidget::CTableViewCell",nullptr);

    tolua_beginmodule(tolua_S,"CGridPageViewPage");
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CGridPageViewPage).name();
    g_luaType[typeName] = "cc.cocoswidget::CGridPageViewPage";
    g_typeCast["CGridPageViewPage"] = "cc.cocoswidget::CGridPageViewPage";
    return 1;
}

int lua_cocos2dx_cocoswidget_CGridPageViewCell_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridPageViewCell* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CGridPageViewCell();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CGridPageViewCell");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CGridPageViewCell",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridPageViewCell_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CGridPageViewCell_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CGridPageViewCell)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CGridPageViewCell(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CGridPageViewCell");
    tolua_cclass(tolua_S,"CGridPageViewCell","cc.cocoswidget::CGridPageViewCell","cc.cocoswidget::CTableViewCell",nullptr);

    tolua_beginmodule(tolua_S,"CGridPageViewCell");
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CGridPageViewCell).name();
    g_luaType[typeName] = "cc.cocoswidget::CGridPageViewCell";
    g_typeCast["CGridPageViewCell"] = "cc.cocoswidget::CGridPageViewCell";
    return 1;
}

int lua_cocos2dx_cocoswidget_CGridPageView_setRows(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridPageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGridPageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGridPageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGridPageView_setRows'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setRows(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setRows",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridPageView_setRows'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGridPageView_getSizeOfCell(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridPageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGridPageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGridPageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGridPageView_getSizeOfCell'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Size& ret = cobj->getSizeOfCell();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getSizeOfCell",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridPageView_getSizeOfCell'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGridPageView_getCountOfCell(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridPageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGridPageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGridPageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGridPageView_getCountOfCell'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        unsigned int ret = cobj->getCountOfCell();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCountOfCell",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridPageView_getCountOfCell'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGridPageView_setSizeOfCell(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridPageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGridPageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGridPageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGridPageView_setSizeOfCell'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setSizeOfCell(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSizeOfCell",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridPageView_setSizeOfCell'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGridPageView_getColumns(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridPageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGridPageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGridPageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGridPageView_getColumns'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        unsigned int ret = cobj->getColumns();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getColumns",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridPageView_getColumns'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGridPageView_setCountOfCell(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridPageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGridPageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGridPageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGridPageView_setCountOfCell'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setCountOfCell(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCountOfCell",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridPageView_setCountOfCell'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGridPageView_getRows(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridPageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGridPageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGridPageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGridPageView_getRows'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        unsigned int ret = cobj->getRows();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getRows",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridPageView_getRows'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGridPageView_setColumns(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridPageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGridPageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGridPageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGridPageView_setColumns'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setColumns(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setColumns",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridPageView_setColumns'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGridPageView_reloadData(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridPageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGridPageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGridPageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGridPageView_reloadData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->reloadData();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "reloadData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridPageView_reloadData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGridPageView_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CGridPageView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::Size arg0;
        ok &= luaval_to_size(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CGridPageView* ret = cocos2d::cocoswidget::CGridPageView::create(arg0);
        object_to_luaval<cocos2d::cocoswidget::CGridPageView>(tolua_S, "cc.cocoswidget::CGridPageView",(cocos2d::cocoswidget::CGridPageView*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridPageView_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CGridPageView_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridPageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CGridPageView();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CGridPageView");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CGridPageView",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridPageView_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CGridPageView_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CGridPageView)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CGridPageView(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CGridPageView");
    tolua_cclass(tolua_S,"CGridPageView","cc.cocoswidget::CGridPageView","cc.cocoswidget::CTableView",nullptr);

    tolua_beginmodule(tolua_S,"CGridPageView");
        tolua_function(tolua_S,"setRows",lua_cocos2dx_cocoswidget_CGridPageView_setRows);
        tolua_function(tolua_S,"getSizeOfCell",lua_cocos2dx_cocoswidget_CGridPageView_getSizeOfCell);
        tolua_function(tolua_S,"getCountOfCell",lua_cocos2dx_cocoswidget_CGridPageView_getCountOfCell);
        tolua_function(tolua_S,"setSizeOfCell",lua_cocos2dx_cocoswidget_CGridPageView_setSizeOfCell);
        tolua_function(tolua_S,"getColumns",lua_cocos2dx_cocoswidget_CGridPageView_getColumns);
        tolua_function(tolua_S,"setCountOfCell",lua_cocos2dx_cocoswidget_CGridPageView_setCountOfCell);
        tolua_function(tolua_S,"getRows",lua_cocos2dx_cocoswidget_CGridPageView_getRows);
        tolua_function(tolua_S,"setColumns",lua_cocos2dx_cocoswidget_CGridPageView_setColumns);
        tolua_function(tolua_S,"reloadData",lua_cocos2dx_cocoswidget_CGridPageView_reloadData);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CGridPageView_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_CGridPageView_create);
		tolua_function(tolua_S, "setDataSourceAdapterScriptHandler", lua_cocos2dx_cocoswidget_CGridPageView_setDataSourceAdapterScriptHandler);
		

    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CGridPageView).name();
    g_luaType[typeName] = "cc.cocoswidget::CGridPageView";
    g_typeCast["CGridPageView"] = "cc.cocoswidget::CGridPageView";
    return 1;
}

int lua_cocos2dx_cocoswidget_CGridViewCell_reset(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridViewCell* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGridViewCell",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGridViewCell*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGridViewCell_reset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->reset();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "reset",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridViewCell_reset'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGridViewCell_setIdx(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridViewCell* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGridViewCell",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGridViewCell*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGridViewCell_setIdx'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setIdx(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setIdx",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridViewCell_setIdx'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGridViewCell_getRow(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridViewCell* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGridViewCell",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGridViewCell*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGridViewCell_getRow'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        unsigned int ret = cobj->getRow();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getRow",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridViewCell_getRow'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGridViewCell_setRow(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridViewCell* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGridViewCell",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGridViewCell*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGridViewCell_setRow'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setRow(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setRow",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridViewCell_setRow'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGridViewCell_getIdx(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridViewCell* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGridViewCell",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGridViewCell*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGridViewCell_getIdx'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        unsigned int ret = cobj->getIdx();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getIdx",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridViewCell_getIdx'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGridViewCell_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridViewCell* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CGridViewCell();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CGridViewCell");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CGridViewCell",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridViewCell_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CGridViewCell_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CGridViewCell)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CGridViewCell(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CGridViewCell");
    tolua_cclass(tolua_S,"CGridViewCell","cc.cocoswidget::CGridViewCell","cc.cocoswidget::CLayout",nullptr);

    tolua_beginmodule(tolua_S,"CGridViewCell");
        tolua_function(tolua_S,"reset",lua_cocos2dx_cocoswidget_CGridViewCell_reset);
        tolua_function(tolua_S,"setIdx",lua_cocos2dx_cocoswidget_CGridViewCell_setIdx);
        tolua_function(tolua_S,"getRow",lua_cocos2dx_cocoswidget_CGridViewCell_getRow);
        tolua_function(tolua_S,"setRow",lua_cocos2dx_cocoswidget_CGridViewCell_setRow);
        tolua_function(tolua_S,"getIdx",lua_cocos2dx_cocoswidget_CGridViewCell_getIdx);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CGridViewCell_constructor);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CGridViewCell).name();
    g_luaType[typeName] = "cc.cocoswidget::CGridViewCell";
    g_typeCast["CGridViewCell"] = "cc.cocoswidget::CGridViewCell";
    return 1;
}

int lua_cocos2dx_cocoswidget_CGridView_getSizeOfCell(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGridView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGridView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGridView_getSizeOfCell'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Size& ret = cobj->getSizeOfCell();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getSizeOfCell",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridView_getSizeOfCell'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGridView_getCells(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGridView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGridView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGridView_getCells'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Vector<cocos2d::cocoswidget::CGridViewCell *> ret = cobj->getCells();
        ccvector_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCells",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridView_getCells'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGridView_getCountOfCell(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGridView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGridView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGridView_getCountOfCell'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        unsigned int ret = cobj->getCountOfCell();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCountOfCell",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridView_getCountOfCell'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGridView_setSizeOfCell(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGridView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGridView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGridView_setSizeOfCell'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setSizeOfCell(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSizeOfCell",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridView_setSizeOfCell'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGridView_getColumns(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGridView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGridView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGridView_getColumns'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        unsigned int ret = cobj->getColumns();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getColumns",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridView_getColumns'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGridView_setCountOfCell(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGridView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGridView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGridView_setCountOfCell'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setCountOfCell(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCountOfCell",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridView_setCountOfCell'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGridView_setAutoRelocate(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGridView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGridView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGridView_setAutoRelocate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setAutoRelocate(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAutoRelocate",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridView_setAutoRelocate'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGridView_getRows(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGridView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGridView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGridView_getRows'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        unsigned int ret = cobj->getRows();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getRows",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridView_getRows'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGridView_isAutoRelocate(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGridView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGridView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGridView_isAutoRelocate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isAutoRelocate();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isAutoRelocate",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridView_isAutoRelocate'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGridView_setColumns(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGridView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGridView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGridView_setColumns'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setColumns(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setColumns",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridView_setColumns'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGridView_reloadData(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGridView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGridView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGridView_reloadData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->reloadData();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "reloadData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridView_reloadData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGridView_cellAtIndex(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGridView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGridView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGridView_cellAtIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CGridViewCell* ret = cobj->cellAtIndex(arg0);
        object_to_luaval<cocos2d::cocoswidget::CGridViewCell>(tolua_S, "cc.cocoswidget::CGridViewCell",(cocos2d::cocoswidget::CGridViewCell*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cellAtIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridView_cellAtIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGridView_dequeueCell(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CGridView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CGridView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CGridView_dequeueCell'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CGridViewCell* ret = cobj->dequeueCell();
        object_to_luaval<cocos2d::cocoswidget::CGridViewCell>(tolua_S, "cc.cocoswidget::CGridViewCell",(cocos2d::cocoswidget::CGridViewCell*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "dequeueCell",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridView_dequeueCell'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CGridView_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CGridView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::Size arg0;
        ok &= luaval_to_size(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CGridView* ret = cocos2d::cocoswidget::CGridView::create(arg0);
        object_to_luaval<cocos2d::cocoswidget::CGridView>(tolua_S, "cc.cocoswidget::CGridView",(cocos2d::cocoswidget::CGridView*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridView_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CGridView_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CGridView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CGridView();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CGridView");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CGridView",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CGridView_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CGridView_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CGridView)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CGridView(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CGridView");
    tolua_cclass(tolua_S,"CGridView","cc.cocoswidget::CGridView","cc.cocoswidget::CScrollView",nullptr);

    tolua_beginmodule(tolua_S,"CGridView");
        tolua_function(tolua_S,"getSizeOfCell",lua_cocos2dx_cocoswidget_CGridView_getSizeOfCell);
        tolua_function(tolua_S,"getCells",lua_cocos2dx_cocoswidget_CGridView_getCells);
        tolua_function(tolua_S,"getCountOfCell",lua_cocos2dx_cocoswidget_CGridView_getCountOfCell);
        tolua_function(tolua_S,"setSizeOfCell",lua_cocos2dx_cocoswidget_CGridView_setSizeOfCell);
        tolua_function(tolua_S,"getColumns",lua_cocos2dx_cocoswidget_CGridView_getColumns);
        tolua_function(tolua_S,"setCountOfCell",lua_cocos2dx_cocoswidget_CGridView_setCountOfCell);
        tolua_function(tolua_S,"setAutoRelocate",lua_cocos2dx_cocoswidget_CGridView_setAutoRelocate);
        tolua_function(tolua_S,"getRows",lua_cocos2dx_cocoswidget_CGridView_getRows);
        tolua_function(tolua_S,"isAutoRelocate",lua_cocos2dx_cocoswidget_CGridView_isAutoRelocate);
        tolua_function(tolua_S,"setColumns",lua_cocos2dx_cocoswidget_CGridView_setColumns);
        tolua_function(tolua_S,"reloadData",lua_cocos2dx_cocoswidget_CGridView_reloadData);
        tolua_function(tolua_S,"cellAtIndex",lua_cocos2dx_cocoswidget_CGridView_cellAtIndex);
        tolua_function(tolua_S,"dequeueCell",lua_cocos2dx_cocoswidget_CGridView_dequeueCell);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CGridView_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_CGridView_create);
		tolua_function(tolua_S, "setDataSourceAdapterScriptHandler", lua_cocos2dx_cocoswidget_CGridView_setDataSourceAdapterScriptHandler);

    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CGridView).name();
    g_luaType[typeName] = "cc.cocoswidget::CGridView";
    g_typeCast["CGridView"] = "cc.cocoswidget::CGridView";
    return 1;
}

int lua_cocos2dx_cocoswidget_CImageView_onTouchMoved(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CImageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CImageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CImageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CImageView_onTouchMoved'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchMoved(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchMoved",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CImageView_onTouchMoved'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CImageView_onTouchEnded(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CImageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CImageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CImageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CImageView_onTouchEnded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchEnded(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchEnded",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CImageView_onTouchEnded'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CImageView_onTouchCancelled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CImageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CImageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CImageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CImageView_onTouchCancelled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchCancelled(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchCancelled",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CImageView_onTouchCancelled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CImageView_onTouchBegan(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CImageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CImageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CImageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CImageView_onTouchBegan'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Touch* arg0;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);
        if(!ok)
            return 0;
        int ret = (int)cobj->onTouchBegan(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchBegan",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CImageView_onTouchBegan'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CImageView_init(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CImageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CImageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CImageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CImageView_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CImageView_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CImageView_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CImageView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            cocos2d::cocoswidget::CImageView* ret = cocos2d::cocoswidget::CImageView::create(arg0);
            object_to_luaval<cocos2d::cocoswidget::CImageView>(tolua_S, "cc.cocoswidget::CImageView",(cocos2d::cocoswidget::CImageView*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            cocos2d::cocoswidget::CImageView* ret = cocos2d::cocoswidget::CImageView::create();
            object_to_luaval<cocos2d::cocoswidget::CImageView>(tolua_S, "cc.cocoswidget::CImageView",(cocos2d::cocoswidget::CImageView*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1);
            if (!ok) { break; }
            cocos2d::cocoswidget::CImageView* ret = cocos2d::cocoswidget::CImageView::create(arg0, arg1);
            object_to_luaval<cocos2d::cocoswidget::CImageView>(tolua_S, "cc.cocoswidget::CImageView",(cocos2d::cocoswidget::CImageView*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CImageView_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CImageView_createWithTexture(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CImageView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);
            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1);
            if (!ok) { break; }
            cocos2d::cocoswidget::CImageView* ret = cocos2d::cocoswidget::CImageView::createWithTexture(arg0, arg1);
            object_to_luaval<cocos2d::cocoswidget::CImageView>(tolua_S, "cc.cocoswidget::CImageView",(cocos2d::cocoswidget::CImageView*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 1)
        {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);
            if (!ok) { break; }
            cocos2d::cocoswidget::CImageView* ret = cocos2d::cocoswidget::CImageView::createWithTexture(arg0);
            object_to_luaval<cocos2d::cocoswidget::CImageView>(tolua_S, "cc.cocoswidget::CImageView",(cocos2d::cocoswidget::CImageView*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "createWithTexture",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CImageView_createWithTexture'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CImageView_createWithSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CImageView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CImageView* ret = cocos2d::cocoswidget::CImageView::createWithSpriteFrameName(arg0);
        object_to_luaval<cocos2d::cocoswidget::CImageView>(tolua_S, "cc.cocoswidget::CImageView",(cocos2d::cocoswidget::CImageView*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createWithSpriteFrameName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CImageView_createWithSpriteFrameName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CImageView_createWithSpriteFrame(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CImageView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::SpriteFrame* arg0;
        ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CImageView* ret = cocos2d::cocoswidget::CImageView::createWithSpriteFrame(arg0);
        object_to_luaval<cocos2d::cocoswidget::CImageView>(tolua_S, "cc.cocoswidget::CImageView",(cocos2d::cocoswidget::CImageView*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createWithSpriteFrame",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CImageView_createWithSpriteFrame'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CImageView_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CImageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CImageView();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CImageView");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CImageView",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CImageView_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CImageView_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CImageView)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CImageView(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CImageView");
    tolua_cclass(tolua_S,"CImageView","cc.cocoswidget::CImageView","cc.Sprite",nullptr);

    tolua_beginmodule(tolua_S,"CImageView");
        tolua_function(tolua_S,"onTouchMoved",lua_cocos2dx_cocoswidget_CImageView_onTouchMoved);
        tolua_function(tolua_S,"onTouchEnded",lua_cocos2dx_cocoswidget_CImageView_onTouchEnded);
        tolua_function(tolua_S,"onTouchCancelled",lua_cocos2dx_cocoswidget_CImageView_onTouchCancelled);
        tolua_function(tolua_S,"onTouchBegan",lua_cocos2dx_cocoswidget_CImageView_onTouchBegan);
        tolua_function(tolua_S,"init",lua_cocos2dx_cocoswidget_CImageView_init);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CImageView_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_CImageView_create);
        tolua_function(tolua_S,"createWithTexture", lua_cocos2dx_cocoswidget_CImageView_createWithTexture);
        tolua_function(tolua_S,"createWithSpriteFrameName", lua_cocos2dx_cocoswidget_CImageView_createWithSpriteFrameName);
        tolua_function(tolua_S,"createWithSpriteFrame", lua_cocos2dx_cocoswidget_CImageView_createWithSpriteFrame);
		tolua_function(tolua_S, "setOnClickScriptHandler", lua_cocos2dx_cocoswidget_CImageView_setOnClickScriptHandler);
		tolua_function(tolua_S, "setOnLongClickScriptHandler", lua_cocos2dx_cocoswidget_CImageView_setOnLongClickScriptHandler);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CImageView).name();
    g_luaType[typeName] = "cc.cocoswidget::CImageView";
    g_typeCast["CImageView"] = "cc.cocoswidget::CImageView";
    return 1;
}

int lua_cocos2dx_cocoswidget_CImageViewScale9_onTouchMoved(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CImageViewScale9* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CImageViewScale9",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CImageViewScale9*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CImageViewScale9_onTouchMoved'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchMoved(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchMoved",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CImageViewScale9_onTouchMoved'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CImageViewScale9_onTouchEnded(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CImageViewScale9* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CImageViewScale9",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CImageViewScale9*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CImageViewScale9_onTouchEnded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchEnded(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchEnded",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CImageViewScale9_onTouchEnded'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CImageViewScale9_onTouchCancelled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CImageViewScale9* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CImageViewScale9",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CImageViewScale9*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CImageViewScale9_onTouchCancelled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchCancelled(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchCancelled",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CImageViewScale9_onTouchCancelled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CImageViewScale9_onTouchBegan(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CImageViewScale9* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CImageViewScale9",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CImageViewScale9*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CImageViewScale9_onTouchBegan'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Touch* arg0;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);
        if(!ok)
            return 0;
        int ret = (int)cobj->onTouchBegan(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchBegan",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CImageViewScale9_onTouchBegan'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CImageViewScale9_init(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CImageViewScale9* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CImageViewScale9",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CImageViewScale9*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CImageViewScale9_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CImageViewScale9_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CImageViewScale9_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CImageViewScale9",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 3)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1);
            if (!ok) { break; }
            cocos2d::Rect arg2;
            ok &= luaval_to_rect(tolua_S, 4, &arg2);
            if (!ok) { break; }
            cocos2d::cocoswidget::CImageViewScale9* ret = cocos2d::cocoswidget::CImageViewScale9::create(arg0, arg1, arg2);
            object_to_luaval<cocos2d::cocoswidget::CImageViewScale9>(tolua_S, "cc.cocoswidget::CImageViewScale9",(cocos2d::cocoswidget::CImageViewScale9*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            cocos2d::Size arg0;
            ok &= luaval_to_size(tolua_S, 2, &arg0);
            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
            if (!ok) { break; }
            cocos2d::cocoswidget::CImageViewScale9* ret = cocos2d::cocoswidget::CImageViewScale9::create(arg0, arg1);
            object_to_luaval<cocos2d::cocoswidget::CImageViewScale9>(tolua_S, "cc.cocoswidget::CImageViewScale9",(cocos2d::cocoswidget::CImageViewScale9*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1);
            if (!ok) { break; }
            cocos2d::cocoswidget::CImageViewScale9* ret = cocos2d::cocoswidget::CImageViewScale9::create(arg0, arg1);
            object_to_luaval<cocos2d::cocoswidget::CImageViewScale9>(tolua_S, "cc.cocoswidget::CImageViewScale9",(cocos2d::cocoswidget::CImageViewScale9*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            cocos2d::Rect arg0;
            ok &= luaval_to_rect(tolua_S, 2, &arg0);
            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
            if (!ok) { break; }
            cocos2d::cocoswidget::CImageViewScale9* ret = cocos2d::cocoswidget::CImageViewScale9::create(arg0, arg1);
            object_to_luaval<cocos2d::cocoswidget::CImageViewScale9>(tolua_S, "cc.cocoswidget::CImageViewScale9",(cocos2d::cocoswidget::CImageViewScale9*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 1)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            cocos2d::cocoswidget::CImageViewScale9* ret = cocos2d::cocoswidget::CImageViewScale9::create(arg0);
            object_to_luaval<cocos2d::cocoswidget::CImageViewScale9>(tolua_S, "cc.cocoswidget::CImageViewScale9",(cocos2d::cocoswidget::CImageViewScale9*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            cocos2d::cocoswidget::CImageViewScale9* ret = cocos2d::cocoswidget::CImageViewScale9::create();
            object_to_luaval<cocos2d::cocoswidget::CImageViewScale9>(tolua_S, "cc.cocoswidget::CImageViewScale9",(cocos2d::cocoswidget::CImageViewScale9*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CImageViewScale9_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CImageViewScale9_createWithTexture(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CImageViewScale9",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);
            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1);
            if (!ok) { break; }
            cocos2d::cocoswidget::CImageViewScale9* ret = cocos2d::cocoswidget::CImageViewScale9::createWithTexture(arg0, arg1);
            object_to_luaval<cocos2d::cocoswidget::CImageViewScale9>(tolua_S, "cc.cocoswidget::CImageViewScale9",(cocos2d::cocoswidget::CImageViewScale9*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 1)
        {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);
            if (!ok) { break; }
            cocos2d::cocoswidget::CImageViewScale9* ret = cocos2d::cocoswidget::CImageViewScale9::createWithTexture(arg0);
            object_to_luaval<cocos2d::cocoswidget::CImageViewScale9>(tolua_S, "cc.cocoswidget::CImageViewScale9",(cocos2d::cocoswidget::CImageViewScale9*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "createWithTexture",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CImageViewScale9_createWithTexture'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CImageViewScale9_createWithSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CImageViewScale9",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            cocos2d::cocoswidget::CImageViewScale9* ret = cocos2d::cocoswidget::CImageViewScale9::createWithSpriteFrameName(arg0);
            object_to_luaval<cocos2d::cocoswidget::CImageViewScale9>(tolua_S, "cc.cocoswidget::CImageViewScale9",(cocos2d::cocoswidget::CImageViewScale9*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1);
            if (!ok) { break; }
            cocos2d::cocoswidget::CImageViewScale9* ret = cocos2d::cocoswidget::CImageViewScale9::createWithSpriteFrameName(arg0, arg1);
            object_to_luaval<cocos2d::cocoswidget::CImageViewScale9>(tolua_S, "cc.cocoswidget::CImageViewScale9",(cocos2d::cocoswidget::CImageViewScale9*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "createWithSpriteFrameName",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CImageViewScale9_createWithSpriteFrameName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CImageViewScale9_createWithSpriteFrame(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CImageViewScale9",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            cocos2d::SpriteFrame* arg0;
            ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);
            if (!ok) { break; }
            cocos2d::cocoswidget::CImageViewScale9* ret = cocos2d::cocoswidget::CImageViewScale9::createWithSpriteFrame(arg0);
            object_to_luaval<cocos2d::cocoswidget::CImageViewScale9>(tolua_S, "cc.cocoswidget::CImageViewScale9",(cocos2d::cocoswidget::CImageViewScale9*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            cocos2d::SpriteFrame* arg0;
            ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);
            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1);
            if (!ok) { break; }
            cocos2d::cocoswidget::CImageViewScale9* ret = cocos2d::cocoswidget::CImageViewScale9::createWithSpriteFrame(arg0, arg1);
            object_to_luaval<cocos2d::cocoswidget::CImageViewScale9>(tolua_S, "cc.cocoswidget::CImageViewScale9",(cocos2d::cocoswidget::CImageViewScale9*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "createWithSpriteFrame",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CImageViewScale9_createWithSpriteFrame'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CImageViewScale9_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CImageViewScale9* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CImageViewScale9();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CImageViewScale9");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CImageViewScale9",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CImageViewScale9_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CImageViewScale9_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CImageViewScale9)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CImageViewScale9(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CImageViewScale9");
    tolua_cclass(tolua_S,"CImageViewScale9","cc.cocoswidget::CImageViewScale9","cc.cocoswidget::CScale9Sprite",nullptr);

    tolua_beginmodule(tolua_S,"CImageViewScale9");
        tolua_function(tolua_S,"onTouchMoved",lua_cocos2dx_cocoswidget_CImageViewScale9_onTouchMoved);
        tolua_function(tolua_S,"onTouchEnded",lua_cocos2dx_cocoswidget_CImageViewScale9_onTouchEnded);
        tolua_function(tolua_S,"onTouchCancelled",lua_cocos2dx_cocoswidget_CImageViewScale9_onTouchCancelled);
        tolua_function(tolua_S,"onTouchBegan",lua_cocos2dx_cocoswidget_CImageViewScale9_onTouchBegan);
        tolua_function(tolua_S,"init",lua_cocos2dx_cocoswidget_CImageViewScale9_init);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CImageViewScale9_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_CImageViewScale9_create);
        tolua_function(tolua_S,"createWithTexture", lua_cocos2dx_cocoswidget_CImageViewScale9_createWithTexture);
        tolua_function(tolua_S,"createWithSpriteFrameName", lua_cocos2dx_cocoswidget_CImageViewScale9_createWithSpriteFrameName);
        tolua_function(tolua_S,"createWithSpriteFrame", lua_cocos2dx_cocoswidget_CImageViewScale9_createWithSpriteFrame);
		tolua_function(tolua_S, "setOnClickScriptHandler", lua_cocos2dx_cocoswidget_CImageViewScale9_setOnClickScriptHandler);
		tolua_function(tolua_S, "setOnLongClickScriptHandler", lua_cocos2dx_cocoswidget_CImageViewScale9_setOnLongClickScriptHandler);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CImageViewScale9).name();
    g_luaType[typeName] = "cc.cocoswidget::CImageViewScale9";
    g_typeCast["CImageViewScale9"] = "cc.cocoswidget::CImageViewScale9";
    return 1;
}

int lua_cocos2dx_cocoswidget_CPageViewCell_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CPageViewCell* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CPageViewCell();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CPageViewCell");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CPageViewCell",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CPageViewCell_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CPageViewCell_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CPageViewCell)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CPageViewCell(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CPageViewCell");
    tolua_cclass(tolua_S,"CPageViewCell","cc.cocoswidget::CPageViewCell","cc.cocoswidget::CTableViewCell",nullptr);

    tolua_beginmodule(tolua_S,"CPageViewCell");
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CPageViewCell).name();
    g_luaType[typeName] = "cc.cocoswidget::CPageViewCell";
    g_typeCast["CPageViewCell"] = "cc.cocoswidget::CPageViewCell";
    return 1;
}

int lua_cocos2dx_cocoswidget_CPageView_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CPageView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::Size arg0;
        ok &= luaval_to_size(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CPageView* ret = cocos2d::cocoswidget::CPageView::create(arg0);
        object_to_luaval<cocos2d::cocoswidget::CPageView>(tolua_S, "cc.cocoswidget::CPageView",(cocos2d::cocoswidget::CPageView*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CPageView_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CPageView_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CPageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CPageView();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CPageView");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CPageView",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CPageView_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CPageView_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CPageView)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CPageView(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CPageView");
    tolua_cclass(tolua_S,"CPageView","cc.cocoswidget::CPageView","cc.cocoswidget::CTableView",nullptr);

    tolua_beginmodule(tolua_S,"CPageView");
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_CPageView_create);
		tolua_function(tolua_S, "setOnPageChangedScriptHandler", lua_cocos2dx_cocoswidget_CPageView_setOnPageChangedScriptHandler);
		tolua_function(tolua_S, "setDataSourceAdapterScriptHandler", lua_cocos2dx_cocoswidget_CPageView_setDataSourceAdapterScriptHandler);
		
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CPageView).name();
    g_luaType[typeName] = "cc.cocoswidget::CPageView";
    g_typeCast["CPageView"] = "cc.cocoswidget::CPageView";
    return 1;
}

int lua_cocos2dx_cocoswidget_CListView_getNodeCount(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CListView_getNodeCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        unsigned int ret = cobj->getNodeCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getNodeCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CListView_getNodeCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CListView_removeAllNodes(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CListView_removeAllNodes'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeAllNodes();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeAllNodes",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CListView_removeAllNodes'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CListView_removeNode(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CListView_removeNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);
        if(!ok)
            return 0;
        cobj->removeNode(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeNode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CListView_removeNode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CListView_insertNodeAtFront(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CListView_insertNodeAtFront'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);
        if(!ok)
            return 0;
        cobj->insertNodeAtFront(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "insertNodeAtFront",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CListView_insertNodeAtFront'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CListView_insertNodeAtLast(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CListView_insertNodeAtLast'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);
        if(!ok)
            return 0;
        cobj->insertNodeAtLast(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "insertNodeAtLast",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CListView_insertNodeAtLast'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CListView_removeLastNode(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CListView_removeLastNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeLastNode();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeLastNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CListView_removeLastNode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CListView_getNodes(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CListView_getNodes'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Vector<cocos2d::Node *> ret = cobj->getNodes();
        ccvector_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getNodes",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CListView_getNodes'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CListView_insertNode(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CListView* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CListView",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::cocoswidget::CListView*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CListView_insertNode'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            cocos2d::Node* arg0;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);

            if (!ok) { break; }
            unsigned int arg1;
            ok &= luaval_to_uint32(tolua_S, 3,&arg1);

            if (!ok) { break; }
            cobj->insertNode(arg0, arg1);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            cocos2d::Node* arg0;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);

            if (!ok) { break; }
            cocos2d::Node* arg1;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 3, "cc.Node",&arg1);

            if (!ok) { break; }
            cobj->insertNode(arg0, arg1);
            return 0;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "insertNode",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CListView_insertNode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CListView_removeFrontNode(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CListView_removeFrontNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeFrontNode();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeFrontNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CListView_removeFrontNode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CListView_removeNodeAtIndex(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CListView_removeNodeAtIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->removeNodeAtIndex(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeNodeAtIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CListView_removeNodeAtIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CListView_reloadData(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CListView_reloadData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->reloadData();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "reloadData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CListView_reloadData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CListView_getNodeAtIndex(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CListView_getNodeAtIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->getNodeAtIndex(arg0);
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getNodeAtIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CListView_getNodeAtIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CListView_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CListView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::Size arg0;
        ok &= luaval_to_size(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CListView* ret = cocos2d::cocoswidget::CListView::create(arg0);
        object_to_luaval<cocos2d::cocoswidget::CListView>(tolua_S, "cc.cocoswidget::CListView",(cocos2d::cocoswidget::CListView*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CListView_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CListView_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CListView();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CListView");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CListView",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CListView_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CListView_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CListView)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CListView(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CListView");
    tolua_cclass(tolua_S,"CListView","cc.cocoswidget::CListView","cc.cocoswidget::CScrollView",nullptr);

    tolua_beginmodule(tolua_S,"CListView");
        tolua_function(tolua_S,"getNodeCount",lua_cocos2dx_cocoswidget_CListView_getNodeCount);
        tolua_function(tolua_S,"removeAllNodes",lua_cocos2dx_cocoswidget_CListView_removeAllNodes);
        tolua_function(tolua_S,"removeNode",lua_cocos2dx_cocoswidget_CListView_removeNode);
        tolua_function(tolua_S,"insertNodeAtFront",lua_cocos2dx_cocoswidget_CListView_insertNodeAtFront);
        tolua_function(tolua_S,"insertNodeAtLast",lua_cocos2dx_cocoswidget_CListView_insertNodeAtLast);
        tolua_function(tolua_S,"removeLastNode",lua_cocos2dx_cocoswidget_CListView_removeLastNode);
        tolua_function(tolua_S,"getNodes",lua_cocos2dx_cocoswidget_CListView_getNodes);
        tolua_function(tolua_S,"insertNode",lua_cocos2dx_cocoswidget_CListView_insertNode);
        tolua_function(tolua_S,"removeFrontNode",lua_cocos2dx_cocoswidget_CListView_removeFrontNode);
        tolua_function(tolua_S,"removeNodeAtIndex",lua_cocos2dx_cocoswidget_CListView_removeNodeAtIndex);
        tolua_function(tolua_S,"reloadData",lua_cocos2dx_cocoswidget_CListView_reloadData);
        tolua_function(tolua_S,"getNodeAtIndex",lua_cocos2dx_cocoswidget_CListView_getNodeAtIndex);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CListView_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_CListView_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CListView).name();
    g_luaType[typeName] = "cc.cocoswidget::CListView";
    g_typeCast["CListView"] = "cc.cocoswidget::CListView";
    return 1;
}

int lua_cocos2dx_cocoswidget_CCheckBox_setDisabledCheckedSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_setDisabledCheckedSpriteFrameName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setDisabledCheckedSpriteFrameName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDisabledCheckedSpriteFrameName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_setDisabledCheckedSpriteFrameName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_onTouchEnded(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_onTouchEnded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchEnded(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchEnded",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_onTouchEnded'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_setNormalTexture(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_setNormalTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Texture2D* arg0;

        ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);
        if(!ok)
            return 0;
        cobj->setNormalTexture(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setNormalTexture",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_setNormalTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_onTouchMoved(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_onTouchMoved'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchMoved(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchMoved",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_onTouchMoved'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_setChecked(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_setChecked'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setChecked(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setChecked",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_setChecked'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_setDisabledCheckedSpriteFrame(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_setDisabledCheckedSpriteFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::SpriteFrame* arg0;

        ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);
        if(!ok)
            return 0;
        cobj->setDisabledCheckedSpriteFrame(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDisabledCheckedSpriteFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_setDisabledCheckedSpriteFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_setNormalSpriteFrame(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_setNormalSpriteFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::SpriteFrame* arg0;

        ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);
        if(!ok)
            return 0;
        cobj->setNormalSpriteFrame(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setNormalSpriteFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_setNormalSpriteFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_setDisabledCheckedTexture(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_setDisabledCheckedTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Texture2D* arg0;

        ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);
        if(!ok)
            return 0;
        cobj->setDisabledCheckedTexture(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDisabledCheckedTexture",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_setDisabledCheckedTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_setDisabledNormalSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_setDisabledNormalSpriteFrameName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setDisabledNormalSpriteFrameName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDisabledNormalSpriteFrameName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_setDisabledNormalSpriteFrameName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_setNormalPressSpriteFrame(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_setNormalPressSpriteFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::SpriteFrame* arg0;

        ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);
        if(!ok)
            return 0;
        cobj->setNormalPressSpriteFrame(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setNormalPressSpriteFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_setNormalPressSpriteFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_setCheckedPressSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_setCheckedPressSpriteFrameName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setCheckedPressSpriteFrameName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCheckedPressSpriteFrameName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_setCheckedPressSpriteFrameName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_setDisabledCheckedImage(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_setDisabledCheckedImage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setDisabledCheckedImage(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDisabledCheckedImage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_setDisabledCheckedImage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_setDisabledNormalImage(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_setDisabledNormalImage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setDisabledNormalImage(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDisabledNormalImage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_setDisabledNormalImage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_setCheckedSpriteFrame(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_setCheckedSpriteFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::SpriteFrame* arg0;

        ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);
        if(!ok)
            return 0;
        cobj->setCheckedSpriteFrame(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCheckedSpriteFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_setCheckedSpriteFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_init(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_setNormalPressImage(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_setNormalPressImage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setNormalPressImage(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setNormalPressImage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_setNormalPressImage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_setDisabledNormalSpriteFrame(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_setDisabledNormalSpriteFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::SpriteFrame* arg0;

        ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);
        if(!ok)
            return 0;
        cobj->setDisabledNormalSpriteFrame(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDisabledNormalSpriteFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_setDisabledNormalSpriteFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_setEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_setEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setEnabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setEnabled",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_setEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_setDisabledNormalTexture(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_setDisabledNormalTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Texture2D* arg0;

        ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);
        if(!ok)
            return 0;
        cobj->setDisabledNormalTexture(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDisabledNormalTexture",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_setDisabledNormalTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_setNormalSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_setNormalSpriteFrameName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setNormalSpriteFrameName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setNormalSpriteFrameName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_setNormalSpriteFrameName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_setNormalPressTexture(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_setNormalPressTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Texture2D* arg0;

        ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);
        if(!ok)
            return 0;
        cobj->setNormalPressTexture(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setNormalPressTexture",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_setNormalPressTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_setCheckedPressSpriteFrame(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_setCheckedPressSpriteFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::SpriteFrame* arg0;

        ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);
        if(!ok)
            return 0;
        cobj->setCheckedPressSpriteFrame(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCheckedPressSpriteFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_setCheckedPressSpriteFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_onTouchCancelled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_onTouchCancelled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchCancelled(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchCancelled",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_onTouchCancelled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_onTouchBegan(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_onTouchBegan'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Touch* arg0;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);
        if(!ok)
            return 0;
        int ret = (int)cobj->onTouchBegan(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchBegan",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_onTouchBegan'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_setCheckedImage(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_setCheckedImage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setCheckedImage(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCheckedImage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_setCheckedImage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_setContentSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_setContentSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setContentSize(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setContentSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_setContentSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_setNormalPressSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_setNormalPressSpriteFrameName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setNormalPressSpriteFrameName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setNormalPressSpriteFrameName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_setNormalPressSpriteFrameName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_setCheckedPressImage(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_setCheckedPressImage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setCheckedPressImage(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCheckedPressImage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_setCheckedPressImage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_setNormalImage(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_setNormalImage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setNormalImage(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setNormalImage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_setNormalImage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_setCheckedTexture(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_setCheckedTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Texture2D* arg0;

        ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);
        if(!ok)
            return 0;
        cobj->setCheckedTexture(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCheckedTexture",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_setCheckedTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_setCheckedSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_setCheckedSpriteFrameName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setCheckedSpriteFrameName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCheckedSpriteFrameName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_setCheckedSpriteFrameName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_setCheckedPressTexture(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CCheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CCheckBox_setCheckedPressTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Texture2D* arg0;

        ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);
        if(!ok)
            return 0;
        cobj->setCheckedPressTexture(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCheckedPressTexture",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_setCheckedPressTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CCheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CCheckBox* ret = cocos2d::cocoswidget::CCheckBox::create();
        object_to_luaval<cocos2d::cocoswidget::CCheckBox>(tolua_S, "cc.cocoswidget::CCheckBox",(cocos2d::cocoswidget::CCheckBox*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CCheckBox_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CCheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CCheckBox();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CCheckBox");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCheckBox",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CCheckBox_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CCheckBox_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCheckBox)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CCheckBox(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CCheckBox");
    tolua_cclass(tolua_S,"CCheckBox","cc.cocoswidget::CCheckBox","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"CCheckBox");
        tolua_function(tolua_S,"setDisabledCheckedSpriteFrameName",lua_cocos2dx_cocoswidget_CCheckBox_setDisabledCheckedSpriteFrameName);
        tolua_function(tolua_S,"onTouchEnded",lua_cocos2dx_cocoswidget_CCheckBox_onTouchEnded);
        tolua_function(tolua_S,"setNormalTexture",lua_cocos2dx_cocoswidget_CCheckBox_setNormalTexture);
        tolua_function(tolua_S,"onTouchMoved",lua_cocos2dx_cocoswidget_CCheckBox_onTouchMoved);
        tolua_function(tolua_S,"setChecked",lua_cocos2dx_cocoswidget_CCheckBox_setChecked);
        tolua_function(tolua_S,"setDisabledCheckedSpriteFrame",lua_cocos2dx_cocoswidget_CCheckBox_setDisabledCheckedSpriteFrame);
        tolua_function(tolua_S,"setNormalSpriteFrame",lua_cocos2dx_cocoswidget_CCheckBox_setNormalSpriteFrame);
        tolua_function(tolua_S,"setDisabledCheckedTexture",lua_cocos2dx_cocoswidget_CCheckBox_setDisabledCheckedTexture);
        tolua_function(tolua_S,"setDisabledNormalSpriteFrameName",lua_cocos2dx_cocoswidget_CCheckBox_setDisabledNormalSpriteFrameName);
        tolua_function(tolua_S,"setNormalPressSpriteFrame",lua_cocos2dx_cocoswidget_CCheckBox_setNormalPressSpriteFrame);
        tolua_function(tolua_S,"setCheckedPressSpriteFrameName",lua_cocos2dx_cocoswidget_CCheckBox_setCheckedPressSpriteFrameName);
        tolua_function(tolua_S,"setDisabledCheckedImage",lua_cocos2dx_cocoswidget_CCheckBox_setDisabledCheckedImage);
        tolua_function(tolua_S,"setDisabledNormalImage",lua_cocos2dx_cocoswidget_CCheckBox_setDisabledNormalImage);
        tolua_function(tolua_S,"setCheckedSpriteFrame",lua_cocos2dx_cocoswidget_CCheckBox_setCheckedSpriteFrame);
        tolua_function(tolua_S,"init",lua_cocos2dx_cocoswidget_CCheckBox_init);
        tolua_function(tolua_S,"setNormalPressImage",lua_cocos2dx_cocoswidget_CCheckBox_setNormalPressImage);
        tolua_function(tolua_S,"setDisabledNormalSpriteFrame",lua_cocos2dx_cocoswidget_CCheckBox_setDisabledNormalSpriteFrame);
        tolua_function(tolua_S,"setEnabled",lua_cocos2dx_cocoswidget_CCheckBox_setEnabled);
        tolua_function(tolua_S,"setDisabledNormalTexture",lua_cocos2dx_cocoswidget_CCheckBox_setDisabledNormalTexture);
        tolua_function(tolua_S,"setNormalSpriteFrameName",lua_cocos2dx_cocoswidget_CCheckBox_setNormalSpriteFrameName);
        tolua_function(tolua_S,"setNormalPressTexture",lua_cocos2dx_cocoswidget_CCheckBox_setNormalPressTexture);
        tolua_function(tolua_S,"setCheckedPressSpriteFrame",lua_cocos2dx_cocoswidget_CCheckBox_setCheckedPressSpriteFrame);
        tolua_function(tolua_S,"onTouchCancelled",lua_cocos2dx_cocoswidget_CCheckBox_onTouchCancelled);
        tolua_function(tolua_S,"onTouchBegan",lua_cocos2dx_cocoswidget_CCheckBox_onTouchBegan);
        tolua_function(tolua_S,"setCheckedImage",lua_cocos2dx_cocoswidget_CCheckBox_setCheckedImage);
        tolua_function(tolua_S,"setContentSize",lua_cocos2dx_cocoswidget_CCheckBox_setContentSize);
        tolua_function(tolua_S,"setNormalPressSpriteFrameName",lua_cocos2dx_cocoswidget_CCheckBox_setNormalPressSpriteFrameName);
        tolua_function(tolua_S,"setCheckedPressImage",lua_cocos2dx_cocoswidget_CCheckBox_setCheckedPressImage);
        tolua_function(tolua_S,"setNormalImage",lua_cocos2dx_cocoswidget_CCheckBox_setNormalImage);
        tolua_function(tolua_S,"setCheckedTexture",lua_cocos2dx_cocoswidget_CCheckBox_setCheckedTexture);
        tolua_function(tolua_S,"setCheckedSpriteFrameName",lua_cocos2dx_cocoswidget_CCheckBox_setCheckedSpriteFrameName);
        tolua_function(tolua_S,"setCheckedPressTexture",lua_cocos2dx_cocoswidget_CCheckBox_setCheckedPressTexture);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CCheckBox_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_CCheckBox_create);
		tolua_function(tolua_S, "setOnClickScriptHandler", lua_cocos2dx_cocoswidget_CCheckBox_setOnClickScriptHandler);
		tolua_function(tolua_S, "setOnLongClickScriptHandler", lua_cocos2dx_cocoswidget_CCheckBox_setOnLongClickScriptHandler);
		tolua_function(tolua_S, "setOnCheckScriptHandler", lua_cocos2dx_cocoswidget_CCheckBox_setOnCheckScriptHandler);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CCheckBox).name();
    g_luaType[typeName] = "cc.cocoswidget::CCheckBox";
    g_typeCast["CCheckBox"] = "cc.cocoswidget::CCheckBox";
    return 1;
}

int lua_cocos2dx_cocoswidget_CControlView_setBaseBoardImage(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CControlView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CControlView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CControlView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CControlView_setBaseBoardImage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setBaseBoardImage(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBaseBoardImage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CControlView_setBaseBoardImage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CControlView_setJoystickSpriteFrame(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CControlView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CControlView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CControlView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CControlView_setJoystickSpriteFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::SpriteFrame* arg0;

        ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);
        if(!ok)
            return 0;
        cobj->setJoystickSpriteFrame(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setJoystickSpriteFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CControlView_setJoystickSpriteFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CControlView_setBaseBoardSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CControlView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CControlView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CControlView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CControlView_setBaseBoardSpriteFrameName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setBaseBoardSpriteFrameName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBaseBoardSpriteFrameName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CControlView_setBaseBoardSpriteFrameName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CControlView_initWithFile(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CControlView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CControlView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CControlView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CControlView_initWithFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        const char* arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        bool ret = cobj->initWithFile(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWithFile",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CControlView_initWithFile'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CControlView_setJoystickTexture(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CControlView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CControlView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CControlView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CControlView_setJoystickTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Texture2D* arg0;

        ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);
        if(!ok)
            return 0;
        cobj->setJoystickTexture(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setJoystickTexture",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CControlView_setJoystickTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CControlView_setJoystickImage(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CControlView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CControlView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CControlView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CControlView_setJoystickImage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setJoystickImage(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setJoystickImage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CControlView_setJoystickImage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CControlView_setJoystickSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CControlView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CControlView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CControlView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CControlView_setJoystickSpriteFrameName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setJoystickSpriteFrameName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setJoystickSpriteFrameName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CControlView_setJoystickSpriteFrameName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CControlView_onTouchCancelled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CControlView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CControlView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CControlView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CControlView_onTouchCancelled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchCancelled(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchCancelled",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CControlView_onTouchCancelled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CControlView_isRelocateWithAnimation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CControlView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CControlView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CControlView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CControlView_isRelocateWithAnimation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isRelocateWithAnimation();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isRelocateWithAnimation",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CControlView_isRelocateWithAnimation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CControlView_onTouchBegan(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CControlView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CControlView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CControlView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CControlView_onTouchBegan'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Touch* arg0;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);
        if(!ok)
            return 0;
        int ret = (int)cobj->onTouchBegan(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchBegan",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CControlView_onTouchBegan'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CControlView_init(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CControlView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CControlView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CControlView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CControlView_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CControlView_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CControlView_onTouchMoved(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CControlView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CControlView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CControlView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CControlView_onTouchMoved'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchMoved(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchMoved",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CControlView_onTouchMoved'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CControlView_setBaseBoardSpriteFrame(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CControlView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CControlView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CControlView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CControlView_setBaseBoardSpriteFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::SpriteFrame* arg0;

        ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);
        if(!ok)
            return 0;
        cobj->setBaseBoardSpriteFrame(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBaseBoardSpriteFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CControlView_setBaseBoardSpriteFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CControlView_onTouchEnded(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CControlView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CControlView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CControlView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CControlView_onTouchEnded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchEnded(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchEnded",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CControlView_onTouchEnded'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CControlView_setRelocateWithAnimation(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CControlView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CControlView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CControlView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CControlView_setRelocateWithAnimation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setRelocateWithAnimation(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setRelocateWithAnimation",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CControlView_setRelocateWithAnimation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CControlView_setContentSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CControlView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CControlView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CControlView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CControlView_setContentSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setContentSize(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setContentSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CControlView_setContentSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CControlView_setRadius(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CControlView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CControlView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CControlView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CControlView_setRadius'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setRadius(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setRadius",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CControlView_setRadius'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CControlView_setBaseBoardTexture(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CControlView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CControlView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CControlView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CControlView_setBaseBoardTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Texture2D* arg0;

        ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);
        if(!ok)
            return 0;
        cobj->setBaseBoardTexture(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBaseBoardTexture",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CControlView_setBaseBoardTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CControlView_getRadius(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CControlView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CControlView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CControlView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CControlView_getRadius'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getRadius();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getRadius",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CControlView_getRadius'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CControlView_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CControlView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
            if (!ok) { break; }
            cocos2d::cocoswidget::CControlView* ret = cocos2d::cocoswidget::CControlView::create(arg0, arg1);
            object_to_luaval<cocos2d::cocoswidget::CControlView>(tolua_S, "cc.cocoswidget::CControlView",(cocos2d::cocoswidget::CControlView*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            cocos2d::cocoswidget::CControlView* ret = cocos2d::cocoswidget::CControlView::create();
            object_to_luaval<cocos2d::cocoswidget::CControlView>(tolua_S, "cc.cocoswidget::CControlView",(cocos2d::cocoswidget::CControlView*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CControlView_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CControlView_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CControlView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CControlView();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CControlView");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CControlView",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CControlView_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CControlView_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CControlView)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CControlView(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CControlView");
    tolua_cclass(tolua_S,"CControlView","cc.cocoswidget::CControlView","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"CControlView");
        tolua_function(tolua_S,"setBaseBoardImage",lua_cocos2dx_cocoswidget_CControlView_setBaseBoardImage);
        tolua_function(tolua_S,"setJoystickSpriteFrame",lua_cocos2dx_cocoswidget_CControlView_setJoystickSpriteFrame);
        tolua_function(tolua_S,"setBaseBoardSpriteFrameName",lua_cocos2dx_cocoswidget_CControlView_setBaseBoardSpriteFrameName);
        tolua_function(tolua_S,"initWithFile",lua_cocos2dx_cocoswidget_CControlView_initWithFile);
        tolua_function(tolua_S,"setJoystickTexture",lua_cocos2dx_cocoswidget_CControlView_setJoystickTexture);
        tolua_function(tolua_S,"setJoystickImage",lua_cocos2dx_cocoswidget_CControlView_setJoystickImage);
        tolua_function(tolua_S,"setJoystickSpriteFrameName",lua_cocos2dx_cocoswidget_CControlView_setJoystickSpriteFrameName);
        tolua_function(tolua_S,"onTouchCancelled",lua_cocos2dx_cocoswidget_CControlView_onTouchCancelled);
        tolua_function(tolua_S,"isRelocateWithAnimation",lua_cocos2dx_cocoswidget_CControlView_isRelocateWithAnimation);
        tolua_function(tolua_S,"onTouchBegan",lua_cocos2dx_cocoswidget_CControlView_onTouchBegan);
        tolua_function(tolua_S,"init",lua_cocos2dx_cocoswidget_CControlView_init);
        tolua_function(tolua_S,"onTouchMoved",lua_cocos2dx_cocoswidget_CControlView_onTouchMoved);
        tolua_function(tolua_S,"setBaseBoardSpriteFrame",lua_cocos2dx_cocoswidget_CControlView_setBaseBoardSpriteFrame);
        tolua_function(tolua_S,"onTouchEnded",lua_cocos2dx_cocoswidget_CControlView_onTouchEnded);
        tolua_function(tolua_S,"setRelocateWithAnimation",lua_cocos2dx_cocoswidget_CControlView_setRelocateWithAnimation);
        tolua_function(tolua_S,"setContentSize",lua_cocos2dx_cocoswidget_CControlView_setContentSize);
        tolua_function(tolua_S,"setRadius",lua_cocos2dx_cocoswidget_CControlView_setRadius);
        tolua_function(tolua_S,"setBaseBoardTexture",lua_cocos2dx_cocoswidget_CControlView_setBaseBoardTexture);
        tolua_function(tolua_S,"getRadius",lua_cocos2dx_cocoswidget_CControlView_getRadius);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CControlView_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_CControlView_create);
		tolua_function(tolua_S, "setOnControlScriptHandler", lua_cocos2dx_cocoswidget_CControlView_setOnControlScriptHandler);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CControlView).name();
    g_luaType[typeName] = "cc.cocoswidget::CControlView";
    g_typeCast["CControlView"] = "cc.cocoswidget::CControlView";
    return 1;
}

int lua_cocos2dx_cocoswidget_CProgressBar_setProgressSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_setProgressSpriteFrameName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setProgressSpriteFrameName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setProgressSpriteFrameName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_setProgressSpriteFrameName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_setBackgroundTexture(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_setBackgroundTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Texture2D* arg0;

        ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);
        if(!ok)
            return 0;
        cobj->setBackgroundTexture(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBackgroundTexture",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_setBackgroundTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_setBackgroundSpriteFrame(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_setBackgroundSpriteFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::SpriteFrame* arg0;

        ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);
        if(!ok)
            return 0;
        cobj->setBackgroundSpriteFrame(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBackgroundSpriteFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_setBackgroundSpriteFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_getDirection(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_getDirection'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = (int)cobj->getDirection();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDirection",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_getDirection'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_getLabel(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_getLabel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CLabel* ret = cobj->getLabel();
        object_to_luaval<cocos2d::cocoswidget::CLabel>(tolua_S, "cc.cocoswidget::CLabel",(cocos2d::cocoswidget::CLabel*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getLabel",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_getLabel'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_getLabelFormat(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_getLabelFormat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = (int)cobj->getLabelFormat();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getLabelFormat",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_getLabelFormat'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_getBackgroundImage(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_getBackgroundImage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Sprite* ret = cobj->getBackgroundImage();
        object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBackgroundImage",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_getBackgroundImage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_startProgress(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_startProgress'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        double arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->startProgress(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "startProgress",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_startProgress'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_setBackgroundSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_setBackgroundSpriteFrameName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setBackgroundSpriteFrameName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBackgroundSpriteFrameName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_setBackgroundSpriteFrameName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_removeBackgroundGradient(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_removeBackgroundGradient'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeBackgroundGradient();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeBackgroundGradient",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_removeBackgroundGradient'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_setDirection(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_setDirection'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::cocoswidget::CProgressBarDirection arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setDirection(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDirection",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_setDirection'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_setProgressImage(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_setProgressImage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setProgressImage(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setProgressImage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_setProgressImage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_getPercentage(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_getPercentage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getPercentage();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getPercentage",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_getPercentage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_setMinValue(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_setMinValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setMinValue(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setMinValue",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_setMinValue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_getMinValue(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_getMinValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getMinValue();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getMinValue",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_getMinValue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_init(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_getMaxValue(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_getMaxValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getMaxValue();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getMaxValue",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_getMaxValue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_initText(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_initText'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 5) 
    {
        std::string arg0;
        std::string arg1;
        double arg2;
        cocos2d::Size arg3;
        cocos2d::Color3B arg4;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_std_string(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_size(tolua_S, 5, &arg3);

        ok &= luaval_to_color3b(tolua_S, 6, &arg4);
        if(!ok)
            return 0;
        cobj->initText(arg0, arg1, arg2, arg3, arg4);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initText",argc, 5);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_initText'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_setBackgroundOpacity(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_setBackgroundOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setBackgroundOpacity(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBackgroundOpacity",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_setBackgroundOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_setValue(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_setValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setValue(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setValue",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_setValue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_removeBackgroundColor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_removeBackgroundColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeBackgroundColor();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeBackgroundColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_removeBackgroundColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_setShowValueLabel(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_setShowValueLabel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setShowValueLabel(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setShowValueLabel",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_setShowValueLabel'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_startProgressFromTo(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_startProgressFromTo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        int arg0;
        int arg1;
        double arg2;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cobj->startProgressFromTo(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "startProgressFromTo",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_startProgressFromTo'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_setBackgroundImage(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_setBackgroundImage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setBackgroundImage(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBackgroundImage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_setBackgroundImage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_setBackgroundColor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_setBackgroundColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color4B arg0;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setBackgroundColor(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBackgroundColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_setBackgroundColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_setProgressTexture(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_setProgressTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Texture2D* arg0;

        ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);
        if(!ok)
            return 0;
        cobj->setProgressTexture(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setProgressTexture",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_setProgressTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_setContentSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_setContentSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setContentSize(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setContentSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_setContentSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_setProgressSpriteFrame(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_setProgressSpriteFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::SpriteFrame* arg0;

        ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);
        if(!ok)
            return 0;
        cobj->setProgressSpriteFrame(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setProgressSpriteFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_setProgressSpriteFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_setLabelFormat(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_setLabelFormat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::cocoswidget::eLabFormat arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setLabelFormat(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setLabelFormat",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_setLabelFormat'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_initWithFile(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_initWithFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        bool ret = cobj->initWithFile(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWithFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_initWithFile'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_stopProgress(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_stopProgress'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->stopProgress();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "stopProgress",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_stopProgress'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_isProgressEnded(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_isProgressEnded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isProgressEnded();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isProgressEnded",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_isProgressEnded'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_setMaxValue(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_setMaxValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setMaxValue(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setMaxValue",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_setMaxValue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_getValue(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_getValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getValue();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getValue",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_getValue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_setBackgroundGradient(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_setBackgroundGradient'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Color4B arg0;
        cocos2d::Color4B arg1;
        cocos2d::Point arg2;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0);

        ok &=luaval_to_color4b(tolua_S, 3, &arg1);

        ok &= luaval_to_point(tolua_S, 4, &arg2);
        if(!ok)
            return 0;
        cobj->setBackgroundGradient(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBackgroundGradient",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_setBackgroundGradient'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_removeBackgroundImage(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CProgressBar_removeBackgroundImage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeBackgroundImage();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeBackgroundImage",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_removeBackgroundImage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            cocos2d::cocoswidget::CProgressBar* ret = cocos2d::cocoswidget::CProgressBar::create(arg0);
            object_to_luaval<cocos2d::cocoswidget::CProgressBar>(tolua_S, "cc.cocoswidget::CProgressBar",(cocos2d::cocoswidget::CProgressBar*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            cocos2d::cocoswidget::CProgressBar* ret = cocos2d::cocoswidget::CProgressBar::create();
            object_to_luaval<cocos2d::cocoswidget::CProgressBar>(tolua_S, "cc.cocoswidget::CProgressBar",(cocos2d::cocoswidget::CProgressBar*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CProgressBar_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CProgressBar();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CProgressBar");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CProgressBar",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CProgressBar_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CProgressBar_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CProgressBar)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CProgressBar(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CProgressBar");
    tolua_cclass(tolua_S,"CProgressBar","cc.cocoswidget::CProgressBar","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"CProgressBar");
        tolua_function(tolua_S,"setProgressSpriteFrameName",lua_cocos2dx_cocoswidget_CProgressBar_setProgressSpriteFrameName);
        tolua_function(tolua_S,"setBackgroundTexture",lua_cocos2dx_cocoswidget_CProgressBar_setBackgroundTexture);
        tolua_function(tolua_S,"setBackgroundSpriteFrame",lua_cocos2dx_cocoswidget_CProgressBar_setBackgroundSpriteFrame);
        tolua_function(tolua_S,"getDirection",lua_cocos2dx_cocoswidget_CProgressBar_getDirection);
        tolua_function(tolua_S,"getLabel",lua_cocos2dx_cocoswidget_CProgressBar_getLabel);
        tolua_function(tolua_S,"getLabelFormat",lua_cocos2dx_cocoswidget_CProgressBar_getLabelFormat);
        tolua_function(tolua_S,"getBackgroundImage",lua_cocos2dx_cocoswidget_CProgressBar_getBackgroundImage);
        tolua_function(tolua_S,"startProgress",lua_cocos2dx_cocoswidget_CProgressBar_startProgress);
        tolua_function(tolua_S,"setBackgroundSpriteFrameName",lua_cocos2dx_cocoswidget_CProgressBar_setBackgroundSpriteFrameName);
        tolua_function(tolua_S,"removeBackgroundGradient",lua_cocos2dx_cocoswidget_CProgressBar_removeBackgroundGradient);
        tolua_function(tolua_S,"setDirection",lua_cocos2dx_cocoswidget_CProgressBar_setDirection);
        tolua_function(tolua_S,"setProgressImage",lua_cocos2dx_cocoswidget_CProgressBar_setProgressImage);
        tolua_function(tolua_S,"getPercentage",lua_cocos2dx_cocoswidget_CProgressBar_getPercentage);
        tolua_function(tolua_S,"setMinValue",lua_cocos2dx_cocoswidget_CProgressBar_setMinValue);
        tolua_function(tolua_S,"getMinValue",lua_cocos2dx_cocoswidget_CProgressBar_getMinValue);
        tolua_function(tolua_S,"init",lua_cocos2dx_cocoswidget_CProgressBar_init);
        tolua_function(tolua_S,"getMaxValue",lua_cocos2dx_cocoswidget_CProgressBar_getMaxValue);
        tolua_function(tolua_S,"initText",lua_cocos2dx_cocoswidget_CProgressBar_initText);
        tolua_function(tolua_S,"setBackgroundOpacity",lua_cocos2dx_cocoswidget_CProgressBar_setBackgroundOpacity);
        tolua_function(tolua_S,"setValue",lua_cocos2dx_cocoswidget_CProgressBar_setValue);
        tolua_function(tolua_S,"removeBackgroundColor",lua_cocos2dx_cocoswidget_CProgressBar_removeBackgroundColor);
        tolua_function(tolua_S,"setShowValueLabel",lua_cocos2dx_cocoswidget_CProgressBar_setShowValueLabel);
        tolua_function(tolua_S,"startProgressFromTo",lua_cocos2dx_cocoswidget_CProgressBar_startProgressFromTo);
        tolua_function(tolua_S,"setBackgroundImage",lua_cocos2dx_cocoswidget_CProgressBar_setBackgroundImage);
        tolua_function(tolua_S,"setBackgroundColor",lua_cocos2dx_cocoswidget_CProgressBar_setBackgroundColor);
        tolua_function(tolua_S,"setProgressTexture",lua_cocos2dx_cocoswidget_CProgressBar_setProgressTexture);
        tolua_function(tolua_S,"setContentSize",lua_cocos2dx_cocoswidget_CProgressBar_setContentSize);
        tolua_function(tolua_S,"setProgressSpriteFrame",lua_cocos2dx_cocoswidget_CProgressBar_setProgressSpriteFrame);
        tolua_function(tolua_S,"setLabelFormat",lua_cocos2dx_cocoswidget_CProgressBar_setLabelFormat);
        tolua_function(tolua_S,"initWithFile",lua_cocos2dx_cocoswidget_CProgressBar_initWithFile);
        tolua_function(tolua_S,"stopProgress",lua_cocos2dx_cocoswidget_CProgressBar_stopProgress);
        tolua_function(tolua_S,"isProgressEnded",lua_cocos2dx_cocoswidget_CProgressBar_isProgressEnded);
        tolua_function(tolua_S,"setMaxValue",lua_cocos2dx_cocoswidget_CProgressBar_setMaxValue);
        tolua_function(tolua_S,"getValue",lua_cocos2dx_cocoswidget_CProgressBar_getValue);
        tolua_function(tolua_S,"setBackgroundGradient",lua_cocos2dx_cocoswidget_CProgressBar_setBackgroundGradient);
        tolua_function(tolua_S,"removeBackgroundImage",lua_cocos2dx_cocoswidget_CProgressBar_removeBackgroundImage);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CProgressBar_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_CProgressBar_create);
		tolua_function(tolua_S,"setOnProgressEndedScriptHandler", lua_cocos2dx_cocoswidget_CProgressBar_setOnProgressEndedScriptHandler);
		tolua_function(tolua_S, "setOnValueChangedScriptHandler", lua_cocos2dx_cocoswidget_CProgressBar_setOnValueChangedScriptHandler);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CProgressBar).name();
    g_luaType[typeName] = "cc.cocoswidget::CProgressBar";
    g_typeCast["CProgressBar"] = "cc.cocoswidget::CProgressBar";
    return 1;
}

int lua_cocos2dx_cocoswidget_CSlider_onTouchMoved(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CSlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CSlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CSlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CSlider_onTouchMoved'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchMoved(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchMoved",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CSlider_onTouchMoved'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CSlider_setValue(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CSlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CSlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CSlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CSlider_setValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setValue(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setValue",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CSlider_setValue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CSlider_onTouchEnded(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CSlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CSlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CSlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CSlider_onTouchEnded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchEnded(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchEnded",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CSlider_onTouchEnded'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CSlider_setSliderSpriteFrame(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CSlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CSlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CSlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CSlider_setSliderSpriteFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::SpriteFrame* arg0;

        ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0);
        if(!ok)
            return 0;
        cobj->setSliderSpriteFrame(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSliderSpriteFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CSlider_setSliderSpriteFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CSlider_onTouchCancelled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CSlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CSlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CSlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CSlider_onTouchCancelled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchCancelled(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchCancelled",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CSlider_onTouchCancelled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CSlider_initWithSlider(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CSlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CSlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CSlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CSlider_initWithSlider'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        const char* arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        bool ret = cobj->initWithSlider(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWithSlider",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CSlider_initWithSlider'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CSlider_setSliderImage(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CSlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CSlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CSlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CSlider_setSliderImage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setSliderImage(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSliderImage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CSlider_setSliderImage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CSlider_setContentSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CSlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CSlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CSlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CSlider_setContentSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setContentSize(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setContentSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CSlider_setContentSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CSlider_onTouchBegan(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CSlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CSlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CSlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CSlider_onTouchBegan'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Touch* arg0;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);
        if(!ok)
            return 0;
        int ret = (int)cobj->onTouchBegan(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchBegan",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CSlider_onTouchBegan'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CSlider_setSliderTexture(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CSlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CSlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CSlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CSlider_setSliderTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Texture2D* arg0;

        ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0);
        if(!ok)
            return 0;
        cobj->setSliderTexture(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSliderTexture",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CSlider_setSliderTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CSlider_setSliderSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CSlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CSlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CSlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CSlider_setSliderSpriteFrameName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setSliderSpriteFrameName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSliderSpriteFrameName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CSlider_setSliderSpriteFrameName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CSlider_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CSlider",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
            if (!ok) { break; }
            cocos2d::cocoswidget::CSlider* ret = cocos2d::cocoswidget::CSlider::create(arg0, arg1);
            object_to_luaval<cocos2d::cocoswidget::CSlider>(tolua_S, "cc.cocoswidget::CSlider",(cocos2d::cocoswidget::CSlider*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            cocos2d::cocoswidget::CSlider* ret = cocos2d::cocoswidget::CSlider::create();
            object_to_luaval<cocos2d::cocoswidget::CSlider>(tolua_S, "cc.cocoswidget::CSlider",(cocos2d::cocoswidget::CSlider*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CSlider_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CSlider_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CSlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CSlider();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CSlider");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CSlider",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CSlider_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CSlider_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CSlider)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CSlider(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CSlider");
    tolua_cclass(tolua_S,"CSlider","cc.cocoswidget::CSlider","cc.cocoswidget::CProgressBar",nullptr);

    tolua_beginmodule(tolua_S,"CSlider");
        tolua_function(tolua_S,"onTouchMoved",lua_cocos2dx_cocoswidget_CSlider_onTouchMoved);
        tolua_function(tolua_S,"setValue",lua_cocos2dx_cocoswidget_CSlider_setValue);
        tolua_function(tolua_S,"onTouchEnded",lua_cocos2dx_cocoswidget_CSlider_onTouchEnded);
        tolua_function(tolua_S,"setSliderSpriteFrame",lua_cocos2dx_cocoswidget_CSlider_setSliderSpriteFrame);
        tolua_function(tolua_S,"onTouchCancelled",lua_cocos2dx_cocoswidget_CSlider_onTouchCancelled);
        tolua_function(tolua_S,"initWithSlider",lua_cocos2dx_cocoswidget_CSlider_initWithSlider);
        tolua_function(tolua_S,"setSliderImage",lua_cocos2dx_cocoswidget_CSlider_setSliderImage);
        tolua_function(tolua_S,"setContentSize",lua_cocos2dx_cocoswidget_CSlider_setContentSize);
        tolua_function(tolua_S,"onTouchBegan",lua_cocos2dx_cocoswidget_CSlider_onTouchBegan);
        tolua_function(tolua_S,"setSliderTexture",lua_cocos2dx_cocoswidget_CSlider_setSliderTexture);
        tolua_function(tolua_S,"setSliderSpriteFrameName",lua_cocos2dx_cocoswidget_CSlider_setSliderSpriteFrameName);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CSlider_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_CSlider_create);
		tolua_function(tolua_S, "setOnValueChangedScriptHandler", lua_cocos2dx_cocoswidget_CSlider_setOnValueChangedScriptHandler);
		
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CSlider).name();
    g_luaType[typeName] = "cc.cocoswidget::CSlider";
    g_typeCast["CSlider"] = "cc.cocoswidget::CSlider";
    return 1;
}

int lua_cocos2dx_cocoswidget_CTextRich_insertElement(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTextRich* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTextRich",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::cocoswidget::CTextRich*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTextRich_insertElement'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            cocos2d::Node* arg0;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);

            if (!ok) { break; }
            cobj->insertElement(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            cocos2d::Node* arg0;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);

            if (!ok) { break; }
            unsigned int arg1;
            ok &= luaval_to_uint32(tolua_S, 3,&arg1);

            if (!ok) { break; }
            cobj->insertElement(arg0, arg1);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 3) {
            cocos2d::Node* arg0;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);

            if (!ok) { break; }
            unsigned int arg1;
            ok &= luaval_to_uint32(tolua_S, 3,&arg1);

            if (!ok) { break; }
            const char* arg2;
            std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();

            if (!ok) { break; }
            cobj->insertElement(arg0, arg1, arg2);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->insertElement(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

            if (!ok) { break; }
            cobj->insertElement(arg0, arg1);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 3) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2);

            if (!ok) { break; }
            cobj->insertElement(arg0, arg1, arg2);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 4) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2);

            if (!ok) { break; }
            cocos2d::Color3B arg3;
            ok &= luaval_to_color3b(tolua_S, 5, &arg3);

            if (!ok) { break; }
            cobj->insertElement(arg0, arg1, arg2, arg3);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 5) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2);

            if (!ok) { break; }
            cocos2d::Color3B arg3;
            ok &= luaval_to_color3b(tolua_S, 5, &arg3);

            if (!ok) { break; }
            const char* arg4;
            std::string arg4_tmp; ok &= luaval_to_std_string(tolua_S, 6, &arg4_tmp); arg4 = arg4_tmp.c_str();

            if (!ok) { break; }
            cobj->insertElement(arg0, arg1, arg2, arg3, arg4);
            return 0;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "insertElement",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTextRich_insertElement'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTextRich_setFontName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTextRich* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTextRich",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTextRich*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTextRich_setFontName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setFontName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setFontName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTextRich_setFontName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTextRich_getFontSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTextRich* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTextRich",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTextRich*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTextRich_getFontSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getFontSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getFontSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTextRich_getFontSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTextRich_onTouchEnded(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTextRich* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTextRich",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTextRich*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTextRich_onTouchEnded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchEnded(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchEnded",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTextRich_onTouchEnded'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTextRich_onTouchMoved(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTextRich* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTextRich",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTextRich*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTextRich_onTouchMoved'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchMoved(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchMoved",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTextRich_onTouchMoved'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTextRich_onTouchCancelled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTextRich* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTextRich",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTextRich*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTextRich_onTouchCancelled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchCancelled(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchCancelled",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTextRich_onTouchCancelled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTextRich_onTouchBegan(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTextRich* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTextRich",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTextRich*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTextRich_onTouchBegan'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Touch* arg0;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);
        if(!ok)
            return 0;
        int ret = (int)cobj->onTouchBegan(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchBegan",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTextRich_onTouchBegan'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTextRich_setVerticalSpacing(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTextRich* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTextRich",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTextRich*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTextRich_setVerticalSpacing'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setVerticalSpacing(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setVerticalSpacing",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTextRich_setVerticalSpacing'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTextRich_init(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTextRich* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTextRich",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTextRich*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTextRich_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTextRich_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTextRich_reloadData(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTextRich* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTextRich",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTextRich*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTextRich_reloadData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->reloadData();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "reloadData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTextRich_reloadData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTextRich_setFontSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTextRich* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTextRich",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTextRich*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTextRich_setFontSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setFontSize(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setFontSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTextRich_setFontSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTextRich_setMaxLineLength(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTextRich* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTextRich",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTextRich*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTextRich_setMaxLineLength'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setMaxLineLength(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setMaxLineLength",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTextRich_setMaxLineLength'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTextRich_getVerticalSpacing(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTextRich* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTextRich",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTextRich*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTextRich_getVerticalSpacing'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getVerticalSpacing();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getVerticalSpacing",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTextRich_getVerticalSpacing'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTextRich_getMaxLineLength(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTextRich* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTextRich",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTextRich*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTextRich_getMaxLineLength'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        unsigned int ret = cobj->getMaxLineLength();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getMaxLineLength",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTextRich_getMaxLineLength'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTextRich_getFontName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTextRich* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTextRich",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTextRich*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTextRich_getFontName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getFontName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getFontName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTextRich_getFontName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTextRich_removeAllElements(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTextRich* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CTextRich",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CTextRich*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CTextRich_removeAllElements'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeAllElements();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeAllElements",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTextRich_removeAllElements'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CTextRich_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CTextRich",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CTextRich* ret = cocos2d::cocoswidget::CTextRich::create();
        object_to_luaval<cocos2d::cocoswidget::CTextRich>(tolua_S, "cc.cocoswidget::CTextRich",(cocos2d::cocoswidget::CTextRich*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTextRich_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CTextRich_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CTextRich* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CTextRich();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CTextRich");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CTextRich",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CTextRich_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CTextRich_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CTextRich)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CTextRich(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CTextRich");
    tolua_cclass(tolua_S,"CTextRich","cc.cocoswidget::CTextRich","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"CTextRich");
        tolua_function(tolua_S,"insertElement",lua_cocos2dx_cocoswidget_CTextRich_insertElement);
        tolua_function(tolua_S,"setFontName",lua_cocos2dx_cocoswidget_CTextRich_setFontName);
        tolua_function(tolua_S,"getFontSize",lua_cocos2dx_cocoswidget_CTextRich_getFontSize);
        tolua_function(tolua_S,"onTouchEnded",lua_cocos2dx_cocoswidget_CTextRich_onTouchEnded);
        tolua_function(tolua_S,"onTouchMoved",lua_cocos2dx_cocoswidget_CTextRich_onTouchMoved);
        tolua_function(tolua_S,"onTouchCancelled",lua_cocos2dx_cocoswidget_CTextRich_onTouchCancelled);
        tolua_function(tolua_S,"onTouchBegan",lua_cocos2dx_cocoswidget_CTextRich_onTouchBegan);
        tolua_function(tolua_S,"setVerticalSpacing",lua_cocos2dx_cocoswidget_CTextRich_setVerticalSpacing);
        tolua_function(tolua_S,"init",lua_cocos2dx_cocoswidget_CTextRich_init);
        tolua_function(tolua_S,"reloadData",lua_cocos2dx_cocoswidget_CTextRich_reloadData);
        tolua_function(tolua_S,"setFontSize",lua_cocos2dx_cocoswidget_CTextRich_setFontSize);
        tolua_function(tolua_S,"setMaxLineLength",lua_cocos2dx_cocoswidget_CTextRich_setMaxLineLength);
        tolua_function(tolua_S,"getVerticalSpacing",lua_cocos2dx_cocoswidget_CTextRich_getVerticalSpacing);
        tolua_function(tolua_S,"getMaxLineLength",lua_cocos2dx_cocoswidget_CTextRich_getMaxLineLength);
        tolua_function(tolua_S,"getFontName",lua_cocos2dx_cocoswidget_CTextRich_getFontName);
        tolua_function(tolua_S,"removeAllElements",lua_cocos2dx_cocoswidget_CTextRich_removeAllElements);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CTextRich_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_CTextRich_create);
		tolua_function(tolua_S, "setOnTextRichClickScriptHandler", lua_cocos2dx_cocoswidget_CTextRich_setOnTextRichClickScriptHandler);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CTextRich).name();
    g_luaType[typeName] = "cc.cocoswidget::CTextRich";
    g_typeCast["CTextRich"] = "cc.cocoswidget::CTextRich";
    return 1;
}

int lua_cocos2dx_cocoswidget_CExpandableNode_onTouchMoved(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CExpandableNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CExpandableNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CExpandableNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CExpandableNode_onTouchMoved'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchMoved(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchMoved",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CExpandableNode_onTouchMoved'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CExpandableNode_onTouchEnded(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CExpandableNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CExpandableNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CExpandableNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CExpandableNode_onTouchEnded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchEnded(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchEnded",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CExpandableNode_onTouchEnded'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CExpandableNode_removeItemNodeAtIndex(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CExpandableNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CExpandableNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CExpandableNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CExpandableNode_removeItemNodeAtIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->removeItemNodeAtIndex(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeItemNodeAtIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CExpandableNode_removeItemNodeAtIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CExpandableNode_onTouchCancelled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CExpandableNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CExpandableNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CExpandableNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CExpandableNode_onTouchCancelled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchCancelled(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchCancelled",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CExpandableNode_onTouchCancelled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CExpandableNode_insertItemNodeAtFront(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CExpandableNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CExpandableNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CExpandableNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CExpandableNode_insertItemNodeAtFront'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);
        if(!ok)
            return 0;
        cobj->insertItemNodeAtFront(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "insertItemNodeAtFront",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CExpandableNode_insertItemNodeAtFront'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CExpandableNode_removeItemNode(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CExpandableNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CExpandableNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CExpandableNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CExpandableNode_removeItemNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);
        if(!ok)
            return 0;
        cobj->removeItemNode(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeItemNode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CExpandableNode_removeItemNode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CExpandableNode_removeAllItemNodes(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CExpandableNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CExpandableNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CExpandableNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CExpandableNode_removeAllItemNodes'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeAllItemNodes();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeAllItemNodes",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CExpandableNode_removeAllItemNodes'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CExpandableNode_insertItemNodeAtLast(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CExpandableNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CExpandableNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CExpandableNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CExpandableNode_insertItemNodeAtLast'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);
        if(!ok)
            return 0;
        cobj->insertItemNodeAtLast(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "insertItemNodeAtLast",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CExpandableNode_insertItemNodeAtLast'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CExpandableNode_onTouchBegan(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CExpandableNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CExpandableNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CExpandableNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CExpandableNode_onTouchBegan'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Touch* arg0;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);
        if(!ok)
            return 0;
        int ret = (int)cobj->onTouchBegan(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchBegan",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CExpandableNode_onTouchBegan'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CExpandableNode_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CExpandableNode",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CExpandableNode* ret = cocos2d::cocoswidget::CExpandableNode::create();
        object_to_luaval<cocos2d::cocoswidget::CExpandableNode>(tolua_S, "cc.cocoswidget::CExpandableNode",(cocos2d::cocoswidget::CExpandableNode*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CExpandableNode_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CExpandableNode_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CExpandableNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CExpandableNode();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CExpandableNode");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CExpandableNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CExpandableNode_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CExpandableNode_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CExpandableNode)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CExpandableNode(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CExpandableNode");
    tolua_cclass(tolua_S,"CExpandableNode","cc.cocoswidget::CExpandableNode","cc.cocoswidget::CLayout",nullptr);

    tolua_beginmodule(tolua_S,"CExpandableNode");
        tolua_function(tolua_S,"onTouchMoved",lua_cocos2dx_cocoswidget_CExpandableNode_onTouchMoved);
        tolua_function(tolua_S,"onTouchEnded",lua_cocos2dx_cocoswidget_CExpandableNode_onTouchEnded);
        tolua_function(tolua_S,"removeItemNodeAtIndex",lua_cocos2dx_cocoswidget_CExpandableNode_removeItemNodeAtIndex);
        tolua_function(tolua_S,"onTouchCancelled",lua_cocos2dx_cocoswidget_CExpandableNode_onTouchCancelled);
        tolua_function(tolua_S,"insertItemNodeAtFront",lua_cocos2dx_cocoswidget_CExpandableNode_insertItemNodeAtFront);
        tolua_function(tolua_S,"removeItemNode",lua_cocos2dx_cocoswidget_CExpandableNode_removeItemNode);
        tolua_function(tolua_S,"removeAllItemNodes",lua_cocos2dx_cocoswidget_CExpandableNode_removeAllItemNodes);
        tolua_function(tolua_S,"insertItemNodeAtLast",lua_cocos2dx_cocoswidget_CExpandableNode_insertItemNodeAtLast);
        tolua_function(tolua_S,"onTouchBegan",lua_cocos2dx_cocoswidget_CExpandableNode_onTouchBegan);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CExpandableNode_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_CExpandableNode_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CExpandableNode).name();
    g_luaType[typeName] = "cc.cocoswidget::CExpandableNode";
    g_typeCast["CExpandableNode"] = "cc.cocoswidget::CExpandableNode";
    return 1;
}

int lua_cocos2dx_cocoswidget_CExpandableListView_getExpandableNodeCount(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CExpandableListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CExpandableListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CExpandableListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CExpandableListView_getExpandableNodeCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        unsigned int ret = cobj->getExpandableNodeCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getExpandableNodeCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CExpandableListView_getExpandableNodeCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CExpandableListView_removeLastExpandableNode(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CExpandableListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CExpandableListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CExpandableListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CExpandableListView_removeLastExpandableNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeLastExpandableNode();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeLastExpandableNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CExpandableListView_removeLastExpandableNode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CExpandableListView_collapse(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CExpandableListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CExpandableListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CExpandableListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CExpandableListView_collapse'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->collapse(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "collapse",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CExpandableListView_collapse'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CExpandableListView_getExpandableNodeAtIndex(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CExpandableListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CExpandableListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CExpandableListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CExpandableListView_getExpandableNodeAtIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CExpandableNode* ret = cobj->getExpandableNodeAtIndex(arg0);
        object_to_luaval<cocos2d::cocoswidget::CExpandableNode>(tolua_S, "cc.cocoswidget::CExpandableNode",(cocos2d::cocoswidget::CExpandableNode*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getExpandableNodeAtIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CExpandableListView_getExpandableNodeAtIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CExpandableListView_removeFrontExpandableNode(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CExpandableListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CExpandableListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CExpandableListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CExpandableListView_removeFrontExpandableNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeFrontExpandableNode();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeFrontExpandableNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CExpandableListView_removeFrontExpandableNode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CExpandableListView_getExpandableNodes(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CExpandableListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CExpandableListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CExpandableListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CExpandableListView_getExpandableNodes'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Vector<cocos2d::cocoswidget::CExpandableNode *> ret = cobj->getExpandableNodes();
        ccvector_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getExpandableNodes",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CExpandableListView_getExpandableNodes'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CExpandableListView_removeExpandableNodeAtIndex(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CExpandableListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CExpandableListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CExpandableListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CExpandableListView_removeExpandableNodeAtIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->removeExpandableNodeAtIndex(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeExpandableNodeAtIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CExpandableListView_removeExpandableNodeAtIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CExpandableListView_insertExpandableNodeAtLast(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CExpandableListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CExpandableListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CExpandableListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CExpandableListView_insertExpandableNodeAtLast'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::cocoswidget::CExpandableNode* arg0;

        ok &= luaval_to_object<cocos2d::cocoswidget::CExpandableNode>(tolua_S, 2, "cc.cocoswidget::CExpandableNode",&arg0);
        if(!ok)
            return 0;
        cobj->insertExpandableNodeAtLast(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "insertExpandableNodeAtLast",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CExpandableListView_insertExpandableNodeAtLast'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CExpandableListView_removeExpandableNode(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CExpandableListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CExpandableListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CExpandableListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CExpandableListView_removeExpandableNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::cocoswidget::CExpandableNode* arg0;

        ok &= luaval_to_object<cocos2d::cocoswidget::CExpandableNode>(tolua_S, 2, "cc.cocoswidget::CExpandableNode",&arg0);
        if(!ok)
            return 0;
        cobj->removeExpandableNode(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeExpandableNode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CExpandableListView_removeExpandableNode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CExpandableListView_removeAllExpandableNodes(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CExpandableListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CExpandableListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CExpandableListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CExpandableListView_removeAllExpandableNodes'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeAllExpandableNodes();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeAllExpandableNodes",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CExpandableListView_removeAllExpandableNodes'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CExpandableListView_insertExpandableNodeAtFront(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CExpandableListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CExpandableListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CExpandableListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CExpandableListView_insertExpandableNodeAtFront'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::cocoswidget::CExpandableNode* arg0;

        ok &= luaval_to_object<cocos2d::cocoswidget::CExpandableNode>(tolua_S, 2, "cc.cocoswidget::CExpandableNode",&arg0);
        if(!ok)
            return 0;
        cobj->insertExpandableNodeAtFront(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "insertExpandableNodeAtFront",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CExpandableListView_insertExpandableNodeAtFront'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CExpandableListView_reloadData(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CExpandableListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CExpandableListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CExpandableListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CExpandableListView_reloadData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->reloadData();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "reloadData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CExpandableListView_reloadData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CExpandableListView_expand(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CExpandableListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CExpandableListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CExpandableListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CExpandableListView_expand'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->expand(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "expand",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CExpandableListView_expand'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CExpandableListView_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CExpandableListView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::Size arg0;
        ok &= luaval_to_size(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CExpandableListView* ret = cocos2d::cocoswidget::CExpandableListView::create(arg0);
        object_to_luaval<cocos2d::cocoswidget::CExpandableListView>(tolua_S, "cc.cocoswidget::CExpandableListView",(cocos2d::cocoswidget::CExpandableListView*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CExpandableListView_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CExpandableListView_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CExpandableListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CExpandableListView();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CExpandableListView");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CExpandableListView",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CExpandableListView_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CExpandableListView_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CExpandableListView)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CExpandableListView(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CExpandableListView");
    tolua_cclass(tolua_S,"CExpandableListView","cc.cocoswidget::CExpandableListView","cc.cocoswidget::CScrollView",nullptr);

    tolua_beginmodule(tolua_S,"CExpandableListView");
        tolua_function(tolua_S,"getExpandableNodeCount",lua_cocos2dx_cocoswidget_CExpandableListView_getExpandableNodeCount);
        tolua_function(tolua_S,"removeLastExpandableNode",lua_cocos2dx_cocoswidget_CExpandableListView_removeLastExpandableNode);
        tolua_function(tolua_S,"collapse",lua_cocos2dx_cocoswidget_CExpandableListView_collapse);
        tolua_function(tolua_S,"getExpandableNodeAtIndex",lua_cocos2dx_cocoswidget_CExpandableListView_getExpandableNodeAtIndex);
        tolua_function(tolua_S,"removeFrontExpandableNode",lua_cocos2dx_cocoswidget_CExpandableListView_removeFrontExpandableNode);
        tolua_function(tolua_S,"getExpandableNodes",lua_cocos2dx_cocoswidget_CExpandableListView_getExpandableNodes);
        tolua_function(tolua_S,"removeExpandableNodeAtIndex",lua_cocos2dx_cocoswidget_CExpandableListView_removeExpandableNodeAtIndex);
        tolua_function(tolua_S,"insertExpandableNodeAtLast",lua_cocos2dx_cocoswidget_CExpandableListView_insertExpandableNodeAtLast);
        tolua_function(tolua_S,"removeExpandableNode",lua_cocos2dx_cocoswidget_CExpandableListView_removeExpandableNode);
        tolua_function(tolua_S,"removeAllExpandableNodes",lua_cocos2dx_cocoswidget_CExpandableListView_removeAllExpandableNodes);
        tolua_function(tolua_S,"insertExpandableNodeAtFront",lua_cocos2dx_cocoswidget_CExpandableListView_insertExpandableNodeAtFront);
        tolua_function(tolua_S,"reloadData",lua_cocos2dx_cocoswidget_CExpandableListView_reloadData);
        tolua_function(tolua_S,"expand",lua_cocos2dx_cocoswidget_CExpandableListView_expand);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CExpandableListView_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_CExpandableListView_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CExpandableListView).name();
    g_luaType[typeName] = "cc.cocoswidget::CExpandableListView";
    g_typeCast["CExpandableListView"] = "cc.cocoswidget::CExpandableListView";
    return 1;
}

int lua_cocos2dx_cocoswidget_ArmatureBtn_onTouchBegan(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::ArmatureBtn* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::ArmatureBtn",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::ArmatureBtn*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_ArmatureBtn_onTouchBegan'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Touch* arg0;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);
        if(!ok)
            return 0;
        int ret = (int)cobj->onTouchBegan(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchBegan",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_ArmatureBtn_onTouchBegan'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_ArmatureBtn_onTouchEnded(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::ArmatureBtn* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::ArmatureBtn",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::ArmatureBtn*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_ArmatureBtn_onTouchEnded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchEnded(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchEnded",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_ArmatureBtn_onTouchEnded'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_ArmatureBtn_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::ArmatureBtn",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cocos2d::cocoswidget::ArmatureBtn* ret = cocos2d::cocoswidget::ArmatureBtn::create(arg0);
        object_to_luaval<cocos2d::cocoswidget::ArmatureBtn>(tolua_S, "cc.cocoswidget::ArmatureBtn",(cocos2d::cocoswidget::ArmatureBtn*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_ArmatureBtn_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_ArmatureBtn_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::ArmatureBtn* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::ArmatureBtn();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::ArmatureBtn");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "ArmatureBtn",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_ArmatureBtn_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_ArmatureBtn_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ArmatureBtn)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_ArmatureBtn(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::ArmatureBtn");
    tolua_cclass(tolua_S,"ArmatureBtn","cc.cocoswidget::ArmatureBtn","ccs.Armature",nullptr);

    tolua_beginmodule(tolua_S,"ArmatureBtn");
        tolua_function(tolua_S,"onTouchBegan",lua_cocos2dx_cocoswidget_ArmatureBtn_onTouchBegan);
        tolua_function(tolua_S,"onTouchEnded",lua_cocos2dx_cocoswidget_ArmatureBtn_onTouchEnded);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_ArmatureBtn_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_ArmatureBtn_create);
		tolua_function(tolua_S, "setOnClickScriptHandler", lua_cocos2dx_cocoswidget_ArmatureBtn_setOnClickScriptHandler);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::ArmatureBtn).name();
    g_luaType[typeName] = "cc.cocoswidget::ArmatureBtn";
    g_typeCast["ArmatureBtn"] = "cc.cocoswidget::ArmatureBtn";
    return 1;
}

int lua_cocos2dx_cocoswidget_NumericStepper_onTouchMoved(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::NumericStepper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::NumericStepper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::NumericStepper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_NumericStepper_onTouchMoved'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchMoved(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchMoved",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_NumericStepper_onTouchMoved'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_NumericStepper_setValue(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::NumericStepper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::NumericStepper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::NumericStepper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_NumericStepper_setValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setValue(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setValue",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_NumericStepper_setValue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_NumericStepper_onTouchEnded(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::NumericStepper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::NumericStepper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::NumericStepper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_NumericStepper_onTouchEnded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchEnded(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchEnded",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_NumericStepper_onTouchEnded'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_NumericStepper_getStep(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::NumericStepper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::NumericStepper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::NumericStepper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_NumericStepper_getStep'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getStep();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getStep",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_NumericStepper_getStep'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_NumericStepper_setrSelectedSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::NumericStepper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::NumericStepper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::NumericStepper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_NumericStepper_setrSelectedSpriteFrameName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setrSelectedSpriteFrameName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setrSelectedSpriteFrameName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_NumericStepper_setrSelectedSpriteFrameName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_NumericStepper_setlDisabledSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::NumericStepper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::NumericStepper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::NumericStepper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_NumericStepper_setlDisabledSpriteFrameName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setlDisabledSpriteFrameName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setlDisabledSpriteFrameName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_NumericStepper_setlDisabledSpriteFrameName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_NumericStepper_setlNormalSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::NumericStepper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::NumericStepper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::NumericStepper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_NumericStepper_setlNormalSpriteFrameName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setlNormalSpriteFrameName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setlNormalSpriteFrameName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_NumericStepper_setlNormalSpriteFrameName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_NumericStepper_setrDisabledSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::NumericStepper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::NumericStepper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::NumericStepper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_NumericStepper_setrDisabledSpriteFrameName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setrDisabledSpriteFrameName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setrDisabledSpriteFrameName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_NumericStepper_setrDisabledSpriteFrameName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_NumericStepper_onTouchBegan(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::NumericStepper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::NumericStepper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::NumericStepper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_NumericStepper_onTouchBegan'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Touch* arg0;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);
        if(!ok)
            return 0;
        int ret = (int)cobj->onTouchBegan(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchBegan",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_NumericStepper_onTouchBegan'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_NumericStepper_setStepBgSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::NumericStepper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::NumericStepper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::NumericStepper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_NumericStepper_setStepBgSpriteFrameName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setStepBgSpriteFrameName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setStepBgSpriteFrameName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_NumericStepper_setStepBgSpriteFrameName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_NumericStepper_setStep(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::NumericStepper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::NumericStepper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::NumericStepper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_NumericStepper_setStep'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setStep(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setStep",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_NumericStepper_setStep'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_NumericStepper_init(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::NumericStepper* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::NumericStepper",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::cocoswidget::NumericStepper*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_NumericStepper_init'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 7) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

            if (!ok) { break; }
            const char* arg2;
            std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();

            if (!ok) { break; }
            const char* arg3;
            std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp); arg3 = arg3_tmp.c_str();

            if (!ok) { break; }
            const char* arg4;
            std::string arg4_tmp; ok &= luaval_to_std_string(tolua_S, 6, &arg4_tmp); arg4 = arg4_tmp.c_str();

            if (!ok) { break; }
            const char* arg5;
            std::string arg5_tmp; ok &= luaval_to_std_string(tolua_S, 7, &arg5_tmp); arg5 = arg5_tmp.c_str();

            if (!ok) { break; }
            const char* arg6;
            std::string arg6_tmp; ok &= luaval_to_std_string(tolua_S, 8, &arg6_tmp); arg6 = arg6_tmp.c_str();

            if (!ok) { break; }
            bool ret = cobj->init(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            bool ret = cobj->init();
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_NumericStepper_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_NumericStepper_setlSelectedSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::NumericStepper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::NumericStepper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::NumericStepper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_NumericStepper_setlSelectedSpriteFrameName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setlSelectedSpriteFrameName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setlSelectedSpriteFrameName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_NumericStepper_setlSelectedSpriteFrameName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_NumericStepper_onTouchCancelled(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::NumericStepper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::NumericStepper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::NumericStepper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_NumericStepper_onTouchCancelled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchCancelled(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchCancelled",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_NumericStepper_onTouchCancelled'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_NumericStepper_getValue(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::NumericStepper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::NumericStepper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::NumericStepper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_NumericStepper_getValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getValue();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getValue",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_NumericStepper_getValue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_NumericStepper_setrNormalSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::NumericStepper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::NumericStepper",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::NumericStepper*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_NumericStepper_setrNormalSpriteFrameName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setrNormalSpriteFrameName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setrNormalSpriteFrameName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_NumericStepper_setrNormalSpriteFrameName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_NumericStepper_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::NumericStepper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 7)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
            if (!ok) { break; }
            const char* arg2;
            std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();
            if (!ok) { break; }
            const char* arg3;
            std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp); arg3 = arg3_tmp.c_str();
            if (!ok) { break; }
            const char* arg4;
            std::string arg4_tmp; ok &= luaval_to_std_string(tolua_S, 6, &arg4_tmp); arg4 = arg4_tmp.c_str();
            if (!ok) { break; }
            const char* arg5;
            std::string arg5_tmp; ok &= luaval_to_std_string(tolua_S, 7, &arg5_tmp); arg5 = arg5_tmp.c_str();
            if (!ok) { break; }
            const char* arg6;
            std::string arg6_tmp; ok &= luaval_to_std_string(tolua_S, 8, &arg6_tmp); arg6 = arg6_tmp.c_str();
            if (!ok) { break; }
            cocos2d::cocoswidget::NumericStepper* ret = cocos2d::cocoswidget::NumericStepper::create(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
            object_to_luaval<cocos2d::cocoswidget::NumericStepper>(tolua_S, "cc.cocoswidget::NumericStepper",(cocos2d::cocoswidget::NumericStepper*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            cocos2d::cocoswidget::NumericStepper* ret = cocos2d::cocoswidget::NumericStepper::create();
            object_to_luaval<cocos2d::cocoswidget::NumericStepper>(tolua_S, "cc.cocoswidget::NumericStepper",(cocos2d::cocoswidget::NumericStepper*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_NumericStepper_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_NumericStepper_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::NumericStepper* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::NumericStepper();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::NumericStepper");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "NumericStepper",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_NumericStepper_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_NumericStepper_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (NumericStepper)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_NumericStepper(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::NumericStepper");
    tolua_cclass(tolua_S,"NumericStepper","cc.cocoswidget::NumericStepper","cc.cocoswidget::CLayout",nullptr);

    tolua_beginmodule(tolua_S,"NumericStepper");
        tolua_function(tolua_S,"onTouchMoved",lua_cocos2dx_cocoswidget_NumericStepper_onTouchMoved);
        tolua_function(tolua_S,"setValue",lua_cocos2dx_cocoswidget_NumericStepper_setValue);
        tolua_function(tolua_S,"onTouchEnded",lua_cocos2dx_cocoswidget_NumericStepper_onTouchEnded);
        tolua_function(tolua_S,"getStep",lua_cocos2dx_cocoswidget_NumericStepper_getStep);
        tolua_function(tolua_S,"setrSelectedSpriteFrameName",lua_cocos2dx_cocoswidget_NumericStepper_setrSelectedSpriteFrameName);
        tolua_function(tolua_S,"setlDisabledSpriteFrameName",lua_cocos2dx_cocoswidget_NumericStepper_setlDisabledSpriteFrameName);
        tolua_function(tolua_S,"setlNormalSpriteFrameName",lua_cocos2dx_cocoswidget_NumericStepper_setlNormalSpriteFrameName);
        tolua_function(tolua_S,"setrDisabledSpriteFrameName",lua_cocos2dx_cocoswidget_NumericStepper_setrDisabledSpriteFrameName);
        tolua_function(tolua_S,"onTouchBegan",lua_cocos2dx_cocoswidget_NumericStepper_onTouchBegan);
        tolua_function(tolua_S,"setStepBgSpriteFrameName",lua_cocos2dx_cocoswidget_NumericStepper_setStepBgSpriteFrameName);
        tolua_function(tolua_S,"setStep",lua_cocos2dx_cocoswidget_NumericStepper_setStep);
        tolua_function(tolua_S,"init",lua_cocos2dx_cocoswidget_NumericStepper_init);
        tolua_function(tolua_S,"setlSelectedSpriteFrameName",lua_cocos2dx_cocoswidget_NumericStepper_setlSelectedSpriteFrameName);
        tolua_function(tolua_S,"onTouchCancelled",lua_cocos2dx_cocoswidget_NumericStepper_onTouchCancelled);
        tolua_function(tolua_S,"getValue",lua_cocos2dx_cocoswidget_NumericStepper_getValue);
        tolua_function(tolua_S,"setrNormalSpriteFrameName",lua_cocos2dx_cocoswidget_NumericStepper_setrNormalSpriteFrameName);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_NumericStepper_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_NumericStepper_create);
		tolua_function(tolua_S, "setOnValueChangedScriptHandler", lua_cocos2dx_cocoswidget_NumericStepper_setOnValueChangedScriptHandler);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::NumericStepper).name();
    g_luaType[typeName] = "cc.cocoswidget::NumericStepper";
    g_typeCast["NumericStepper"] = "cc.cocoswidget::NumericStepper";
    return 1;
}

int lua_cocos2dx_cocoswidget_MovieView_play(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::MovieView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::MovieView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::MovieView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_MovieView_play'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->play();
        return 0;
    }
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->play(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "play",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_MovieView_play'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_MovieView_getSprites(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::MovieView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::MovieView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::MovieView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_MovieView_getSprites'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Vector<cocos2d::Sprite *> ret = cobj->getSprites();
        ccvector_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getSprites",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_MovieView_getSprites'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_MovieView_getFrameRate(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::MovieView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::MovieView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::MovieView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_MovieView_getFrameRate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getFrameRate();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getFrameRate",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_MovieView_getFrameRate'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_MovieView_getIsFlip(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::MovieView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::MovieView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::MovieView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_MovieView_getIsFlip'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->getIsFlip();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getIsFlip",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_MovieView_getIsFlip'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_MovieView_getIsLoop(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::MovieView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::MovieView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::MovieView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_MovieView_getIsLoop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->getIsLoop();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getIsLoop",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_MovieView_getIsLoop'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_MovieView_stop(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::MovieView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::MovieView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::MovieView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_MovieView_stop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->stop();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "stop",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_MovieView_stop'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_MovieView_init(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::MovieView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::MovieView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::MovieView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_MovieView_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        bool ret = cobj->init(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_MovieView_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_MovieView_rePlay(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::MovieView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::MovieView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::MovieView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_MovieView_rePlay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->rePlay();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "rePlay",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_MovieView_rePlay'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_MovieView_getMaxFrame(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::MovieView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::MovieView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::MovieView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_MovieView_getMaxFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getMaxFrame();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getMaxFrame",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_MovieView_getMaxFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_MovieView_getCurrFrame(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::MovieView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::MovieView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::MovieView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_MovieView_getCurrFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getCurrFrame();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCurrFrame",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_MovieView_getCurrFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_MovieView_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::MovieView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::MovieView* ret = cocos2d::cocoswidget::MovieView::create(arg0);
        object_to_luaval<cocos2d::cocoswidget::MovieView>(tolua_S, "cc.cocoswidget::MovieView",(cocos2d::cocoswidget::MovieView*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_MovieView_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_MovieView_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::MovieView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::MovieView();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::MovieView");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "MovieView",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_MovieView_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_MovieView_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (MovieView)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_MovieView(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::MovieView");
    tolua_cclass(tolua_S,"MovieView","cc.cocoswidget::MovieView","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"MovieView");
        tolua_function(tolua_S,"play",lua_cocos2dx_cocoswidget_MovieView_play);
        tolua_function(tolua_S,"getSprites",lua_cocos2dx_cocoswidget_MovieView_getSprites);
        tolua_function(tolua_S,"getFrameRate",lua_cocos2dx_cocoswidget_MovieView_getFrameRate);
        tolua_function(tolua_S,"getIsFlip",lua_cocos2dx_cocoswidget_MovieView_getIsFlip);
        tolua_function(tolua_S,"getIsLoop",lua_cocos2dx_cocoswidget_MovieView_getIsLoop);
        tolua_function(tolua_S,"stop",lua_cocos2dx_cocoswidget_MovieView_stop);
        tolua_function(tolua_S,"init",lua_cocos2dx_cocoswidget_MovieView_init);
        tolua_function(tolua_S,"rePlay",lua_cocos2dx_cocoswidget_MovieView_rePlay);
        tolua_function(tolua_S,"getMaxFrame",lua_cocos2dx_cocoswidget_MovieView_getMaxFrame);
        tolua_function(tolua_S,"getCurrFrame",lua_cocos2dx_cocoswidget_MovieView_getCurrFrame);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_MovieView_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_MovieView_create);
		tolua_function(tolua_S, "setOnCallBackScriptHandle", lua_cocos2dx_cocoswidget_MovieView_setOnCallBackScriptHandle);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::MovieView).name();
    g_luaType[typeName] = "cc.cocoswidget::MovieView";
    g_typeCast["MovieView"] = "cc.cocoswidget::MovieView";
    return 1;
}

int lua_cocos2dx_cocoswidget_CircleMenu_onTouchMoved(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CircleMenu* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CircleMenu",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CircleMenu*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CircleMenu_onTouchMoved'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchMoved(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchMoved",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CircleMenu_onTouchMoved'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CircleMenu_onTouchEnded(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CircleMenu* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CircleMenu",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CircleMenu*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CircleMenu_onTouchEnded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Touch* arg0;
        double arg1;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->onTouchEnded(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchEnded",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CircleMenu_onTouchEnded'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CircleMenu_getItemScaleA(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CircleMenu* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CircleMenu",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CircleMenu*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CircleMenu_getItemScaleA'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getItemScaleA();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getItemScaleA",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CircleMenu_getItemScaleA'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CircleMenu_update(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CircleMenu* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CircleMenu",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CircleMenu*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CircleMenu_update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->update(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CircleMenu_update'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CircleMenu_onTouchBegan(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CircleMenu* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CircleMenu",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CircleMenu*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CircleMenu_onTouchBegan'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Touch* arg0;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0);
        if(!ok)
            return 0;
        int ret = (int)cobj->onTouchBegan(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTouchBegan",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CircleMenu_onTouchBegan'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CircleMenu_setItemScaleB(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CircleMenu* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CircleMenu",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CircleMenu*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CircleMenu_setItemScaleB'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setItemScaleB(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setItemScaleB",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CircleMenu_setItemScaleB'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CircleMenu_init(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CircleMenu* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CircleMenu",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::cocoswidget::CircleMenu*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CircleMenu_init'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            cocos2d::Size arg0;
            ok &= luaval_to_size(tolua_S, 2, &arg0);

            if (!ok) { break; }
            bool ret = cobj->init(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            cocos2d::Vector<cocos2d::Node *> arg0;
            ok &= luaval_to_ccvector(tolua_S, 2, &arg0);

            if (!ok) { break; }
            cocos2d::Size arg1;
            ok &= luaval_to_size(tolua_S, 3, &arg1);

            if (!ok) { break; }
            bool ret = cobj->init(arg0, arg1);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CircleMenu_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CircleMenu_setItemScaleA(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CircleMenu* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CircleMenu",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CircleMenu*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CircleMenu_setItemScaleA'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setItemScaleA(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setItemScaleA",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CircleMenu_setItemScaleA'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CircleMenu_getItemScaleB(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CircleMenu* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CircleMenu",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CircleMenu*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CircleMenu_getItemScaleB'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getItemScaleB();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getItemScaleB",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CircleMenu_getItemScaleB'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CircleMenu_getNoFocusOpacity(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CircleMenu* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CircleMenu",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CircleMenu*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CircleMenu_getNoFocusOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getNoFocusOpacity();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getNoFocusOpacity",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CircleMenu_getNoFocusOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CircleMenu_reloadData(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CircleMenu* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CircleMenu",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CircleMenu*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CircleMenu_reloadData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->reloadData();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "reloadData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CircleMenu_reloadData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CircleMenu_setNoFocusOpacity(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CircleMenu* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.cocoswidget::CircleMenu",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::cocoswidget::CircleMenu*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocoswidget_CircleMenu_setNoFocusOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setNoFocusOpacity(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setNoFocusOpacity",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CircleMenu_setNoFocusOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocoswidget_CircleMenu_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.cocoswidget::CircleMenu",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            cocos2d::Size arg0;
            ok &= luaval_to_size(tolua_S, 2, &arg0);
            if (!ok) { break; }
            cocos2d::cocoswidget::CircleMenu* ret = cocos2d::cocoswidget::CircleMenu::create(arg0);
            object_to_luaval<cocos2d::cocoswidget::CircleMenu>(tolua_S, "cc.cocoswidget::CircleMenu",(cocos2d::cocoswidget::CircleMenu*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            cocos2d::Vector<cocos2d::Node *> arg0;
            ok &= luaval_to_ccvector(tolua_S, 2, &arg0);
            if (!ok) { break; }
            cocos2d::Size arg1;
            ok &= luaval_to_size(tolua_S, 3, &arg1);
            if (!ok) { break; }
            cocos2d::cocoswidget::CircleMenu* ret = cocos2d::cocoswidget::CircleMenu::create(arg0, arg1);
            object_to_luaval<cocos2d::cocoswidget::CircleMenu>(tolua_S, "cc.cocoswidget::CircleMenu",(cocos2d::cocoswidget::CircleMenu*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CircleMenu_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocoswidget_CircleMenu_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::cocoswidget::CircleMenu* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::cocoswidget::CircleMenu();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.cocoswidget::CircleMenu");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CircleMenu",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocoswidget_CircleMenu_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocoswidget_CircleMenu_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CircleMenu)");
    return 0;
}

int lua_register_cocos2dx_cocoswidget_CircleMenu(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.cocoswidget::CircleMenu");
    tolua_cclass(tolua_S,"CircleMenu","cc.cocoswidget::CircleMenu","cc.cocoswidget::CLayout",nullptr);

    tolua_beginmodule(tolua_S,"CircleMenu");
        tolua_function(tolua_S,"onTouchMoved",lua_cocos2dx_cocoswidget_CircleMenu_onTouchMoved);
        tolua_function(tolua_S,"onTouchEnded",lua_cocos2dx_cocoswidget_CircleMenu_onTouchEnded);
        tolua_function(tolua_S,"getItemScaleA",lua_cocos2dx_cocoswidget_CircleMenu_getItemScaleA);
        tolua_function(tolua_S,"update",lua_cocos2dx_cocoswidget_CircleMenu_update);
        tolua_function(tolua_S,"onTouchBegan",lua_cocos2dx_cocoswidget_CircleMenu_onTouchBegan);
        tolua_function(tolua_S,"setItemScaleB",lua_cocos2dx_cocoswidget_CircleMenu_setItemScaleB);
        tolua_function(tolua_S,"init",lua_cocos2dx_cocoswidget_CircleMenu_init);
        tolua_function(tolua_S,"setItemScaleA",lua_cocos2dx_cocoswidget_CircleMenu_setItemScaleA);
        tolua_function(tolua_S,"getItemScaleB",lua_cocos2dx_cocoswidget_CircleMenu_getItemScaleB);
        tolua_function(tolua_S,"getNoFocusOpacity",lua_cocos2dx_cocoswidget_CircleMenu_getNoFocusOpacity);
        tolua_function(tolua_S,"reloadData",lua_cocos2dx_cocoswidget_CircleMenu_reloadData);
        tolua_function(tolua_S,"setNoFocusOpacity",lua_cocos2dx_cocoswidget_CircleMenu_setNoFocusOpacity);
        tolua_function(tolua_S,"new",lua_cocos2dx_cocoswidget_CircleMenu_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocoswidget_CircleMenu_create);
		tolua_function(tolua_S, "setOnClickScriptHandler", lua_cocos2dx_cocoswidget_CircleMenu_setOnClickScriptHandler);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::cocoswidget::CircleMenu).name();
    g_luaType[typeName] = "cc.cocoswidget::CircleMenu";
    g_typeCast["CircleMenu"] = "cc.cocoswidget::CircleMenu";
    return 1;
}
TOLUA_API int register_all_cocos2dx_cocoswidget(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,nullptr,0);
	tolua_beginmodule(tolua_S,nullptr);

	lua_register_cocos2dx_cocoswidget_CWidgetTouchProtocol(tolua_S);
	lua_register_cocos2dx_cocoswidget_CWidget(tolua_S);
	lua_register_cocos2dx_cocoswidget_CClickableProtocol(tolua_S);
	lua_register_cocos2dx_cocoswidget_ArmatureBtn(tolua_S);
	lua_register_cocos2dx_cocoswidget_CLayoutableProtocol(tolua_S);
	lua_register_cocos2dx_cocoswidget_CLayout(tolua_S);
	lua_register_cocos2dx_cocoswidget_CTableViewCell(tolua_S);
	lua_register_cocos2dx_cocoswidget_CGridPageViewPage(tolua_S);
	lua_register_cocos2dx_cocoswidget_CScale9Sprite(tolua_S);
	lua_register_cocos2dx_cocoswidget_CLongClickableProtocol(tolua_S);
	lua_register_cocos2dx_cocoswidget_CImageViewScale9(tolua_S);
	lua_register_cocos2dx_cocoswidget_CScrollableProtocol(tolua_S);
	lua_register_cocos2dx_cocoswidget_CScrollView(tolua_S);
	lua_register_cocos2dx_cocoswidget_CColorView(tolua_S);
	lua_register_cocos2dx_cocoswidget_CDataSourceAdapterProtocol(tolua_S);
	lua_register_cocos2dx_cocoswidget_CTableView(tolua_S);
	lua_register_cocos2dx_cocoswidget_CPageChangeableProtocol(tolua_S);
	lua_register_cocos2dx_cocoswidget_CGridPageView(tolua_S);
	lua_register_cocos2dx_cocoswidget_CTextRichClickableProtocol(tolua_S);
	lua_register_cocos2dx_cocoswidget_CTextRich(tolua_S);
	lua_register_cocos2dx_cocoswidget_CircleMenu(tolua_S);
	lua_register_cocos2dx_cocoswidget_CListView(tolua_S);
	lua_register_cocos2dx_cocoswidget_CLabelAtlas(tolua_S);
	lua_register_cocos2dx_cocoswidget_CPageViewCell(tolua_S);
	lua_register_cocos2dx_cocoswidget_CWidgetWindow(tolua_S);
	lua_register_cocos2dx_cocoswidget_CButton(tolua_S);
	lua_register_cocos2dx_cocoswidget_CGradientView(tolua_S);
	lua_register_cocos2dx_cocoswidget_CControlableProtocol(tolua_S);
	lua_register_cocos2dx_cocoswidget_CImageView(tolua_S);
	lua_register_cocos2dx_cocoswidget_CGridPageViewCell(tolua_S);
	lua_register_cocos2dx_cocoswidget_CExpandableListView(tolua_S);
	lua_register_cocos2dx_cocoswidget_CProgressEndedProtocol(tolua_S);
	lua_register_cocos2dx_cocoswidget_MovieView(tolua_S);
	lua_register_cocos2dx_cocoswidget_CCheckableProtocol(tolua_S);
	lua_register_cocos2dx_cocoswidget_CToggleView(tolua_S);
	lua_register_cocos2dx_cocoswidget_CPageView(tolua_S);
	lua_register_cocos2dx_cocoswidget_CGridViewCell(tolua_S);
	lua_register_cocos2dx_cocoswidget_CExpandableNode(tolua_S);
	lua_register_cocos2dx_cocoswidget_CValueChangeableProtocol(tolua_S);
	lua_register_cocos2dx_cocoswidget_CControlView(tolua_S);
	lua_register_cocos2dx_cocoswidget_CLabel(tolua_S);
	lua_register_cocos2dx_cocoswidget_CProgressBar(tolua_S);
	lua_register_cocos2dx_cocoswidget_CSlider(tolua_S);
	lua_register_cocos2dx_cocoswidget_CCheckBox(tolua_S);
	lua_register_cocos2dx_cocoswidget_NumericStepper(tolua_S);
	lua_register_cocos2dx_cocoswidget_CScrollViewContainer(tolua_S);
	lua_register_cocos2dx_cocoswidget_CGridView(tolua_S);
	lua_register_cocos2dx_cocoswidget_CLabelBMFont(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

