/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:57:19 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/16 15:37:52 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
Purpose: 
- Custom/improved version of usleep function
- WHY! usleep is not precise and timing differ from pc to pc
- Best performance usleep(10)
*/
void ft_usleep(uint64_t microsec)
{
    uint64_t start;

    start = get_time();
    while (get_time() - start < microsec)
        usleep(10);
}

/*
int main()
{
    int i = 30;
    uint64_t start;
    uint64_t end;
    int set;
    
    set = 20000;
    while (i--)
    {
        start = get_time();
        ft_usleep(set);
        end = get_time();
        printf("%lu\n", end - start);
    }
}
*/