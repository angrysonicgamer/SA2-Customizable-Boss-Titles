#include "pch.h"
#include "BossTitles.h"
#include "Config.h"


//Externs from config

std::string SonicTitle;
std::string ShadowTitle;
std::string TailsTitle;
std::string EggmanTitle;
std::string KnucklesTitle;
std::string RougeTitle;

//For CharSel

std::string AmyTitle = "Amy";
std::string MetalSonicTitle = "Metal Sonic";
std::string TikalTitle = "Tikal";
std::string ChaosTitle = "Chaos";
std::string ChaoWalkerTitle = "Chao";
std::string DarkChaoTitle = "Dark Chao";


std::vector<BossTitleLetterData> SonicLetters;
std::vector<BossTitleLetterData> ShadowLetters;
std::vector<BossTitleLetterData> TailsLetters;
std::vector<BossTitleLetterData> EggmanLetters;
std::vector<BossTitleLetterData> KnucklesLetters;
std::vector<BossTitleLetterData> RougeLetters;

std::vector<BossTitleLetterData> AmyLetters;
std::vector<BossTitleLetterData> MetalSonicLetters;
std::vector<BossTitleLetterData> TikalLetters;
std::vector<BossTitleLetterData> ChaosLetters;
std::vector<BossTitleLetterData> ChaoWalkerLetters;
std::vector<BossTitleLetterData> DarkChaoLetters;


FullBossTitleData VsSonic;
FullBossTitleData VsShadow;
FullBossTitleData VsTails;
FullBossTitleData VsEggman;
FullBossTitleData VsKnuckles;
FullBossTitleData VsRouge;

FullBossTitleData VsAmy;
FullBossTitleData VsMetalSonic;
FullBossTitleData VsTikal;
FullBossTitleData VsChaos;
FullBossTitleData VsChaoWalker;
FullBossTitleData VsDarkChao;


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


NJS_TEXNAME VsCharacterTexName[41]; //total number of letters in BossLetters
NJS_TEXLIST VsCharacterTexlist{ arrayptrandlengthT(VsCharacterTexName, int) };


struct BossTitle
{
	std::string DefaultText;
	std::string* CustomText;
	std::vector<BossTitleLetterData>& LetterData;
	FullBossTitleData& BossTitleData;
};

std::vector<BossTitle> BossTitlesData
{
	{ "Sonic", &SonicTitle, SonicLetters, VsSonic },
	{ "Shadow", &ShadowTitle, ShadowLetters, VsShadow },
	{ "Tails", &TailsTitle, TailsLetters, VsTails },
	{ "Dr.Eggman", &EggmanTitle, EggmanLetters, VsEggman },
	{ "Knuckles", &KnucklesTitle, KnucklesLetters, VsKnuckles },
	{ "Rouge", &RougeTitle, RougeLetters, VsRouge },

	{ AmyTitle, &AmyTitle, AmyLetters, VsAmy },
	{ MetalSonicTitle, &MetalSonicTitle, MetalSonicLetters, VsMetalSonic },
	{ TikalTitle, &TikalTitle, TikalLetters, VsTikal },
	{ ChaosTitle, &ChaosTitle, ChaosLetters, VsChaos },
	{ ChaoWalkerTitle, &ChaoWalkerTitle, ChaoWalkerLetters, VsChaoWalker },
	{ DarkChaoTitle, &DarkChaoTitle, DarkChaoLetters, VsDarkChao },
};


void ProcessBossTitles()
{
	for (auto& title : BossTitlesData)
	{
		if (title.CustomText->empty())
		{
			*title.CustomText = title.DefaultText;
		}

		for (auto& letter : *title.CustomText)
		{
			if (BossLetters.count(std::toupper(letter)))
			{
				title.LetterData.push_back(BossLetters[std::toupper(letter)]);
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
	for (auto& title : BossTitlesData)
	{
		int spacing = CalculateSpacing(title.LetterData);

		for (int i = 0; i < title.LetterData.size() - 1; i++) //add spacing to all letters expect for the last one, so the title will be properly centered
		{
			title.LetterData[i].Width += spacing;
		}
	}
}


int CalculateDisplayTime(const BossTitle& title)
{
	int defaultDisplayTime = 360;
	int delay = 20;
	int displayTime = 120;

	for (auto& letter : title.LetterData)
	{
		displayTime += delay;
	}

	return displayTime < defaultDisplayTime ? defaultDisplayTime : displayTime;
}

void SetUpBossTitles()
{
	for (auto& title : BossTitlesData)
	{
		title.BossTitleData = { title.LetterData.data(), (short)title.LetterData.size(), 0, 20, nullptr, 0, 3, CalculateDisplayTime(title), &VsCharacterTexlist, 320, 240, 2, 0xFFFFFF};
	}
}



//Character Select (Plus) code for compatibility

void LoadBossTitle(char id)
{
	FullBossTitleData* title = nullptr;
	switch (id)
	{
	case Characters_Sonic:
		title = &VsSonic;
		break;
	case Characters_Shadow:
		title = &VsShadow;
		break;
	case Characters_Tails:
	case Characters_MechTails:
		title = &VsTails;
		break;
	case Characters_Eggman:
	case Characters_MechEggman:
		title = &VsEggman;
		break;
	case Characters_Knuckles:
		title = &VsKnuckles;
		break;
	case Characters_Rouge:
		title = &VsRouge;
		break;
	case Characters_Amy:
		title = &VsAmy;
		break;
	case Characters_MetalSonic:
		title = &VsMetalSonic;
		break;
	case Characters_Tikal:
		title = &VsTikal;
		break;
	case Characters_Chaos:
		title = &VsChaos;
		break;
	case Characters_ChaoWalker:
		title = &VsChaoWalker;
		break;
	case Characters_DarkChaoWalker:
		title = &VsDarkChao;
		break;
	}

	if (title)
	{
		if (CurrentLevel == LevelIDs_TailsVsEggman2)
		{
			if (title->DisplayTime < 480)
			{
				title->DisplayTime = 480;
			}
		}

		LoadBossTitleExec(nullptr, (BossTitleData*)title);
	}
}


const void* const loc_4C8142 = (void*)0x4C8142;
__declspec(naked) void LoadShadow2BossTitle()
{
	__asm
	{
		movzx eax, al
		push eax
		call LoadBossTitle
		pop eax
		jmp loc_4C8142
	}
}

const void* const loc_619D4C = (void*)0x619D4C;
__declspec(naked) void LoadShadow1BossTitle()
{
	__asm
	{
		movzx eax, al
		push eax
		call LoadBossTitle
		pop eax
		jmp loc_619D4C
	}
}

const void* const loc_6273E7 = (void*)0x6273E7;
__declspec(naked) void LoadEggman1BossTitle()
{
	__asm
	{
		movzx eax, al
		push eax
		call LoadBossTitle
		pop eax
		jmp loc_6273E7
	}
}

const void* const loc_649C91 = (void*)0x649C91;
__declspec(naked) void LoadRougeBossTitle()
{
	__asm
	{
		movzx eax, al
		push eax
		call LoadBossTitle
		pop eax
		jmp loc_649C91
	}
}

const void* const loc_662A7B = (void*)0x662A7B;
__declspec(naked) void LoadEggman2BossTitle()
{
	__asm
	{
		movzx eax, al
		push eax
		call LoadBossTitle
		pop eax
		jmp loc_662A7B
	}
}


void FreeTitleTex(ObjectMaster* obj)
{
	FreeTexList(&VsCharacterTexlist);
}

void LoadBossTitleTex(ObjectMaster* obj, char id)
{
	const char* vscharacter = "titletex_vscharacter";
	LoadTextureList(vscharacter, &VsCharacterTexlist);
	obj->DeleteSub = FreeTitleTex;
}


const void* const loc_4C909C = (void*)0x4C909C;
__declspec(naked) void LoadShadow2BossTitleTex()
{
	__asm
	{
		movzx eax, al
		push eax
		push edi
		call LoadBossTitleTex
		pop edi
		pop eax
		jmp loc_4C909C
	}
}

const void* const loc_61A383 = (void*)0x61A383;
__declspec(naked) void LoadShadow1BossTitleTex()
{
	__asm
	{
		movzx eax, al
		push eax
		push edi
		call LoadBossTitleTex
		pop edi
		pop eax
		jmp loc_61A383
	}
}

const void* const loc_627D02 = (void*)0x627D02;
__declspec(naked) void LoadEggman1BossTitleTex()
{
	__asm
	{
		movzx eax, al
		push eax
		push edi
		call LoadBossTitleTex
		pop edi
		pop eax
		jmp loc_627D02
	}
}

const void* const loc_64B7A0 = (void*)0x64B7A0;
__declspec(naked) void LoadRougeBossTitleTex()
{
	__asm
	{
		movzx eax, al
		push eax
		push edi
		call LoadBossTitleTex
		pop edi
		pop eax
		jmp loc_64B7A0
	}
}

const void* const loc_6639D9 = (void*)0x6639D9;
__declspec(naked) void LoadEggman2BossTitleTex()
{
	__asm
	{
		movzx eax, al
		push eax
		push edi
		call LoadBossTitleTex
		pop edi
		pop eax
		jmp loc_6639D9
	}
}


void InitCharacterBossTitles()
{
	ProcessBossTitles();
	SetCharacterSpacing();
	SetUpBossTitles();

	WriteJump((void*)0x4C8124, LoadShadow2BossTitle);
	WriteJump((void*)0x4C9061, LoadShadow2BossTitleTex);
	WriteJump((void*)0x619D2E, LoadShadow1BossTitle);
	WriteJump((void*)0x61A348, LoadShadow1BossTitleTex);
	WriteJump((void*)0x6273C9, LoadEggman1BossTitle);
	WriteJump((void*)0x627CC7, LoadEggman1BossTitleTex);
	WriteJump((void*)0x649C73, LoadRougeBossTitle);
	WriteJump((void*)0x64B765, LoadRougeBossTitleTex);
	WriteJump((void*)0x662A5D, LoadEggman2BossTitle);
	WriteJump((void*)0x66399E, LoadEggman2BossTitleTex);
}