#ifndef VGUI_FRAME_H
#define VGUI_FRAME_H

#include "core/stdafx.h"
#include "vgui_controls/EditablePanel.h"

namespace vgui
{

	class Frame : public EditablePanel
	{
	public:
		virtual void sub_1807D66C0() = 0;
		virtual void SetTitle(const char* title, bool surfaceTitle) = 0;
		virtual void sub_1807D2710() = 0;
		virtual void sub_1807D27B0() = 0;
		virtual void sub_1807D3570() = 0;
		virtual void sub_1807D3580() = 0;
		virtual void sub_1807D61C0() = 0;
		virtual void sub_1807D4800() = 0;
		virtual void sub_1807D64E0() = 0;
		virtual void sub_1807D45D0() = 0;
		virtual void sub_1807D6510() = 0;
		virtual void sub_1807D45E0() = 0;
		virtual void sub_1807D6480() = 0;
		virtual void sub_1807D64A0() = 0;
		virtual void sub_1807D6450() = 0;
		virtual void sub_1807D64C0() = 0;
		virtual void sub_1807D61A0() = 0;
		virtual void sub_1807D4590() = 0;
		virtual void sub_1807D36F0() = 0;
		virtual void sub_1807D3710() = 0;
		virtual void sub_1807D3BD0() = 0;
		virtual void sub_1807D6560() = 0;
		virtual void sub_1807D6770() = 0;
		virtual void sub_1807D6180() = 0;
		virtual void sub_1807D3940() = 0;
		virtual void sub_1807D6530() = 0;
		virtual void sub_1807D45F0() = 0;
		virtual void sub_1807D39B0() = 0;
		virtual void sub_1807D3950() = 0;
		virtual void sub_1807D37A0() = 0;
		virtual void sub_1807D3830() = 0;
		virtual void sub_1807D3620() = 0;
		virtual void sub_1807D4EA0() = 0;
		virtual void nullsub_418() = 0;
		virtual void nullsub_419() = 0;
		virtual void sub_1807D5230() = 0;
		virtual void nullsub_420() = 0;
		virtual void sub_1807D49D0() = 0;
		virtual void sub_1807D3970() = 0;
		virtual void sub_1807D3850() = 0;
		virtual void sub_1807D4580() = 0;
		virtual void sub_1807D44B0() = 0;
		virtual void sub_1807D4BC0() = 0;
		_BYTE gap8[220];
	};
	static_assert(sizeof(Frame) == 920);

}
inline CMemory p_Frame__Frame;
inline auto v_Frame__Frame = p_Frame__Frame.RCast<vgui::Frame*(*)(vgui::Frame*,void*,const char*,bool,bool)>();


///////////////////////////////////////////////////////////////////////////////
class VguiFrame : public IDetour
{
	virtual void GetAdr(void) const
	{
		LogFunAdr("vgui::Frame::Frame", p_Frame__Frame.GetPtr());
	}
	virtual void GetFun(void) const
	{
		p_Frame__Frame = g_pClientDll->FindPatternSIMD("48 89 5C 24 10 48 89 6C 24 18 48 89 74 24 20 57 41 54 41 55 41 56 41 57 48 83 EC 20 41 0F B6 F1");
		v_Frame__Frame = p_Frame__Frame.RCast<vgui::Frame*(*)(vgui::Frame*,void*,const char*,bool,bool)>();
	}
	virtual void GetVar(void) const { }
	virtual void GetCon(void) const { }
	virtual void Attach(void) const { }
	virtual void Detach(void) const { }
};
///////////////////////////////////////////////////////////////////////////////

#endif /* VGUI_FRAME_H */