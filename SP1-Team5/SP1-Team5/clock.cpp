#include "header.h"
#include "clock.h"
#include "functions.h"
#include "highscore.h"

/**
*	Chuan Guang Zhe
*	This cpp file contains the functions needed to calculate time taken for the stage to be clear / player loses.
*	This cpp file is mainly used for highscore.cpp
*	
*	clock_start() 21/8/2015
*	Starts the clock
*
*	clock_end() 21/8/2015
*	Ends the clock and returns
*/

//Declarations of variables
int seconds = 0;
int minutes = 0;
clock_t start;

//Starts the clock
void clock_start(void)
{
	//Resets and Records current time
	seconds = 0;
	minutes = 0;
	start = clock();
}

//Ends the clock
void clock_end(void)
{
	//Current time - previous current time is converted into seconds
	seconds = (clock() - start ) / (int) CLOCKS_PER_SEC ;
	//Converts timing from seconds only to minutes and seconds
	while(seconds >= 60)
	{
		seconds -=60;
		minutes += 1;
	}
	if (minutes == 0 && seconds <60)
	{
		gotoXY (54,17);
		cout <<"Time taken: "; 
		gotoXY (54,18);
		cout << seconds <<" seconds"<< endl;
		gotoXY (0,24);
	}
	else if (minutes > 0 && minutes <= 1)
	{
		gotoXY (54,17);
		cout <<"Time taken: "; 
		gotoXY (54,18);
		cout << minutes << " minute " << seconds <<" seconds"<< endl;
		gotoXY (0,24);
	}
	else if (minutes > 1)
	{
		gotoXY (54,17);
		cout <<"Time taken: "; 
		gotoXY (54,18);
		cout << minutes << " minutes " << seconds <<" seconds"<< endl;
		gotoXY (0,24);
	}
}