#pragma once
#include "Header.h"


void alarm(int i)
{
			ledOn(i);
			Wait(10);
			ledOff(i);
			Wait(10);
}

void unlocked(int i)
{
		ledOn(i);
		Wait(10);
		ledOff(i);
}

void locked(int i)
{
	ledOn(i);
	Wait(10);
	ledOff(i);
}

void breakIn(int i)
{
	ledOn(i);
}

