/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 02:27:32 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/20 02:27:32 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void *ft_monitor(void *arg)
{
    t_data *data;

    data = (t_data *)arg;
    while (1)
        if (check_dead(data) || check_all_full(data))
            break;
    return (NULL);
}