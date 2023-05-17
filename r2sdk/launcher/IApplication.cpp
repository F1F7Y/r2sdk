#include "launcher/IApplication.h"

#include "interfaces/interfaces.h"
#include "tier1/cvar.h"
#include "gameui/GameConsole.h"

int CModAppSystemGroup__Main(void* pModAppSystemGroup, void *a2)
{
	DevMsg(eDLL_T::NONE, "CModAppSystemGroup__Main\n");

	// Get factories
	g_pCVar = Sys_GetFactoryPtr("vstdlib.dll", CVAR_INTERFACE_VERSION).RCast<ICvar*>();
	g_pGameConsole = Sys_GetFactoryPtr("client.dll", GAMECONSOLE_INTERFACE_VERSION).RCast<IGameConsole*>();
	
	return v_CModAppSystemGroup__Main(pModAppSystemGroup, a2);
}

bool CModAppSystemGroup__Create(void* pModAppSystemGroup)
{
	DevMsg(eDLL_T::NONE, "CModAppSystemGroup__Create\n");
	return v_CModAppSystemGroup__Create(pModAppSystemGroup);
}

///////////////////////////////////////////////////////////////////////////////
void VApplication::Attach(void) const
{
	DetourAttach((LPVOID*)&v_CModAppSystemGroup__Main, &CModAppSystemGroup__Main);
	DetourAttach((LPVOID*)&v_CModAppSystemGroup__Create, &CModAppSystemGroup__Create);
}
void VApplication::Detach(void) const
{
	DetourDetach((LPVOID*)&v_CModAppSystemGroup__Main, &CModAppSystemGroup__Main);
	DetourDetach((LPVOID*)&v_CModAppSystemGroup__Create, &CModAppSystemGroup__Create);
}