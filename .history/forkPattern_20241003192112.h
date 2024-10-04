#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
// /#include <windows.h>
#include <time.h>

#define SUB_PROCESS_MAX 256

void sleepFunction();

void processingFork(int forkPattern, int patternNum, int id);

void processFork1(int forkPattern);

void processFork2(int forkPattern);