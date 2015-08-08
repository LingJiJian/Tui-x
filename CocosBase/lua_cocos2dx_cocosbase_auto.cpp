#include "lua_cocos2dx_cocosbase_auto.hpp"
#include "cocos-base.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"
#include "CCLuaValue.h"

///////////////////////handle///////////////////////////////////////////////
int lua_cocos2dx_cocosbase_CSceneManager_registerSceneClassScriptFunc(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;
	cocos2d::CSceneManager* cobj = nullptr;
	cobj = (cocos2d::CSceneManager*)tolua_tousertype(tolua_S, 1, 0);
	argc = lua_gettop(tolua_S) - 1;
	if (2 == argc)
	{
		const char* key;

		std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); key = arg0_tmp.c_str();
		if (!ok)
			return 0;

		LUA_FUNCTION nHandler = toluafix_ref_function(tolua_S, 3, 0);
		cobj->registerSceneClassScriptFunc(key, nHandler);
	}
	return 0;
}

#define LUA_COCOS2DX_CCB_SCRIPT_HANDLER( __WIDGET__, __SET_HANDLER__)         \
	int lua_cocos2dx_cocosbase_##__WIDGET__##_##__SET_HANDLER__(lua_State* tolua_S)       \
{    \
	int argc = 0;      \
	cocos2d::__WIDGET__* cobj = nullptr;	     \
	cobj = (cocos2d::__WIDGET__*)tolua_tousertype(tolua_S, 1, 0);     \
	argc = lua_gettop(tolua_S) - 1;     \
if (1 == argc)      \
{     \
	LUA_FUNCTION nHandler = toluafix_ref_function(tolua_S, 2, 0);     \
	cobj->__SET_HANDLER__(nHandler);     \
}     \
	return 0;     \
}

LUA_COCOS2DX_CCB_SCRIPT_HANDLER(CSceneExtension, setOnLoadResourcesScriptHandler)
LUA_COCOS2DX_CCB_SCRIPT_HANDLER(CSceneExtension, setOnLoadResourcesCompletedScriptHandler)
LUA_COCOS2DX_CCB_SCRIPT_HANDLER(CSceneExtension, setOnLoadResourcesProgressScriptHandler)
LUA_COCOS2DX_CCB_SCRIPT_HANDLER(CSceneExtension, setOnLoadSceneScriptHandler)
LUA_COCOS2DX_CCB_SCRIPT_HANDLER(CSceneExtension, setOnEnterSceneScriptHandler)
LUA_COCOS2DX_CCB_SCRIPT_HANDLER(CSceneExtension, setOnExitSceneScriptHandler)

//////////////////////////////////////////////////////////////////////////
/*
int lua_cocos2dx_cocosbase_CCMsgDelegate_removeOnMessageScriptHandler(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCMsgDelegate* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCMsgDelegate",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCMsgDelegate*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCMsgDelegate_removeOnMessageScriptHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeOnMessageScriptHandler();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeOnMessageScriptHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCMsgDelegate_removeOnMessageScriptHandler'.",&tolua_err);
#endif

    return 0;
}
*/
int lua_cocos2dx_cocosbase_CCMsgDelegate_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCMsgDelegate* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCMsgDelegate();
        tolua_pushusertype(tolua_S,(void*)cobj,"cc.CCMsgDelegate");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCMsgDelegate",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCMsgDelegate_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCMsgDelegate_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCMsgDelegate)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCMsgDelegate(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCMsgDelegate");
    tolua_cclass(tolua_S,"CCMsgDelegate","cc.CCMsgDelegate","",nullptr);

    tolua_beginmodule(tolua_S,"CCMsgDelegate");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCMsgDelegate_constructor);
        //tolua_function(tolua_S,"removeOnMessageScriptHandler",lua_cocos2dx_cocosbase_CCMsgDelegate_removeOnMessageScriptHandler);
		
	tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCMsgDelegate).name();
    g_luaType[typeName] = "cc.CCMsgDelegate";
    g_typeCast["CCMsgDelegate"] = "cc.CCMsgDelegate";
    return 1;
}

int lua_cocos2dx_cocosbase_CCMsgManager_PostMessage(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCMsgManager* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCMsgManager",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::CCMsgManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCMsgManager_PostMessage'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 3) {
            cocos2d::CCMsgDelegate* arg0;
            ok &= luaval_to_object<cocos2d::CCMsgDelegate>(tolua_S, 2, "cc.CCMsgDelegate",&arg0);

            if (!ok) { break; }
            unsigned int arg1;
            ok &= luaval_to_uint32(tolua_S, 3,&arg1);

            if (!ok) { break; }
            cocos2d::Ref* arg2;
            ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 4, "cc.Ref",&arg2);

            if (!ok) { break; }
            cobj->PostMessage(arg0, arg1, arg2);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0);

            if (!ok) { break; }
            cocos2d::Ref* arg1;
            ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 3, "cc.Ref",&arg1);

            if (!ok) { break; }
            cobj->PostMessage(arg0, arg1);
            return 0;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "PostMessage",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCMsgManager_PostMessage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCMsgManager_registerMsgDelegate(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCMsgManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCMsgManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCMsgManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCMsgManager_registerMsgDelegate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::CCMsgDelegate* arg0;

        ok &= luaval_to_object<cocos2d::CCMsgDelegate>(tolua_S, 2, "cc.CCMsgDelegate",&arg0);
        if(!ok)
            return 0;
        cobj->registerMsgDelegate(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "registerMsgDelegate",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCMsgManager_registerMsgDelegate'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCMsgManager_update(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCMsgManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCMsgManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCMsgManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCMsgManager_update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->update();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "update",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCMsgManager_update'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCMsgManager_unregisterMsgDelegate(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCMsgManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCMsgManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCMsgManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCMsgManager_unregisterMsgDelegate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::CCMsgDelegate* arg0;

        ok &= luaval_to_object<cocos2d::CCMsgDelegate>(tolua_S, 2, "cc.CCMsgDelegate",&arg0);
        if(!ok)
            return 0;
        cobj->unregisterMsgDelegate(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "unregisterMsgDelegate",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCMsgManager_unregisterMsgDelegate'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCMsgManager_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCMsgManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocos2d::CCMsgManager* ret = cocos2d::CCMsgManager::getInstance();
        object_to_luaval<cocos2d::CCMsgManager>(tolua_S, "cc.CCMsgManager",(cocos2d::CCMsgManager*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCMsgManager_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_cocosbase_CCMsgManager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCMsgManager)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCMsgManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCMsgManager");
    tolua_cclass(tolua_S,"CCMsgManager","cc.CCMsgManager","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CCMsgManager");
        tolua_function(tolua_S,"PostMessage",lua_cocos2dx_cocosbase_CCMsgManager_PostMessage);
        tolua_function(tolua_S,"registerMsgDelegate",lua_cocos2dx_cocosbase_CCMsgManager_registerMsgDelegate);
        tolua_function(tolua_S,"update",lua_cocos2dx_cocosbase_CCMsgManager_update);
        tolua_function(tolua_S,"unregisterMsgDelegate",lua_cocos2dx_cocosbase_CCMsgManager_unregisterMsgDelegate);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_cocosbase_CCMsgManager_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCMsgManager).name();
    g_luaType[typeName] = "cc.CCMsgManager";
    g_typeCast["CCMsgManager"] = "cc.CCMsgManager";
    return 1;
}

int lua_cocos2dx_cocosbase_CCBundle_putInt(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBundle* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBundle",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBundle*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCBundle_putInt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        cobj->putInt(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "putInt",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCBundle_putInt'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCBundle_getUShort(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBundle* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBundle",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBundle*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCBundle_getUShort'", nullptr);
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
        unsigned short ret = cobj->getUShort(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getUShort",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCBundle_getUShort'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCBundle_getFloat(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBundle* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBundle",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBundle*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCBundle_getFloat'", nullptr);
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
        double ret = cobj->getFloat(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getFloat",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCBundle_getFloat'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCBundle_putFloat(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBundle* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBundle",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBundle*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCBundle_putFloat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        double arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->putFloat(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "putFloat",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCBundle_putFloat'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCBundle_getString(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBundle* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBundle",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBundle*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCBundle_getString'", nullptr);
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
        const char* ret = cobj->getString(arg0);
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCBundle_getString'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCBundle_putBundle(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBundle* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBundle",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBundle*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCBundle_putBundle'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        cocos2d::CCBundle* arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_object<cocos2d::CCBundle>(tolua_S, 3, "cc.CCBundle",&arg1);
        if(!ok)
            return 0;
        cobj->putBundle(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "putBundle",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCBundle_putBundle'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCBundle_putShort(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBundle* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBundle",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBundle*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCBundle_putShort'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int32_t arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->putShort(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "putShort",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCBundle_putShort'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCBundle_putDouble(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBundle* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBundle",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBundle*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCBundle_putDouble'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        double arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->putDouble(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "putDouble",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCBundle_putDouble'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCBundle_putString(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBundle* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBundle",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBundle*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCBundle_putString'", nullptr);
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
        cobj->putString(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "putString",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCBundle_putString'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCBundle_putUInt(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBundle* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBundle",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBundle*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCBundle_putUInt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        unsigned int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_uint32(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->putUInt(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "putUInt",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCBundle_putUInt'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCBundle_getInt(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBundle* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBundle",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBundle*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCBundle_getInt'", nullptr);
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
        int ret = cobj->getInt(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getInt",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCBundle_getInt'.",&tolua_err);
#endif

    return 0;
}

int lua_cocos2dx_cocosbase_CCBundle_putObject(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBundle* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBundle",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBundle*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCBundle_putObject'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        cocos2d::Ref* arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 3, "cc.Ref",&arg1);
        if(!ok)
            return 0;
        cobj->putObject(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "putObject",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCBundle_putObject'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCBundle_getBundle(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBundle* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBundle",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBundle*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCBundle_getBundle'", nullptr);
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
        cocos2d::CCBundle* ret = cobj->getBundle(arg0);
        object_to_luaval<cocos2d::CCBundle>(tolua_S, "cc.CCBundle",(cocos2d::CCBundle*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBundle",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCBundle_getBundle'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCBundle_getUInt(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBundle* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBundle",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBundle*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCBundle_getUInt'", nullptr);
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
        unsigned int ret = cobj->getUInt(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getUInt",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCBundle_getUInt'.",&tolua_err);
#endif

    return 0;
}

int lua_cocos2dx_cocosbase_CCBundle_getShort(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBundle* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBundle",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBundle*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCBundle_getShort'", nullptr);
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
        int32_t ret = cobj->getShort(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getShort",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCBundle_getShort'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCBundle_putUShort(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBundle* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBundle",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBundle*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCBundle_putUShort'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        unsigned short arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_ushort(tolua_S, 3, &arg1);
        if(!ok)
            return 0;
        cobj->putUShort(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "putUShort",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCBundle_putUShort'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCBundle_getObject(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBundle* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBundle",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBundle*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCBundle_getObject'", nullptr);
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
        cocos2d::Ref* ret = cobj->getObject(arg0);
        object_to_luaval<cocos2d::Ref>(tolua_S, "cc.Ref",(cocos2d::Ref*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getObject",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCBundle_getObject'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCBundle_getDouble(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBundle* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCBundle",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCBundle*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCBundle_getDouble'", nullptr);
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
        double ret = cobj->getDouble(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDouble",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCBundle_getDouble'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCBundle_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCBundle",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocos2d::CCBundle* ret = cocos2d::CCBundle::create();
        object_to_luaval<cocos2d::CCBundle>(tolua_S, "cc.CCBundle",(cocos2d::CCBundle*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCBundle_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCBundle_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCBundle* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCBundle();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCBundle");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCBundle",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCBundle_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCBundle_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCBundle)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCBundle(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCBundle");
    tolua_cclass(tolua_S,"CCBundle","cc.CCBundle","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CCBundle");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCBundle_constructor);
        tolua_function(tolua_S,"putInt",lua_cocos2dx_cocosbase_CCBundle_putInt);
        tolua_function(tolua_S,"getUShort",lua_cocos2dx_cocosbase_CCBundle_getUShort);
        tolua_function(tolua_S,"getFloat",lua_cocos2dx_cocosbase_CCBundle_getFloat);
        tolua_function(tolua_S,"putFloat",lua_cocos2dx_cocosbase_CCBundle_putFloat);
        tolua_function(tolua_S,"getString",lua_cocos2dx_cocosbase_CCBundle_getString);
        tolua_function(tolua_S,"putBundle",lua_cocos2dx_cocosbase_CCBundle_putBundle);
        tolua_function(tolua_S,"putShort",lua_cocos2dx_cocosbase_CCBundle_putShort);
        tolua_function(tolua_S,"putDouble",lua_cocos2dx_cocosbase_CCBundle_putDouble);
        tolua_function(tolua_S,"putString",lua_cocos2dx_cocosbase_CCBundle_putString);
        tolua_function(tolua_S,"putUInt",lua_cocos2dx_cocosbase_CCBundle_putUInt);
        tolua_function(tolua_S,"getInt",lua_cocos2dx_cocosbase_CCBundle_getInt);
        tolua_function(tolua_S,"putObject",lua_cocos2dx_cocosbase_CCBundle_putObject);
        tolua_function(tolua_S,"getBundle",lua_cocos2dx_cocosbase_CCBundle_getBundle);
        tolua_function(tolua_S,"getUInt",lua_cocos2dx_cocosbase_CCBundle_getUInt);
        tolua_function(tolua_S,"getShort",lua_cocos2dx_cocosbase_CCBundle_getShort);
        tolua_function(tolua_S,"putUShort",lua_cocos2dx_cocosbase_CCBundle_putUShort);
        tolua_function(tolua_S,"getObject",lua_cocos2dx_cocosbase_CCBundle_getObject);
        tolua_function(tolua_S,"getDouble",lua_cocos2dx_cocosbase_CCBundle_getDouble);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCBundle_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCBundle).name();
    g_luaType[typeName] = "cc.CCBundle";
    g_typeCast["CCBundle"] = "cc.CCBundle";
    return 1;
}

int lua_cocos2dx_cocosbase_CSceneExtension_setAutoRemoveUnusedTexture(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneExtension* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneExtension",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneExtension*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneExtension_setAutoRemoveUnusedTexture'", nullptr);
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
        cobj->setAutoRemoveUnusedTexture(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAutoRemoveUnusedTexture",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneExtension_setAutoRemoveUnusedTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneExtension_setCachable(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneExtension* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneExtension",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneExtension*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneExtension_setCachable'", nullptr);
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
        cobj->setCachable(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCachable",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneExtension_setCachable'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneExtension_onLoadResources(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneExtension* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneExtension",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneExtension*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneExtension_onLoadResources'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->onLoadResources();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onLoadResources",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneExtension_onLoadResources'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneExtension_onLoadScene(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneExtension* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneExtension",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneExtension*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneExtension_onLoadScene'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->onLoadScene();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onLoadScene",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneExtension_onLoadScene'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneExtension_isLoaded(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneExtension* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneExtension",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneExtension*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneExtension_isLoaded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isLoaded();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isLoaded",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneExtension_isLoaded'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneExtension_addImage(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneExtension* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneExtension",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneExtension*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneExtension_addImage'", nullptr);
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
        cobj->addImage(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addImage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneExtension_addImage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneExtension_init(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneExtension* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneExtension",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneExtension*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneExtension_init'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneExtension_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneExtension_getClassName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneExtension* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneExtension",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneExtension*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneExtension_getClassName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getClassName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getClassName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneExtension_getClassName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneExtension_onLoadResourcesCompleted(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneExtension* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneExtension",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneExtension*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneExtension_onLoadResourcesCompleted'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->onLoadResourcesCompleted();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onLoadResourcesCompleted",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneExtension_onLoadResourcesCompleted'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneExtension_isAutoRemoveUnusedTexture(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneExtension* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneExtension",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneExtension*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneExtension_isAutoRemoveUnusedTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isAutoRemoveUnusedTexture();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isAutoRemoveUnusedTexture",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneExtension_isAutoRemoveUnusedTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneExtension_setExtraObject(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneExtension* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneExtension",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneExtension*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneExtension_setExtraObject'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Ref* arg0;

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0);
        if(!ok)
            return 0;
        cobj->setExtraObject(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setExtraObject",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneExtension_setExtraObject'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneExtension_addImageAsync(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneExtension* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneExtension",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneExtension*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneExtension_addImageAsync'", nullptr);
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
        cobj->addImageAsync(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addImageAsync",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneExtension_addImageAsync'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneExtension_getExtraObject(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneExtension* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneExtension",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneExtension*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneExtension_getExtraObject'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Ref* ret = cobj->getExtraObject();
        object_to_luaval<cocos2d::Ref>(tolua_S, "cc.Ref",(cocos2d::Ref*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getExtraObject",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneExtension_getExtraObject'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneExtension_isCachable(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneExtension* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneExtension",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneExtension*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneExtension_isCachable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isCachable();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isCachable",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneExtension_isCachable'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneExtension_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CSceneExtension",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocos2d::CSceneExtension* ret = cocos2d::CSceneExtension::create();
        object_to_luaval<cocos2d::CSceneExtension>(tolua_S, "cc.CSceneExtension",(cocos2d::CSceneExtension*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneExtension_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CSceneExtension_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneExtension* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CSceneExtension();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CSceneExtension");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CSceneExtension",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneExtension_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CSceneExtension_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CSceneExtension)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CSceneExtension(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CSceneExtension");
    tolua_cclass(tolua_S,"CSceneExtension","cc.CSceneExtension","ccw.CWidgetWindow",nullptr);

    tolua_beginmodule(tolua_S,"CSceneExtension");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CSceneExtension_constructor);
        tolua_function(tolua_S,"setAutoRemoveUnusedTexture",lua_cocos2dx_cocosbase_CSceneExtension_setAutoRemoveUnusedTexture);
        tolua_function(tolua_S,"setCachable",lua_cocos2dx_cocosbase_CSceneExtension_setCachable);
        tolua_function(tolua_S,"onLoadResources",lua_cocos2dx_cocosbase_CSceneExtension_onLoadResources);
        tolua_function(tolua_S,"onLoadScene",lua_cocos2dx_cocosbase_CSceneExtension_onLoadScene);
        tolua_function(tolua_S,"isLoaded",lua_cocos2dx_cocosbase_CSceneExtension_isLoaded);
        tolua_function(tolua_S,"addImage",lua_cocos2dx_cocosbase_CSceneExtension_addImage);
        tolua_function(tolua_S,"init",lua_cocos2dx_cocosbase_CSceneExtension_init);
        tolua_function(tolua_S,"getClassName",lua_cocos2dx_cocosbase_CSceneExtension_getClassName);
        tolua_function(tolua_S,"onLoadResourcesCompleted",lua_cocos2dx_cocosbase_CSceneExtension_onLoadResourcesCompleted);
        tolua_function(tolua_S,"isAutoRemoveUnusedTexture",lua_cocos2dx_cocosbase_CSceneExtension_isAutoRemoveUnusedTexture);
        tolua_function(tolua_S,"setExtraObject",lua_cocos2dx_cocosbase_CSceneExtension_setExtraObject);
        tolua_function(tolua_S,"addImageAsync",lua_cocos2dx_cocosbase_CSceneExtension_addImageAsync);
		tolua_function(tolua_S, "setOnLoadResourcesScriptHandler", lua_cocos2dx_cocosbase_CSceneExtension_setOnLoadResourcesScriptHandler);
		tolua_function(tolua_S, "setOnLoadResourcesCompletedScriptHandler", lua_cocos2dx_cocosbase_CSceneExtension_setOnLoadResourcesCompletedScriptHandler);
		tolua_function(tolua_S, "setOnLoadSceneScriptHandler", lua_cocos2dx_cocosbase_CSceneExtension_setOnLoadSceneScriptHandler);
		tolua_function(tolua_S, "setOnEnterSceneScriptHandler", lua_cocos2dx_cocosbase_CSceneExtension_setOnEnterSceneScriptHandler);
        tolua_function(tolua_S, "setOnLoadRescourcesProgressScriptHandler",lua_cocos2dx_cocosbase_CSceneExtension_setOnLoadResourcesProgressScriptHandler);
		tolua_function(tolua_S, "setOnExitSceneScriptHandler", lua_cocos2dx_cocosbase_CSceneExtension_setOnExitSceneScriptHandler);
		tolua_function(tolua_S,"getExtraObject",lua_cocos2dx_cocosbase_CSceneExtension_getExtraObject);
        tolua_function(tolua_S,"isCachable",lua_cocos2dx_cocosbase_CSceneExtension_isCachable);
		//tolua_function(tolua_S, "setOnMessageScriptHandler", lua_cocos2dx_cocosbase_CCMsgDelegate_setOnMessageScriptHandler);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CSceneExtension_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CSceneExtension).name();
    g_luaType[typeName] = "cc.CSceneExtension";
    g_typeCast["CSceneExtension"] = "cc.CSceneExtension";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionEase_easeActionWithAction(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionEase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionEase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionEase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionEase_easeActionWithAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::ActionInterval* arg0;

        ok &= luaval_to_object<cocos2d::ActionInterval>(tolua_S, 2, "cc.ActionInterval",&arg0);
        if(!ok)
            return 0;
        cocos2d::ActionInterval* ret = cobj->easeActionWithAction(arg0);
        object_to_luaval<cocos2d::ActionInterval>(tolua_S, "cc.ActionInterval",(cocos2d::ActionInterval*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "easeActionWithAction",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionEase_easeActionWithAction'.",&tolua_err);
#endif

    return 0;
}
static int lua_cocos2dx_cocosbase_CCSceneExTransitionEase_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionEase)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionEase(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionEase");
    tolua_cclass(tolua_S,"CCSceneExTransitionEase","cc.CCSceneExTransitionEase","",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionEase");
        tolua_function(tolua_S,"easeActionWithAction",lua_cocos2dx_cocosbase_CCSceneExTransitionEase_easeActionWithAction);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionEase).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionEase";
    g_typeCast["CCSceneExTransitionEase"] = "cc.CCSceneExTransitionEase";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransition_getInScene(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransition* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransition",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransition*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransition_getInScene'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::CSceneExtension* ret = cobj->getInScene();
        object_to_luaval<cocos2d::CSceneExtension>(tolua_S, "cc.CSceneExtension",(cocos2d::CSceneExtension*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getInScene",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransition_getInScene'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransition_draw(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransition* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransition",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransition*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransition_draw'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Renderer* arg0;
        cocos2d::Mat4 arg1;
        unsigned int arg2;

        ok &= luaval_to_object<cocos2d::Renderer>(tolua_S, 2, "cc.Renderer",&arg0);

        ok &= luaval_to_mat4(tolua_S, 3, &arg1);

        ok &= luaval_to_uint32(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cobj->draw(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "draw",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransition_draw'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransition_finish(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransition* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransition",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransition*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransition_finish'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->finish();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "finish",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransition_finish'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransition_initWithDuration(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransition* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransition",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransition*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransition_initWithDuration'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        if(!ok)
            return 0;
        bool ret = cobj->initWithDuration(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWithDuration",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransition_initWithDuration'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransition_cleanup(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransition* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransition",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransition*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransition_cleanup'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->cleanup();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cleanup",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransition_cleanup'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransition_hideOutShowIn(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransition* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransition",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransition*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransition_hideOutShowIn'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->hideOutShowIn();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "hideOutShowIn",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransition_hideOutShowIn'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransition_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransition",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransition* ret = cocos2d::CCSceneExTransition::create(arg0, arg1);
        object_to_luaval<cocos2d::CCSceneExTransition>(tolua_S, "cc.CCSceneExTransition",(cocos2d::CCSceneExTransition*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransition_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransition_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransition* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransition();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransition");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransition",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransition_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransition_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransition)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransition(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransition");
    tolua_cclass(tolua_S,"CCSceneExTransition","cc.CCSceneExTransition","cc.CSceneExtension",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransition");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransition_constructor);
        tolua_function(tolua_S,"getInScene",lua_cocos2dx_cocosbase_CCSceneExTransition_getInScene);
        tolua_function(tolua_S,"draw",lua_cocos2dx_cocosbase_CCSceneExTransition_draw);
        tolua_function(tolua_S,"finish",lua_cocos2dx_cocosbase_CCSceneExTransition_finish);
        tolua_function(tolua_S,"initWithDuration",lua_cocos2dx_cocosbase_CCSceneExTransition_initWithDuration);
        tolua_function(tolua_S,"cleanup",lua_cocos2dx_cocosbase_CCSceneExTransition_cleanup);
        tolua_function(tolua_S,"hideOutShowIn",lua_cocos2dx_cocosbase_CCSceneExTransition_hideOutShowIn);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransition_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransition).name();
    g_luaType[typeName] = "cc.CCSceneExTransition";
    g_typeCast["CCSceneExTransition"] = "cc.CCSceneExTransition";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionOriented_initWithDuration(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionOriented* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionOriented",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionOriented*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionOriented_initWithDuration'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        cocos2d::TransitionScene::Orientation arg2;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);
        if(!ok)
            return 0;
        bool ret = cobj->initWithDuration(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWithDuration",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionOriented_initWithDuration'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionOriented_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionOriented",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        cocos2d::TransitionScene::Orientation arg2;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransitionOriented* ret = cocos2d::CCSceneExTransitionOriented::create(arg0, arg1, arg2);
        object_to_luaval<cocos2d::CCSceneExTransitionOriented>(tolua_S, "cc.CCSceneExTransitionOriented",(cocos2d::CCSceneExTransitionOriented*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionOriented_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionOriented_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionOriented* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionOriented();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionOriented");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionOriented",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionOriented_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionOriented_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionOriented)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionOriented(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionOriented");
    tolua_cclass(tolua_S,"CCSceneExTransitionOriented","cc.CCSceneExTransitionOriented","cc.CCSceneExTransition",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionOriented");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionOriented_constructor);
        tolua_function(tolua_S,"initWithDuration",lua_cocos2dx_cocosbase_CCSceneExTransitionOriented_initWithDuration);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionOriented_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionOriented).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionOriented";
    g_typeCast["CCSceneExTransitionOriented"] = "cc.CCSceneExTransitionOriented";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionRotoZoom_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionRotoZoom",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransitionRotoZoom* ret = cocos2d::CCSceneExTransitionRotoZoom::create(arg0, arg1);
        object_to_luaval<cocos2d::CCSceneExTransitionRotoZoom>(tolua_S, "cc.CCSceneExTransitionRotoZoom",(cocos2d::CCSceneExTransitionRotoZoom*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionRotoZoom_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionRotoZoom_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionRotoZoom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionRotoZoom();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionRotoZoom");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionRotoZoom",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionRotoZoom_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionRotoZoom_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionRotoZoom)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionRotoZoom(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionRotoZoom");
    tolua_cclass(tolua_S,"CCSceneExTransitionRotoZoom","cc.CCSceneExTransitionRotoZoom","cc.CCSceneExTransition",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionRotoZoom");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionRotoZoom_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionRotoZoom_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionRotoZoom).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionRotoZoom";
    g_typeCast["CCSceneExTransitionRotoZoom"] = "cc.CCSceneExTransitionRotoZoom";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionJumpZoom_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionJumpZoom",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransitionJumpZoom* ret = cocos2d::CCSceneExTransitionJumpZoom::create(arg0, arg1);
        object_to_luaval<cocos2d::CCSceneExTransitionJumpZoom>(tolua_S, "cc.CCSceneExTransitionJumpZoom",(cocos2d::CCSceneExTransitionJumpZoom*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionJumpZoom_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionJumpZoom_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionJumpZoom* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionJumpZoom();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionJumpZoom");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionJumpZoom",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionJumpZoom_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionJumpZoom_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionJumpZoom)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionJumpZoom(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionJumpZoom");
    tolua_cclass(tolua_S,"CCSceneExTransitionJumpZoom","cc.CCSceneExTransitionJumpZoom","cc.CCSceneExTransition",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionJumpZoom");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionJumpZoom_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionJumpZoom_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionJumpZoom).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionJumpZoom";
    g_typeCast["CCSceneExTransitionJumpZoom"] = "cc.CCSceneExTransitionJumpZoom";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInL_action(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionMoveInL* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionMoveInL",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionMoveInL*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInL_action'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::ActionInterval* ret = cobj->action();
        object_to_luaval<cocos2d::ActionInterval>(tolua_S, "cc.ActionInterval",(cocos2d::ActionInterval*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "action",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInL_action'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInL_easeActionWithAction(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionMoveInL* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionMoveInL",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionMoveInL*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInL_easeActionWithAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::ActionInterval* arg0;

        ok &= luaval_to_object<cocos2d::ActionInterval>(tolua_S, 2, "cc.ActionInterval",&arg0);
        if(!ok)
            return 0;
        cocos2d::ActionInterval* ret = cobj->easeActionWithAction(arg0);
        object_to_luaval<cocos2d::ActionInterval>(tolua_S, "cc.ActionInterval",(cocos2d::ActionInterval*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "easeActionWithAction",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInL_easeActionWithAction'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInL_initScenes(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionMoveInL* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionMoveInL",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionMoveInL*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInL_initScenes'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->initScenes();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initScenes",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInL_initScenes'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInL_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionMoveInL",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransitionMoveInL* ret = cocos2d::CCSceneExTransitionMoveInL::create(arg0, arg1);
        object_to_luaval<cocos2d::CCSceneExTransitionMoveInL>(tolua_S, "cc.CCSceneExTransitionMoveInL",(cocos2d::CCSceneExTransitionMoveInL*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInL_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInL_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionMoveInL* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionMoveInL();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionMoveInL");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionMoveInL",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInL_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInL_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionMoveInL)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionMoveInL(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionMoveInL");
    tolua_cclass(tolua_S,"CCSceneExTransitionMoveInL","cc.CCSceneExTransitionMoveInL","cc.CCSceneExTransition",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionMoveInL");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInL_constructor);
        tolua_function(tolua_S,"action",lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInL_action);
        tolua_function(tolua_S,"easeActionWithAction",lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInL_easeActionWithAction);
        tolua_function(tolua_S,"initScenes",lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInL_initScenes);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInL_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionMoveInL).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionMoveInL";
    g_typeCast["CCSceneExTransitionMoveInL"] = "cc.CCSceneExTransitionMoveInL";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInR_initScenes(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionMoveInR* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionMoveInR",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionMoveInR*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInR_initScenes'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->initScenes();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initScenes",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInR_initScenes'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInR_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionMoveInR",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransitionMoveInR* ret = cocos2d::CCSceneExTransitionMoveInR::create(arg0, arg1);
        object_to_luaval<cocos2d::CCSceneExTransitionMoveInR>(tolua_S, "cc.CCSceneExTransitionMoveInR",(cocos2d::CCSceneExTransitionMoveInR*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInR_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInR_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionMoveInR* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionMoveInR();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionMoveInR");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionMoveInR",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInR_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInR_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionMoveInR)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionMoveInR(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionMoveInR");
    tolua_cclass(tolua_S,"CCSceneExTransitionMoveInR","cc.CCSceneExTransitionMoveInR","cc.CCSceneExTransitionMoveInL",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionMoveInR");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInR_constructor);
        tolua_function(tolua_S,"initScenes",lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInR_initScenes);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInR_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionMoveInR).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionMoveInR";
    g_typeCast["CCSceneExTransitionMoveInR"] = "cc.CCSceneExTransitionMoveInR";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInT_initScenes(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionMoveInT* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionMoveInT",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionMoveInT*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInT_initScenes'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->initScenes();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initScenes",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInT_initScenes'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInT_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionMoveInT",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransitionMoveInT* ret = cocos2d::CCSceneExTransitionMoveInT::create(arg0, arg1);
        object_to_luaval<cocos2d::CCSceneExTransitionMoveInT>(tolua_S, "cc.CCSceneExTransitionMoveInT",(cocos2d::CCSceneExTransitionMoveInT*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInT_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInT_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionMoveInT* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionMoveInT();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionMoveInT");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionMoveInT",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInT_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInT_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionMoveInT)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionMoveInT(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionMoveInT");
    tolua_cclass(tolua_S,"CCSceneExTransitionMoveInT","cc.CCSceneExTransitionMoveInT","cc.CCSceneExTransitionMoveInL",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionMoveInT");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInT_constructor);
        tolua_function(tolua_S,"initScenes",lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInT_initScenes);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInT_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionMoveInT).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionMoveInT";
    g_typeCast["CCSceneExTransitionMoveInT"] = "cc.CCSceneExTransitionMoveInT";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInB_initScenes(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionMoveInB* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionMoveInB",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionMoveInB*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInB_initScenes'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->initScenes();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initScenes",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInB_initScenes'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInB_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionMoveInB",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransitionMoveInB* ret = cocos2d::CCSceneExTransitionMoveInB::create(arg0, arg1);
        object_to_luaval<cocos2d::CCSceneExTransitionMoveInB>(tolua_S, "cc.CCSceneExTransitionMoveInB",(cocos2d::CCSceneExTransitionMoveInB*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInB_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInB_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionMoveInB* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionMoveInB();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionMoveInB");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionMoveInB",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInB_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInB_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionMoveInB)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionMoveInB(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionMoveInB");
    tolua_cclass(tolua_S,"CCSceneExTransitionMoveInB","cc.CCSceneExTransitionMoveInB","cc.CCSceneExTransitionMoveInL",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionMoveInB");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInB_constructor);
        tolua_function(tolua_S,"initScenes",lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInB_initScenes);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionMoveInB_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionMoveInB).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionMoveInB";
    g_typeCast["CCSceneExTransitionMoveInB"] = "cc.CCSceneExTransitionMoveInB";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInL_action(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionSlideInL* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionSlideInL",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionSlideInL*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInL_action'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::ActionInterval* ret = cobj->action();
        object_to_luaval<cocos2d::ActionInterval>(tolua_S, "cc.ActionInterval",(cocos2d::ActionInterval*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "action",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInL_action'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInL_easeActionWithAction(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionSlideInL* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionSlideInL",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionSlideInL*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInL_easeActionWithAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::ActionInterval* arg0;

        ok &= luaval_to_object<cocos2d::ActionInterval>(tolua_S, 2, "cc.ActionInterval",&arg0);
        if(!ok)
            return 0;
        cocos2d::ActionInterval* ret = cobj->easeActionWithAction(arg0);
        object_to_luaval<cocos2d::ActionInterval>(tolua_S, "cc.ActionInterval",(cocos2d::ActionInterval*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "easeActionWithAction",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInL_easeActionWithAction'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInL_initScenes(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionSlideInL* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionSlideInL",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionSlideInL*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInL_initScenes'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->initScenes();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initScenes",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInL_initScenes'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInL_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionSlideInL",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransitionSlideInL* ret = cocos2d::CCSceneExTransitionSlideInL::create(arg0, arg1);
        object_to_luaval<cocos2d::CCSceneExTransitionSlideInL>(tolua_S, "cc.CCSceneExTransitionSlideInL",(cocos2d::CCSceneExTransitionSlideInL*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInL_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInL_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionSlideInL* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionSlideInL();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionSlideInL");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionSlideInL",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInL_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInL_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionSlideInL)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionSlideInL(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionSlideInL");
    tolua_cclass(tolua_S,"CCSceneExTransitionSlideInL","cc.CCSceneExTransitionSlideInL","cc.CCSceneExTransition",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionSlideInL");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInL_constructor);
        tolua_function(tolua_S,"action",lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInL_action);
        tolua_function(tolua_S,"easeActionWithAction",lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInL_easeActionWithAction);
        tolua_function(tolua_S,"initScenes",lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInL_initScenes);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInL_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionSlideInL).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionSlideInL";
    g_typeCast["CCSceneExTransitionSlideInL"] = "cc.CCSceneExTransitionSlideInL";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInR_action(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionSlideInR* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionSlideInR",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionSlideInR*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInR_action'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::ActionInterval* ret = cobj->action();
        object_to_luaval<cocos2d::ActionInterval>(tolua_S, "cc.ActionInterval",(cocos2d::ActionInterval*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "action",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInR_action'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInR_initScenes(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionSlideInR* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionSlideInR",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionSlideInR*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInR_initScenes'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->initScenes();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initScenes",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInR_initScenes'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInR_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionSlideInR",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransitionSlideInR* ret = cocos2d::CCSceneExTransitionSlideInR::create(arg0, arg1);
        object_to_luaval<cocos2d::CCSceneExTransitionSlideInR>(tolua_S, "cc.CCSceneExTransitionSlideInR",(cocos2d::CCSceneExTransitionSlideInR*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInR_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInR_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionSlideInR* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionSlideInR();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionSlideInR");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionSlideInR",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInR_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInR_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionSlideInR)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionSlideInR(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionSlideInR");
    tolua_cclass(tolua_S,"CCSceneExTransitionSlideInR","cc.CCSceneExTransitionSlideInR","cc.CCSceneExTransitionSlideInL",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionSlideInR");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInR_constructor);
        tolua_function(tolua_S,"action",lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInR_action);
        tolua_function(tolua_S,"initScenes",lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInR_initScenes);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInR_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionSlideInR).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionSlideInR";
    g_typeCast["CCSceneExTransitionSlideInR"] = "cc.CCSceneExTransitionSlideInR";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInB_action(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionSlideInB* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionSlideInB",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionSlideInB*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInB_action'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::ActionInterval* ret = cobj->action();
        object_to_luaval<cocos2d::ActionInterval>(tolua_S, "cc.ActionInterval",(cocos2d::ActionInterval*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "action",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInB_action'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInB_initScenes(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionSlideInB* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionSlideInB",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionSlideInB*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInB_initScenes'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->initScenes();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initScenes",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInB_initScenes'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInB_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionSlideInB",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransitionSlideInB* ret = cocos2d::CCSceneExTransitionSlideInB::create(arg0, arg1);
        object_to_luaval<cocos2d::CCSceneExTransitionSlideInB>(tolua_S, "cc.CCSceneExTransitionSlideInB",(cocos2d::CCSceneExTransitionSlideInB*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInB_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInB_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionSlideInB* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionSlideInB();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionSlideInB");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionSlideInB",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInB_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInB_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionSlideInB)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionSlideInB(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionSlideInB");
    tolua_cclass(tolua_S,"CCSceneExTransitionSlideInB","cc.CCSceneExTransitionSlideInB","cc.CCSceneExTransitionSlideInL",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionSlideInB");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInB_constructor);
        tolua_function(tolua_S,"action",lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInB_action);
        tolua_function(tolua_S,"initScenes",lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInB_initScenes);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInB_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionSlideInB).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionSlideInB";
    g_typeCast["CCSceneExTransitionSlideInB"] = "cc.CCSceneExTransitionSlideInB";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInT_action(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionSlideInT* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionSlideInT",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionSlideInT*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInT_action'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::ActionInterval* ret = cobj->action();
        object_to_luaval<cocos2d::ActionInterval>(tolua_S, "cc.ActionInterval",(cocos2d::ActionInterval*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "action",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInT_action'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInT_initScenes(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionSlideInT* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionSlideInT",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionSlideInT*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInT_initScenes'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->initScenes();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initScenes",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInT_initScenes'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInT_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionSlideInT",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransitionSlideInT* ret = cocos2d::CCSceneExTransitionSlideInT::create(arg0, arg1);
        object_to_luaval<cocos2d::CCSceneExTransitionSlideInT>(tolua_S, "cc.CCSceneExTransitionSlideInT",(cocos2d::CCSceneExTransitionSlideInT*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInT_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInT_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionSlideInT* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionSlideInT();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionSlideInT");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionSlideInT",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInT_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInT_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionSlideInT)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionSlideInT(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionSlideInT");
    tolua_cclass(tolua_S,"CCSceneExTransitionSlideInT","cc.CCSceneExTransitionSlideInT","cc.CCSceneExTransitionSlideInL",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionSlideInT");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInT_constructor);
        tolua_function(tolua_S,"action",lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInT_action);
        tolua_function(tolua_S,"initScenes",lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInT_initScenes);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionSlideInT_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionSlideInT).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionSlideInT";
    g_typeCast["CCSceneExTransitionSlideInT"] = "cc.CCSceneExTransitionSlideInT";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionShrinkGrow_easeActionWithAction(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionShrinkGrow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionShrinkGrow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionShrinkGrow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionShrinkGrow_easeActionWithAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::ActionInterval* arg0;

        ok &= luaval_to_object<cocos2d::ActionInterval>(tolua_S, 2, "cc.ActionInterval",&arg0);
        if(!ok)
            return 0;
        cocos2d::ActionInterval* ret = cobj->easeActionWithAction(arg0);
        object_to_luaval<cocos2d::ActionInterval>(tolua_S, "cc.ActionInterval",(cocos2d::ActionInterval*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "easeActionWithAction",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionShrinkGrow_easeActionWithAction'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionShrinkGrow_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionShrinkGrow",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransitionShrinkGrow* ret = cocos2d::CCSceneExTransitionShrinkGrow::create(arg0, arg1);
        object_to_luaval<cocos2d::CCSceneExTransitionShrinkGrow>(tolua_S, "cc.CCSceneExTransitionShrinkGrow",(cocos2d::CCSceneExTransitionShrinkGrow*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionShrinkGrow_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionShrinkGrow_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionShrinkGrow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionShrinkGrow();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionShrinkGrow");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionShrinkGrow",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionShrinkGrow_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionShrinkGrow_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionShrinkGrow)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionShrinkGrow(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionShrinkGrow");
    tolua_cclass(tolua_S,"CCSceneExTransitionShrinkGrow","cc.CCSceneExTransitionShrinkGrow","cc.CCSceneExTransition",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionShrinkGrow");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionShrinkGrow_constructor);
        tolua_function(tolua_S,"easeActionWithAction",lua_cocos2dx_cocosbase_CCSceneExTransitionShrinkGrow_easeActionWithAction);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionShrinkGrow_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionShrinkGrow).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionShrinkGrow";
    g_typeCast["CCSceneExTransitionShrinkGrow"] = "cc.CCSceneExTransitionShrinkGrow";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionFlipX_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionFlipX",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0);
            if (!ok) { break; }
            cocos2d::CSceneExtension* arg1;
            ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
            if (!ok) { break; }
            cocos2d::CCSceneExTransitionFlipX* ret = cocos2d::CCSceneExTransitionFlipX::create(arg0, arg1);
            object_to_luaval<cocos2d::CCSceneExTransitionFlipX>(tolua_S, "cc.CCSceneExTransitionFlipX",(cocos2d::CCSceneExTransitionFlipX*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0);
            if (!ok) { break; }
            cocos2d::CSceneExtension* arg1;
            ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
            if (!ok) { break; }
            cocos2d::TransitionScene::Orientation arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);
            if (!ok) { break; }
            cocos2d::CCSceneExTransitionFlipX* ret = cocos2d::CCSceneExTransitionFlipX::create(arg0, arg1, arg2);
            object_to_luaval<cocos2d::CCSceneExTransitionFlipX>(tolua_S, "cc.CCSceneExTransitionFlipX",(cocos2d::CCSceneExTransitionFlipX*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionFlipX_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionFlipX_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionFlipX* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionFlipX();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionFlipX");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionFlipX",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionFlipX_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionFlipX_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionFlipX)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionFlipX(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionFlipX");
    tolua_cclass(tolua_S,"CCSceneExTransitionFlipX","cc.CCSceneExTransitionFlipX","cc.CCSceneExTransitionOriented",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionFlipX");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionFlipX_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionFlipX_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionFlipX).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionFlipX";
    g_typeCast["CCSceneExTransitionFlipX"] = "cc.CCSceneExTransitionFlipX";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionFlipY_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionFlipY",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0);
            if (!ok) { break; }
            cocos2d::CSceneExtension* arg1;
            ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
            if (!ok) { break; }
            cocos2d::CCSceneExTransitionFlipY* ret = cocos2d::CCSceneExTransitionFlipY::create(arg0, arg1);
            object_to_luaval<cocos2d::CCSceneExTransitionFlipY>(tolua_S, "cc.CCSceneExTransitionFlipY",(cocos2d::CCSceneExTransitionFlipY*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0);
            if (!ok) { break; }
            cocos2d::CSceneExtension* arg1;
            ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
            if (!ok) { break; }
            cocos2d::TransitionScene::Orientation arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);
            if (!ok) { break; }
            cocos2d::CCSceneExTransitionFlipY* ret = cocos2d::CCSceneExTransitionFlipY::create(arg0, arg1, arg2);
            object_to_luaval<cocos2d::CCSceneExTransitionFlipY>(tolua_S, "cc.CCSceneExTransitionFlipY",(cocos2d::CCSceneExTransitionFlipY*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionFlipY_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionFlipY_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionFlipY* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionFlipY();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionFlipY");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionFlipY",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionFlipY_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionFlipY_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionFlipY)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionFlipY(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionFlipY");
    tolua_cclass(tolua_S,"CCSceneExTransitionFlipY","cc.CCSceneExTransitionFlipY","cc.CCSceneExTransitionOriented",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionFlipY");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionFlipY_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionFlipY_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionFlipY).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionFlipY";
    g_typeCast["CCSceneExTransitionFlipY"] = "cc.CCSceneExTransitionFlipY";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionFlipAngular_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionFlipAngular",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0);
            if (!ok) { break; }
            cocos2d::CSceneExtension* arg1;
            ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
            if (!ok) { break; }
            cocos2d::CCSceneExTransitionFlipAngular* ret = cocos2d::CCSceneExTransitionFlipAngular::create(arg0, arg1);
            object_to_luaval<cocos2d::CCSceneExTransitionFlipAngular>(tolua_S, "cc.CCSceneExTransitionFlipAngular",(cocos2d::CCSceneExTransitionFlipAngular*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0);
            if (!ok) { break; }
            cocos2d::CSceneExtension* arg1;
            ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
            if (!ok) { break; }
            cocos2d::TransitionScene::Orientation arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);
            if (!ok) { break; }
            cocos2d::CCSceneExTransitionFlipAngular* ret = cocos2d::CCSceneExTransitionFlipAngular::create(arg0, arg1, arg2);
            object_to_luaval<cocos2d::CCSceneExTransitionFlipAngular>(tolua_S, "cc.CCSceneExTransitionFlipAngular",(cocos2d::CCSceneExTransitionFlipAngular*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionFlipAngular_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionFlipAngular_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionFlipAngular* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionFlipAngular();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionFlipAngular");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionFlipAngular",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionFlipAngular_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionFlipAngular_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionFlipAngular)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionFlipAngular(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionFlipAngular");
    tolua_cclass(tolua_S,"CCSceneExTransitionFlipAngular","cc.CCSceneExTransitionFlipAngular","cc.CCSceneExTransitionOriented",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionFlipAngular");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionFlipAngular_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionFlipAngular_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionFlipAngular).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionFlipAngular";
    g_typeCast["CCSceneExTransitionFlipAngular"] = "cc.CCSceneExTransitionFlipAngular";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionZoomFlipX_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionZoomFlipX",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0);
            if (!ok) { break; }
            cocos2d::CSceneExtension* arg1;
            ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
            if (!ok) { break; }
            cocos2d::CCSceneExTransitionZoomFlipX* ret = cocos2d::CCSceneExTransitionZoomFlipX::create(arg0, arg1);
            object_to_luaval<cocos2d::CCSceneExTransitionZoomFlipX>(tolua_S, "cc.CCSceneExTransitionZoomFlipX",(cocos2d::CCSceneExTransitionZoomFlipX*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0);
            if (!ok) { break; }
            cocos2d::CSceneExtension* arg1;
            ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
            if (!ok) { break; }
            cocos2d::TransitionScene::Orientation arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);
            if (!ok) { break; }
            cocos2d::CCSceneExTransitionZoomFlipX* ret = cocos2d::CCSceneExTransitionZoomFlipX::create(arg0, arg1, arg2);
            object_to_luaval<cocos2d::CCSceneExTransitionZoomFlipX>(tolua_S, "cc.CCSceneExTransitionZoomFlipX",(cocos2d::CCSceneExTransitionZoomFlipX*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionZoomFlipX_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionZoomFlipX_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionZoomFlipX* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionZoomFlipX();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionZoomFlipX");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionZoomFlipX",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionZoomFlipX_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionZoomFlipX_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionZoomFlipX)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionZoomFlipX(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionZoomFlipX");
    tolua_cclass(tolua_S,"CCSceneExTransitionZoomFlipX","cc.CCSceneExTransitionZoomFlipX","cc.CCSceneExTransitionOriented",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionZoomFlipX");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionZoomFlipX_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionZoomFlipX_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionZoomFlipX).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionZoomFlipX";
    g_typeCast["CCSceneExTransitionZoomFlipX"] = "cc.CCSceneExTransitionZoomFlipX";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionZoomFlipY_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionZoomFlipY",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0);
            if (!ok) { break; }
            cocos2d::CSceneExtension* arg1;
            ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
            if (!ok) { break; }
            cocos2d::CCSceneExTransitionZoomFlipY* ret = cocos2d::CCSceneExTransitionZoomFlipY::create(arg0, arg1);
            object_to_luaval<cocos2d::CCSceneExTransitionZoomFlipY>(tolua_S, "cc.CCSceneExTransitionZoomFlipY",(cocos2d::CCSceneExTransitionZoomFlipY*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0);
            if (!ok) { break; }
            cocos2d::CSceneExtension* arg1;
            ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
            if (!ok) { break; }
            cocos2d::TransitionScene::Orientation arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);
            if (!ok) { break; }
            cocos2d::CCSceneExTransitionZoomFlipY* ret = cocos2d::CCSceneExTransitionZoomFlipY::create(arg0, arg1, arg2);
            object_to_luaval<cocos2d::CCSceneExTransitionZoomFlipY>(tolua_S, "cc.CCSceneExTransitionZoomFlipY",(cocos2d::CCSceneExTransitionZoomFlipY*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionZoomFlipY_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionZoomFlipY_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionZoomFlipY* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionZoomFlipY();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionZoomFlipY");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionZoomFlipY",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionZoomFlipY_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionZoomFlipY_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionZoomFlipY)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionZoomFlipY(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionZoomFlipY");
    tolua_cclass(tolua_S,"CCSceneExTransitionZoomFlipY","cc.CCSceneExTransitionZoomFlipY","cc.CCSceneExTransitionOriented",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionZoomFlipY");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionZoomFlipY_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionZoomFlipY_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionZoomFlipY).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionZoomFlipY";
    g_typeCast["CCSceneExTransitionZoomFlipY"] = "cc.CCSceneExTransitionZoomFlipY";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionZoomFlipAngular_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionZoomFlipAngular",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0);
            if (!ok) { break; }
            cocos2d::CSceneExtension* arg1;
            ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
            if (!ok) { break; }
            cocos2d::CCSceneExTransitionZoomFlipAngular* ret = cocos2d::CCSceneExTransitionZoomFlipAngular::create(arg0, arg1);
            object_to_luaval<cocos2d::CCSceneExTransitionZoomFlipAngular>(tolua_S, "cc.CCSceneExTransitionZoomFlipAngular",(cocos2d::CCSceneExTransitionZoomFlipAngular*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0);
            if (!ok) { break; }
            cocos2d::CSceneExtension* arg1;
            ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
            if (!ok) { break; }
            cocos2d::TransitionScene::Orientation arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);
            if (!ok) { break; }
            cocos2d::CCSceneExTransitionZoomFlipAngular* ret = cocos2d::CCSceneExTransitionZoomFlipAngular::create(arg0, arg1, arg2);
            object_to_luaval<cocos2d::CCSceneExTransitionZoomFlipAngular>(tolua_S, "cc.CCSceneExTransitionZoomFlipAngular",(cocos2d::CCSceneExTransitionZoomFlipAngular*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionZoomFlipAngular_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionZoomFlipAngular_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionZoomFlipAngular* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionZoomFlipAngular();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionZoomFlipAngular");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionZoomFlipAngular",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionZoomFlipAngular_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionZoomFlipAngular_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionZoomFlipAngular)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionZoomFlipAngular(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionZoomFlipAngular");
    tolua_cclass(tolua_S,"CCSceneExTransitionZoomFlipAngular","cc.CCSceneExTransitionZoomFlipAngular","cc.CCSceneExTransitionOriented",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionZoomFlipAngular");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionZoomFlipAngular_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionZoomFlipAngular_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionZoomFlipAngular).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionZoomFlipAngular";
    g_typeCast["CCSceneExTransitionZoomFlipAngular"] = "cc.CCSceneExTransitionZoomFlipAngular";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionFade_initWithDuration(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionFade* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionFade",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::CCSceneExTransitionFade*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionFade_initWithDuration'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0);

            if (!ok) { break; }
            cocos2d::CSceneExtension* arg1;
            ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);

            if (!ok) { break; }
            bool ret = cobj->initWithDuration(arg0, arg1);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 3) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0);

            if (!ok) { break; }
            cocos2d::CSceneExtension* arg1;
            ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);

            if (!ok) { break; }
            cocos2d::Color3B arg2;
            ok &= luaval_to_color3b(tolua_S, 4, &arg2);

            if (!ok) { break; }
            bool ret = cobj->initWithDuration(arg0, arg1, arg2);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWithDuration",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionFade_initWithDuration'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionFade_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionFade",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0);
            if (!ok) { break; }
            cocos2d::CSceneExtension* arg1;
            ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
            if (!ok) { break; }
            cocos2d::CCSceneExTransitionFade* ret = cocos2d::CCSceneExTransitionFade::create(arg0, arg1);
            object_to_luaval<cocos2d::CCSceneExTransitionFade>(tolua_S, "cc.CCSceneExTransitionFade",(cocos2d::CCSceneExTransitionFade*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0);
            if (!ok) { break; }
            cocos2d::CSceneExtension* arg1;
            ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
            if (!ok) { break; }
            cocos2d::Color3B arg2;
            ok &= luaval_to_color3b(tolua_S, 4, &arg2);
            if (!ok) { break; }
            cocos2d::CCSceneExTransitionFade* ret = cocos2d::CCSceneExTransitionFade::create(arg0, arg1, arg2);
            object_to_luaval<cocos2d::CCSceneExTransitionFade>(tolua_S, "cc.CCSceneExTransitionFade",(cocos2d::CCSceneExTransitionFade*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionFade_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionFade_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionFade* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionFade();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionFade");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionFade",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionFade_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionFade_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionFade)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionFade(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionFade");
    tolua_cclass(tolua_S,"CCSceneExTransitionFade","cc.CCSceneExTransitionFade","cc.CCSceneExTransition",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionFade");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionFade_constructor);
        tolua_function(tolua_S,"initWithDuration",lua_cocos2dx_cocosbase_CCSceneExTransitionFade_initWithDuration);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionFade_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionFade).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionFade";
    g_typeCast["CCSceneExTransitionFade"] = "cc.CCSceneExTransitionFade";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionCrossFade_draw(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionCrossFade* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionCrossFade",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionCrossFade*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionCrossFade_draw'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Renderer* arg0;
        cocos2d::Mat4 arg1;
        unsigned int arg2;

        ok &= luaval_to_object<cocos2d::Renderer>(tolua_S, 2, "cc.Renderer",&arg0);

        ok &= luaval_to_mat4(tolua_S, 3, &arg1);

        ok &= luaval_to_uint32(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cobj->draw(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "draw",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionCrossFade_draw'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionCrossFade_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionCrossFade",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransitionCrossFade* ret = cocos2d::CCSceneExTransitionCrossFade::create(arg0, arg1);
        object_to_luaval<cocos2d::CCSceneExTransitionCrossFade>(tolua_S, "cc.CCSceneExTransitionCrossFade",(cocos2d::CCSceneExTransitionCrossFade*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionCrossFade_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionCrossFade_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionCrossFade* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionCrossFade();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionCrossFade");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionCrossFade",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionCrossFade_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionCrossFade_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionCrossFade)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionCrossFade(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionCrossFade");
    tolua_cclass(tolua_S,"CCSceneExTransitionCrossFade","cc.CCSceneExTransitionCrossFade","cc.CCSceneExTransition",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionCrossFade");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionCrossFade_constructor);
        tolua_function(tolua_S,"draw",lua_cocos2dx_cocosbase_CCSceneExTransitionCrossFade_draw);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionCrossFade_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionCrossFade).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionCrossFade";
    g_typeCast["CCSceneExTransitionCrossFade"] = "cc.CCSceneExTransitionCrossFade";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionTurnOffTiles_sceneOrder(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionTurnOffTiles* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionTurnOffTiles",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionTurnOffTiles*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionTurnOffTiles_sceneOrder'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->sceneOrder();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "sceneOrder",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionTurnOffTiles_sceneOrder'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionTurnOffTiles_easeActionWithAction(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionTurnOffTiles* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionTurnOffTiles",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionTurnOffTiles*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionTurnOffTiles_easeActionWithAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::ActionInterval* arg0;

        ok &= luaval_to_object<cocos2d::ActionInterval>(tolua_S, 2, "cc.ActionInterval",&arg0);
        if(!ok)
            return 0;
        cocos2d::ActionInterval* ret = cobj->easeActionWithAction(arg0);
        object_to_luaval<cocos2d::ActionInterval>(tolua_S, "cc.ActionInterval",(cocos2d::ActionInterval*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "easeActionWithAction",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionTurnOffTiles_easeActionWithAction'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionTurnOffTiles_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionTurnOffTiles",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransitionTurnOffTiles* ret = cocos2d::CCSceneExTransitionTurnOffTiles::create(arg0, arg1);
        object_to_luaval<cocos2d::CCSceneExTransitionTurnOffTiles>(tolua_S, "cc.CCSceneExTransitionTurnOffTiles",(cocos2d::CCSceneExTransitionTurnOffTiles*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionTurnOffTiles_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionTurnOffTiles_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionTurnOffTiles* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionTurnOffTiles();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionTurnOffTiles");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionTurnOffTiles",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionTurnOffTiles_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionTurnOffTiles_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionTurnOffTiles)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionTurnOffTiles(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionTurnOffTiles");
    tolua_cclass(tolua_S,"CCSceneExTransitionTurnOffTiles","cc.CCSceneExTransitionTurnOffTiles","cc.CCSceneExTransition",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionTurnOffTiles");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionTurnOffTiles_constructor);
        tolua_function(tolua_S,"sceneOrder",lua_cocos2dx_cocosbase_CCSceneExTransitionTurnOffTiles_sceneOrder);
        tolua_function(tolua_S,"easeActionWithAction",lua_cocos2dx_cocosbase_CCSceneExTransitionTurnOffTiles_easeActionWithAction);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionTurnOffTiles_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionTurnOffTiles).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionTurnOffTiles";
    g_typeCast["CCSceneExTransitionTurnOffTiles"] = "cc.CCSceneExTransitionTurnOffTiles";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionSplitCols_action(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionSplitCols* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionSplitCols",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionSplitCols*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSplitCols_action'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::ActionInterval* ret = cobj->action();
        object_to_luaval<cocos2d::ActionInterval>(tolua_S, "cc.ActionInterval",(cocos2d::ActionInterval*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "action",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSplitCols_action'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionSplitCols_easeActionWithAction(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionSplitCols* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionSplitCols",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionSplitCols*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSplitCols_easeActionWithAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::ActionInterval* arg0;

        ok &= luaval_to_object<cocos2d::ActionInterval>(tolua_S, 2, "cc.ActionInterval",&arg0);
        if(!ok)
            return 0;
        cocos2d::ActionInterval* ret = cobj->easeActionWithAction(arg0);
        object_to_luaval<cocos2d::ActionInterval>(tolua_S, "cc.ActionInterval",(cocos2d::ActionInterval*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "easeActionWithAction",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSplitCols_easeActionWithAction'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionSplitCols_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionSplitCols",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransitionSplitCols* ret = cocos2d::CCSceneExTransitionSplitCols::create(arg0, arg1);
        object_to_luaval<cocos2d::CCSceneExTransitionSplitCols>(tolua_S, "cc.CCSceneExTransitionSplitCols",(cocos2d::CCSceneExTransitionSplitCols*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSplitCols_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionSplitCols_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionSplitCols* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionSplitCols();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionSplitCols");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionSplitCols",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSplitCols_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionSplitCols_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionSplitCols)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionSplitCols(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionSplitCols");
    tolua_cclass(tolua_S,"CCSceneExTransitionSplitCols","cc.CCSceneExTransitionSplitCols","cc.CCSceneExTransition",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionSplitCols");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionSplitCols_constructor);
        tolua_function(tolua_S,"action",lua_cocos2dx_cocosbase_CCSceneExTransitionSplitCols_action);
        tolua_function(tolua_S,"easeActionWithAction",lua_cocos2dx_cocosbase_CCSceneExTransitionSplitCols_easeActionWithAction);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionSplitCols_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionSplitCols).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionSplitCols";
    g_typeCast["CCSceneExTransitionSplitCols"] = "cc.CCSceneExTransitionSplitCols";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionSplitRows_action(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionSplitRows* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionSplitRows",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionSplitRows*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSplitRows_action'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::ActionInterval* ret = cobj->action();
        object_to_luaval<cocos2d::ActionInterval>(tolua_S, "cc.ActionInterval",(cocos2d::ActionInterval*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "action",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSplitRows_action'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionSplitRows_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionSplitRows",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransitionSplitRows* ret = cocos2d::CCSceneExTransitionSplitRows::create(arg0, arg1);
        object_to_luaval<cocos2d::CCSceneExTransitionSplitRows>(tolua_S, "cc.CCSceneExTransitionSplitRows",(cocos2d::CCSceneExTransitionSplitRows*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSplitRows_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionSplitRows_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionSplitRows* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionSplitRows();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionSplitRows");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionSplitRows",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionSplitRows_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionSplitRows_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionSplitRows)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionSplitRows(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionSplitRows");
    tolua_cclass(tolua_S,"CCSceneExTransitionSplitRows","cc.CCSceneExTransitionSplitRows","cc.CCSceneExTransitionSplitCols",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionSplitRows");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionSplitRows_constructor);
        tolua_function(tolua_S,"action",lua_cocos2dx_cocosbase_CCSceneExTransitionSplitRows_action);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionSplitRows_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionSplitRows).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionSplitRows";
    g_typeCast["CCSceneExTransitionSplitRows"] = "cc.CCSceneExTransitionSplitRows";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionFadeTR_easeActionWithAction(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionFadeTR* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionFadeTR",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionFadeTR*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionFadeTR_easeActionWithAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::ActionInterval* arg0;

        ok &= luaval_to_object<cocos2d::ActionInterval>(tolua_S, 2, "cc.ActionInterval",&arg0);
        if(!ok)
            return 0;
        cocos2d::ActionInterval* ret = cobj->easeActionWithAction(arg0);
        object_to_luaval<cocos2d::ActionInterval>(tolua_S, "cc.ActionInterval",(cocos2d::ActionInterval*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "easeActionWithAction",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionFadeTR_easeActionWithAction'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionFadeTR_actionWithSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionFadeTR* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionFadeTR",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionFadeTR*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionFadeTR_actionWithSize'", nullptr);
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
        cocos2d::ActionInterval* ret = cobj->actionWithSize(arg0);
        object_to_luaval<cocos2d::ActionInterval>(tolua_S, "cc.ActionInterval",(cocos2d::ActionInterval*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "actionWithSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionFadeTR_actionWithSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionFadeTR_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionFadeTR",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransitionFadeTR* ret = cocos2d::CCSceneExTransitionFadeTR::create(arg0, arg1);
        object_to_luaval<cocos2d::CCSceneExTransitionFadeTR>(tolua_S, "cc.CCSceneExTransitionFadeTR",(cocos2d::CCSceneExTransitionFadeTR*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionFadeTR_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionFadeTR_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionFadeTR* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionFadeTR();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionFadeTR");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionFadeTR",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionFadeTR_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionFadeTR_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionFadeTR)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionFadeTR(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionFadeTR");
    tolua_cclass(tolua_S,"CCSceneExTransitionFadeTR","cc.CCSceneExTransitionFadeTR","cc.CCSceneExTransition",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionFadeTR");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionFadeTR_constructor);
        tolua_function(tolua_S,"easeActionWithAction",lua_cocos2dx_cocosbase_CCSceneExTransitionFadeTR_easeActionWithAction);
        tolua_function(tolua_S,"actionWithSize",lua_cocos2dx_cocosbase_CCSceneExTransitionFadeTR_actionWithSize);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionFadeTR_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionFadeTR).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionFadeTR";
    g_typeCast["CCSceneExTransitionFadeTR"] = "cc.CCSceneExTransitionFadeTR";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionFadeBL_actionWithSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionFadeBL* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionFadeBL",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionFadeBL*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionFadeBL_actionWithSize'", nullptr);
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
        cocos2d::ActionInterval* ret = cobj->actionWithSize(arg0);
        object_to_luaval<cocos2d::ActionInterval>(tolua_S, "cc.ActionInterval",(cocos2d::ActionInterval*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "actionWithSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionFadeBL_actionWithSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionFadeBL_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionFadeBL",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransitionFadeBL* ret = cocos2d::CCSceneExTransitionFadeBL::create(arg0, arg1);
        object_to_luaval<cocos2d::CCSceneExTransitionFadeBL>(tolua_S, "cc.CCSceneExTransitionFadeBL",(cocos2d::CCSceneExTransitionFadeBL*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionFadeBL_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionFadeBL_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionFadeBL* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionFadeBL();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionFadeBL");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionFadeBL",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionFadeBL_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionFadeBL_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionFadeBL)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionFadeBL(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionFadeBL");
    tolua_cclass(tolua_S,"CCSceneExTransitionFadeBL","cc.CCSceneExTransitionFadeBL","cc.CCSceneExTransitionFadeTR",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionFadeBL");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionFadeBL_constructor);
        tolua_function(tolua_S,"actionWithSize",lua_cocos2dx_cocosbase_CCSceneExTransitionFadeBL_actionWithSize);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionFadeBL_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionFadeBL).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionFadeBL";
    g_typeCast["CCSceneExTransitionFadeBL"] = "cc.CCSceneExTransitionFadeBL";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionFadeUp_actionWithSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionFadeUp* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionFadeUp",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionFadeUp*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionFadeUp_actionWithSize'", nullptr);
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
        cocos2d::ActionInterval* ret = cobj->actionWithSize(arg0);
        object_to_luaval<cocos2d::ActionInterval>(tolua_S, "cc.ActionInterval",(cocos2d::ActionInterval*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "actionWithSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionFadeUp_actionWithSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionFadeUp_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionFadeUp",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransitionFadeUp* ret = cocos2d::CCSceneExTransitionFadeUp::create(arg0, arg1);
        object_to_luaval<cocos2d::CCSceneExTransitionFadeUp>(tolua_S, "cc.CCSceneExTransitionFadeUp",(cocos2d::CCSceneExTransitionFadeUp*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionFadeUp_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionFadeUp_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionFadeUp* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionFadeUp();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionFadeUp");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionFadeUp",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionFadeUp_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionFadeUp_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionFadeUp)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionFadeUp(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionFadeUp");
    tolua_cclass(tolua_S,"CCSceneExTransitionFadeUp","cc.CCSceneExTransitionFadeUp","cc.CCSceneExTransitionFadeTR",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionFadeUp");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionFadeUp_constructor);
        tolua_function(tolua_S,"actionWithSize",lua_cocos2dx_cocosbase_CCSceneExTransitionFadeUp_actionWithSize);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionFadeUp_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionFadeUp).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionFadeUp";
    g_typeCast["CCSceneExTransitionFadeUp"] = "cc.CCSceneExTransitionFadeUp";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionFadeDown_actionWithSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionFadeDown* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionFadeDown",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionFadeDown*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionFadeDown_actionWithSize'", nullptr);
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
        cocos2d::ActionInterval* ret = cobj->actionWithSize(arg0);
        object_to_luaval<cocos2d::ActionInterval>(tolua_S, "cc.ActionInterval",(cocos2d::ActionInterval*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "actionWithSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionFadeDown_actionWithSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionFadeDown_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionFadeDown",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransitionFadeDown* ret = cocos2d::CCSceneExTransitionFadeDown::create(arg0, arg1);
        object_to_luaval<cocos2d::CCSceneExTransitionFadeDown>(tolua_S, "cc.CCSceneExTransitionFadeDown",(cocos2d::CCSceneExTransitionFadeDown*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionFadeDown_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionFadeDown_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionFadeDown* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionFadeDown();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionFadeDown");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionFadeDown",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionFadeDown_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionFadeDown_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionFadeDown)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionFadeDown(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionFadeDown");
    tolua_cclass(tolua_S,"CCSceneExTransitionFadeDown","cc.CCSceneExTransitionFadeDown","cc.CCSceneExTransitionFadeTR",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionFadeDown");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionFadeDown_constructor);
        tolua_function(tolua_S,"actionWithSize",lua_cocos2dx_cocosbase_CCSceneExTransitionFadeDown_actionWithSize);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionFadeDown_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionFadeDown).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionFadeDown";
    g_typeCast["CCSceneExTransitionFadeDown"] = "cc.CCSceneExTransitionFadeDown";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionPageTurn_actionWithSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionPageTurn* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionPageTurn",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionPageTurn*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionPageTurn_actionWithSize'", nullptr);
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
        cocos2d::ActionInterval* ret = cobj->actionWithSize(arg0);
        object_to_luaval<cocos2d::ActionInterval>(tolua_S, "cc.ActionInterval",(cocos2d::ActionInterval*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "actionWithSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionPageTurn_actionWithSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionPageTurn_initWithDuration(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionPageTurn* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CCSceneExTransitionPageTurn",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CCSceneExTransitionPageTurn*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionPageTurn_initWithDuration'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        bool arg2;

        ok &= luaval_to_number(tolua_S, 2,&arg0);

        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);

        ok &= luaval_to_boolean(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        bool ret = cobj->initWithDuration(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWithDuration",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionPageTurn_initWithDuration'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionPageTurn_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionPageTurn",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        bool arg2;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        ok &= luaval_to_boolean(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransitionPageTurn* ret = cocos2d::CCSceneExTransitionPageTurn::create(arg0, arg1, arg2);
        object_to_luaval<cocos2d::CCSceneExTransitionPageTurn>(tolua_S, "cc.CCSceneExTransitionPageTurn",(cocos2d::CCSceneExTransitionPageTurn*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionPageTurn_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionPageTurn_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionPageTurn* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionPageTurn();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionPageTurn");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionPageTurn",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionPageTurn_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionPageTurn_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionPageTurn)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionPageTurn(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionPageTurn");
    tolua_cclass(tolua_S,"CCSceneExTransitionPageTurn","cc.CCSceneExTransitionPageTurn","cc.CCSceneExTransition",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionPageTurn");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionPageTurn_constructor);
        tolua_function(tolua_S,"actionWithSize",lua_cocos2dx_cocosbase_CCSceneExTransitionPageTurn_actionWithSize);
        tolua_function(tolua_S,"initWithDuration",lua_cocos2dx_cocosbase_CCSceneExTransitionPageTurn_initWithDuration);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionPageTurn_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionPageTurn).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionPageTurn";
    g_typeCast["CCSceneExTransitionPageTurn"] = "cc.CCSceneExTransitionPageTurn";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionProgress_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionProgress",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransitionProgress* ret = cocos2d::CCSceneExTransitionProgress::create(arg0, arg1);
        object_to_luaval<cocos2d::CCSceneExTransitionProgress>(tolua_S, "cc.CCSceneExTransitionProgress",(cocos2d::CCSceneExTransitionProgress*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionProgress_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosbase_CCSceneExTransitionProgress_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CCSceneExTransitionProgress* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::CCSceneExTransitionProgress();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.CCSceneExTransitionProgress");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCSceneExTransitionProgress",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionProgress_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosbase_CCSceneExTransitionProgress_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionProgress)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionProgress(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionProgress");
    tolua_cclass(tolua_S,"CCSceneExTransitionProgress","cc.CCSceneExTransitionProgress","cc.CCSceneExTransition",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionProgress");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosbase_CCSceneExTransitionProgress_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionProgress_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionProgress).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionProgress";
    g_typeCast["CCSceneExTransitionProgress"] = "cc.CCSceneExTransitionProgress";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionProgressRadialCCW_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionProgressRadialCCW",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransitionProgressRadialCCW* ret = cocos2d::CCSceneExTransitionProgressRadialCCW::create(arg0, arg1);
        object_to_luaval<cocos2d::CCSceneExTransitionProgressRadialCCW>(tolua_S, "cc.CCSceneExTransitionProgressRadialCCW",(cocos2d::CCSceneExTransitionProgressRadialCCW*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionProgressRadialCCW_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_cocosbase_CCSceneExTransitionProgressRadialCCW_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionProgressRadialCCW)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionProgressRadialCCW(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionProgressRadialCCW");
    tolua_cclass(tolua_S,"CCSceneExTransitionProgressRadialCCW","cc.CCSceneExTransitionProgressRadialCCW","cc.CCSceneExTransitionProgress",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionProgressRadialCCW");
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionProgressRadialCCW_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionProgressRadialCCW).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionProgressRadialCCW";
    g_typeCast["CCSceneExTransitionProgressRadialCCW"] = "cc.CCSceneExTransitionProgressRadialCCW";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionProgressRadialCW_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionProgressRadialCW",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransitionProgressRadialCW* ret = cocos2d::CCSceneExTransitionProgressRadialCW::create(arg0, arg1);
        object_to_luaval<cocos2d::CCSceneExTransitionProgressRadialCW>(tolua_S, "cc.CCSceneExTransitionProgressRadialCW",(cocos2d::CCSceneExTransitionProgressRadialCW*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionProgressRadialCW_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_cocosbase_CCSceneExTransitionProgressRadialCW_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionProgressRadialCW)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionProgressRadialCW(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionProgressRadialCW");
    tolua_cclass(tolua_S,"CCSceneExTransitionProgressRadialCW","cc.CCSceneExTransitionProgressRadialCW","cc.CCSceneExTransitionProgress",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionProgressRadialCW");
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionProgressRadialCW_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionProgressRadialCW).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionProgressRadialCW";
    g_typeCast["CCSceneExTransitionProgressRadialCW"] = "cc.CCSceneExTransitionProgressRadialCW";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionProgressHorizontal_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionProgressHorizontal",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransitionProgressHorizontal* ret = cocos2d::CCSceneExTransitionProgressHorizontal::create(arg0, arg1);
        object_to_luaval<cocos2d::CCSceneExTransitionProgressHorizontal>(tolua_S, "cc.CCSceneExTransitionProgressHorizontal",(cocos2d::CCSceneExTransitionProgressHorizontal*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionProgressHorizontal_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_cocosbase_CCSceneExTransitionProgressHorizontal_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionProgressHorizontal)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionProgressHorizontal(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionProgressHorizontal");
    tolua_cclass(tolua_S,"CCSceneExTransitionProgressHorizontal","cc.CCSceneExTransitionProgressHorizontal","cc.CCSceneExTransitionProgress",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionProgressHorizontal");
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionProgressHorizontal_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionProgressHorizontal).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionProgressHorizontal";
    g_typeCast["CCSceneExTransitionProgressHorizontal"] = "cc.CCSceneExTransitionProgressHorizontal";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionProgressVertical_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionProgressVertical",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransitionProgressVertical* ret = cocos2d::CCSceneExTransitionProgressVertical::create(arg0, arg1);
        object_to_luaval<cocos2d::CCSceneExTransitionProgressVertical>(tolua_S, "cc.CCSceneExTransitionProgressVertical",(cocos2d::CCSceneExTransitionProgressVertical*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionProgressVertical_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_cocosbase_CCSceneExTransitionProgressVertical_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionProgressVertical)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionProgressVertical(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionProgressVertical");
    tolua_cclass(tolua_S,"CCSceneExTransitionProgressVertical","cc.CCSceneExTransitionProgressVertical","cc.CCSceneExTransitionProgress",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionProgressVertical");
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionProgressVertical_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionProgressVertical).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionProgressVertical";
    g_typeCast["CCSceneExTransitionProgressVertical"] = "cc.CCSceneExTransitionProgressVertical";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionProgressInOut_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionProgressInOut",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransitionProgressInOut* ret = cocos2d::CCSceneExTransitionProgressInOut::create(arg0, arg1);
        object_to_luaval<cocos2d::CCSceneExTransitionProgressInOut>(tolua_S, "cc.CCSceneExTransitionProgressInOut",(cocos2d::CCSceneExTransitionProgressInOut*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionProgressInOut_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_cocosbase_CCSceneExTransitionProgressInOut_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionProgressInOut)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionProgressInOut(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionProgressInOut");
    tolua_cclass(tolua_S,"CCSceneExTransitionProgressInOut","cc.CCSceneExTransitionProgressInOut","cc.CCSceneExTransitionProgress",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionProgressInOut");
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionProgressInOut_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionProgressInOut).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionProgressInOut";
    g_typeCast["CCSceneExTransitionProgressInOut"] = "cc.CCSceneExTransitionProgressInOut";
    return 1;
}

int lua_cocos2dx_cocosbase_CCSceneExTransitionProgressOutIn_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CCSceneExTransitionProgressOutIn",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        cocos2d::CSceneExtension* arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 3, "cc.CSceneExtension",&arg1);
        if(!ok)
            return 0;
        cocos2d::CCSceneExTransitionProgressOutIn* ret = cocos2d::CCSceneExTransitionProgressOutIn::create(arg0, arg1);
        object_to_luaval<cocos2d::CCSceneExTransitionProgressOutIn>(tolua_S, "cc.CCSceneExTransitionProgressOutIn",(cocos2d::CCSceneExTransitionProgressOutIn*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CCSceneExTransitionProgressOutIn_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_cocosbase_CCSceneExTransitionProgressOutIn_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSceneExTransitionProgressOutIn)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CCSceneExTransitionProgressOutIn(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CCSceneExTransitionProgressOutIn");
    tolua_cclass(tolua_S,"CCSceneExTransitionProgressOutIn","cc.CCSceneExTransitionProgressOutIn","cc.CCSceneExTransitionProgress",nullptr);

    tolua_beginmodule(tolua_S,"CCSceneExTransitionProgressOutIn");
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosbase_CCSceneExTransitionProgressOutIn_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CCSceneExTransitionProgressOutIn).name();
    g_luaType[typeName] = "cc.CCSceneExTransitionProgressOutIn";
    g_typeCast["CCSceneExTransitionProgressOutIn"] = "cc.CCSceneExTransitionProgressOutIn";
    return 1;
}

int lua_cocos2dx_cocosbase_CSceneManager_removeUnusedCachedScenes(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneManager_removeUnusedCachedScenes'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeUnusedCachedScenes();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeUnusedCachedScenes",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneManager_removeUnusedCachedScenes'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneManager_popToSceneStackLevel(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneManager_popToSceneStackLevel'", nullptr);
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
        cobj->popToSceneStackLevel(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        int arg0;
        cocos2d::Ref* arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 3, "cc.Ref",&arg1);
        if(!ok)
            return 0;
        cobj->popToSceneStackLevel(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "popToSceneStackLevel",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneManager_popToSceneStackLevel'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneManager_isSendCleanupToScene(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneManager_isSendCleanupToScene'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isSendCleanupToScene();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isSendCleanupToScene",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneManager_isSendCleanupToScene'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneManager_getRunningScene(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneManager_getRunningScene'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::CSceneExtension* ret = cobj->getRunningScene();
        object_to_luaval<cocos2d::CSceneExtension>(tolua_S, "cc.CSceneExtension",(cocos2d::CSceneExtension*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getRunningScene",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneManager_getRunningScene'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneManager_popToRootScene(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneManager_popToRootScene'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->popToRootScene();
        return 0;
    }
    if (argc == 1) 
    {
        cocos2d::Ref* arg0;

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0);
        if(!ok)
            return 0;
        cobj->popToRootScene(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "popToRootScene",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneManager_popToRootScene'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneManager_isSceneRunning(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneManager_isSceneRunning'", nullptr);
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
        bool ret = cobj->isSceneRunning(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isSceneRunning",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneManager_isSceneRunning'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneManager_seekScene(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneManager_seekScene'", nullptr);
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
        cocos2d::CSceneExtension* ret = cobj->seekScene(arg0);
        object_to_luaval<cocos2d::CSceneExtension>(tolua_S, "cc.CSceneExtension",(cocos2d::CSceneExtension*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "seekScene",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneManager_seekScene'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneManager_removeAllCachedScenes(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneManager_removeAllCachedScenes'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeAllCachedScenes();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeAllCachedScenes",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneManager_removeAllCachedScenes'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneManager_removeCachedScene(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneManager_removeCachedScene'", nullptr);
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
        cobj->removeCachedScene(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeCachedScene",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneManager_removeCachedScene'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneManager_end(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneManager_end'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->end();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "end",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneManager_end'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneManager_runWithScene(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneManager_runWithScene'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
	if (argc == 1)
	{
		cocos2d::CSceneExtension* arg0;

		ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 2, "cc.CSceneExtension", &arg0);
		if (!ok)
            return 0;
        cobj->runWithScene(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        cocos2d::CSceneExtension* arg0;
        cocos2d::Ref* arg1;

        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 2, "cc.CSceneExtension",&arg0);

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 3, "cc.Ref",&arg1);
        if(!ok)
            return 0;
        cobj->runWithScene(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "runWithScene",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneManager_runWithScene'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneManager_popUIScene(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneManager_popUIScene'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::CSceneExtension* arg0;

        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 2, "cc.CSceneExtension",&arg0);
        if(!ok)
            return 0;
        cobj->popUIScene(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "popUIScene",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneManager_popUIScene'.",&tolua_err);
#endif

    return 0;
}

int lua_cocos2dx_cocosbase_CSceneManager_popSuspendScene(lua_State* tolua_S)
{
	int argc = 0;
	cocos2d::CSceneManager* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "cc.CSceneManager", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (cocos2d::CSceneManager*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneManager_popSuspendScene'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		cocos2d::CSceneExtension* arg0;

		ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 2, "cc.CSceneExtension", &arg0);
		if (!ok)
			return 0;
		cobj->popSuspendScene(arg0);
		return 0;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "popSuspendScene", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_cocosbase_CSceneManager_popSuspendScene'.", &tolua_err);
#endif

	return 0;
}

int lua_cocos2dx_cocosbase_CSceneManager_getTouchPriority(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneManager_getTouchPriority'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneManager_getTouchPriority'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneManager_loadScene(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneManager_loadScene'", nullptr);
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
        cocos2d::CSceneExtension* ret = cobj->loadScene(arg0);
        object_to_luaval<cocos2d::CSceneExtension>(tolua_S, "cc.CSceneExtension",(cocos2d::CSceneExtension*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "loadScene",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneManager_loadScene'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneManager_popAllUIScene(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneManager_popAllUIScene'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->popAllUIScene();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "popAllUIScene",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneManager_popAllUIScene'.",&tolua_err);
#endif

    return 0;
}

int lua_cocos2dx_cocosbase_CSceneManager_popAllSuspendScene(lua_State* tolua_S)
{
	int argc = 0;
	cocos2d::CSceneManager* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "cc.CSceneManager", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (cocos2d::CSceneManager*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneManager_popAllSuspendScene'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{
		if (!ok)
			return 0;
		cobj->popAllSuspendScene();
		return 0;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "popAllSuspendScene", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_cocosbase_CSceneManager_popAllSuspendScene'.", &tolua_err);
#endif

	return 0;
}

int lua_cocos2dx_cocosbase_CSceneManager_runSuspendScene(lua_State* tolua_S)
{
	int argc = 0;
	cocos2d::CSceneManager* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "cc.CSceneManager", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (cocos2d::CSceneManager*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneManager_runSuspendScene'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		cocos2d::CSceneExtension* arg0;

		ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 2, "cc.CSceneExtension", &arg0);
		if (!ok)
			return 0;
		cobj->runSuspendScene(arg0);
		return 0;
	}
	if (argc == 2)
	{
		cocos2d::CSceneExtension* arg0;
		cocos2d::Ref* arg1;

		ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 2, "cc.CSceneExtension", &arg0);

		ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 3, "cc.Ref", &arg1);
		if (!ok)
			return 0;
		cobj->runSuspendScene(arg0, arg1);
		return 0;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "runSuspendScene", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_cocosbase_CSceneManager_runSuspendScene'.", &tolua_err);
#endif

	return 0;
}

int lua_cocos2dx_cocosbase_CSceneManager_runUIScene(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneManager_runUIScene'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::CSceneExtension* arg0;

        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 2, "cc.CSceneExtension",&arg0);
        if(!ok)
            return 0;
        cobj->runUIScene(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        cocos2d::CSceneExtension* arg0;
        cocos2d::Ref* arg1;

        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 2, "cc.CSceneExtension",&arg0);

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 3, "cc.Ref",&arg1);
        if(!ok)
            return 0;
        cobj->runUIScene(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "runUIScene",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneManager_runUIScene'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneManager_replaceScene(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneManager_replaceScene'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::CSceneExtension* arg0;

        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 2, "cc.CSceneExtension",&arg0);
        if(!ok)
            return 0;
        cobj->replaceScene(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        cocos2d::CSceneExtension* arg0;
        cocos2d::Ref* arg1;

        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 2, "cc.CSceneExtension",&arg0);

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 3, "cc.Ref",&arg1);
        if(!ok)
            return 0;
        cobj->replaceScene(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "replaceScene",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneManager_replaceScene'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneManager_pushScene(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneManager_pushScene'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::CSceneExtension* arg0;

        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 2, "cc.CSceneExtension",&arg0);
        if(!ok)
            return 0;
        cobj->pushScene(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        cocos2d::CSceneExtension* arg0;
        cocos2d::Ref* arg1;

        ok &= luaval_to_object<cocos2d::CSceneExtension>(tolua_S, 2, "cc.CSceneExtension",&arg0);

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 3, "cc.Ref",&arg1);
        if(!ok)
            return 0;
        cobj->pushScene(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "pushScene",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneManager_pushScene'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneManager_popScene(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CSceneManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CSceneManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CSceneManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosbase_CSceneManager_popScene'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->popScene();
        return 0;
    }
    if (argc == 1) 
    {
        cocos2d::Ref* arg0;

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0);
        if(!ok)
            return 0;
        cobj->popScene(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "popScene",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneManager_popScene'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosbase_CSceneManager_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CSceneManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocos2d::CSceneManager* ret = cocos2d::CSceneManager::getInstance();
        object_to_luaval<cocos2d::CSceneManager>(tolua_S, "cc.CSceneManager",(cocos2d::CSceneManager*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosbase_CSceneManager_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_cocosbase_CSceneManager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CSceneManager)");
    return 0;
}

int lua_register_cocos2dx_cocosbase_CSceneManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CSceneManager");
    tolua_cclass(tolua_S,"CSceneManager","cc.CSceneManager","cc.Scene",nullptr);

    tolua_beginmodule(tolua_S,"CSceneManager");
        tolua_function(tolua_S,"registerSceneClassScriptFunc",lua_cocos2dx_cocosbase_CSceneManager_registerSceneClassScriptFunc);
        tolua_function(tolua_S,"removeUnusedCachedScenes",lua_cocos2dx_cocosbase_CSceneManager_removeUnusedCachedScenes);
        tolua_function(tolua_S,"popToSceneStackLevel",lua_cocos2dx_cocosbase_CSceneManager_popToSceneStackLevel);
        tolua_function(tolua_S,"isSendCleanupToScene",lua_cocos2dx_cocosbase_CSceneManager_isSendCleanupToScene);
        tolua_function(tolua_S,"getRunningScene",lua_cocos2dx_cocosbase_CSceneManager_getRunningScene);
        tolua_function(tolua_S,"popToRootScene",lua_cocos2dx_cocosbase_CSceneManager_popToRootScene);
        tolua_function(tolua_S,"isSceneRunning",lua_cocos2dx_cocosbase_CSceneManager_isSceneRunning);
        tolua_function(tolua_S,"seekScene",lua_cocos2dx_cocosbase_CSceneManager_seekScene);
        tolua_function(tolua_S,"removeAllCachedScenes",lua_cocos2dx_cocosbase_CSceneManager_removeAllCachedScenes);
        tolua_function(tolua_S,"removeCachedScene",lua_cocos2dx_cocosbase_CSceneManager_removeCachedScene);
        tolua_function(tolua_S,"end",lua_cocos2dx_cocosbase_CSceneManager_end);
        tolua_function(tolua_S,"runWithScene",lua_cocos2dx_cocosbase_CSceneManager_runWithScene);
        tolua_function(tolua_S,"popUIScene",lua_cocos2dx_cocosbase_CSceneManager_popUIScene);
		tolua_function(tolua_S, "popSuspendScene", lua_cocos2dx_cocosbase_CSceneManager_popSuspendScene);
        tolua_function(tolua_S,"getTouchPriority",lua_cocos2dx_cocosbase_CSceneManager_getTouchPriority);
        tolua_function(tolua_S,"loadScene",lua_cocos2dx_cocosbase_CSceneManager_loadScene);
        tolua_function(tolua_S,"popAllUIScene",lua_cocos2dx_cocosbase_CSceneManager_popAllUIScene);
		tolua_function(tolua_S, "popAllSuspendScene", lua_cocos2dx_cocosbase_CSceneManager_popAllSuspendScene);
        tolua_function(tolua_S,"runUIScene",lua_cocos2dx_cocosbase_CSceneManager_runUIScene);
		tolua_function(tolua_S, "runSuspendScene", lua_cocos2dx_cocosbase_CSceneManager_runSuspendScene);
        tolua_function(tolua_S,"replaceScene",lua_cocos2dx_cocosbase_CSceneManager_replaceScene);
        tolua_function(tolua_S,"pushScene",lua_cocos2dx_cocosbase_CSceneManager_pushScene);
        tolua_function(tolua_S,"popScene",lua_cocos2dx_cocosbase_CSceneManager_popScene);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_cocosbase_CSceneManager_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CSceneManager).name();
    g_luaType[typeName] = "cc.CSceneManager";
    g_typeCast["CSceneManager"] = "cc.CSceneManager";
    return 1;
}
TOLUA_API int register_all_cocos2dx_cocosbase(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,nullptr,0);
	tolua_beginmodule(tolua_S, nullptr);

	lua_register_cocos2dx_cocosbase_CCMsgDelegate(tolua_S);
	lua_register_cocos2dx_cocosbase_CSceneExtension(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransition(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionOriented(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionZoomFlipX(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionZoomFlipY(tolua_S);
	lua_register_cocos2dx_cocosbase_CCBundle(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionProgress(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionProgressOutIn(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionProgressVertical(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionFlipAngular(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionEase(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionTurnOffTiles(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionProgressRadialCCW(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionCrossFade(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionFadeTR(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionFadeDown(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionSplitCols(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionSplitRows(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionFade(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionProgressInOut(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionRotoZoom(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionPageTurn(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionProgressRadialCW(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionSlideInL(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionSlideInB(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionMoveInL(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionFadeUp(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionMoveInB(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionZoomFlipAngular(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionJumpZoom(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionSlideInR(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionSlideInT(tolua_S);
	lua_register_cocos2dx_cocosbase_CSceneManager(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionMoveInR(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionMoveInT(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionProgressHorizontal(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionShrinkGrow(tolua_S);
	lua_register_cocos2dx_cocosbase_CCMsgManager(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionFadeBL(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionFlipY(tolua_S);
	lua_register_cocos2dx_cocosbase_CCSceneExTransitionFlipX(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

