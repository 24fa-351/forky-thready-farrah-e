#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>
#include <time.h>

#define SUB_PROCESS_MAX 256

void sleepFunction(int sleepDuration);

void processingFork(int numOfThings, int patternNum, int id);

void processFork1(int childIndex, int sleepDuration);

void processFork2(int childIndex, int sleepDuration, int numOfThings);