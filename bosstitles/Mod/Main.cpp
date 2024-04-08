#include "pch.h"
#include "BossTitles.h"


extern "C"
{
	__declspec(dllexport) void Init(const char* modPath, const HelperFunctions& helperFunctions)
	{
		InitBossTitles(modPath);
	}

	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer };
}