#include <stdio.h>
#include "forkPattern1.h"

int main(int argc, char* argv[]) {
    int numOfThings = atoi(argv[1]);
    int patternNum = atoi(argv[2]);
    //pattern 1 implementing
    if (numOfThings < 1 || numOfThings > MAX_PROCESSES) {
    fprintf(stderr, "Number of things must be between 1 and %d.\n", MAX_PROCESSES);
    return EXIT_FAILURE;
    }


    return 0;
}