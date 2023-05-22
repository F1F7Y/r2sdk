#pragma once
// UI

#include "squirrel/sqvm.h"

inline CMemory p_SQVM_UI_PrintFunc;
inline auto v_SQVM_UI_PrintFunc = p_SQVM_UI_PrintFunc.RCast<SQRESULT(*)(HSquirrelVM* sqvm, SQChar* fmt, ...)>();

///////////////////////////////////////////////////////////////////////////////
class HSQVM_UI : public IDetour
{
	virtual void GetAdr(void) const
	{
		LogFunAdr("SQVM_UI_PrintFunc", p_SQVM_UI_PrintFunc.GetPtr());
	}
	virtual void GetFun(void) const
	{
		p_SQVM_UI_PrintFunc = g_pClientDll->Offset(0x12BA0); /* "24 20 BA 00 08 00 00 E8  14 0E 72 00 80 3D CC EE" - 32 */
		v_SQVM_UI_PrintFunc = p_SQVM_UI_PrintFunc.RCast<SQRESULT(*)(HSquirrelVM*, SQChar*, ...)>();
	}
	virtual void GetVar(void) const { }
	virtual void GetCon(void) const { }
	virtual void Attach(void) const;
	virtual void Detach(void) const;
};
///////////////////////////////////////////////////////////////////////////////