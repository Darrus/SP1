#ifndef MAIN_H
#define MAIN_H

enum state
{
	Play = 1,
	Create,
	Quit,
	MAX
};

void title();
void menu();
void input(state& s);
void cls();

#endif