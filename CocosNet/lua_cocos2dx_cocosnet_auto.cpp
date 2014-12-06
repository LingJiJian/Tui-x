#include "lua_cocos2dx_cocosnet_auto.hpp"
#include "cocos-net.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"

#define LUA_COCOS2DX_COCOSNET_SCRIPT_HANDLER( __WIDGET__, __SET_HANDLER__)         \
	int lua_cocos2dx_cocosnet_##__WIDGET__##_##__SET_HANDLER__(lua_State* tolua_S)       \
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

LUA_COCOS2DX_COCOSNET_SCRIPT_HANDLER(CNetDelegate, setOnMessageReceivedScriptHandler)
LUA_COCOS2DX_COCOSNET_SCRIPT_HANDLER(CNetDelegate, setOnExceptionCaughtScriptHandler)
LUA_COCOS2DX_COCOSNET_SCRIPT_HANDLER(CNetDelegate, setOnConnectedScriptHandler)
LUA_COCOS2DX_COCOSNET_SCRIPT_HANDLER(CNetDelegate, setOnConnectTimeoutScriptHandler)
LUA_COCOS2DX_COCOSNET_SCRIPT_HANDLER(CNetDelegate, setOnDisconnectedScriptHandler)

int lua_cocos2dx_cocosnet_CBuffer_readUChar(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_readUChar'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        uint16_t ret = cobj->readUChar();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "readUChar",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_readUChar'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_setWriterIndex(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_setWriterIndex'", nullptr);
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
        cobj->setWriterIndex(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setWriterIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_setWriterIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_readFloat(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_readFloat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->readFloat();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "readFloat",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_readFloat'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_writeData(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_writeData'", nullptr);
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
        cobj->writeData(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "writeData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_writeData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_writeString(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_writeString'", nullptr);
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
        cobj->writeString(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "writeString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_writeString'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_writeShort(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_writeShort'", nullptr);
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
        cobj->writeShort(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "writeShort",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_writeShort'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_readWholeData(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_readWholeData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        char* ret = cobj->readWholeData();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "readWholeData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_readWholeData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_readData(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_readData'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = (char*)arg0_tmp.c_str();

            if (!ok) { break; }
            unsigned int arg1;
            ok &= luaval_to_uint32(tolua_S, 3,&arg1);

            if (!ok) { break; }
            cobj->readData(arg0, arg1);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0);

            if (!ok) { break; }
            cocos2d::CBuffer* ret = cobj->readData(arg0);
            object_to_luaval<cocos2d::CBuffer>(tolua_S, "cc.CBuffer",(cocos2d::CBuffer*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "readData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_readData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_writeDouble(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_writeDouble'", nullptr);
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
        cobj->writeDouble(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "writeDouble",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_writeDouble'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_getBufferSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_getBufferSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        unsigned int ret = cobj->getBufferSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBufferSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_getBufferSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_readChar(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_readChar'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int32_t ret = cobj->readChar();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "readChar",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_readChar'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_markReaderIndex(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_markReaderIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->markReaderIndex();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "markReaderIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_markReaderIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_moveRight(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_moveRight'", nullptr);
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
        cobj->moveRight(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "moveRight",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_moveRight'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_readLongLong(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_readLongLong'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        long long ret = cobj->readLongLong();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "readLongLong",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_readLongLong'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_readUShort(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_readUShort'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        unsigned short ret = cobj->readUShort();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "readUShort",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_readUShort'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_getReadableSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_getReadableSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        unsigned int ret = cobj->getReadableSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getReadableSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_getReadableSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_getReaderIndex(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_getReaderIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        unsigned int ret = cobj->getReaderIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getReaderIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_getReaderIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_capacity(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_capacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        unsigned int ret = cobj->capacity();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "capacity",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_capacity'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_getWriterIndex(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_getWriterIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        unsigned int ret = cobj->getWriterIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getWriterIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_getWriterIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_readUInt(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_readUInt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        unsigned int ret = cobj->readUInt();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "readUInt",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_readUInt'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_discardReadContent(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_discardReadContent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->discardReadContent();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "discardReadContent",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_discardReadContent'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_writeUChar(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_writeUChar'", nullptr);
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
        cobj->writeUChar(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "writeUChar",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_writeUChar'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_setReaderIndex(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_setReaderIndex'", nullptr);
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
        cobj->setReaderIndex(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setReaderIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_setReaderIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_writeLengthAndData(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_writeLengthAndData'", nullptr);
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
        cobj->writeLengthAndData(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "writeLengthAndData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_writeLengthAndData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_writeFloat(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_writeFloat'", nullptr);
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
        cobj->writeFloat(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "writeFloat",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_writeFloat'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_readULongLong(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_readULongLong'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        unsigned long long ret = cobj->readULongLong();
        #pragma warning NO CONVERSION FROM NATIVE FOR unsigned long long;
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "readULongLong",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_readULongLong'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_getContentSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_getContentSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        unsigned int ret = cobj->getContentSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getContentSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_getContentSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_readLengthAndString(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_readLengthAndString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        std::string ret = cobj->readLengthAndString();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "readLengthAndString",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_readLengthAndString'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_moveWriterIndexToBack(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_moveWriterIndexToBack'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->moveWriterIndexToBack();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "moveWriterIndexToBack",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_moveWriterIndexToBack'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_writeUInt(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_writeUInt'", nullptr);
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
        cobj->writeUInt(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "writeUInt",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_writeUInt'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_empty(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_empty'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->empty();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "empty",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_empty'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_writeLengthAndString(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_writeLengthAndString'", nullptr);
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
        cobj->writeLengthAndString(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "writeLengthAndString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_writeLengthAndString'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_moveLeft(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_moveLeft'", nullptr);
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
        cobj->moveLeft(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "moveLeft",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_moveLeft'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_readShort(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_readShort'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int32_t ret = cobj->readShort();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "readShort",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_readShort'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_writeChar(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_writeChar'", nullptr);
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
        cobj->writeChar(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "writeChar",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_writeChar'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_readInt(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_readInt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->readInt();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "readInt",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_readInt'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_moveReaderIndexToFront(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_moveReaderIndexToFront'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->moveReaderIndexToFront();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "moveReaderIndexToFront",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_moveReaderIndexToFront'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_moveWriterIndexToFront(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_moveWriterIndexToFront'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->moveWriterIndexToFront();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "moveWriterIndexToFront",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_moveWriterIndexToFront'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_readDouble(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_readDouble'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        double ret = cobj->readDouble();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "readDouble",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_readDouble'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_copy(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_copy'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Ref* ret = cobj->copy();
        object_to_luaval<cocos2d::Ref>(tolua_S, "cc.Ref",(cocos2d::Ref*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "copy",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_copy'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_data(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_data'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        char* ret = cobj->data();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "data",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_data'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_readString(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_readString'", nullptr);
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
        std::string ret = cobj->readString(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "readString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_readString'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_reset(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_reset'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_reset'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_writeUShort(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_writeUShort'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->writeUShort(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "writeUShort",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_writeUShort'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_moveReaderIndexToBack(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_moveReaderIndexToBack'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->moveReaderIndexToBack();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "moveReaderIndexToBack",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_moveReaderIndexToBack'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_clear(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_clear'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_clear'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_writeULongLong(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_writeULongLong'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned long long arg0;

        #pragma warning NO CONVERSION TO NATIVE FOR unsigned long long;
        if(!ok)
            return 0;
        cobj->writeULongLong(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "writeULongLong",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_writeULongLong'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_skipData(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_skipData'", nullptr);
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
        cobj->skipData(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "skipData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_skipData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_length(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_length'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        unsigned int ret = cobj->length();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "length",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_length'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_resetReaderIndex(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_resetReaderIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->resetReaderIndex();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "resetReaderIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_resetReaderIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_isReadable(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_isReadable'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0);

            if (!ok) { break; }
            bool ret = cobj->isReadable(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            bool ret = cobj->isReadable();
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isReadable",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_isReadable'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_writeInt(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_writeInt'", nullptr);
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
        cobj->writeInt(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "writeInt",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_writeInt'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_writeLongLong(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CBuffer_writeLongLong'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        long long arg0;

        ok &= luaval_to_long_long(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->writeLongLong(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "writeLongLong",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_writeLongLong'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.CBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0);
            if (!ok) { break; }
            cocos2d::CBuffer* ret = cocos2d::CBuffer::create(arg0);
            object_to_luaval<cocos2d::CBuffer>(tolua_S, "cc.CBuffer",(cocos2d::CBuffer*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            cocos2d::CBuffer* ret = cocos2d::CBuffer::create();
            object_to_luaval<cocos2d::CBuffer>(tolua_S, "cc.CBuffer",(cocos2d::CBuffer*)ret);
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
            unsigned int arg1;
            ok &= luaval_to_uint32(tolua_S, 3,&arg1);
            if (!ok) { break; }
            cocos2d::CBuffer* ret = cocos2d::CBuffer::create(arg0, arg1);
            object_to_luaval<cocos2d::CBuffer>(tolua_S, "cc.CBuffer",(cocos2d::CBuffer*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_cocosnet_CBuffer_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CBuffer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0);

            if (!ok) { break; }
            cobj = new cocos2d::CBuffer(arg0);
            tolua_pushusertype(tolua_S,(void*)cobj,"cc.CBuffer");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            cobj = new cocos2d::CBuffer();
            tolua_pushusertype(tolua_S,(void*)cobj,"cc.CBuffer");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            unsigned int arg1;
            ok &= luaval_to_uint32(tolua_S, 3,&arg1);

            if (!ok) { break; }
            cobj = new cocos2d::CBuffer(arg0, arg1);
            tolua_pushusertype(tolua_S,(void*)cobj,"cc.CBuffer");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CBuffer",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CBuffer_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosnet_CBuffer_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CBuffer)");
    return 0;
}

int lua_register_cocos2dx_cocosnet_CBuffer(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CBuffer");
    tolua_cclass(tolua_S,"CBuffer","cc.CBuffer","cc.CCObject",nullptr);

    tolua_beginmodule(tolua_S,"CBuffer");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosnet_CBuffer_constructor);
        tolua_function(tolua_S,"readUChar",lua_cocos2dx_cocosnet_CBuffer_readUChar);
        tolua_function(tolua_S,"setWriterIndex",lua_cocos2dx_cocosnet_CBuffer_setWriterIndex);
        tolua_function(tolua_S,"readFloat",lua_cocos2dx_cocosnet_CBuffer_readFloat);
        tolua_function(tolua_S,"writeData",lua_cocos2dx_cocosnet_CBuffer_writeData);
        tolua_function(tolua_S,"writeString",lua_cocos2dx_cocosnet_CBuffer_writeString);
        tolua_function(tolua_S,"writeShort",lua_cocos2dx_cocosnet_CBuffer_writeShort);
        tolua_function(tolua_S,"readWholeData",lua_cocos2dx_cocosnet_CBuffer_readWholeData);
        tolua_function(tolua_S,"readData",lua_cocos2dx_cocosnet_CBuffer_readData);
        tolua_function(tolua_S,"writeDouble",lua_cocos2dx_cocosnet_CBuffer_writeDouble);
        tolua_function(tolua_S,"getBufferSize",lua_cocos2dx_cocosnet_CBuffer_getBufferSize);
        tolua_function(tolua_S,"readChar",lua_cocos2dx_cocosnet_CBuffer_readChar);
        tolua_function(tolua_S,"markReaderIndex",lua_cocos2dx_cocosnet_CBuffer_markReaderIndex);
        tolua_function(tolua_S,"moveRight",lua_cocos2dx_cocosnet_CBuffer_moveRight);
        tolua_function(tolua_S,"readLongLong",lua_cocos2dx_cocosnet_CBuffer_readLongLong);
        tolua_function(tolua_S,"readUShort",lua_cocos2dx_cocosnet_CBuffer_readUShort);
        tolua_function(tolua_S,"getReadableSize",lua_cocos2dx_cocosnet_CBuffer_getReadableSize);
        tolua_function(tolua_S,"getReaderIndex",lua_cocos2dx_cocosnet_CBuffer_getReaderIndex);
        tolua_function(tolua_S,"capacity",lua_cocos2dx_cocosnet_CBuffer_capacity);
        tolua_function(tolua_S,"getWriterIndex",lua_cocos2dx_cocosnet_CBuffer_getWriterIndex);
        tolua_function(tolua_S,"readUInt",lua_cocos2dx_cocosnet_CBuffer_readUInt);
        tolua_function(tolua_S,"discardReadContent",lua_cocos2dx_cocosnet_CBuffer_discardReadContent);
        tolua_function(tolua_S,"writeUChar",lua_cocos2dx_cocosnet_CBuffer_writeUChar);
        tolua_function(tolua_S,"setReaderIndex",lua_cocos2dx_cocosnet_CBuffer_setReaderIndex);
        tolua_function(tolua_S,"writeLengthAndData",lua_cocos2dx_cocosnet_CBuffer_writeLengthAndData);
        tolua_function(tolua_S,"writeFloat",lua_cocos2dx_cocosnet_CBuffer_writeFloat);
        tolua_function(tolua_S,"readULongLong",lua_cocos2dx_cocosnet_CBuffer_readULongLong);
        tolua_function(tolua_S,"getContentSize",lua_cocos2dx_cocosnet_CBuffer_getContentSize);
        tolua_function(tolua_S,"readLengthAndString",lua_cocos2dx_cocosnet_CBuffer_readLengthAndString);
        tolua_function(tolua_S,"moveWriterIndexToBack",lua_cocos2dx_cocosnet_CBuffer_moveWriterIndexToBack);
        tolua_function(tolua_S,"writeUInt",lua_cocos2dx_cocosnet_CBuffer_writeUInt);
        tolua_function(tolua_S,"empty",lua_cocos2dx_cocosnet_CBuffer_empty);
        tolua_function(tolua_S,"writeLengthAndString",lua_cocos2dx_cocosnet_CBuffer_writeLengthAndString);
        tolua_function(tolua_S,"moveLeft",lua_cocos2dx_cocosnet_CBuffer_moveLeft);
        tolua_function(tolua_S,"readShort",lua_cocos2dx_cocosnet_CBuffer_readShort);
        tolua_function(tolua_S,"writeChar",lua_cocos2dx_cocosnet_CBuffer_writeChar);
        tolua_function(tolua_S,"readInt",lua_cocos2dx_cocosnet_CBuffer_readInt);
        tolua_function(tolua_S,"moveReaderIndexToFront",lua_cocos2dx_cocosnet_CBuffer_moveReaderIndexToFront);
        tolua_function(tolua_S,"moveWriterIndexToFront",lua_cocos2dx_cocosnet_CBuffer_moveWriterIndexToFront);
        tolua_function(tolua_S,"readDouble",lua_cocos2dx_cocosnet_CBuffer_readDouble);
        tolua_function(tolua_S,"copy",lua_cocos2dx_cocosnet_CBuffer_copy);
        tolua_function(tolua_S,"data",lua_cocos2dx_cocosnet_CBuffer_data);
        tolua_function(tolua_S,"readString",lua_cocos2dx_cocosnet_CBuffer_readString);
        tolua_function(tolua_S,"reset",lua_cocos2dx_cocosnet_CBuffer_reset);
        tolua_function(tolua_S,"writeUShort",lua_cocos2dx_cocosnet_CBuffer_writeUShort);
        tolua_function(tolua_S,"moveReaderIndexToBack",lua_cocos2dx_cocosnet_CBuffer_moveReaderIndexToBack);
        tolua_function(tolua_S,"clear",lua_cocos2dx_cocosnet_CBuffer_clear);
        tolua_function(tolua_S,"writeULongLong",lua_cocos2dx_cocosnet_CBuffer_writeULongLong);
        tolua_function(tolua_S,"skipData",lua_cocos2dx_cocosnet_CBuffer_skipData);
        tolua_function(tolua_S,"length",lua_cocos2dx_cocosnet_CBuffer_length);
        tolua_function(tolua_S,"resetReaderIndex",lua_cocos2dx_cocosnet_CBuffer_resetReaderIndex);
        tolua_function(tolua_S,"isReadable",lua_cocos2dx_cocosnet_CBuffer_isReadable);
        tolua_function(tolua_S,"writeInt",lua_cocos2dx_cocosnet_CBuffer_writeInt);
        tolua_function(tolua_S,"writeLongLong",lua_cocos2dx_cocosnet_CBuffer_writeLongLong);
        tolua_function(tolua_S,"create", lua_cocos2dx_cocosnet_CBuffer_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CBuffer).name();
    g_luaType[typeName] = "cc.CBuffer";
    g_typeCast["CBuffer"] = "cc.CBuffer";
    return 1;
}

int lua_cocos2dx_cocosnet_CInetAddress_getLength(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CInetAddress* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CInetAddress",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CInetAddress*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CInetAddress_getLength'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getLength();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getLength",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CInetAddress_getLength'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CInetAddress_setIp(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CInetAddress* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CInetAddress",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::CInetAddress*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CInetAddress_setIp'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            unsigned int arg0;
            ok &= luaval_to_uint32(tolua_S, 2,&arg0);

            if (!ok) { break; }
            cobj->setIp(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->setIp(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setIp",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CInetAddress_setIp'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CInetAddress_setHost(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CInetAddress* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CInetAddress",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CInetAddress*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CInetAddress_setHost'", nullptr);
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
        cobj->setHost(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setHost",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CInetAddress_setHost'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CInetAddress_getIp(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CInetAddress* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CInetAddress",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CInetAddress*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CInetAddress_getIp'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getIp();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getIp",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CInetAddress_getIp'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CInetAddress_getHostAddress(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CInetAddress* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CInetAddress",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CInetAddress*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CInetAddress_getHostAddress'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getHostAddress();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getHostAddress",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CInetAddress_getHostAddress'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CInetAddress_getPort(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CInetAddress* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CInetAddress",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CInetAddress*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CInetAddress_getPort'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        unsigned short ret = cobj->getPort();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getPort",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CInetAddress_getPort'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CInetAddress_setPort(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CInetAddress* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.CInetAddress",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::CInetAddress*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_cocosnet_CInetAddress_setPort'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setPort(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setPort",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CInetAddress_setPort'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_cocosnet_CInetAddress_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::CInetAddress* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            unsigned short arg1;
            ok &= luaval_to_ushort(tolua_S, 3, &arg1);

            if (!ok) { break; }
            cobj = new cocos2d::CInetAddress(arg0, arg1);
            tolua_pushusertype(tolua_S,(void*)cobj,"cc.CInetAddress");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            cobj = new cocos2d::CInetAddress();
            tolua_pushusertype(tolua_S,(void*)cobj,"cc.CInetAddress");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            const sockaddr* arg0;
            #pragma warning NO CONVERSION TO NATIVE FOR sockaddr*;

            if (!ok) { break; }
            cobj = new cocos2d::CInetAddress(arg0);
            tolua_pushusertype(tolua_S,(void*)cobj,"cc.CInetAddress");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CInetAddress",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_cocosnet_CInetAddress_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_cocosnet_CInetAddress_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CInetAddress)");
    return 0;
}

int lua_register_cocos2dx_cocosnet_CInetAddress(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.CInetAddress");
    tolua_cclass(tolua_S,"CInetAddress","cc.CInetAddress","sockaddr_in",nullptr);

    tolua_beginmodule(tolua_S,"CInetAddress");
        tolua_function(tolua_S,"new",lua_cocos2dx_cocosnet_CInetAddress_constructor);
        tolua_function(tolua_S,"getLength",lua_cocos2dx_cocosnet_CInetAddress_getLength);
        tolua_function(tolua_S,"setIp",lua_cocos2dx_cocosnet_CInetAddress_setIp);
        tolua_function(tolua_S,"setHost",lua_cocos2dx_cocosnet_CInetAddress_setHost);
        tolua_function(tolua_S,"getIp",lua_cocos2dx_cocosnet_CInetAddress_getIp);
        tolua_function(tolua_S,"getHostAddress",lua_cocos2dx_cocosnet_CInetAddress_getHostAddress);
        tolua_function(tolua_S,"getPort",lua_cocos2dx_cocosnet_CInetAddress_getPort);
        tolua_function(tolua_S,"setPort",lua_cocos2dx_cocosnet_CInetAddress_setPort);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::CInetAddress).name();
    g_luaType[typeName] = "cc.CInetAddress";
    g_typeCast["CInetAddress"] = "cc.CInetAddress";
    return 1;
}

int lua_cocos2dx_cocosnet_CNetDelegate_constructor(lua_State* tolua_S)
{
	int argc = 0;
	cocos2d::CNetDelegate* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif
	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{
		if (!ok)
			return 0;
		cobj = new cocos2d::CNetDelegate();
		cobj->autorelease();
		int ID = (int)cobj->_ID;
		int* luaID = &cobj->_luaID;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, "cc.CNetDelegate");
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CNetDelegate", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_cocosnet_CNetDelegate_constructor'.", &tolua_err);
#endif

	return 0;
}

int lua_cocos2dx_cocosnet_CNetDelegate_getInstance(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "cc.CNetDelegate", 0, &tolua_err)) goto tolua_lerror;
#endif

	argc = lua_gettop(tolua_S) - 1;

	if (argc == 0)
	{
		if (!ok)
			return 0;
		cocos2d::CNetDelegate* ret = cocos2d::CNetDelegate::getInstance();
		object_to_luaval<cocos2d::CNetDelegate>(tolua_S, "cc.CNetDelegate", (cocos2d::CNetDelegate*)ret);
		return 1;
	}
	CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getInstance", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_cocosnet_CNetDelegate_getInstance'.", &tolua_err);
#endif
	return 0;
}

int lua_register_cocos2dx_cocosnet_CNetDelegate(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "cc.CNetDelegate");
	tolua_cclass(tolua_S, "CNetDelegate", "cc.CNetDelegate", "cc.Ref", nullptr);

	tolua_beginmodule(tolua_S, "CNetDelegate");
	tolua_function(tolua_S, "new", lua_cocos2dx_cocosnet_CNetDelegate_constructor);
	tolua_function(tolua_S, "setOnMessageReceivedScriptHandler", lua_cocos2dx_cocosnet_CNetDelegate_setOnMessageReceivedScriptHandler);
	tolua_function(tolua_S, "setOnExceptionCaughtScriptHandler", lua_cocos2dx_cocosnet_CNetDelegate_setOnExceptionCaughtScriptHandler);
	tolua_function(tolua_S, "setOnConnectedScriptHandler", lua_cocos2dx_cocosnet_CNetDelegate_setOnConnectedScriptHandler);
	tolua_function(tolua_S, "setOnConnectTimeoutScriptHandler", lua_cocos2dx_cocosnet_CNetDelegate_setOnConnectTimeoutScriptHandler);
	tolua_function(tolua_S, "setOnDisconnectedScriptHandler", lua_cocos2dx_cocosnet_CNetDelegate_setOnDisconnectedScriptHandler);
	tolua_function(tolua_S, "getInstance", lua_cocos2dx_cocosnet_CNetDelegate_getInstance);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(cocos2d::CNetDelegate).name();
	g_luaType[typeName] = "cc.CNetDelegate";
	g_typeCast["CNetDelegate"] = "cc.CNetDelegate";
	return 1;
}

TOLUA_API int register_all_cocos2dx_cocosnet(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,NULL,0);
	tolua_beginmodule(tolua_S, NULL);

	lua_register_cocos2dx_cocosnet_CBuffer(tolua_S);
	lua_register_cocos2dx_cocosnet_CInetAddress(tolua_S);
	lua_register_cocos2dx_cocosnet_CNetDelegate(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

