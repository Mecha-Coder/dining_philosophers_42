/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:45:15 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/22 23:45:15 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

static void fork_philo(t_data *data);
static void check_return_status(t_data *data);
static void kill_all(t_data *data);

void simulation(t_data *data)
{
   fork_philo(data);
   sem_close(&data->my_unsem);
   check_return_status(data);
}

static void fork_philo(t_data *data)
{
    int i;
    
    i = -1;
    data->start_time = get_time();
    data->last_meal_time = data->start_time;
    while (++i < data->philo_no)
    {
        data->philo_pid[i] = fork();
        if (data->philo_pid[i] == 0)
            philo_routine(data, i + 1);
    }
}

static void check_return_status(t_data *data)
{
    int i;
    int status;
    
    i = -1;
    while(++i < data->philo_no)
    {
        wait(&status);
        if (WEXITSTATUS(status) == 1)
        {
            kill_all(data);
            break ;
        }
    }
    i = -1;
    while(++i < data->philo_no)
        waitpid(data->philo_pid[i], NULL, 0);
}


static void kill_all(t_data *data)
{
    int i;
    
    i = -1;
    while (++i < data->philo_no)
        kill(data->philo_pid[i], SIGTERM);
}