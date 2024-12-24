/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:13:56 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/23 17:13:56 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

/*
Keep, but no using this function
*/
void *ft_delay(void *arg)
{
    t_data *data;

    data = (t_data *)arg;

    ft_sleep(data->eat_period / 2);

    sem_wait(&data->my_unsem);
    if (data->delay_me == TRUE)
    {
        sem_post(data->synchronizer_sem[data->id - 1]);
        if (data->id - 1 == 0)
            sem_wait(data->synchronizer_sem[data->philo_no - 1]);
        else
            sem_wait(data->synchronizer_sem[data->id - 2]);
    }
    sem_post(&data->my_unsem);
    return (NULL);
}