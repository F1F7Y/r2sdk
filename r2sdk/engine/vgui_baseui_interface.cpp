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
	frame->SetTitle("Cs", true);
	frame->SetVisible(true);
	//frame->sub_1807708A0("cock");
	//DevMsg(eDLL_T::NONE, "name: %s\n", frame->GetName());
	//frame->SetName("cock");
	//DevMsg(eDLL_T::NONE, "name: %s\n", frame->GetName());
	//frame->SetSize(200, 300);
	//frame->SetPos(50, 50);
	//int x, y;
	//frame->nullsub_159(x, y);
	//DevMsg(eDLL_T::NONE, "pos: %i, %i\n",x,y);
	//frame->sub_18009E140(255);
	//DevMsg(eDLL_T::NONE, "Unk: %i", frame->IsDragEnabled());
	//frame->SetDragEnabled(true);
	//DevMsg(eDLL_T::NONE, "Unk: %i", frame->sub_18075D890());

	//vgui::Label* label = MemAllocSingleton()->Alloc<vgui::Label>(sizeof(vgui::Label));
	//v_Label__Label(label, frame, "LabelTest", "Penis");
	//label->SetVisible(true);

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