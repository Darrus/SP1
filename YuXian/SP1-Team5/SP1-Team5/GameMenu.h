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

enum customenum
{
	Save1 = 1,
	Save2,
	Save3,
	END,
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