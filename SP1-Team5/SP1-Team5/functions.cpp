#include "header.h"
#include "functions.h"
#include <Windows.h>

/**
*	By Lee Yu Xian
*	This .cpp contains function:
*	gotoXY(COORD c) 
	From the SP framework, relocates cursor to desired location.

*	gotoXY(int x, int y)
	From the SP framework, relocates cursor to desired location.
	
*	setcolor(unsigned short color)
	From the SP framework, sets color.

*	cls()
	From the SP framework, refreshes the screen.

*/

void gotoXY(COORD c)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void gotoXY(int x, int y) {
	COORD c = {x,y};
	gotoXY(c);
}

void setcolor(unsigned short color)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon,color);
}

void cls(void)
{
	//Fills the entire screen with blank spaces, effectively clearing the screen
	gotoXY(0,0);
	cout << string(3000,' ');
	gotoXY(0,0);
}