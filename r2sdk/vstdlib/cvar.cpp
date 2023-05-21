#include "cvar.h"

#include "core/logdef.h"


void* CCvar__Disconnect()
{
	// We use g_pCvar to print to GameConsole, when we're shutting down
	// we need to stop printing to it, otherwise we AV
	g_bLogToGameConsole = false;
	return v_CCvar__Disconnect();
}

void VCVar::Attach(void) const
{
	DetourAttach((LPVOID*)&v_CCvar__Disconnect, &CCvar__Disconnect);
}
void VCVar::Detach(void) const
{
	DetourDetach((LPVOID*)&v_CCvar__Disconnect, &CCvar__Disconnect);
}