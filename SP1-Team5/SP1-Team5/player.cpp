#include "header.h"
#include "player.h"
#include "functions.h"
#include "MazeGenerator.h"
#include "game.h"

void player()
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),g_player);
	cout << (char)1;
}

void movement()
{
	int ch = _getch();
	switch(ch)
	{
	case 72:
		detect(g_player.Y-1,g_player.X); //Top movement
		break;
	case 80:
		detect(g_player.Y+1,g_player.X); //Down movement
		break;
	case 77:
		detect(g_player.Y,g_player.X+1); //Right movement
		break;
	case 75:
		detect(g_player.Y,g_player.X-1); //Left movement
		break;
	case 27:
		g_quit = true;
		break;
	case 'r':
	case 'R':
		reset();
		break;
	default: movement();
		break;
	}
}

void detect(int Y,int X)
{
	switch(g_size[Y][X])
	{
	case '0': 
		g_player.Y = Y;
		g_player.X = X;
		break;
	case 'x': 
		g_size[Y][X] = '3';
		g_player.Y = Y;
		g_player.X = X;
		break; 
	case '!': 
		g_size[Y][X] = '0';
		g_player.Y = Y;
		g_player.X = X;
		g_key = true;
		break;
	case '4': 
		g_clear = true;
		g_player.Y = Y;
		g_player.X = X;
		break;
	}
}