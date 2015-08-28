#include "header.h"
#include "clock.h"
#include "functions.h"
#include "highscore.h"

int seconds;
int minutes = 0;
clock_t start;

//Starts the clock
void clock_start()
{
	//Records current time
	start = clock();
}

int clock_end()
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
		gotoXY (54,15);
		cout <<"Time taken: "; 
		gotoXY (54,16);
		cout << seconds <<" seconds"<< endl;
		gotoXY (0,24);
	}
	else if (minutes > 0 && minutes <= 1)
	{
		gotoXY (54,15);
		cout <<"Time taken: "; 
		gotoXY (54,16);
		cout << minutes << " minute " << seconds <<" seconds"<< endl;
		gotoXY (0,24);
	}
	else if (minutes > 1)
	{
		gotoXY (54,15);
		cout <<"Time taken: "; 
		gotoXY (54,16);
		cout << minutes << " minutes " << seconds <<" seconds"<< endl;
		gotoXY (0,24);
	}
	return minutes,seconds;
	seconds = 0;
	minutes = 0;
}