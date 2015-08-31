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
#include "sounds.h"

extern bool g_quit;
extern bool g_key;
extern bool g_playing;
extern int seconds;
extern int minutes;
extern bool newscore;
extern bool g_once;

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

void levelselect(int sel)
{
	if(sel == 1)
	{
		lvl1 = true;
		mazestore(m1);
	}
	else if(sel == 2)
	{
		lvl2 = true;
		mazestore(m2);
	}
	else if(sel == 3)
	{
		lvl3 = true;
		mazestore(m3);
	}
	clock_start();
	showscore();
	while(!g_quit && !g_clear)
	{
		mazemapping();
		UI();
		movement();
		showscore();
	}
	clock_end();
	//Calls the highscore function
	if(g_clear == true)
	{
		store(minutes,seconds);
		showscore();
	}
	if (newscore == false && g_quit == false)
	{
		win();
	}
	cout << "Press spacebar to continue" << endl << "Press R to restart level";
	cont();
}

void custom(int sel)
{
	if(sel == 1)
	{
		c1 = true;
		mazestore(customs);
	}
	else if(sel == 2)
	{
		c2 = true;
		mazestore(customs2);
	}
	else if(sel == 3)
	{
		c3 = true;
		mazestore(customs3);
	}
	
	while(!g_quit && !g_clear)
	{
		mazemapping();
		if(g_playing == true)
		{
			UI();
			movement();
		}
		else if (g_playing == false)
		{
			customUI();
			custommovement();
		}
	}
	if(!g_quit)
	{
		c1 = false;
		cout << "Press spacebar to continue";
		cont();
	}
}

void reset()
{
	cls();
	g_key = false;
	g_clear = false;
	g_quit = false;
	if(lvl1 == true)
		level(1);
	else if(lvl2 == true)
		level(2);
	else if(lvl3 == true)
		level(3);
	else if(c1 == true)
		custom(1);
	else if(c2 == true)
		custom(2);
}

void cont()
{
	char in = _getch();
	switch(in)
	{
	case ' ':
		cls();
		if(lvl1 == true)
		{
			lvl1 = false;
			if(g_clear == true)
			{
				lvl2 = true;
			}
		}
		else if(lvl2 == true)
		{
			lvl2 = false;
			if(g_clear == true)
			{
				lvl3 = true;
			}
		}
		else if(lvl3 == true)
			lvl3 = false;
		else if(c1 == true)
			c1 = false;
		else if(c2 == true)
			c2 = false;
		play();
		break;
	case 'R':
	case 'r':
		reset();
		break;
	default:
		cont();
		break;
	}
}