#include "header.h"
#include "MazeGenerator.h"
#include "main.h"
#include "functions.h"
#include "player.h"
#include "clock.h"
#include "FOE_Movement.h"

int step = 0;
bool up;
bool down;
bool left;
bool right;
bool Oup = false;
bool Odown = false;
bool Oleft = false;
bool Oright = false;

//Circular moving FOE
void FOEO()
{
//{
//	if (g_size[g_FOEO.Y-1][g_FOEO.X] == '0' && g_size[g_FOEO.Y+1][g_FOEO.X] == '1' && (g_size[g_FOEO.Y][g_FOEO.X+1] || g_size[g_FOEO.Y][g_FOEO.X-1]))
//	{
//		
//		Oup = true;
//		Odown = false;
//		//Oleft = false;
//		//Oright = false;
//		//if (g_size[g_FOEO.Y-1][g_FOEO.X] == '0' && up == true)
//		//{
//		//	//move up
//		//	g_FOEO.Y--;
//		//	gotoXY(g_FOEO.X,g_FOEO.Y);
//		//	g_size[g_FOEO.Y][g_FOEO.X] = '^';
//		//	g_size[g_FOEO.Y+1][g_FOEO.X] = '0';
//		//}
//
//	}
//	else if(g_size[g_FOEO.Y+1][g_FOEO.X] == '0' && g_size[g_FOEO.Y-1][g_FOEO.X] == '1' && (g_size[g_FOEO.Y][g_FOEO.X+1] || g_size[g_FOEO.Y][g_FOEO.X-1]))
//	{
//		Odown = true;
//		Oup = false;
//		//Oleft = false;
//		//Oright = false;
//		//if (g_size[g_FOEO.Y+1][g_FOEO.X] == '0' && down == true)
//		//{
//		//	//move down
//		//	g_FOEO.Y++;
//		//	gotoXY(g_FOEO.X,g_FOEO.Y);
//		//	g_size[g_FOEO.Y][g_FOEO.X] = 'v';
//		//	g_size[g_FOEO.Y-1][g_FOEO.X] = '0';
//		//}
//	}
//	else if(g_size[g_FOEO.Y][g_FOEO.X+1] == '0' && g_size[g_FOEO.Y][g_FOEO.X-1] == '1' && (g_size[g_FOEO.Y+1][g_FOEO.X] || g_size[g_FOEO.Y-1][g_FOEO.X]))
//	{
//		Oright = true;
//		Oleft = false;
//		//Oup = false;
//		//Odown = false;
//		//if (g_size[g_FOEO.Y][g_FOEO.X+1] == '0' && right == true)
//		//{
//		//	//move right
//		//	g_FOEO.X++;
//		//	gotoXY(g_FOEO.X,g_FOEO.Y);
//		//	g_size[g_FOEO.Y][g_FOEO.X] = '>';
//		//	g_size[g_FOEO.Y][g_FOEO.X-1] = '0';
//		//}
//	}
//	else if(g_size[g_FOEO.Y][g_FOEO.X-1] == '0' && g_size[g_FOEO.Y][g_FOEO.X+1] == '1' && (g_size[g_FOEO.Y+1][g_FOEO.X] || g_size[g_FOEO.Y-1][g_FOEO.X]))
//	{
//		Oleft = true;
//		Oright = false;
//		//Oup = false;
//		//Odown = false;
//		//if (g_size[g_FOEO.Y][g_FOEO.X-1] == '0' && left == true)
//		//{
//		//	//move left
//		//	g_FOEO.X--;
//		//	gotoXY(g_FOEO.X,g_FOEO.Y);
//		//	g_size[g_FOEO.Y][g_FOEO.X] = '<';
//		//	g_size[g_FOEO.Y][g_FOEO.X+1] = '0';
//		//}
//	}
//	if (g_size[g_FOEO.Y-1][g_FOEO.X] == '0' && Oup == true)
//	{
//		//move up
//		g_FOEO.Y--;
//		gotoXY(g_FOEO.X,g_FOEO.Y);
//		g_size[g_FOEO.Y][g_FOEO.X] = '^';
//		g_size[g_FOEO.Y+1][g_FOEO.X] = '0';
//	}
//	else if (g_size[g_FOEO.Y+1][g_FOEO.X] == '0' && Odown == true)
//	{
//		//move down
//		g_FOEO.Y++;
//		gotoXY(g_FOEO.X,g_FOEO.Y);
//		g_size[g_FOEO.Y][g_FOEO.X] = 'v';
//		g_size[g_FOEO.Y-1][g_FOEO.X] = '0';
//	}
//	else if (g_size[g_FOEO.Y][g_FOEO.X+1] == '0' && Oright == true)
//	{
//		//move right
//		g_FOEO.X++;
//		gotoXY(g_FOEO.X,g_FOEO.Y);
//		g_size[g_FOEO.Y][g_FOEO.X] = '>';
//		g_size[g_FOEO.Y][g_FOEO.X-1] = '0';
//	}
//	else if (g_size[g_FOEO.Y][g_FOEO.X-1] == '0' && Oleft == true)
//	{
//		//move left
//		g_FOEO.X--;
//		gotoXY(g_FOEO.X,g_FOEO.Y);
//		g_size[g_FOEO.Y][g_FOEO.X] = '<';
//		g_size[g_FOEO.Y][g_FOEO.X+1] = '0';
//	}
	step += 1;
	if (step <= 2)
	{
		g_FOEO.Y++;
		gotoXY(g_FOEO.X,g_FOEO.Y);
		g_size[g_FOEO.Y][g_FOEO.X] = 'v';
		g_size[g_FOEO.Y-1][g_FOEO.X] = '0';
	}
	else if (step > 2 && step <= 4)
	{
		g_FOEO.X--;
		gotoXY(g_FOEO.X,g_FOEO.Y);
		g_size[g_FOEO.Y][g_FOEO.X] = '<';
		g_size[g_FOEO.Y][g_FOEO.X+1] = '0';
	}
	else if (step > 4 && step <= 6)
	{
		g_FOEO.Y--;
		gotoXY(g_FOEO.X,g_FOEO.Y);
		g_size[g_FOEO.Y][g_FOEO.X] = '^';
		g_size[g_FOEO.Y+1][g_FOEO.X] = '0';
	}
	else if (step > 6 && step <= 8)
	{
		g_FOEO.X++;
		gotoXY(g_FOEO.X,g_FOEO.Y);
		g_size[g_FOEO.Y][g_FOEO.X] = '>';
		g_size[g_FOEO.Y][g_FOEO.X-1] = '0';
		if (step == 8)
		{
			step = 0;
		}
	}
}
//Horizontal moving FOE
void FOEH()
{
	if (g_size[g_FOEH.Y][g_FOEH.X+1] == '0' && g_size[g_FOEH.Y][g_FOEH.X-1] == '1')
	{
		right = true;
		left = false;
	}
	else if(g_size[g_FOEH.Y][g_FOEH.X-1] == '0' && g_size[g_FOEH.Y][g_FOEH.X+1] == '1')
	{
		left = true;
		right = false;
	}
	if (g_size[g_FOEH.Y][g_FOEH.X+1] == '0' && right == true)
	{
		//move right
		g_FOEH.X++;
		gotoXY(g_FOEH.X,g_FOEH.Y);
		g_size[g_FOEH.Y][g_FOEH.X] = '>';
		g_size[g_FOEH.Y][g_FOEH.X-1] = '0';
	}
	else if (g_size[g_FOEH.Y][g_FOEH.X-1] == '0' && left == true)
	{
		//move left
		g_FOEH.X--;
		gotoXY(g_FOEH.X,g_FOEH.Y);
		g_size[g_FOEH.Y][g_FOEH.X] = '<';
		g_size[g_FOEH.Y][g_FOEH.X+1] = '0';
	}
}
//Vertical moving FOE
void FOEV()
{
	if (g_size[g_FOEV.Y-1][g_FOEV.X] == '0' && g_size[g_FOEV.Y+1][g_FOEV.X] == '1')
	{
		up = true;
		down = false;
	}
	else if(g_size[g_FOEV.Y+1][g_FOEV.X] == '0' && g_size[g_FOEV.Y-1][g_FOEV.X] == '1')
	{
		down = true;
		up = false;
	}
	if (g_size[g_FOEV.Y-1][g_FOEV.X] == '0' && up == true)
	{
		//move up
		g_FOEV.Y--;
		gotoXY(g_FOEV.X,g_FOEV.Y);
		g_size[g_FOEV.Y][g_FOEV.X] = '^';
		g_size[g_FOEV.Y+1][g_FOEV.X] = '0';
	}
	else if (g_size[g_FOEV.Y+1][g_FOEV.X] == '0' && down == true)
	{
		//move down
		g_FOEV.Y++;
		gotoXY(g_FOEV.X,g_FOEV.Y);
		g_size[g_FOEV.Y][g_FOEV.X] = 'v';
		g_size[g_FOEV.Y-1][g_FOEV.X] = '0';
	}
}