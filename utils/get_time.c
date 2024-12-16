/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:41:37 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/16 15:40:09 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
get_time
=========
Purpose 
- Get current time in microseconds
- Type uint64_t ensures variable declared exactly 64 bits

============================================================================
Function - gettimeofday()

gettimeofday(struct timeval *tv, struct timezone *tz)

struct timeval
{
    time_t      tv_sec;     // seconds from January 1, 1970
    suseconds_t tv_usec;    // microsecond of tv_sec
}
Return
> 0 on success,
> -1 on error.

============================================================================
Time conversion:

1 second = 1 000 000 microsec
1 second = 1 000 millisec

*/
uint64_t get_time(void)
{
	struct timeval	t;

	check_error("gettimeofday", gettimeofday(&t, NULL));
    return ((t.tv_sec * (uint64_t)1000000) + t.tv_usec);
}

/*
int main()
{
    printf("%lu\n", get_time());
    printf("%lu\n", ULONG_MAX);
}
*/
