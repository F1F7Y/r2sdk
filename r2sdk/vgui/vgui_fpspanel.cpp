#include "vgui_fpspanel.h"
#include "engine/vgui_baseui_interface.h"
#include "tier1/cvar.h"

void* CFPSPanel_Paint(void* self)
{
	if (cl_showsdkdbg->GetBool())
	{
		vgui::HFont font = *((char*)self + 612);
		g_pMatSystemSurface->DrawColoredText(font, 5, 5, 255, 255, 255, 255, "Howdy");
	}

	return v_CFPSPanel_Paint(self);
}

void VFPSPanel::Attach(void) const
{
	DetourAttach((LPVOID*)&v_CFPSPanel_Paint, &CFPSPanel_Paint);
}

void VFPSPanel::Detach(void) const
{
	DetourDetach((LPVOID*)&v_CFPSPanel_Paint, &CFPSPanel_Paint);
}