/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:57:19 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/12 19:43:53 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
Purpose: 
- Custom/improved version of usleep function
- WHY! usleep is not precise and timing differ from pc to pc
*/
void ft_usleep(uint64_t microsec)
{
    uint64_t start;

    start = get_time();
    while (get_time() - start < microsec)
        usleep(10);
}


int main()
{
    uint64_t start;
    uint64_t end;
    uint64_t set;
    
    set = 80000;
    start = get_time();
    // ft_usleep(set);
    usleep(set);
    end = get_time();

    printf("Set    : %ld microsec\n", set);
    printf("Actual : %ld microsec\n", end - start);
}
