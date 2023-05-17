//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
//===========================================================================//

#ifndef IGAMECONSOLE_H
#define IGAMECONSOLE_H
#ifdef _WIN32
#pragma once
#endif

#include "public/icvar.h"
#include "mathlib/color.h"
#include "tier1/interface.h"

class EditablePanel
{
public:
	virtual ~EditablePanel() = 0;
	unsigned char unknown[0x2B0];
};

class CConsolePanel : public EditablePanel, public IConsoleDisplayFunc
{
};

class CConsoleDialog
{
public:
	struct VTable
	{
		void* unknown[298];
		void (*OnCommandSubmitted)(CConsoleDialog* consoleDialog, const char* pCommand);
	};

	VTable* m_vtable;
	unsigned char unknown[0x398];
	CConsolePanel* m_pConsolePanel;
};

//-----------------------------------------------------------------------------
// Purpose: interface to game/dev console
//-----------------------------------------------------------------------------
abstract_class IGameConsole// : public IBaseInterface
{
public:
	virtual ~IGameConsole() = 0;

	// activates the console, makes it visible and brings it to the foreground
	virtual void Activate() = 0;

	virtual void Initialize() = 0;

	// hides the console
	virtual void Hide() = 0;

	// clears the console
	virtual void Clear() = 0;

	// return true if the console has focus
	virtual bool IsConsoleVisible() = 0;

	virtual void SetParent(int parent) = 0;

	bool m_bInitialized;
	CConsoleDialog* m_pConsole;
};

#define GAMECONSOLE_INTERFACE_VERSION "GameConsole004"

#endif // IGAMECONSOLE_H
