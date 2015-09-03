#include "GameMenu.h"
#include <Windows.h>
#include "functions.h"

//Links everything together and runs the game
void main(void)
{
	//Console title : aMAZE
	SetConsoleTitle(L"aMAZE");
	//Set console size
	setConsoleSize(80 , 123);
	gamemenu();
}

