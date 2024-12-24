#include <string.h>    // memset
#include <stdio.h>     // printf
#include <unistd.h>    // write, fork, kill, usleep
#include <stdlib.h>    // exit
#include <pthread.h>   // create, detect, join
#include <sys/time.h>  // gettimeofday
#include <sys/wait.h>  // waitpid
#include <semaphore.h> // sem_open, sem_close, sem_post, 
//                     // sem_wait, sem_unlink
#include <fcntl.h>     // Macro: O_CREAT | O_EXCL


int main()
{
    sem_t   *sem1;
    sem_t   *sem2;

    sem1 = sem_open("SEM_NAME_1", O_CREAT | O_EXCL, 0644, 0);
    sem2 = sem_open("SEM_NAME_2", O_CREAT | O_EXCL, 0644, 0);

    if (fork() == 0)
    {
        printf("1\n");
        sem_post(sem1);    // s1(1)
        sem_wait(sem2);    // s2(0)
        printf("3\n");
        sem_post(sem1);    // s1(1)

        sem_close(sem1);
        sem_close(sem2);
    }
    else
    {
        sem_wait(sem1);   // s1(0)
        printf("2\n");
        sem_post(sem2);   // s2(1)
        sem_wait(sem1);   // s1(0)
        printf("4\n");

        sem_close(sem1);
        sem_close(sem2);
    }

    sem_unlink("SEM_NAME_1");
    sem_unlink("SEM_NAME_2");
}