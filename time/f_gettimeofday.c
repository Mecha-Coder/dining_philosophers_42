#include <stdio.h> //printf
#include <sys/time.h> // time
#include <unistd.h> // unsleep
#include <stdint.h> // uin64_t

/* 

>>> Purpose:
- Get current time with high precision
- get time in sec and microsec
- The counter begins on January 1, 1970

=================================================================
>>> Usage of gettimeofday
- can accurately measure time intervals, timeouts

=================================================================
>>> What stdint.h used for
- ensures variable declared will always be exactly 64 bits wide 
- type uint64_t is something like a long int

=================================================================
>>> struct for timeval
struct timeval
{
    time_t      tv_sec;     // seconds from January 1, 1970
    suseconds_t tv_usec;    // microsecond of tv_sec
} 

=================================================================
>>> Time conversion
1 second = 1 000 000 microsec
1 second = 1 000 millisec

=================================================================
>>> Function Prototype 
int gettimeofday(struct timeval *tv, struct timezone *tz);

=================================================================
>> Return Value
- Returns 0 on success, -1 on error.

*/

void example1(void)
{
    struct timeval time;
    int past_year;

    if (gettimeofday(&time, NULL))
        return ;
    printf("%ld seconds\n", time.tv_sec);
    printf("%ld microseconds\n", time.tv_usec);

    past_year = time.tv_sec/ (60 * 60 * 24 * 365);
    printf("%d years passed since 1970\n", past_year);
}


uint64_t get_time(void) // return time in millisecond
{
    struct timeval time;
    uint64_t convert_millisec;

    if (gettimeofday(&time, NULL))
        return (0);
    
    convert_millisec = (time.tv_sec * (uint64_t)1000) + (time.tv_usec / 1000);
    return (convert_millisec);
}

void example2()
{
    uint64_t start_time;
    uint64_t now;

    start_time = get_time();
    usleep(10000); // accept value in microsec. 10 000 mircosec == 10 millisec
    now = get_time();
    printf("%ld millisecond passed since the start\n", now - start_time);
}


int main()
{
    printf("Example1\n\n");

    example1();

    printf("\n====================\nExample2\n\n");

    example2();
}