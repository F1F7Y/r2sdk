#include "console.h"

#include "gameui/GameConsole.h"

//-----------------------------------------------------------------------------
// Purpose: toggles the console
//-----------------------------------------------------------------------------
void Con_ToggleConsole_f(const CCommand& arg)
{
	if (!g_pGameConsole->m_bInitialized)
	{
		Warning(eDLL_T::NONE, "Tried to toggle console when it is not initilazed!\n");
		return;
	}

	if (g_pGameConsole->IsConsoleVisible())
	{
		g_pGameConsole->Hide();
		DevMsg(eDLL_T::NONE, "hide\n");
	}
	else
	{
		g_pGameConsole->Activate();
		DevMsg(eDLL_T::NONE, "show\n");
	}
}

//-----------------------------------------------------------------------------
// Purpose: hides the console
//-----------------------------------------------------------------------------
void Con_HideConsole_f(const CCommand& arg)
{
	if (!g_pGameConsole->m_bInitialized)
	{
		Warning(eDLL_T::NONE, "Tried to hide console when it is not initilazed!\n");
		return;
	}

	g_pGameConsole->Hide();
}

//-----------------------------------------------------------------------------
// Purpose: shows the console
//-----------------------------------------------------------------------------
void Con_ShowConsole_f(const CCommand& arg)
{
	if (!g_pGameConsole->m_bInitialized)
	{
		Warning(eDLL_T::NONE, "Tried to show console when it is not initilazed!\n");
		return;
	}

	g_pGameConsole->Activate();
}