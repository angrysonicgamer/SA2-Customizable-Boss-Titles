#include "pch.h"
#include "Include/Mod Loader Common/IniFile.hpp"


#define ReplaceBossTitlePAK(file) helperFunctions.ReplaceFile("resource\\gd_PC\\" file ".prs", "resource\\gd_PC\\PRS\\dcstyle\\" file ".pak");

extern std::string SonicTitle;
extern std::string ShadowTitle;
extern std::string TailsTitle;
extern std::string EggmanTitle;
extern std::string KnucklesTitle;
extern std::string RougeTitle;

extern std::string AmyTitle;
extern std::string MetalSonicTitle;
extern std::string TikalTitle;
extern std::string ChaosTitle;
extern std::string ChaoWalkerTitle;
extern std::string DarkChaoTitle;

std::string BossTitlesStyle;

int GetBossTitlesStyle()
{
	if (BossTitlesStyle == "PC") return 0;
	if (BossTitlesStyle == "DC/GC") return 1;
}


void ReadConfig(const char* modPath)
{
	IniFile config(std::string(modPath) + "\\config.ini");

	BossTitlesStyle = config.getString("Style", "BossTitlesStyle", "PC");

	SonicTitle = config.getString("CustomizationDefault", "SonicTitle", "Sonic");
	ShadowTitle = config.getString("CustomizationDefault", "ShadowTitle", "Shadow");
	TailsTitle = config.getString("CustomizationDefault", "TailsTitle", "Tails");
	EggmanTitle = config.getString("CustomizationDefault", "EggmanTitle", "Dr.Eggman");
	KnucklesTitle = config.getString("CustomizationDefault", "KnucklesTitle", "Knuckles");	
	RougeTitle = config.getString("CustomizationDefault", "RougeTitle", "Rouge");

	AmyTitle = config.getString("CustomizationAlt", "AmyTitle", "Amy");
	MetalSonicTitle = config.getString("CustomizationAlt", "MetalSonicTitle", "Metal Sonic");
	TikalTitle = config.getString("CustomizationAlt", "TikalTitle", "Tikal");
	ChaosTitle = config.getString("CustomizationAlt", "ChaosTitle", "Chaos");
	ChaoWalkerTitle = config.getString("CustomizationAlt", "ChaoWalkerTitle", "Chao");
	DarkChaoTitle = config.getString("CustomizationAlt", "DarkChaoTitle", "Dark Chao");
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