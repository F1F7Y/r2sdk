#ifndef ICONVAR_H
#define ICONVAR_H

//-----------------------------------------------------------------------------
// Forward declarations
//-----------------------------------------------------------------------------
class IConVar;
class CCommand;

//-----------------------------------------------------------------------------
// Command to ConVars and ConCommands
//-----------------------------------------------------------------------------
// The default, no flags at all
#define FCVAR_NONE 0

// Command to ConVars and ConCommands
// ConVar Systems
#define FCVAR_UNREGISTERED (1 << 0) // If this is set, don't add to linked list, etc.
#define FCVAR_DEVELOPMENTONLY (1 << 1) // Hidden in released products. Flag is removed automatically if ALLOW_DEVELOPMENT_CVARS is defined.
#define FCVAR_GAMEDLL (1 << 2) // defined by the game DLL
#define FCVAR_CLIENTDLL (1 << 3) // defined by the client DLL
#define FCVAR_HIDDEN (1 << 4) // Hidden. Doesn't appear in find or auto complete. Like DEVELOPMENTONLY, but can't be compiled out.

// ConVar only
#define FCVAR_PROTECTED                                                                                                                    \
	(1 << 5) // It's a server cvar, but we don't send the data since it's a password, etc.  Sends 1 if it's not bland/zero, 0 otherwise as
			 // value.
#define FCVAR_SPONLY (1 << 6) // This cvar cannot be changed by clients connected to a multiplayer server.
#define FCVAR_ARCHIVE (1 << 7) // set to cause it to be saved to vars.rc
#define FCVAR_NOTIFY (1 << 8) // notifies players when changed
#define FCVAR_USERINFO (1 << 9) // changes the client's info string

#define FCVAR_PRINTABLEONLY (1 << 10) // This cvar's string cannot contain unprintable characters ( e.g., used for player name etc ).
#define FCVAR_GAMEDLL_FOR_REMOTE_CLIENTS                                                                                                   \
	(1 << 10) // When on concommands this allows remote clients to execute this cmd on the server.
			  // We are changing the default behavior of concommands to disallow execution by remote clients without
			  // this flag due to the number existing concommands that can lag or crash the server when clients abuse them.

#define FCVAR_UNLOGGED (1 << 11) // If this is a FCVAR_SERVER, don't log changes to the log file / console if we are creating a log
#define FCVAR_NEVER_AS_STRING (1 << 12) // never try to print that cvar

// It's a ConVar that's shared between the client and the server.
// At signon, the values of all such ConVars are sent from the server to the client (skipped for local client, of course )
// If a change is requested it must come from the console (i.e., no remote client changes)
// If a value is changed while a server is active, it's replicated to all connected clients
#define FCVAR_REPLICATED (1 << 13) // server setting enforced on clients, TODO rename to FCAR_SERVER at some time
#define FCVAR_CHEAT (1 << 14) // Only useable in singleplayer / debug / multiplayer & sv_cheats
#define FCVAR_SS (1 << 15) // causes varnameN where N == 2 through max splitscreen slots for mod to be autogenerated
#define FCVAR_DEMO (1 << 16) // record this cvar when starting a demo file
#define FCVAR_DONTRECORD (1 << 17) // don't record these command in demofiles
#define FCVAR_SS_ADDED (1 << 18) // This is one of the "added" FCVAR_SS variables for the splitscreen players
#define FCVAR_RELEASE (1 << 19) // Cvars tagged with this are the only cvars avaliable to customers
#define FCVAR_RELOAD_MATERIALS (1 << 20) // If this cvar changes, it forces a material reload
#define FCVAR_RELOAD_TEXTURES (1 << 21) // If this cvar changes, if forces a texture reload

#define FCVAR_NOT_CONNECTED (1 << 22) // cvar cannot be changed by a client that is connected to a server
#define FCVAR_MATERIAL_SYSTEM_THREAD (1 << 23) // Indicates this cvar is read from the material system thread
#define FCVAR_ARCHIVE_PLAYERPROFILE (1 << 24) // respawn-defined flag, same as FCVAR_ARCHIVE but writes to profile.cfg

#define FCVAR_SERVER_CAN_EXECUTE                                                                                                           \
	(1 << 28) // the server is allowed to execute this command on clients via
			  // ClientCommand/NET_StringCmd/CBaseClientState::ProcessStringCmd.
#define FCVAR_SERVER_CANNOT_QUERY                                                                                                          \
	(1 << 29) // If this is set, then the server is not allowed to query this cvar's value (via IServerPluginHelpers::StartQueryCvarValue).

// !!!NOTE!!! : this is likely incorrect, there are multiple concommands that the vanilla game registers with this flag that 100% should not
// be remotely executable i.e. multiple commands that only exist on client (screenshot, joystick_initialize) we now use
// FCVAR_GAMEDLL_FOR_REMOTE_CLIENTS in all places this flag was previously used
#define FCVAR_CLIENTCMD_CAN_EXECUTE                                                                                                        \
	(1 << 30) // IVEngineClient::ClientCmd is allowed to execute this command.
			  // Note: IVEngineClient::ClientCmd_Unrestricted can run any client command.

#define FCVAR_ACCESSIBLE_FROM_THREADS (1 << 25) // used as a debugging tool necessary to check material system thread convars
//-----------------------------------------------------------------------------
// Called when a ConCommand needs to execute
//-----------------------------------------------------------------------------
typedef void (*FnCommandCallback_t)(const CCommand& command);

#define COMMAND_COMPLETION_MAXITEMS		128
#define COMMAND_COMPLETION_ITEM_LENGTH	128

#define COMMAND_COMPLETION_MARKER -1

//-----------------------------------------------------------------------------
// Returns 0 to COMMAND_COMPLETION_MAXITEMS worth of completion strings
//-----------------------------------------------------------------------------
typedef int  (*FnCommandCompletionCallback)(const char* partial, char commands[COMMAND_COMPLETION_MAXITEMS][COMMAND_COMPLETION_ITEM_LENGTH]);

//-----------------------------------------------------------------------------
// Interface version
//-----------------------------------------------------------------------------
class ICommandCallback
{
public:
	virtual void CommandCallback(const CCommand& command) = 0;
};

class ICommandCompletionCallback
{
public:
	//virtual int  CommandCompletionCallback(const char* pPartial, CUtlVector< CUtlString > &commands) = 0;
};

//-----------------------------------------------------------------------------
// Called when a ConVar changes value
// NOTE: For FCVAR_NEVER_AS_STRING ConVars, pOldValue == NULL
//-----------------------------------------------------------------------------
typedef void (*FnChangeCallback_t)(IConVar* var, const char* pOldValue, float flOldValue);


//-----------------------------------------------------------------------------
// Abstract interface for ConVars
//-----------------------------------------------------------------------------
abstract_class IConVar // taken from r5r, TODO: verify
{
public:
	virtual ~IConVar() { };

	// Value set
	virtual void SetValue(const char* pValue) = 0;
	virtual void SetValue(float flValue) = 0;
	virtual void SetValue(int nValue) = 0;

	// Original name 'GetName'. Renamed due to name ambiguity
	// as we are not implementing it in ConVar, we are just
	// interfacing it with the game executable.
	virtual const char* GetCommandName(void) const = 0;

	// Return name of command (usually == GetName(), except in case of FCVAR_SS_ADDED vars
	virtual const char* GetBaseName(void) const = 0;

	// Accessors.. not as efficient as using GetState()/GetInfo()
	// if you call these methods multiple times on the same IConVar
	virtual bool IsConVarFlagSet(int nFlag) const = 0; // Original name 'IsFlagSet'. Renamed for same reason as 'GetName'.

	virtual int GetSplitScreenPlayerSlot() const = 0;
};

struct ConVarFlagsToString_t
{
	int m_nFlag;
	const char* m_pszDesc;
};

inline ConVarFlagsToString_t g_PrintConVarFlags[] =
{
	{FCVAR_UNREGISTERED, "UNREGISTERED"},
	{FCVAR_DEVELOPMENTONLY, "DEVELOPMENTONLY"},
	{FCVAR_GAMEDLL, "GAMEDLL"},
	{FCVAR_CLIENTDLL, "CLIENTDLL"},
	{FCVAR_HIDDEN, "HIDDEN"},
	{FCVAR_PROTECTED, "PROTECTED"},
	{FCVAR_SPONLY, "SPONLY"},
	{FCVAR_ARCHIVE, "ARCHIVE"},
	{FCVAR_NOTIFY, "NOTIFY"},
	{FCVAR_USERINFO, "USERINFO"},

	// TODO: PRINTABLEONLY and GAMEDLL_FOR_REMOTE_CLIENTS are both 1<<10, one is for vars and one is for commands
	// this fucking sucks i think
	{FCVAR_PRINTABLEONLY, "PRINTABLEONLY"},
	{FCVAR_GAMEDLL_FOR_REMOTE_CLIENTS, "GAMEDLL_FOR_REMOTE_CLIENTS"},

	{FCVAR_UNLOGGED, "UNLOGGED"},
	{FCVAR_NEVER_AS_STRING, "NEVER_AS_STRING"},
	{FCVAR_REPLICATED, "REPLICATED"},
	{FCVAR_CHEAT, "CHEAT"},
	{FCVAR_SS, "SS"},
	{FCVAR_DEMO, "DEMO"},
	{FCVAR_DONTRECORD, "DONTRECORD"},
	{FCVAR_SS_ADDED, "SS_ADDED"},
	{FCVAR_RELEASE, "RELEASE"},
	{FCVAR_RELOAD_MATERIALS, "RELOAD_MATERIALS"},
	{FCVAR_RELOAD_TEXTURES, "RELOAD_TEXTURES"},
	{FCVAR_NOT_CONNECTED, "NOT_CONNECTED"},
	{FCVAR_MATERIAL_SYSTEM_THREAD, "MATERIAL_SYSTEM_THREAD"},
	{FCVAR_ARCHIVE_PLAYERPROFILE, "ARCHIVE_PLAYERPROFILE"},
	{FCVAR_SERVER_CAN_EXECUTE, "SERVER_CAN_EXECUTE"},
	{FCVAR_SERVER_CANNOT_QUERY, "SERVER_CANNOT_QUERY"},
	{FCVAR_CLIENTCMD_CAN_EXECUTE, "UNKNOWN"},
	{FCVAR_ACCESSIBLE_FROM_THREADS, "ACCESSIBLE_FROM_THREADS"}
};

#endif // ICONVAR_H
