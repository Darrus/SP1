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
void refresh(void)
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
void save(void) 
{
	ofstream save;
	if (c1 == true)
		save.open("custom1.txt");
	else if (c2 == true)
		save.open("custom2.txt");
	else if (c3 == true)
		save.open("custom3.txt");
	for(size_t i = 0; i < g_size.size()-1; ++i)
	{
		for(size_t j = 0; j < g_size[i].size(); ++j)
		{
			save << g_size[i][j];
		}
		save << endl;
	}
	save.close();
}

// movement for custom map
void custommovement(void)
{
	if(g_playing == true)
	{
		g_switch = true;
	}

	int ch = _getch(); // getting input from user and converting to int
	switch (ch)
	{
	case 72: // ascii code for up arrow key
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
	case 80: // ascii code for down arrow key
		if(g_player.Y+1 < 23)
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
	case 77: // ascii code for right arrow key
		if(g_player.X+1 < 50)
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
	case 75: // ascii code for left arrow key
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
	case 27: // ascii code for escape key
		g_quit = true;
		break;
	case 'q':
	case 'Q':
		if (g_switch != true)
		{
			g_size[g_player.Y][g_player.X] = '0'; // deleting
		}
		break;
	case 32:
		if (g_switch != true)
		{
			g_size[g_player.Y][g_player.X] = '1'; // placing down walls
		}
		break;
	case '4':
		if (g_switch != true)
		{
			g_size[g_player.Y][g_player.X] = '2'; // placing down doors
		}
		break;
	case '3':
		if (g_switch != true)
		{
			g_size[g_player.Y][g_player.X] = '!'; // placing down keys for doors
		}
		break;
	case '2':
		if (g_switch != true)
		{
			g_size[g_player.Y][g_player.X] = '3'; // placing down gates
		}
		break;
	case '1':
		if (g_switch != true)
		{
			g_size[g_player.Y][g_player.X] = '$'; // placing down keys for gates
		}
		break;
	case 'e':
	case 'E':
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
	case 'r':
	case 'R':
		if (g_switch != true)
		{
			g_size[g_player.Y][g_player.X] = 'M'; // placing down mud
		}
		break;
	case 'v':
	case 'V':
		if (g_switch != true)
		{
			g_size[g_player.Y][g_player.X] = 'S'; // setting starting point
		}
		break;
	case 'f':
	case 'F':
		if (g_switch != true)
		{
			g_size[g_player.Y][g_player.X] = '?'; // placing down invisiable wall (player can pass, FOE cannot)
		}
		break;
	case 'x':
	case 'X':
		if (g_switch != true)
		{
			g_size[g_player.Y][g_player.X] = '@'; // placing down obiting FOE
		}
		break;
	case 'c':
	case 'C':
		if (g_switch != true)
		{
			g_size[g_player.Y][g_player.X] = '#'; // placing down wall for obiting FOE to obit around
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
	default: 
		custommovement();
		break;
	}
}

void customUI(void)
{
	// hard coded UI as instructions for player
	setcolor(0x2F);
	gotoXY(51, 0);
	cout << "Use WASD to summon FOE";
	gotoXY(51, 2);
	cout << "Press space for walls";
	gotoXY(51, 3);
	cout << "Press 1 for key (gate)";
	gotoXY(51, 4);
	cout << "Press 2 for gate";
	gotoXY(51, 5);
	cout << "Press 3 for key (door)";
	gotoXY(51, 6);
	cout << "Press 4 for door";
	gotoXY(51, 7);
	cout << "Press E for traps";
	gotoXY(51, 8);
	cout << "Press R for mud";
	gotoXY(51, 9);
	cout << "Press F for invisiable wall";
	gotoXY(51, 10);
	cout << "(Player can pass, FOE can't)";
	gotoXY(51, 11);
	cout << "Press X for obiting FOE";
	gotoXY(51, 12);
	cout << "Press C for obiting FOE wall";
	gotoXY(51, 14);
	cout << "Press V to set start point";
	gotoXY(51, 15);
	cout << "Press Q to delete blocks";
	gotoXY(51, 16);
	cout << "Press N to refresh the map";
	gotoXY(51, 17);
	cout << "Press B to save map";
	gotoXY(51, 18);
	cout << "Press Z to switch modes";
	gotoXY(51, 20);
	cout << "Press Esc to exit";
	gotoXY(51, 22);
	if (g_switch == false)
	{
		cout << "Custom mode";
	}
	else if (g_switch == true)
	{
		cout << "Normal mode";
	}
	setcolor(7);
	gotoXY(0,24);
}