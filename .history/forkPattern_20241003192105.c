#include <stdio.h>
#include <stdlib.h>
#include "forkPattern.h"

void processingFork(int forkPattern, int patternNum, int id){
    printf("Process %d (PID: %d) beginning.\n", 0, getpid());
    sleep();
    if (patternNum = 1){
        processFork1(forkPattern);
    } else processFork2(forkPattern);
}

void sleepFuction(){
    sleep(rand() % 8 + 1);
}

void processFork1(int forkPattern){

}

void processFork2(int forkPattern){
    if (forkPattern-1 > 0) pid_t pid = fork();

    if (pid == 0) {

    }
    

}