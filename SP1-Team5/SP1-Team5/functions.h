#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void gotoXY(COORD c);
void gotoXY(int x, int y);
void setcolor(unsigned short color);

extern bool g_quit;
extern COORD g_player;
extern char g_size[25][60];
extern bool g_clear1;
extern bool g_reset;
extern bool g_key;


#endif