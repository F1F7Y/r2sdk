#pragma once

#include "sqdatatypes.h"
#include "sqclasstypes.h"

///////////////////////////////////////////////////////////////////////////////
template <ScriptContext context>
SQRESULT SQVM_PrintFunc(HSquirrelVM* sqvm, SQChar* fmt, ...);