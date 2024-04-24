#include "pch.h"
#include "Config.h"
#include "Include/Mod Loader Common/IniFile.hpp"


#define ReplaceBossTitlePAK(file) helperFunctions.ReplaceFile("resource\\gd_PC\\" file ".prs", "resource\\gd_PC\\PRS\\dcstyle\\" file ".pak");

std::string Config::SonicTitle;
std::string Config::ShadowTitle;
std::string Config::TailsTitle;
std::string Config::EggmanTitle;
std::string Config::KnucklesTitle;
std::string Config::RougeTitle;

std::string Config::AmyTitle;
std::string Config::MetalSonicTitle;
std::string Config::TikalTitle;
std::string Config::ChaosTitle;
std::string Config::ChaoWalkerTitle;
std::string Config::DarkChaoTitle;

std::string Config::BossTitlesStyle;


void Config::Read(const char* modPath)
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

void Config::Init(const char* modPath, const HelperFunctions& helperFunctions)
{
	Read(modPath);

	if (BossTitlesStyle == "DC/GC")
	{
		LoadDCStyleBossTitleTextures(helperFunctions);
	}
}