#include "pch.h"
#include "BossTitles.h"
#include "Config.h"


DataPointer(FullBossTitleData, VsSonic1, 0xFFE904);
DataPointer(FullBossTitleData, VsSonic2, 0x1646524);
DataPointer(FullBossTitleData, VsShadow1, 0xFFFCCC);
DataPointer(FullBossTitleData, VsShadow2, 0x1647C24);
DataPointer(FullBossTitleData, VsTails1, 0xEF3084);
DataPointer(FullBossTitleData, VsTails2, 0xC86F08);
DataPointer(FullBossTitleData, VsEggman1, 0xEF3190);
DataPointer(FullBossTitleData, VsEggman2, 0xC86F34);
DataPointer(FullBossTitleData, VsKnuckles, 0xDCF434);
DataPointer(FullBossTitleData, VsRouge, 0xDCF530);

DataPointer(FullBossTitleData, KingBoomBoo, 0x100C808);
DataPointer(FullBossTitleData, EggGolemHero, 0x16670D0);
DataPointer(FullBossTitleData, EggGolemDark, 0x16CC4EC);
DataPointer(FullBossTitleData, Biolizard, 0x1371BEC);
DataPointer(FullBossTitleData, Finalhazard, 0x170639C);


std::vector<std::string*> BossTitles = GetBossTitles();

std::vector<BossTitleLetterData> SonicLetters;
std::vector<BossTitleLetterData> TailsLetters;
std::vector<BossTitleLetterData> KnucklesLetters;
std::vector<BossTitleLetterData> ShadowLetters;
std::vector<BossTitleLetterData> EggmanLetters;
std::vector<BossTitleLetterData> RougeLetters;


std::map<char, BossTitleLetterData> BossLetters
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
	{ '\'', { apostrophe, 6, 16, 0, 32, 16, 0 } },
	{ '!', { exclamation, 6, 16, 0, 32, 16, 0 } },
	{ '?', { question, 15, 16, 0, 32, 16, 0 } },
	{ ' ', { space, 12, 16, 0, 32, 16, 0 } },
};

std::vector<std::vector<BossTitleLetterData>*> CustomLetterData
{
	&SonicLetters,
	&ShadowLetters,
	&TailsLetters,
	&EggmanLetters,
	&KnucklesLetters,
	&RougeLetters,
};


struct BossTitle
{
	std::string DefaultText;
	std::string* CustomText;
	std::vector<BossTitleLetterData>& CustomLetterData;
	FullBossTitleData& VanillaBossTitleData;
};

std::vector<BossTitle> BossTitlesData
{
	{ "Sonic", BossTitles[Characters_Sonic], SonicLetters, VsSonic1},
	{ "Sonic", BossTitles[Characters_Sonic], SonicLetters, VsSonic2 },
	{ "Shadow", BossTitles[Characters_Shadow], ShadowLetters, VsShadow1 },
	{ "Shadow", BossTitles[Characters_Shadow], ShadowLetters, VsShadow2 },
	{ "Tails", BossTitles[Characters_Tails], TailsLetters, VsTails1 },
	{ "Tails", BossTitles[Characters_Tails], TailsLetters, VsTails2 },
	{ "Dr.Eggman", BossTitles[Characters_Eggman], EggmanLetters, VsEggman1 },
	{ "Dr.Eggman", BossTitles[Characters_Eggman], EggmanLetters, VsEggman2 },
	{ "Knuckles", BossTitles[Characters_Knuckles], KnucklesLetters, VsKnuckles },
	{ "Rouge", BossTitles[Characters_Rouge], RougeLetters, VsRouge },
};


void ProcessBossTitles()
{
	for (auto& title : BossTitlesData)
	{
		if (!title.CustomLetterData.empty()) continue;
		
		if (title.CustomText->empty())
		{
			*title.CustomText = title.DefaultText;
		}		

		for (auto& letter : *title.CustomText)
		{
			if (BossLetters.count(std::toupper(letter)))
			{
				title.CustomLetterData.push_back(BossLetters[std::toupper(letter)]);
			}			
		}
	}
}


int CalculateSpacing(const std::vector<BossTitleLetterData>& letterData)
{
	int maxSpacing = 12;
	float baseWidth = 320 * ( 3.0f / 4 ) * ( HorizontalResolution / VerticalResolution );
	int totalWidth = 0;
	int spacing = maxSpacing;

	for (auto& letter : letterData)
	{
		totalWidth += letter.Width;
	}

	while (spacing > 0)
	{
		if (totalWidth + spacing * (letterData.size() - 1) > baseWidth)
		{
			spacing--;
		}
		else break;
	}
	
	return spacing;
}

void SetCharacterSpacing()
{
	for (auto& data : CustomLetterData)
	{
		int spacing = CalculateSpacing(*data);

		for (int i = 0; i < data->size() - 1; i++) //add spacing to all letters expect for the last one, so the title will be properly centered
		{
			data->at(i).Width += spacing;
		}
	}
}


int CalculateDisplayTime(const BossTitle& title)
{
	int vanillaDisplayTime = title.VanillaBossTitleData.DisplayTime;
	int delay = 20;
	int displayTime = 120;

	for (auto& letter : title.CustomLetterData)
	{
		displayTime += delay;
	}

	return displayTime < vanillaDisplayTime ? vanillaDisplayTime : displayTime;
}

void SetUpBossTitles()
{
	for (auto& title : BossTitlesData)
	{
		title.VanillaBossTitleData = { title.CustomLetterData.data(), (short)title.CustomLetterData.size(), 0, 20, nullptr, 0, 3, CalculateDisplayTime(title), title.VanillaBossTitleData.TexList, 320, 240, 2, 0xFFFFFF};
	}
}


void RenameCharacterBossTexlists()
{
	const char* vscharacter = "titletex_vscharacter";

	WriteData((const char**)0x61A352, vscharacter); //Sonic 1
	WriteData((const char**)0x4C906B, vscharacter); //Sonic 2
	WriteData((const char**)0x61A373, vscharacter); //Shadow 1
	WriteData((const char**)0x4C908C, vscharacter); //Shadow 2
	WriteData((const char**)0x627CD1, vscharacter); //Tails 1
	WriteData((const char**)0x6639A8, vscharacter); //Tails 2
	WriteData((const char**)0x627CF2, vscharacter); //Eggman 1
	WriteData((const char**)0x6639C9, vscharacter); //Eggman 2
	WriteData((const char**)0x64B76F, vscharacter); //Knuckles
	WriteData((const char**)0x64B790, vscharacter); //Rouge
}


void InitCharacterBossTitles(const char* modPath)
{
	ProcessBossTitles();
	SetCharacterSpacing();
	SetUpBossTitles();
	RenameCharacterBossTexlists();
}