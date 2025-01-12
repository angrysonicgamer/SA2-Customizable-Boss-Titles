#pragma once

class BossTitleStuff
{
private:
	static std::map<char, BossTitleLetterData> BossLetters;

	void GenerateLetterData();
	short CalculateSpacing();
	void SetCharacterSpacing();
	short CalculateDisplayTime();

public:
	std::string DefaultText;
	std::string& CustomText;
	std::vector<BossTitleLetterData>& LetterData;
	FullBossTitleData& BossTitleData;

	void SetDefaultTitle();
	void SetUpBossTitle(NJS_TEXLIST* texlist);
};