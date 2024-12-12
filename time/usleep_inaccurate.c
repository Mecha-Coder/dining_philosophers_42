#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

long int get_microsec(struct timeval *tv)
{
    long int microsec;

    microsec =  (tv->tv_sec * 1000000) + (tv->tv_usec); 
    return (microsec);
}

int main()
{
    struct timeval start_time;
    struct timeval end_time;
    long requested_time;
    long actual_sleep_time;
    

    requested_time = 200 * 1000; // 200 millisec

    gettimeofday(&start_time, NULL);
    usleep(requested_time);
    gettimeofday(&end_time, NULL);
    
    actual_sleep_time = get_microsec(&end_time) - get_microsec(&start_time);
    
    printf("Requested sleep time: %ld microseconds\n", requested_time);
    printf("Actual sleep time   : %ld microsecond\n", actual_sleep_time);

}   
