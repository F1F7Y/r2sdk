
#include "windows/console.h"

void SDK_Init()
{
    Console_Init();
}

void SDK_Shutdown()
{
    Console_Shutdown();
    //SpdLog_Shutdown();

    //Systems_Shutdown();
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