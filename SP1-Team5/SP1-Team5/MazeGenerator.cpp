#include "MazeGenerator.h"
#include "header.h"
#include "functions.h"
#include "player.h"

char wall = 219;
char door = 254;
int h = 0;

COORD cursor;
int play = 0;

void UI()
{
	gotoXY(52,4);
	setcolor(0x2F);
	cout << "Use the arrow keys to move";
	gotoXY(54,5);
	cout << "Find the key to ";
	gotoXY(54,6);
	cout << "unlock the door!";
	gotoXY(54, 8);
	setcolor(0x02);
	cout << "Player = Green " << (char)1  << endl;
	gotoXY(54, 9);
	setcolor(0x0C);
	cout << "FOE = Red ^v<>" << endl;
	gotoXY(54, 10);
	setcolor(0x0C);
	cout << "Unstable Floors = Red 0" << endl;
	gotoXY(54, 11);
	setcolor(0x0C);
	cout << "Broken Floors = Red O" << endl;
	gotoXY(54, 12);
	setcolor(0x0E);
	cout << "Keys = Yellow *" << endl;
	gotoXY(54, 13);
	setcolor(0x0F);
	cout << "Door = White " << door << endl;
	setcolor(7);
	gotoXY(0,24); 
}

void mazestore(string map)
{
	ifstream fin;
	fin.open(map,ios::in);
	while(!fin.eof())
	{	
		fin.getline(g_size[h],60);
		++h;
	}
}

void mazemapping()
{
	gotoXY(0,0);
	int a = 0;
	int b = 5;
	for(int a = 0; a < h; ++a)
	{
		for(int b = 0; b < 60; ++b)
		{
			switch(g_size[a][b])
			{
				case '0':cout << " "; 
					break;
				case '1':setcolor(0x0f);cout << wall;setcolor(7);
					break;
				case '2':setcolor(0x0f);cout << door;setcolor(7);
					break;
				case 'x': cout << '0';
					break;
				case '3': cout << 'O';
					break;
				case '!':setcolor(14);cout << "*";setcolor(7);
					break;
				case 'H':setcolor(12);cout << "H";setcolor(7); 
					break;
				case 'V':setcolor(12);cout << "V";setcolor(7);
					break;
				case 'O':setcolor(12);cout << "O";setcolor(7);
					break;
				case 'S':
					{
						cout << ' ';
						g_size[a][b] = '0';
						if(play == 0)
						{
							g_player.X = b;
							g_player.Y = a;
							play++;
						}
					}
					break;
				case '?':cout << "?";
					break;
				case '\n':cout << endl;
					break;
			}	
		}
		cout << endl;
	}
	player();
}