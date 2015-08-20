#include "header.h"
#include "MazeGenerator.h"
#include "functions.h"
#include "player.h"
#include "clock.h"
#include "game.h"

bool g_quit = false;
COORD g_player;
char g_size[25][60];
bool g_clear = false;
bool g_key = false;

void main()
{
	level1();
	level2();
}