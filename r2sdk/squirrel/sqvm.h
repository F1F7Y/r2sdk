#pragma once

#include "sqdatatypes.h"
#include "sqclasstypes.h"

///////////////////////////////////////////////////////////////////////////////
template <ScriptContext context>
SQRESULT SQVM_PrintFunc(HSquirrelVM* sqvm, SQChar* fmt, ...);

template <ScriptContext context>
void SQVM_CompileError(HSquirrelVM* sqvm, const SQChar* pszError, const SQChar* pszFile, SQUnsignedInteger nLine, SQInteger nColumn);