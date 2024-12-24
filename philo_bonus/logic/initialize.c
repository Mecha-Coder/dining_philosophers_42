/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:24:42 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/22 23:24:42 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void initialize(t_data *data, pid_t *philo_pid)
{
    data->meal_count = 0;
    data->eating = FALSE;
    data->philo_pid = philo_pid;

    sem_unlink("FORK");
    sem_unlink("PRINT");
    sem_init(&data->my_unsem, 0, 1);
    data->fork_sem = sem_open("FORK", O_CREAT , 0644, data->philo_no);
    data->print_sem = sem_open("PRINT",  O_CREAT , 0644, 1);
    
}

/*
void initialize(t_data *data, pid_t *philo_pid, sem_t **synchronizer)
{
    int i;            
    char sem_name[6];

    i = -1;
    data->meal_count = 0;
    data->eating = FALSE;
    data->philo_pid = philo_pid;

    sem_unlink("FORK");
    sem_unlink("PRINT");
    sem_init(&data->my_unsem, 0, 1);
    data->fork_sem = sem_open("FORK", O_CREAT , 0644, data->philo_no);
    data->print_sem = sem_open("PRINT",  O_CREAT , 0644, 1);
    
    sem_name[0] = 'S';
    sem_name[1] = '_';
    sem_name[5] = '\0';
    while (++i < data->philo_no)
    {
        sem_name[2] = (i / 100) + '0';
        sem_name[3] = (i / 10) %10 + '0'; 
        sem_name[4] = (i % 10) + '0';
        sem_unlink(sem_name);
        synchronizer[i] = sem_open(sem_name,  O_CREAT , 0644, 1);
    }
    sem_wait(synchronizer[data->philo_no - 1]);
    data->synchronizer_sem = synchronizer;
}
*/