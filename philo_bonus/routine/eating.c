/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:10:39 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/23 10:10:39 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

static void pick_fork(t_data *data);
static void begin_eating(t_data *data);
static int release_fork(t_data *data);
//static void synchorize_eating(t_data *data);

int eating(t_data *data)
{
    pick_fork(data);
    begin_eating(data);
    return (release_fork(data));
}

static void pick_fork(t_data *data)
{
    sem_wait(data->fork_sem);
    print_log(data, TAKE);
    
    if (data->philo_no == 1)
        ft_sleep(data->die_period + 10);

    sem_wait(data->fork_sem);
    print_log(data, TAKE);
}

static void begin_eating(t_data *data)
{
    print_log(data, EAT);

    sem_wait(&data->my_unsem);
    data->eating = TRUE;
    data->meal_count++;
    data->last_meal_time = get_time();
    sem_post(&data->my_unsem);

    ft_sleep(data->eat_period);
}

static int release_fork(t_data *data)
{
    int state;

    state = FALSE;
    sem_wait(&data->my_unsem);
    data->eating = FALSE;
    if (data->meal_no != -1 && data->meal_no == data->meal_count)
        state = TRUE;
    sem_post(&data->my_unsem);

    sem_post(data->fork_sem);
    sem_post(data->fork_sem);
    return (state);
}

/*
static void synchorize_eating(t_data *data)
{
    pthread_t delay_checker;

    sem_wait(&data->my_unsem);
    data->delay_me = TRUE;
    sem_post(&data->my_unsem);

    thread(&delay_checker, ft_delay, data, CREATE);
    thread(&delay_checker, NULL, NULL, DETACH);

    sem_wait(data->synchronizer_sem[data->id - 1]);
    sem_wait(&data->my_unsem);
    data->delay_me = FALSE;
    sem_post(&data->my_unsem);
    sem_post(data->synchronizer_sem[data->id - 1]);
}
*/