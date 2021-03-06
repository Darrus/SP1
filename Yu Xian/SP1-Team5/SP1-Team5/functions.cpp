#include "header.h"
#include "functions.h"

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

void setConsoleSize(unsigned short ushX, unsigned short ushY)
{
    SMALL_RECT windowSize = {0, 0, ushX, ushY};
}