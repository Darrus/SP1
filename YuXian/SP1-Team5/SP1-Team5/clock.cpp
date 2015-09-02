#include "header.h"
#include "clock.h"
#include "functions.h"
#include "highscore.h"

int seconds = 0;
int minutes = 0;
clock_t start;

//Starts the clock
void clock_start(void)
{
	//Records current time
	seconds = 0;
	minutes = 0;
	start = clock();
}

int clock_end(void)
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
	return minutes,seconds;
}