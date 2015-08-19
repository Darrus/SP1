#include "header.h"
#include "game.h"
#include "clock.h"
#include "MazeGenerator.h"
#include "player.h"
#include "functions.h"

string m1 = "m1OriginalCreation.txt";
string m2 = "m2ModifiedWintermaulMaze.txt";

void level1()
{
	mazestore(m1);
	clock_start();
	while(!g_quit && !g_reset)
	{
		mazemapping();
		UI();
		movement();
	}
	clock_end();
	if(g_reset == true)
	{
		reset();
	}
}

void level2()
{
	mazestore(m2);
	clock_start();
	while(!g_quit)
	{
		mazemapping();
		UI();
		movement();
	}
	clock_end();
}

void reset()
{
	gotoXY(0,0);
	cout << string(1920,' ');
	if(g_clear1 == false)
	{
		g_reset = false;
		level1();
	}
	else
	{
		level2();
	}
}