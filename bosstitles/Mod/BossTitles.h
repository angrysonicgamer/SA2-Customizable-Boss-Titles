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

void InitBossTitles(const char* modPath);