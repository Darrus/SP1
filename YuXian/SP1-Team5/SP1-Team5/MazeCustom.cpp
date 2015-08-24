#include "MazeGenerator.h"
#include "header.h"
#include "functions.h"
#include "player.h"
#include "MazeCustom.h"

extern vector <string> g_size;
extern COORD g_player;
extern bool g_quit;
extern bool g_switch;

char col[23] = {0};
char row[49] = {0};

void placewall(int Y, int X)
{
	g_size[Y][X] = '1';
}

void placedoor (int Y, int X)
{
	g_size[Y][X] = '2';
}

void placekey (int Y, int X)
{
	g_size[Y][X] = '!';
}

void delplace (int Y, int X)
{
	g_size[Y][X] = '0';
}

// refreshing the text file back to default
void refresh()
{
	ofstream refresh;
	refresh.open("custom.txt");
	for (int i = 1; i < sizeof(col); ++i) 
	{
		col[i] = '0';
		refresh << col[i];
		for (int j = 1; j < sizeof(row); ++j)
		{
			row[j] = '0';
			refresh << row[j];
		}
		refresh << '1' << endl;
	}
	for (int line = 0; line <= sizeof(row); ++line)
	{
		refresh << '1';
	}
	refresh.close();
}

// saving the edited txt file
void save() 
{
	ofstream save;
	save.open("custom.txt");
	for(size_t i = 0; i < g_size.size(); ++i)
	{
		for(size_t j = 0; j < g_size[i].size(); ++j)
		{
			save << g_size[i][j];
		}
		save << endl;
	}
	save.close();
}

void custommovement()
{
	int ch = _getch();
	switch (ch)
	{
	case 72:
		if(g_player.Y-1 >= 0)
		{
			g_player.Y--; // going up
		}
		break;
	case 80:
		if(g_player.Y+1 < 22)
		{
			g_player.Y++; // going down
		} 
		break; 
	case 77:
		if(g_player.X+1 < 49)
		{
			g_player.X++; // going right
		}
		break;
	case 75:
		if(g_player.X-1 >= 0)
		{
			g_player.X--; // going left
		}
		break;
	case 27:
		g_quit = true;
		break;
	case 'q':
	case 'Q':
		delplace(g_player.Y, g_player.X);
		break;
	case 'W':
	case 'w':
		placewall(g_player.Y, g_player.X);
		break;
	case 'd':
	case 'D':
		placedoor(g_player.Y, g_player.X);
		break;
	case 'E':
	case 'e':
		placekey(g_player.Y, g_player.X);
		break;
	case 'N':
	case 'n':
		refresh();
		break;
	case 'b':
	case 'B':
		save();
		break;
	case 'z':
	case 'Z':
		g_switch = true;
		break;
	}
}

void customUI()
{
	setcolor(0x2F);
	gotoXY(52,2);
	cout << "Press W to place down walls";
	gotoXY(52,3);
	cout << "Press E to place down keys";
	gotoXY(52,4);
	cout << "Press D to place down doors";
	gotoXY(52,5);
	cout << "Press N to reset the map";
	gotoXY(52,6);
	cout << "Press B to save the map";
	gotoXY(52, 7);
	cout << "Press Q remove blocks";
	gotoXY(52, 9);
	cout << "Press Esc to exit"  << endl;
	setcolor(7);
	gotoXY(0,24);
}