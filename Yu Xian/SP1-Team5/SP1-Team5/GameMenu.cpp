#include "header.h"
#include "game.h"
#include "GameMenu.h"
#include "functions.h"
#include "sounds.h"

state choice = Play;
level number = One;
bool g_playing = false;
customenum no = Save1;

void gamemenu(void)
{
	//Construct the title screen
	title();
	menu();
	//Using enum with switch case, allows players to choose game modes.
	input(choice);
	menuselect();
	switch (choice)
	{
		case Play:
			//Switches menu to level select if players chose to play the game
			play();
			break;
		case Create:
			cls();
			custom();
			break;
		case Quit:
			choice = MAX;
			quit();
			break;
		default:
			//If players entered a non specified number, the program will end
			error();
			choice = MAX;
			break;
	}
}

//Prints out the title of the game
void title(void)
{
	//Hard-coded to print the game title
	setcolor(0xE);
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
	setcolor(7);
}

//Prints out the main menu options
void menu(void)
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
void play(void)
{
	g_playing = true;
	cls();
	title();
	levelmenu();
	//Using enum with switch case, allows players to select levels.
	levelselect(number);
	menuselect();
	while(g_playing == true)
	{
		switch (number)
		{
			case One:
			case Two:
			case Three:
				cls();
				levelselect(number);
				break;
			case Custom:
				cls();
				custom();
				break;
			case Back:
				cls();
				back();
				g_playing = false;
				gamemenu();
				break;
			default:
				play();
				error();
				break;
		}
	}
}

//Gets input from user for main menu options
void input(state & s)
{
	//Converts input to enum state
	int num = 0;
	cout << "Please enter your choice (1, 2 or 3 ONLY): ";
	cin >> num;
	s = static_cast<state>(num);
}

//Prints out the level select menu
void levelmenu(void)
{
	//Hard-coded to print level select options, the numbers corresponds to the functionality
	cout << "LEVEL SELECT";
	gotoXY(10,9);
	cout << "[1] Level 1";
	gotoXY(10,10);
	cout << "[2] Level 2";
	gotoXY(10,11);
	cout << "[3] Level 3";
	gotoXY(10,12);
	cout << "[4] Custom Level";
	gotoXY(10,13);
	cout << "[0] Back";
	gotoXY(10,14);
}

//Gets input from user for level select
void levelselect(level& l)
{
	//Converts input to enum state
	int n = 0;
	cout << "Please enter your choice (0, 1, 2, 3 or 4 ONLY): ";
	cin >> n;
	l = static_cast<level>(n);
}

//Prints out an error message for main menu
void error(void)
{
	//Hard-coded to print out the error message right under the input
	gotoXY(10,15);
	cout << "Error! Seems like you did not follow the instruction.";
	gotoXY(10,16);
	cout << "The game will now close!";
	gotoXY(10,17);
	errorsound();
}

//Prints out a message when player quits the game
void quit(void)
{
	//Hard-coded to print out the message when players quit the game
	gotoXY(10,13);
	cout <<"Thanks for playing the game!";
	gotoXY(10,14);
}

void custom(void)
{
	cls();
	title();
	custommenu();
	customselect(no);
	menuselect();
	switch (no)
	{
	case Save1:
	case Save2:
	case Save3:
		cls();
		customlevel(no);
	case Back1:
		cls();
		g_playing = false;
		gamemenu();
		break;
	default:
		error();
		no = END;
		break;
	}
}

void custommenu(void)
{
	cout << "SAVE SELECT";
	gotoXY(10,9);
	cout << "[1] Save 1";
	gotoXY(10,10);
	cout << "[2] Save 2";
	gotoXY(10,11);
	cout << "[3] Save 3";
	gotoXY(10,12);
	cout << "[0] Back";
	gotoXY(10,13);
}

void customselect (customenum& i)
{
	// converting
	int j = 0;
	cout << "Which save do you want? (0, 1, 2 or 3 ONLY): ";
	cin >> j;
	i = static_cast<customenum>(j);
}