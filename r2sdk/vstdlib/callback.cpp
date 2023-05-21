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