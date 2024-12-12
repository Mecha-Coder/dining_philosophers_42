/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:25:54 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/12 18:48:56 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void    err_msg(char *s)
{
    int i;

    i = -1;
    write(2, "Error: ", 7);
    while (s && s[++i])
        write(2, &s[i], 1);
    write(2, "\n", 1);
}

/* 
int main()
{
     err_msg("get_time: failed gettimeofday()");
}
*/