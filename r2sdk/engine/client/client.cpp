#include "client.h"

bool CClient__Connect(void* self, const char* szName, void* pNetChannel, bool bFakePlayer, void* a5, char* szMessage, void* a7)
{
	DevMsg(eDLL_T::NONE, "CClient__Connect\n");
	bool bRet = v_CClient__Connect(self, szName, pNetChannel, bFakePlayer, a5, szMessage, a7);
	if (!bRet)
		return bRet;

	// TODO [Fifty]: Use source fs for this
	// TODO [Fifty]: Make this better
	std::fstream pdataStream("./platform/placeholder_playerdata.pdata", std::ios_base::in);
	if (!pdataStream.fail())
	{
		// get file length
		pdataStream.seekg(0, pdataStream.end);
		auto length = pdataStream.tellg();
		pdataStream.seekg(0, pdataStream.beg);

		// copy pdata into buffer
		pdataStream.read((char*)self + 0x4FA, length);
	}
	else
	{
		Error(eDLL_T::ENGINE, EXIT_FAILURE, "Failed to read pdata!");
	}

	// Set persistence data as ready
	*((char*)self + 0x4a0) = (char)0x3;

	return bRet;
}

///////////////////////////////////////////////////////////////////////////////
void VClient::Attach(void) const
{
	DetourAttach((LPVOID*)&v_CClient__Connect, &CClient__Connect);
}

void VClient::Detach(void) const
{
	DetourDetach((LPVOID*)&v_CClient__Connect, &CClient__Connect);
}