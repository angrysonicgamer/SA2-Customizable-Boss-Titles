#pragma once

struct FullBossTitleData
{
	BossTitleLetterData* Letters;
	short LetterCount;
	short Spacing;
	short Delay;
	short Null1;				// always 0 probably, setting non-zero value doesn't seem to change anything
	BossTitleLetterData* Bar;
	short BarFragmentsCount;
	short DisplayMode;			// uses flags
	short DisplayTime;
	short Null2;				// always 0 probably as well
	NJS_TEXLIST* Texlist;
	float X;
	float Y;
	float Scale;
	int Color;
};

enum BossTitleDisplayFlags : short
{
	BossTitle_SetDisplayTime = 1,	// DisplayTime = 0 if not set (boss title doesn't disappear in this case, unless some other code makes it disappear)
	BossTitle_SetScale = 2,			// Scale = 1.0 if not set
	BossTitle_IgnoreDelay = 4,		// Delay = 0 if set (displays only first letter in this case), use set delay if not set
};

enum BossTitleLetterIDs
{
	space = 0,
	
	// vs character
	
	_A = 1000000,
	_B,
	_C,
	_D,
	_E,
	_F,
	_G,
	_H,
	_I,
	_J,
	_K,
	_L,
	_M,
	_N,
	_O,
	_P,
	_Q,
	_R,
	_S,
	_T,
	_U,
	_V,
	_W,
	_X,
	_Y,
	_Z,
	_0,
	_1,
	_2,
	_3,
	_4,
	_5,
	_6,
	_7,
	_8,
	_9,
	dot,
	comma,
	apostrophe,
	exclamation,
	question,	

	// King Boom Boo

	kbb_K = 8795042,
	kbb_I = 8795041,
	kbb_N = 8795044,
	kbb_G = 8795040,
	kbb_B = 8795029,
	kbb_O = 8795045,
	kbb_M = 8795043,

	// Egg Golem

	glm_G = 7001008,
	glm_O = 7001011,
	glm_L = 7001009,
	glm_E = 7001007,
	glm_M = 7001010,

	// The Biolizard

	bio_T = 8795069,
	bio_H = 8795065,
	bio_E = 8795064,
	bio_B = 8795047,
	bio_I = 8795066,
	bio_O = 8795067,
	bio_L = 8795095,
	bio_Z = 8795070,
	bio_A = 8795046,
	bio_R = 8795068,
	bio_D = 8795063,

	// The Finalhazard

	fin_T = 8795093,
	fin_H = 8795088,
	fin_E = 8795086,
	fin_F = 8795087,
	fin_I = 8795089,
	fin_N = 8795091,
	fin_A = 8795071,
	fin_L = 8795090,
	fin_Z = 8795094,
	fin_R = 8795092,
	fin_D = 8795085,
};

DataPointer(FullBossTitleData, KingBoomBoo, 0x100C808);
DataPointer(FullBossTitleData, EggGolemHero, 0x16670D0);
DataPointer(FullBossTitleData, EggGolemDark, 0x16CC4EC);
DataPointer(FullBossTitleData, Biolizard, 0x1371BEC);
DataPointer(FullBossTitleData, Finalhazard, 0x170639C);

const int WhiteColor = 0xFFFFFF;
const int KBBColor = 0x22FF22;

void InitCharacterBossTitles();
void SetUpGunRoboFont();
void InitOtherBossTitles();