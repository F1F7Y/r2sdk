#pragma once

inline CMemory p_CCvar__Disconnect;
inline auto v_CCvar__Disconnect = p_CCvar__Disconnect.RCast<void*(*)()>();

///////////////////////////////////////////////////////////////////////////////
class VCVar : public IDetour
{
	virtual void GetAdr(void) const
	{
		LogFunAdr("CCvar::Disconnect", p_CCvar__Disconnect.GetPtr());
	}
	virtual void GetFun(void) const
	{
		p_CCvar__Disconnect = g_pVstdlibDll->FindPatternSIMD("48 83 EC 28 E8 B7");
		v_CCvar__Disconnect = p_CCvar__Disconnect.RCast<void*(*)()>();
	}
	virtual void GetVar(void) const { }
	virtual void GetCon(void) const { }
	virtual void Attach(void) const;
	virtual void Detach(void) const;
};
///////////////////////////////////////////////////////////////////////////////