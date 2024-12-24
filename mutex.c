
/*
int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);
*/

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t my_mutex;

void *thread_func(void *arg) {
    // ... critical section protected by the mutex ...
    pthread_mutex_lock(&my_mutex);
    // ... critical section code ...
    printf("Hello from thread!\n");
    pthread_mutex_unlock(&my_mutex);
    return NULL;
}


#include <stdio.h>
#include <pthread.h>

pthread_mutex_t my_mutex;

void *thread_func(void *arg) {
    // ... critical section protected by the mutex ...
    pthread_mutex_lock(&my_mutex);
    // ... critical section code ...
    pthread_mutex_unlock(&my_mutex);
    return NULL;
}

int main() {
    pthread_t thread_id;

    // Initialize the mutex
    pthread_mutex_init(&my_mutex, NULL);

    // Create a thread
    pthread_create(&thread_id, NULL, thread_func, NULL);

    // ... other code ...

    // Join the thread
    pthread_join(thread_id, NULL);

    // Destroy the mutex
    pthread_mutex_destroy(&my_mutex);

    return 0;
}