#include "core/logdef.h"
#include "launcher/launcher.h"

int LauncherMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	SpdLog_PostInit();
	DevMsg(eDLL_T::NONE, "LauncherMain\n");
	return v_LauncherMain(hInstance, hPrevInstance, lpCmdLine, nShowCmd);
}

void VLauncher::Attach(void) const
{
	DetourAttach((LPVOID*)&v_LauncherMain, &LauncherMain);
}

void VLauncher::Detach(void) const
{
	DetourDetach((LPVOID*)&v_LauncherMain, &LauncherMain);
}