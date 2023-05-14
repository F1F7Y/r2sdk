#ifndef LAUNCHER_H
#define LAUNCHER_H

inline CMemory p_LauncherMain;
inline auto v_LauncherMain = p_LauncherMain.RCast<int(*)(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)>();
///////////////////////////////////////////////////////////////////////////////

int LauncherMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	SpdLog_PostInit();
	DevMsg(eDLL_T::NONE, "LauncherMain\n");
	return v_LauncherMain(hInstance, hPrevInstance, lpCmdLine, nShowCmd);
}

///////////////////////////////////////////////////////////////////////////////
class VLauncher : public IDetour
{
	virtual void GetAdr(void) const
	{
		LogFunAdr("LauncherMain", p_LauncherMain.GetPtr());
	}
	virtual void GetFun(void) const
	{
		p_LauncherMain = g_LauncherDll.GetExportedFunction("LauncherMain");
		v_LauncherMain = p_LauncherMain.RCast<int(*)(HINSTANCE, HINSTANCE, LPSTR, int)>();
	}
	virtual void GetVar(void) const { }
	virtual void GetCon(void) const { }
	virtual void Attach(void) const
	{
		DetourAttach((LPVOID*)&v_LauncherMain, &LauncherMain);
	}
	virtual void Detach(void) const
	{
		DetourDetach((LPVOID*)&v_LauncherMain, &LauncherMain);
	}
};
///////////////////////////////////////////////////////////////////////////////

#endif // LAUNCHER_H