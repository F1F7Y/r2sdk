#pragma once
// CLIENT

#include "squirrel/sqvm.h"

inline CMemory p_SQVM_CLIENT_PrintFunc;
inline auto v_SQVM_CLIENT_PrintFunc = p_SQVM_CLIENT_PrintFunc.RCast<SQRESULT(*)(HSquirrelVM* sqvm, SQChar* fmt, ...)>();

///////////////////////////////////////////////////////////////////////////////
class HSQVM_CLIENT : public IDetour
{
	virtual void GetAdr(void) const
	{
		LogFunAdr("SQVM_CLIENT_PrintFunc", p_SQVM_CLIENT_PrintFunc.GetPtr());
	}
	virtual void GetFun(void) const
	{
		p_SQVM_CLIENT_PrintFunc = g_pClientDll->Offset(0x12B00); /* "24 20 BA 00 08 00 00 E8  B4 0E 72 00 80 3D 6C EF" - 32 */
		v_SQVM_CLIENT_PrintFunc = p_SQVM_CLIENT_PrintFunc.RCast<SQRESULT(*)(HSquirrelVM*, SQChar*, ...)>();
	}
	virtual void GetVar(void) const { }
	virtual void GetCon(void) const { }
	virtual void Attach(void) const;
	virtual void Detach(void) const;
};
///////////////////////////////////////////////////////////////////////////////