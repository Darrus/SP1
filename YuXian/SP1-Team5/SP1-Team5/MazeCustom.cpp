#include "MazeGenerator.h"
#include "header.h"
#include "functions.h"
#include "player.h"
#include "MazeCustom.h"

extern vector <string> g_size;
extern COORD g_player;
extern bool g_quit;
extern bool g_switch;
extern bool g_playing;
extern bool c1;
extern bool c2;
extern bool c3;

// refreshing the text file back to default
void refresh()
{
	ofstream refresh;
	for(size_t i = 0; i < g_size.size()-2; ++i)
	{
		for(size_t j = 0; j < g_size[i].size()-1; ++j)
		{
			g_size[i][j] = '0';
			refresh << g_size[i][j];
		}
		refresh << endl;
	}
	refresh.close();
}

// saving the edited txt file
void save() 
{
	ofstream save;
	if (c1 = true)
	{
		save.open("custom1.txt");
		for(size_t i = 0; i < g_size.size()-1; ++i)
		{
			for(size_t j = 0; j < g_size[i].size(); ++j)
			{
				save << g_size[i][j];
			}
			save << endl;
		}
	}
	else if (c2 = true)
	{
		save.open("custom2.txt");
		for(size_t i = 0; i < g_size.size()-1; ++i)
		{
			for(size_t j = 0; j < g_size[i].size(); ++j)
			{
				save << g_size[i][j];
			}
			save << endl;
		}
	}
	else if (c3 = true)
	{
		save.open("custom3.txt");
		for(size_t i = 0; i < g_size.size()-1; ++i)
		{
			for(size_t j = 0; j < g_size[i].size(); ++j)
			{
				save << g_size[i][j];
			}
			save << endl;
		}
	}
	save.close();
}

// movement for custom map
 void custommovement()
{
	if(g_playing == true)
	{
		g_switch = true;
	}

	int ch = _getch();
	switch (ch)
	{
	case 72:
		if(g_player.Y-1 >= 0)
		{
			if(g_switch == true)
			{
				detect(g_player.Y-1,g_player.X); // going up in normal mode
			}
			else
			{
				g_player.Y--; // going up in custom mode
			}
		}
		break;
	case 80:
		if(g_player.Y+1 < 22)
		{
			if(g_switch == true)
			{
				detect(g_player.Y+1,g_player.X); // going down in normal mode
			}
			else
			{
				g_player.Y++; // going down in custom mode
			}
		} 
		break; 
	case 77:
		if(g_player.X+1 < 49)
		{
			if(g_switch == true)
			{
				detect(g_player.Y,g_player.X+1); // going right in normal mode
			}
			else
			{
				g_player.X++; // going right in custom mode
			}
		}
		break;
	case 75:
		if(g_player.X-1 >= 0)
		{
			if(g_switch == true)
			{
				detect(g_player.Y,g_player.X-1); // going left in normal mode
			}
			else
			{
				g_player.X--; // going left in custom mode
			}
		}
		break;
	case 27:
		g_quit = true;
		break;
	case 'q':
	case 'Q':
		if (g_switch != true)
		{
			g_size[g_player.Y][g_player.X] = '0'; // deleting
		}
		break;
	case 'e':
	case 'E':
		if (g_switch != true)
		{
			g_size[g_player.Y][g_player.X] = '1'; // placing down walls
		}
		break;
	case 'r':
	case 'R':
		if (g_switch != true)
		{
			g_size[g_player.Y][g_player.X] = '2'; // placing down doors
		}
		break;
	case 'f':
	case 'F':
		if (g_switch != true)
		{
			g_size[g_player.Y][g_player.X] = '!'; // placing down keys for doors
		}
		break;
	case 't':
	case 'T':
		if (g_switch != true)
		{
			g_size[g_player.Y][g_player.X] = '3'; // placing down gates
		}
		break;
	case 'g':
	case 'G':
		if (g_switch != true)
		{
			g_size[g_player.Y][g_player.X] = '$'; // placing down keys for gates
		}
		break;
	case 'c':
	case 'C':
		if (g_switch != true)
		{
			g_size[g_player.Y][g_player.X] = 'x'; // placing down traps
		}
		break;
		
	case 'w':
	case 'W':
		if (g_switch != true)
		{
			g_size[g_player.Y][g_player.X] = '^'; // summoning FOE facing north
		}
		break;
	case 'a':
	case 'A':
		if (g_switch != true)
		{
			g_size[g_player.Y][g_player.X] = '<'; // summoning FOE facing west
		}
		break;
	case 's':
	case 'S':
		if (g_switch != true)
		{
			g_size[g_player.Y][g_player.X] = 'v'; // summoning FOE facing south
		}
		break;
	case 'd':
	case 'D':
		if (g_switch != true)
		{
			g_size[g_player.Y][g_player.X] = '>'; // summoning FOE facing east
		}
		break;
	case 'v':
	case 'V':
		if (g_switch != true)
		{
			g_size[g_player.Y][g_player.X] = 'M'; // placing down mud
		}
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
		if (g_playing == false && g_switch == false)
		{
			g_switch = true;
		}
		else if (g_playing == false && g_switch == true)
		{
			g_switch = false;
		}
		break;
	}
}

void customUI()
{
	setcolor(0x2F);
	gotoXY(52, 1);
	cout << "Use WASD to summon AOE";
	gotoXY(52, 3);
	cout << "Press E for walls";
	gotoXY(52, 4);
	cout << "Press R for doors";
	gotoXY(52, 5);
	cout << "Press F for keys (doors)";
	gotoXY(52, 6);
	cout << "Press T for gates";
	gotoXY(52, 7);
	cout << "Press G for keys (gates)";
	gotoXY(52, 8);
	cout << "Press C for traps";
	gotoXY(52, 9);
	cout << "Press V for mud";
	gotoXY(52, 11);
	cout << "Press Q to delete blocks";
	gotoXY(52, 12);
	cout << "Press N to refresh the map";
	gotoXY(52, 13);
	cout << "Press B to save map";
	gotoXY(52, 14);
	cout << "Press Z to switch modes";
	gotoXY(52, 16);
	cout << "Press Esc to exit";
	gotoXY(52, 18);
	if (g_switch == false)
	{
		cout << "Custom mode";
	}
	else if (g_switch == true)
	{
		cout << "Normal mode";
	}
	gotoXY(52, 20);
	cout << "Note: Normal mode makes";
	gotoXY(52, 21);
	cout << "use of normal controls.";
	setcolor(7);
	gotoXY(0,24);
}