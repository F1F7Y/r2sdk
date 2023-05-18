#ifndef LABEL_H
#define LABEL_H

#include "vgui_controls/Panel.h"

namespace vgui
{
	class Label : public Panel
	{
	public:
		virtual void sub_18077F530() = 0;
		virtual void sub_18077F510() = 0;
		virtual void sub_18077EF70() = 0;
		virtual void sub_1807806C0() = 0;
		virtual void sub_180780A80() = 0;
		virtual void sub_18077F560() = 0;
		virtual void sub_1807806D0() = 0;
		virtual void sub_1807806E0() = 0;
		virtual void sub_18077F120() = 0;
		virtual void sub_18077F130() = 0;
		virtual void sub_1807809E0() = 0;
		virtual void sub_180780750() = 0;
		virtual void sub_18077F140() = 0;
		virtual void sub_180780780() = 0;
		virtual void sub_18077F160() = 0;
		virtual void sub_180780660() = 0;
		virtual void sub_18077E040() = 0;
		virtual void sub_180780790() = 0;
		virtual void sub_1807807E0() = 0;
		virtual void sub_180780890() = 0;
		virtual void sub_18077F170() = 0;
		virtual void sub_18077F1A0() = 0;
		virtual void sub_18077EBD0() = 0;
		virtual void sub_1807805E0() = 0;
		virtual void sub_180780860() = 0;
		virtual void sub_18077F550() = 0;
		virtual void sub_180780A00() = 0;
		virtual void sub_180780CB0() = 0;
		virtual wchar_t CalculateHotkey(const wchar_t* text) = 0;
		virtual wchar_t CalculateHotkey(const char* text) = 0;
		virtual void sub_18077EBF0() = 0;
		virtual void OnSetText(void* params) = 0;
		virtual void sub_18077EE00() = 0;
		virtual void sub_18077FC60() = 0;
		virtual void sub_18077EF20() = 0;
		virtual void sub_18077FBF0() = 0;
		virtual void nullsub_393() = 0;

		_BYTE gap4[140];
		_QWORD qword270;
		_BYTE gap278[40];
		_QWORD qword2A0;
		_DWORD dword2A8;
		_DWORD dword2AC;
		_BYTE gap2B0[8];
		_QWORD qword2B8;
	};
	//static_assert(sizeof(Label) == 760);
}

inline CMemory p_Label__Label;
inline auto v_Label__Label = p_Label__Label.RCast<vgui::Label * (*)(vgui::Label*, void*, const char*, const char*)>();


///////////////////////////////////////////////////////////////////////////////
class VguiLabel : public IDetour
{
	virtual void GetAdr(void) const
	{
		LogFunAdr("vgui::Label::Label", p_Label__Label.GetPtr());
	}
	virtual void GetFun(void) const
	{
		p_Label__Label = g_pClientDll->FindPatternSIMD("48 89 5C 24 10 48 89 6C 24 18 48 89 74 24 20 57 48 83 EC 20 49 8B F1 48 8B F9 E8 B1");
		v_Label__Label = p_Label__Label.RCast<vgui::Label * (*)(vgui::Label*, void*, const char*, const char*)>();
	}
	virtual void GetVar(void) const { }
	virtual void GetCon(void) const { }
	virtual void Attach(void) const { }
	virtual void Detach(void) const { }
};
///////////////////////////////////////////////////////////////////////////////
#endif // !LABEL_H