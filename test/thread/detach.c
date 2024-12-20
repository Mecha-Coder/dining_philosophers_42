
/* Purpose: 
- detached thread becomes a background thread that runs independently
- from main

prototype
int pthread_detach(pthread_t thread);

Return 
0: Success Non-zero: Error
*/

#include <stdio.h>
#include <pthread.h>

void *my_thread_func(void *arg) 
{
    char *msg = (char *)arg;
    printf("Hello from thread! %s\n",msg);
    return NULL;
}

int main() {
    pthread_t thread_id;

    pthread_create(&thread_id, NULL, my_thread_func, (void *)"pass arg");
    pthread_detach(thread_id); // Detach the thread
    
    // Main thread continues without waiting for the detached thread
    printf("Main thread continues...\n");

    return 0;
}