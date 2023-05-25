#include "vgui_fpspanel.h"
#include "engine/vgui_baseui_interface.h"
#include "tier1/cvar.h"
#include "toolframework/itoolentity.h"
#include "mathlib/vector.h"

void* CFPSPanel_Paint(void* self)
{
	// TODO [Fifty]: This only gets called when either cl_showpos or cl_showfps
	//               are set. Possibly move this somewhere else
	if (cl_showsdkdbg->GetBool())
	{
		vgui::HFont smallFont = *((char*)self + 612);
		vgui::HFont largeFont = *((char*)self + 616);
		Vector3D origin;
		QAngle angle;
		float fov;
		g_pClientTools->GetLocalPlayerEyePosition(origin, angle, fov);
		g_pMatSystemSurface->DrawColoredText(smallFont, 5, 5, 255, 255, 255, 255, "Howdy");
		g_pMatSystemSurface->DrawColoredText(smallFont, 5, 17, 255, 255, 255, 255, "Origin: %.2f, %.2f, %.2f", origin.x, origin.y, origin.z);
		g_pMatSystemSurface->DrawColoredText(smallFont, 5, 29, 255, 255, 255, 255, "Angle: %.2f, %.2f, %.2f", angle.x, angle.y, angle.z);
		g_pMatSystemSurface->DrawColoredText(smallFont, 5, 41, 255, 255, 255, 255, "FOV: %.2f", fov);

		int yOffset = 0;
		static float time = 30.0;
		MatSystemSurface_DrawTextPopUp(&yOffset, self, largeFont, "Node Graph out of Date. Rebuilding...", true, time); // He he
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