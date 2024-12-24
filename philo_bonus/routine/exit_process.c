/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 01:27:45 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/23 01:27:45 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void exit_process(t_data *data, int status)
{
    sem_close(&data->my_unsem);
    sem_close(data->fork_sem);
    sem_close(data->print_sem);
    exit(status);
}

/*
void exit_process(t_data *data, int status)
{
    int i;            

    i = -1;
  
    while (++i < data->philo_no)
        sem_close(data->synchronizer_sem[i]);
    sem_close(&data->my_unsem);
    sem_close(data->fork_sem);
    sem_close(data->print_sem);
    exit(status);
}
*/