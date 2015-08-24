#ifndef PLAYER_H
#define PLAYER_H

void movement();
void player();
void detect(int Y,int X);
void place(int Y, int X);

extern bool g_key;
extern bool g_quit;
extern COORD g_player;

#endif