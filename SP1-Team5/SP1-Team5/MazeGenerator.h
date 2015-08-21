#ifndef MAZEGENERATOR_H
#define MAZEGENERATOR_H
#include "header.h"

void mazestore(string map);
void mazemapping();
void UI();

struct pos
{
	int X;
	int Y;
	bool right;
	bool left;
	bool down;
	bool up;
};

struct count
{
	int H;
	int V;
	int O;
};

#endif