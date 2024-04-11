#include "pch.h"
#include "Include/Mod Loader Common/IniFile.hpp"


#define ReplaceBossTitlePAK(file) helperFunctions.ReplaceFile("resource\\gd_PC\\" file ".prs", "resource\\gd_PC\\PRS\\dcstyle\\" file ".pak");

extern std::string SonicTitle;
extern std::string TailsTitle;
extern std::string KnucklesTitle;
extern std::string ShadowTitle;
extern std::string EggmanTitle;
extern std::string RougeTitle;
std::string BossTitlesStyle;

void ReadConfig(const char* modPath)
{
	IniFile config(std::string(modPath) + "\\config.ini");

	SonicTitle = config.getString("Customization", "SonicTitle", "Sonic");
	TailsTitle = config.getString("Customization", "TailsTitle", "Tails");
	KnucklesTitle = config.getString("Customization", "KnucklesTitle", "Knuckles");
	ShadowTitle = config.getString("Customization", "ShadowTitle", "Shadow");
	EggmanTitle = config.getString("Customization", "EggmanTitle", "Dr.Eggman");
	RougeTitle = config.getString("Customization", "RougeTitle", "Rouge");
	BossTitlesStyle = config.getString("Style", "BossTitlesStyle", "PC");
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

	if (BossTitlesStyle == "Dreamcast/Gamecube")
	{
		LoadDCStyleBossTitles(helperFunctions);
	}
}