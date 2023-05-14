#include "launcher/IApplication.h"


bool CSourceAppSystemGroup__PreInit(void* pModAppSystemGroup)
{
	DevMsg(eDLL_T::NONE, "CSourceAppSystemGroup__PreInit\n");


	// [Fifty]: r5r has a check for 'CSourceAppSystemGroup::CREATION' here
	// i dont know how the inheritance do so i just added a defensive check
	static bool bCalled = false;

	if (bCalled)
		Error(eDLL_T::NONE, 0xAAAAAAAA, "CSourceAppSystemGroup__PreInit called more than once!");

	bCalled = true;

	return v_CSourceAppSystemGroup__PreInit(pModAppSystemGroup);
}

bool CSourceAppSystemGroup__Create(void* pModAppSystemGroup)
{
	DevMsg(eDLL_T::NONE, "CSourceAppSystemGroup__Create\n");
	return v_CSourceAppSystemGroup__Create(pModAppSystemGroup);
}

///////////////////////////////////////////////////////////////////////////////
void VApplication::Attach(void) const
{
	DetourAttach((LPVOID*)&v_CSourceAppSystemGroup__PreInit, &CSourceAppSystemGroup__PreInit);
	DetourAttach((LPVOID*)&v_CSourceAppSystemGroup__Create, &CSourceAppSystemGroup__Create);

	//DetourAttach((LPVOID*)&CModAppSystemGroup_Main, &CModAppSystemGroup::StaticMain);
	//DetourAttach((LPVOID*)&CModAppSystemGroup_Create, &CModAppSystemGroup::StaticCreate);
}
void VApplication::Detach(void) const
{
	DetourDetach((LPVOID*)&v_CSourceAppSystemGroup__PreInit, &CSourceAppSystemGroup__PreInit);
	DetourDetach((LPVOID*)&v_CSourceAppSystemGroup__Create, &CSourceAppSystemGroup__Create);

	//DetourDetach((LPVOID*)&CModAppSystemGroup_Main, &CModAppSystemGroup::StaticMain);
	//DetourDetach((LPVOID*)&CModAppSystemGroup_Create, &CModAppSystemGroup::StaticCreate);
}