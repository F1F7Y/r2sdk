#ifndef EDITABLEPANEL_H
#define EDITABLEPANEL_H

#include "vgui_controls/Panel.h"

namespace vgui
{
	class EditablePanel : public Panel
	{
	public:
		virtual void sub_18077C950() = 0;
		virtual void sub_18077C9F0() = 0;
		virtual void sub_18077D370() = 0;
		virtual void sub_18077C990() = 0;
		virtual void sub_18077BA30() = 0;
		virtual void sub_18077C250() = 0;
		virtual void sub_18077C0F0() = 0;
		virtual void sub_18077D550() = 0;
		virtual void sub_18077D480() = 0;
		virtual void sub_18077D400() = 0;
		virtual void sub_18077C260() = 0;
		virtual void sub_18077C320() = 0;
		virtual void sub_18077C2F0() = 0;
		virtual void sub_18077D3C0() = 0;
		virtual void sub_18077D5D0() = 0;
		virtual void sub_18077D6F0() = 0;
		virtual void sub_18077D680() = 0;
		virtual void sub_18077D760() = 0;
		virtual void sub_18077D610() = 0;
		virtual void sub_18077D100() = 0;
		virtual void sub_18077C4A0() = 0;
		virtual void sub_18077CBF0() = 0;
		virtual void sub_18077CB40() = 0;
		virtual void sub_18077CC60() = 0;
		virtual void sub_18077CB30() = 0;

		//{
			//_QWORD qword0;
			_BYTE gap8[208];
			//_QWORD qword268;
			//_BYTE gap270[48];
			//_QWORD qword2A0;
			//_QWORD qword2A8;
			//_DWORD dword2B0;
		//};
			// 208
	};
	static_assert(sizeof(EditablePanel) == 696);
}

#endif // !EDITABLEPANEL_H