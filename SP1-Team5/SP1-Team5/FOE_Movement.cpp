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

/*
*	Goh Zheng Yuan & Chuan Guang Zhe
*	This .cpp contains function:
*	FOEO() 28/8/2015
	Check what type of floor the Orbiting FOE is about to step on.

*	FOEH() 21/8/2015 
	Check what type of floor the Horizontal FOE is about to step on.

*	FOEV() 21/8/2015 
	Check what type of floor the Vertical FOE is about to step on.
*/

//Circular moving FOE
void FOEO(int c)
{
	for(int i = 0; i < c; ++i)
	{
		// Check the four corners of the FOE for a special wall, and assign a direction to it.
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
		else if(g_size[roun[i].Y][roun[i].X-1] == '#')
		{
			roun[i].left = false;
			roun[i].right = false;
			roun[i].up = false;
			roun[i].down = true;
		}
		else if(g_size[roun[i].Y][roun[i].X+1] == '#')
		{
			roun[i].left = false;
			roun[i].right = false;
			roun[i].up = true;
			roun[i].down = false;
		}
		else if(g_size[roun[i].Y+1][roun[i].X] == '#')
		{
			roun[i].left = false;
			roun[i].right = true;
			roun[i].up = false;
			roun[i].down = false;
		}
		else if(g_size[roun[i].Y-1][roun[i].X] == '#')
		{
			roun[i].left = true;
			roun[i].right = false;
			roun[i].up = false;
			roun[i].down = false;
		}
		 
		// Checks which direction is true, and checks what the FOE is about to step on
		if ((g_size[roun[i].Y-1][roun[i].X] == '0' || g_size[roun[i].Y-1][roun[i].X] == 'M') && roun[i].up == true)
		{
			//move up
			roun[i].Y--;
			gotoXY(roun[i].X,roun[i].Y);

			//If the FOE is stepping away from a muddy floor, it replaces the floor with the muddy floor
			if(roun[i].mud == true)
			{
				g_size[roun[i].Y+1][roun[i].X] = 'M';
				roun[i].mud = false;
			}

			//Else it replaces it with an empty floor
			else
				g_size[roun[i].Y+1][roun[i].X] = '0';

			//Checks if the FOE is currently stepping on a muddy floor
			if(g_size[roun[i].Y][roun[i].X] == 'M')
				roun[i].mud = true;

			//Assigns the current grid the position of the FOE
			g_size[roun[i].Y][roun[i].X] = '@';
		}
		else if ((g_size[roun[i].Y+1][roun[i].X] == '0' ||g_size[roun[i].Y+1][roun[i].X] == 'M') && roun[i].down == true)
		{
			//move down
			roun[i].Y++;
			gotoXY(roun[i].X,roun[i].Y);

			//If the FOE is stepping away from a muddy floor, it replaces the floor with the muddy floor
			if(roun[i].mud == true)
			{
				g_size[roun[i].Y-1][roun[i].X] = 'M';
				roun[i].mud = false;
			}

			//Else it replaces it with an empty floor
			else
				g_size[roun[i].Y-1][roun[i].X] = '0';

			//Checks if the FOE is currently stepping on a muddy floor
			if(g_size[roun[i].Y][roun[i].X] == 'M')
				roun[i].mud = true;

			//Assigns the current grid the position of the FOE
			g_size[roun[i].Y][roun[i].X] = '@';
		}
		else if ((g_size[roun[i].Y][roun[i].X+1] == '0' || g_size[roun[i].Y][roun[i].X+1] == 'M') && roun[i].right == true)
		{
			//move right
			roun[i].X++;
			gotoXY(roun[i].X,roun[i].Y);

			//If the FOE is stepping away from a muddy floor, it replaces the floor with the muddy floor
			if(roun[i].mud == true)
			{
				g_size[roun[i].Y][roun[i].X-1] = 'M';
				roun[i].mud = false;
			}

			//Else it replaces it with an empty floor
			else
				g_size[roun[i].Y][roun[i].X-1] = '0';

			//Checks if the FOE is currently stepping on a muddy floor
			if(g_size[roun[i].Y][roun[i].X] == 'M')
				roun[i].mud = true;

			//Assigns the current grid the position of the FOE
			g_size[roun[i].Y][roun[i].X] = '@';
		}
		else if ((g_size[roun[i].Y][roun[i].X-1] == '0' || g_size[roun[i].Y][roun[i].X-1] == 'M') && roun[i].left == true)
		{
			//move left
			roun[i].X--;
			gotoXY(roun[i].X,roun[i].Y);

			//If the FOE is stepping away from a muddy floor, it replaces the floor with the muddy floor
			if(roun[i].mud == true)
			{
				g_size[roun[i].Y][roun[i].X+1] = 'M';
				roun[i].mud = false;
			}

			//Else it replaces it with an empty floor
			else
				g_size[roun[i].Y][roun[i].X+1] = '0';

			//Checks if the FOE is currently stepping on a muddy floor
			if(g_size[roun[i].Y][roun[i].X] == 'M')
				roun[i].mud = true;

			//Assigns the current grid the position of the FOE
			g_size[roun[i].Y][roun[i].X] = '@';
		}
	}
}

//Horizontal moving FOE
void FOEH(int c)
{
	for(int a = 0; a < c; ++a)
	{
		//Checks if there is a wall behind, and move into the opposite direction
		if (g_size[hori[a].Y][hori[a].X-1] == '1' || g_size[hori[a].Y][hori[a].X-1] == 'x' || g_size[hori[a].Y][hori[a].X-1] == '?' || g_size[hori[a].Y][hori[a].X-1] == '#' || g_size[hori[a].Y][hori[a].X-1] == '3' || hori[a].X == 0)
		{
			hori[a].right = true;
			hori[a].left = false;
		}
		else if(g_size[hori[a].Y][hori[a].X+1] == '1' || g_size[hori[a].Y][hori[a].X+1] == 'x' || g_size[hori[a].Y][hori[a].X+1] == '?' || g_size[hori[a].Y][hori[a].X+1] == '#' || g_size[hori[a].Y][hori[a].X+1] == '3' || hori[a].X == 49)
		{
			hori[a].left = true;
			hori[a].right = false;
		}

		//If there is no wall, Checks what direction is the FOE facing.
		else if(g_size[hori[a].Y][hori[a].X] == '>')
		{
			hori[a].right = true;
			hori[a].left = false;
		}
		else if(g_size[hori[a].Y][hori[a].X] == '<')
		{
			hori[a].right = false;
			hori[a].left = true;
		}

		//Checks what type of floor the FOE is about to step on.
		if ((g_size[hori[a].Y][hori[a].X+1] == '0' || g_size[hori[a].Y][hori[a].X+1] == 'M') && hori[a].right == true )
		{
			//move right
			hori[a].X++;
			gotoXY(hori[a].X,hori[a].Y);

			//If the FOE is stepping away from a muddy floor, it replaces the floor with the muddy floor
			if(hori[a].mud == true)
			{
				g_size[hori[a].Y][hori[a].X-1] = 'M';
				hori[a].mud = false;
			}

			//Else it replaces it with an empty floor
			else
				g_size[hori[a].Y][hori[a].X-1] = '0';

			//Checks if the FOE is currently stepping on a muddy floor
			if(g_size[hori[a].Y][hori[a].X] == 'M')
				hori[a].mud = true;

			//Assigns the current grid the position of the FOE
			g_size[hori[a].Y][hori[a].X] = '>';
		}
		else if ((g_size[hori[a].Y][hori[a].X-1] == '0' || g_size[hori[a].Y][hori[a].X-1] == 'M') && hori[a].left == true)
		{
			//move left
			hori[a].X--;
			gotoXY(hori[a].X,hori[a].Y);

			//If the FOE is stepping away from a muddy floor, it replaces the floor with the muddy floor
			if(hori[a].mud == true)
			{
				g_size[hori[a].Y][hori[a].X+1] = 'M';
				hori[a].mud = false;
			}

			//Else it replaces it with an empty floor
			else
				g_size[hori[a].Y][hori[a].X+1] = '0';

			//Checks if the FOE is currently stepping on a muddy floor
			if(g_size[hori[a].Y][hori[a].X] == 'M')
				hori[a].mud = true;

			//Assigns the current grid the position of the FOE
			g_size[hori[a].Y][hori[a].X] = '<';
		}
	}
}

//Vertical moving FOE
void FOEV(int c)
{
	for(int a = 0; a < c; ++a)
	{
		//Checks if the FOE is at the edge of the map, if so head into the opposite direction.
		if(vert[a].Y == 0)
		{
			vert[a].down = true;
			vert[a].up = false;
		}

		//Checks if there is a wall behind, and move into the opposite direction
		else if(g_size[vert[a].Y-1][vert[a].X] == '1' || g_size[vert[a].Y-1][vert[a].X] == 'x' || g_size[vert[a].Y-1][vert[a].X] == '#' || g_size[vert[a].Y-1][vert[a].X] == '3' || g_size[vert[a].Y-1][vert[a].X] == '?')
		{
			vert[a].down = true;
			vert[a].up = false;
		}
		else if (g_size[vert[a].Y+1][vert[a].X] == '1' || g_size[vert[a].Y+1][vert[a].X] == 'x' || g_size[vert[a].Y+1][vert[a].X] == '#' || g_size[vert[a].Y+1][vert[a].X] == '3' || g_size[vert[a].Y+1][vert[a].X] == '?' || vert[a].Y == 22)
		{
			vert[a].up = true;
			vert[a].down = false;
		}

		//If there is no wall, Checks what direction is the FOE facing.
		else if (g_size[vert[a].Y][vert[a].X] == 'v')
		{
			vert[a].down = true;
			vert[a].up = false;
		}
		else if (g_size[vert[a].Y][vert[a].X] == '^')
		{
			vert[a].down = false;
			vert[a].up = true;
		}
		
		if(vert[a].up == true)
		{
			if (g_size[vert[a].Y-1][vert[a].X] == '0' || g_size[vert[a].Y-1][vert[a].X] == 'M')
			{
				//move up
				vert[a].Y--;
				gotoXY(vert[a].X,vert[a].Y);

				//If the FOE is stepping away from a muddy floor, it replaces the floor with the muddy floor
				if(vert[a].mud == true)
				{
					g_size[vert[a].Y+1][vert[a].X] = 'M';
					vert[a].mud = false;
				}

				//Else it replaces it with an empty floor
				else
					g_size[vert[a].Y+1][vert[a].X] = '0';

				//Checks if the FOE is currently stepping on a muddy floor
				if(g_size[vert[a].Y][vert[a].X] == 'M')
					vert[a].mud = true;

				//Assigns the current grid the position of the FOE
				g_size[vert[a].Y][vert[a].X] = '^';
			}
		}
		else if ((g_size[vert[a].Y+1][vert[a].X] == '0' || g_size[vert[a].Y+1][vert[a].X] == 'M') && vert[a].down == true)
		{
			//move down
			vert[a].Y++;
			gotoXY(vert[a].X,vert[a].Y);

			//If the FOE is stepping away from a muddy floor, it replaces the floor with the muddy floor
			if(vert[a].mud == true)
			{
				g_size[vert[a].Y-1][vert[a].X] = 'M';
				vert[a].mud = false;
			}

			//Else it replaces it with an empty floor
			else
				g_size[vert[a].Y-1][vert[a].X] = '0';

			//Checks if the FOE is currently stepping on a muddy floor
			if(g_size[vert[a].Y][vert[a].X] == 'M')
				vert[a].mud = true;

				//Assigns the current grid the position of the FOE
			g_size[vert[a].Y][vert[a].X] = 'v';
		}
	}
}