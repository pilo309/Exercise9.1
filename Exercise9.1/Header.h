#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <stdlib.h>
#include <RaspberryDLL.h>
#include <conio.h>
#include <iostream>
#pragma once

void alarm(int i);
void unlocked(int i);
void keyChange(int i, int* keyPtr);
void locked(int i);
void breakIn(int i);

