#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

#define LEN 4

typedef struct s_data 
{
    int         id;
    pthread_t   thread;
    sem_t       *blocker;
} t_data;


void *routine(void *arg)
{
    t_data *data = (t_data *)arg;
    
    sem_wait(data->blocker);
    sleep(1);
    printf("this is thread = %d\n", data->id);
    sem_post(data->blocker);    

    return (NULL);
}


int main()
{
    int i;
    t_data data[LEN];
    sem_t blocker;

    i = -1;
    sem_init(&blocker, 0, 3);
    while (++i < LEN)
    {
        data[i].id = i + 1;
        data[i].blocker = &blocker; 
        pthread_create(&data[i].thread, NULL, routine, &data[i]);
    }
        
    i = -1;
    while (++i < LEN)
        pthread_join(data[i].thread , NULL);

    sem_destroy(&blocker);
}