#include "header.h"
#include "MazeGenerator.h"
#include "functions.h"
#include "player.h"
#include "clock.h"
#include "game.h"

bool g_quit = false;
COORD g_player;
char g_size[25][60];
bool g_clear1 = false;
bool g_clear2 = false;
bool g_reset = false;

void main()
{
	while(!g_quit)
	{
		if(g_clear1 == false)
		{
			level1();
		}
		else
		{
			level2();
		}
	}
}