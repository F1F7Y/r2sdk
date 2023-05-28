#pragma once
// SERVER

#include "squirrel/sqapi.h"

///////////////////////////////////////////////////////////////////////////////
class VSqapi_SERVER : public IDetour
{
	virtual void GetAdr(void) const
	{
	}
	virtual void GetFun(void) const
	{
		// PUSH FUNCS
		p_sq_pushroottable<ScriptContext::SERVER> = g_pServerDll->Offset(0x5860);
		p_sq_pushstring<ScriptContext::SERVER> = g_pServerDll->Offset(0x3440);
		p_sq_pushinteger<ScriptContext::SERVER> = g_pServerDll->Offset(0x36A0);
		p_sq_pushfloat<ScriptContext::SERVER> = g_pServerDll->Offset(0x3800);
		p_sq_pushbool<ScriptContext::SERVER> = g_pServerDll->Offset(0x3710);
		p_sq_pushasset<ScriptContext::SERVER> = g_pServerDll->Offset(0x3560);
		p_sq_pushvector<ScriptContext::SERVER> = g_pServerDll->Offset(0x3780);
		p_sq_pushobject<ScriptContext::SERVER> = g_pServerDll->Offset(0x83A0);

		v_sq_pushroottable<ScriptContext::SERVER> = p_sq_pushroottable<ScriptContext::SERVER>.RCast<void(*)(HSquirrelVM* sqvm)>();
		v_sq_pushstring<ScriptContext::SERVER> = p_sq_pushstring<ScriptContext::SERVER>.RCast<void(*)(HSquirrelVM* sqvm, const SQChar* pStr, SQInteger iLength)>();
		v_sq_pushinteger<ScriptContext::SERVER> = p_sq_pushinteger<ScriptContext::SERVER>.RCast<void(*)(HSquirrelVM* sqvm, SQInteger i)>();
		v_sq_pushfloat<ScriptContext::SERVER> = p_sq_pushfloat<ScriptContext::SERVER>.RCast<void(*)(HSquirrelVM* sqvm, SQFloat f)>();
		v_sq_pushbool<ScriptContext::SERVER> = p_sq_pushbool<ScriptContext::SERVER>.RCast<void(*)(HSquirrelVM* sqvm, SQBool b)>();
		v_sq_pushasset<ScriptContext::SERVER> = p_sq_pushasset<ScriptContext::SERVER>.RCast<void(*)(HSquirrelVM* sqvm, const SQChar* str, SQInteger iLength)>();
		v_sq_pushvector<ScriptContext::SERVER> = p_sq_pushvector<ScriptContext::SERVER>.RCast<void(*)(HSquirrelVM* sqvm, const SQFloat* pVec)>();
		v_sq_pushobject<ScriptContext::SERVER> = p_sq_pushobject<ScriptContext::SERVER>.RCast<void(*)(HSquirrelVM* sqvm, SQObject* pVec)>();

		// GET FUNCS
		p_sq_getstring<ScriptContext::SERVER> = g_pServerDll->Offset(0x60A0);
		p_sq_getinteger<ScriptContext::SERVER> = g_pServerDll->Offset(0x60C0);
		p_sq_getfloat<ScriptContext::SERVER> = g_pServerDll->Offset(0x60E0);
		p_sq_getbool<ScriptContext::SERVER> = g_pServerDll->Offset(0x6110);
		p_sq_get<ScriptContext::SERVER> = g_pServerDll->Offset(0x7C00);
		p_sq_getasset<ScriptContext::SERVER> = g_pServerDll->Offset(0x5FF0);
		p_sq_getuserdata<ScriptContext::SERVER> = g_pServerDll->Offset(0x63B0);
		p_sq_getvector<ScriptContext::SERVER> = g_pServerDll->Offset(0x6120);
		p_sq_getthisentity<ScriptContext::SERVER> = g_pServerDll->Offset(0x203B0);
		p_sq_getobject<ScriptContext::SERVER> = g_pServerDll->Offset(0x6140);

		v_sq_getstring<ScriptContext::SERVER> = p_sq_getstring<ScriptContext::SERVER>.RCast<const SQChar* (*)(HSquirrelVM* sqvm, SQInteger iStackpos)>();
		v_sq_getinteger<ScriptContext::SERVER> = p_sq_getinteger<ScriptContext::SERVER>.RCast<SQInteger(*)(HSquirrelVM* sqvm, SQInteger iStackpos)>();
		v_sq_getfloat<ScriptContext::SERVER> = p_sq_getfloat<ScriptContext::SERVER>.RCast<SQFloat(*)(HSquirrelVM* sqvm, SQInteger iStackpos)>();
		v_sq_getbool<ScriptContext::SERVER> = p_sq_getbool<ScriptContext::SERVER>.RCast<SQBool(*)(HSquirrelVM* sqvm, SQInteger iStackpos)>();
		v_sq_get<ScriptContext::SERVER> = p_sq_get<ScriptContext::SERVER>.RCast<SQRESULT(*)(HSquirrelVM* sqvm, SQInteger iStackpos)>();
		v_sq_getasset<ScriptContext::SERVER> = p_sq_getasset<ScriptContext::SERVER>.RCast<SQRESULT(*)(HSquirrelVM* sqvm, SQInteger iStackpos, const char** pResult)>();
		v_sq_getuserdata<ScriptContext::SERVER> = p_sq_getuserdata<ScriptContext::SERVER>.RCast<SQRESULT(*)(HSquirrelVM* sqvm, SQInteger iStackpos, void** pData, uint64_t* pTypeId)>();
		v_sq_getvector<ScriptContext::SERVER> = p_sq_getvector<ScriptContext::SERVER>.RCast<SQFloat* (*)(HSquirrelVM* sqvm, SQInteger iStackpos)>();
		v_sq_getthisentity<ScriptContext::SERVER> = p_sq_getthisentity<ScriptContext::SERVER>.RCast<SQBool(*)(HSquirrelVM* sqvm, void** ppEntity)>();
		v_sq_getobject<ScriptContext::SERVER> = p_sq_getobject<ScriptContext::SERVER>.RCast<void(*)(HSquirrelVM* sqvm, SQInteger iStackPos, SQObject* pOutObj)>();
	}
	virtual void GetVar(void) const { }
	virtual void GetCon(void) const { }
	virtual void Attach(void) const { }
	virtual void Detach(void) const { }
};
///////////////////////////////////////////////////////////////////////////////