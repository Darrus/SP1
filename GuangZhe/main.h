#ifndef MAIN_H
#define MAIN_H

enum state
{
	Play = 1,
	Create,
	Quit,
	MAX,
};

enum level
{
	All = 0,
	lvl1,
	lvl2,
	clvl,
};

void title();
void menu();
void input(state& s);
void cls();
void levelmenu();
void levelselect(level& l);
void error();
void lvlerror();
void quit();
void play();

#endif