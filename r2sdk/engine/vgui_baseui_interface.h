#ifndef VGUI_BASEUI_INTERFACE_H
#define VGUI_BASEUI_INTERFACE_H

#include "core/stdafx.h"

inline CMemory p_CEngineVGui__Init;
inline auto v_CEngineVGui__Init = p_CEngineVGui__Init.RCast<char(*)(void*)>();


///////////////////////////////////////////////////////////////////////////////
class VEngineVgui : public IDetour
{
	virtual void GetAdr(void) const
	{
		LogFunAdr("CEngineVgui::Init", p_CEngineVGui__Init.GetPtr());
	}
	virtual void GetFun(void) const
	{
		p_CEngineVGui__Init = g_pEngineDll->FindPatternSIMD("40 53 57 48 83 EC 38 48 8B F9 FF 15 38 6E 37 00");
		v_CEngineVGui__Init = p_CEngineVGui__Init.RCast<char(*)(void*)>();
	}
	virtual void GetVar(void) const { }
	virtual void GetCon(void) const { }
	virtual void Attach(void) const;
	virtual void Detach(void) const;
};
///////////////////////////////////////////////////////////////////////////////

#endif /* VGUI_BASEUI_INTERFACE_H */
