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

void placetrap (int Y, int X)
{
	g_size[Y][X] = 'x';
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
void refresh1()
{
	ofstream refresh;
	refresh.open("custom.txt");
	int i = 0;
	int j = 0;
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
	refresh << g_size[i] << endl;
	refresh.close();
}

// saving the edited txt file
void save1() 
{
	ofstream save;
	save.open("custom1.txt");
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

// refreshing the text file back to default (second custom)
void refresh2()
{
	ofstream refresh;
	refresh.open("custom2.txt");
	for (size_t i = 1; i < sizeof(col); ++i) 
	{
		col[i] = '0';
		refresh << col[i];
		for (size_t j = 1; j < sizeof(row); ++j)
		{
			row[j] = '0';
			refresh << row[j];
		}
		refresh << '1' << endl;
	}
	for (size_t line = 0; line <= sizeof(row); ++line)
	{
		refresh << '1';
	}
	refresh.close();
}

// saving the edited text file (second custom)
void save2() 
{
	ofstream save;
	save.open("custom2.txt");
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

// refreshing the text file back to default (third custom)
void refresh3()
{
	ofstream refresh;
	refresh.open("custom3.txt");
	for (size_t i = 1; i < sizeof(col); ++i) 
	{
		col[i] = '0';
		refresh << col[i];
		for (size_t j = 1; j < sizeof(row); ++j)
		{
			row[j] = '0';
			refresh << row[j];
		}
		refresh << '1' << endl;
	}
	for (size_t line = 0; line <= sizeof(row); ++line)
	{
		refresh << '1';
	}
	refresh.close();
}

// saving the edited text file (third custom)
void save3() 
{
	ofstream save;
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

// movement for custom map 1
void custommovement1()
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
				detect(g_player.Y-1,g_player.X);
			}
			else
			{
				g_player.Y--; // going up
			}
		}
		break;
	case 80:
		if(g_player.Y+1 < 22)
		{
			if(g_switch == true)
			{
				detect(g_player.Y+1,g_player.X);
			}
			else
			{
				g_player.Y++; // going down
			}
		} 
		break; 
	case 77:
		if(g_player.X+1 < 49)
		{
			if(g_switch == true)
			{
				detect(g_player.Y,g_player.X+1);
			}
			else
			{
				g_player.X++; // going right
			}
		}
		break;
	case 75:
		if(g_player.X-1 >= 0)
		{
			if(g_switch == true)
			{
				detect(g_player.Y,g_player.X-1);
			}
			else
			{
				g_player.X--; // going left
			}
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
		refresh1();
		break;
	case 'b':
	case 'B':
		save1();
		break;
	case 'z':
	case 'Z':
		if(g_playing == false && g_switch == false)
		{
			g_switch = true;
		}
		else if(g_playing == false && g_switch == true)
		{
			g_switch = false;
		}
		break;
		break;
	}
}

// movement for custom map 2
void custommovement2()
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
				detect(g_player.Y-1,g_player.X);
			}
			else
			{
				g_player.Y--; // going up
			}
		}
		break;
	case 80:
		if(g_player.Y+1 < 22)
		{
			if(g_switch == true)
			{
				detect(g_player.Y+1,g_player.X);
			}
			else
			{
				g_player.Y++; // going down
			}
		} 
		break; 
	case 77:
		if(g_player.X+1 < 49)
		{
			if(g_switch == true)
			{
				detect(g_player.Y,g_player.X+1);
			}
			else
			{
				g_player.X++; // going right
			}
		}
		break;
	case 75:
		if(g_player.X-1 >= 0)
		{
			if(g_switch == true)
			{
				detect(g_player.Y,g_player.X-1);
			}
			else
			{
				g_player.X--; // going left
			}
		}
		break;
	case 27:
		g_quit = true;
		break;
	case 'q':
	case 'Q':
		delplace(g_player.Y, g_player.X); // deleting the block on the player
		break;
	case 'W':
	case 'w':
		placewall(g_player.Y, g_player.X); // placing a wall on the player's location
		break;
	case 'd':
	case 'D':
		placedoor(g_player.Y, g_player.X); // placing a door on the player's location
		break;
	case 'E':
	case 'e':
		placekey(g_player.Y, g_player.X); // placing a key on the player's location
		break;
	case 'r':
	case 'R':
		placetrap(g_player.Y, g_player.X); // placing a trap on the player's location
	case 'N':
	case 'n':
		refresh2(); // refreshing the map back to default
		break;
	case 'b':
	case 'B':
		save2(); // saving the customised map
		break;
	case 'z':
	case 'Z':
		// switch between customising and normal mode
		if(g_playing == false && g_switch == false)
		{
			g_switch = true;
		}
		else if(g_playing == false && g_switch == true)
		{
			g_switch = false;
		}
		break;
	}
}

// movement for custom map 3
void custommovement3()
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
				detect(g_player.Y-1,g_player.X);
			}
			else
			{
				g_player.Y--; // going up
			}
		}
		break;
	case 80:
		if(g_player.Y+1 < 22)
		{
			if(g_switch == true)
			{
				detect(g_player.Y+1,g_player.X);
			}
			else
			{
				g_player.Y++; // going down
			}
		} 
		break; 
	case 77:
		if(g_player.X+1 < 49)
		{
			if(g_switch == true)
			{
				detect(g_player.Y,g_player.X+1);
			}
			else
			{
				g_player.X++; // going right
			}
		}
		break;
	case 75:
		if(g_player.X-1 >= 0)
		{
			if(g_switch == true)
			{
				detect(g_player.Y,g_player.X-1);
			}
			else
			{
				g_player.X--; // going left
			}
		}
		break;
	case 27:
		g_quit = true;
		break;
	case 'q':
	case 'Q':
		delplace(g_player.Y, g_player.X); // deleting the block on the player
		break;
	case 'W':
	case 'w':
		placewall(g_player.Y, g_player.X); // placing a wall on the player's location
		break;
	case 'd':
	case 'D':
		placedoor(g_player.Y, g_player.X); // placing a door on the player's location
		break;
	case 'E':
	case 'e':
		placekey(g_player.Y, g_player.X); // placing a key on the player's location
		break;
	case 'r':
	case 'R':
		placetrap(g_player.Y, g_player.X); // placing a trap on the player's location
	case 'N':
	case 'n':
		refresh3(); // refreshing the map back to default
		break;
	case 'b':
	case 'B':
		save3(); // saving the customised map
		break;
	case 'z':
	case 'Z':
		// switch between customising and normal mode
		if(g_playing == false && g_switch == false)
		{
			g_switch = true;
		}
		else if(g_playing == false && g_switch == true)
		{
			g_switch = false;
		}
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
	gotoXY(52,8);
	cout << "Press Z to switch modes";
	gotoXY(52, 10);
	cout << "Press Esc to exit";
	gotoXY(52, 12);
	cout << "Custom mode";
	gotoXY(52, 14);
	cout << "Note: Normal mode makes";
	gotoXY(52, 15);
	cout << "use of normal controls.";
	setcolor(7);
	gotoXY(0,24);
}

void customUI1()
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
	gotoXY(52,8);
	cout << "Press Z to switch modes";
	gotoXY(52, 10);
	cout << "Press Esc to exit"  << endl;
	gotoXY(52, 12);
	cout << "Normal mode"  << endl;
	setcolor(7);
	gotoXY(0,24);
}