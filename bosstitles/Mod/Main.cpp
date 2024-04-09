#include "pch.h"
#include "BossTitles.h"
#include "Config.h"


extern "C"
{
	__declspec(dllexport) void Init(const char* modPath, const HelperFunctions& helperFunctions)
	{
		InitConfig(modPath, helperFunctions);
		InitCharacterBossTitles(modPath);
	}

	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer };
}