#pragma once

//-------------------------------------------------------------------------
// Methods of IApplication
//-------------------------------------------------------------------------
/* ==== CAPPSYSTEMGROUP ================================================================================================================================================= */
//inline CMemory p_CModAppSystemGroup_Main;
//inline auto CModAppSystemGroup_Main = p_CModAppSystemGroup_Main.RCast<int(*)(CModAppSystemGroup* pModAppSystemGroup)>();

//inline CMemory p_CModAppSystemGroup_Create;
//inline auto CModAppSystemGroup_Create = p_CModAppSystemGroup_Create.RCast<bool(*)(CModAppSystemGroup* pModAppSystemGroup)>();

// CSourceAppSystemGroup table : 0x180065798
inline CMemory p_CSourceAppSystemGroup__PreInit;
inline auto v_CSourceAppSystemGroup__PreInit = p_CSourceAppSystemGroup__PreInit.RCast<bool(*)(void* pModAppSystemGroup)>();

inline CMemory p_CSourceAppSystemGroup__Create;
inline auto v_CSourceAppSystemGroup__Create = p_CSourceAppSystemGroup__Create.RCast<bool(*)(void* pModAppSystemGroup)>();

inline bool g_bAppSystemInit = false;

///////////////////////////////////////////////////////////////////////////////
class VApplication : public IDetour
{
	virtual void GetAdr(void) const
	{
		//LogFunAdr("CModAppSystemGroup::Main", p_CModAppSystemGroup_Main.GetPtr());
		//LogFunAdr("CModAppSystemGroup::Create", p_CModAppSystemGroup_Create.GetPtr());
		LogFunAdr("CSourceAppSystemGroup::PreInit", p_CSourceAppSystemGroup__PreInit.GetPtr()); // launcher.dll + 0xB730
		LogFunAdr("CSourceAppSystemGroup::Create", p_CSourceAppSystemGroup__Create.GetPtr()); // launcher.dll + 0x94E0
	}
	virtual void GetFun(void) const
	{
		p_CSourceAppSystemGroup__PreInit = g_LauncherDll.FindPatternSIMD("48 89 7C 24 18 55 48 8D AC 24 90 FA FF FF 48");
		v_CSourceAppSystemGroup__PreInit = p_CSourceAppSystemGroup__PreInit.RCast<bool(*)(void*)>();

		p_CSourceAppSystemGroup__Create = g_LauncherDll.FindPatternSIMD("48 89 5C 24 08 48 89 74 24 10 48 89 7C 24 18 55 48");
		v_CSourceAppSystemGroup__Create = p_CSourceAppSystemGroup__Create.RCast<bool(*)(void*)>();
	}
	virtual void GetVar(void) const { }
	virtual void GetCon(void) const { }
	virtual void Attach(void) const;
	virtual void Detach(void) const;
};
///////////////////////////////////////////////////////////////////////////////
