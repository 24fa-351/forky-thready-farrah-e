#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include "forkPattern.h"

void processingFork(int numOfThings, int patternNum, int id){

    srand(time(NULL));
    sleepFunction();

    if (patternNum == 1){
        pid_t pids[numOfThings];
        for (int i = 0 ; i < numOfThings; i++){
            pids[i] = fork();
            processFork1(numOfThings, id);
        }
        for (int i = 0 ; i < numOfThings; i++) waitpid(pids[i], NULL, 0);
    } else {
        pid_t pid = fork();
        processFork2(numOfThings, patternNum, id);
        waitpid(pid, NULL, 0);

    }
    printf("All processes have completed.\n");
    exit(EXIT_SUCCESS);
}

void sleepFunction(){
    sleep(rand() % 8 + 1);
}

void processFork1(int numOfThings, int id){
    int myId = id;
    printf("Process %d (PID: %d) beginning.\n", id, getpid());
    sleepFunction();
    if (id < numOfThings){
        printf("Process %d (PID: %d) creating Process %d.\n", myId, getpid(), myId + 1);
        myId++;
    }
    printf("Process %d (PID: %d) exiting.\n", id, getpid());
}

void processFork2(int numOfThings, int forkPattern, int id){
    printf("Process %d (PID: %d) beginning.\n", 0, getpid());

    if (forkPattern-1 > id) {
        srand(time(NULL));
        pid_t pid = fork();

        if (pid == 0) {
            printf("Process %d (PID: %d) creating Process %d.\n", id, getpid(), id);
            processingFork(numOfThings, forkPattern, id + 1);
        } else waitpid(pid, NULL, 0);
    }

printf("Process %d (PID: %d) exiting.\n", id, getpid());
}