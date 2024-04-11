#include "pch.h"
#include "Include/Mod Loader Common/IniFile.hpp"


#define ReplaceBossTitlePAK(file) helperFunctions.ReplaceFile("resource\\gd_PC\\" file ".prs", "resource\\gd_PC\\PRS\\dcstyle\\" file ".pak");

std::string SonicTitle;
std::string ShadowTitle;
std::string TailsTitle;
std::string EggmanTitle;
std::string KnucklesTitle;
std::string RougeTitle;
std::string BossTitlesStyle;

std::vector<std::string*> GetBossTitles()
{
	return { &SonicTitle, &ShadowTitle, &TailsTitle, &EggmanTitle, &KnucklesTitle, &RougeTitle };
};


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