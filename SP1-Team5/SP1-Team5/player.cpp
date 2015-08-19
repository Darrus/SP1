#include "header.h"
#include "player.h"
#include "functions.h"
#include "MazeGenerator.h"

void player()
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),g_player);
	cout << (char)1;
	gotoXY(g_player.X,g_player.Y);
}

void movement()
{
	int ch = _getch();
	switch(ch)
	{
	case 'w':
	case 'W':
	case 72:
		if(g_player.Y > 0 && g_size[g_player.Y-1][g_player.X] == '0')
		{
			g_player.Y--;
		}
		else if(g_size[g_player.Y-1][g_player.X] == 'x')
		{
			g_player.Y--;
			g_size[g_player.Y][g_player.X] = '3';
		}
		break;
	case 's':
	case 'S':
	case 80:
		if(g_player.Y < 24 && g_size[g_player.Y+1][g_player.X] == '0')
		{
			g_player.Y++;
		}
		else if(g_size[g_player.Y+1][g_player.X] == 'x')
		{
			g_player.Y++;
			g_size[g_player.Y][g_player.X] = '3';
		}
		break;
	case 'd':
	case 'D':
	case 77:
		if(g_player.X < 79 && g_size[g_player.Y][g_player.X+1] == '0')
		{
			g_player.X++;
		}
		else if(g_size[g_player.Y][g_player.X+1] == 'x')
		{
			g_player.X++;
			g_size[g_player.Y][g_player.X] = '3';
		}
		break;
	case 'a':
	case 'A':
	case 75:
		if(g_player.X > 0 && g_size[g_player.Y][g_player.X-1] == '0')
		{
			g_player.X--;
		}
		else if(g_size[g_player.Y][g_player.X-1] == 'x')
		{
			g_player.X--;
			g_size[g_player.Y][g_player.X] = '3';
		}
		break;
	case 27:
		g_quit = true;
		break;
	}
}