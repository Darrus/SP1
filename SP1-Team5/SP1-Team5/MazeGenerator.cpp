#include "MazeGenerator.h"
#include "header.h"
#include "functions.h"
#include "player.h"
#include "FOE_Movement.h"
#include "sounds.h"

/**
*	Goh Zhen Yuan & Chuan Guang Zhe & Lee Yu Xian
*	This .cpp contains function:
*	UI() 18/8/2015 Lee Yu Xian
	Prints out the User Interface for the game.

*	mazestore(string map) 18/8/2015 Chuan Guang Zhe
	Gets the .txt file and store into a g_size.

*	mazemapping() 21/8/2015 Goh Zheng Yuan
	Converts each character in g_size so that it will cout the map on the screen.
*/

//Declarations of variables
extern bool g_key;
extern bool g_key1;
extern COORD g_player;
extern bool g_quit;
extern bool g_playing;

char wall = 219; //ASCII value for wall
char door = 254; //ASCII value for door
bool g_once = false; //Check if the map is generated for the first time
vector <string> g_size; //Array for storing the map
count counter; //Counter to count how many horizontal,vertical and orbiting FOE

//To store each FOE current location and which direction it is facing
vector <pos> hori; //Horizontal
vector <pos> vert; //Vertical
vector <pos> roun; //Orbit or Round

pos holder; //A temporary holder to hold the positions of the FOE so that it is able to push into it's proper vector.

//Prints out the UI on the right
void UI()
{
	//Hard-coded every thing on the UI
	setcolor(0x2F);
	gotoXY(54, 1);
	cout << "Find the key to ";
	gotoXY(54, 2);
	cout << "unlock the door!";
	gotoXY(52, 4);
	cout << "-Use the arrow keys to move";
	gotoXY(52, 5);
	cout << "-Press R to reset";
	gotoXY(52, 6);
	cout << "-Press Esc to exit";
	gotoXY(54, 8);
	setcolor(0x0A);
	cout << "Player = Green " << (char)1  << endl;
	gotoXY(54, 9);
	setcolor(0x0C);
	cout << "FOE = Red ^v<>" << endl;
	gotoXY(54, 10);
	cout << "Obiting FOE = Red @" << endl;
	gotoXY(54, 11);
	setcolor(0x07);
	cout << "Unstable Floors = Red O" << endl;
	gotoXY(54, 12);
	cout << "Broken Floors = Red X" << endl;
	gotoXY(54, 13);
	setcolor(0x0E);
	cout << "Keys (door) = Yellow *" << endl;
	gotoXY(54, 14);
	cout << "Door = Yellow " << door << endl;
	gotoXY(54, 15);
	setcolor(0x0B);
	cout << "Keys (gate) = Aqua *" << endl;
	gotoXY(54, 16);
	cout << "Gate = Aqua " << door << endl;
	setcolor(7);
	gotoXY(0,23);
}

//Converts the text map into a string
void mazestore(string map)
{
	//Resets everything
	h = 0;
	g_once = false;
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
				case '0': //Empty space
					cout << " "; 
					break;
				case '1': //Wall
					setcolor(0x0f);cout << wall;setcolor(7);
					break;
				case '2': //Door
					//Opens the door if the player have a key
					if(g_key == true)
					{
						g_size[a][b] = '4';
						cout << ' ';
					}
					else
					{
						setcolor(14);
						cout << door;
						setcolor(7);
					}
					break;
				
				case '3': //Gate
					//Opens the gate if the player have a key
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
				case 'x': //Unstable floor
					cout << 'O';
					break;
				case 'X': //Broken floor
					cout << 'X';
					break;
				case '#': //Wall for orbiting FOE to orbit around
					setcolor(0x0f);
					cout << wall;
					setcolor(7);
					break;
				case '4': //Exit
					cout << "!";
					break;
				case 'M': //Muddy Floor
					setcolor(4);
					cout << wall;
					setcolor(7);
					break;
		
				case '!': //Key
					setcolor(14);cout << "*";setcolor(7);
					break;
				
				case '$': //Key for gate
					setcolor(0xB);cout << "*";setcolor(7);
					break;
				case '@': //Orbiting FOE
					//If the map is being loaded the first time, to store positions of FOE
					if(g_once == false)
					{
						holder.X = b;
						holder.Y = a;
						roun.push_back(holder);
						counter.O++;
					}
					setcolor(12);
					cout << '@';
					setcolor(7);
					//Checks if the FOE is beside the player
					if((a == g_player.Y && b+1 == g_player.X) || (a == g_player.Y && b-1 == g_player.X) || (a-1 == g_player.Y && b == g_player.X) || (a+1 == g_player.Y && b == g_player.X) || (a == g_player.Y  && b == g_player.X) )
					{
						//Check if the player is currently playing
						if (g_playing == true)
						{
							death();
							g_quit = true;
						}
					}
					break;
				case 'S': //Player Spawn
					//Check if the game is currently playing or not
					if (g_playing == false)
					{
						setcolor(0x0A);
						cout << 'S';
						g_size[a][b] = 'S';
					}
					else
					{
						cout << ' ';
						g_size[a][b] = '0';
						if(g_once == false)
						{
							g_player.X = b;
							g_player.Y = a;
						}
					}
					break;
				case '>': //FOE right movement
					//If the map is being loaded the first time, to store positions of FOE
					if(g_once == false)
					{
						holder.X = b;
						holder.Y = a;
						hori.push_back(holder);
						counter.H++;
					}
					setcolor(12);
					cout << '>';
					setcolor(7);
					//Checks if the player is in front of the FOE
					if((a == g_player.Y && b+1 == g_player.X) || (a == g_player.Y  && b == g_player.X))
					{
						//Check if the player is currently playing
						if(g_playing == true)
						{
							death();
							g_quit = true;
						}
					}
					break;
				case '<': //FOE left movement
					//If the map is being loaded the first time, to store positions of FOE
					if(g_once == false)
					{
						holder.X = b;
						holder.Y = a;
						hori.push_back(holder);
						counter.H++;
					}
					setcolor(12);
					cout << '<';
					setcolor(7);
					//Checks if the player is in front of the FOE
					if((a == g_player.Y && b-1 == g_player.X) || (a == g_player.Y  && b == g_player.X))
					{
						//Check if the player is currently playing
						if(g_playing == true)
						{
							death();
							g_quit = true;
						}
					}
					break;
				case '^': //FOE upwards movement
					//If the map is being loaded the first time, to store positions of FOE
					if(g_once == false)
					{
						holder.X = b;
						holder.Y = a;
						vert.push_back(holder);
						counter.V++;
					}
					setcolor(12);
					cout << '^';
					setcolor(7);
					//Checks if the player is in front of the FOE
					if((a-1 == g_player.Y && b == g_player.X) || (a == g_player.Y  && b == g_player.X))
					{
						//Check if the player is currently playing
						if(g_playing == true)
						{
							death();
							g_quit = true;
						}
					}
					break;
				case 'v': //FOE downwards movement
					//If the map is being loaded the first time, to store positions of FOE
					if(g_once == false)
					{
						holder.X = b;
						holder.Y = a;
						vert.push_back(holder);
						counter.V++;
					}
					setcolor(12);
					cout << 'v';
					setcolor(7);
					//Checks if the player is in front of the FOE
					if((a+1 == g_player.Y && b == g_player.X) || (a == g_player.Y  && b == g_player.X))
					{
						//Check if the player is currently playing
						if(g_playing == true)
						{
							death();
							g_quit = true;
						}
					}
					break;
				case '?': //A invisible wall that the FOE is unable to pass through but players are able to
					if (g_playing == false)
					{
						cout << '?';
						g_size[a][b] = '?';
					}
					else
					{
						cout << " ";
					}
					break;
				case '\n': cout << endl;
					break;
			}	
		}
		cout << endl;
	}
	gotoXY(0,23);
	g_once = true; //Map has been run once, set to true
	player(); //Prints out player positions
}