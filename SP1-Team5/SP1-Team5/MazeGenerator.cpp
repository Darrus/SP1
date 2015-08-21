#include "MazeGenerator.h"
#include "header.h"
#include "functions.h"
#include "player.h"
#include "FOE_Movement.h"

char wall = 219;
char door = 254;
int h = 0;
int play = 0;
int counter;
vector <string> g_size;

struct pos
{
	COORD hori;
	COORD vert;
	COORD roun;
};

vector <pos> enemy;

void UI()
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
	gotoXY(54, 14);
	setcolor(0x0F);
	cout << "Door = White " << door << endl;
	setcolor(7);
	gotoXY(0,24);
}

void mazestore(string map)
{
	h = 0;
	play = 0;
	g_size.clear(); 
	ifstream fin;
	string temp;
	fin.open(map,ios::in);
	while(!fin.eof())
	{	
		getline(fin,temp);
		g_size.push_back(temp);
		++h;
	}
	fin.close();
}

void mazemapping()
{
	gotoXY(0,0);
	int a = 0;
	int b = 5;
	counter = 0;
	for(size_t a = 0; a < g_size.size(); ++a)
	{
		for(size_t b = 0; b < g_size[a].length(); ++b)
		{
			if(g_size[a][b] == 'H')
			{
				counter++;
			}
			else if(g_size[a][b] == 'V')
			{
				counter++;
			}
			else if(g_size[a][b] == 'O')
			{
				counter++;
			}
			switch(g_size[a][b])
			{
				case '0':cout << " "; 
					break;
				case '1':setcolor(0x0f);cout << wall;setcolor(7);
					break;
				case '2':if(g_key == true)
						{
							g_size[a][b] = '4';
							cout << ' ';
						}
						else
						{
							setcolor(0x0f);cout << door;setcolor(7);
						}
					break;
				case 'x': cout << '0';
					break;
				case '3': cout << 'O';
					break;
				case '4': cout << "!";
					break;
				case '!':setcolor(14);cout << "*";setcolor(7);
					break;
				case 'H':setcolor(12);cout << counter;setcolor(7);
					break;
				case 'V':setcolor(12);cout << counter;setcolor(7);
					break;
				case 'O':setcolor(12);cout << counter;setcolor(7);
					break;
				case 'S':
						cout << ' ';
						g_size[a][b] = '0';
						if(play == 0)
						{
							g_player.X = b;
							g_player.Y = a;
							play++;
						}
					break;
				case '>': cout << '>';
					break;
				case '<': cout << '<';
						break;
				case '?':cout << "?";
					break;
				case '\n': cout << endl;
					break;
			}	
		}
		cout << endl;
	}
	player();
}