#include "lua_cocos2dx_tui_auto.hpp"
#include "TuiManager.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"

#define LUA_COCOS2DX_TUI_SCRIPT_HANDLER( __WIDGET__, __SET_HANDLER__)         \
	int lua_cocos2dx_tui_##__WIDGET__##_##__SET_HANDLER__(lua_State* tolua_S)       \
{    \
	int argc = 0;      \
	cocos2d::tui::__WIDGET__* cobj = nullptr;	     \
	cobj = (cocos2d::tui::__WIDGET__*)tolua_tousertype(tolua_S, 1, 0);     \
	argc = lua_gettop(tolua_S) - 1;     \
if (1 == argc)      \
{     \
	LUA_FUNCTION nHandler = toluafix_ref_function(tolua_S, 2, 0);     \
	cobj->__SET_HANDLER__(nHandler);     \
}     \
	return 0;     \
}

LUA_COCOS2DX_TUI_SCRIPT_HANDLER(TuiBase, setOnMessageScriptHandler)

int lua_cocos2dx_tui_TuiUtil_createAnimWithName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"tui.TuiUtil",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        const char* arg0;
        double arg1;
        unsigned int arg2;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_number(tolua_S, 3,&arg1);
        ok &= luaval_to_uint32(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cocos2d::Animation* ret = cocos2d::tui::TuiUtil::createAnimWithName(arg0, arg1, arg2);
        object_to_luaval<cocos2d::Animation>(tolua_S, "cc.Animation",(cocos2d::Animation*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createAnimWithName",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiUtil_createAnimWithName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tui_TuiUtil_createAnimWithNameAndNum(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"tui.TuiUtil",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 4)
    {
        const char* arg0;
        int arg1;
        double arg2;
        unsigned int arg3;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        ok &= luaval_to_number(tolua_S, 4,&arg2);
        ok &= luaval_to_uint32(tolua_S, 5,&arg3);
        if(!ok)
            return 0;
        cocos2d::Animation* ret = cocos2d::tui::TuiUtil::createAnimWithNameAndNum(arg0, arg1, arg2, arg3);
        object_to_luaval<cocos2d::Animation>(tolua_S, "cc.Animation",(cocos2d::Animation*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createAnimWithNameAndNum",argc, 4);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiUtil_createAnimWithNameAndNum'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tui_TuiUtil_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (TuiUtil)");
    return 0;
}

int lua_register_cocos2dx_tui_TuiUtil(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tui.TuiUtil");
    tolua_cclass(tolua_S,"TuiUtil","tui.TuiUtil","",nullptr);

    tolua_beginmodule(tolua_S,"TuiUtil");
        tolua_function(tolua_S,"createAnimWithName", lua_cocos2dx_tui_TuiUtil_createAnimWithName);
        tolua_function(tolua_S,"createAnimWithNameAndNum", lua_cocos2dx_tui_TuiUtil_createAnimWithNameAndNum);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::tui::TuiUtil).name();
    g_luaType[typeName] = "tui.TuiUtil";
    g_typeCast["TuiUtil"] = "tui.TuiUtil";
    return 1;
}

int lua_cocos2dx_tui_TuiBase_getControlByTag(lua_State* tolua_S)
{
	int argc = 0;
	cocos2d::tui::TuiBase* cobj = nullptr;
	bool ok  = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S,1,"tui.TuiBase",0,&tolua_err)) goto tolua_lerror;
#endif

	cobj = (cocos2d::tui::TuiBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
	if (!cobj) 
	{
		tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiBase_getControlByTag'", nullptr);
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
		cocos2d::Ref* ret = cobj->getControlByTag(arg0);
		object_to_luaval<cocos2d::Ref>(tolua_S, "cc.Ref",(cocos2d::Ref*)ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "lua_cocos2dx_tui_TuiBase_getControlByTag",argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiBase_getControlByTag'.",&tolua_err);
#endif

	return 0;
}

int lua_cocos2dx_tui_TuiBase_getAutoRemoveUnusedSpriteFrame(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::tui::TuiBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tui.TuiBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::tui::TuiBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiBase_getAutoRemoveUnusedSpriteFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->getAutoRemoveUnusedSpriteFrame();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAutoRemoveUnusedSpriteFrame",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiBase_getAutoRemoveUnusedSpriteFrame'.",&tolua_err);
#endif

    return 0;
}

int lua_cocos2dx_tui_TuiBase_setAutoRemoveUnusedSpriteFrame(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::tui::TuiBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tui.TuiBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::tui::TuiBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiBase_setAutoRemoveUnusedSpriteFrame'", nullptr);
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
        cobj->setAutoRemoveUnusedSpriteFrame(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAutoRemoveUnusedSpriteFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiBase_setAutoRemoveUnusedSpriteFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tui_TuiBase_init(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::tui::TuiBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tui.TuiBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::tui::TuiBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiBase_init'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiBase_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tui_TuiBase_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"tui.TuiBase",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocos2d::tui::TuiBase* ret = cocos2d::tui::TuiBase::create();
        object_to_luaval<cocos2d::tui::TuiBase>(tolua_S, "tui.TuiBase",(cocos2d::tui::TuiBase*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiBase_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tui_TuiBase_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::tui::TuiBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::tui::TuiBase();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"tui.TuiBase");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "TuiBase",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiBase_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_tui_TuiBase_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (TuiBase)");
    return 0;
}

int lua_register_cocos2dx_tui_TuiBase(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tui.TuiBase");
    tolua_cclass(tolua_S,"TuiBase","tui.TuiBase","cc.CSceneExtension",nullptr);

    tolua_beginmodule(tolua_S,"TuiBase");
        tolua_function(tolua_S,"getAutoRemoveUnusedSpriteFrame",lua_cocos2dx_tui_TuiBase_getAutoRemoveUnusedSpriteFrame);
        tolua_function(tolua_S,"setAutoRemoveUnusedSpriteFrame",lua_cocos2dx_tui_TuiBase_setAutoRemoveUnusedSpriteFrame);
		tolua_function(tolua_S, "setOnMessageScriptHandler", lua_cocos2dx_tui_TuiBase_setOnMessageScriptHandler);
		tolua_function(tolua_S,"init",lua_cocos2dx_tui_TuiBase_init);
        tolua_function(tolua_S,"new",lua_cocos2dx_tui_TuiBase_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_tui_TuiBase_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::tui::TuiBase).name();
    g_luaType[typeName] = "tui.TuiBase";
    g_typeCast["TuiBase"] = "tui.TuiBase";
    return 1;
}

int lua_cocos2dx_tui_TuiManager_createCheckBox(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::tui::TuiManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tui.TuiManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::tui::TuiManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_createCheckBox'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 10) 
    {
        double arg0;
        const char* arg1;
        const char* arg2;
        const char* arg3;
        const char* arg4;
        const char* arg5;
        const char* arg6;
        double arg7;
        double arg8;
        double arg9;
		double arg10;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();

        std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp); arg3 = arg3_tmp.c_str();

        std::string arg4_tmp; ok &= luaval_to_std_string(tolua_S, 6, &arg4_tmp); arg4 = arg4_tmp.c_str();

        std::string arg5_tmp; ok &= luaval_to_std_string(tolua_S, 7, &arg5_tmp); arg5 = arg5_tmp.c_str();

        std::string arg6_tmp; ok &= luaval_to_std_string(tolua_S, 8, &arg6_tmp); arg6 = arg6_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 9,&arg7);

        ok &= luaval_to_number(tolua_S, 10,&arg8);

        ok &= luaval_to_number(tolua_S, 11,&arg9);

		ok &= luaval_to_number(tolua_S, 12, &arg10);
        if(!ok)
            return 0;
		cocos2d::cocoswidget::CCheckBox* ret = cobj->createCheckBox(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
        object_to_luaval<cocos2d::cocoswidget::CCheckBox>(tolua_S, "ccw.CCheckBox",(cocos2d::cocoswidget::CCheckBox*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createCheckBox",argc, 10);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_createCheckBox'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tui_TuiManager_createParticle(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::tui::TuiManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tui.TuiManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::tui::TuiManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_createParticle'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        double arg0;
        const char* arg1;
        double arg2;
        double arg3;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_number(tolua_S, 5,&arg3);
        if(!ok)
            return 0;
        cocos2d::ParticleSystemQuad* ret = cobj->createParticle(arg0, arg1, arg2, arg3);
        object_to_luaval<cocos2d::ParticleSystemQuad>(tolua_S, "cc.ParticleSystemQuad",(cocos2d::ParticleSystemQuad*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createParticle",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_createParticle'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tui_TuiManager_createPanel(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::tui::TuiManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tui.TuiManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::tui::TuiManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_createPanel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 6) 
    {
        double arg0;
        double arg1;
        double arg2;
        int arg3;
        int arg4;
        double arg5;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3);

        ok &= luaval_to_int32(tolua_S, 6,(int *)&arg4);

        ok &= luaval_to_number(tolua_S, 7,&arg5);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CWidgetWindow* ret = cobj->createPanel(arg0, arg1, arg2, arg3, arg4, arg5);
        object_to_luaval<cocos2d::cocoswidget::CWidgetWindow>(tolua_S, "ccw.CWidgetWindow",(cocos2d::cocoswidget::CWidgetWindow*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createPanel",argc, 6);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_createPanel'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tui_TuiManager_createControl(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::tui::TuiManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tui.TuiManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::tui::TuiManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_createControl'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 6) 
    {
        double arg0;
        const char* arg1;
        const char* arg2;
        double arg3;
        double arg4;
        double arg5;
		double arg6;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 5,&arg3);

        ok &= luaval_to_number(tolua_S, 6,&arg4);

        ok &= luaval_to_number(tolua_S, 7,&arg5);

		ok &= luaval_to_number(tolua_S, 8, &arg6);
        if(!ok)
            return 0;
		cocos2d::cocoswidget::CControlView* ret = cobj->createControl(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        object_to_luaval<cocos2d::cocoswidget::CControlView>(tolua_S, "ccw.CControlView",(cocos2d::cocoswidget::CControlView*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createControl",argc, 6);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_createControl'.",&tolua_err);
#endif

    return 0;
}

int lua_cocos2dx_tui_TuiManager_init(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::tui::TuiManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tui.TuiManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::tui::TuiManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_init'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tui_TuiManager_parseCell(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::tui::TuiManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tui.TuiManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::tui::TuiManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_parseCell'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::cocoswidget::CLayout* arg0;
        const char* arg1;
        const char* arg2;

        ok &= luaval_to_object<cocos2d::cocoswidget::CLayout>(tolua_S, 2, "ccw.CLayout",&arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();
        if(!ok)
            return 0;
        cobj->parseCell(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "parseCell",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_parseCell'.",&tolua_err);
#endif

    return 0;
}

int lua_cocos2dx_tui_TuiManager_createImage(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::tui::TuiManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tui.TuiManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::tui::TuiManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_createImage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 7) 
    {
        double arg0;
        const char* arg1;
        double arg2;
        double arg3;
        double arg4;
        double arg5;
        double arg6;
		double arg7;
		double arg8;
		double arg9;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_number(tolua_S, 5,&arg3);

        ok &= luaval_to_number(tolua_S, 6,&arg4);

        ok &= luaval_to_number(tolua_S, 7,&arg5);

        ok &= luaval_to_number(tolua_S, 8,&arg6);

		ok &= luaval_to_number(tolua_S, 9, &arg7);

		ok &= luaval_to_number(tolua_S, 10, &arg8);

		ok &= luaval_to_number(tolua_S, 11, &arg9);
        if(!ok)
            return 0;
		cocos2d::cocoswidget::CImageView* ret = cobj->createImage(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8,arg9);
        object_to_luaval<cocos2d::cocoswidget::CImageView>(tolua_S, "ccw.CImageView",(cocos2d::cocoswidget::CImageView*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createImage",argc, 7);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_createImage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tui_TuiManager_createLayout(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::tui::TuiManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tui.TuiManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::tui::TuiManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_createLayout'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 6) 
    {
        double arg0;
        double arg1;
        double arg2;
        double arg3;
        double arg4;
        double arg5;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_number(tolua_S, 5,&arg3);

        ok &= luaval_to_number(tolua_S, 6,&arg4);

        ok &= luaval_to_number(tolua_S, 7,&arg5);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CLayout* ret = cobj->createLayout(arg0, arg1, arg2, arg3, arg4, arg5);
        object_to_luaval<cocos2d::cocoswidget::CLayout>(tolua_S, "ccw.CLayout",(cocos2d::cocoswidget::CLayout*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createLayout",argc, 6);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_createLayout'.",&tolua_err);
#endif

    return 0;
}

int lua_cocos2dx_tui_TuiManager_createArmature(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::tui::TuiManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tui.TuiManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::tui::TuiManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_createArmature'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 8) 
    {
        double arg0;
        const char* arg1;
        const char* arg2;
        const char* arg3;
        const char* arg4;
		const char* arg5;
        double arg6;
        double arg7;
		double arg8;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();

        std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp); arg3 = arg3_tmp.c_str();

        std::string arg4_tmp; ok &= luaval_to_std_string(tolua_S, 6, &arg4_tmp); arg4 = arg4_tmp.c_str();

		std::string arg5_tmp; ok &= luaval_to_std_string(tolua_S, 7, &arg5_tmp); arg5 = arg5_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 8,&arg6);

        ok &= luaval_to_number(tolua_S, 9,&arg7);

        ok &= luaval_to_number(tolua_S, 10,&arg8);
        if(!ok)
            return 0;
        cocostudio::Armature* ret = cobj->createArmature(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7,arg8);
        object_to_luaval<cocostudio::Armature>(tolua_S, "ccs.Armature",(cocostudio::Armature*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createArmature",argc, 8);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_createArmature'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tui_TuiManager_createLabel(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::tui::TuiManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tui.TuiManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::tui::TuiManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_createLabel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 19) 
    {
        double arg0;
        const char* arg1;
        const char* arg2;
        int arg3;
        double arg4;
        int arg5;
        int arg6;
        int arg7;
        double arg8;
        double arg9;
        double arg10;
        double arg11;
        int arg12;
        int arg13;
        int arg14;
        double arg15;
        int arg16;
        double arg17;
        double arg18;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3);

        ok &= luaval_to_number(tolua_S, 6,&arg4);

        ok &= luaval_to_int32(tolua_S, 7,(int *)&arg5);

        ok &= luaval_to_int32(tolua_S, 8,(int *)&arg6);

        ok &= luaval_to_int32(tolua_S, 9,(int *)&arg7);

        ok &= luaval_to_number(tolua_S, 10,&arg8);

        ok &= luaval_to_number(tolua_S, 11,&arg9);

        ok &= luaval_to_number(tolua_S, 12,&arg10);

        ok &= luaval_to_number(tolua_S, 13,&arg11);

        ok &= luaval_to_int32(tolua_S, 14,(int *)&arg12);

        ok &= luaval_to_int32(tolua_S, 15,(int *)&arg13);

        ok &= luaval_to_int32(tolua_S, 16,(int *)&arg14);

        ok &= luaval_to_number(tolua_S, 17,&arg15);

        ok &= luaval_to_int32(tolua_S, 18,(int *)&arg16);

        ok &= luaval_to_number(tolua_S, 19,&arg17);

        ok &= luaval_to_number(tolua_S, 20,&arg18);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CLabel* ret = cobj->createLabel(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18);
        object_to_luaval<cocos2d::cocoswidget::CLabel>(tolua_S, "ccw.CLabel",(cocos2d::cocoswidget::CLabel*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createLabel",argc, 19);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_createLabel'.",&tolua_err);
#endif

    return 0;
}

int lua_cocos2dx_tui_TuiManager_createImage9(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::tui::TuiManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tui.TuiManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::tui::TuiManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_createImage9'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 11) 
    {
        double arg0;
        const char* arg1;
        double arg2;
        double arg3;
        double arg4;
        double arg5;
        double arg6;
        double arg7;
        double arg8;
        double arg9;
        double arg10;
		double arg11;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_number(tolua_S, 5,&arg3);

        ok &= luaval_to_number(tolua_S, 6,&arg4);

        ok &= luaval_to_number(tolua_S, 7,&arg5);

        ok &= luaval_to_number(tolua_S, 8,&arg6);

        ok &= luaval_to_number(tolua_S, 9,&arg7);

        ok &= luaval_to_number(tolua_S, 10,&arg8);

        ok &= luaval_to_number(tolua_S, 11,&arg9);

        ok &= luaval_to_number(tolua_S, 12,&arg10);

		ok &= luaval_to_number(tolua_S, 13, &arg11);
        if(!ok)
            return 0;
		cocos2d::cocoswidget::CImageViewScale9* ret = cobj->createImage9(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
        object_to_luaval<cocos2d::cocoswidget::CImageViewScale9>(tolua_S, "ccw.CImageViewScale9",(cocos2d::cocoswidget::CImageViewScale9*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createImage9",argc, 11);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_createImage9'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tui_TuiManager_parseScene(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::tui::TuiManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tui.TuiManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::tui::TuiManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_parseScene'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Node* arg0;
        const char* arg1;
        const char* arg2;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();
		if (!ok)
            return 0;
        cobj->parseScene(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "parseScene",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_parseScene'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tui_TuiManager_createAnim(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::tui::TuiManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tui.TuiManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::tui::TuiManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_createAnim'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 7) 
    {
        double arg0;
        const char* arg1;
        const char* arg2;
        double arg4;
        double arg5;
        double arg6;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

		std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 5,&arg4);

        ok &= luaval_to_number(tolua_S, 6,&arg5);

        ok &= luaval_to_number(tolua_S, 7,&arg6);
        if(!ok)
            return 0;
        cocos2d::Sprite* ret = cobj->createAnim(arg0, arg1, arg2, arg4, arg5, arg6);
        object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createAnim",argc, 7);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_createAnim'.",&tolua_err);
#endif

    return 0;
}

int lua_cocos2dx_tui_TuiManager_createCircleMenu(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::tui::TuiManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"tui.TuiManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::tui::TuiManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_createCircleMenu'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 6) 
    {
        double arg0;
        double arg1;
        double arg2;
        double arg3;
        double arg4;
        double arg5;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_number(tolua_S, 5,&arg3);

        ok &= luaval_to_number(tolua_S, 6,&arg4);

        ok &= luaval_to_number(tolua_S, 7,&arg5);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CircleMenu* ret = cobj->createCircleMenu(arg0, arg1, arg2, arg3, arg4, arg5);
        object_to_luaval<cocos2d::cocoswidget::CircleMenu>(tolua_S, "ccw.CircleMenu",(cocos2d::cocoswidget::CircleMenu*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createCircleMenu",argc, 6);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_createCircleMenu'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tui_TuiManager_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"tui.TuiManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocos2d::tui::TuiManager* ret = cocos2d::tui::TuiManager::getInstance();
        object_to_luaval<cocos2d::tui::TuiManager>(tolua_S, "tui.TuiManager",(cocos2d::tui::TuiManager*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tui_TuiManager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (TuiManager)");
    return 0;
}

int lua_cocos2dx_tui_TuiManager_setAdaptResolution(lua_State* tolua_S)
{
	int argc = 0;
	cocos2d::tui::TuiManager* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "tui.TuiManager", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (cocos2d::tui::TuiManager*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_setAdaptResolution'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 3)
	{
		bool arg0;
		double arg1;
		double arg2;

		ok &= luaval_to_boolean(tolua_S, 2, &arg0);
		ok &= luaval_to_number(tolua_S, 3, &arg1);
		ok &= luaval_to_number(tolua_S, 4, &arg2);

		if (!ok)
			return 0;
		cobj->setAdaptResolution(arg0,arg1,arg2);
		return 0;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAdaptResolution", argc, 3);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_tui_TuiManager_setAdaptResolution'.", &tolua_err);
#endif

	return 0;
}

int lua_cocos2dx_tui_TuiManager_getScaleResolutionX(lua_State* tolua_S)
{
	int argc = 0;
	cocos2d::tui::TuiManager* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "tui.TuiManager", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (cocos2d::tui::TuiManager*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_TuiManager_getScaleResolutionX'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{
		if (!ok)
			return 0;
		double ret = cobj->getScaleResolutionX();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getScaleResolutionX", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_TuiManager_getScaleResolutionX'.", &tolua_err);
#endif

	return 0;
}

int lua_cocos2dx_tui_TuiManager_getScaleResolutionY(lua_State* tolua_S)
{
	int argc = 0;
	cocos2d::tui::TuiManager* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "tui.TuiManager", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (cocos2d::tui::TuiManager*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_TuiManager_getScaleResolutionY'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{
		if (!ok)
			return 0;
		double ret = cobj->getScaleResolutionY();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getScaleResolutionY", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_TuiManager_getScaleResolutionY'.", &tolua_err);
#endif

	return 0;
}

int lua_register_cocos2dx_tui_TuiManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tui.TuiManager");
    tolua_cclass(tolua_S,"TuiManager","tui.TuiManager","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"TuiManager");
        tolua_function(tolua_S,"createCheckBox",lua_cocos2dx_tui_TuiManager_createCheckBox);
        tolua_function(tolua_S,"createParticle",lua_cocos2dx_tui_TuiManager_createParticle);
        tolua_function(tolua_S,"createPanel",lua_cocos2dx_tui_TuiManager_createPanel);
        tolua_function(tolua_S,"createControl",lua_cocos2dx_tui_TuiManager_createControl);
        tolua_function(tolua_S,"init",lua_cocos2dx_tui_TuiManager_init);
        tolua_function(tolua_S,"parseCell",lua_cocos2dx_tui_TuiManager_parseCell);
        tolua_function(tolua_S,"createImage",lua_cocos2dx_tui_TuiManager_createImage);
        tolua_function(tolua_S,"createLayout",lua_cocos2dx_tui_TuiManager_createLayout);
        tolua_function(tolua_S,"createArmature",lua_cocos2dx_tui_TuiManager_createArmature);
        tolua_function(tolua_S,"createLabel",lua_cocos2dx_tui_TuiManager_createLabel);
        tolua_function(tolua_S,"createImage9",lua_cocos2dx_tui_TuiManager_createImage9);
        tolua_function(tolua_S,"parseScene",lua_cocos2dx_tui_TuiManager_parseScene);
        tolua_function(tolua_S,"createAnim",lua_cocos2dx_tui_TuiManager_createAnim);
        tolua_function(tolua_S,"createCircleMenu",lua_cocos2dx_tui_TuiManager_createCircleMenu);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_tui_TuiManager_getInstance);
		tolua_function(tolua_S, "setAdaptResolution", lua_cocos2dx_tui_TuiManager_setAdaptResolution);
		tolua_function(tolua_S, "getScaleResolutionX", lua_cocos2dx_tui_TuiManager_getScaleResolutionX);
		tolua_function(tolua_S, "getScaleResolutionY", lua_cocos2dx_tui_TuiManager_getScaleResolutionY);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::tui::TuiManager).name();
    g_luaType[typeName] = "tui.TuiManager";
    g_typeCast["TuiManager"] = "tui.TuiManager";
    return 1;
}

TOLUA_API int register_all_cocos2dx_tui(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,nullptr,0);
	tolua_beginmodule(tolua_S,nullptr);

	lua_register_cocos2dx_tui_TuiBase(tolua_S);
	lua_register_cocos2dx_tui_TuiManager(tolua_S);
	lua_register_cocos2dx_tui_TuiUtil(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

