#include "header.h"
#include "player.h"
#include "functions.h"
#include "MazeGenerator.h"
#include "game.h"

void player()
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),g_player);
	detect();
	cout << (char)1;
	gotoXY(g_player.X,g_player.Y);
}

void movement()
{
	int ch = _getch();
	switch(ch)
	{
	case 72:
		if(g_player.Y > 0 && g_size[g_player.Y-1][g_player.X] == '0' || g_size[g_player.Y-1][g_player.X] == 'x' || g_size[g_player.Y-1][g_player.X] == '!')
		{
			g_player.Y--;
		}
		break;
	case 80:
		if(g_player.Y < 24 && g_size[g_player.Y+1][g_player.X] == '0' || g_size[g_player.Y+1][g_player.X] == 'x' || g_size[g_player.Y+1][g_player.X] == '!')
		{
			g_player.Y++;
		}
		break;
	case 77:
		if(g_player.X < 79 && g_size[g_player.Y][g_player.X+1] == '0' || g_size[g_player.Y][g_player.X+1] == 'x' || g_size[g_player.Y][g_player.X+1] == '!')
		{
			g_player.X++;
		}
		break;
	case 75:
		if(g_player.X > 0 && g_size[g_player.Y][g_player.X-1] == '0' || g_size[g_player.Y][g_player.X-1] == 'x' || g_size[g_player.Y][g_player.X-1] == '!')
		{
			g_player.X--;
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

void detect()
{
	switch(g_size[g_player.Y][g_player.X])
	{
	case 'x': g_size[g_player.Y][g_player.X] = '3';
		break; 
	case '!': g_size[g_player.Y][g_player.X] = '0';
		g_key = true;
		break;
	}
}