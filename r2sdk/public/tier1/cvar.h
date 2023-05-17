//===== Copyright � 1996-2005, Valve Corporation, All rights reserved. ======//
//
// Purpose: 
//
// $Workfile:     $
// $Date:         $
//
//-----------------------------------------------------------------------------
// $NoKeywords: $
//===========================================================================//

#ifndef CVAR_H
#define CVAR_H

#include "icvar.h"

///////////////////////////////////////////////////////////////////////////////
extern ICvar* g_pCVar;

#if 0
//#include "vstdlib/concommandhash.h"

//-------------------------------------------------------------------------
// ENGINE                                                                 |
//extern ConVar* sdk_fixedframe_tickinterval;

/* ==== CCVAR =========================================================================================================================================================== */


class CCvar
{ 	// Implementation in engine.
protected:
	enum ConVarSetType_t
	{
		CONVAR_SET_STRING = 0,
		CONVAR_SET_INT,
		CONVAR_SET_FLOAT,
	};

	struct QueuedConVarSet_t
	{
		ConVar* m_pConVar;
		ConVarSetType_t m_nType;
		int m_nInt;
		float m_flFloat;
		CUtlString m_String;
	};

	class CCVarIteratorInternal : public ICVarIteratorInternal
	{
	public:
		virtual void            SetFirst(void) = 0; //0
		virtual void            Next(void) = 0; //1
		virtual	bool            IsValid(void) = 0; //2
		virtual ConCommandBase* Get(void) = 0; //3

		CCvar* const m_pOuter = nullptr;
		CConCommandHash* const m_pHash = nullptr;
		CConCommandHash::CCommandHashIterator_t m_hashIter;
	};

	virtual CCVarIteratorInternal* FactoryInternalIterator(void) = 0;

	friend class CCVarIteratorInternal;
	friend class CCvarUtilities;

private:
	CUtlVector< FnChangeCallback_t > m_GlobalChangeCallbacks;
	char pad0[30];           //!TODO:
	int m_nNextDLLIdentifier;
	ConCommandBase* m_pConCommandList;
	CConCommandHash m_CommandHash;
	CUtlVector<void*> m_Unknown;
	char pad2[32];
	void* m_pCallbackStub;
	void* m_pAllocFunc;
	char pad3[16];
	CUtlVector< QueuedConVarSet_t > m_QueuedConVarSets;
	bool m_bMaterialSystemThreadSetAllowed;
};


/* ==== CONVAR ========================================================================================================================================================== */
//-----------------------------------------------------------------------------
// Purpose: A console variable
//-----------------------------------------------------------------------------
class ConVar : public ConCommandBase, public IConVar
{
	friend class CCvar;
	friend class ConVarRef;

public:
	static ConVar* StaticCreate(const char* pszName, const char* pszDefaultValue, int nFlags, const char* pszHelpString,
		bool bMin, float fMin, bool bMax, float fMax, FnChangeCallback_t pCallback, const char* pszUsageString);
	void Destroy(void);

	ConVar(void);
	virtual ~ConVar(void) { };

	static void StaticInit(void);
	static void InitShipped(void);

	static void PurgeShipped(void);
	static void PurgeHostNames(void);

	bool GetBool(void) const;
	float GetFloat(void) const;
	double GetDouble(void) const;
	int GetInt(void) const;
	int64_t GetInt64(void) const;
	size_t GetSizeT(void) const;
	Color GetColor(void) const;
	const char* GetString(void) const;

	void SetMax(float flMaxValue);
	void SetMin(float flMinValue);
	bool GetMin(float& flMinValue) const;
	bool GetMax(float& flMaxValue) const;
	float GetMinValue(void) const;
	float GetMaxValue(void) const;
	bool HasMin(void) const;
	bool HasMax(void) const;

	void SetValue(int nValue);
	void SetValue(float flValue);
	void SetValue(const char* pszValue);
	void SetValue(Color clValue);

	virtual void InternalSetValue(const char* pszValue) = 0;
	virtual void InternalSetFloatValue(float flValue) = 0;
	virtual void InternalSetIntValue(int nValue) = 0;
	void InternalSetColorValue(Color value);

	virtual __int64 Unknown0(unsigned int a2) = 0;
	virtual __int64 Unknown1(const char* a2) = 0;

	void Revert(void);
	virtual bool ClampValue(float& flValue) = 0;

	const char* GetDefault(void) const;
	void SetDefault(const char* pszDefault);
	bool SetColorFromString(const char* pszValue);

	virtual void ChangeStringValue(const char* pszTempValue) = 0;
	virtual void CreateInternal(const char* pszName, const char* pszDefaultValue, int nFlags, const char* pszHelpString,
		bool bMin, float fMin, bool bMax, float fMax, FnChangeCallback_t pCallback, const char* pszUsageString) = 0;

	void InstallChangeCallback(FnChangeCallback_t callback, bool bInvoke);
	void RemoveChangeCallback(FnChangeCallback_t callback);

	struct CVValue_t
	{
		char* m_pszString;
		size_t     m_iStringLength;
		float      m_fValue;
		int        m_nValue;
	};

	ConVar* m_pParent;         //0x0048
	const char* m_pszDefaultValue; //0x0050
	CVValue_t      m_Value;           //0c0058
	bool           m_bHasMin;         //0x0070
	float          m_fMinVal;         //0x0074
	bool           m_bHasMax;         //0x0078
	float          m_fMaxVal;         //0x007C
	CUtlVector<FnChangeCallback_t> m_fnChangeCallbacks; //0x0080
}; //Size: 0x00A0
static_assert(sizeof(ConVar) == 0xA0);

///////////////////////////////////////////////////////////////////////////////
void ConVar_PrintDescription(ConCommandBase* pVar);

/* ==== CONVAR ========================================================================================================================================================== */
inline CMemory p_ConVar_Register;
inline auto v_ConVar_Register = p_ConVar_Register.RCast<void* (*)(ConVar * thisptr, const char* szName, const char* szDefaultValue, int nFlags, const char* szHelpString, bool bMin, float fMin, bool bMax, float fMax, FnChangeCallback_t pCallback, const char* pszUsageString)>();

inline CMemory p_ConVar_Unregister;
inline auto v_ConVar_Unregister = p_ConVar_Unregister.RCast<void (*)(ConVar * thisptr)>();

inline CMemory p_ConVar_IsFlagSet;
inline auto v_ConVar_IsFlagSet = p_ConVar_IsFlagSet.RCast<bool (*)(ConVar * pConVar, int nFlag)>();

inline CMemory p_ConVar_PrintDescription;
inline auto v_ConVar_PrintDescription = p_ConVar_PrintDescription.RCast<void* (*)(ConCommandBase * pVar)>();

inline ConVar* g_pConVarVBTable;
inline IConVar* g_pConVarVFTable;

///////////////////////////////////////////////////////////////////////////////
class VCVar : public IDetour
{
	virtual void GetAdr(void) const
	{
		LogConAdr("ConCommand::`vftable'", reinterpret_cast<uintptr_t>(g_pConCommandVFTable));
		LogConAdr("ConVar::`vbtable'", reinterpret_cast<uintptr_t>(g_pConVarVBTable));
		LogConAdr("ConVar::`vftable'", reinterpret_cast<uintptr_t>(g_pConVarVFTable));
		LogFunAdr("ConVar::Register", p_ConVar_Register.GetPtr());
		LogFunAdr("ConVar::Unregister", p_ConVar_Unregister.GetPtr());
		LogFunAdr("ConVar::IsFlagSet", p_ConVar_IsFlagSet.GetPtr());
		LogFunAdr("ConVar_PrintDescription", p_ConVar_PrintDescription.GetPtr());
		LogVarAdr("g_pCVar", reinterpret_cast<uintptr_t>(g_pCVar));
	}
	virtual void GetFun(void) const
	{
#if defined (GAMEDLL_S0) || defined (GAMEDLL_S1)
		p_ConVar_Register = g_GameDll.FindPatternSIMD("48 89 5C 24 ?? 48 89 6C 24 ?? 48 89 74 24 ?? 48 89 7C 24 ?? 41 56 48 83 EC 30 F3 0F 10 44 24 ??");
		p_ConVar_Unregister = g_GameDll.FindPatternSIMD("48 89 5C 24 ?? 57 48 83 EC 20 48 8B 59 58 48 8D 05 ?? ?? ?? ??");
#elif defined (GAMEDLL_S2) || defined (GAMEDLL_S3)
		p_ConVar_Register = g_GameDll.FindPatternSIMD("48 89 5C 24 ?? 48 89 6C 24 ?? 48 89 74 24 ?? 57 48 83 EC 40 F3 0F 10 84 24 ?? ?? ?? ??");
		p_ConVar_Unregister = g_GameDll.FindPatternSIMD("48 89 5C 24 ?? 48 89 74 24 ?? 57 48 83 EC 20 48 8B 79 58");
#endif
		p_ConVar_IsFlagSet = g_GameDll.FindPatternSIMD("48 8B 41 48 85 50 38");
		p_ConVar_PrintDescription = g_GameDll.FindPatternSIMD("B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 48 2B E0 48 8B 01 48 89 9C 24 ?? ?? ?? ??");

		v_ConVar_IsFlagSet = p_ConVar_IsFlagSet.RCast<bool (*)(ConVar*, int)>();
		v_ConVar_Register = p_ConVar_Register.RCast<void* (*)(ConVar*, const char*, const char*, int, const char*, bool, float, bool, float, FnChangeCallback_t, const char*)>();
		v_ConVar_Unregister = p_ConVar_Unregister.RCast<void (*)(ConVar*)>();
		v_ConVar_PrintDescription = p_ConVar_PrintDescription.RCast<void* (*)(ConCommandBase*)>();
	}
	virtual void GetVar(void) const
	{
		g_pCVar = g_GameDll.FindPatternSIMD("48 83 EC 28 48 8B 05 ?? ?? ?? ?? 48 8D 0D ?? ?? ?? ?? 48 85 C0 48 89 15")
			.FindPatternSelf("48 8D 0D", CMemory::Direction::DOWN, 40).ResolveRelativeAddressSelf(0x3, 0x7).RCast<CCvar*>();

		//g_pCVar = g_GameDll.FindPatternSIMD("40 53 48 83 EC 20 48 83 3D ?? ?? ?? ?? ?? 48 8B D9 74 09") // Actual CCvar, above is the vtable ptr.
			//.FindPatternSelf("48 83 3D", CMemory::Direction::DOWN).ResolveRelativeAddressSelf(0x3, 0x8).RCast<CCvar*>();
	}
	virtual void GetCon(void) const
	{
		g_pConVarVBTable = g_GameDll.GetVirtualMethodTable(".?AVConVar@@", 0).RCast<ConVar*>();
		g_pConVarVFTable = g_GameDll.GetVirtualMethodTable(".?AVConVar@@", 1).RCast<IConVar*>();
	}
	virtual void Attach(void) const;
	virtual void Detach(void) const;
};
///////////////////////////////////////////////////////////////////////////////
#endif 
#endif // CVAR_H
