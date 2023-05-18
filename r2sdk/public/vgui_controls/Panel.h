#ifndef PANEL_H
#define PANEL_H

#include "public/vgui/VGUI.h"

namespace vgui
{

	class Panel// : public IClientPanel
	{
	public:
		virtual VPANEL GetVPanel() = 0;
		virtual void nullsub_144() = 0;
		virtual void sub_180771E20() = 0;
		virtual void sub_18076B7E0() = 0;
		virtual void sub_18076ADE0() = 0;
		virtual void sub_18076DDB0() = 0;
		virtual void sub_180765BE0() = 0;
		virtual void sub_18075BE80() = 0;
		virtual void sub_18075B680() = 0;
		virtual void nullsub_83() = 0;
		virtual void sub_18076A580() = 0;
		virtual void nullsub_145() = 0;
		virtual void nullsub_146() = 0;
		virtual void sub_18076DF20() = 0;
		virtual void sub_18076DDF0() = 0;
		virtual void sub_18076DEA0() = 0;
		virtual void sub_18076DE20() = 0;
		virtual void Panel__OnMessage() = 0;
		virtual void sub_18075B730() = 0;
		virtual void sub_18075D7D0() = 0;
		virtual void sub_180764C10() = 0;
		virtual void sub_18075B670() = 0;
		virtual const char* GetClassName() = 0;
		virtual void sub_18075D030() = 0;
		virtual void sub_18009E120() = 0;
		virtual void sub_1807648B0() = 0;
		virtual void sub_1807583B0() = 0;
		virtual void sub_18076D010() = 0;
		virtual void sub_18009DA60() = 0;
		virtual void sub_18075C3E0() = 0;
		virtual void nullsub_90() = 0;
		virtual void sub_18022F000() = 0;
		virtual void sub_18022EE80() = 0;
		virtual void sub_18022EF00() = 0;
		virtual void sub_18009DC60() = 0;
		virtual void sub_1807555C0() = 0;
		virtual void SetVisible(bool state) = 0;
		virtual void sub_180765AF0() = 0;
		virtual void sub_180764DB0() = 0;
		virtual void sub_18076C140() = 0;
		virtual void sub_18076C1C0() = 0;
		virtual void nullsub_147() = 0;
		virtual void sub_18075CE00() = 0;
		virtual void sub_18075D890() = 0;
		virtual void sub_1807712D0() = 0;
		virtual void sub_180771280() = 0;
		virtual void sub_18075E900() = 0;
		virtual void sub_18009EC30() = 0;
		virtual void sub_18076FE20() = 0;
		virtual void sub_1807556A0() = 0;
		virtual void sub_1807555F0() = 0;
		virtual void sub_18076D3F0() = 0;
		virtual void sub_18076BC10() = 0;
		virtual void sub_18076DFC0() = 0;
		virtual void sub_18076C310() = 0;
		virtual void sub_1807709D0() = 0;
		virtual void sub_180771780() = 0;
		virtual void sub_1807630D0() = 0;
		virtual void sub_180770920() = 0;
		virtual void sub_180764CC0() = 0;
		virtual void sub_180765370() = 0;
		virtual void sub_180766DA0() = 0;
		virtual void sub_18076FE80() = 0;
		virtual void sub_1807709B0() = 0;
		virtual void sub_1807702B0() = 0;
		virtual void sub_18075B740() = 0;
		virtual void sub_18075E8B0() = 0;
		virtual void sub_180099DF0() = 0;
		virtual void sub_180764770() = 0;
		virtual void sub_1807718A0() = 0;
		virtual void sub_18076FEA0() = 0;
		virtual void sub_unk() = 0;// ? _OriginalCollection@_TaskCollection@details@Concurrency@@AEBAPEAV123@XZ; Concurrency::details::_TaskCollection::_OriginalCollection(virtual void)
		virtual void sub_1807711C0() = 0;
		virtual void sub_180771190() = 0;
		virtual void sub_1807711E0() = 0;
		virtual void sub_180771530() = 0;
		virtual void sub_1807711B0() = 0;
		virtual void sub_18075C8C0() = 0;
		virtual void sub_180770010() = 0;
		virtual void sub_1807649F0() = 0;
		virtual void sub_180764C30() = 0;
		virtual void sub_180764C50() = 0;
		virtual void sub_180766D10() = 0;
		virtual void sub_180765030() = 0;
		virtual void sub_18075E8F0() = 0;
		virtual void sub_180765310() = 0;
		virtual void sub_1807716E0() = 0;
		virtual void sub_1807716F0() = 0;
		virtual void sub_18075D0E0() = 0;
		virtual void sub_18075D0B0() = 0;
		virtual void sub_180756430() = 0;
		virtual void ApplySettings(void* inResourceData) = 0;
		virtual void sub_18076A9C0() = 0;
		virtual void sub_18075D120() = 0;
		virtual const char* GetDescription() = 0;
		virtual void nullsub_148() = 0;
		virtual void nullsub_149() = 0;
		virtual void sub_18075E960() = 0;
		virtual void sub_180767CB0() = 0;
		virtual void sub_180769870() = 0;
		virtual void sub_18076A520() = 0;
		virtual void sub_180769070() = 0;
		virtual void sub_1807683A0() = 0;
		virtual void sub_18076A660() = 0;
		virtual void sub_180768330() = 0;
		virtual void nullsub_85() = 0;
		virtual void nullsub_86() = 0;
		virtual void nullsub_87() = 0;
		virtual void nullsub_102() = 0;
		virtual void nullsub_88() = 0;
		virtual void sub_180769910() = 0;
		virtual void sub_1807719B0() = 0;
		virtual void sub_180765850() = 0;
		virtual void nullsub_89() = 0;
		virtual void sub_180770A10() = 0;
		virtual void sub_18075BF40() = 0;
		virtual void sub_180765AB0() = 0;
		virtual void sub_180764F60() = 0;
		virtual void sub_180764F50() = 0;
		virtual void sub_1807557A0() = 0;
		virtual void nullsub_150() = 0;
		virtual void sub_18075BFD0() = 0;
		virtual void sub_18075C0E0() = 0;
		virtual void sub_180768BF0() = 0;
		virtual void sub_180768E60() = 0;
		virtual void sub_180769020() = 0;
		virtual void sub_180768E10() = 0;
		virtual void sub_180768FD0() = 0;
		virtual void sub_180769890() = 0;
		virtual void sub_18076AA30() = 0;
		virtual void nullsub_91() = 0;
		virtual void sub_18076ACB0() = 0;
		virtual void sub_18076ACF0() = 0;
		virtual void nullsub_92() = 0;
		virtual void sub_18076B9E0() = 0;
		virtual void sub_18075CB00() = 0;
		virtual void sub_180771550() = 0;
		virtual void sub_180770E30() = 0;
		virtual void sub_180770B30() = 0;
		virtual void sub_1807652D0() = 0;
		virtual void sub_180764F10() = 0;
		virtual void sub_1807593F0() = 0;
		virtual void sub_1807588A0() = 0;
		virtual void sub_180758C40() = 0;
		virtual void sub_1807591C0() = 0;
		virtual void sub_180759180() = 0;
		virtual void sub_1807708A0() = 0;
		virtual void sub_180764C90() = 0;
		virtual void sub_180771770() = 0;
		virtual void nullsub_151() = 0;
		virtual void sub_18076FE90() = 0;
		virtual void sub_1807649D0() = 0;
		virtual void sub_18075BC70() = 0;
		virtual void sub_1807708F0() = 0;
		virtual void sub_180770900() = 0;
		virtual void sub_180764CA0() = 0;
		virtual void sub_18075BC80() = 0;
		virtual void nullsub_152() = 0;
		virtual void nullsub_153() = 0;
		virtual void sub_18075BBF0() = 0;
		virtual void nullsub_154() = 0;
		virtual void nullsub_84() = 0;
		virtual void sub_180764CB0() = 0;
		virtual void Panel__OnDraggablePanelPaint() = 0;
		virtual void sub_180768570() = 0;
		virtual void nullsub_155() = 0;
		virtual void nullsub_156() = 0;
		virtual void nullsub_157() = 0;
		virtual void sub_18075BCB0() = 0;
		virtual void sub_18075BC10() = 0;
		virtual void sub_1807648C0() = 0;
		virtual void sub_18075BC90() = 0;
		virtual void sub_18009D2E0() = 0;
		virtual void sub_180757960() = 0;
		virtual void sub_1807596C0() = 0;
		virtual void sub_18075C8B0() = 0;
		virtual void sub_18075B6F0() = 0;
		virtual void sub_180771870() = 0;
		virtual void sub_1807671E0() = 0;
		virtual void sub_180766E20() = 0;
		virtual void sub_180766FF0() = 0;
		virtual void sub_180767040() = 0;
		virtual void sub_180767090() = 0;
		virtual void sub_180766E70() = 0;
		virtual void sub_180767100() = 0;
		virtual void nullsub_158() = 0;
		virtual void nullsub_159() = 0;
		virtual void sub_18009DFC0() = 0;
		virtual void sub_18009E090() = 0;
		virtual void sub_18009DFD0() = 0;
		virtual void sub_18009DFE0() = 0;
		virtual void sub_18009E150() = 0;
		virtual void sub_18009E050() = 0;
		virtual void sub_18009E110() = 0;
		virtual void sub_18009E100() = 0;
		virtual void sub_18009E0A0() = 0;
		virtual void sub_18009E170() = 0;
		virtual void sub_18009E130() = 0;
		virtual void sub_18009E140() = 0;
		virtual void sub_18009D2D0() = 0;
		virtual void sub_18076A590() = 0;
		virtual void sub_180767D00() = 0;
		virtual void sub_180768660() = 0;
		virtual void sub_1807586A0() = 0;
		virtual void sub_18075BB60() = 0;
		virtual void sub_180758070() = 0;
		virtual void sub_18076A250() = 0;
		virtual void sub_18076A290() = 0;
		virtual void sub_1807633F0() = 0;
		virtual void sub_180763310() = 0;
		virtual void sub_180763390() = 0;
		virtual void sub_180763EE0() = 0;
		virtual void sub_180763D70() = 0;
		virtual void sub_1807641D0() = 0;
		virtual void sub_180764010() = 0;
		virtual void sub_180764250() = 0;
		virtual void sub_1807638E0() = 0;
		virtual void sub_180763A30() = 0;
		virtual void sub_180763CB0() = 0;
		virtual void sub_180763970() = 0;
		virtual void sub_180763C80() = 0;
		virtual void sub_180763E40() = 0;
		virtual void sub_1807638D0() = 0;
		virtual void sub_1807642B0() = 0;
		virtual void sub_18075D760() = 0;
		virtual void sub_18075D6E0() = 0;
		virtual void sub_18009D080() = 0;
		virtual void nullsub_160() = 0;
		virtual void nullsub_161() = 0;
		virtual void sub_18009DAB0() = 0;

		//struct struct_a1
		//{
			//int a1300;
			_BYTE gap4[48];
			_QWORD qword38;
			_BYTE gap40[16];
			_QWORD qword50;
			_BYTE gap58[64];
			_DWORD dword98;
			_QWORD qwordA0;
			_QWORD qwordA8;
			_QWORD qwordB0;
			_DWORD dwordB8;
			_QWORD qwordC0;
			_QWORD qwordC8;
			_QWORD qwordD0;
			_DWORD dwordD8;
			_QWORD qwordE0;
			_DWORD dwordE8;
			_BYTE gapEC[44];
			_QWORD qword118;
			_BYTE gap120[8];
			_QWORD qword128;
			_WORD word130;
			_BYTE gap132[54];
			_QWORD qword168;
			_BYTE gap170[32];
			_QWORD qword190;
			_BYTE gap198[32];
			_QWORD qword1B8;
			_BYTE gap1C0[32];
			_QWORD qword1E0;
		//};
		// index: 5 - Alawys ""
		// index: 13 - panelName
		//struct __unaligned __declspec(align(2))
		//{
		//_BYTE gap0[152];
		//_DWORD dword98;
		//_BYTE gap9C[28];
		//_DWORD dwordB8;
		//_BYTE gapBC[28];
		//_DWORD dwordD8;
		//_BYTE gapDC[12];
		//_DWORD dwordE8;
		//_BYTE gapEC[12];
		//_WORD wordF8;
		//_BYTE gapFA[54];
		//_WORD word130;
		//}
	};
	static_assert(sizeof(Panel) == 488);

} // vgui

inline CMemory p_Panel__Panel;
inline auto v_Panel__Panel = p_Panel__Panel.RCast<vgui::Panel*(*)(vgui::Panel*, void*)>();

///////////////////////////////////////////////////////////////////////////////
class VguiPanel : public IDetour
{
	virtual void GetAdr(void) const
	{
		LogFunAdr("vgui::Panel::Panel", p_Panel__Panel.GetPtr());
	}
	virtual void GetFun(void) const
	{
		p_Panel__Panel = g_pClientDll->FindPatternSIMD("48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 30 48 8D 05 02 63 27 00");
		v_Panel__Panel = p_Panel__Panel.RCast<vgui::Panel * (*)(vgui::Panel*, void*)>();
	}
	virtual void GetVar(void) const { }
	virtual void GetCon(void) const { }
	virtual void Attach(void) const { }
	virtual void Detach(void) const { }
};
#endif /* !PANEL_H */