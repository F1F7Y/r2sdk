#include "sqvm.h"

#include "client/sqvm.h"
#include "server/sqvm.h"
#include "ui/sqvm.h"

template <ScriptContext context>
SQRESULT SQVM_PrintFunc(HSquirrelVM* sqvm, SQChar* fmt, ...)
{
	eDLL_T remoteContext;

	switch (context)
	{
	case ScriptContext::SERVER:
		remoteContext = eDLL_T::SCRIPT_SERVER;
		break;
	case ScriptContext::CLIENT:
		remoteContext = eDLL_T::SCRIPT_CLIENT;
		break;
	case ScriptContext::UI:
		remoteContext = eDLL_T::SCRIPT_UI;
		break;
	default: // Maybe we should throw an error here ?
		remoteContext = eDLL_T::NONE;
		break;
	}

	// TODO: 

	LogLevel_t level = LogLevel_t::LEVEL_CONSOLE;
	LogType_t type = LogType_t::SQ_INFO;

	va_list args;
	va_start(args, fmt);
	CoreMsgV(type, level, remoteContext, "squirrel_re", fmt, args);
	va_end(args);

	return SQRESULT_NULL;
}

///////////////////////////////////////////////////////////////////////////////
// CLIENT
void HSQVM_CLIENT::Attach(void) const
{
	DetourAttach((LPVOID*)&v_SQVM_CLIENT_PrintFunc, &SQVM_PrintFunc<ScriptContext::CLIENT>);
}

void HSQVM_CLIENT::Detach(void) const
{
	DetourDetach((LPVOID*)&v_SQVM_CLIENT_PrintFunc, &SQVM_PrintFunc<ScriptContext::CLIENT>);
}

///////////////////////////////////////////////////////////////////////////////
// SERVER
void HSQVM_SERVER::Attach(void) const
{
	DetourAttach((LPVOID*)&v_SQVM_SERVER_PrintFunc, &SQVM_PrintFunc<ScriptContext::SERVER>);
}

void HSQVM_SERVER::Detach(void) const
{
	DetourDetach((LPVOID*)&v_SQVM_SERVER_PrintFunc, &SQVM_PrintFunc<ScriptContext::SERVER>);
}

///////////////////////////////////////////////////////////////////////////////
// UI
void HSQVM_UI::Attach(void) const
{
	DetourAttach((LPVOID*)&v_SQVM_UI_PrintFunc, &SQVM_PrintFunc<ScriptContext::UI>);
}

void HSQVM_UI::Detach(void) const
{
	DetourDetach((LPVOID*)&v_SQVM_UI_PrintFunc, &SQVM_PrintFunc<ScriptContext::UI>);
}