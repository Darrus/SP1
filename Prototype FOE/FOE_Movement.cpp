#include "header.h"
#include "MazeGenerator.h"
#include "main.h"
#include "functions.h"
#include "player.h"
#include "clock.h"
#include "FOE_Movement.h"

int step = 0;

void FOE_O_clockwise()
{
	step += 1;
	/*if(g_size[g_FOEO.Y+1][g_FOEO.X] == '0' && g_size[g_FOEO.Y][g_FOEO.X+1] == '1')
	{
		g_FOEO.Y++;
		gotoXY(g_FOEO.X,g_FOEO.Y);
		g_size[g_FOEO.Y][g_FOEO.X] = 'O';
		g_size[g_FOEO.Y-1][g_FOEO.X] = '0';
	}
	else if(g_size[g_FOEO.Y][g_FOEO.X-1] == '0' && g_size[g_FOEO.Y+1][g_FOEO.X] == '1')
	{
		g_FOEO.X--;
		gotoXY(g_FOEO.X,g_FOEO.Y);
		g_size[g_FOEO.Y][g_FOEO.X] = 'O';
		g_size[g_FOEO.Y][g_FOEO.X+1] = '0';
	}
	else if(g_size[g_FOEO.Y-1][g_FOEO.X] == '0' && g_size[g_FOEO.Y][g_FOEO.X-1] == '1')
	{
		g_FOEO.Y--;
		gotoXY(g_FOEO.X,g_FOEO.Y);
		g_size[g_FOEO.Y][g_FOEO.X] = 'O';
		g_size[g_FOEO.Y+1][g_FOEO.X] = '0';
	}*/
	if (step <= 2)
	{
		g_FOEO.Y++;
		gotoXY(g_FOEO.X,g_FOEO.Y);
		g_size[g_FOEO.Y][g_FOEO.X] = 'O';
		g_size[g_FOEO.Y-1][g_FOEO.X] = '0';
	}
	else if (step > 2 && step <= 4)
	{
		g_FOEO.X--;
		gotoXY(g_FOEO.X,g_FOEO.Y);
		g_size[g_FOEO.Y][g_FOEO.X] = 'O';
		g_size[g_FOEO.Y][g_FOEO.X+1] = '0';
	}
	else if (step > 4 && step <= 6)
	{
		g_FOEO.Y--;
		gotoXY(g_FOEO.X,g_FOEO.Y);
		g_size[g_FOEO.Y][g_FOEO.X] = 'O';
		g_size[g_FOEO.Y+1][g_FOEO.X] = '0';
	}
	else if (step > 6 && step <= 8)
	{
		g_FOEO.X++;
		gotoXY(g_FOEO.X,g_FOEO.Y);
		g_size[g_FOEO.Y][g_FOEO.X] = 'O';
		g_size[g_FOEO.Y][g_FOEO.X-1] = '0';
		if (step == 8)
		{
			step = 0;
		}
	}
}

void FOE_stay()
{
	gotoXY(g_FOEO.X,g_FOEO.Y);
	g_size[g_FOEO.Y][g_FOEO.X] = 'O';
}