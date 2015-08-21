#include "header.h"
#include "MazeGenerator.h"
#include "main.h"
#include "functions.h"
#include "player.h"
#include "clock.h"
#include "FOE_Movement.h"

extern vector <string> g_size;
extern vector <pos> hori;
extern vector <pos> vert;
extern COORD g_player;
extern bool g_quit;

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
//void FOEO()
//{
////{
////	if (g_size[g_FOEO.Y-1][g_FOEO.X] == '0' && g_size[g_FOEO.Y+1][g_FOEO.X] == '1' && (g_size[g_FOEO.Y][g_FOEO.X+1] || g_size[g_FOEO.Y][g_FOEO.X-1]))
////	{
////		
////		Oup = true;
////		Odown = false;
////		//Oleft = false;
////		//Oright = false;
////		//if (g_size[g_FOEO.Y-1][g_FOEO.X] == '0' && up == true)
////		//{
////		//	//move up
////		//	g_FOEO.Y--;
////		//	gotoXY(g_FOEO.X,g_FOEO.Y);
////		//	g_size[g_FOEO.Y][g_FOEO.X] = '^';
////		//	g_size[g_FOEO.Y+1][g_FOEO.X] = '0';
////		//}
////
////	}
////	else if(g_size[g_FOEO.Y+1][g_FOEO.X] == '0' && g_size[g_FOEO.Y-1][g_FOEO.X] == '1' && (g_size[g_FOEO.Y][g_FOEO.X+1] || g_size[g_FOEO.Y][g_FOEO.X-1]))
////	{
////		Odown = true;
////		Oup = false;
////		//Oleft = false;
////		//Oright = false;
////		//if (g_size[g_FOEO.Y+1][g_FOEO.X] == '0' && down == true)
////		//{
////		//	//move down
////		//	g_FOEO.Y++;
////		//	gotoXY(g_FOEO.X,g_FOEO.Y);
////		//	g_size[g_FOEO.Y][g_FOEO.X] = 'v';
////		//	g_size[g_FOEO.Y-1][g_FOEO.X] = '0';
////		//}
////	}
////	else if(g_size[g_FOEO.Y][g_FOEO.X+1] == '0' && g_size[g_FOEO.Y][g_FOEO.X-1] == '1' && (g_size[g_FOEO.Y+1][g_FOEO.X] || g_size[g_FOEO.Y-1][g_FOEO.X]))
////	{
////		Oright = true;
////		Oleft = false;
////		//Oup = false;
////		//Odown = false;
////		//if (g_size[g_FOEO.Y][g_FOEO.X+1] == '0' && right == true)
////		//{
////		//	//move right
////		//	g_FOEO.X++;
////		//	gotoXY(g_FOEO.X,g_FOEO.Y);
////		//	g_size[g_FOEO.Y][g_FOEO.X] = '>';
////		//	g_size[g_FOEO.Y][g_FOEO.X-1] = '0';
////		//}
////	}
////	else if(g_size[g_FOEO.Y][g_FOEO.X-1] == '0' && g_size[g_FOEO.Y][g_FOEO.X+1] == '1' && (g_size[g_FOEO.Y+1][g_FOEO.X] || g_size[g_FOEO.Y-1][g_FOEO.X]))
////	{
////		Oleft = true;
////		Oright = false;
////		//Oup = false;
////		//Odown = false;
////		//if (g_size[g_FOEO.Y][g_FOEO.X-1] == '0' && left == true)
////		//{
////		//	//move left
////		//	g_FOEO.X--;
////		//	gotoXY(g_FOEO.X,g_FOEO.Y);
////		//	g_size[g_FOEO.Y][g_FOEO.X] = '<';
////		//	g_size[g_FOEO.Y][g_FOEO.X+1] = '0';
////		//}
////	}
////	if (g_size[g_FOEO.Y-1][g_FOEO.X] == '0' && Oup == true)
////	{
////		//move up
////		g_FOEO.Y--;
////		gotoXY(g_FOEO.X,g_FOEO.Y);
////		g_size[g_FOEO.Y][g_FOEO.X] = '^';
////		g_size[g_FOEO.Y+1][g_FOEO.X] = '0';
////	}
////	else if (g_size[g_FOEO.Y+1][g_FOEO.X] == '0' && Odown == true)
////	{
////		//move down
////		g_FOEO.Y++;
////		gotoXY(g_FOEO.X,g_FOEO.Y);
////		g_size[g_FOEO.Y][g_FOEO.X] = 'v';
////		g_size[g_FOEO.Y-1][g_FOEO.X] = '0';
////	}
////	else if (g_size[g_FOEO.Y][g_FOEO.X+1] == '0' && Oright == true)
////	{
////		//move right
////		g_FOEO.X++;
////		gotoXY(g_FOEO.X,g_FOEO.Y);
////		g_size[g_FOEO.Y][g_FOEO.X] = '>';
////		g_size[g_FOEO.Y][g_FOEO.X-1] = '0';
////	}
////	else if (g_size[g_FOEO.Y][g_FOEO.X-1] == '0' && Oleft == true)
////	{
////		//move left
////		g_FOEO.X--;
////		gotoXY(g_FOEO.X,g_FOEO.Y);
////		g_size[g_FOEO.Y][g_FOEO.X] = '<';
////		g_size[g_FOEO.Y][g_FOEO.X+1] = '0';
////	}
//	step += 1;
//	if (step <= 2)
//	{
//		g_FOEO.Y++;
//		gotoXY(g_FOEO.X,g_FOEO.Y);
//		g_size[g_FOEO.Y][g_FOEO.X] = 'v';
//		g_size[g_FOEO.Y-1][g_FOEO.X] = '0';
//	}
//	else if (step > 2 && step <= 4)
//	{
//		g_FOEO.X--;
//		gotoXY(g_FOEO.X,g_FOEO.Y);
//		g_size[g_FOEO.Y][g_FOEO.X] = '<';
//		g_size[g_FOEO.Y][g_FOEO.X+1] = '0';
//	}
//	else if (step > 4 && step <= 6)
//	{
//		g_FOEO.Y--;
//		gotoXY(g_FOEO.X,g_FOEO.Y);
//		g_size[g_FOEO.Y][g_FOEO.X] = '^';
//		g_size[g_FOEO.Y+1][g_FOEO.X] = '0';
//	}
//	else if (step > 6 && step <= 8)
//	{
//		g_FOEO.X++;
//		gotoXY(g_FOEO.X,g_FOEO.Y);
//		g_size[g_FOEO.Y][g_FOEO.X] = '>';
//		g_size[g_FOEO.Y][g_FOEO.X-1] = '0';
//		if (step == 8)
//		{
//			step = 0;
//		}
//	}
//}

//Horizontal moving FOE
void FOEH(int c)
{
	for(int a = 0; a < c; ++a)
	{
		
		if (g_size[hori[a].Y][hori[a].X+1] == '0' && (g_size[hori[a].Y][hori[a].X-1] == '1' || g_size[hori[a].Y][hori[a].X-1] == 'x'))
		{
			hori[a].right = true;
			hori[a].left = false;
		}
		else if(g_size[hori[a].Y][hori[a].X-1] == '0' && (g_size[hori[a].Y][hori[a].X+1] == '1' || g_size[hori[a].Y][hori[a].X+1] == 'x'))
		{
			hori[a].left = true;
			hori[a].right = false;
		}
		if (g_size[hori[a].Y][hori[a].X+1] == '0' && hori[a].right == true)
		{
			//move right
			hori[a].X++;
			gotoXY(hori[a].X,hori[a].Y);
			g_size[hori[a].Y][hori[a].X] = '>';
			g_size[hori[a].Y][hori[a].X-1] = '0';
			/*if(hori[a].Y == g_player.Y && hori[a].X+1 == g_player.X)
			{
				g_quit = true;
			}*/
		}
		else if (g_size[hori[a].Y][hori[a].X-1] == '0' && hori[a].left == true)
		{
			//move left
			hori[a].X--;
			gotoXY(hori[a].X,hori[a].Y);
			g_size[hori[a].Y][hori[a].X] = '<';
			g_size[hori[a].Y][hori[a].X+1] = '0';
			/*if(hori[a].Y == g_player.Y && hori[a].X-1 == g_player.X)
			{
				g_quit = true;
			}*/
		}
	}
}

//Vertical moving FOE
void FOEV(int c)
{
	for(int a = 0; a < c; ++a)
	{
		if (g_size[vert[a].Y-1][vert[a].X] == '0' && g_size[vert[a].Y+1][vert[a].X] == '1')
		{
			vert[a].up = true;
			vert[a].down = false;
		}
		else if(g_size[vert[a].Y+1][vert[a].X] == '0' && g_size[vert[a].Y-1][vert[a].X] == '1')
		{
			vert[a].down = true;
			vert[a].up = false;
		}
		if (g_size[vert[a].Y-1][vert[a].X] == '0' && vert[a].up == true)
		{
			//move up
			vert[a].Y--;
			gotoXY(vert[a].X,vert[a].Y);
			g_size[vert[a].Y][vert[a].X] = '^';
			g_size[vert[a].Y+1][vert[a].X] = '0';
			if(vert[a].Y-1 == g_player.Y && vert[a].X == g_player.X)
			{
				g_quit = true;
			}
		}
		else if (g_size[vert[a].Y+1][vert[a].X] == '0' && vert[a].down == true)
		{
			//move down
			vert[a].Y++;
			gotoXY(vert[a].X,vert[a].Y);
			g_size[vert[a].Y][vert[a].X] = 'v';
			g_size[vert[a].Y-1][vert[a].X] = '0';
			if(vert[a].Y+1 == g_player.Y && vert[a].X == g_player.X)
			{
				g_quit = true;
			}
		}
	}
}