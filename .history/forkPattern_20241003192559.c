#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
//#include <sys/wait.h>
#include <windows.h>
#include <time.h>
#include "forkPattern.h"

void processingFork(int forkPattern, int patternNum, int id){
    printf("Process %d (PID: %d) beginning.\n", 0, getpid());
    sleep();
    if (patternNum = 1){
        processFork1(forkPattern, id);
    } else processFork2(forkPattern, id);
}

void sleepFuction(){
    sleep(rand() % 8 + 1);
}

void processFork1(int forkPattern, int id){

}

void processFork2(int forkPattern, id){
    if (forkPattern-1 > 0) pid_t pid = fork();

    if (pid == 0) {
        printf("Process %d (PID: %d) creating Process %d.\n", id, getpid(), id + 1, getpid());
        processFork(forkPattern, id + 1);
    } else waitpid(pid, NULL, 0);

printf("Process %d (PID: %d) exiting.\n", id, getpid());
}