/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:41:37 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/12 19:34:02 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
Purpose:  
- Get current time in milliseconds
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

	if (gettimeofday(&t, NULL) == -1)
	    err_msg("get_time: failed gettimeofday()");
    return ((t.tv_sec * 1000000) + t.tv_usec);
}

/*
int main()
{
    printf("%lu\n", get_time());
}
*/
