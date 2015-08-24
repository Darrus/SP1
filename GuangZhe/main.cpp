#include "main.h"
#include "header.h"
#include "game.h"
#include "functions.h"

void main()
{		
	title();
	menu();
	state choice = Play;
	level number = All;
	input(choice);
	switch (choice)
	{
		case Play:
			cls();
			title();
			levelmenu();
			levelselect(number);
			switch (number)
			{
				case All:
					cls();
					level1();
					level2();
					break;
				case lvl1:
					cls();
					level1();
					break;
				case lvl2:
					cls();
					level2();
					break;
				case clvl:
					cls();
					cout << "Errr waiting for custom map" << endl;
					break;
				default:
					lvlerror();
					choice = MAX;
					break;
			}
			break;
		case Create:
			cls();
			cout <<"ERROR WAITING FOR SHAWN TO COMPLETE HIS THINGY"<< endl;
			break;
		case Quit:
			choice = MAX;
			quit();
			break;
		default:
			error();
			choice = MAX;
	}
}

void title()
{
	gotoXY(10,0);
	cout << " ______     __    __     ______     ______     ______    ";
	gotoXY(10,1);
	cout << "/\\  __ \\   /\\ \\-./  \\   /\\  __ \\   /\\___  \\   /\\  ___\\   ";
	gotoXY(10,2);
	cout << "\\ \\  __ \\  \\ \\ \\-./\\ \\  \\ \\  __ \\  \\/_/  /__  \\ \\  __\\   ";
	gotoXY(10,3);
	cout << " \\ \\_\\ \\_\\  \\ \\_\\ \\ \\_\\  \\ \\_\\ \\_\\   /\\_____\\  \\ \\_____\\ ";
	gotoXY(10,4);
	cout << "  \\/_/\\/_/   \\/_/  \\/_/   \\/_/\\/_/   \\/_____/   \\/_____/ "; 
	gotoXY(10,8);
}

void menu()
{
	cout << "Please select a choice";
	gotoXY(10,9);
	cout << "[1] Start Game!";
	gotoXY(10,10);
	cout << "[2] Custom Maze Maker!";
	gotoXY(10,11);
	cout << "[3] Quit Game";
	gotoXY(10,12);
}

void input(state& s)
{
	int num = 0;
	cout << "Please enter your choice (1, 2 or 3 ONLY): ";
	cin >> num; 
	s = static_cast<state>(num);
}

void cls()
{
	gotoXY(0,0);
	cout << string(2000,' ');
	gotoXY(0,0);
}

void levelmenu()
{
	cout << "LEVEL SELECT";
	gotoXY(10,9);
	cout << "[0] All levels (1 and 2)";
	gotoXY(10,10);
	cout << "[1] Level 1";
	gotoXY(10,11);
	cout << "[2] Level 2";
	gotoXY(10,12);
	cout << "[3] Custom Level";
	gotoXY(10,13);
}

void levelselect(level& l)
{
	int n = 0;
	cout << "Please enter your choice (0, 1, 2 or 3 ONLY): ";
	cin >> n;
	l = static_cast<level>(n);
}

void error()
{
	gotoXY(10,13);
	cout << "Oops! Seems like you did not follow the instruction.";
	gotoXY(10,14);
	cout << "The game will now close!";
	gotoXY(10,15);
}

void lvlerror()
{
	gotoXY(10,14);
	cout << "Oops! Seems like you did not follow the instruction.";
	gotoXY(10,15);
	cout << "The game will now close!";
	gotoXY(10,16);
}

void quit()
{
	gotoXY(10,13);
	cout <<"Thanks for playing the game!";
	gotoXY(10,14);
}

