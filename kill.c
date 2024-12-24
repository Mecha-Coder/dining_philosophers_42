#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

int main() 
{
    int status;
    pid_t child_pid = fork();

    if (child_pid == 0) 
    { 
        printf("Child process started\n");
        exit(0); 
    } 
   
    printf("Parent process waiting for child\n");
    wait(&status);
    
    if (kill(child_pid, SIGTERM) == -1) 
        perror("kill failed");
    else 
        printf("kill() call returned success (but the child is already terminated)\n");


    return 0;
}