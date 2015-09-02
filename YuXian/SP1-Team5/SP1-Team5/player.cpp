#include "header.h"
#include "player.h"
#include "functions.h"
#include "MazeGenerator.h"
#include "clock.h"
#include "game.h"
#include "FOE_Movement.h"
#include "sounds.h"

extern count counter;
extern bool g_clear;
extern vector <string> g_size;
extern bool lvl1;
extern bool lvl2;
extern bool lvl3;
extern bool c1;
extern bool c2;
extern bool c3;

bool g_key = false;
bool g_key1 = false;
bool g_quit = false;
bool g_reset = false;
COORD g_player;

void player(void)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),g_player);
	setcolor(0x0A);
	cout << (char)1;
}

void movement(void)
{
	int ch = _getch();
	switch(ch)
	{
	case 72:
		if(g_player.Y-1 >= 0)
		{
			detect(g_player.Y-1,g_player.X); //Top movement
		}
		break;
	case 80:
		if(g_player.Y+1 < 23)
		{
			detect(g_player.Y+1,g_player.X); //Down movement
		}
		break;
	case 77:
		if(g_player.X+1 < 50)
		{
			detect(g_player.Y,g_player.X+1); //Right movement
		}
		break;
	case 75:
		if(g_player.X-1 >= 0)
		{
			detect(g_player.Y,g_player.X-1); //Left movement
		}
		break;
	case 27:
		g_quit = true;
		break;
	case 'r':
	case 'R':
		g_reset = true;
		break;
	default: movement();
		break;
	}
}

void detect(int Y,int X)
{
	//Detection for FOE movements
	switch(g_size[Y][X])
	{
	case 'M':
		for(int i = 0; i < 2; ++i)
		{
			FOEH(counter.H);
			FOEV(counter.V);
			FOEO(counter.O);
		}
		muddy();
		break;
	case '1':
	case 'X':
	case '2':
	case '3':
	case '#':
		break;
	default:
		FOEH(counter.H);
		FOEV(counter.V);
		FOEO(counter.O);
		break;
	}

	//Detection for Player movements
	switch(g_size[Y][X])
	{
	case '0': 
	case 'M':
	case 'S':
	case '<':
	case '>':
	case '^':
	case 'V':
	case '?':
		g_player.Y = Y;
		g_player.X = X;
		break;
	case 'x': 
		g_size[Y][X] = 'X';
		g_player.Y = Y;
		g_player.X = X;
		brokenfloor();
		break;
	case '$':
		g_size[Y][X] = '0';
		g_player.Y = Y;
		g_player.X = X;
		g_key1 = true;
		gate();
		break;
	case '!': 
		g_size[Y][X] = '0';
		g_player.Y = Y;
		g_player.X = X;
		g_key = true;
		door1();
		break;
	case '4': 
		if(lvl1 == true)
			g_clear = true;
		else if(lvl2 == true)
			g_clear = true;
		else if(lvl3 == true)
			g_clear = true;
		else if(c1 == true)
			g_clear = true;
		else if(c2 == true)
			g_clear = true;
		else if(c3 == true)
			g_clear = true;
		g_player.Y = Y;
		g_player.X = X;
		break;
	}
}