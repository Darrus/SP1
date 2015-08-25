#include "header.h"
#include "game.h"
#include "clock.h"
#include "MazeGenerator.h"
#include "player.h"
#include "functions.h"
#include "MazeCustom.h"

extern bool g_quit;
extern bool g_key;

bool g_switch = false;
bool g_clear = false;
string m1 = "m1OriginalCreation.txt";
string m2 = "m2ModifiedWintermaulMaze.txt";
string customs1 = "custom1.txt";
string customs2 = "custom2.txt";
string customs3 = "custom3.txt";

void level1()
{
	mazestore(m1);
	clock_start();
	while(!g_quit && !g_clear)
	{
		mazemapping();
		UI();
		movement();
	}
	clock_end();
	if(!g_quit)
	{
		cout << "Press spacebar to continue";
		cont();
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

void custom1()
{
	mazestore(customs1);
	while(!g_quit)
	{
		mazemapping();
		if (g_switch == false)
		{
		customUI();
		custommovement1();
		}
		else if (g_switch == true)
		{
		customUI1();
		movement();
		}
	}
}

void custom2()
{	
	mazestore(customs2);
	while(!g_quit)
	{
		mazemapping();
		if (g_switch == false)
		{
		customUI();
		custommovement2();
		}
		else if (g_switch == true)
		{
		customUI1();
		movement();
		}
	}
}

void custom3()
{	
	mazestore(customs3);
	while(!g_quit)
	{
		mazemapping();
		if (g_switch == false)
		{
		customUI();
		custommovement3();
		}
		else if (g_switch == true)
		{
		customUI1();
		movement();
		}
	}
}


void reset()
{
	gotoXY(0,0);
	cout << string(2000,' ');
	g_key = false;
	if(g_clear == false)
	{
		level1();
	}
	else
		level2();
}

void cont()
{
	char in = _getch();
	switch(in)
	{
	case ' ':
		reset();
		break;
	default:
		cont();
		break;
	}
}