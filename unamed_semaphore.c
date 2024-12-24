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

typedef struct s_data
{
    int id;
    pthread_t thread;
    sem_t *print_key;
} t_data; 

void *routine(void *arg)
{
    t_data *data = (t_data *)arg;

    sem_wait(data->print_key);
    sleep(1);
    printf("This is id = %d\n", data->id);
    sem_post(data->print_key);
    return (NULL);
}   


int main()
{
    int i = -1;
    int size = 6;
    t_data data[size];
    sem_t print_key;


    sem_init(&print_key, 0, 3);
    while (++i < size)
    {
        data[i].id = i + 1;
        data[i].print_key = &print_key;
        pthread_create(&data[i].thread, NULL, routine, &data[i]);
    }

    i = -1;
    while (++i < size)
        pthread_join(data[i].thread, NULL);

    sem_close(&print_key);
}