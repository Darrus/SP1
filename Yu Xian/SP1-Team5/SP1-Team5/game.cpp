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

extern COORD g_player;
extern bool g_quit;
extern bool g_key;
extern bool g_key1;
extern bool g_playing;
extern bool newscore;
extern bool g_once;
extern bool g_reset;
extern int seconds;
extern int minutes;

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

string customs1 = "custom1.txt";
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
	while(!g_quit && !g_clear && !g_reset)
	{
		mazemapping();
		UI();
		movement();
		showscore();
	}
	clock_end();

	if(g_reset == true)
	{
		g_reset = false;
		reset();
	}
	else
	{
		//Calls the highscore function
		cout << "Press spacebar to continue" << endl << "Press R to restart level";
		if(g_clear == true)
		{
			store(minutes,seconds);
			showscore();
		}
		if (newscore == false && g_quit == false)
		{
			win();
	}
		cont();
		play();
	}
}

void customlevel(int sel)
{
	g_player.X = 0;
	g_player.Y = 0;
	if(sel == 1)
	{
		c1 = true;
		mazestore(customs1);
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
	
	while(!g_quit && !g_clear && !g_reset)
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
	gotoXY(1, 25);
	cout << "Press spacebar to continue" << endl;
	if(g_playing == true)
	{
		if(g_reset == true)
		{
			g_reset = false;
			reset();
		}
		else
		{
			cont();
			play();
		}
	}
	else
	{
		cont();
		gamemenu();
	}
}

void reset(void)
{
	cls();
	g_key = false;
	g_key1 = false;
	g_clear = false;
	g_quit = false;
	if(lvl1 == true)
		levelselect(1);
	else if(lvl2 == true)
		levelselect(2);
	else if(lvl3 == true)
		levelselect(3);
	else if(c1 == true)
		customlevel(1);
	else if(c2 == true)
		customlevel(2);
	else if(c3 == true)
		customlevel(3);
}

void cont(void)
{
	char in = _getch();
	switch(in)
	{
	case ' ':
		cls();
		if(lvl1 == true)
			lvl1 = false;
		else if(lvl2 == true)
			lvl2 = false;
		else if(lvl3 == true)
			lvl3 = false;
		else if(c1 == true)
			c1 = false;
		else if(c2 == true)
			c2 = false;
		else if(c3 == true)
			c3 = false;
		reset();
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