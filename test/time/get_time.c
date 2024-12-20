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

int main() {
    struct timeval tv;
    struct timezone tz;

    if (gettimeofday(&tv, &tz) < 0)
        return (perror("gettimeofday"), 0);
    
    printf("Seconds since Epoch: %ld\n", tv.tv_sec);
    printf("Microseconds: %ld\n", tv.tv_usec);
    printf("Timezone: %d\n", tz.tz_minuteswest);
}

