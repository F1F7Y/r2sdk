#include "basefilesystem.h"


bool CBaseFilesystem__VCheckDisk(const char* pszFilePath)
{
	std::string svFilePath = ConvertToWinPath(pszFilePath);
	if (svFilePath.find("\\*\\") != string::npos)
	{
		// Erase '//*/'.
		svFilePath.erase(0, 4);
	}

	fs::path filePath(svFilePath);
	if (filePath.is_absolute())
	{
		// Skip absolute file paths.
		return false;
	}

	// TODO: obtain 'mod' SearchPath's instead.
	svFilePath.insert(0, "platform\\");

	if (::FileExists(svFilePath) /*|| ::FileExists(pszFilePath)*/)
	{
		return true;
	}

	return false;
}


FileHandle_t CBaseFileSystem__ReadFileFromVPK(void* self, FileHandle_t pResult, char* pszFilePath)
{
	//DevMsg(eDLL_T::FS, "ReadFileFromVPK: %s\n", pszFilePath);

	if (CBaseFilesystem__VCheckDisk(pszFilePath))
	{
		*reinterpret_cast<int64_t*>(pResult) = -1;
		return pResult;
	}

	return v_CBaseFileSystem__ReadFileFromVPK(self, pResult, pszFilePath);
}

bool CBaseFileSystem_LoadFromCache(void* self, char* pszFilePath, void* pResult)
{
	//DevMsg(eDLL_T::FS, "LoadFromCache: %s\n", pszFilePath);

	// Invalidate cache entry if the file exists on disk
	// so we can then redirect to it in ReadFileFromVPK
	if (CBaseFilesystem__VCheckDisk(pszFilePath))
	{
		return false;
	}

	return v_CBaseFileSystem_LoadFromCache(self, pszFilePath, pResult);
}

void VBaseFileSystem::Attach() const
{
	DetourAttach((LPVOID*)&v_CBaseFileSystem__ReadFileFromVPK, &CBaseFileSystem__ReadFileFromVPK);
	DetourAttach((LPVOID*)&v_CBaseFileSystem_LoadFromCache, &CBaseFileSystem_LoadFromCache);
}
void VBaseFileSystem::Detach() const
{
	DetourDetach((LPVOID*)&v_CBaseFileSystem__ReadFileFromVPK, &CBaseFileSystem__ReadFileFromVPK);
	DetourDetach((LPVOID*)&v_CBaseFileSystem_LoadFromCache, &CBaseFileSystem_LoadFromCache);
}