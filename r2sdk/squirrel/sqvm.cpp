#include "sqvm.h"

#include "client/sqvm.h"
#include "server/sqvm.h"
#include "ui/sqvm.h"

template <ScriptContext context>
SQRESULT SQVM_PrintFunc(HSquirrelVM* sqvm, SQChar* fmt, ...)
{
	eDLL_T logContext = (eDLL_T)context;

	LogLevel_t level = LogLevel_t::LEVEL_CONSOLE;
	LogType_t type = LogType_t::SQ_INFO;

	va_list args;
	va_start(args, fmt);
	CoreMsgV(type, level, logContext, "squirrel_re", fmt, args);
	va_end(args);

	return SQRESULT_NULL;
}

template <ScriptContext context>
void SQVM_CompileError(HSquirrelVM* sqvm, const SQChar* pszError, const SQChar* pszFile, SQUnsignedInteger nLine, SQInteger nColumn)
{
	eDLL_T logContext = (eDLL_T)context;

	// TODO [Fifty]: Detect UI VM as Client and Ui share the same function
	// TODO [Fifty]: Automatically disconnect teh player on Client && Ui
	//               errors so we don't AV

	Error(logContext, NO_ERROR, "Compile error: '%s'\n", pszError);
	Error(logContext, NO_ERROR, "  '%s': line [%d] column [%d]\n", pszFile, nLine, nColumn);
}

///////////////////////////////////////////////////////////////////////////////
// CLIENT
void HSQVM_CLIENT::Attach(void) const
{
	DetourAttach((LPVOID*)&v_SQVM_CLIENT_PrintFunc, &SQVM_PrintFunc<ScriptContext::CLIENT>);
	DetourAttach((LPVOID*)&v_SQVM_CLIENT_CompileError, &SQVM_CompileError<ScriptContext::CLIENT>);
}

void HSQVM_CLIENT::Detach(void) const
{
	DetourDetach((LPVOID*)&v_SQVM_CLIENT_PrintFunc, &SQVM_PrintFunc<ScriptContext::CLIENT>);
	DetourDetach((LPVOID*)&v_SQVM_CLIENT_CompileError, &SQVM_CompileError<ScriptContext::CLIENT>);
}

///////////////////////////////////////////////////////////////////////////////
// SERVER
void HSQVM_SERVER::Attach(void) const
{
	DetourAttach((LPVOID*)&v_SQVM_SERVER_PrintFunc, &SQVM_PrintFunc<ScriptContext::SERVER>);
	DetourAttach((LPVOID*)&v_SQVM_SERVER_CompileError, &SQVM_CompileError<ScriptContext::SERVER>);
}

void HSQVM_SERVER::Detach(void) const
{
	DetourDetach((LPVOID*)&v_SQVM_SERVER_PrintFunc, &SQVM_PrintFunc<ScriptContext::SERVER>);
	DetourDetach((LPVOID*)&v_SQVM_SERVER_CompileError, &SQVM_CompileError<ScriptContext::SERVER>);
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