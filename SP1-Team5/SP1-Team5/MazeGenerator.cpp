#include "MazeGenerator.h"
#include "header.h"
#include "functions.h"
#include "player.h"
#include "FOE_Movement.h"

//Declarations of variables
extern bool g_key;
extern COORD g_player;
extern bool g_quit;

char wall = 219;
char door = 254;
int h = 0;
int play = 0;

vector <string> g_size;

count counter;

vector <pos> hori;
vector <pos> vert;
vector <pos> roun;

pos holder;

//Prints out the UI on the right
void UI()
{
	//Hard-coded every thing on the UI
	setcolor(0x2F);
	gotoXY(54,2);
	cout << "Find the key to ";
	gotoXY(54,3);
	cout << "unlock the door!";
	gotoXY(52,5);
	cout << "-Use the arrow keys to move";
	gotoXY(52,6);
	cout << "-Press R to reset";
	gotoXY(52,7);
	cout << "-Press Esc to exit";
	gotoXY(54, 9);
	setcolor(0x0A);
	cout << "Player = Green " << (char)1  << endl;
	gotoXY(54, 10);
	setcolor(0x0C);
	cout << "FOE = Red ^v<>" << endl;
	gotoXY(54, 11);
	setcolor(0x0C);
	cout << "Unstable Floors = Red 0" << endl;
	gotoXY(54, 12);
	setcolor(0x0C);
	cout << "Broken Floors = Red O" << endl;
	gotoXY(54, 13);
	setcolor(0x0E);
	cout << "Keys = Yellow *" << endl;
	gotoXY(54, 14);
	setcolor(0x0F);
	cout << "Door = White " << door << endl;
	setcolor(7);
	gotoXY(0,23);
}

//Converts the text map into a string
void mazestore(string map)
{
	h = 0;
	play = 0;
	g_size.clear(); 
	ifstream fin;
	string temp;
	//Gets the text map
	fin.open(map,ios::in);
	while(!fin.eof())
	{
		getline(fin,temp);
		//Converts into string
		g_size.push_back(temp);
		++h;
	}
	fin.close();
}

//Generates the map based on text map
void mazemapping()
{
	//Declaration of variables
	gotoXY(0,0);
	int a = 0;
	int b = 5;
	counter.H = 0;
	counter.V = 0;
	//Reads the columns
	for(size_t a = 0; a < g_size.size(); ++a)
	{
		//Reads the rows
		for(size_t b = 0; b < g_size[a].length(); ++b)
		{
			//Switch case based on what is on the map
			switch(g_size[a][b])
			{
				//0 is converted into space
				case '0':cout << " "; 
					break;
				//1 is converted into walls
				case '1':setcolor(0x0f);cout << wall;setcolor(7);
					break;
				//2 is converted into door
				case '2':if(g_key == true)
						{
							//Opens the door if the player have a key
							g_size[a][b] = '4';
							cout << ' ';
						}
						else
						{
							setcolor(0x0f);cout << door;setcolor(7);
						}
					break;
				//Broken Floor system
				case 'x': cout << '0';
					break;
				case '3': cout << 'O';
					break;
				case '4': cout << "!";
					break;
				//Muddy Floor
				case 'M':
					setcolor(4);
					cout << wall;
					setcolor(7);
					break;
				//Key
				case '!':setcolor(14);cout << "*";setcolor(7);
					break;
				case 'O':
					//holder.X = b;
					//holder.Y = a;
					//roun.push_back(holder);
					//counter.O++;
					setcolor(12);
					cout << 'O';
					setcolor(7);
					break;
				//Player spawn
				case 'S':
						cout << ' ';
						g_size[a][b] = '0';
						if(play == 0)
						{
							g_player.X = b;
							g_player.Y = a;
							play++;
						}
					break;
				//FOE right movement
				case '>': 
					holder.X = b;
					holder.Y = a;
					hori.push_back(holder);
					counter.H++;
					setcolor(12);
					cout << '>';
					setcolor(7);
					if((a == g_player.Y && b+1 == g_player.X) || (a == g_player.Y  && b == g_player.X))
					{
						g_quit = true;
					}
					break;
				//FOE left movement
				case '<': 
					holder.X = b;
					holder.Y = a;
					hori.push_back(holder);
					counter.H++;
					setcolor(12);
					cout << '<';
					setcolor(7);
					if((a == g_player.Y && b-1 == g_player.X) || (a == g_player.Y  && b == g_player.X))
					{
						g_quit = true;
					}
					break;
				//FOE upwards movement
				case '^':
					holder.X = b;
					holder.Y = a;
					vert.push_back(holder);
					counter.V++;
					setcolor(12);
					cout << '^';
					setcolor(7);
					if((a-1 == g_player.Y && b == g_player.X) || (a == g_player.Y  && b == g_player.X))
					{
						g_quit = true;
					}
					break;
				//FOE downwards movement
				case 'v':
					holder.X = b;
					holder.Y = a;
					vert.push_back(holder);
					counter.V++;
					setcolor(12);
					cout << 'v';
					setcolor(7);
					if((a+1 == g_player.Y && b == g_player.X) || (a == g_player.Y  && b == g_player.X))
					{
						g_quit = true;
					}
					break;
				//Invisible wall for FOE
				case '?':cout << " ";
					break;
				case '\n': cout << endl;
					break;
			}	
		}
		cout << endl;
	}
	gotoXY(0,23);
	player();
}