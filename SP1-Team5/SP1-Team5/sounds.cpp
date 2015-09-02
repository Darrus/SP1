#include "sounds.h"
#include "header.h"

/**
*	By Chuan Guang Zhe 28/8/2015
*	This cpp file contains functions that plays sound effects which is used in other cpp files.
*/

//Door sound
void door1(void)
{
	PlaySound(TEXT("doorsound"),NULL,SND_FILENAME|SND_ASYNC);
}

//Gate sound
void gate(void)
{
	PlaySound(TEXT("gate"),NULL,SND_FILENAME|SND_ASYNC);
}

//Broken floor sound
void brokenfloor(void)
{
	PlaySound(TEXT("brokenfloor"), NULL, SND_FILENAME|SND_ASYNC);
}

//Muddy floor sound
void muddy(void)
{
	PlaySound(TEXT("mud"), NULL, SND_FILENAME|SND_ASYNC);
}

//Menu select sound
void menuselect(void)
{
	PlaySound(TEXT("menuselect"), NULL, SND_FILENAME|SND_ASYNC);
}

//Menu "back" sound
void backsound(void)
{
	PlaySound(TEXT("back"), NULL, SND_FILENAME|SND_ASYNC);
}

//Menu error sound
void errorsound(void)
{
	PlaySound(TEXT("error"), NULL, SND_FILENAME);
}

//Player death sound
void death(void)
{
	PlaySound(TEXT("death"), NULL, SND_FILENAME|SND_ASYNC);
}

//Level clear sound
void win(void)
{
	PlaySound(TEXT("win"), NULL, SND_FILENAME);
}

//New highscore sound
void newhighscore(void)
{
	PlaySound(TEXT("newhighscore"), NULL, SND_FILENAME|SND_ASYNC);
}