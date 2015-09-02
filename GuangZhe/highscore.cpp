#include "header.h"
#include "clock.h"
#include "functions.h"
#include "highscore.h"
#include "game.h"
#include "sounds.h"

extern bool lvl1;
extern bool lvl2;
extern bool lvl3;
bool newscore = false;


//Stores highscore 
void store(int min, int sec)
{
	int highscore[4] = {0};
	char highscoreC[5] = {0};
	int i = 0;

	//convert time taken to your highscore
	if ( min < 10)
	{
		//If minute is only 1 digit
		*(highscore+1) = min;
	}
	else if (min >= 10)
	{
		//If minute is 2 digit
		*(highscore+1) = min % 10;
		*highscore = (min - *(highscore+1)) /10;
	}
	if (sec < 10)
	{
		//If second is only 1 digit
		*(highscore+3) = sec;
	}
	else if ( sec >= 10)
	{
		//If second is 2 digit
		*(highscore+3) = sec % 10;
		*(highscore+2) = (sec - *(highscore+3)) /10;
	}
	
	//value of what highscore u achieved
	int highmin = (highscore[0] * 10) + highscore[1];
	int highsec = (highscore[2] * 10) + highscore[3];

	//getting data from textfile
	if(lvl1 == true)
	{
		//For level 1
		ifstream coutfile;
		coutfile.open("highscore1.txt");
		coutfile.getline(highscoreC,5);
		//cout << highscoreC << endl;
		coutfile.close();
	}
	else if(lvl2 == true)
	{
		//For level 2
		ifstream coutfile;
		coutfile.open("highscore2.txt");
		coutfile.getline(highscoreC,5);
		//cout << highscoreC << endl;
		coutfile.close();
	}
	else if(lvl3 == true)
	{
		//For level 3
		ifstream coutfile;
		coutfile.open("highscore3.txt");
		coutfile.getline(highscoreC,5);
		//cout << highscoreC << endl;
		coutfile.close();
	}

	//value of the best highscore from textfile
	int highminC = ((highscoreC[0]-48)*10) + (highscoreC[1]-48);
	int highsecC = ((highscoreC[2]-48)*10) + (highscoreC[3]-48);

	//replace highscore
	if(highmin < highminC)
	{
		newhighscore();
		highminC = highmin;
		highsecC = highsec;
		gotoXY(25,26);
		setcolor(0xE);
		cout << "You have achieved a new highscore!";
		setcolor(7);
		newscore = true;
	}
	else if(highmin == highminC)
	{
		if(highsec < highsecC)
		{
			newhighscore();
			highsecC = highsec;
			gotoXY(25,26);
			setcolor(0xE);
			cout << "You have achieved a new highscore!";
			setcolor(7);
			newscore = true;
		}
		else if (highsec == highsecC)
		{
			newscore = false;
		}
	}
	
	//convert highminC and highsecC to highscoreC 
	if (highminC < 10)
	{
		*highscoreC = '0';
		*(highscoreC+1) = highminC+48;
	}
	else if (highminC >= 10)
	{
		*(highscoreC+1) = highminC % 10;
		*highscoreC = (highminC - highscoreC[1]) /10 + 48;
		*(highscoreC+1) += 48;
	}
	if (highsecC < 10)
	{
		*(highscoreC+2) = '0';
		*(highscoreC+3) = highsecC+48;
	}
	else if ( sec >= 10)
	{
		*(highscoreC+3) = highsecC % 10;
		*(highscoreC+2) = (highsecC - highscoreC[3]) /10 + 48;
		*(highscoreC+3) += 48;
	}

	//stores best highscore in texfile
	if(lvl1 == true)
	{
		//For level 1
		ofstream cinfile;
		cinfile.open("highscore1.txt");
		for(i = 0; i < sizeof(highscoreC); ++i)
		{
			cinfile << highscoreC[i];
		}
		cinfile.close();
	}
	else if (lvl2 == true)
	{
		//For level 2
		ofstream cinfile;
		cinfile.open("highscore2.txt");
		for(i = 0; i < sizeof(highscoreC); ++i)
		{
			cinfile << highscoreC[i];
		}
		cinfile.close();
	}
	else if (lvl3 == true)
	{
		//For level 3
		ofstream cinfile;
		cinfile.open("highscore3.txt");
		for(i = 0; i < sizeof(highscoreC); ++i)
		{
			cinfile << highscoreC[i];
		}
		cinfile.close();
	}
}

//Shows highscore
void showscore(void)
{
	char highscoreC[5] = {0};
	if(lvl1 == true)
	{
		//getting data from textfile
		//For level 1
		ifstream coutfile;
		coutfile.open("highscore1.txt");
		coutfile.getline(highscoreC,5);
		coutfile.close();
		//prints out the current best highscore
		gotoXY (54,20);
		cout << "Best Highscore: ";
		gotoXY (54,21);
		cout << highscoreC[0] << highscoreC[1] <<" minutes " << highscoreC[2] << highscoreC[3] << " seconds";
		gotoXY (0,24);
	}
	else if (lvl2 == true)
	{
		//getting data from textfile
		//For level 2
		ifstream coutfile;
		coutfile.open("highscore2.txt");
		coutfile.getline(highscoreC,5);
		coutfile.close();
		//prints out the current best highscore
		gotoXY (54,20);
		cout << "Best Highscore: ";
		gotoXY (54,21);
		cout << highscoreC[0] << highscoreC[1] <<" minutes " << highscoreC[2] << highscoreC[3] << " seconds";
		gotoXY (0,24);
	}
	else if (lvl3 == true)
	{
		//getting data from textfile
		//For level 3
		ifstream coutfile;
		coutfile.open("highscore3.txt");
		coutfile.getline(highscoreC,5);
		coutfile.close();
		//prints out the current best highscore
		gotoXY (54,20);
		cout << "Best Highscore: ";
		gotoXY (54,21);
		cout << highscoreC[0] << highscoreC[1] <<" minutes " << highscoreC[2] << highscoreC[3] << " seconds";
		gotoXY (0,24);
	}
}