#include "vgui_baseui_interface.h"
#include "gameui/GameConsole.h"
#include "vgui_controls/Frame.h"
#include "vgui_controls/Label.h"
#include "core/logdef.h"
#include <tier0/memstd.h>

char CEngineVGui__Init(void* self)
{
	char cResult = v_CEngineVGui__Init(self);
	DevMsg(eDLL_T::NONE, "CEngineVGui__Init: %i\n", cResult);
	g_pGameConsole->Initialize();

	vgui::Frame* frame = MemAllocSingleton()->Alloc<vgui::Frame>(sizeof(vgui::Frame));
	v_Frame__Frame(frame, NULL, "FrameTest", false, true);
	frame->SetTitle("Cock and balls", true);
	frame->SetVisible(true);

	vgui::Label* label = MemAllocSingleton()->Alloc<vgui::Label>(sizeof(vgui::Label));
	v_Label__Label(label, frame, "LabelTest", "Penis");
	label->SetVisible(true);

	SpdLog_PostInit();
	return cResult;
}

void VEngineVgui::Attach(void) const
{
	DetourAttach((LPVOID*)&v_CEngineVGui__Init, &CEngineVGui__Init);
}

void VEngineVgui::Detach(void) const
{
	DetourDetach((LPVOID*)&v_CEngineVGui__Init, &CEngineVGui__Init);
}