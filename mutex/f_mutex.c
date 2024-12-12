#include <stdio.h> //printf
#include <stdlib.h> //malloc
#include <pthread.h>
#include <unistd.h>

typedef struct s_data
{
    int num;
    pthread_mutex_t mutex;
}   t_data;

t_data *init_data()
{
    t_data *data;

    data = malloc(sizeof(t_data));
    if (data == NULL)
        exit(1);
    data->num = 0;
    pthread_mutex_init(&data->mutex, NULL);
    return (data);
}

void free_data(t_data *data)
{
    pthread_mutex_destroy(&data->mutex);
    free(data);
}

void exit_on_error(t_data *data, int exit_code)
{
    free(data);
    exit(exit_code);
}

void *routine(void *arg)
{
    t_data *data;
    int i;

    data = (t_data *)arg;
    i = 0;
    while (i < 10000000)
    {
        pthread_mutex_lock(&data->mutex); // LOCK
        data->num++;
        pthread_mutex_unlock(&data->mutex); // UNLOCK
        i++;
    }
    return (NULL);
}

void example(void)
{
    t_data *data;
    pthread_t t1;
    pthread_t t2;

    data = init_data();

    if (pthread_create(&t1, NULL, routine, data))
        exit_on_error(data, 2);
    if (pthread_create(&t2, NULL, routine, data))
        exit_on_error(data, 2);

    if (pthread_join(t1, NULL))
        exit_on_error(data, 3);
    if (pthread_join(t2, NULL))
        exit_on_error(data, 3);

    printf("Num: %d\n", data->num);
    free_data(data);
}

int main()
{
    example();
}