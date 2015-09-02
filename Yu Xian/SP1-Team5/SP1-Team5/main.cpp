#include "GameMenu.h"
#include <Windows.h>
#include "functions.h"

//Links everything together and runs the game
void main(void)
{
	SetConsoleTitle(L"aMAZE");
	setConsoleSize(79 , 25);
	gamemenu();
}

