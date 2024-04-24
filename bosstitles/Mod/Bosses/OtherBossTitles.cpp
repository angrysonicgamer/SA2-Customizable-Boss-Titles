#include "pch.h"
#include "BossTitles.h"
#include "Mod/Config/Config.h"


int GetBossTitlesStyle()
{
	if (Config::BossTitlesStyle == "PC") return 0;
	if (Config::BossTitlesStyle == "DC/GC") return 1;
}


//King Boom Boo

BossTitleLetterData KBBLettersPC[]
{
	{ kbb_K, 22, 21, 0, 32, 32, 0 },
	{ kbb_I, 10, 21, 0, 32, 32, 0 },
	{ kbb_N, 21, 21, 0, 32, 32, 0 },
	{ kbb_G, 21, 21, 0, 32, 32, 0 },
	{ space, 14, 21, 0, 32, 32, 0 },
	{ kbb_B, 21, 21, 0, 32, 32, 0 },
	{ kbb_O, 21, 21, 0, 32, 32, 0 },
	{ kbb_O, 21, 21, 0, 32, 32, 0 },
	{ kbb_M, 25, 21, 0, 32, 32, 0 },
	{ space, 14, 21, 0, 32, 32, 0 },
	{ kbb_B, 21, 21, 0, 32, 32, 0 },
	{ kbb_O, 21, 21, 0, 32, 32, 0 },
	{ kbb_O, 21, 21, 0, 32, 32, 0 },
};

BossTitleLetterData KBBLettersDC[]
{
	{ kbb_K, 22, 22, 0, 32, 32, 0 },
	{ kbb_I, 18, 22, 0, 32, 32, 0 },
	{ kbb_N, 22, 22, 0, 32, 32, 0 },
	{ kbb_G, 21, 22, 0, 32, 32, 0 },
	{ space, 16, 22, 0, 32, 32, 0 },
	{ kbb_B, 24, 22, 0, 32, 32, 0 },
	{ kbb_O, 22, 22, 0, 32, 32, 0 },
	{ kbb_O, 22, 22, 0, 32, 32, 0 },
	{ kbb_M, 28, 22, 0, 32, 32, 0 },
	{ space, 16, 22, 0, 32, 32, 0 },
	{ kbb_B, 24, 22, 0, 32, 32, 0 },
	{ kbb_O, 22, 22, 0, 32, 32, 0 },
	{ kbb_O, 22, 22, 0, 32, 32, 0 },
};

FullBossTitleData KingBoomBooTitle[]
{
	{ arrayptrandlengthT(KBBLettersPC, short), 0, 20, KingBoomBoo.Bar, 16, 3, 360, KingBoomBoo.Texlist, 320, 275, 1.75, KBBColor }, //PC style
	{ arrayptrandlengthT(KBBLettersDC, short), -2, 20, KingBoomBoo.Bar, 16, 3, 360, KingBoomBoo.Texlist, 320, 275, 1.75, KBBColor }, //Dreamcast/Gamecube style
};

void WriteKingBoomBooTitle()
{
	KingBoomBoo = KingBoomBooTitle[GetBossTitlesStyle()];
}


//Egg Golem

BossTitleLetterData EggGolemLetters[]
{
	{ glm_E, 21, 18, 0, 32, 32, 0 },
	{ glm_G, 22, 18, 0, 32, 32, 0 },
	{ glm_G, 22, 18, 0, 32, 32, 0 },
	{ space, 16, 18, 0, 32, 32, 0 },
	{ glm_G, 22, 18, 0, 32, 32, 0 },
	{ glm_O, 23, 18, 0, 32, 32, 0 },
	{ glm_L, 17, 18, 0, 32, 32, 0 },
	{ glm_E, 21, 18, 0, 32, 32, 0 },
	{ glm_M, 26, 18, 0, 32, 32, 0 },
};

void WriteEggGolemTitles()
{
	EggGolemHero.Letters = EggGolemLetters;
	EggGolemDark.Letters = EggGolemLetters;
}


//The Biolizard

BossTitleLetterData BiolizardLettersPC[]
{
	{ bio_T, 19, 20, 0, 32, 32, 0 },
	{ bio_H, 20, 20, 0, 32, 32, 0 },
	{ bio_E, 19, 20, 0, 32, 32, 0 },
	{ space, 18, 20, 0, 32, 32, 0 },
	{ bio_B, 19, 20, 0, 32, 32, 0 },
	{ bio_I, 9, 20, 0, 16, 32, 0 },
	{ bio_O, 21, 20, 0, 32, 32, 0 },
	{ bio_L, 16, 20, 0, 32, 32, 0 },
	{ bio_I, 9, 20, 0, 16, 32, 0 },
	{ bio_Z, 18, 20, 0, 32, 32, 0 },
	{ bio_A, 20, 20, 0, 32, 32, 0 },
	{ bio_R, 20, 20, 0, 32, 32, 0 },
	{ bio_D, 17, 20, 0, 32, 32, 0 },
};

BossTitleLetterData BiolizardLettersDC[]
{
	{ bio_T, 19, 20, 0, 32, 32, 0 },
	{ bio_H, 20, 20, 0, 32, 32, 0 },
	{ bio_E, 19, 20, 0, 32, 32, 0 },
	{ space, 12, 20, 0, 32, 32, 0 },
	{ bio_B, 19, 20, 0, 32, 32, 0 },
	{ bio_I, 8, 20, 0, 32, 32, 0 },
	{ bio_O, 21, 20, 0, 32, 32, 0 },
	{ bio_L, 16, 20, 0, 32, 32, 0 },
	{ bio_I, 8, 20, 0, 32, 32, 0 },
	{ bio_Z, 19, 20, 0, 32, 32, 0 },
	{ bio_A, 22, 20, 0, 32, 32, 0 },
	{ bio_R, 20, 20, 0, 32, 32, 0 },
	{ bio_D, 18, 20, 0, 32, 32, 0 },
};

FullBossTitleData BiolizardTitle[]
{
	{ arrayptrandlengthT(BiolizardLettersPC, short), 0, 25, Biolizard.Bar, 15, 2, 0, Biolizard.Texlist, 320, 240, 1.5, WhiteColor },
	{ arrayptrandlengthT(BiolizardLettersDC, short), 0, 25, Biolizard.Bar, 15, 2, 0, Biolizard.Texlist, 320, 240, 1.5, WhiteColor },
};

void WriteBiolizardTitle()
{
	Biolizard = BiolizardTitle[GetBossTitlesStyle()];
}


//The Finalhazard

BossTitleLetterData FinalhazardLettersPC[]
{
	{ fin_T, 14, 25, 0, 16, 32, 0 },
	{ fin_H, 15, 25, 0, 16, 32, 0 },
	{ fin_E, 15, 25, 0, 16, 32, 0 },
	{ space, 7, 25, 0, 16, 32, 0 },
	{ fin_F, 15, 25, 0, 16, 32, 0 },
	{ fin_I, 7, 27, 0, 16, 32, 0 },
	{ fin_N, 15, 25, 0, 16, 32, 0 },
	{ fin_A, 16, 25, 0, 16, 32, 0 },
	{ fin_L, 12, 25, 0, 16, 32, 0 },
	{ fin_H, 15, 25, 0, 16, 32, 0 },
	{ fin_A, 16, 25, 0, 16, 32, 0 },
	{ fin_Z, 14, 25, 0, 16, 32, 0 },
	{ fin_A, 16, 25, 0, 16, 32, 0 },
	{ fin_R, 15, 25, 0, 16, 32, 0 },
	{ fin_D, 14, 25, 0, 16, 32, 0 },
};

BossTitleLetterData FinalhazardLettersDC[]
{
	{ fin_T, 15, 25, 0, 16, 32, 0 },
	{ fin_H, 16, 25, 0, 16, 32, 0 },
	{ fin_E, 12, 25, 0, 16, 32, 0 },
	{ space, 7, 25, 0, 16, 32, 0 },
	{ fin_F, 12, 25, 0, 16, 32, 0 },
	{ fin_I, 8, 27, 0, 16, 32, 0 },
	{ fin_N, 15, 25, 0, 16, 32, 0 },
	{ fin_A, 17, 25, 0, 16, 32, 0 },
	{ fin_L, 12, 25, 0, 16, 32, 0 },
	{ fin_H, 16, 25, 0, 16, 32, 0 },
	{ fin_A, 17, 25, 0, 16, 32, 0 },
	{ fin_Z, 13, 25, 0, 16, 32, 0 },
	{ fin_A, 17, 25, 0, 16, 32, 0 },
	{ fin_R, 15, 25, 0, 16, 32, 0 },
	{ fin_D, 15, 25, 0, 16, 32, 0 },
};

FullBossTitleData FinalhazardTitle[]
{
	{ arrayptrandlengthT(FinalhazardLettersPC, short), 0, 25, Finalhazard.Bar, 13, 2, 0, Finalhazard.Texlist, 320, 240, 2, WhiteColor },
	{ arrayptrandlengthT(FinalhazardLettersDC, short), 0, 25, Finalhazard.Bar, 13, 2, 0, Finalhazard.Texlist, 320, 240, 2, WhiteColor },
};

void WriteFinalHazardTitle()
{
	Finalhazard = FinalhazardTitle[GetBossTitlesStyle()];
}


void InitOtherBossTitles()
{
	WriteKingBoomBooTitle();
	WriteEggGolemTitles();
	WriteBiolizardTitle();
	WriteFinalHazardTitle();
}