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

bool CBaseFileSystem__LoadFromCache(void* self, char* pszFilePath, void* pResult)
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

VPKData_t* CBaseFileSystem__MountVPKFile(void* self, const char* pszVpkPath)
{
	int nHandle = v_CBaseFileSystem__GetMountedVPKHandle(self, pszVpkPath);
	VPKData_t* pData = v_CBaseFileSystem_MountVPKFile(self, pszVpkPath);

	if (pData)
	{
		if (nHandle < 0) // Only log if vpk hasn't been mounted yet...
		{
			DevMsg(eDLL_T::FS, "Mounted VPK file: '%s' with handle: '%i'\n", pszVpkPath, pData->m_nHandle);
		}
	}
	else
	{
		Warning(eDLL_T::FS, "Unable to mount VPK file: '%s'\n", pszVpkPath);
	}

	return pData;
}

const char* CBaseFileSystem__UnmountVPKFile(void* self, const char* pszVpkPath)
{
	int nHandle = v_CBaseFileSystem__GetMountedVPKHandle(self, pszVpkPath);
	const char* pRet = v_CBaseFileSystem__UnmountVPKFile(self, pszVpkPath);

	if (nHandle >= 0)
	{
		DevMsg(eDLL_T::FS, "Unmounted VPK file: '%s' with handle: '%i'\n", pszVpkPath, nHandle);
	}

	return pRet;
}

void VBaseFileSystem::Attach() const
{
	DetourAttach((LPVOID*)&v_CBaseFileSystem__ReadFileFromVPK, &CBaseFileSystem__ReadFileFromVPK);
	DetourAttach((LPVOID*)&v_CBaseFileSystem_LoadFromCache, &CBaseFileSystem__LoadFromCache);
	DetourAttach((LPVOID*)&v_CBaseFileSystem_MountVPKFile, &CBaseFileSystem__MountVPKFile);
	DetourAttach((LPVOID*)&v_CBaseFileSystem__UnmountVPKFile, &CBaseFileSystem__UnmountVPKFile);
}
void VBaseFileSystem::Detach() const
{
	DetourDetach((LPVOID*)&v_CBaseFileSystem__ReadFileFromVPK, &CBaseFileSystem__ReadFileFromVPK);
	DetourDetach((LPVOID*)&v_CBaseFileSystem_LoadFromCache, &CBaseFileSystem__LoadFromCache);
	DetourDetach((LPVOID*)&v_CBaseFileSystem_MountVPKFile, &CBaseFileSystem__MountVPKFile);
	DetourAttach((LPVOID*)&v_CBaseFileSystem__UnmountVPKFile, &CBaseFileSystem__UnmountVPKFile);
}