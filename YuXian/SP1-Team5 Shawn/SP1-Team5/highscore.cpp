#include "header.h"
#include "clock.h"
#include "functions.h"
#include "highscore.h"

void store(int min, int sec)
{
	int highscore[4] = {0};
	char highscoreC[5] = {0};
	int m = min;
	int s = sec;
	int i = 0;

	//convert time taken to your highscore
	if ( m < 10)
	{
		highscore[1] = m;
	}
	else if (m >= 10)
	{
		highscore[1] = m % 10;
		highscore[0] = m - highscore[1];
	}
	if (s < 10)
	{
		highscore[3] = s;
	}
	else if ( s >= 10)
	{
		highscore[3] = s % 10;
		highscore[2] = s - highscore[3];
	}
	
	//value of what highscore u achieved
	int highmin = (highscore[0] * 10) + highscore[1];
	int highsec = (highscore[2] * 10) + highscore[3];

	//getting data from textfile
	ifstream coutfile;
	coutfile.open("highscore1.txt");
	coutfile.getline(highscoreC,5);
	cout << highscoreC << endl;
	coutfile.close();

	//value of the best highscore from textfile
	int highminC = ((highscoreC[0]-48)*10) + (highscoreC[1]-48);
	int highsecC = ((highscoreC[2]-48)*10) + (highscoreC[3]-48);

	//replace highscore
	if(highmin < highminC)
	{
		highminC = highmin;
		highsecC = highsec;
		gotoXY(0,23);
		cout << "You have achieved a new highscore!";
	}
	else if(highmin == highminC)
	{
		if(highsec < highsecC)
		{
			highsecC = highsec;
			gotoXY(0,23);
			cout << "You have achieved a new highscore!";
		}
	}
	
	//convert highminC and highsecC to highscoreC 
	if (highminC < 10)
	{
		highscoreC[0] = '0';
		highscoreC[1] = highminC+48;
	}
	else if (highminC >= 10)
	{
		highscoreC[1] = highminC % 10;
		highscoreC[0] = (highminC - highscoreC[1])+48;
	}
	if (highsecC < 10)
	{
		highscoreC[2] = '0';
		highscoreC[3] = highsecC+48;
	}
	else if ( s >= 10)
	{
		highscoreC[3] = highsecC % 10;
		highscoreC[2] = (highsecC - highscoreC[3])+48;
	}

	//stores best highscore in texfile
	ofstream cinfile;
	cinfile.open("highscore1.txt");
	for(i = 0; i < sizeof(highscoreC); ++i)
	{
		cinfile << highscoreC[i];
	}
	cinfile.close();
	
	//prints out the current best highscore
	gotoXY (52,20);
	cout << "Best Highscore: ";
	gotoXY (52,21);
	cout << highscoreC[0] << highscoreC[1] <<" minutes " << highscoreC[2] << highscoreC[3] << " seconds";
	gotoXY (0,24);
}
void store2(int min, int sec)
{
	int highscore[4] = {0};
	char highscoreC[5] = {0};
	int m = min;
	int s = sec;
	int i = 0;

	//convert time taken to your highscore
	if ( m < 10)
	{
		highscore[1] = m;
	}
	else if (m >= 10)
	{
		highscore[1] = m % 10;
		highscore[0] = m - highscore[1];
	}
	if (s < 10)
	{
		highscore[3] = s;
	}
	else if ( s >= 10)
	{
		highscore[3] = s % 10;
		highscore[2] = s - highscore[3];
	}
	
	//value of what highscore u achieved
	int highmin = (highscore[0] * 10) + highscore[1];
	int highsec = (highscore[2] * 10) + highscore[3];

	//getting data from textfile
	ifstream coutfile;
	coutfile.open("highscore2.txt");
	coutfile.getline(highscoreC,5);
	cout << highscoreC << endl;
	coutfile.close();

	//value of the best highscore from textfile
	int highminC = ((highscoreC[0]-48)*10) + (highscoreC[1]-48);
	int highsecC = ((highscoreC[2]-48)*10) + (highscoreC[3]-48);

	//replace highscore
	if(highmin < highminC)
	{
		highminC = highmin;
		highsecC = highsec;
		gotoXY(0,23);
		cout << "You have achieved a new highscore!";
	}
	else if(highmin == highminC)
	{
		if(highsec < highsecC)
		{
			highsecC = highsec;
			gotoXY(0,23);
			cout << "You have achieved a new highscore!";
		}
	}
	
	//convert highminC and highsecC to highscoreC 
	if (highminC < 10)
	{
		highscoreC[0] = '0';
		highscoreC[1] = highminC+48;
	}
	else if (highminC >= 10)
	{
		highscoreC[1] = highminC % 10;
		highscoreC[0] = (highminC - highscoreC[1])+48;
		//m2d = true;
	}
	if (highsecC < 10)
	{
		highscoreC[2] = '0';
		highscoreC[3] = highsecC+48;
	}
	else if ( s >= 10)
	{
		highscoreC[3] = highsecC % 10;
		highscoreC[2] = (highsecC - highscoreC[3])+48;
		//s2d = true;
	}

	//stores best highscore in texfile
	ofstream cinfile;
	cinfile.open("highscore2.txt");
	for(i = 0; i < sizeof(highscoreC); ++i)
	{
		cinfile << highscoreC[i];
	}
	cinfile.close();
	
	//prints out the current best highscore
	gotoXY (52,20);
	cout << "Best Highscore: ";
	gotoXY (52,21);
	cout << highscoreC[0] << highscoreC[1] <<" minutes " << highscoreC[2] << highscoreC[3] << " seconds";
	gotoXY (0,24);
}