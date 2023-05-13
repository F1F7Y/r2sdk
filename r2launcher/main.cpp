#include <Windows.h>
#include <shlwapi.h>
#include <iostream>
#include <string>

bool GetExePathW(wchar_t* dest, DWORD destSize)
{
	if (!dest)
		return NULL;
	if (destSize < MAX_PATH)
		return NULL;

	DWORD length = GetModuleFileNameW(NULL, dest, destSize);
	return length && PathRemoveFileSpecW(dest);
}

void Error(std::string szErrorMessage)
{
	MessageBoxA(
		GetForegroundWindow(),
		szErrorMessage.c_str(),
		"Launcher error",
		0
	);
}

int APIENTRY WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nShowCmd
)
{
	WCHAR szExePath[MAX_PATH];
	WCHAR szPathBuffer[MAX_PATH];

	if (!GetExePathW(szExePath, sizeof(szExePath)))
	{
		Error("Failed to get executable path!");
		return EXIT_FAILURE;
	}

	SetCurrentDirectoryW(szExePath);

	swprintf_s(szPathBuffer, L"%s\\bin\\x64_retail\\launcher.dll", szExePath);
	HMODULE hLauncher = LoadLibraryExW(szPathBuffer, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
	if (hLauncher == NULL)
	{
		Error("Failed to load launcher.dll!");
		return EXIT_FAILURE;
	}

	swprintf_s(szPathBuffer, L"%s\\r2sdk.dll", szExePath);
	HMODULE hSDK = LoadLibraryExW(szPathBuffer, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
	if (hSDK == NULL)
	{
		Error("Failed to load r2sdk.dll!");
		return EXIT_FAILURE;
	}

	FARPROC LauncherMain;
	LauncherMain = GetProcAddress(hLauncher, "LauncherMain");

	return ((int(*)(HINSTANCE, HINSTANCE, LPSTR, int))LauncherMain)(NULL, NULL, NULL, 0);
}