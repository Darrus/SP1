#ifndef GAMEMENU_H
#define GAMEMENU_H

enum state
{
	Play = 1,
	Create,
	Quit,
	MAX_STATE,
};

enum level
{
	One = 1,
	Two,
	Custom,
	Back,
	MAX_LEVEL,
};

enum customenum
{
	Save1 = 1,
	Save2,
	Save3,
	Back1,
	MAX_CUSTOM,
};

void gamemenu();
void title();
void menu();
void play();
void custom();
void input(state& s);
void cls();
void levelmenu();
void custommenu();
void levelselect(level& l);
void customselect(customenum& i);
void error();
void quit();

#endif