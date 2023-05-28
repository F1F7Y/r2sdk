#pragma once

#include "sqdatatypes.h"
#include "sqclasstypes.h"


/* ==== SQUIRREL ======================================================================================================================================================== */
/* ==== ARRAY FUNCS ===================================================================================================================================================== */
template<ScriptContext context>
inline CMemory p_sq_newarray;
template<ScriptContext context>
inline auto v_sq_newarray = p_sq_newarray<context>.RCast<void(*)(HSquirrelVM* sqvm, SQInteger iStackpos)>();

template<ScriptContext context>
inline CMemory p_sq_arrayappend;
template<ScriptContext context>
inline auto v_sq_arrayappend = p_sq_arrayappend<context>.RCast<SQRESULT(*)(HSquirrelVM* sqvm, SQInteger iStackpos)>();
/* ==== TABLE FUNCS ===================================================================================================================================================== */
template<ScriptContext context>
inline CMemory p_sq_newtable;
template<ScriptContext context>
inline auto v_sq_newtable = p_sq_newtable<context>.RCast<SQRESULT(*)(HSquirrelVM* sqvm)>();

template<ScriptContext context>
inline CMemory p_sq_newtableslot;
template<ScriptContext context>
inline auto v_sq_newtableslot = p_sq_newtableslot<context>.RCast<SQRESULT(*)(HSquirrelVM* sqvm, SQInteger idx, SQBool bStatic)>();
/* ==== STACK PUSH FUNCS ================================================================================================================================================ */
template<ScriptContext context>
inline CMemory p_sq_pushroottable;
template<ScriptContext context>
inline auto v_sq_pushroottable = p_sq_pushroottable<context>.RCast<void(*)(HSquirrelVM* sqvm)>();

template<ScriptContext context>
inline CMemory p_sq_pushstring;
template<ScriptContext context>
inline auto v_sq_pushstring = p_sq_pushstring<context>.RCast<void(*)(HSquirrelVM* sqvm, const SQChar* pStr, SQInteger iLength)>();

template<ScriptContext context>
inline CMemory p_sq_pushinteger;
template<ScriptContext context>
inline auto v_sq_pushinteger = p_sq_pushinteger<context>.RCast<void(*)(HSquirrelVM* sqvm, SQInteger i)>();

template<ScriptContext context>
inline CMemory p_sq_pushfloat;
template<ScriptContext context>
inline auto v_sq_pushfloat = p_sq_pushfloat<context>.RCast<void(*)(HSquirrelVM* sqvm, SQFloat f)>();

template<ScriptContext context>
inline CMemory p_sq_pushbool;
template<ScriptContext context>
inline auto v_sq_pushbool = p_sq_pushbool<context>.RCast<void(*)(HSquirrelVM* sqvm, SQBool b)>();

template<ScriptContext context>
inline CMemory p_sq_pushasset;
template<ScriptContext context>
inline auto v_sq_pushasset = p_sq_pushasset<context>.RCast<void(*)(HSquirrelVM* sqvm, const SQChar* str, SQInteger iLength)>();

template<ScriptContext context>
inline CMemory p_sq_pushvector;
template<ScriptContext context>
inline auto v_sq_pushvector = p_sq_pushvector<context>.RCast<void(*)(HSquirrelVM* sqvm, const SQFloat* pVec)>();

template<ScriptContext context>
inline CMemory p_sq_pushobject;
template<ScriptContext context>
inline auto v_sq_pushobject = p_sq_pushobject<context>.RCast<void(*)(HSquirrelVM* sqvm, SQObject* pVec)>();
/* ==== STACK GET FUNCS ================================================================================================================================================= */
template<ScriptContext context>
inline CMemory p_sq_getstring;
template<ScriptContext context>
inline auto v_sq_getstring = p_sq_getstring<context>.RCast<const SQChar*(*)(HSquirrelVM* sqvm, SQInteger iStackpos)>();

template<ScriptContext context>
inline CMemory p_sq_getinteger;
template<ScriptContext context>
inline auto v_sq_getinteger = p_sq_getinteger<context>.RCast<SQInteger(*)(HSquirrelVM* sqvm, SQInteger iStackpos)>();

template<ScriptContext context>
inline CMemory p_sq_getfloat;
template<ScriptContext context>
inline auto v_sq_getfloat = p_sq_getfloat<context>.RCast<SQFloat(*)(HSquirrelVM* sqvm, SQInteger iStackpos)>();

template<ScriptContext context>
inline CMemory p_sq_getbool;
template<ScriptContext context>
inline auto v_sq_getbool = p_sq_getbool<context>.RCast<SQBool(*)(HSquirrelVM* sqvm, SQInteger iStackpos)>();

template<ScriptContext context>
inline CMemory p_sq_get;
template<ScriptContext context>
inline auto v_sq_get = p_sq_get<context>.RCast<SQRESULT(*)(HSquirrelVM* sqvm, SQInteger iStackpos)>();

template<ScriptContext context>
inline CMemory p_sq_getasset;
template<ScriptContext context>
inline auto v_sq_getasset = p_sq_getasset<context>.RCast<SQRESULT(*)(HSquirrelVM* sqvm, SQInteger iStackpos, const char** pResult)>();

template<ScriptContext context>
inline CMemory p_sq_getuserdata;
template<ScriptContext context>
inline auto v_sq_getuserdata = p_sq_getuserdata<context>.RCast<SQRESULT(*)(HSquirrelVM* sqvm, SQInteger iStackpos, void** pData, uint64_t* pTypeId)>();

template<ScriptContext context>
inline CMemory p_sq_getvector;
template<ScriptContext context>
inline auto v_sq_getvector = p_sq_getvector<context>.RCast<SQFloat*(*)(HSquirrelVM* sqvm, SQInteger iStackpos)>();

template<ScriptContext context>
inline CMemory p_sq_getthisentity;
template<ScriptContext context>
inline auto v_sq_getthisentity = p_sq_getthisentity<context>.RCast<SQBool(*)(HSquirrelVM* sqvm, void** ppEntity)>();

template<ScriptContext context>
inline CMemory p_sq_getobject;
template<ScriptContext context>
inline auto v_sq_getobject = p_sq_getobject<context>.RCast<void(*)(HSquirrelVM* sqvm, SQInteger iStackPos, SQObject* pOutObj)>();

///////////////////////////////////////////////////////////////////////////////
