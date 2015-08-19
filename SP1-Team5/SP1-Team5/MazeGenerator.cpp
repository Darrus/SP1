#include "MazeGenerator.h"
#include "header.h"
#include "functions.h"
#include "player.h"

char size[25][60];
char wall = 219;
char door = 254;

COORD cursor;
int play = 0;

void UI()
{
	gotoXY(54, 5);
	setcolor(0x02);
	cout << "Player = Green " << (char)1  << endl;
	gotoXY(54, 6);
	setcolor(0x0C);
	cout << "FOE = Red ^v<>" << endl;
	gotoXY(54, 7);
	setcolor(0x0C);
	cout << "Unstable Floors = Red 0" << endl;
	gotoXY(54, 8);
	setcolor(0x0C);
	cout << "Broken Floors = Red O" << endl;
	gotoXY(54, 9);
	setcolor(0x0E);
	cout << "Keys = Yellow *" << endl;
	gotoXY(54, 10);
	setcolor(0x0f);
	cout << "Walls = White " << wall << endl;
	gotoXY(54, 11);
	cout << "Door = White " << door << endl;
	setcolor(7);
}

void maze(string map)
{
	int a = 0;
	int h = 0;
	gotoXY(0,0);
	ifstream fin;
	fin.open(map,ios::in);
	while(!fin.eof())
	{	
		fin.getline(size[h],60);
		for(a = 0;size[h][a] != '\0'; ++a)
		{
			mazemapping(h,a);
		}
		cout << endl;
		++h;
	}
	cout << endl;
}

void mazemapping(int Height,int Length)
{
	int h = Height;
	int a = Length;
	switch(size[h][a])
	{
		case '0':cout << " "; 
			break;
		case '1':setcolor(0x0f);cout << wall;setcolor(7);
			break;
		case '2':setcolor(0x0f);cout << door;setcolor(7);
			break;
		case 'x': cout << "O";size[h][a] = '0';
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
			size[h][a] = '0';
			if(play == 0)
			{
				cursor.X = a;
				cursor.Y = h;
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