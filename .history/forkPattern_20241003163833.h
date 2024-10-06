#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define SUB_PROCESS_MAX 256

void sleepFunction();

void processingFork(int forkPattern, int patternNum);

processFork1(int forkPattern);