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
	Back = 0,
	One,
	Two,
	Three,
	Custom,
};

enum customenum
{
	Back1 = 0,
	Save1,
	Save2,
	Save3,
	END,
};

void gamemenu();
void title();
void menu();
void play();
void input(state& s);
void levelmenu();
void levelselect(level& l);
void error();
void quit();
void custom();
void custommenu();
void customselect(customenum& i);

#endif