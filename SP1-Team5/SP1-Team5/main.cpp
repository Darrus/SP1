#include "header.h"
#include "MazeGenerator.h"
#include "main.h"
#include "functions.h"
#include "player.h"

string m1 = "m1OriginalCreation.txt";
string m2 = "m2ModifiedWintermaulMaze.txt";
bool g_quit = false;
COORD g_player;
char g_size[25][60];

void main()
{
	level1();
	cout << "A" << endl;
}

void level1()
{
	mazestore(m2);
	while(!g_quit)
	{
		mazemapping();
		UI();
		movement();
	}
}

void level2()
{

}