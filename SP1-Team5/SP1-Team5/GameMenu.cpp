#include "header.h"
#include "game.h"
#include "GameMenu.h"
#include "functions.h"

state choice = Play;
level number = One;

void gamemenu()
{
	//Construct the title screen
	title();
	menu();
	//Using enum with switch case, allows players to choose game modes.
	input(choice);
	switch (choice)
	{
		case Play:
			//Switches menu to level select if players chose to play the game
			play();
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
			//If players entered a non specified number, the program will end
			error();
			choice = MAX;
	}
}

//Prints out the title of the game
void title()
{
	//Hard-coded to print the game title
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

//Prints out the main menu options
void menu()
{
	//Hard-coded to print main menu options, the numbers corresponds to the functionality
	cout << "Please select a choice";
	gotoXY(10,9);
	cout << "[1] Start Game!";
	gotoXY(10,10);
	cout << "[2] Custom Maze Maker!";
	gotoXY(10,11);
	cout << "[3] Quit Game";
	gotoXY(10,12);
}

//Function for case Play
void play()
{
	cls();
	title();
	levelmenu();
	//Using enum with switch case, allows players to select levels.
	levelselect(number);
	switch (number)
	{
		case One:
			cls();
			level1();
			break;
		case Two:
			cls();
			level2();
			break;
		case Custom:
			cls();
			cout << "Errr waiting for custom map" << endl;
			break;
		default:
			error();
			choice = MAX;
			break;
	}
}

//Gets input from user for main menu options
void input(state& s)
{
	//Converts input to enum state
	int num = 0;
	cout << "Please enter your choice (1, 2 or 3 ONLY): ";
	cin >> num;
	s = static_cast<state>(num);
}

//Clears the screen 
void cls()
{
	//Fills the entire screen with blank spaces, effectively clearing the screen
	gotoXY(0,0);
	cout << string(2000,' ');
	gotoXY(0,0);
}

//Prints out the level select menu
void levelmenu()
{
	//Hard-coded to print level select options, the numbers corresponds to the functionality
	cout << "LEVEL SELECT";
	gotoXY(10,9);
	cout << "[1] Level 1";
	gotoXY(10,10);
	cout << "[2] Level 2";
	gotoXY(10,11);
	cout << "[3] Custom Level";
	gotoXY(10,12);
}

//Gets input from user for level select
void levelselect(level& l)
{
	//Converts input to enum state
	int n = 0;
	cout << "Please enter your choice (1, 2 or 3 ONLY): ";
	cin >> n;
	l = static_cast<level>(n);
}

//Prints out an error message for main menu
void error()
{
	//Hard-coded to print out the error message right under the input
	gotoXY(10,13);
	cout << "Oops! Seems like you did not follow the instruction.";
	gotoXY(10,14);
	cout << "The game will now close!";
	gotoXY(10,15);
}

//Prints out a message when player quits the game
void quit()
{
	//Hard-coded to print out the message when players quit the game
	gotoXY(10,13);
	cout <<"Thanks for playing the game!";
	gotoXY(10,14);
}