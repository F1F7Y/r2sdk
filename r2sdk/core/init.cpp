﻿//=============================================================================//
//
// Purpose: Main systems initialization file
//
//=============================================================================//

#include "core/stdafx.h"
#include "core/logdef.h"
#include "tier0/fasttimer.h"
// Tier0
#include "tier0/platform_internal.h"
//#include "tier0/commandline.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
//
// ██╗███╗   ██╗██╗████████╗██╗ █████╗ ██╗     ██╗███████╗ █████╗ ████████╗██╗ ██████╗ ███╗   ██╗
// ██║████╗  ██║██║╚══██╔══╝██║██╔══██╗██║     ██║╚══███╔╝██╔══██╗╚══██╔══╝██║██╔═══██╗████╗  ██║
// ██║██╔██╗ ██║██║   ██║   ██║███████║██║     ██║  ███╔╝ ███████║   ██║   ██║██║   ██║██╔██╗ ██║
// ██║██║╚██╗██║██║   ██║   ██║██╔══██║██║     ██║ ███╔╝  ██╔══██║   ██║   ██║██║   ██║██║╚██╗██║
// ██║██║ ╚████║██║   ██║   ██║██║  ██║███████╗██║███████╗██║  ██║   ██║   ██║╚██████╔╝██║ ╚████║
// ╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝╚═╝  ╚═╝╚══════╝╚═╝╚══════╝╚═╝  ╚═╝   ╚═╝   ╚═╝ ╚═════╝ ╚═╝  ╚═══╝
//
/////////////////////////////////////////////////////////////////////////////////////////////////

void Systems_PreInit()
{
	spdlog::info("+---------------------------------------------------------------------+\n");
	QuerySystemInfo();

	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());

	// Commit the transaction
	HRESULT hr = DetourTransactionCommit();
	if (hr != NO_ERROR)
	{
		// Failed to hook into the process, terminate
		Error(eDLL_T::COMMON, 0xBAD0C0DE, "Failed to detour process: error code = %08x\n", hr);
	}
}

void Systems_Init()
{
	DetourRegister();
	CFastTimer initTimer;

	initTimer.Start();
	DetourInit();
	initTimer.End();

	spdlog::info("+---------------------------------------------------------------------+\n");
	spdlog::info("{:16s} '{:10.6f}' seconds ('{:12d}' clocks)\n", "Detour->InitDB()", initTimer.GetDuration().GetSeconds(), initTimer.GetDuration().GetCycles());

	initTimer.Start();

	// Begin the detour transaction to hook the process
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());

	// Hook functions
	for (const IDetour* pDetour : g_DetourVector)
	{
		pDetour->Attach();
	}

	// Patch instructions
	//RuntimePtc_Init();

	// Commit the transaction
	HRESULT hr = DetourTransactionCommit();
	if (hr != NO_ERROR)
	{
		// Failed to hook into the process, terminate
		Error(eDLL_T::COMMON, 0xBAD0C0DE, "Failed to detour process: error code = %08x\n", hr);
	}

	initTimer.End();
	spdlog::info("{:16s} '{:10.6f}' seconds ('{:12d}' clocks)\n", "Detour->Attach()", initTimer.GetDuration().GetSeconds(), initTimer.GetDuration().GetCycles());
	spdlog::info("+---------------------------------------------------------------------+\n");

	//ConVar::StaticInit();
}

//////////////////////////////////////////////////////////////////////////
//
// ███████╗██╗  ██╗██╗   ██╗████████╗██████╗  ██████╗ ██╗    ██╗███╗   ██╗
// ██╔════╝██║  ██║██║   ██║╚══██╔══╝██╔══██╗██╔═══██╗██║    ██║████╗  ██║
// ███████╗███████║██║   ██║   ██║   ██║  ██║██║   ██║██║ █╗ ██║██╔██╗ ██║
// ╚════██║██╔══██║██║   ██║   ██║   ██║  ██║██║   ██║██║███╗██║██║╚██╗██║
// ███████║██║  ██║╚██████╔╝   ██║   ██████╔╝╚██████╔╝╚███╔███╔╝██║ ╚████║
// ╚══════╝╚═╝  ╚═╝ ╚═════╝    ╚═╝   ╚═════╝  ╚═════╝  ╚══╝╚══╝ ╚═╝  ╚═══╝
//
//////////////////////////////////////////////////////////////////////////

void Systems_Shutdown()
{
	CFastTimer shutdownTimer;
	shutdownTimer.Start();

	// Begin the detour transaction to unhook the process
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());

	// Unhook functions
	for (const IDetour* pDetour : g_DetourVector)
	{
		pDetour->Detach();
	}

	// Commit the transaction
	DetourTransactionCommit();

	shutdownTimer.End();
	spdlog::info("{:16s} '{:10.6f}' seconds ('{:12d}' clocks)\n", "Detour->Detach()", shutdownTimer.GetDuration().GetSeconds(), shutdownTimer.GetDuration().GetCycles());
	spdlog::info("+---------------------------------------------------------------------+\n");
}

/////////////////////////////////////////////////////
//
// ██╗   ██╗████████╗██╗██╗     ██╗████████╗██╗   ██╗
// ██║   ██║╚══██╔══╝██║██║     ██║╚══██╔══╝╚██╗ ██╔╝
// ██║   ██║   ██║   ██║██║     ██║   ██║    ╚████╔╝ 
// ██║   ██║   ██║   ██║██║     ██║   ██║     ╚██╔╝  
// ╚██████╔╝   ██║   ██║███████╗██║   ██║      ██║   
//  ╚═════╝    ╚═╝   ╚═╝╚══════╝╚═╝   ╚═╝      ╚═╝   
//
/////////////////////////////////////////////////////

void Winsock_Init()
{
	/*
	WSAData wsaData{};
	int nError = ::WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (nError != 0)
	{
		Error(eDLL_T::COMMON, NO_ERROR, "%s: Failed to start Winsock: (%s)\n", __FUNCTION__, NET_ErrorString(WSAGetLastError()));
	}
	*/
}
void Winsock_Shutdown()
{
	/*
	int nError = ::WSACleanup();
	if (nError != 0)
	{
		Error(eDLL_T::COMMON, NO_ERROR, "%s: Failed to stop Winsock: (%s)\n", __FUNCTION__, NET_ErrorString(WSAGetLastError()));
	}
	*/
}
void QuerySystemInfo()
{
#ifndef DEDICATED
	for (int i = 0; ; i++)
	{
		DISPLAY_DEVICE dd = { sizeof(dd), {0} };
		BOOL f = EnumDisplayDevices(NULL, i, &dd, EDD_GET_DEVICE_INTERFACE_NAME);
		if (!f)
		{
			break;
		}

		if (dd.StateFlags & DISPLAY_DEVICE_PRIMARY_DEVICE) // Only log the primary device.
		{
			char szDeviceName[128];
#ifndef UNICODE
			strncpy_s(szDeviceName, dd.DeviceString, sizeof(szDeviceName));
#else
			wcstombs(szDeviceName, dd.DeviceString, sizeof(szDeviceName));
#endif // !UNICODE
			spdlog::info("{:25s}: '{:s}'\n", "GPU model identifier", szDeviceName);
		}
	}
#endif // !DEDICATED

	const CPUInformation& pi = GetCPUInformation();

	spdlog::info("{:25s}: '{:s}'\n", "CPU model identifier", pi.m_szProcessorBrand);
	spdlog::info("{:25s}: '{:s}'\n", "CPU vendor tag", pi.m_szProcessorID);
	spdlog::info("{:25s}: '{:12d}' ('{:2d}' {:s})\n", "CPU core count", pi.m_nPhysicalProcessors, pi.m_nLogicalProcessors, "logical");
	spdlog::info("{:25s}: '{:12d}' ({:12s})\n", "CPU core speed", pi.m_Speed, "Cycles");
	spdlog::info("{:20s}{:s}: '{:12d}' (0x{:<10X})\n", "L1 cache", "(KiB)", pi.m_nL1CacheSizeKb, pi.m_nL1CacheDesc);
	spdlog::info("{:20s}{:s}: '{:12d}' (0x{:<10X})\n", "L2 cache", "(KiB)", pi.m_nL2CacheSizeKb, pi.m_nL2CacheDesc);
	spdlog::info("{:20s}{:s}: '{:12d}' (0x{:<10X})\n", "L3 cache", "(KiB)", pi.m_nL3CacheSizeKb, pi.m_nL3CacheDesc);

	MEMORYSTATUSEX statex{};
	statex.dwLength = sizeof(statex);

	if (GlobalMemoryStatusEx(&statex))
	{
		DWORDLONG totalPhysical = (statex.ullTotalPhys / 1024) / 1024;
		DWORDLONG totalVirtual = (statex.ullTotalVirtual / 1024) / 1024;

		DWORDLONG availPhysical = (statex.ullAvailPhys / 1024) / 1024;
		DWORDLONG availVirtual = (statex.ullAvailVirtual / 1024) / 1024;

		spdlog::info("{:20s}{:s}: '{:12d}' ('{:9d}' {:s})\n", "Total system memory", "(MiB)", totalPhysical, totalVirtual, "virtual");
		spdlog::info("{:20s}{:s}: '{:12d}' ('{:9d}' {:s})\n", "Avail system memory", "(MiB)", availPhysical, availVirtual, "virtual");
	}
	else
	{
		spdlog::error("Unable to retrieve system memory information: {:s}\n",
			std::system_category().message(static_cast<int>(::GetLastError())));
	}
}

void CheckCPU() // Respawn's engine and our SDK utilize POPCNT, SSE3 and SSSE3 (Supplemental SSE 3 Instructions).
{
	/*
	const CPUInformation& pi = GetCPUInformation();
	static char szBuf[1024];
	if (!pi.m_bSSE3)
	{
		V_snprintf(szBuf, sizeof(szBuf), "CPU does not have %s!\n", "SSE 3");
		MessageBoxA(NULL, szBuf, "Unsupported CPU", MB_ICONERROR | MB_OK);
		ExitProcess(0xFFFFFFFF);
	}
	if (!pi.m_bSSSE3)
	{
		V_snprintf(szBuf, sizeof(szBuf), "CPU does not have %s!\n", "SSSE 3 (Supplemental SSE 3 Instructions)");
		MessageBoxA(NULL, szBuf, "Unsupported CPU", MB_ICONERROR | MB_OK);
		ExitProcess(0xFFFFFFFF);
	}
	if (!pi.m_bPOPCNT)
	{
		V_snprintf(szBuf, sizeof(szBuf), "CPU does not have %s!\n", "POPCNT");
		MessageBoxA(NULL, szBuf, "Unsupported CPU", MB_ICONERROR | MB_OK);
		ExitProcess(0xFFFFFFFF);
	}
	*/
}

void DetourInit() // Run the sigscan
{
	LPSTR pCommandLine = GetCommandLineA();

	bool bLogAdr = (strstr(pCommandLine, "-sig_toconsole") != nullptr);
	bool bInitDivider = false;

	//g_SigCache.SetDisabled((strstr(pCommandLine, "-nosmap") != nullptr));
	//g_SigCache.LoadCache(SIGDB_FILE);

	for (const IDetour* pDetour : g_DetourVector)
	{
		pDetour->GetCon(); // Constants.
		pDetour->GetFun(); // Functions.
		pDetour->GetVar(); // Variables.

		if (bLogAdr)
		{
			if (!bInitDivider)
			{
				bInitDivider = true;
				spdlog::debug("+---------------------------------------------------------------------+\n");
			}
			pDetour->GetAdr();
			spdlog::debug("+---------------------------------------------------------------------+\n");
		}
	}

	//g_SigCache.WriteCache(SIGDB_FILE);
	//g_SigCache.InvalidateMap();
}

void DetourAddress() // Test the sigscan results
{
	spdlog::debug("+---------------------------------------------------------------------+\n");
	for (const IDetour* pDetour : g_DetourVector)
	{
		pDetour->GetAdr();
		spdlog::debug("+---------------------------------------------------------------------+\n");
	}
}

void DetourRegister() // Register detour classes to be searched and hooked.
{
	// Tier0
	REGISTER(VPlatform);
}