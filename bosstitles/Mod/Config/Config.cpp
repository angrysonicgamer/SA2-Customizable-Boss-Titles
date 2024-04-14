#include "pch.h"
#include "Include/Mod Loader Common/IniFile.hpp"


#define ReplaceBossTitlePAK(file) helperFunctions.ReplaceFile("resource\\gd_PC\\" file ".prs", "resource\\gd_PC\\PRS\\dcstyle\\" file ".pak");

extern std::string SonicTitle;
extern std::string ShadowTitle;
extern std::string TailsTitle;
extern std::string EggmanTitle;
extern std::string KnucklesTitle;
extern std::string RougeTitle;

std::string BossTitlesStyle;

int GetBossTitlesStyle()
{
	if (BossTitlesStyle == "PC") return 0;
	if (BossTitlesStyle == "DC/GC") return 1;
}


void ReadConfig(const char* modPath)
{
	IniFile config(std::string(modPath) + "\\config.ini");

	SonicTitle = config.getString("Customization", "SonicTitle", "Sonic");
	ShadowTitle = config.getString("Customization", "ShadowTitle", "Shadow");
	TailsTitle = config.getString("Customization", "TailsTitle", "Tails");
	EggmanTitle = config.getString("Customization", "EggmanTitle", "Dr.Eggman");
	KnucklesTitle = config.getString("Customization", "KnucklesTitle", "Knuckles");	
	RougeTitle = config.getString("Customization", "RougeTitle", "Rouge");
	BossTitlesStyle = config.getString("Style", "BossTitlesStyle", "PC");
}


void LoadDCStyleBossTitleTextures(const HelperFunctions& helperFunctions)
{
	ReplaceBossTitlePAK("titletex_bossbogy");
	ReplaceBossTitlePAK("titletex_bosslast1");
	ReplaceBossTitlePAK("titletex_bosslast2");
}


void InitConfig(const char* modPath, const HelperFunctions& helperFunctions)
{
	ReadConfig(modPath);

	if (BossTitlesStyle == "DC/GC")
	{
		LoadDCStyleBossTitleTextures(helperFunctions);
	}
}