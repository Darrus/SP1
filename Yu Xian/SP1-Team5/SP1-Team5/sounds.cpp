#include "sounds.h"
#include "header.h"

extern bool g_key;

void door1(void)
{
	if (g_key == true)
	{
		PlaySound(TEXT("doorsound"),NULL,SND_FILENAME|SND_ASYNC);
	}
}

void gate(void)
{
	PlaySound(TEXT("gate"),NULL,SND_FILENAME|SND_ASYNC);
}

void brokenfloor(void)
{
	PlaySound(TEXT("brokenfloor"), NULL, SND_FILENAME|SND_ASYNC);
}

void muddy(void)
{
	PlaySound(TEXT("mud"), NULL, SND_FILENAME|SND_ASYNC);
}

void menuselect(void)
{
	PlaySound(TEXT("menuselect"), NULL, SND_FILENAME|SND_ASYNC);
}

void back(void)
{
	PlaySound(TEXT("back"), NULL, SND_FILENAME|SND_ASYNC);
}

void errorsound(void)
{
	PlaySound(TEXT("error"), NULL, SND_FILENAME);
}

void death(void)
{
	PlaySound(TEXT("death"), NULL, SND_FILENAME|SND_ASYNC);
}

void win(void)
{
	PlaySound(TEXT("win"), NULL, SND_FILENAME);
}

void newhighscore(void)
{
	PlaySound(TEXT("newhighscore"), NULL, SND_FILENAME|SND_ASYNC);
}