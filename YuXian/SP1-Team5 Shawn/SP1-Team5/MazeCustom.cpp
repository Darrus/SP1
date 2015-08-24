#include "MazeGenerator.h"
#include "header.h"
#include "functions.h"
#include "player.h"
#include "MazeCustom.h"

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

void refresh()
{
	ofstream cinfile;
	cinfile.open("custom.txt");
	for (int i = 1; i < sizeof(col); ++i) 
	{
		col[i] = '0';
		cinfile << col[i];
		for (int j = 1; j < sizeof(row); ++j)
		{
			row[j] = '0';
			cinfile << row[j];
		}
		cinfile << '1' << endl;
	}
	for (int line = 0; line <= sizeof(row); ++line)
	{
		cinfile << '1';
	}
	cinfile.close();
}

void save() 
{
	
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
	case 's':
	case 'S':
		placekey(g_player.Y, g_player.X);
		break;
	case 'm':
		refresh();
	}
}

void customUI()
{
	setcolor(0x2F);
	gotoXY(54,2);
	cout << "Find the key to ";
	gotoXY(54,3);
	cout << "unlock the door!";
	gotoXY(52,5);
	cout << "-Use the arrow keys to move";
	gotoXY(52,6);
	cout << "-Press R to reset";
	gotoXY(52,7);
	cout << "-Press Esc to exit";
	gotoXY(54, 9);
	setcolor(0x0A);
	cout << "Player = Green " << (char)1  << endl;
	gotoXY(54, 10);
	setcolor(0x0C);
	cout << "FOE = Red ^v<>" << endl;
	gotoXY(54, 11);
	setcolor(0x0C);
	cout << "Unstable Floors = Red 0" << endl;
	gotoXY(54, 12);
	setcolor(0x0C);
	cout << "Broken Floors = Red O" << endl;
	gotoXY(54, 13);
	setcolor(0x0E);
	cout << "Keys = Yellow *" << endl;
	setcolor(7);
	gotoXY(0,24);
}