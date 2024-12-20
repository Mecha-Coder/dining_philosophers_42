
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

void *my_thread_func() 
{
    usleep(1000000);
    printf("Hello from thread!\n");
    return NULL;
}

int main() {
    pthread_t thread_id;

    pthread_create(&thread_id, NULL, my_thread_func, NULL);
    printf("Doing what\n");
    printf("Are you waiting\n");
    //pthread_join(thread_id, NULL); // Wait for the thread to finish
    printf("Finish\n");
    return 0;
}