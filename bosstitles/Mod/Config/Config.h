#pragma once

class Config
{
public:
	static std::string SonicTitle;
	static std::string ShadowTitle;
	static std::string TailsTitle;
	static std::string EggmanTitle;
	static std::string KnucklesTitle;
	static std::string RougeTitle;

	static std::string AmyTitle;
	static std::string MetalSonicTitle;
	static std::string TikalTitle;
	static std::string ChaosTitle;
	static std::string ChaoWalkerTitle;
	static std::string DarkChaoTitle;

	static std::string BossTitlesStyle;

	static void Read(const char* modPath);
	static void Init(const char* modPath, const HelperFunctions& helperFunctions);
};