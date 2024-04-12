#include "pch.h"
#include "BossTitles.h"


//Setting up widths for redrawn GUN robo boss title textures

struct GunRoboLetterData
{
	int Index;
	float Width;
};

DataArray(GunRoboLetterData, GunRoboLetterWidths, 0x11188A8, 20);


std::vector<GunRoboLetterData> EnglishValues
{
	{ 0, 16 }, //-1
	{ 1, 22 }, //-3
	{ 2, 22 }, //-6
	{ 3, 15 }, //B
	{ 4, 16 }, //D
	{ 5, 13 }, //F
	{ 6, 17 }, //G
	{ 7, 15 }, //H
	{ 8, 5 }, //I
	{ 9, 12 }, //L
	{ 10, 15 }, //N
	{ 11, 18 }, //O
	{ 12, 16 }, //R
	{ 13, 15 }, //S
	{ 14, 15 }, //T
	{ 15, 18 }, //Y
	{ 16, 8 }, //t
	{ 17, 13 }, //x
	{ 18, 26 }, //A
	{ 19, 7 } //space
};


void SetUpGunRoboFont()
{
	int size = EnglishValues.size();
	for (int i = 0; i < size; i++)
	{
		GunRoboLetterWidths[i] = EnglishValues[i];
	}
};