#include "MazeGenerator.h"
#include "header.h"
#include "functions.h"
#include "player.h"
#include "FOE_Movement.h"
#include "sounds.h"

//Declarations of variables
extern bool g_key;
extern bool g_key1;
extern COORD g_player;
extern bool g_quit;
extern bool g_playing;

char wall = 219;
char door = 254;
int h = 0;
bool play = false;

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
	//Resets everything
	h = 0;
	play = false;
	hori.clear();
	vert.clear();
	roun.clear();
	counter.H = 0;
	counter.V = 0;
	counter.O = 0;
	g_size.clear(); 

	//Gets the text map
	ifstream fin;
	string temp;
	fin.open(map,ios::in);
	while(!fin.eof())
	{
		getline(fin,temp);
		//Store into string
		g_size.push_back(temp);
		++h;
	}
	fin.close();
}

//Generates the map based on text map
void mazemapping()
{
	//Resets point to 0,0
	gotoXY(0,0);
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
							setcolor(0x0E);
							cout << door;
							setcolor(7);
						}
					break;
				// gate
				case '3':
					if (g_key1 == true)
					{
						g_size[a][b] = '0';
						cout << ' ';
					}
					else
					{
						setcolor (0x0B);
						cout << door;
						setcolor(7);
					}
					break;
				//Broken Floor system
				case 'x': cout << 'O';
					break;
				case 'X': cout << 'X';
					break;
				case '#':
					setcolor(0x0f);
					cout << wall;
					setcolor(7);
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
				// key 2
				case '$':setcolor(0xB);cout << "*";setcolor(7);
					break;
				case '@':
					if(play == false)
					{
						holder.X = b;
						holder.Y = a;
						roun.push_back(holder);
						counter.O++;
					}
					setcolor(12);
					cout << '@';
					setcolor(7);
					break;
				//Player spawn
				case 'S':
						cout << ' ';
						g_size[a][b] = '0';
						if(play == false)
						{
							g_player.X = b;
							g_player.Y = a;
						}
					break;
				//FOE right movement
				case '>': 
					if(play == false)
					{
						holder.X = b;
						holder.Y = a;
						hori.push_back(holder);
						counter.H++;
					}
					setcolor(12);
					cout << '>';
					setcolor(7);
					if((a == g_player.Y && b+1 == g_player.X) || (a == g_player.Y  && b == g_player.X))
					{
						if (g_playing == true)
						{
							g_quit = true;
						}
					}
					break;
				//FOE left movement
				case '<': 
					if(play == false)
					{
						holder.X = b;
						holder.Y = a;
						hori.push_back(holder);
						counter.H++;
					}
					setcolor(12);
					cout << '<';
					setcolor(7);
					if((a == g_player.Y && b-1 == g_player.X) || (a == g_player.Y  && b == g_player.X))
					{
						if (g_playing == true)
						{
							g_quit = true;
						}
					}
					break;
				//FOE upwards movement
				case '^':
					if(play == false)
					{
						holder.X = b;
						holder.Y = a;
						vert.push_back(holder);
						counter.V++;
					}
					setcolor(12);
					cout << '^';
					setcolor(7);
					if((a-1 == g_player.Y && b == g_player.X) || (a == g_player.Y  && b == g_player.X))
					{
						if (g_playing == true)
						{
							g_quit = true;
						}
					}
					break;
				//FOE downwards movement
				case 'v':
					if(play == false)
					{
						holder.X = b;
						holder.Y = a;
						vert.push_back(holder);
						counter.V++;
					}
					setcolor(12);
					cout << 'v';
					setcolor(7);
					if((a+1 == g_player.Y && b == g_player.X) || (a == g_player.Y  && b == g_player.X))
					{
						if (g_playing == true)
						{
							g_quit = true;
						}
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
	play = true;
	player();
}