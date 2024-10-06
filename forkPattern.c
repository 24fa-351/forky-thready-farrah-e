#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include "forkPattern.h"

void processingFork(int numOfThings, int patternNum, int id){
    pid_t childArray[20];
    if (patternNum == 1) fprintf(stderr, "**Pattern 1: creating %d processes\n", numOfThings);
    else if (patternNum == 2) fprintf(stderr, "**Pattern 2: creating %d processes\n", numOfThings);
    else exit(EXIT_FAILURE);

    for (int childIndex = 0; childIndex <= numOfThings; childIndex++){
        int sleepDuration = rand() % 8 + 1;
        pid_t pid = fork();
        if (pid == 0){
                //processFork1 will exit and not return
                if (patternNum == 1) processFork1(childIndex, sleepDuration);
                //processFork2 will exit and not return
                else if (patternNum == 2) processFork2(childIndex, sleepDuration, numOfThings);
        }
        //pid = childProcessID
        childArray[childIndex] = pid;
    } 
    for (int childIndex = 0; childIndex <= numOfThings; childIndex++){
        waitpid(childArray[childIndex], NULL, 0);
    }
    fprintf(stderr, "All children have exited\n \n");
}

void sleepFunction(int sleepDuration){
    fprintf(stderr, "sleeping for %d seconds\n", sleepDuration);
    sleep(sleepDuration);
}

void processFork1(int childIndex, int sleepDuration){
    fprintf(stderr, "Process %d (PID: %d) beginning.\n", childIndex, getpid());
    sleepFunction(sleepDuration);
    fprintf(stderr, "Process %d (PID: %d) exiting.\n", childIndex, getpid());
    exit(0);
}



void processFork2(int childIndex, int sleepDuration, int numOfThings){
    fprintf(stderr, "Process %d (PID: %d) beginning.\n", childIndex, getpid());
    if(childIndex < numOfThings)
    fprintf(stderr, "Process %d (PID: %d) creating Process %d.\n", childIndex, getpid(), childIndex+1);
    sleepFunction(sleepDuration);
    fprintf(stderr, "Process %d (PID: %d) exiting.\n", childIndex, getpid());
    exit(0);
}

