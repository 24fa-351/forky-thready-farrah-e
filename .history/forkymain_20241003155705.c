#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <time.h>

#define NUM_PROCESSES 5

void create_process(int id) {
    printf("Process %d (PID: %d) beginning.\n", id, getpid());
    
    // Sleep for a random duration between 1 and 8 seconds
    int sleep_time = rand() % 8 + 1; // 1 to 8 seconds
    sleep(sleep_time);
    
    // If this is not the last process, create another process
    if (id < NUM_PROCESSES - 1) {
        pid_t pid = fork();
        
        if (pid < 0) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            printf("Process %d (PID: %d) creating Process %d.\n", id, getpid(), id + 1);
            create_process(id + 1);
            exit(EXIT_SUCCESS);
        } else {
            // Parent process waits for the child
            waitpid(pid, NULL, 0);
        }
    }

    printf("Process %d (PID: %d) exiting.\n", id, getpid());
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Create the first process
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        return EXIT_FAILURE;
    } else if (pid == 0) {
        // Child process
        create_process(0);
        exit(EXIT_SUCCESS);
    }

    // Parent process waits for the first child to complete
    waitpid(pid, NULL, 0);
    
    printf("All processes have completed.\n");
    return 0;
}
