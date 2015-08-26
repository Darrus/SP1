#include "header.h"
#include "game.h"
#include "clock.h"
#include "MazeGenerator.h"
#include "player.h"
#include "functions.h"
#include "highscore.h"
#include "clock.h"
#include "MazeCustom.h"
#include "GameMenu.h"

extern bool g_quit;
extern bool g_key;
extern vector <pos> hori;
extern vector <pos> vert;
extern vector <pos> roun;

bool g_switch = false;
bool g_clear = false;
bool lvl1 = false;
bool lvl2 = false;
bool lvl3 = false;
string m1 = "m1OriginalCreation.txt";
string m2 = "m2ModifiedWintermaulMaze.txt";
string m3 = "m3Final.txt";
string customs = "custom.txt";

void level1()
{
	lvl1 = true;
	mazestore(m1);
	clock_start();
	while(!g_quit && !g_clear)
	{
		mazemapping();
		UI();
		movement();
	}
	clock_end();
	showscore();
	if(!g_quit)
	{
		//Calls the highscore function
		store(minutes,seconds);
		lvl1 = false;
		cout << "Press spacebar to continue";
		cont();
	}
}

void level2()
{
	lvl2 = true;
	mazestore(m2);
	clock_start();
	while(!g_quit && !g_clear)
	{
		mazemapping();
		UI();
		movement();
	}
	clock_end();
	showscore();
	if (!g_quit)
	{
		//Calls the highscore function
		store(minutes,seconds);
		lvl2 = false;
		cont();
	}
}

void level3()
{
	lvl3 = true;
	mazestore(m3);
	clock_start();
	while(!g_quit && !g_clear)
	{
		mazemapping();
		UI();
		movement();
	}
	clock_end();
	lvl3 = false;
}

void custom()
{
	mazestore(customs);
	while(!g_quit)
	{
		mazemapping();
		if (g_switch == false)
		{
			customUI();
			custommovement();
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
	g_clear = false;
	hori.clear();
	vert.clear();
	if(lvl1 == true)
		level1();
	else if(lvl2 == true)
		level2();
	else if(lvl3 == true)
		level3();
	else
		custom();
}

void cont()
{
	char in = _getch();
	switch(in)
	{
	case ' ':
		gotoXY(0,0);
		cout << string(2000,' ');
		g_key = false;
		g_clear = false;
		hori.clear();
		vert.clear();
		play();
		break;
	default:
		cont();
		break;
	}
}