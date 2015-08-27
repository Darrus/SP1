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
extern bool g_playing;
extern vector <pos> hori;
extern vector <pos> vert;
extern vector <pos> roun;

bool g_switch = false;
bool g_clear = false;
bool lvl1 = false;
bool lvl2 = false;
bool lvl3 = false;
bool c1 = false;
bool c2 = false;
bool c3 = false;
string m1 = "m1OriginalCreation.txt";
string m2 = "m2ModifiedWintermaulMaze.txt";
string m3 = "m3Copy.txt";

string customs = "custom1.txt";
string customs2 = "custom2.txt";
string customs3 = "custom3.txt";

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
	showscore();
	if (!g_quit)
	{
		//Calls the highscore function
		store(minutes,seconds);
		lvl3 = false;
		cont();
	}
}

void custom1()
{
	c1 = true;
	mazestore(customs);
	while(!g_quit && !g_clear)
	{
		mazemapping();
		if(g_playing == true)
		{
			UI();
			movement();
		}
		if (g_switch == false && g_playing == false)
		{
			customUI();
			custommovement1();
		}
		else if (g_switch == true && g_playing == false)
		{
			customUI1();
			custommovement1();
		}
	}
	if(!g_quit)
	{
		c1 = false;
		cout << "Press spacebar to continue";
		cont();
	}
}

void custom2()
{	
	c2 = true;
	mazestore(customs2);
	while(!g_quit && !g_clear)
	{
		mazemapping();
		if (g_playing == true)
		{
			UI();
			movement();
		}
		else if (g_switch == false)
		{
			customUI();
			custommovement2();
		}
		else if (g_switch == true)
		{
			customUI1();
			custommovement2();
		}
	}
	if(!g_quit)
	{
		c2 = false;
		cout << "Press spacebar to continue";
		cont();
	}
}

void custom3()
{	
	c3 = true;
	mazestore(customs3);
	while(!g_quit && !g_clear)
	{
		mazemapping();
		if (g_playing == true)
		{
			UI();
			movement();
		}
		else if (g_switch == false)
		{
			customUI();
			custommovement3();
		}
		else if (g_switch == true)
		{
			customUI1();
			custommovement3();
		}
	}
	if(!g_quit)
	{
		c3 = false;
		cout << "Press spacebar to continue";
		cont();
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
	else if(c1 == true)
		custom1();
	else if(c2 == true)
		custom2();
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