/* 
Purpose: Get current time
can accurately measure time intervals, timeouts

Function Prototype 
int gettimeofday(struct timeval *tv, struct timezone *tz);

Return Value
- Returns 0 on success, -1 on error.
*/

#include <sys/time.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int main() {
    struct timeval t;
    uint64_t now_in_usec;

    if (gettimeofday(&t, NULL) < 0)
        return (perror("gettimeofday"), 0);

    now_in_usec = (t.tv_sec * (uint64_t)1000000) + t.tv_usec;   
    
    printf("%lu\n", t.tv_sec);
    printf("%lu\n", t.tv_usec);
    printf("%lu\n", now_in_usec);
    printf("%lu\n", ULONG_MAX);
    
}

