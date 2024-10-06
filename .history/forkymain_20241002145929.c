#define _XOPEN_SOURCE 600


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h> 

void forky() 
{ 
    int x = 1; 
    pid_t p = fork(); 
      if(p<0){ 
      perror("fork fail"); 
      exit(1); 
    } 
    else if (p == 0) 
        printf("Child has x = %d\n", ++x); 
    else 
        printf("Parent has x = %d\n", --x); 
} 
int main() 
{ 
    forky(); 
    return 0; 
} 