#pragma once

struct FullBossTitleData
{
	BossTitleLetterData* Letters;
	short LetterCount;
	short Spacing;
	int Delay;
	BossTitleLetterData* Bar;
	short BarFragmentsCount;
	short DisplayMode; //default value = 3 (displays all letters, doesn't ignore scale and display time)
	int DisplayTime;
	NJS_TEXLIST* TexList;
	float X;
	float Y;
	float Scale;
	int Color;
};

enum BossTitleLetterIDs
{
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
	apostrophe,
	exclamation,
	question,
	space = 0
};

DataPointer(FullBossTitleData, KingBoomBoo, 0x100C808);
DataPointer(FullBossTitleData, EggGolemHero, 0x16670D0);
DataPointer(FullBossTitleData, EggGolemDark, 0x16CC4EC);
DataPointer(FullBossTitleData, Biolizard, 0x1371BEC);
DataPointer(FullBossTitleData, Finalhazard, 0x170639C);

void InitCharacterBossTitles();
void SetUpGunRoboFont();