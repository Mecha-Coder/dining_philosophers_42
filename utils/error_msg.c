/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:25:54 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/17 11:19:21 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
error_msg
==========
Purpose:
- print issue and return error code
*/
int    error_msg(char *issue)
{
    printf(RED "Error: " RESET "%s\n", issue);
    return (ERROR);
}


/* Test
int main()
{
    printf("%d\n", error_msg("get_time: fail gettimeofday"));
}
*/


