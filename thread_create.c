
/* 
Purpose:  create a new thread of execution
execute multiple tasks concurrently within a single process

Function prototype
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);

1) thread: A pointer to a thread ID.
2) attr: Attributes for the new thread. Often set to NULL to use default attributes.
3) start_routine: A pointer to the function that the new thread will execute.
4) arg: An argument to be passed to the start_routine function.


Return 
0:Sucess Non_zero: Error
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *routine(void *arg) 
{
    pthread_mutex_t *lock;

    lock = (pthread_mutex_t *)arg;
    
    pthread_mutex_lock(lock);
    printf("Hello from thread!\n");
    pthread_mutex_unlock(lock);
    return NULL;
}

int main() {
    pthread_t thread_id;
    pthread_mutex_t lock;

    pthread_mutex_init(&lock, NULL);

    pthread_mutex_lock(&lock);
    pthread_create(&thread_id, NULL, routine, &lock);
    
    printf("Doing what\n");
    printf("Are you waiting\n");

    pthread_mutex_unlock(&lock);
    pthread_join(thread_id, NULL); // --> thread actual begin here
    
    printf("Finish\n");
    
    pthread_mutex_destroy(&lock);
    return 0;
}