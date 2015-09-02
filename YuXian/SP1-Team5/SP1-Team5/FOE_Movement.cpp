#include "header.h"
#include "MazeGenerator.h"
#include "functions.h"
#include "player.h"
#include "clock.h"
#include "FOE_Movement.h"

extern vector <string> g_size;
extern vector <pos> hori;
extern vector <pos> vert;
extern vector <pos> roun;
extern COORD g_player;
extern bool g_quit;

//Circular moving FOE
void FOEO(int c)
{
	for(int i = 0; i < c; ++i)
	{
		if ((g_size[roun[i].Y-1][roun[i].X+1] == '#' || g_size[roun[i].Y-1][roun[i].X+1] == '?') && g_size[roun[i].Y-1][roun[i].X] == '0')
		{
			roun[i].up = true;
			roun[i].down = false;
			roun[i].left = false;
			roun[i].right = false;
		}
		else if((g_size[roun[i].Y+1][roun[i].X-1] == '#' || g_size[roun[i].Y+1][roun[i].X-1] == '?') && g_size[roun[i].Y+1][roun[i].X] == '0')
		{
			roun[i].down = true;
			roun[i].up = false;
			roun[i].left = false;
			roun[i].right = false;
		}
		else if((g_size[roun[i].Y+1][roun[i].X+1] == '#' || g_size[roun[i].Y+1][roun[i].X+1] == '?') && g_size[roun[i].Y][roun[i].X+1] == '0')
		{
			roun[i].right = true;
			roun[i].left = false;
			roun[i].up = false;
			roun[i].down = false;
		}
		else if((g_size[roun[i].Y-1][roun[i].X-1] == '#' || g_size[roun[i].Y-1][roun[i].X-1] == '?') && g_size[roun[i].Y][roun[i].X-1] == '0')
		{
			roun[i].left = true;
			roun[i].right = false;
			roun[i].up = false;
			roun[i].down = false;
		}
		 

		if ((g_size[roun[i].Y-1][roun[i].X] == '0' || g_size[roun[i].Y-1][roun[i].X] == 'M') && roun[i].up == true)
		{
			//move up
			roun[i].Y--;
			gotoXY(roun[i].X,roun[i].Y);
			if(roun[i].mud == true)
			{
				g_size[roun[i].Y+1][roun[i].X] = 'M';
				roun[i].mud = false;
			}
			else
				g_size[roun[i].Y+1][roun[i].X] = '0';
			if(g_size[roun[i].Y][roun[i].X] == 'M')
				roun[i].mud = true;
			g_size[roun[i].Y][roun[i].X] = '@';
		}
		else if ((g_size[roun[i].Y+1][roun[i].X] == '0' ||g_size[roun[i].Y+1][roun[i].X] == 'M') && roun[i].down == true)
		{
			//move down
			roun[i].Y++;
			gotoXY(roun[i].X,roun[i].Y);
			if(roun[i].mud == true)
			{
				g_size[roun[i].Y-1][roun[i].X] = 'M';
				roun[i].mud = false;
			}
			else
				g_size[roun[i].Y-1][roun[i].X] = '0';
			if(g_size[roun[i].Y][roun[i].X] == 'M')
				roun[i].mud = true;
			g_size[roun[i].Y][roun[i].X] = '@';
		}
		else if ((g_size[roun[i].Y][roun[i].X+1] == '0' || g_size[roun[i].Y][roun[i].X+1] == 'M') && roun[i].right == true)
		{
			//move right
			roun[i].X++;
			gotoXY(roun[i].X,roun[i].Y);
			if(roun[i].mud == true)
			{
				g_size[roun[i].Y][roun[i].X-1] = 'M';
				roun[i].mud = false;
			}
			else
				g_size[roun[i].Y][roun[i].X-1] = '0';
			if(g_size[roun[i].Y][roun[i].X] == 'M')
				roun[i].mud = true;
			g_size[roun[i].Y][roun[i].X] = '@';
		}
		else if ((g_size[roun[i].Y][roun[i].X-1] == '0' || g_size[roun[i].Y][roun[i].X-1] == 'M') && roun[i].left == true)
		{
			//move left
			roun[i].X--;
			gotoXY(roun[i].X,roun[i].Y);
			if(roun[i].mud == true)
			{
				g_size[roun[i].Y][roun[i].X+1] = 'M';
				roun[i].mud = false;
			}
			else
				g_size[roun[i].Y][roun[i].X+1] = '0';
			if(g_size[roun[i].Y][roun[i].X] == 'M')
				roun[i].mud = true;
			g_size[roun[i].Y][roun[i].X] = '@';
		}
	}
}

//Horizontal moving FOE
void FOEH(int c)
{
	for(int a = 0; a < c; ++a)
	{
		
		if (g_size[hori[a].Y][hori[a].X-1] == '1' || g_size[hori[a].Y][hori[a].X-1] == 'x' || g_size[hori[a].Y][hori[a].X-1] == '?')
		{
			hori[a].right = true;
			hori[a].left = false;
		}
		else if(g_size[hori[a].Y][hori[a].X+1] == '1' || g_size[hori[a].Y][hori[a].X+1] == 'x' || g_size[hori[a].Y][hori[a].X+1] == '?')
		{
			hori[a].left = true;
			hori[a].right = false;
		}
		if ((g_size[hori[a].Y][hori[a].X+1] == '0' || g_size[hori[a].Y][hori[a].X+1] == 'M') && hori[a].right == true )
		{
			//move right
			hori[a].X++;
			gotoXY(hori[a].X,hori[a].Y);
			if(hori[a].mud == true)
			{
				g_size[hori[a].Y][hori[a].X-1] = 'M';
				hori[a].mud = false;
			}
			else
				g_size[hori[a].Y][hori[a].X-1] = '0';
			if(g_size[hori[a].Y][hori[a].X] == 'M')
				hori[a].mud = true;
			g_size[hori[a].Y][hori[a].X] = '>';
		}
		else if ((g_size[hori[a].Y][hori[a].X-1] == '0' || g_size[hori[a].Y][hori[a].X-1] == 'M') && hori[a].left == true)
		{
			//move left
			hori[a].X--;
			gotoXY(hori[a].X,hori[a].Y);
			if(hori[a].mud == true)
			{
				g_size[hori[a].Y][hori[a].X+1] = 'M';
				hori[a].mud = false;
			}
			else
				g_size[hori[a].Y][hori[a].X+1] = '0';
			if(g_size[hori[a].Y][hori[a].X] == 'M')
				hori[a].mud = true;
			g_size[hori[a].Y][hori[a].X] = '<';
		}
	}
}

//Vertical moving FOE
void FOEV(int c)
{
	for(int a = 0; a < c; ++a)
	{
		if (g_size[vert[a].Y+1][vert[a].X] == '1' || g_size[vert[a].Y+1][vert[a].X] == 'x')
		{
			vert[a].up = true;
			vert[a].down = false;
		}
		else if(g_size[vert[a].Y-1][vert[a].X] == '1' || g_size[vert[a].Y-1][vert[a].X] == 'x')
		{
			vert[a].down = true;
			vert[a].up = false;
		}
		else
		{
			vert[a].down = true;
		}
		if ((g_size[vert[a].Y-1][vert[a].X] == '0' || g_size[vert[a].Y-1][vert[a].X] == 'M') && vert[a].up == true)
		{
			//move up
			vert[a].Y--;
			gotoXY(vert[a].X,vert[a].Y);
			g_size[vert[a].Y][vert[a].X] = '^';
			g_size[vert[a].Y+1][vert[a].X] = '0';
		}
		else if ((g_size[vert[a].Y+1][vert[a].X] == '0' || g_size[vert[a].Y+1][vert[a].X] == 'M') && vert[a].down == true)
		{
			//move down
			vert[a].Y++;
			gotoXY(vert[a].X,vert[a].Y);
			g_size[vert[a].Y][vert[a].X] = 'v';
			g_size[vert[a].Y-1][vert[a].X] = '0';
		}
	}
}