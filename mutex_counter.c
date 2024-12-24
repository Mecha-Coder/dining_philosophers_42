#include <stdio.h>
#include <pthread.h>

int shared_counter = 0;
pthread_mutex_t mutex;

void *increment_counter(void *arg) 
{
    int *arg_int = (int *)arg;
    (void)arg_int;
    for (int i = 0; i < 10000; ++i) 
    {
        pthread_mutex_lock(&mutex);
        shared_counter++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    int arg_value = 42;
    pthread_t threads[10];
    
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < 10; ++i)
        pthread_create(&threads[i], NULL, increment_counter, (void *)&arg_value);


    for (int i = 0; i < 10; ++i) 
        pthread_join(threads[i], NULL);

    printf("Final counter value: %d\n", shared_counter);
    pthread_mutex_destroy(&mutex);
}