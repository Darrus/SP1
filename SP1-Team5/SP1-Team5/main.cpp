#include "GameMenu.h"
#include <Windows.h>
#include "functions.h"

//Links everything together and runs the game
void main(void)
{
	//Console title : aMAZE
	SetConsoleTitle(L"aMAZE");

	//Set console size
	HWND wh = GetConsoleWindow();
	MoveWindow(wh, 450, 250, 1000, 450, TRUE);

	gamemenu();
}

