#include "sounds.h"
#include "header.h"

extern bool g_key;

void door1()
{
	if (g_key == true)
	{
		PlaySound(TEXT("doorsound"),NULL,SND_FILENAME|SND_ASYNC);
	}
}

void door2()
{

}

void brokenfloor()
{
	PlaySound(TEXT("brokenfloor"), NULL, SND_FILENAME|SND_ASYNC);
}

void muddy()
{
	PlaySound(TEXT("mud"), NULL, SND_FILENAME|SND_ASYNC);
}

void menuselect()
{
	PlaySound(TEXT("menuselect"), NULL, SND_FILENAME|SND_ASYNC);
}

void back()
{
	PlaySound(TEXT("back"), NULL, SND_FILENAME|SND_ASYNC);
}

void death()
{
	PlaySound(TEXT("death"), NULL, SND_FILENAME|SND_ASYNC);
}