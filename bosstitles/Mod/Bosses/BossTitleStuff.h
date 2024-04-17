#pragma once

class BossTitleStuff
{
private:
	static std::map<char, BossTitleLetterData> BossLetters;

	void GenerateLetterData();
	int CalculateSpacing();
	void SetCharacterSpacing();
	int CalculateDisplayTime();

public:
	std::string DefaultText;
	std::string& CustomText;
	std::vector<BossTitleLetterData>& LetterData;
	FullBossTitleData& BossTitleData;

	void SetDefaultTitle();
	void SetUpBossTitle(NJS_TEXLIST* texlist);
};