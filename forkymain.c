#include <stdio.h>
#include <stdlib.h>
#include "forkPattern.h"

int main(int argc, char* argv[]) {
    srand(time(NULL));

    int numOfThings = atoi(argv[1]);
    int patternNum = atoi(argv[2]);

    if (numOfThings < 1 || numOfThings > SUB_PROCESS_MAX) {
        printf("subprocess must be between 1 and %d.\n", SUB_PROCESS_MAX);
        return -1;
    }

    if (patternNum < 1 || patternNum > 2) {
        printf ("Please choose pattern of 1 or 2.\n");
        return -1;
    }


    processingFork(numOfThings, patternNum, 0);


    return 0;
}
