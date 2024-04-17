#include "pch.h"
#include "BossTitles.h"
#include "BossTitleStuff.h"
#include "Mod/Config/Config.h"


//Externs from config

std::string SonicTitle;
std::string ShadowTitle;
std::string TailsTitle;
std::string EggmanTitle;
std::string KnucklesTitle;
std::string RougeTitle;
std::string AmyTitle;
std::string MetalSonicTitle;
std::string TikalTitle;
std::string ChaosTitle;
std::string ChaoWalkerTitle;
std::string DarkChaoTitle;

//Letter data

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

//Boss title data

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

//Texlist

NJS_TEXNAME VsCharacterTexName[42]; //total number of letters in BossLetters
NJS_TEXLIST VsCharacterTexlist{ arrayptrandlengthT(VsCharacterTexName, int) };


std::vector<BossTitleStuff> BossTitlesData
{
	{ "Sonic", SonicTitle, SonicLetters, VsSonic },
	{ "Shadow", ShadowTitle, ShadowLetters, VsShadow },
	{ "Tails", TailsTitle, TailsLetters, VsTails },
	{ "Dr.Eggman", EggmanTitle, EggmanLetters, VsEggman },
	{ "Knuckles", KnucklesTitle, KnucklesLetters, VsKnuckles },
	{ "Rouge", RougeTitle, RougeLetters, VsRouge },

	{ "Amy", AmyTitle, AmyLetters, VsAmy},
	{ "Metal Sonic", MetalSonicTitle, MetalSonicLetters, VsMetalSonic},
	{ "Tikal", TikalTitle, TikalLetters, VsTikal},
	{ "Chaos", ChaosTitle, ChaosLetters, VsChaos },
	{ "Chao", ChaoWalkerTitle, ChaoWalkerLetters, VsChaoWalker},
	{ "Dark Chao", DarkChaoTitle, DarkChaoLetters, VsDarkChao},
};


void ProcessBossTitles()
{
	for (auto& title : BossTitlesData)
	{
		if (title.CustomText.empty())
		{
			title.SetDefaultTitle();
		}

		title.SetUpBossTitle(&VsCharacterTexlist);
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
		if (CurrentLevel == LevelIDs_TailsVsEggman2 || CurrentLevel == LevelIDs_KnucklesVsRouge)
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