#pragma once
// UI
// Client and UI share these

#include "squirrel/sqapi.h"

///////////////////////////////////////////////////////////////////////////////
class VSqapi_UI : public IDetour
{
	virtual void GetAdr(void) const
	{
	}
	virtual void GetFun(void) const
	{
		// PUSH FUNCS
		p_sq_pushroottable<ScriptContext::UI> = g_pClientDll->Offset(0x5860);
		p_sq_pushstring<ScriptContext::UI> = g_pClientDll->Offset(0x3440);
		p_sq_pushinteger<ScriptContext::UI> = g_pClientDll->Offset(0x36A0);
		p_sq_pushfloat<ScriptContext::UI> = g_pClientDll->Offset(0x3800);
		p_sq_pushbool<ScriptContext::UI> = g_pClientDll->Offset(0x3710);
		p_sq_pushasset<ScriptContext::UI> = g_pClientDll->Offset(0x3560);
		p_sq_pushvector<ScriptContext::UI> = g_pClientDll->Offset(0x3780);
		p_sq_pushobject<ScriptContext::UI> = g_pClientDll->Offset(0x83D0);

		v_sq_pushroottable<ScriptContext::UI> = p_sq_pushroottable<ScriptContext::UI>.RCast<void(*)(HSquirrelVM* sqvm)>();
		v_sq_pushstring<ScriptContext::UI> = p_sq_pushstring<ScriptContext::UI>.RCast<void(*)(HSquirrelVM* sqvm, const SQChar* pStr, SQInteger iLength)>();
		v_sq_pushinteger<ScriptContext::UI> = p_sq_pushinteger<ScriptContext::UI>.RCast<void(*)(HSquirrelVM* sqvm, SQInteger i)>();
		v_sq_pushfloat<ScriptContext::UI> = p_sq_pushfloat<ScriptContext::UI>.RCast<void(*)(HSquirrelVM* sqvm, SQFloat f)>();
		v_sq_pushbool<ScriptContext::UI> = p_sq_pushbool<ScriptContext::UI>.RCast<void(*)(HSquirrelVM* sqvm, SQBool b)>();
		v_sq_pushasset<ScriptContext::UI> = p_sq_pushasset<ScriptContext::UI>.RCast<void(*)(HSquirrelVM* sqvm, const SQChar* str, SQInteger iLength)>();
		v_sq_pushvector<ScriptContext::UI> = p_sq_pushvector<ScriptContext::UI>.RCast<void(*)(HSquirrelVM* sqvm, const SQFloat* pVec)>();
		v_sq_pushobject<ScriptContext::UI> = p_sq_pushobject<ScriptContext::UI>.RCast<void(*)(HSquirrelVM* sqvm, SQObject* pVec)>();

		// GET FUNCS
		p_sq_getstring<ScriptContext::UI> = g_pClientDll->Offset(0x60C0);
		p_sq_getinteger<ScriptContext::UI> = g_pClientDll->Offset(0x60E0);
		p_sq_getfloat<ScriptContext::UI> = g_pClientDll->Offset(0x6100);
		p_sq_getbool<ScriptContext::UI> = g_pClientDll->Offset(0x6130);
		p_sq_get<ScriptContext::UI> = g_pClientDll->Offset(0x7C30);
		p_sq_getasset<ScriptContext::UI> = g_pClientDll->Offset(0x6010);
		p_sq_getuserdata<ScriptContext::UI> = g_pClientDll->Offset(0x63D0);
		p_sq_getvector<ScriptContext::UI> = g_pClientDll->Offset(0x6140);
		p_sq_getthisentity<ScriptContext::UI> = g_pClientDll->Offset(0x12F80);
		p_sq_getobject<ScriptContext::UI> = g_pClientDll->Offset(0x6160);

		v_sq_getstring<ScriptContext::UI> = p_sq_getstring<ScriptContext::UI>.RCast<const SQChar*(*)(HSquirrelVM* sqvm, SQInteger iStackpos)>();
		v_sq_getinteger<ScriptContext::UI> = p_sq_getinteger<ScriptContext::UI>.RCast<SQInteger(*)(HSquirrelVM* sqvm, SQInteger iStackpos)>();
		v_sq_getfloat<ScriptContext::UI> = p_sq_getfloat<ScriptContext::UI>.RCast<SQFloat(*)(HSquirrelVM* sqvm, SQInteger iStackpos)>();
		v_sq_getbool<ScriptContext::UI> = p_sq_getbool<ScriptContext::UI>.RCast<SQBool(*)(HSquirrelVM* sqvm, SQInteger iStackpos)>();
		v_sq_get<ScriptContext::UI> = p_sq_get<ScriptContext::UI>.RCast<SQRESULT(*)(HSquirrelVM* sqvm, SQInteger iStackpos)>();
		v_sq_getasset<ScriptContext::UI> = p_sq_getasset<ScriptContext::UI>.RCast<SQRESULT(*)(HSquirrelVM* sqvm, SQInteger iStackpos, const char** pResult)>();
		v_sq_getuserdata<ScriptContext::UI> = p_sq_getuserdata<ScriptContext::UI>.RCast<SQRESULT(*)(HSquirrelVM* sqvm, SQInteger iStackpos, void** pData, uint64_t* pTypeId)>();
		v_sq_getvector<ScriptContext::UI> = p_sq_getvector<ScriptContext::UI>.RCast<SQFloat*(*)(HSquirrelVM* sqvm, SQInteger iStackpos)>();
		v_sq_getthisentity<ScriptContext::UI> = p_sq_getthisentity<ScriptContext::UI>.RCast<SQBool(*)(HSquirrelVM* sqvm, void** ppEntity)>();
		v_sq_getobject<ScriptContext::UI> = p_sq_getobject<ScriptContext::UI>.RCast<void(*)(HSquirrelVM* sqvm, SQInteger iStackPos, SQObject* pOutObj)>();
	}
	virtual void GetVar(void) const { }
	virtual void GetCon(void) const { }
	virtual void Attach(void) const { }
	virtual void Detach(void) const { }
};
///////////////////////////////////////////////////////////////////////////////