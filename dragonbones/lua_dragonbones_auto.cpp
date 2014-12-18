#include "lua_dragonbones_auto.hpp"
#include "DBCCRenderHeaders.h"
#include "DragonBonesHeaders.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_dragonbones_IAnimatable_advanceTime(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::IAnimatable* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.IAnimatable",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::IAnimatable*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_IAnimatable_advanceTime'", nullptr);
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
        cobj->advanceTime(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "advanceTime",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_IAnimatable_advanceTime'.",&tolua_err);
#endif

    return 0;
}
static int lua_dragonbones_IAnimatable_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (IAnimatable)");
    return 0;
}

int lua_register_dragonbones_IAnimatable(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.IAnimatable");
    tolua_cclass(tolua_S,"IAnimatable","db.IAnimatable","",nullptr);

    tolua_beginmodule(tolua_S,"IAnimatable");
        tolua_function(tolua_S,"advanceTime",lua_dragonbones_IAnimatable_advanceTime);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::IAnimatable).name();
    g_luaType[typeName] = "db.IAnimatable";
    g_typeCast["IAnimatable"] = "db.IAnimatable";
    return 1;
}

int lua_dragonbones_AnimationState_setCurrentTime(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_setCurrentTime'", nullptr);
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
        dragonBones::AnimationState* ret = cobj->setCurrentTime(arg0);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCurrentTime",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_setCurrentTime'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_setTimeScale(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_setTimeScale'", nullptr);
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
        dragonBones::AnimationState* ret = cobj->setTimeScale(arg0);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTimeScale",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_setTimeScale'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_setAdditiveBlending(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_setAdditiveBlending'", nullptr);
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
        dragonBones::AnimationState* ret = cobj->setAdditiveBlending(arg0);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAdditiveBlending",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_setAdditiveBlending'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_getClip(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_getClip'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const dragonBones::AnimationData* ret = cobj->getClip();
        object_to_luaval<dragonBones::AnimationData>(tolua_S, "db.AnimationData",(dragonBones::AnimationData*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getClip",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_getClip'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_setPlayTimes(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_setPlayTimes'", nullptr);
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
        dragonBones::AnimationState* ret = cobj->setPlayTimes(arg0);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setPlayTimes",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_setPlayTimes'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_removeMixingTransform(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_removeMixingTransform'", nullptr);
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
        dragonBones::AnimationState* ret = cobj->removeMixingTransform(arg0);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        bool arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        dragonBones::AnimationState* ret = cobj->removeMixingTransform(arg0, arg1);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeMixingTransform",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_removeMixingTransform'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_getGroup(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_getGroup'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const std::string& ret = cobj->getGroup();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getGroup",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_getGroup'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_getCurrentPlayTimes(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_getCurrentPlayTimes'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getCurrentPlayTimes();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCurrentPlayTimes",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_getCurrentPlayTimes'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_removeAllMixingTransform(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_removeAllMixingTransform'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        dragonBones::AnimationState* ret = cobj->removeAllMixingTransform();
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeAllMixingTransform",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_removeAllMixingTransform'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_addMixingTransform(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_addMixingTransform'", nullptr);
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
        dragonBones::AnimationState* ret = cobj->addMixingTransform(arg0);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        bool arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        dragonBones::AnimationState* ret = cobj->addMixingTransform(arg0, arg1);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addMixingTransform",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_addMixingTransform'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_getCurrentTime(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_getCurrentTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getCurrentTime();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCurrentTime",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_getCurrentTime'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_setAutoFadeOut(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_setAutoFadeOut'", nullptr);
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
        dragonBones::AnimationState* ret = cobj->setAutoFadeOut(arg0);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        bool arg0;
        double arg1;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        dragonBones::AnimationState* ret = cobj->setAutoFadeOut(arg0, arg1);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAutoFadeOut",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_setAutoFadeOut'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_getTotalTime(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_getTotalTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getTotalTime();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getTotalTime",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_getTotalTime'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_getLayer(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_getLayer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getLayer();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getLayer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_getLayer'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_getPlayTimes(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_getPlayTimes'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getPlayTimes();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getPlayTimes",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_getPlayTimes'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_play(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_play'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        dragonBones::AnimationState* ret = cobj->play();
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "play",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_play'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_fadeOut(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_fadeOut'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        bool arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        dragonBones::AnimationState* ret = cobj->fadeOut(arg0, arg1);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "fadeOut",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_fadeOut'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_stop(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_stop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        dragonBones::AnimationState* ret = cobj->stop();
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "stop",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_stop'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_getCurrentWeight(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_getCurrentWeight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getCurrentWeight();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCurrentWeight",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_getCurrentWeight'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_getIsComplete(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_getIsComplete'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->getIsComplete();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getIsComplete",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_getIsComplete'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_getTimeScale(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_getTimeScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getTimeScale();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getTimeScale",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_getTimeScale'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_setFrameTween(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_setFrameTween'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        bool arg0;
        bool arg1;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);

        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        dragonBones::AnimationState* ret = cobj->setFrameTween(arg0, arg1);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setFrameTween",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_setFrameTween'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_setWeight(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_setWeight'", nullptr);
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
        dragonBones::AnimationState* ret = cobj->setWeight(arg0);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setWeight",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_setWeight'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_getMixingTransform(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_getMixingTransform'", nullptr);
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
        bool ret = cobj->getMixingTransform(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getMixingTransform",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_getMixingTransform'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_getIsPlaying(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_getIsPlaying'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->getIsPlaying();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getIsPlaying",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_getIsPlaying'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_constructor(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new dragonBones::AnimationState();
        tolua_pushusertype(tolua_S,(void*)cobj,"db.AnimationState");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "AnimationState",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_dragonbones_AnimationState_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (AnimationState)");
    return 0;
}

int lua_register_dragonbones_AnimationState(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.AnimationState");
    tolua_cclass(tolua_S,"AnimationState","db.AnimationState","",nullptr);

    tolua_beginmodule(tolua_S,"AnimationState");
        tolua_function(tolua_S,"new",lua_dragonbones_AnimationState_constructor);
        tolua_function(tolua_S,"setCurrentTime",lua_dragonbones_AnimationState_setCurrentTime);
        tolua_function(tolua_S,"setTimeScale",lua_dragonbones_AnimationState_setTimeScale);
        tolua_function(tolua_S,"setAdditiveBlending",lua_dragonbones_AnimationState_setAdditiveBlending);
        tolua_function(tolua_S,"getClip",lua_dragonbones_AnimationState_getClip);
        tolua_function(tolua_S,"setPlayTimes",lua_dragonbones_AnimationState_setPlayTimes);
        tolua_function(tolua_S,"removeMixingTransform",lua_dragonbones_AnimationState_removeMixingTransform);
        tolua_function(tolua_S,"getGroup",lua_dragonbones_AnimationState_getGroup);
        tolua_function(tolua_S,"getCurrentPlayTimes",lua_dragonbones_AnimationState_getCurrentPlayTimes);
        tolua_function(tolua_S,"removeAllMixingTransform",lua_dragonbones_AnimationState_removeAllMixingTransform);
        tolua_function(tolua_S,"addMixingTransform",lua_dragonbones_AnimationState_addMixingTransform);
        tolua_function(tolua_S,"getCurrentTime",lua_dragonbones_AnimationState_getCurrentTime);
        tolua_function(tolua_S,"setAutoFadeOut",lua_dragonbones_AnimationState_setAutoFadeOut);
        tolua_function(tolua_S,"getTotalTime",lua_dragonbones_AnimationState_getTotalTime);
        tolua_function(tolua_S,"getLayer",lua_dragonbones_AnimationState_getLayer);
        tolua_function(tolua_S,"getPlayTimes",lua_dragonbones_AnimationState_getPlayTimes);
        tolua_function(tolua_S,"play",lua_dragonbones_AnimationState_play);
        tolua_function(tolua_S,"fadeOut",lua_dragonbones_AnimationState_fadeOut);
        tolua_function(tolua_S,"stop",lua_dragonbones_AnimationState_stop);
        tolua_function(tolua_S,"getCurrentWeight",lua_dragonbones_AnimationState_getCurrentWeight);
        tolua_function(tolua_S,"getIsComplete",lua_dragonbones_AnimationState_getIsComplete);
        tolua_function(tolua_S,"getTimeScale",lua_dragonbones_AnimationState_getTimeScale);
        tolua_function(tolua_S,"setFrameTween",lua_dragonbones_AnimationState_setFrameTween);
        tolua_function(tolua_S,"setWeight",lua_dragonbones_AnimationState_setWeight);
        tolua_function(tolua_S,"getMixingTransform",lua_dragonbones_AnimationState_getMixingTransform);
        tolua_function(tolua_S,"getIsPlaying",lua_dragonbones_AnimationState_getIsPlaying);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::AnimationState).name();
    g_luaType[typeName] = "db.AnimationState";
    g_typeCast["AnimationState"] = "db.AnimationState";
    return 1;
}

int lua_dragonbones_Animation_getAnimationList(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_getAnimationList'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const std::vector<std::string>& ret = cobj->getAnimationList();
        ccvector_std_string_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAnimationList",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_getAnimationList'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_setTimeScale(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_setTimeScale'", nullptr);
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
        cobj->setTimeScale(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTimeScale",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_setTimeScale'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_stop(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_stop'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_stop'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_clear(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_clear'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->clear();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "clear",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_clear'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_dispose(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_dispose'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->dispose();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "dispose",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_dispose'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_play(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_play'", nullptr);
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
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "play",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_play'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_hasAnimation(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_hasAnimation'", nullptr);
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
        bool ret = cobj->hasAnimation(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "hasAnimation",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_hasAnimation'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_getLastAnimationState(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_getLastAnimationState'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        dragonBones::AnimationState* ret = cobj->getLastAnimationState();
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getLastAnimationState",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_getLastAnimationState'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_gotoAndPlay(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_gotoAndPlay'", nullptr);
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
        dragonBones::AnimationState* ret = cobj->gotoAndPlay(arg0);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        double arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        dragonBones::AnimationState* ret = cobj->gotoAndPlay(arg0, arg1);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 3) 
    {
        std::string arg0;
        double arg1;
        double arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        dragonBones::AnimationState* ret = cobj->gotoAndPlay(arg0, arg1, arg2);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 4) 
    {
        std::string arg0;
        double arg1;
        double arg2;
        int arg3;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3);
        if(!ok)
            return 0;
        dragonBones::AnimationState* ret = cobj->gotoAndPlay(arg0, arg1, arg2, arg3);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 5) 
    {
        std::string arg0;
        double arg1;
        double arg2;
        int arg3;
        int arg4;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3);

        ok &= luaval_to_int32(tolua_S, 6,(int *)&arg4);
        if(!ok)
            return 0;
        dragonBones::AnimationState* ret = cobj->gotoAndPlay(arg0, arg1, arg2, arg3, arg4);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 6) 
    {
        std::string arg0;
        double arg1;
        double arg2;
        int arg3;
        int arg4;
        std::string arg5;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3);

        ok &= luaval_to_int32(tolua_S, 6,(int *)&arg4);

        ok &= luaval_to_std_string(tolua_S, 7,&arg5);
        if(!ok)
            return 0;
        dragonBones::AnimationState* ret = cobj->gotoAndPlay(arg0, arg1, arg2, arg3, arg4, arg5);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 7) 
    {
        std::string arg0;
        double arg1;
        double arg2;
        int arg3;
        int arg4;
        std::string arg5;
        dragonBones::Animation::AnimationFadeOutMode arg6;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3);

        ok &= luaval_to_int32(tolua_S, 6,(int *)&arg4);

        ok &= luaval_to_std_string(tolua_S, 7,&arg5);

        ok &= luaval_to_int32(tolua_S, 8,(int *)&arg6);
        if(!ok)
            return 0;
        dragonBones::AnimationState* ret = cobj->gotoAndPlay(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 8) 
    {
        std::string arg0;
        double arg1;
        double arg2;
        int arg3;
        int arg4;
        std::string arg5;
        dragonBones::Animation::AnimationFadeOutMode arg6;
        bool arg7;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3);

        ok &= luaval_to_int32(tolua_S, 6,(int *)&arg4);

        ok &= luaval_to_std_string(tolua_S, 7,&arg5);

        ok &= luaval_to_int32(tolua_S, 8,(int *)&arg6);

        ok &= luaval_to_boolean(tolua_S, 9,&arg7);
        if(!ok)
            return 0;
        dragonBones::AnimationState* ret = cobj->gotoAndPlay(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 9) 
    {
        std::string arg0;
        double arg1;
        double arg2;
        int arg3;
        int arg4;
        std::string arg5;
        dragonBones::Animation::AnimationFadeOutMode arg6;
        bool arg7;
        bool arg8;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3);

        ok &= luaval_to_int32(tolua_S, 6,(int *)&arg4);

        ok &= luaval_to_std_string(tolua_S, 7,&arg5);

        ok &= luaval_to_int32(tolua_S, 8,(int *)&arg6);

        ok &= luaval_to_boolean(tolua_S, 9,&arg7);

        ok &= luaval_to_boolean(tolua_S, 10,&arg8);
        if(!ok)
            return 0;
        dragonBones::AnimationState* ret = cobj->gotoAndPlay(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "gotoAndPlay",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_gotoAndPlay'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_getState(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_getState'", nullptr);
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
        dragonBones::AnimationState* ret = cobj->getState(arg0);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        int arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        dragonBones::AnimationState* ret = cobj->getState(arg0, arg1);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getState",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_getState'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_getIsComplete(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_getIsComplete'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->getIsComplete();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getIsComplete",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_getIsComplete'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_advanceTime(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_advanceTime'", nullptr);
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
        cobj->advanceTime(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "advanceTime",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_advanceTime'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_getIsPlaying(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_getIsPlaying'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->getIsPlaying();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getIsPlaying",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_getIsPlaying'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_gotoAndStop(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_gotoAndStop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        double arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        dragonBones::AnimationState* ret = cobj->gotoAndStop(arg0, arg1);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 3) 
    {
        std::string arg0;
        double arg1;
        double arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        dragonBones::AnimationState* ret = cobj->gotoAndStop(arg0, arg1, arg2);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 4) 
    {
        std::string arg0;
        double arg1;
        double arg2;
        double arg3;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_number(tolua_S, 5,&arg3);
        if(!ok)
            return 0;
        dragonBones::AnimationState* ret = cobj->gotoAndStop(arg0, arg1, arg2, arg3);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 5) 
    {
        std::string arg0;
        double arg1;
        double arg2;
        double arg3;
        double arg4;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_number(tolua_S, 5,&arg3);

        ok &= luaval_to_number(tolua_S, 6,&arg4);
        if(!ok)
            return 0;
        dragonBones::AnimationState* ret = cobj->gotoAndStop(arg0, arg1, arg2, arg3, arg4);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 6) 
    {
        std::string arg0;
        double arg1;
        double arg2;
        double arg3;
        double arg4;
        int arg5;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_number(tolua_S, 5,&arg3);

        ok &= luaval_to_number(tolua_S, 6,&arg4);

        ok &= luaval_to_int32(tolua_S, 7,(int *)&arg5);
        if(!ok)
            return 0;
        dragonBones::AnimationState* ret = cobj->gotoAndStop(arg0, arg1, arg2, arg3, arg4, arg5);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 7) 
    {
        std::string arg0;
        double arg1;
        double arg2;
        double arg3;
        double arg4;
        int arg5;
        std::string arg6;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_number(tolua_S, 5,&arg3);

        ok &= luaval_to_number(tolua_S, 6,&arg4);

        ok &= luaval_to_int32(tolua_S, 7,(int *)&arg5);

        ok &= luaval_to_std_string(tolua_S, 8,&arg6);
        if(!ok)
            return 0;
        dragonBones::AnimationState* ret = cobj->gotoAndStop(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 8) 
    {
        std::string arg0;
        double arg1;
        double arg2;
        double arg3;
        double arg4;
        int arg5;
        std::string arg6;
        dragonBones::Animation::AnimationFadeOutMode arg7;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);

        ok &= luaval_to_number(tolua_S, 4,&arg2);

        ok &= luaval_to_number(tolua_S, 5,&arg3);

        ok &= luaval_to_number(tolua_S, 6,&arg4);

        ok &= luaval_to_int32(tolua_S, 7,(int *)&arg5);

        ok &= luaval_to_std_string(tolua_S, 8,&arg6);

        ok &= luaval_to_int32(tolua_S, 9,(int *)&arg7);
        if(!ok)
            return 0;
        dragonBones::AnimationState* ret = cobj->gotoAndStop(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "gotoAndStop",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_gotoAndStop'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_getTimeScale(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_getTimeScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getTimeScale();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getTimeScale",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_getTimeScale'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_constructor(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new dragonBones::Animation();
        tolua_pushusertype(tolua_S,(void*)cobj,"db.Animation");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "Animation",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_dragonbones_Animation_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Animation)");
    return 0;
}

int lua_register_dragonbones_Animation(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.Animation");
    tolua_cclass(tolua_S,"Animation","db.Animation","",nullptr);

    tolua_beginmodule(tolua_S,"Animation");
        tolua_function(tolua_S,"new",lua_dragonbones_Animation_constructor);
        tolua_function(tolua_S,"getAnimationList",lua_dragonbones_Animation_getAnimationList);
        tolua_function(tolua_S,"setTimeScale",lua_dragonbones_Animation_setTimeScale);
        tolua_function(tolua_S,"stop",lua_dragonbones_Animation_stop);
        tolua_function(tolua_S,"clear",lua_dragonbones_Animation_clear);
        tolua_function(tolua_S,"dispose",lua_dragonbones_Animation_dispose);
        tolua_function(tolua_S,"play",lua_dragonbones_Animation_play);
        tolua_function(tolua_S,"hasAnimation",lua_dragonbones_Animation_hasAnimation);
        tolua_function(tolua_S,"getLastAnimationState",lua_dragonbones_Animation_getLastAnimationState);
        tolua_function(tolua_S,"gotoAndPlay",lua_dragonbones_Animation_gotoAndPlay);
        tolua_function(tolua_S,"getState",lua_dragonbones_Animation_getState);
        tolua_function(tolua_S,"getIsComplete",lua_dragonbones_Animation_getIsComplete);
        tolua_function(tolua_S,"advanceTime",lua_dragonbones_Animation_advanceTime);
        tolua_function(tolua_S,"getIsPlaying",lua_dragonbones_Animation_getIsPlaying);
        tolua_function(tolua_S,"gotoAndStop",lua_dragonbones_Animation_gotoAndStop);
        tolua_function(tolua_S,"getTimeScale",lua_dragonbones_Animation_getTimeScale);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::Animation).name();
    g_luaType[typeName] = "db.Animation";
    g_typeCast["Animation"] = "db.Animation";
    return 1;
}

int lua_dragonbones_Armature_getBone(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_getBone'", nullptr);
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
        dragonBones::Bone* ret = cobj->getBone(arg0);
        object_to_luaval<dragonBones::Bone>(tolua_S, "db.Bone",(dragonBones::Bone*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBone",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_getBone'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_getAnimation(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_getAnimation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        dragonBones::Animation* ret = cobj->getAnimation();
        object_to_luaval<dragonBones::Animation>(tolua_S, "db.Animation",(dragonBones::Animation*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAnimation",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_getAnimation'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_addBone(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_addBone'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            dragonBones::Bone* arg0;
            ok &= luaval_to_object<dragonBones::Bone>(tolua_S, 2, "db.Bone",&arg0);

            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1);

            if (!ok) { break; }
            cobj->addBone(arg0, arg1);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            dragonBones::Bone* arg0;
            ok &= luaval_to_object<dragonBones::Bone>(tolua_S, 2, "db.Bone",&arg0);

            if (!ok) { break; }
            cobj->addBone(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addBone",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_addBone'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_removeSlot(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_removeSlot'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            dragonBones::Slot* ret = cobj->removeSlot(arg0);
            object_to_luaval<dragonBones::Slot>(tolua_S, "db.Slot",(dragonBones::Slot*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            dragonBones::Slot* arg0;
            ok &= luaval_to_object<dragonBones::Slot>(tolua_S, 2, "db.Slot",&arg0);

            if (!ok) { break; }
            cobj->removeSlot(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeSlot",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_removeSlot'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_getSlot(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_getSlot'", nullptr);
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
        dragonBones::Slot* ret = cobj->getSlot(arg0);
        object_to_luaval<dragonBones::Slot>(tolua_S, "db.Slot",(dragonBones::Slot*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getSlot",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_getSlot'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_removeBone(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_removeBone'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            dragonBones::Bone* ret = cobj->removeBone(arg0);
            object_to_luaval<dragonBones::Bone>(tolua_S, "db.Bone",(dragonBones::Bone*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            dragonBones::Bone* arg0;
            ok &= luaval_to_object<dragonBones::Bone>(tolua_S, 2, "db.Bone",&arg0);

            if (!ok) { break; }
            cobj->removeBone(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeBone",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_removeBone'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_replaceSlot(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_replaceSlot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        std::string arg0;
        std::string arg1;
        dragonBones::Slot* arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_std_string(tolua_S, 3,&arg1);

        ok &= luaval_to_object<dragonBones::Slot>(tolua_S, 4, "db.Slot",&arg2);
        if(!ok)
            return 0;
        cobj->replaceSlot(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "replaceSlot",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_replaceSlot'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_getDisplay(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_getDisplay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        void* ret = cobj->getDisplay();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDisplay",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_getDisplay'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_addSlot(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_addSlot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        dragonBones::Slot* arg0;
        std::string arg1;

        ok &= luaval_to_object<dragonBones::Slot>(tolua_S, 2, "db.Slot",&arg0);

        ok &= luaval_to_std_string(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->addSlot(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addSlot",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_addSlot'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_getSlotByDisplay(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_getSlotByDisplay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const void* arg0;

        #pragma warning NO CONVERSION TO NATIVE FOR void*;
        if(!ok)
            return 0;
        dragonBones::Slot* ret = cobj->getSlotByDisplay(arg0);
        object_to_luaval<dragonBones::Slot>(tolua_S, "db.Slot",(dragonBones::Slot*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getSlotByDisplay",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_getSlotByDisplay'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_getBoneByDisplay(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_getBoneByDisplay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const void* arg0;

        #pragma warning NO CONVERSION TO NATIVE FOR void*;
        if(!ok)
            return 0;
        dragonBones::Bone* ret = cobj->getBoneByDisplay(arg0);
        object_to_luaval<dragonBones::Bone>(tolua_S, "db.Bone",(dragonBones::Bone*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBoneByDisplay",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_getBoneByDisplay'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_getArmatureData(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_getArmatureData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const dragonBones::ArmatureData* ret = cobj->getArmatureData();
        object_to_luaval<dragonBones::ArmatureData>(tolua_S, "db.ArmatureData",(dragonBones::ArmatureData*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getArmatureData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_getArmatureData'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_invalidUpdate(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_invalidUpdate'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            cobj->invalidUpdate(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            cobj->invalidUpdate();
            return 0;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "invalidUpdate",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_invalidUpdate'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_getEventDispatcher(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_getEventDispatcher'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        dragonBones::IEventDispatcher* ret = cobj->getEventDispatcher();
        object_to_luaval<dragonBones::IEventDispatcher>(tolua_S, "db.IEventDispatcher",(dragonBones::IEventDispatcher*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getEventDispatcher",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_getEventDispatcher'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_sortSlotsByZOrder(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_sortSlotsByZOrder'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->sortSlotsByZOrder();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "sortSlotsByZOrder",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_sortSlotsByZOrder'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_dispose(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_dispose'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->dispose();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "dispose",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_dispose'.",&tolua_err);
#endif

    return 0;
}
static int lua_dragonbones_Armature_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Armature)");
    return 0;
}

int lua_register_dragonbones_Armature(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.Armature");
    tolua_cclass(tolua_S,"Armature","db.Armature","db.IAnimatable",nullptr);

    tolua_beginmodule(tolua_S,"Armature");
        tolua_function(tolua_S,"getBone",lua_dragonbones_Armature_getBone);
        tolua_function(tolua_S,"getAnimation",lua_dragonbones_Armature_getAnimation);
        tolua_function(tolua_S,"addBone",lua_dragonbones_Armature_addBone);
        tolua_function(tolua_S,"removeSlot",lua_dragonbones_Armature_removeSlot);
        tolua_function(tolua_S,"getSlot",lua_dragonbones_Armature_getSlot);
        tolua_function(tolua_S,"removeBone",lua_dragonbones_Armature_removeBone);
        tolua_function(tolua_S,"replaceSlot",lua_dragonbones_Armature_replaceSlot);
        tolua_function(tolua_S,"getDisplay",lua_dragonbones_Armature_getDisplay);
        tolua_function(tolua_S,"addSlot",lua_dragonbones_Armature_addSlot);
        tolua_function(tolua_S,"getSlotByDisplay",lua_dragonbones_Armature_getSlotByDisplay);
        tolua_function(tolua_S,"getBoneByDisplay",lua_dragonbones_Armature_getBoneByDisplay);
        tolua_function(tolua_S,"getArmatureData",lua_dragonbones_Armature_getArmatureData);
        tolua_function(tolua_S,"invalidUpdate",lua_dragonbones_Armature_invalidUpdate);
        tolua_function(tolua_S,"getEventDispatcher",lua_dragonbones_Armature_getEventDispatcher);
        tolua_function(tolua_S,"sortSlotsByZOrder",lua_dragonbones_Armature_sortSlotsByZOrder);
        tolua_function(tolua_S,"dispose",lua_dragonbones_Armature_dispose);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::Armature).name();
    g_luaType[typeName] = "db.Armature";
    g_typeCast["Armature"] = "db.Armature";
    return 1;
}

int lua_dragonbones_Slot_getZOrder(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Slot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Slot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Slot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Slot_getZOrder'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getZOrder();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getZOrder",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Slot_getZOrder'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Slot_setChildArmature(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Slot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Slot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Slot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Slot_setChildArmature'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        dragonBones::Armature* arg0;

        ok &= luaval_to_object<dragonBones::Armature>(tolua_S, 2, "db.Armature",&arg0);
        if(!ok)
            return 0;
        cobj->setChildArmature(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        dragonBones::Armature* arg0;
        bool arg1;

        ok &= luaval_to_object<dragonBones::Armature>(tolua_S, 2, "db.Armature",&arg0);

        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->setChildArmature(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setChildArmature",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Slot_setChildArmature'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Slot_getDisplay(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Slot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Slot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Slot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Slot_getDisplay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        void* ret = cobj->getDisplay();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDisplay",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Slot_getDisplay'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Slot_isShowDisplay(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Slot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Slot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Slot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Slot_isShowDisplay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isShowDisplay();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isShowDisplay",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Slot_isShowDisplay'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Slot_setDisplay(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Slot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Slot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Slot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Slot_setDisplay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        void* arg0;

        #pragma warning NO CONVERSION TO NATIVE FOR void*;
        if(!ok)
            return 0;
        cobj->setDisplay(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        void* arg0;
        dragonBones::DisplayType arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*;

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        cobj->setDisplay(arg0, arg1);
        return 0;
    }
    if (argc == 3) 
    {
        void* arg0;
        dragonBones::DisplayType arg1;
        bool arg2;

        #pragma warning NO CONVERSION TO NATIVE FOR void*;

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);

        ok &= luaval_to_boolean(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cobj->setDisplay(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDisplay",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Slot_setDisplay'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Slot_getChildArmature(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Slot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Slot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Slot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Slot_getChildArmature'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        dragonBones::Armature* ret = cobj->getChildArmature();
        object_to_luaval<dragonBones::Armature>(tolua_S, "db.Armature",(dragonBones::Armature*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getChildArmature",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Slot_getChildArmature'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Slot_setZOrder(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Slot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Slot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Slot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Slot_setZOrder'", nullptr);
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
        cobj->setZOrder(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setZOrder",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Slot_setZOrder'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Slot_getDisplayIndex(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Slot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Slot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Slot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Slot_getDisplayIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getDisplayIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDisplayIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Slot_getDisplayIndex'.",&tolua_err);
#endif

    return 0;
}
static int lua_dragonbones_Slot_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Slot)");
    return 0;
}

int lua_register_dragonbones_Slot(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.Slot");
    tolua_cclass(tolua_S,"Slot","db.Slot","db.Object",nullptr);

    tolua_beginmodule(tolua_S,"Slot");
        tolua_function(tolua_S,"getZOrder",lua_dragonbones_Slot_getZOrder);
        tolua_function(tolua_S,"setChildArmature",lua_dragonbones_Slot_setChildArmature);
        tolua_function(tolua_S,"getDisplay",lua_dragonbones_Slot_getDisplay);
        tolua_function(tolua_S,"isShowDisplay",lua_dragonbones_Slot_isShowDisplay);
        tolua_function(tolua_S,"setDisplay",lua_dragonbones_Slot_setDisplay);
        tolua_function(tolua_S,"getChildArmature",lua_dragonbones_Slot_getChildArmature);
        tolua_function(tolua_S,"setZOrder",lua_dragonbones_Slot_setZOrder);
        tolua_function(tolua_S,"getDisplayIndex",lua_dragonbones_Slot_getDisplayIndex);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::Slot).name();
    g_luaType[typeName] = "db.Slot";
    g_typeCast["Slot"] = "db.Slot";
    return 1;
}

int lua_dragonbones_WorldClock_play(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::WorldClock* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.WorldClock",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::WorldClock*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_WorldClock_play'", nullptr);
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
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "play",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_WorldClock_play'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_WorldClock_setTimeScale(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::WorldClock* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.WorldClock",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::WorldClock*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_WorldClock_setTimeScale'", nullptr);
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
        cobj->setTimeScale(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTimeScale",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_WorldClock_setTimeScale'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_WorldClock_getTime(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::WorldClock* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.WorldClock",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::WorldClock*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_WorldClock_getTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getTime();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getTime",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_WorldClock_getTime'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_WorldClock_stop(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::WorldClock* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.WorldClock",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::WorldClock*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_WorldClock_stop'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_WorldClock_stop'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_WorldClock_dispose(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::WorldClock* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.WorldClock",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::WorldClock*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_WorldClock_dispose'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->dispose();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "dispose",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_WorldClock_dispose'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_WorldClock_getTimeScale(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::WorldClock* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.WorldClock",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::WorldClock*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_WorldClock_getTimeScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->getTimeScale();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getTimeScale",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_WorldClock_getTimeScale'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_WorldClock_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"db.WorldClock",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        dragonBones::WorldClock* ret = dragonBones::WorldClock::getInstance();
        object_to_luaval<dragonBones::WorldClock>(tolua_S, "db.WorldClock",(dragonBones::WorldClock*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_WorldClock_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_dragonbones_WorldClock_constructor(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::WorldClock* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new dragonBones::WorldClock();
        tolua_pushusertype(tolua_S,(void*)cobj,"db.WorldClock");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj = new dragonBones::WorldClock(arg0);
        tolua_pushusertype(tolua_S,(void*)cobj,"db.WorldClock");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj = new dragonBones::WorldClock(arg0, arg1);
        tolua_pushusertype(tolua_S,(void*)cobj,"db.WorldClock");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "WorldClock",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_WorldClock_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_dragonbones_WorldClock_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (WorldClock)");
    return 0;
}

int lua_register_dragonbones_WorldClock(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.WorldClock");
    tolua_cclass(tolua_S,"WorldClock","db.WorldClock","db.IAnimatable",nullptr);

    tolua_beginmodule(tolua_S,"WorldClock");
        tolua_function(tolua_S,"new",lua_dragonbones_WorldClock_constructor);
        tolua_function(tolua_S,"play",lua_dragonbones_WorldClock_play);
        tolua_function(tolua_S,"setTimeScale",lua_dragonbones_WorldClock_setTimeScale);
        tolua_function(tolua_S,"getTime",lua_dragonbones_WorldClock_getTime);
        tolua_function(tolua_S,"stop",lua_dragonbones_WorldClock_stop);
        tolua_function(tolua_S,"dispose",lua_dragonbones_WorldClock_dispose);
        tolua_function(tolua_S,"getTimeScale",lua_dragonbones_WorldClock_getTimeScale);
        tolua_function(tolua_S,"getInstance", lua_dragonbones_WorldClock_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::WorldClock).name();
    g_luaType[typeName] = "db.WorldClock";
    g_typeCast["WorldClock"] = "db.WorldClock";
    return 1;
}

int lua_dragonbones_BaseFactory_buildArmature(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::BaseFactory* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.BaseFactory",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (dragonBones::BaseFactory*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_BaseFactory_buildArmature'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1);

            if (!ok) { break; }
            dragonBones::Armature* ret = cobj->buildArmature(arg0, arg1);
            object_to_luaval<dragonBones::Armature>(tolua_S, "db.Armature",(dragonBones::Armature*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            dragonBones::Armature* ret = cobj->buildArmature(arg0);
            object_to_luaval<dragonBones::Armature>(tolua_S, "db.Armature",(dragonBones::Armature*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 5) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1);

            if (!ok) { break; }
            std::string arg2;
            ok &= luaval_to_std_string(tolua_S, 4,&arg2);

            if (!ok) { break; }
            std::string arg3;
            ok &= luaval_to_std_string(tolua_S, 5,&arg3);

            if (!ok) { break; }
            std::string arg4;
            ok &= luaval_to_std_string(tolua_S, 6,&arg4);

            if (!ok) { break; }
            dragonBones::Armature* ret = cobj->buildArmature(arg0, arg1, arg2, arg3, arg4);
            object_to_luaval<dragonBones::Armature>(tolua_S, "db.Armature",(dragonBones::Armature*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "buildArmature",argc, 5);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_BaseFactory_buildArmature'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_BaseFactory_removeDragonBonesData(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::BaseFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.BaseFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::BaseFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_BaseFactory_removeDragonBonesData'", nullptr);
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
        cobj->removeDragonBonesData(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        std::string arg0;
        bool arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->removeDragonBonesData(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeDragonBonesData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_BaseFactory_removeDragonBonesData'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_BaseFactory_addTextureAtlas(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::BaseFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.BaseFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::BaseFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_BaseFactory_addTextureAtlas'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        dragonBones::ITextureAtlas* arg0;

        ok &= luaval_to_object<dragonBones::ITextureAtlas>(tolua_S, 2, "db.ITextureAtlas",&arg0);
        if(!ok)
            return 0;
        cobj->addTextureAtlas(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        dragonBones::ITextureAtlas* arg0;
        std::string arg1;

        ok &= luaval_to_object<dragonBones::ITextureAtlas>(tolua_S, 2, "db.ITextureAtlas",&arg0);

        ok &= luaval_to_std_string(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->addTextureAtlas(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addTextureAtlas",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_BaseFactory_addTextureAtlas'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_BaseFactory_addDragonBonesData(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::BaseFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.BaseFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::BaseFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_BaseFactory_addDragonBonesData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        dragonBones::DragonBonesData* arg0;

        ok &= luaval_to_object<dragonBones::DragonBonesData>(tolua_S, 2, "db.DragonBonesData",&arg0);
        if(!ok)
            return 0;
        cobj->addDragonBonesData(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        dragonBones::DragonBonesData* arg0;
        std::string arg1;

        ok &= luaval_to_object<dragonBones::DragonBonesData>(tolua_S, 2, "db.DragonBonesData",&arg0);

        ok &= luaval_to_std_string(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->addDragonBonesData(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addDragonBonesData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_BaseFactory_addDragonBonesData'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_BaseFactory_dispose(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::BaseFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.BaseFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::BaseFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_BaseFactory_dispose'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->dispose();
        return 0;
    }
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->dispose(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "dispose",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_BaseFactory_dispose'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_BaseFactory_getTextureAtlas(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::BaseFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.BaseFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::BaseFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_BaseFactory_getTextureAtlas'", nullptr);
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
        dragonBones::ITextureAtlas* ret = cobj->getTextureAtlas(arg0);
        object_to_luaval<dragonBones::ITextureAtlas>(tolua_S, "db.ITextureAtlas",(dragonBones::ITextureAtlas*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getTextureAtlas",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_BaseFactory_getTextureAtlas'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_BaseFactory_getTextureDisplay(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::BaseFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.BaseFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::BaseFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_BaseFactory_getTextureDisplay'", nullptr);
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
        void* ret = cobj->getTextureDisplay(arg0);
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_std_string(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        void* ret = cobj->getTextureDisplay(arg0, arg1);
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    if (argc == 3) 
    {
        std::string arg0;
        std::string arg1;
        const dragonBones::DisplayData* arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_std_string(tolua_S, 3,&arg1);

        ok &= luaval_to_object<const dragonBones::DisplayData>(tolua_S, 4, "db.DisplayData",&arg2);
        if(!ok)
            return 0;
        void* ret = cobj->getTextureDisplay(arg0, arg1, arg2);
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getTextureDisplay",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_BaseFactory_getTextureDisplay'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_BaseFactory_removeTextureAtlas(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::BaseFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.BaseFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::BaseFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_BaseFactory_removeTextureAtlas'", nullptr);
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
        cobj->removeTextureAtlas(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        std::string arg0;
        bool arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->removeTextureAtlas(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeTextureAtlas",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_BaseFactory_removeTextureAtlas'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_BaseFactory_getDragonBonesData(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::BaseFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.BaseFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::BaseFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_BaseFactory_getDragonBonesData'", nullptr);
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
        dragonBones::DragonBonesData* ret = cobj->getDragonBonesData(arg0);
        object_to_luaval<dragonBones::DragonBonesData>(tolua_S, "db.DragonBonesData",(dragonBones::DragonBonesData*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDragonBonesData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_BaseFactory_getDragonBonesData'.",&tolua_err);
#endif

    return 0;
}
static int lua_dragonbones_BaseFactory_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (BaseFactory)");
    return 0;
}

int lua_register_dragonbones_BaseFactory(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.BaseFactory");
    tolua_cclass(tolua_S,"BaseFactory","db.BaseFactory","",nullptr);

    tolua_beginmodule(tolua_S,"BaseFactory");
        tolua_function(tolua_S,"buildArmature",lua_dragonbones_BaseFactory_buildArmature);
        tolua_function(tolua_S,"removeDragonBonesData",lua_dragonbones_BaseFactory_removeDragonBonesData);
        tolua_function(tolua_S,"addTextureAtlas",lua_dragonbones_BaseFactory_addTextureAtlas);
        tolua_function(tolua_S,"addDragonBonesData",lua_dragonbones_BaseFactory_addDragonBonesData);
        tolua_function(tolua_S,"dispose",lua_dragonbones_BaseFactory_dispose);
        tolua_function(tolua_S,"getTextureAtlas",lua_dragonbones_BaseFactory_getTextureAtlas);
        tolua_function(tolua_S,"getTextureDisplay",lua_dragonbones_BaseFactory_getTextureDisplay);
        tolua_function(tolua_S,"removeTextureAtlas",lua_dragonbones_BaseFactory_removeTextureAtlas);
        tolua_function(tolua_S,"getDragonBonesData",lua_dragonbones_BaseFactory_getDragonBonesData);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::BaseFactory).name();
    g_luaType[typeName] = "db.BaseFactory";
    g_typeCast["BaseFactory"] = "db.BaseFactory";
    return 1;
}

int lua_dragonbones_DBCCSlot_getCCChildArmature(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DBCCSlot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.DBCCSlot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::DBCCSlot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_DBCCSlot_getCCChildArmature'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        dragonBones::DBCCArmature* ret = cobj->getCCChildArmature();
        object_to_luaval<dragonBones::DBCCArmature>(tolua_S, "db.DBCCArmature",(dragonBones::DBCCArmature*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCCChildArmature",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCSlot_getCCChildArmature'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_DBCCSlot_getCCDisplay(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DBCCSlot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.DBCCSlot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::DBCCSlot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_DBCCSlot_getCCDisplay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->getCCDisplay();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCCDisplay",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCSlot_getCCDisplay'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_DBCCSlot_setDisplayImage(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DBCCSlot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.DBCCSlot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::DBCCSlot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_DBCCSlot_setDisplayImage'", nullptr);
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
        cobj->setDisplayImage(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        cocos2d::Node* arg0;
        bool arg1;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);

        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->setDisplayImage(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDisplayImage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCSlot_setDisplayImage'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_DBCCSlot_constructor(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DBCCSlot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        dragonBones::SlotData* arg0;

        ok &= luaval_to_object<dragonBones::SlotData>(tolua_S, 2, "db.SlotData",&arg0);
        if(!ok)
            return 0;
        cobj = new dragonBones::DBCCSlot(arg0);
        tolua_pushusertype(tolua_S,(void*)cobj,"db.DBCCSlot");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "DBCCSlot",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCSlot_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_dragonbones_DBCCSlot_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DBCCSlot)");
    return 0;
}

int lua_register_dragonbones_DBCCSlot(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.DBCCSlot");
    tolua_cclass(tolua_S,"DBCCSlot","db.DBCCSlot","db.Slot",nullptr);

    tolua_beginmodule(tolua_S,"DBCCSlot");
        tolua_function(tolua_S,"new",lua_dragonbones_DBCCSlot_constructor);
        tolua_function(tolua_S,"getCCChildArmature",lua_dragonbones_DBCCSlot_getCCChildArmature);
        tolua_function(tolua_S,"getCCDisplay",lua_dragonbones_DBCCSlot_getCCDisplay);
        tolua_function(tolua_S,"setDisplayImage",lua_dragonbones_DBCCSlot_setDisplayImage);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::DBCCSlot).name();
    g_luaType[typeName] = "db.DBCCSlot";
    g_typeCast["DBCCSlot"] = "db.DBCCSlot";
    return 1;
}

int lua_dragonbones_DBCCArmature_getCCEventDispatcher(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DBCCArmature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.DBCCArmature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::DBCCArmature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_DBCCArmature_getCCEventDispatcher'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::EventDispatcher* ret = cobj->getCCEventDispatcher();
        object_to_luaval<cocos2d::EventDispatcher>(tolua_S, "cc.EventDispatcher",(cocos2d::EventDispatcher*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCCEventDispatcher",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCArmature_getCCEventDispatcher'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_DBCCArmature_getCCSlot(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DBCCArmature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.DBCCArmature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::DBCCArmature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_DBCCArmature_getCCSlot'", nullptr);
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
        dragonBones::DBCCSlot* ret = cobj->getCCSlot(arg0);
        object_to_luaval<dragonBones::DBCCSlot>(tolua_S, "db.DBCCSlot",(dragonBones::DBCCSlot*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCCSlot",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCArmature_getCCSlot'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_DBCCArmature_getCCDisplay(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DBCCArmature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.DBCCArmature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::DBCCArmature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_DBCCArmature_getCCDisplay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->getCCDisplay();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCCDisplay",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCArmature_getCCDisplay'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_DBCCArmature_getCCBoundingBox(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DBCCArmature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.DBCCArmature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::DBCCArmature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_DBCCArmature_getCCBoundingBox'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Rect ret = cobj->getCCBoundingBox();
        rect_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCCBoundingBox",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCArmature_getCCBoundingBox'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_DBCCArmature_constructor(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DBCCArmature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        dragonBones::ArmatureData* arg0;
        dragonBones::Animation* arg1;
        dragonBones::IEventDispatcher* arg2;
        cocos2d::Node* arg3;

        ok &= luaval_to_object<dragonBones::ArmatureData>(tolua_S, 2, "db.ArmatureData",&arg0);

        ok &= luaval_to_object<dragonBones::Animation>(tolua_S, 3, "db.Animation",&arg1);

        ok &= luaval_to_object<dragonBones::IEventDispatcher>(tolua_S, 4, "db.IEventDispatcher",&arg2);

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 5, "cc.Node",&arg3);
        if(!ok)
            return 0;
        cobj = new dragonBones::DBCCArmature(arg0, arg1, arg2, arg3);
        tolua_pushusertype(tolua_S,(void*)cobj,"db.DBCCArmature");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "DBCCArmature",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCArmature_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_dragonbones_DBCCArmature_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DBCCArmature)");
    return 0;
}

int lua_register_dragonbones_DBCCArmature(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.DBCCArmature");
    tolua_cclass(tolua_S,"DBCCArmature","db.DBCCArmature","db.Armature",nullptr);

    tolua_beginmodule(tolua_S,"DBCCArmature");
        tolua_function(tolua_S,"new",lua_dragonbones_DBCCArmature_constructor);
        tolua_function(tolua_S,"getCCEventDispatcher",lua_dragonbones_DBCCArmature_getCCEventDispatcher);
        tolua_function(tolua_S,"getCCSlot",lua_dragonbones_DBCCArmature_getCCSlot);
        tolua_function(tolua_S,"getCCDisplay",lua_dragonbones_DBCCArmature_getCCDisplay);
        tolua_function(tolua_S,"getCCBoundingBox",lua_dragonbones_DBCCArmature_getCCBoundingBox);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::DBCCArmature).name();
    g_luaType[typeName] = "db.DBCCArmature";
    g_typeCast["DBCCArmature"] = "db.DBCCArmature";
    return 1;
}

int lua_dragonbones_DBCCArmatureNode_getAnimation(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DBCCArmatureNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.DBCCArmatureNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::DBCCArmatureNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_DBCCArmatureNode_getAnimation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        dragonBones::Animation* ret = cobj->getAnimation();
        object_to_luaval<dragonBones::Animation>(tolua_S, "db.Animation",(dragonBones::Animation*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAnimation",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCArmatureNode_getAnimation'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_DBCCArmatureNode_registerMovementEventHandler(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DBCCArmatureNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.DBCCArmatureNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::DBCCArmatureNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_DBCCArmatureNode_registerMovementEventHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::LUA_FUNCTION arg0;

        arg0 =  toluafix_ref_function(tolua_S,2,0);ok &= arg0 != 0;;
        if(!ok)
            return 0;
        cobj->registerMovementEventHandler(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerMovementEventHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCArmatureNode_registerMovementEventHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_DBCCArmatureNode_getCCEventDispatcher(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DBCCArmatureNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.DBCCArmatureNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::DBCCArmatureNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_DBCCArmatureNode_getCCEventDispatcher'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::EventDispatcher* ret = cobj->getCCEventDispatcher();
        object_to_luaval<cocos2d::EventDispatcher>(tolua_S, "cc.EventDispatcher",(cocos2d::EventDispatcher*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCCEventDispatcher",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCArmatureNode_getCCEventDispatcher'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_DBCCArmatureNode_registerFrameEventHandler(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DBCCArmatureNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.DBCCArmatureNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::DBCCArmatureNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_DBCCArmatureNode_registerFrameEventHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::LUA_FUNCTION arg0;

        arg0 =  toluafix_ref_function(tolua_S,2,0);ok &= arg0 != 0;;
        if(!ok)
            return 0;
        cobj->registerFrameEventHandler(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerFrameEventHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCArmatureNode_registerFrameEventHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_DBCCArmatureNode_getArmature(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DBCCArmatureNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.DBCCArmatureNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::DBCCArmatureNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_DBCCArmatureNode_getArmature'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        dragonBones::DBCCArmature* ret = cobj->getArmature();
        object_to_luaval<dragonBones::DBCCArmature>(tolua_S, "db.DBCCArmature",(dragonBones::DBCCArmature*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getArmature",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCArmatureNode_getArmature'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_DBCCArmatureNode_unregisterMovementEventHandler(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DBCCArmatureNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.DBCCArmatureNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::DBCCArmatureNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_DBCCArmatureNode_unregisterMovementEventHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->unregisterMovementEventHandler();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "unregisterMovementEventHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCArmatureNode_unregisterMovementEventHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_DBCCArmatureNode_getCCSlot(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DBCCArmatureNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.DBCCArmatureNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::DBCCArmatureNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_DBCCArmatureNode_getCCSlot'", nullptr);
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
        dragonBones::DBCCSlot* ret = cobj->getCCSlot(arg0);
        object_to_luaval<dragonBones::DBCCSlot>(tolua_S, "db.DBCCSlot",(dragonBones::DBCCSlot*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCCSlot",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCArmatureNode_getCCSlot'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_DBCCArmatureNode_unregisterFrameEventHandler(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DBCCArmatureNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.DBCCArmatureNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::DBCCArmatureNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_DBCCArmatureNode_unregisterFrameEventHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->unregisterFrameEventHandler();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "unregisterFrameEventHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCArmatureNode_unregisterFrameEventHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_DBCCArmatureNode_initWithDBCCArmature(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DBCCArmatureNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.DBCCArmatureNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::DBCCArmatureNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_DBCCArmatureNode_initWithDBCCArmature'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        dragonBones::DBCCArmature* arg0;
        dragonBones::WorldClock* arg1;

        ok &= luaval_to_object<dragonBones::DBCCArmature>(tolua_S, 2, "db.DBCCArmature",&arg0);

        ok &= luaval_to_object<dragonBones::WorldClock>(tolua_S, 3, "db.WorldClock",&arg1);
        if(!ok)
            return 0;
        bool ret = cobj->initWithDBCCArmature(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWithDBCCArmature",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCArmatureNode_initWithDBCCArmature'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_DBCCArmatureNode_getCCDisplay(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DBCCArmatureNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.DBCCArmatureNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::DBCCArmatureNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_DBCCArmatureNode_getCCDisplay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->getCCDisplay();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCCDisplay",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCArmatureNode_getCCDisplay'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_DBCCArmatureNode_advanceTime(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DBCCArmatureNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.DBCCArmatureNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::DBCCArmatureNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_DBCCArmatureNode_advanceTime'", nullptr);
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
        cobj->advanceTime(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "advanceTime",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCArmatureNode_advanceTime'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_DBCCArmatureNode_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"db.DBCCArmatureNode",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        dragonBones::DBCCArmature* arg0;
        ok &= luaval_to_object<dragonBones::DBCCArmature>(tolua_S, 2, "db.DBCCArmature",&arg0);
        if(!ok)
            return 0;
        dragonBones::DBCCArmatureNode* ret = dragonBones::DBCCArmatureNode::create(arg0);
        object_to_luaval<dragonBones::DBCCArmatureNode>(tolua_S, "db.DBCCArmatureNode",(dragonBones::DBCCArmatureNode*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCArmatureNode_create'.",&tolua_err);
#endif
    return 0;
}
int lua_dragonbones_DBCCArmatureNode_createWithWorldClock(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"db.DBCCArmatureNode",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        dragonBones::DBCCArmature* arg0;
        dragonBones::WorldClock* arg1;
        ok &= luaval_to_object<dragonBones::DBCCArmature>(tolua_S, 2, "db.DBCCArmature",&arg0);
        ok &= luaval_to_object<dragonBones::WorldClock>(tolua_S, 3, "db.WorldClock",&arg1);
        if(!ok)
            return 0;
        dragonBones::DBCCArmatureNode* ret = dragonBones::DBCCArmatureNode::createWithWorldClock(arg0, arg1);
        object_to_luaval<dragonBones::DBCCArmatureNode>(tolua_S, "db.DBCCArmatureNode",(dragonBones::DBCCArmatureNode*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createWithWorldClock",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCArmatureNode_createWithWorldClock'.",&tolua_err);
#endif
    return 0;
}
int lua_dragonbones_DBCCArmatureNode_constructor(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DBCCArmatureNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new dragonBones::DBCCArmatureNode();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"db.DBCCArmatureNode");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "DBCCArmatureNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCArmatureNode_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_dragonbones_DBCCArmatureNode_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DBCCArmatureNode)");
    return 0;
}

int lua_register_dragonbones_DBCCArmatureNode(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.DBCCArmatureNode");
    tolua_cclass(tolua_S,"DBCCArmatureNode","db.DBCCArmatureNode","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"DBCCArmatureNode");
        tolua_function(tolua_S,"new",lua_dragonbones_DBCCArmatureNode_constructor);
        tolua_function(tolua_S,"getAnimation",lua_dragonbones_DBCCArmatureNode_getAnimation);
        tolua_function(tolua_S,"registerMovementEventHandler",lua_dragonbones_DBCCArmatureNode_registerMovementEventHandler);
        tolua_function(tolua_S,"getCCEventDispatcher",lua_dragonbones_DBCCArmatureNode_getCCEventDispatcher);
        tolua_function(tolua_S,"registerFrameEventHandler",lua_dragonbones_DBCCArmatureNode_registerFrameEventHandler);
        tolua_function(tolua_S,"getArmature",lua_dragonbones_DBCCArmatureNode_getArmature);
        tolua_function(tolua_S,"unregisterMovementEventHandler",lua_dragonbones_DBCCArmatureNode_unregisterMovementEventHandler);
        tolua_function(tolua_S,"getCCSlot",lua_dragonbones_DBCCArmatureNode_getCCSlot);
        tolua_function(tolua_S,"unregisterFrameEventHandler",lua_dragonbones_DBCCArmatureNode_unregisterFrameEventHandler);
        tolua_function(tolua_S,"initWithDBCCArmature",lua_dragonbones_DBCCArmatureNode_initWithDBCCArmature);
        tolua_function(tolua_S,"getCCDisplay",lua_dragonbones_DBCCArmatureNode_getCCDisplay);
        tolua_function(tolua_S,"advanceTime",lua_dragonbones_DBCCArmatureNode_advanceTime);
        tolua_function(tolua_S,"create", lua_dragonbones_DBCCArmatureNode_create);
        tolua_function(tolua_S,"createWithWorldClock", lua_dragonbones_DBCCArmatureNode_createWithWorldClock);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::DBCCArmatureNode).name();
    g_luaType[typeName] = "db.DBCCArmatureNode";
    g_typeCast["DBCCArmatureNode"] = "db.DBCCArmatureNode";
    return 1;
}

int lua_dragonbones_DBCCFactory_buildArmatureNode(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DBCCFactory* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.DBCCFactory",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (dragonBones::DBCCFactory*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_DBCCFactory_buildArmatureNode'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1);

            if (!ok) { break; }
            dragonBones::DBCCArmatureNode* ret = cobj->buildArmatureNode(arg0, arg1);
            object_to_luaval<dragonBones::DBCCArmatureNode>(tolua_S, "db.DBCCArmatureNode",(dragonBones::DBCCArmatureNode*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            dragonBones::DBCCArmatureNode* ret = cobj->buildArmatureNode(arg0);
            object_to_luaval<dragonBones::DBCCArmatureNode>(tolua_S, "db.DBCCArmatureNode",(dragonBones::DBCCArmatureNode*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 5) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1);

            if (!ok) { break; }
            std::string arg2;
            ok &= luaval_to_std_string(tolua_S, 4,&arg2);

            if (!ok) { break; }
            std::string arg3;
            ok &= luaval_to_std_string(tolua_S, 5,&arg3);

            if (!ok) { break; }
            std::string arg4;
            ok &= luaval_to_std_string(tolua_S, 6,&arg4);

            if (!ok) { break; }
            dragonBones::DBCCArmatureNode* ret = cobj->buildArmatureNode(arg0, arg1, arg2, arg3, arg4);
            object_to_luaval<dragonBones::DBCCArmatureNode>(tolua_S, "db.DBCCArmatureNode",(dragonBones::DBCCArmatureNode*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "buildArmatureNode",argc, 5);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCFactory_buildArmatureNode'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_DBCCFactory_hasDragonBones(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DBCCFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.DBCCFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::DBCCFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_DBCCFactory_hasDragonBones'", nullptr);
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
        bool ret = cobj->hasDragonBones(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_std_string(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        bool ret = cobj->hasDragonBones(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 3) 
    {
        std::string arg0;
        std::string arg1;
        std::string arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_std_string(tolua_S, 3,&arg1);

        ok &= luaval_to_std_string(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        bool ret = cobj->hasDragonBones(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "hasDragonBones",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCFactory_hasDragonBones'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_DBCCFactory_loadTextureAtlas(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DBCCFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.DBCCFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::DBCCFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_DBCCFactory_loadTextureAtlas'", nullptr);
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
        dragonBones::ITextureAtlas* ret = cobj->loadTextureAtlas(arg0);
        object_to_luaval<dragonBones::ITextureAtlas>(tolua_S, "db.ITextureAtlas",(dragonBones::ITextureAtlas*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_std_string(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        dragonBones::ITextureAtlas* ret = cobj->loadTextureAtlas(arg0, arg1);
        object_to_luaval<dragonBones::ITextureAtlas>(tolua_S, "db.ITextureAtlas",(dragonBones::ITextureAtlas*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "loadTextureAtlas",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCFactory_loadTextureAtlas'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_DBCCFactory_refreshAllTextureAtlasTexture(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DBCCFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.DBCCFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::DBCCFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_DBCCFactory_refreshAllTextureAtlasTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->refreshAllTextureAtlasTexture();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "refreshAllTextureAtlasTexture",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCFactory_refreshAllTextureAtlasTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_DBCCFactory_refreshTextureAtlasTexture(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DBCCFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.DBCCFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::DBCCFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_DBCCFactory_refreshTextureAtlasTexture'", nullptr);
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
        cobj->refreshTextureAtlasTexture(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "refreshTextureAtlasTexture",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCFactory_refreshTextureAtlasTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_DBCCFactory_loadDragonBonesData(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DBCCFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.DBCCFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::DBCCFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_DBCCFactory_loadDragonBonesData'", nullptr);
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
        dragonBones::DragonBonesData* ret = cobj->loadDragonBonesData(arg0);
        object_to_luaval<dragonBones::DragonBonesData>(tolua_S, "db.DragonBonesData",(dragonBones::DragonBonesData*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0);

        ok &= luaval_to_std_string(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        dragonBones::DragonBonesData* ret = cobj->loadDragonBonesData(arg0, arg1);
        object_to_luaval<dragonBones::DragonBonesData>(tolua_S, "db.DragonBonesData",(dragonBones::DragonBonesData*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "loadDragonBonesData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCFactory_loadDragonBonesData'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_DBCCFactory_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"db.DBCCFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        dragonBones::DBCCFactory* ret = dragonBones::DBCCFactory::getInstance();
        object_to_luaval<dragonBones::DBCCFactory>(tolua_S, "db.DBCCFactory",(dragonBones::DBCCFactory*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCFactory_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_dragonbones_DBCCFactory_constructor(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DBCCFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new dragonBones::DBCCFactory();
        tolua_pushusertype(tolua_S,(void*)cobj,"db.DBCCFactory");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "DBCCFactory",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DBCCFactory_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_dragonbones_DBCCFactory_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DBCCFactory)");
    return 0;
}

int lua_register_dragonbones_DBCCFactory(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.DBCCFactory");
    tolua_cclass(tolua_S,"DBCCFactory","db.DBCCFactory","db.BaseFactory",nullptr);

    tolua_beginmodule(tolua_S,"DBCCFactory");
        tolua_function(tolua_S,"new",lua_dragonbones_DBCCFactory_constructor);
        tolua_function(tolua_S,"buildArmatureNode",lua_dragonbones_DBCCFactory_buildArmatureNode);
        tolua_function(tolua_S,"hasDragonBones",lua_dragonbones_DBCCFactory_hasDragonBones);
        tolua_function(tolua_S,"loadTextureAtlas",lua_dragonbones_DBCCFactory_loadTextureAtlas);
        tolua_function(tolua_S,"refreshAllTextureAtlasTexture",lua_dragonbones_DBCCFactory_refreshAllTextureAtlasTexture);
        tolua_function(tolua_S,"refreshTextureAtlasTexture",lua_dragonbones_DBCCFactory_refreshTextureAtlasTexture);
        tolua_function(tolua_S,"loadDragonBonesData",lua_dragonbones_DBCCFactory_loadDragonBonesData);
        tolua_function(tolua_S,"getInstance", lua_dragonbones_DBCCFactory_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::DBCCFactory).name();
    g_luaType[typeName] = "db.DBCCFactory";
    g_typeCast["DBCCFactory"] = "db.DBCCFactory";
    return 1;
}
TOLUA_API int register_all_dragonbones(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,NULL,0);
	tolua_beginmodule(tolua_S, NULL);

	lua_register_dragonbones_Slot(tolua_S);
	lua_register_dragonbones_BaseFactory(tolua_S);
	lua_register_dragonbones_IAnimatable(tolua_S);
	lua_register_dragonbones_AnimationState(tolua_S);
	lua_register_dragonbones_DBCCFactory(tolua_S);
	lua_register_dragonbones_Animation(tolua_S);
	lua_register_dragonbones_DBCCSlot(tolua_S);
	lua_register_dragonbones_Armature(tolua_S);
	lua_register_dragonbones_DBCCArmature(tolua_S);
	lua_register_dragonbones_DBCCArmatureNode(tolua_S);
	lua_register_dragonbones_WorldClock(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

