#include "header.h"
#include "game.h"
#include "clock.h"
#include "MazeGenerator.h"
#include "player.h"
#include "functions.h"
#include "highscore.h"
#include "clock.h"

extern bool g_quit;
extern bool g_key;
extern vector <pos> hori;
extern vector <pos> vert;
extern vector <pos> roun;

bool g_clear = false;
bool lvl1 = false;
bool lvl2 = false;
string m1 = "m1OriginalCreation.txt";
string m2 = "m2ModifiedWintermaulMaze.txt";

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
	lvl1 = false;
	clock_end();
	//Calls the highscore function
	store(minutes,seconds);
	if(!g_quit)
	{
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
	lvl2 = false;
	clock_end();
	//Calls the highscore function
	store2(minutes,seconds);
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