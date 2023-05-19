#ifndef EDITABLEPANEL_H
#define EDITABLEPANEL_H

#include "vgui_controls/Panel.h"

namespace vgui
{
	class EditablePanel : public Panel
	{
	public:
		virtual void sub_18077C950();
		virtual void sub_18077C9F0();
		virtual void sub_18077D370();
		virtual void sub_18077C990();
		virtual void sub_18077BA30();
		virtual void sub_18077C250();
		virtual void sub_18077C0F0();
		virtual void sub_18077D550();
		virtual void SetControlString(const char* controlName, const char* string);
		virtual void SetControlString(const char* controlName, const wchar_t* string);
		virtual int GetControlInt(const char* controlName, int defaultState);
		virtual void GetControlString(const char* controlName, char* buf, int bufSize, const char* defaultString);
		virtual void sub_18077C2F0();
		virtual void sub_18077D3C0();
		virtual void sub_18077D5D0();
		virtual /*KeyValues*/ void* GetDialogVariables();
		virtual void sub_18077D680(); // Also GetDialogVariables???
		virtual void sub_18077D760(); // Also GetDialogVariables???
		virtual void sub_18077D610(); // Also GetDialogVariables???
		virtual void sub_18077D100();
		virtual void sub_18077C4A0();
		virtual void sub_18077CBF0();
		virtual void OnCurrentDefaultButtonSet(VPANEL defaultButton);
		virtual void OnFindDefaultButton();
		virtual void sub_18077CB30();

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