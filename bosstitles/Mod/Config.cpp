#include "pch.h"
#include "Include/Mod Loader Common/IniFile.hpp"


#define ReplaceBossTitlePAK(file) helperFunctions.ReplaceFile("resource\\gd_PC\\" file ".prs", "resource\\gd_PC\\PRS\\dcstyle\\" file ".pak");

std::string BossTitleStyle;

void ReadConfig(const char* modPath)
{
	IniFile config(std::string(modPath) + "\\config.ini");

	BossTitleStyle = config.getString("Options", "BossTitlesStyle", "PC");
}


void LoadDCStyleBossTitles(const HelperFunctions& helperFunctions)
{
	ReplaceBossTitlePAK("titletex_bossbogy");
	ReplaceBossTitlePAK("titletex_bosslast1");
	ReplaceBossTitlePAK("titletex_bosslast2");
}


void InitConfig(const char* modPath, const HelperFunctions& helperFunctions)
{
	ReadConfig(modPath);

	if (BossTitleStyle == "Dreamcast/Gamecube")
	{
		LoadDCStyleBossTitles(helperFunctions);
	}
}