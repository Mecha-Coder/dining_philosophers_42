/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 01:28:20 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/23 01:28:20 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"


void *ft_monitor(void *arg)
{
    t_data *data;
    uint64_t time_elapse;

    data = (t_data *)arg;
    while (1)
    {
        sem_wait(&data->my_unsem);
        time_elapse = get_time() - data->last_meal_time;
        if (!data->eating && time_elapse >= data->die_period)
            break;
        sem_post(&data->my_unsem);
    }
    print_log(data, DIE);
    sem_wait(data->print_sem);
    exit_process(data, EXIT_FAILURE);
    return (NULL);
}