#include "lua_cocos2dx_tui_auto.hpp"
#include "TuiManager.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_cocos2dx_tui_AnimationUtil_createAnimWithName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"tui.AnimationUtil",0,&tolua_err)) goto tolua_lerror;
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
        cocos2d::Animation* ret = cocos2d::tui::AnimationUtil::createAnimWithName(arg0, arg1, arg2);
        object_to_luaval<cocos2d::Animation>(tolua_S, "cc.Animation",(cocos2d::Animation*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createAnimWithName",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_AnimationUtil_createAnimWithName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_tui_AnimationUtil_createAnimWithNameAndNum(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"tui.AnimationUtil",0,&tolua_err)) goto tolua_lerror;
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
        cocos2d::Animation* ret = cocos2d::tui::AnimationUtil::createAnimWithNameAndNum(arg0, arg1, arg2, arg3);
        object_to_luaval<cocos2d::Animation>(tolua_S, "cc.Animation",(cocos2d::Animation*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createAnimWithNameAndNum",argc, 4);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_AnimationUtil_createAnimWithNameAndNum'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_tui_AnimationUtil_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (AnimationUtil)");
    return 0;
}

int lua_register_cocos2dx_tui_AnimationUtil(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tui.AnimationUtil");
    tolua_cclass(tolua_S,"AnimationUtil","tui.AnimationUtil","",nullptr);

    tolua_beginmodule(tolua_S,"AnimationUtil");
        tolua_function(tolua_S,"createAnimWithName", lua_cocos2dx_tui_AnimationUtil_createAnimWithName);
        tolua_function(tolua_S,"createAnimWithNameAndNum", lua_cocos2dx_tui_AnimationUtil_createAnimWithNameAndNum);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::tui::AnimationUtil).name();
    g_luaType[typeName] = "tui.AnimationUtil";
    g_typeCast["AnimationUtil"] = "tui.AnimationUtil";
    return 1;
}

int lua_cocos2dx_tui_TuiBase_getControl(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiBase_getControl'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->getControl(arg0, arg1);
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getControl",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiBase_getControl'.",&tolua_err);
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
int lua_cocos2dx_tui_TuiBase_getPanel(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiBase_getPanel'", nullptr);
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
        cocos2d::Node* ret = cobj->getPanel(arg0);
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getPanel",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiBase_getPanel'.",&tolua_err);
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
    tolua_cclass(tolua_S,"TuiBase","tui.TuiBase","cc.Scene",nullptr);

    tolua_beginmodule(tolua_S,"TuiBase");
        tolua_function(tolua_S,"getControl",lua_cocos2dx_tui_TuiBase_getControl);
        tolua_function(tolua_S,"getAutoRemoveUnusedSpriteFrame",lua_cocos2dx_tui_TuiBase_getAutoRemoveUnusedSpriteFrame);
        tolua_function(tolua_S,"getPanel",lua_cocos2dx_tui_TuiBase_getPanel);
        tolua_function(tolua_S,"setAutoRemoveUnusedSpriteFrame",lua_cocos2dx_tui_TuiBase_setAutoRemoveUnusedSpriteFrame);
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
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CCheckBox* ret = cobj->createCheckBox(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
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

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 5,&arg3);

        ok &= luaval_to_number(tolua_S, 6,&arg4);

        ok &= luaval_to_number(tolua_S, 7,&arg5);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CControlView* ret = cobj->createControl(arg0, arg1, arg2, arg3, arg4, arg5);
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
int lua_cocos2dx_tui_TuiManager_createBtn(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_createBtn'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 9) 
    {
        double arg0;
        const char* arg1;
        const char* arg2;
        const char* arg3;
        double arg4;
        double arg5;
        double arg6;
        double arg7;
        double arg8;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();

        std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp); arg3 = arg3_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 6,&arg4);

        ok &= luaval_to_number(tolua_S, 7,&arg5);

        ok &= luaval_to_number(tolua_S, 8,&arg6);

        ok &= luaval_to_number(tolua_S, 9,&arg7);

        ok &= luaval_to_number(tolua_S, 10,&arg8);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CButton* ret = cobj->createBtn(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        object_to_luaval<cocos2d::cocoswidget::CButton>(tolua_S, "ccw.CButton",(cocos2d::cocoswidget::CButton*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createBtn",argc, 9);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_createBtn'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tui_TuiManager_createListView(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_createListView'", nullptr);
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

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_number(tolua_S, 5,&arg3);

        ok &= luaval_to_number(tolua_S, 6,&arg4);

        ok &= luaval_to_number(tolua_S, 7,&arg5);

        ok &= luaval_to_number(tolua_S, 8,&arg6);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CListView* ret = cobj->createListView(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        object_to_luaval<cocos2d::cocoswidget::CListView>(tolua_S, "ccw.CListView",(cocos2d::cocoswidget::CListView*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createListView",argc, 7);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_createListView'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tui_TuiManager_createArmatureBtn(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_createArmatureBtn'", nullptr);
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
        double arg5;
        double arg6;
        double arg7;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();

        std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp); arg3 = arg3_tmp.c_str();

        std::string arg4_tmp; ok &= luaval_to_std_string(tolua_S, 6, &arg4_tmp); arg4 = arg4_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 7,&arg5);

        ok &= luaval_to_number(tolua_S, 8,&arg6);

        ok &= luaval_to_number(tolua_S, 9,&arg7);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::ArmatureBtn* ret = cobj->createArmatureBtn(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
        object_to_luaval<cocos2d::cocoswidget::ArmatureBtn>(tolua_S, "ccw.ArmatureBtn",(cocos2d::cocoswidget::ArmatureBtn*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createArmatureBtn",argc, 8);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_createArmatureBtn'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tui_TuiManager_createScrollView(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_createScrollView'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 7) 
    {
        double arg0;
        int arg1;
		int innerWidth;
		int innerHeight;
        double arg2;
        double arg3;
        double arg4;
        double arg5;
        double arg6;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);

		ok &= luaval_to_int32(tolua_S, 4, (int *)&innerWidth);

		ok &= luaval_to_int32(tolua_S, 5, (int *)&innerHeight);

        ok &= luaval_to_number(tolua_S, 6,&arg2);

        ok &= luaval_to_number(tolua_S, 7,&arg3);

        ok &= luaval_to_number(tolua_S, 8,&arg4);

        ok &= luaval_to_number(tolua_S, 9,&arg5);

        ok &= luaval_to_number(tolua_S, 10,&arg6);
        if(!ok)
            return 0;
		cocos2d::cocoswidget::CScrollView* ret = cobj->createScrollView(arg0, arg1, innerWidth, innerHeight, arg2, arg3, arg4, arg5, arg6);
        object_to_luaval<cocos2d::cocoswidget::CScrollView>(tolua_S, "ccw.CScrollView",(cocos2d::cocoswidget::CScrollView*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createScrollView",argc, 9);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_createScrollView'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tui_TuiManager_createEditBox(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_createEditBox'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 9) 
    {
        double arg0;
        const char* arg1;
        int arg2;
        int arg3;
        double arg4;
        double arg5;
        double arg6;
        double arg7;
        double arg8;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3);

        ok &= luaval_to_number(tolua_S, 6,&arg4);

        ok &= luaval_to_number(tolua_S, 7,&arg5);

        ok &= luaval_to_number(tolua_S, 8,&arg6);

        ok &= luaval_to_number(tolua_S, 9,&arg7);

        ok &= luaval_to_number(tolua_S, 10,&arg8);
        if(!ok)
            return 0;
        cocos2d::extension::EditBox* ret = cobj->createEditBox(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        object_to_luaval<cocos2d::extension::EditBox>(tolua_S, "cc.EditBox",(cocos2d::extension::EditBox*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createEditBox",argc, 9);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_createEditBox'.",&tolua_err);
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
int lua_cocos2dx_tui_TuiManager_createMovieView(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_createMovieView'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 7) 
    {
        double arg0;
        const char* arg1;
        const char* arg2;
        const char* arg3;
        double arg4;
        double arg5;
        double arg6;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();

        std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp); arg3 = arg3_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 6,&arg4);

        ok &= luaval_to_number(tolua_S, 7,&arg5);

        ok &= luaval_to_number(tolua_S, 8,&arg6);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::MovieView* ret = cobj->createMovieView(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        object_to_luaval<cocos2d::cocoswidget::MovieView>(tolua_S, "ccw.MovieView",(cocos2d::cocoswidget::MovieView*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createMovieView",argc, 7);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_createMovieView'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tui_TuiManager_createGridPageView(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_createGridPageView'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 13) 
    {
        double arg0;
        const char* arg1;
        int arg2;
        int arg3;
        int arg4;
        int arg5;
        int arg6;
        int arg7;
        double arg8;
        double arg9;
        double arg10;
        double arg11;
        double arg12;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3);

        ok &= luaval_to_int32(tolua_S, 6,(int *)&arg4);

        ok &= luaval_to_int32(tolua_S, 7,(int *)&arg5);

        ok &= luaval_to_int32(tolua_S, 8,(int *)&arg6);

        ok &= luaval_to_int32(tolua_S, 9,(int *)&arg7);

        ok &= luaval_to_number(tolua_S, 10,&arg8);

        ok &= luaval_to_number(tolua_S, 11,&arg9);

        ok &= luaval_to_number(tolua_S, 12,&arg10);

        ok &= luaval_to_number(tolua_S, 13,&arg11);

        ok &= luaval_to_number(tolua_S, 14,&arg12);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CGridPageView* ret = cobj->createGridPageView(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
        object_to_luaval<cocos2d::cocoswidget::CGridPageView>(tolua_S, "ccw.CGridPageView",(cocos2d::cocoswidget::CGridPageView*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createGridPageView",argc, 13);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_createGridPageView'.",&tolua_err);
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

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_number(tolua_S, 5,&arg3);

        ok &= luaval_to_number(tolua_S, 6,&arg4);

        ok &= luaval_to_number(tolua_S, 7,&arg5);

        ok &= luaval_to_number(tolua_S, 8,&arg6);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CImageView* ret = cobj->createImage(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
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
int lua_cocos2dx_tui_TuiManager_createSlider(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_createSlider'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 7) 
    {
        double arg0;
        const char* arg1;
        const char* arg2;
        const char* arg3;
        double arg4;
        double arg5;
        double arg6;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();

        std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp); arg3 = arg3_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 6,&arg4);

        ok &= luaval_to_number(tolua_S, 7,&arg5);

        ok &= luaval_to_number(tolua_S, 8,&arg6);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CSlider* ret = cobj->createSlider(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        object_to_luaval<cocos2d::cocoswidget::CSlider>(tolua_S, "ccw.CSlider",(cocos2d::cocoswidget::CSlider*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createSlider",argc, 7);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_createSlider'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tui_TuiManager_createToggleView(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_createToggleView'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 8) 
    {
        double arg0;
        int arg1;
        const char* arg2;
        const char* arg3;
        const char* arg4;
        double arg5;
        double arg6;
        double arg7;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();

        std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp); arg3 = arg3_tmp.c_str();

        std::string arg4_tmp; ok &= luaval_to_std_string(tolua_S, 6, &arg4_tmp); arg4 = arg4_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 7,&arg5);

        ok &= luaval_to_number(tolua_S, 8,&arg6);

        ok &= luaval_to_number(tolua_S, 9,&arg7);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CToggleView* ret = cobj->createToggleView(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
        object_to_luaval<cocos2d::cocoswidget::CToggleView>(tolua_S, "ccw.CToggleView",(cocos2d::cocoswidget::CToggleView*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createToggleView",argc, 8);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_createToggleView'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tui_TuiManager_createGridView(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_createGridView'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 11) 
    {
        double arg0;
        const char* arg1;
        int arg2;
        int arg3;
        int arg4;
        int arg5;
        double arg6;
        double arg7;
        double arg8;
        double arg9;
        double arg10;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3);

        ok &= luaval_to_int32(tolua_S, 6,(int *)&arg4);

        ok &= luaval_to_int32(tolua_S, 7,(int *)&arg5);

        ok &= luaval_to_number(tolua_S, 8,&arg6);

        ok &= luaval_to_number(tolua_S, 9,&arg7);

        ok &= luaval_to_number(tolua_S, 10,&arg8);

        ok &= luaval_to_number(tolua_S, 11,&arg9);

        ok &= luaval_to_number(tolua_S, 12,&arg10);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CGridView* ret = cobj->createGridView(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
        object_to_luaval<cocos2d::cocoswidget::CGridView>(tolua_S, "ccw.CGridView",(cocos2d::cocoswidget::CGridView*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createGridView",argc, 11);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_createGridView'.",&tolua_err);
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
        double arg5;
        double arg6;
        double arg7;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();

        std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp); arg3 = arg3_tmp.c_str();

        std::string arg4_tmp; ok &= luaval_to_std_string(tolua_S, 6, &arg4_tmp); arg4 = arg4_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 7,&arg5);

        ok &= luaval_to_number(tolua_S, 8,&arg6);

        ok &= luaval_to_number(tolua_S, 9,&arg7);
        if(!ok)
            return 0;
        cocostudio::Armature* ret = cobj->createArmature(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
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
int lua_cocos2dx_tui_TuiManager_createNumStep(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_createNumStep'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 11) 
    {
        double arg0;
        const char* arg1;
        const char* arg2;
        const char* arg3;
        const char* arg4;
        const char* arg5;
        const char* arg6;
        const char* arg7;
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

        std::string arg7_tmp; ok &= luaval_to_std_string(tolua_S, 9, &arg7_tmp); arg7 = arg7_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 10,&arg8);

        ok &= luaval_to_number(tolua_S, 11,&arg9);

        ok &= luaval_to_number(tolua_S, 12,&arg10);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::NumericStepper* ret = cobj->createNumStep(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
        object_to_luaval<cocos2d::cocoswidget::NumericStepper>(tolua_S, "ccw.NumericStepper",(cocos2d::cocoswidget::NumericStepper*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createNumStep",argc, 11);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_createNumStep'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tui_TuiManager_createPageView(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_createPageView'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 9) 
    {
        double arg0;
        const char* arg1;
        int arg2;
        int arg3;
        double arg4;
        double arg5;
        double arg6;
        double arg7;
        double arg8;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3);

        ok &= luaval_to_number(tolua_S, 6,&arg4);

        ok &= luaval_to_number(tolua_S, 7,&arg5);

        ok &= luaval_to_number(tolua_S, 8,&arg6);

        ok &= luaval_to_number(tolua_S, 9,&arg7);

        ok &= luaval_to_number(tolua_S, 10,&arg8);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CPageView* ret = cobj->createPageView(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        object_to_luaval<cocos2d::cocoswidget::CPageView>(tolua_S, "ccw.CPageView",(cocos2d::cocoswidget::CPageView*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createPageView",argc, 9);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_createPageView'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tui_TuiManager_setUseSpriteFrame(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_setUseSpriteFrame'", nullptr);
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
        cobj->setUseSpriteFrame(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setUseSpriteFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_setUseSpriteFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tui_TuiManager_createTableView(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_createTableView'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 11) 
    {
        double arg0;
        const char* arg1;
        int arg2;
        int arg3;
        int arg4;
        int arg5;
        double arg6;
        double arg7;
        double arg8;
        double arg9;
        double arg10;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3);

        ok &= luaval_to_int32(tolua_S, 6,(int *)&arg4);

        ok &= luaval_to_int32(tolua_S, 7,(int *)&arg5);

        ok &= luaval_to_number(tolua_S, 8,&arg6);

        ok &= luaval_to_number(tolua_S, 9,&arg7);

        ok &= luaval_to_number(tolua_S, 10,&arg8);

        ok &= luaval_to_number(tolua_S, 11,&arg9);

        ok &= luaval_to_number(tolua_S, 12,&arg10);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CTableView* ret = cobj->createTableView(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
        object_to_luaval<cocos2d::cocoswidget::CTableView>(tolua_S, "ccw.CTableView",(cocos2d::cocoswidget::CTableView*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createTableView",argc, 11);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_createTableView'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_tui_TuiManager_createLabelAtlas(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_createLabelAtlas'", nullptr);
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

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_number(tolua_S, 5,&arg3);

        ok &= luaval_to_number(tolua_S, 6,&arg4);

        ok &= luaval_to_number(tolua_S, 7,&arg5);

        ok &= luaval_to_number(tolua_S, 8,&arg6);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CLabelAtlas* ret = cobj->createLabelAtlas(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        object_to_luaval<cocos2d::cocoswidget::CLabelAtlas>(tolua_S, "ccw.CLabelAtlas",(cocos2d::cocoswidget::CLabelAtlas*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createLabelAtlas",argc, 7);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_createLabelAtlas'.",&tolua_err);
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
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CImageViewScale9* ret = cobj->createImage9(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
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
        if(!ok)
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
        const char* arg3;
        double arg4;
        double arg5;
        double arg6;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();

        std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp); arg3 = arg3_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 6,&arg4);

        ok &= luaval_to_number(tolua_S, 7,&arg5);

        ok &= luaval_to_number(tolua_S, 8,&arg6);
        if(!ok)
            return 0;
        cocos2d::Sprite* ret = cobj->createAnim(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
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
int lua_cocos2dx_tui_TuiManager_createProgress(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_tui_TuiManager_createProgress'", nullptr);
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

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 5,&arg3);

        ok &= luaval_to_number(tolua_S, 6,&arg4);

        ok &= luaval_to_number(tolua_S, 7,&arg5);
        if(!ok)
            return 0;
        cocos2d::cocoswidget::CProgressBar* ret = cobj->createProgress(arg0, arg1, arg2, arg3, arg4, arg5);
        object_to_luaval<cocos2d::cocoswidget::CProgressBar>(tolua_S, "ccw.CProgressBar",(cocos2d::cocoswidget::CProgressBar*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createProgress",argc, 6);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_tui_TuiManager_createProgress'.",&tolua_err);
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

int lua_register_cocos2dx_tui_TuiManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"tui.TuiManager");
    tolua_cclass(tolua_S,"TuiManager","tui.TuiManager","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"TuiManager");
        tolua_function(tolua_S,"createCheckBox",lua_cocos2dx_tui_TuiManager_createCheckBox);
        tolua_function(tolua_S,"createParticle",lua_cocos2dx_tui_TuiManager_createParticle);
        tolua_function(tolua_S,"createPanel",lua_cocos2dx_tui_TuiManager_createPanel);
        tolua_function(tolua_S,"createControl",lua_cocos2dx_tui_TuiManager_createControl);
        tolua_function(tolua_S,"createBtn",lua_cocos2dx_tui_TuiManager_createBtn);
        tolua_function(tolua_S,"createListView",lua_cocos2dx_tui_TuiManager_createListView);
        tolua_function(tolua_S,"createArmatureBtn",lua_cocos2dx_tui_TuiManager_createArmatureBtn);
        tolua_function(tolua_S,"createScrollView",lua_cocos2dx_tui_TuiManager_createScrollView);
        tolua_function(tolua_S,"createEditBox",lua_cocos2dx_tui_TuiManager_createEditBox);
        tolua_function(tolua_S,"init",lua_cocos2dx_tui_TuiManager_init);
        tolua_function(tolua_S,"parseCell",lua_cocos2dx_tui_TuiManager_parseCell);
        tolua_function(tolua_S,"createMovieView",lua_cocos2dx_tui_TuiManager_createMovieView);
        tolua_function(tolua_S,"createGridPageView",lua_cocos2dx_tui_TuiManager_createGridPageView);
        tolua_function(tolua_S,"createImage",lua_cocos2dx_tui_TuiManager_createImage);
        tolua_function(tolua_S,"createLayout",lua_cocos2dx_tui_TuiManager_createLayout);
        tolua_function(tolua_S,"createSlider",lua_cocos2dx_tui_TuiManager_createSlider);
        tolua_function(tolua_S,"createToggleView",lua_cocos2dx_tui_TuiManager_createToggleView);
        tolua_function(tolua_S,"createGridView",lua_cocos2dx_tui_TuiManager_createGridView);
        tolua_function(tolua_S,"createArmature",lua_cocos2dx_tui_TuiManager_createArmature);
        tolua_function(tolua_S,"createLabel",lua_cocos2dx_tui_TuiManager_createLabel);
        tolua_function(tolua_S,"createNumStep",lua_cocos2dx_tui_TuiManager_createNumStep);
        tolua_function(tolua_S,"createPageView",lua_cocos2dx_tui_TuiManager_createPageView);
        tolua_function(tolua_S,"setUseSpriteFrame",lua_cocos2dx_tui_TuiManager_setUseSpriteFrame);
        tolua_function(tolua_S,"createTableView",lua_cocos2dx_tui_TuiManager_createTableView);
        tolua_function(tolua_S,"createLabelAtlas",lua_cocos2dx_tui_TuiManager_createLabelAtlas);
        tolua_function(tolua_S,"createImage9",lua_cocos2dx_tui_TuiManager_createImage9);
        tolua_function(tolua_S,"parseScene",lua_cocos2dx_tui_TuiManager_parseScene);
        tolua_function(tolua_S,"createAnim",lua_cocos2dx_tui_TuiManager_createAnim);
        tolua_function(tolua_S,"createProgress",lua_cocos2dx_tui_TuiManager_createProgress);
        tolua_function(tolua_S,"createCircleMenu",lua_cocos2dx_tui_TuiManager_createCircleMenu);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_tui_TuiManager_getInstance);
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
	lua_register_cocos2dx_tui_AnimationUtil(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

