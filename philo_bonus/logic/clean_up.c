/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:06:43 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/23 11:06:43 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void clean_up(t_data *data)
{
    sem_close(data->fork_sem);
    sem_close(data->print_sem);

    sem_unlink("FORK");
    sem_unlink("PRINT");
}

/*
void clean_up(t_data *data)
{
    int i;            
    char sem_name[6];

    i = -1;
    sem_close(data->fork_sem);
    sem_close(data->print_sem);

    sem_unlink("FORK");
    sem_unlink("PRINT");

    sem_name[0] = 'S';
    sem_name[1] = '_';
    sem_name[5] = '\0';
    while (++i < data->philo_no)
    {
        sem_name[2] = (i / 100) + '0';
        sem_name[3] = (i / 10) %10 + '0'; 
        sem_name[4] = (i % 10) + '0';
        sem_close(data->synchronizer_sem[i]);
        sem_unlink(sem_name);
    }
}
*/