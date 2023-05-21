#pragma once

#include "filesystem.h"

inline CMemory p_CBaseFileSystem__ReadFileFromVPK;
inline auto v_CBaseFileSystem__ReadFileFromVPK = p_CBaseFileSystem__ReadFileFromVPK.RCast<FileHandle_t(*)(void *self, FileHandle_t pResult, char* pszFilePath)>();

inline CMemory p_CBaseFileSystem_LoadFromCache;
inline auto v_CBaseFileSystem_LoadFromCache = p_CBaseFileSystem_LoadFromCache.RCast<bool(*)(void* self, char* pszFilePath, void* pResult)>();

///////////////////////////////////////////////////////////////////////////////
class VBaseFileSystem : public IDetour
{
	virtual void GetAdr(void) const
	{
		LogFunAdr("CBaseFileSystem::ReadFileFromVPK", p_CBaseFileSystem__ReadFileFromVPK.GetPtr());
	}
	virtual void GetFun(void) const
	{
		p_CBaseFileSystem__ReadFileFromVPK = g_pFSStdioDll->FindPatternSIMD("48 89 5C 24 08 57 48 81 EC C0");
		v_CBaseFileSystem__ReadFileFromVPK = p_CBaseFileSystem__ReadFileFromVPK.RCast<FileHandle_t(*)(void* self, FileHandle_t pResult, char* pszFilePath)>();

		p_CBaseFileSystem_LoadFromCache = g_pFSStdioDll->FindPatternSIMD("40 53 48 81 EC 40 02 00");
		v_CBaseFileSystem_LoadFromCache = p_CBaseFileSystem_LoadFromCache.RCast<bool(*)(void* self, char* pszFilePath, void* pResult)>();
	}
	virtual void GetVar(void) const { }
	virtual void GetCon(void) const { }
	virtual void Attach(void) const;
	virtual void Detach(void) const;
};