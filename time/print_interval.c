#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main() {
    struct timeval start_time; 
    struct timeval current_time;
    
    gettimeofday(&start_time, NULL);
    while (1) 
    {
        gettimeofday(&current_time, NULL);
        long elapsed_time = (current_time.tv_sec - start_time.tv_sec) * 1000000 + (current_time.tv_usec - start_time.tv_usec);

        printf("%ld\n", elapsed_time);

        // Adjust this sleep time as needed
        usleep(1000000); // 100 milliseconds
    }
    return 0;
}