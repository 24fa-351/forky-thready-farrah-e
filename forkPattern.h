#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>
#include <time.h>

#define SUB_PROCESS_MAX 256

void sleepFunction();

void processingFork(int numOfThings, int patternNum, int id);

void processFork1(int numOfThings, int id);

void processFork2(int numOfThings, int forkPattern, int id);