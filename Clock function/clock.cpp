#include "header.h"
#include "clock.h"
#include "functions.h"

int seconds;
int minutes = 0;
clock_t start;

void clock_start()
{
	start = clock();
}
void clock_end()
{
	seconds = (clock() - start ) / (int) CLOCKS_PER_SEC + 800 ;
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
	seconds = 0;
	minutes = 0;
}