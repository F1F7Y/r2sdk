#include "core/stdafx.h"
#include "core/r2dev.h"
#include "core/init.h"
#include "core/logdef.h"

#include "windows/console.h"

void SDK_Init()
{
    g_svCmdLine = GetCommandLineA();

#ifndef DEDICATED
    if (g_svCmdLine.find("-wconsole") != std::string::npos || true)
    {
        Console_Init();
    }
#else
    Console_Init();
#endif // !DEDICATED

    SpdLog_Init();

    for (size_t i = 0; i < SDK_ARRAYSIZE(R2SDK_EMBLEM); i++)
    {
        string svEscaped = StringEscape(R2SDK_EMBLEM[i]);
        spdlog::info("{:s}{:s}{:s}\n", g_svCyanF, svEscaped, g_svReset);
    }

    Systems_PreInit();
}

void SDK_Shutdown()
{
    Console_Shutdown();
    SpdLog_Shutdown();

    Systems_Shutdown();
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved) {
    switch (dwReason) {
        case DLL_PROCESS_ATTACH:
            SDK_Init();
            break;
        case DLL_PROCESS_DETACH:
            SDK_Shutdown();
            break;
    };

    return TRUE;
}