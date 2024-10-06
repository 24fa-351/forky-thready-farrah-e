#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "forkPattern1.h"

int main(int argc, char* argv[]) {
    int numOfThings = atoi(argv[1]);
    int patternNum = atoi(argv[2]);

    if (numOfThings < 1 || numOfThings > SUB_PROCESS_MAX) {
        fprintf(stderr, "subprocess must be between 1 and %d.\n", SUB_PROCESS_MAX);
        return -1;
    }




}