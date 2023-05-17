#include "vgui_baseui_interface.h"
#include "gameui/GameConsole.h"
#include "core/logdef.h"

char CEngine__Init(void* self)
{
	char cResult = v_CEngineVGui__Init(self);
	DevMsg(eDLL_T::NONE, "CEngine__Init: %i\n", cResult);
	g_pGameConsole->Initialize();
	return cResult;
}

void VEngineVgui::Attach(void) const
{
	DetourAttach((LPVOID*)&v_CEngineVGui__Init, &CEngine__Init);
}

void VEngineVgui::Detach(void) const
{
	DetourDetach((LPVOID*)&v_CEngineVGui__Init, &CEngine__Init);
}