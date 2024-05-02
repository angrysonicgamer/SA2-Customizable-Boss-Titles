#include "pch.h"
#include "BossTitles.h"
#include "BossTitleStuff.h"


std::map<char, BossTitleLetterData> BossTitleStuff::BossLetters
{
	{ 'A', { _A, 17, 16, 0, 32, 16, 0 } },
	{ 'B', { _B, 16, 16, 0, 32, 16, 0 } },
	{ 'C', { _C, 15, 16, 0, 32, 16, 0 } },
	{ 'D', { _D, 16, 16, 0, 32, 16, 0 } },
	{ 'E', { _E, 15, 16, 0, 32, 16, 0 } },
	{ 'F', { _F, 15, 16, 0, 32, 16, 0 } },
	{ 'G', { _G, 16, 16, 0, 32, 16, 0 } },
	{ 'H', { _H, 16, 16, 0, 32, 16, 0 } },
	{ 'I', { _I, 6, 16, 0, 32, 16, 0 } },
	{ 'J', { _J, 14, 16, 0, 32, 16, 0 } },
	{ 'K', { _K, 16, 16, 0, 32, 16, 0 } },
	{ 'L', { _L, 12, 16, 0, 32, 16, 0 } },
	{ 'M', { _M, 19, 16, 0, 32, 16, 0 } },
	{ 'N', { _N, 16, 16, 0, 32, 16, 0 } },
	{ 'O', { _O, 17, 16, 0, 32, 16, 0 } },
	{ 'P', { _P, 16, 16, 0, 32, 16, 0 } },
	{ 'Q', { _Q, 17, 16, 0, 32, 16, 0 } },
	{ 'R', { _R, 16, 16, 0, 32, 16, 0 } },
	{ 'S', { _S, 16, 16, 0, 32, 16, 0 } },
	{ 'T', { _T, 15, 16, 0, 32, 16, 0 } },
	{ 'U', { _U, 16, 16, 0, 32, 16, 0 } },
	{ 'V', { _V, 17, 16, 0, 32, 16, 0 } },
	{ 'W', { _W, 25, 16, 0, 32, 16, 0 } },
	{ 'X', { _X, 17, 16, 0, 32, 16, 0 } },
	{ 'Y', { _Y, 16, 16, 0, 32, 16, 0 } },
	{ 'Z', { _Z, 14, 16, 0, 32, 16, 0 } },
	{ '0', { _0, 16, 16, 0, 32, 16, 0 } },
	{ '1', { _1, 7, 16, 0, 32, 16, 0 } },
	{ '2', { _2, 16, 16, 0, 32, 16, 0 } },
	{ '3', { _3, 16, 16, 0, 32, 16, 0 } },
	{ '4', { _4, 16, 16, 0, 32, 16, 0 } },
	{ '5', { _5, 16, 16, 0, 32, 16, 0 } },
	{ '6', { _6, 16, 16, 0, 32, 16, 0 } },
	{ '7', { _7, 14, 16, 0, 32, 16, 0 } },
	{ '8', { _8, 16, 16, 0, 32, 16, 0 } },
	{ '9', { _9, 16, 16, 0, 32, 16, 0 } },
	{ '.', { dot, 6, 16, 0, 32, 16, 0 } },
	{ ',', { comma, 6, 16, 0, 32, 16, 0 } },
	{ '\'', { apostrophe, 6, 16, 0, 32, 16, 0 } },
	{ '!', { exclamation, 6, 16, 0, 32, 16, 0 } },
	{ '?', { question, 15, 16, 0, 32, 16, 0 } },
	{ ' ', { space, 12, 16, 0, 32, 16, 0 } },
};


void BossTitleStuff::GenerateLetterData()
{
	for (auto& letter : CustomText)
	{
		if (BossLetters.count(std::toupper(letter)))
		{
			LetterData.push_back(BossLetters[std::toupper(letter)]);
		}
	}
}


int BossTitleStuff::CalculateSpacing()
{
	int maxSpacing = 12; // the game's default value for character boss titles
	float baseWidth = 320 * (3.0f / 4) * (HorizontalResolution / VerticalResolution);
	int totalWidth = 0;
	int spacing = maxSpacing;

	for (auto& letter : LetterData)
	{
		totalWidth += letter.Width;
	}

	while (spacing > 0)
	{
		if (totalWidth + spacing * (LetterData.size() - 1) > baseWidth)
		{
			spacing--;
		}
		else break;
	}

	return spacing;
}

void BossTitleStuff::SetCharacterSpacing()
{
	int spacing = CalculateSpacing();

	for (int i = 0; i < LetterData.size() - 1; i++) // add spacing to all letters except for the last one, so the title will be properly centered
	{
		LetterData[i].Width += spacing;
	}
}


int BossTitleStuff::CalculateDisplayTime()
{
	int defaultDisplayTime = 360;
	int delay = 20;
	int displayTime = 120 + delay * LetterData.size();

	return displayTime < defaultDisplayTime ? defaultDisplayTime : displayTime;
}


void BossTitleStuff::SetDefaultTitle()
{
	CustomText = DefaultText;
}


void BossTitleStuff::SetUpBossTitle(NJS_TEXLIST* texlist)
{
	GenerateLetterData();
	SetCharacterSpacing();
	BossTitleData = { LetterData.data(), (short)LetterData.size(), 0, 20, nullptr, 0, 3, CalculateDisplayTime(), texlist, 320, 240, 2, WhiteColor };
}