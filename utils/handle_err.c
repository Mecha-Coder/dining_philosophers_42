/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:25:54 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/16 15:36:14 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/* 
check_error
===========
Purpose:
- Check if function like pthread or gettimeofday return none-zero value
- If yes, respond by printing error message and exist program
*/
void    check_error(char *issue, int result)
{
    if (result != 0)
        error_exit(issue);
}

/*
error_exit
==========
Purpose:
- print issue and exit program
*/
void    error_exit(char *issue)
{
    printf(RED "Error: " RESET "%s\n", issue);
    exit (EXIT_FAILURE);
}


/* Test
=========
int main()
{
    err_exit("get_time", "fail gettimeofday");
}
*/

