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
	Back1,
	Save1,
	Save2,
	Save3,
	END,
};

void gamemenu(void);
void title(void);
void menu(void);
void play(void);
void input(state& s);
void levelmenu(void);
void levelselect(level& l);
void back(void);
void error(void);
void quit(void);
void custom(void);
void custommenu(void);
void customselect(customenum& i);

#endif