#include "pch.h"
#include "BossTitles.h"


//Setting up widths for redrawn GUN robo boss title textures

struct GunRoboLetterData
{
	int ID;
	float Width;
};

DataArray(GunRoboLetterData, GunRoboLetterWidths, 0x11188A8, 20);


enum GunRoboBossTitleLetterIDs
{
	gun_1,
	gun_3,
	gun_6,
	gun_B,
	gun_D,
	gun_F,
	gun_G,
	gun_H,
	gun_I,
	gun_L,
	gun_N,
	gun_O,
	gun_R,
	gun_S,
	gun_T,
	gun_Y,
	gun_t,
	gun_x,
	gun_A,
	gun_space,
};

GunRoboLetterData NewLetterWidths[]
{
	{ gun_1, 16 },
	{ gun_3, 22 },
	{ gun_6, 22 },
	{ gun_B, 15 },
	{ gun_D, 16 },
	{ gun_F, 13 },
	{ gun_G, 17 },
	{ gun_H, 15 },
	{ gun_I, 5 },
	{ gun_L, 12 },
	{ gun_N, 15 },
	{ gun_O, 18 },
	{ gun_R, 16 },
	{ gun_S, 15 },
	{ gun_T, 15 },
	{ gun_Y, 18 },
	{ gun_t, 8 },
	{ gun_x, 13 },
	{ gun_A, 26 },
	{ gun_space, 7 },
};


void SetUpGunRoboFont()
{
	int size = std::size(NewLetterWidths);
	for (int i = 0; i < size; i++)
	{
		GunRoboLetterWidths[i] = NewLetterWidths[i];
	}
};