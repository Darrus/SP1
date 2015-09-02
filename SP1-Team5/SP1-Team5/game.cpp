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

bool g_clear = false; //Check if player has cleared the level

bool lvl1 = false; //Check if level 1 is being run
bool lvl2 = false; //Check if level 2 is being run
bool lvl3 = false; //Check if level 3 is being run

bool c1 = false; //Check if custom level 1 is being run
bool c2 = false; //Check if custom level 2 is being run
bool c3 = false; //Check if custom level 3 is being run

string m1 = "m1OriginalCreation.txt"; //String to hold name of .txt file
string m2 = "m2ModifiedWintermaulMaze.txt"; //String to hold name of .txt file
string m3 = "m3Copy.txt"; //String to hold name of .txt file

string customs = "custom1.txt"; //String to hold name of .txt file
string customs2 = "custom2.txt"; //String to hold name of .txt file
string customs3 = "custom3.txt"; //String to hold name of .txt file

/*
*	Goh Zheng Yuan & Lee Yu Xian
*	This .cpp contains function:
*	chooselevel(int sel) 21/8/2015 Goh Zheng Yuan
	Selects appropriate level and keep running till player cleared the level or press escape/reset

*	customlevel(int sel) Lee Yu Xian
	
*	reset() 21/8/2015 Goh Zheng Yuan
	Resets every boolean and check if player is still in level

*	cont() 21/8/2015 Goh Zheng Yuan
	Gets input spacebar, check which level is running now and turn it off.
*/

void chooselevel(int sel)
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

void reset()
{
	cls();
	g_key = false;
	g_key1 = false;
	g_clear = false;
	g_quit = false;
	if(lvl1 == true)
		chooselevel(1);
	else if(lvl2 == true)
		chooselevel(2);
	else if(lvl3 == true)
		chooselevel(3);
	else if(c1 == true)
		customlevel(1);
	else if(c2 == true)
		customlevel(2);
	else if(c3 == true)
		customlevel(3);
}

void cont()
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