
/*
int pthread_join(pthread_t thread, void **retval);

retval: A pointer to a location where the return value of the thread function can be stored. If the return value is not needed, this can be set to NULL

*/

#include <stdio.h>
#include <pthread.h>

void *my_thread_func(void *arg) {
    printf("Hello from thread!\n");
    return NULL;
}

int main() {
    pthread_t thread_id;

    pthread_create(&thread_id, NULL, my_thread_func, NULL);

    pthread_join(thread_id, NULL); // Wait for the thread to finish

    printf("Main thread continues...\n");

    return 0;
}