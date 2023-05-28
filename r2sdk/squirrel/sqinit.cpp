#include "sqinit.h"
#include "squirrel/sqvm.h"
#include "squirrel/squirrelmanager.h"

namespace VSquirrel
{
    namespace SHARED
    {
        //-----------------------------------------------------------------------------
        // Purpose: Returns SDK Version as a string
        //-----------------------------------------------------------------------------
        SQRESULT GetSdkVersion(HSquirrelVM* sqvm)
        {
            ScriptContext context = SQ_GetVMContext(sqvm);

            // TODO [Fifty]: template this ( maybe get rid of namespaces to make registration more readable ? )
            switch (context)
            {
            case ScriptContext::SERVER:
                g_pSQManager<ScriptContext::SERVER>->PushString(sqvm, "0.0", 4);
                break;
            case ScriptContext::CLIENT:
                g_pSQManager<ScriptContext::CLIENT>->PushString(sqvm, "0.0", 4);
                break;
            case ScriptContext::UI:
                g_pSQManager<ScriptContext::UI>->PushString(sqvm, "0.0", 4);
                break;
            }
            return SQRESULT_NOTNULL;
        }
    }
    namespace SERVER
    {
    }
    namespace CLIENT
    {
    }
    namespace UI
    {
    }
}