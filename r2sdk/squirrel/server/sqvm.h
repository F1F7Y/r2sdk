#pragma once
// SERVER

#include "squirrel/sqvm.h"

inline CMemory p_SQVM_SERVER_PrintFunc;
inline auto v_SQVM_SERVER_PrintFunc = p_SQVM_SERVER_PrintFunc.RCast<SQRESULT(*)(HSquirrelVM* sqvm, SQChar* fmt, ...)>();

///////////////////////////////////////////////////////////////////////////////
class HSQVM_SERVER : public IDetour
{
	virtual void GetAdr(void) const
	{
		LogFunAdr("SQVM_SERVER_PrintFunc", p_SQVM_SERVER_PrintFunc.GetPtr());
	}
	virtual void GetFun(void) const
	{
		p_SQVM_SERVER_PrintFunc = g_pServerDll->Offset(0x1FE90); /* "24 20 BA 00 08 00 00 E8  E4 AC 6F 00 80 3D BC 90" - 32 */
		v_SQVM_SERVER_PrintFunc = p_SQVM_SERVER_PrintFunc.RCast<SQRESULT(*)(HSquirrelVM*, SQChar*, ...)>();
	}
	virtual void GetVar(void) const { }
	virtual void GetCon(void) const { }
	virtual void Attach(void) const;
	virtual void Detach(void) const;
};
///////////////////////////////////////////////////////////////////////////////