#pragma once

#include "sqdatatypes.h"
#include "sqclasstypes.h"

///////////////////////////////////////////////////////////////////////////////

template<ScriptContext context>
inline CMemory p_CSquirrelVM_Init;
template<ScriptContext context>
inline auto v_CSquirrelVM_Init = p_CSquirrelVM_Init<context>.RCast<CSquirrelVM*(*)(CSquirrelVM* sqvm, ScriptContext nSqContext)>();

///////////////////////////////////////////////////////////////////////////////
template <ScriptContext context>
CSquirrelVM* CSquirrelVM_Init(CSquirrelVM* sqvm, ScriptContext nSqContext);