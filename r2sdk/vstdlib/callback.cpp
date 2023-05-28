//=============================================================================//
//
// Purpose: Callback functions for Concommands
//
//=============================================================================//

#include "callback.h"

/*
=====================
SIG_GetAdr_f

  Logs the sigscan
  results to the console.
=====================
*/
void SIG_GetAdr_f(const CCommand& args)
{
	DetourAddress();
}

/*
=====================
SQVM_ServerScript_f

  Executes input on the
  VM in SERVER context.
=====================
*/
void SQVM_ServerScript_f(const CCommand& args)
{
	if (args.ArgC() >= 2)
	{
		//Script_Execute(args.ArgS(), SQCONTEXT::SERVER);
	}
}

/*
=====================
SQVM_ClientScript_f

  Executes input on the
  VM in CLIENT context.
=====================
*/
void SQVM_ClientScript_f(const CCommand& args)
{
	if (args.ArgC() >= 2)
	{
		//Script_Execute(args.ArgS(), SQCONTEXT::CLIENT);
	}
}

/*
=====================
SQVM_UIScript_f

  Executes input on the
  VM in UI context.
=====================
*/
void SQVM_UIScript_f(const CCommand& args)
{
	if (args.ArgC() >= 2)
	{
		//Script_Execute(args.ArgS(), SQCONTEXT::UI);
	}
}