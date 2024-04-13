#include "pch.h"
#include "Bosses/BossTitles.h"
#include "Config/Config.h"


extern "C"
{
	__declspec(dllexport) void Init(const char* modPath, const HelperFunctions& helperFunctions)
	{
		InitConfig(modPath, helperFunctions);
		InitCharacterBossTitles();
		SetUpGunRoboFont();
		InitOtherBossTitles();
	}

	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer };
}