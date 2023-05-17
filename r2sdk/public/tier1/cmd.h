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

#ifndef CMD_H
#define CMD_H

//#include "tier1/utlvector.h"
//#include "tier1/utlstring.h"
//#include "tier1/characterset.h"
#include "public/iconvar.h"
#include "public/iconcommand.h"
#include "mathlib/color.h"

//-----------------------------------------------------------------------------
// Forward declarations
//-----------------------------------------------------------------------------
class ConCommandBase;

//-----------------------------------------------------------------------------
// Any executable that wants to use ConVars need to implement one of
// these to hook up access to console variables.
//-----------------------------------------------------------------------------
class IConCommandBaseAccessor
{
public:
	// Flags is a combination of FCVAR flags in cvar.h.
	// hOut is filled in with a handle to the variable.
	virtual bool RegisterConCommandBase(ConCommandBase* pVar) = 0;
};

//-----------------------------------------------------------------------------
// Purpose: Command tokenizer
//-----------------------------------------------------------------------------
class CCommand
{
private:
	enum
	{
		COMMAND_MAX_ARGC = 64,
		COMMAND_MAX_LENGTH = 512,
	};
public:
	CCommand() = delete;

	int64_t ArgC() const;
	const char** ArgV() const;
	const char* ArgS() const; // All args that occur after the 0th arg, in string form
	const char* GetCommandString() const; // The entire command in string form, including the 0th arg
	const char* operator[](int nIndex) const; // Gets at arguments
	const char* Arg(int nIndex) const; // Gets at arguments

	static int MaxCommandLength();

private:
	int64_t m_nArgc;
	int64_t m_nArgv0Size;
	char m_pArgSBuffer[COMMAND_MAX_LENGTH];
	char m_pArgvBuffer[COMMAND_MAX_LENGTH];
	const char* m_ppArgv[COMMAND_MAX_ARGC];
};

//-----------------------------------------------------------------------------
// Purpose: The base console invoked command/cvar interface
//-----------------------------------------------------------------------------
class ConCommandBase
{
public:
	bool HasFlags(int nFlags);
	void AddFlags(int nFlags);
	void RemoveFlags(int nFlags);

	bool IsCommand(void) const;
	bool IsRegistered(void) const;
	bool IsFlagSet(int nFlags) const;
	static bool IsFlagSet(ConCommandBase* pCommandBase, int nFlags); // For hooking to engine's implementation.

	int GetFlags(void) const;
	ConCommandBase* GetNext(void) const;
	const char* GetHelpText(void) const;

	char* CopyString(const char* szFrom) const;

	void* m_pConCommandBaseVTable; // 0x0000
	ConCommandBase* m_pNext; // 0x0008
	bool m_bRegistered; // 0x0010
	char pad_0011[7]; // 0x0011 <- 3 bytes padding + unk int32.
	const char* m_pszName; // 0x0018
	const char* m_pszHelpString; // 0x0020
	int m_nFlags; // 0x0028
	ConCommandBase* s_pConCommandBases; // 0x002C
	IConCommandBaseAccessor* s_pAccessor; // 0x0034
}; // Size: 0x0040
static_assert(sizeof(ConCommandBase) == 0x40);

//-----------------------------------------------------------------------------
// Purpose: The console invoked command
//-----------------------------------------------------------------------------
class ConCommand : public ConCommandBase
{
	friend class CCVar;

public:
	ConCommand(void); // !TODO: Rebuild engine constructor in SDK instead.
	ConCommand(const char* szName, const char* szHelpString, int nFlags, void* pCallback, void* pCommandCompletionCallback);

	static ConCommand* StaticCreate(const char* szName, const char* szHelpString, int nFlags,
		FnCommandCallback_t pCallback, FnCommandCompletionCallback pCommandCompletionCallback);

	static void StaticInit(void);
	static void InitShipped(void);
	static void PurgeShipped(void);

	void Init(void);
	bool IsCommand(void) const;

	FnCommandCallback_t m_fnCommandCallback{}; // 0x0040 <- starts from 0x40 since we inherit ConCommandBase.
	FnCommandCompletionCallback m_fnCompletionCallback{}; // 0x0048 <- defaults to sub_180417410 ('xor eax, eax').
	int m_nCallbackFlags{}; // 0x0050
	char pad_0054[4]; // 0x0054
	int unk0; // 0x0058
	int unk1; // 0x005C
}; // Size: 0x0060

/* ==== CONCOMMAND ====================================================================================================================================================== */

/*
typedef void (*ConCommandConstructorType)(
	ConCommand* newCommand, const char* name, FnCommandCallback_t callback, const char* helpString, int flags, void* parent);
*/

inline CMemory p_ConCommand_ConCommand;
inline auto v_ConCommand_ConCommand = p_ConCommand_ConCommand.RCast<void(*)(void* newCommand, const char* name, FnCommandCallback_t callback, const char* helpString, int flags, void* parent)>();

inline ConCommandBase* g_pConCommandVFTable;

///////////////////////////////////////////////////////////////////////////////
class VConCommand : public IDetour
{
	virtual void GetAdr(void) const
	{
		LogFunAdr("ConCommand::ConCommand", p_ConCommand_ConCommand.GetPtr());
		//LogFunAdr("ConCommandBase::IsFlagSet", p_ConCommandBase_IsFlagSet.GetPtr());
		//LogConAdr("ConCommand::AutoCompleteSuggest", p_ConCommand_AutoCompleteSuggest.GetPtr());
		//LogFunAdr("Cbuf_AddText", p_Cbuf_AddText.GetPtr());
		//LogFunAdr("Cbuf_Execute", p_Cbuf_Execute.GetPtr());
		//LogFunAdr("Cmd_ForwardToServer", p_Cmd_ForwardToServer.GetPtr());
		//LogFunAdr("CallbackStub", p_CallbackStub.GetPtr());
		//LogFunAdr("NullSub", p_NullSub.GetPtr());
	}
	virtual void GetFun(void) const
	{
		p_ConCommand_ConCommand = g_pEngineDll->FindPatternSIMD("40 53 48 83 EC 20 48 8B D9 45 33 D2 4C 89 41 40");
		v_ConCommand_ConCommand = p_ConCommand_ConCommand.RCast<void(*)(void* newCommand, const char* name, FnCommandCallback_t callback, const char* helpString, int flags, void* parent)>();
		//p_ConCommand_AutoCompleteSuggest = g_GameDll.FindPatternSIMD("40 ?? B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 48 2B E0 F6 41 60 04");
		//p_ConCommandBase_IsFlagSet = g_GameDll.FindPatternSIMD("85 51 38 0F 95 C0 C3");

		//p_Cbuf_AddText = g_GameDll.FindPatternSIMD("48 89 5C 24 ?? 48 89 74 24 ?? 57 48 83 EC 20 48 63 D9 41 8B F8 48 8D 0D ?? ?? ?? ?? 48 8B F2 FF 15 ?? ?? ?? ?? 48 8D 05 ?? ?? ?? ?? 41 B9 ?? ?? ?? ??");
		//p_Cbuf_Execute = g_GameDll.FindPatternSIMD("48 89 5C 24 ?? 48 89 6C 24 ?? 48 89 74 24 ?? 57 48 83 EC 20 FF 15 ?? ?? ?? ??");
		//p_Cmd_ForwardToServer = g_GameDll.FindPatternSIMD("48 89 5C 24 ?? 48 89 6C 24 ?? 48 89 74 24 ?? 57 48 81 EC ?? ?? ?? ?? 44 8B 59 04");
		//p_NullSub = g_GameDll.FindPatternSIMD("C2 ?? ?? CC CC CC CC CC CC CC CC CC CC CC CC CC 40 53 48 83 EC 20 48 8D 05 ?? ?? ?? ??");
		//p_CallbackStub = g_GameDll.FindPatternSIMD("33 C0 C3 CC CC CC CC CC CC CC CC CC CC CC CC CC 80 49 68 08");

		//ConCommandBase_IsFlagSet = p_ConCommandBase_IsFlagSet.RCast<bool (*)(ConCommandBase*, int)>(); /*85 51 38 0F 95 C0 C3*/
		//ConCommand_AutoCompleteSuggest = p_ConCommand_AutoCompleteSuggest.RCast<bool (*)(ConCommand*, const char*, CUtlVector< CUtlString >&)>();

		//Cbuf_AddText = p_Cbuf_AddText.RCast<void (*)(ECommandTarget_t, const char*, cmd_source_t)>(); /*48 89 5C 24 ?? 48 89 74 24 ?? 57 48 83 EC 20 48 63 D9 41 8B F8 48 8D 0D ?? ?? ?? ?? 48 8B F2 FF 15 ?? ?? ?? ?? 48 8D 05 ?? ?? ?? ?? 41 B9 ?? ?? ?? ??*/
		//Cbuf_Execute = p_Cbuf_Execute.RCast<void (*)(void)>();                                        /*48 89 5C 24 ?? 48 89 6C 24 ?? 48 89 74 24 ?? 57 48 83 EC 20 FF 15 ?? ?? ?? ??*/
		//v_Cmd_ForwardToServer = p_Cmd_ForwardToServer.RCast<bool (*)(const CCommand*)>();           /*48 89 5C 24 ?? 48 89 6C 24 ?? 48 89 74 24 ?? 57 48 81 EC ?? ?? ?? ?? 44 8B 59 04*/
		//NullSub = p_NullSub.RCast<void(*)(void)>();                                   /*C2 00 00 CC CC CC CC CC CC CC CC CC CC CC CC CC 40 53 48 83 EC 20 48 8D 05 ?? ?? ?? ??*/
		//CallbackStub = p_CallbackStub.RCast<FnCommandCompletionCallback>();                /*33 C0 C3 CC CC CC CC CC CC CC CC CC CC CC CC CC 80 49 68 08*/ /*UserMathErrorFunction*/
	}
	virtual void GetVar(void) const { }
	virtual void GetCon(void) const
	{
		g_pConCommandVFTable = g_pEngineDll->GetVirtualMethodTable(".?AVConCommand@@").RCast<ConCommandBase*>();
	}
	virtual void Attach(void) const;
	virtual void Detach(void) const;
};
///////////////////////////////////////////////////////////////////////////////

#endif // CMD_H
