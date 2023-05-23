#include "squirrel/sqscript.h"

#include "squirrel/sqvm.h"
#include "squirrel/client/sqscript.h"
#include "squirrel/server/sqscript.h"

template <ScriptContext context>
CSquirrelVM* CSquirrelVM_Init(CSquirrelVM* sqvm, ScriptContext nSqContext)
{
	DevMsg((eDLL_T)context, "Created %s VM: '0x%p'\n", SQ_GetContextName(nSqContext).c_str(), sqvm);
	return v_CSquirrelVM_Init<context>(sqvm, nSqContext);
}

///////////////////////////////////////////////////////////////////////////////
// CLIENT
void VSQVM_CLIENT::Attach(void) const
{
	DetourAttach((LPVOID*)&v_CSquirrelVM_Init<ScriptContext::CLIENT>, &CSquirrelVM_Init<ScriptContext::CLIENT>);
}

void VSQVM_CLIENT::Detach(void) const
{
	DetourDetach((LPVOID*)&v_CSquirrelVM_Init<ScriptContext::CLIENT>, &CSquirrelVM_Init<ScriptContext::CLIENT>);
}

///////////////////////////////////////////////////////////////////////////////
// SERVER
void VSQVM_SERVER::Attach(void) const
{
	DetourAttach((LPVOID*)&v_CSquirrelVM_Init<ScriptContext::SERVER>, &CSquirrelVM_Init<ScriptContext::SERVER>);
}

void VSQVM_SERVER::Detach(void) const
{
	DetourDetach((LPVOID*)&v_CSquirrelVM_Init<ScriptContext::SERVER>, &CSquirrelVM_Init<ScriptContext::SERVER>);
}
