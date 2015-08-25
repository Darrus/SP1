#ifndef GAMEMENU_H
#define GAMEMENU_H

enum state
{
	Play = 1,
	Create,
	Quit,
	MAX,
};

enum level
{
	One = 1,
	Two,
	Custom,
};

void gamemenu();
void title();
void menu();
void play();
void input(state& s);
void cls();
void levelmenu();
void levelselect(level& l);
void error();
void quit();

#endif