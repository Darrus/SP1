#include "header.h"
#include "functions.h"

#define PERR(bSuccess, api) { if(!(bSuccess)) printf("%s:Error %d from %s \
    on line %d\n", __FILE__, GetLastError(), api, __LINE__); }

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

void setConsoleSize(unsigned short ushX, unsigned short ushY)
{
    SMALL_RECT windowSize = {0, 0, ushX, ushY};

    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    bool bSuccess = SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
	PERR( bSuccess, "SetConsoleWindowInfo" );
}