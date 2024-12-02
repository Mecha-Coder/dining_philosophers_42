
/*
int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);
*/

#include <stdio.h>
#include <pthread.h>

void *my_thread_func(void *arg)
{
    pthread_mutex_t *mutex = (pthread_mutex_t *)arg;
    
    pthread_mutex_lock(mutex); // Acquire the mutex
    // Critical section: access shared resource
    printf("Hello from thread!\n");
    pthread_mutex_unlock(mutex); // Release the mutex
    return NULL;
}


int main()
{
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL); // Initialize the mutex

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, my_thread_func, &mutex);

    pthread_join(thread_id, NULL);

    pthread_mutex_destroy(&mutex); // Destroy the mutex

    return 0;
}