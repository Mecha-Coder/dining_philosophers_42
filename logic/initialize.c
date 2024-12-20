/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 02:21:26 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/20 02:21:26 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void init_philo(t_data *data);

void initialize(t_data *data, t_philo *philo_l, t_mutex *fork_l)
{
    data->philo = philo_l;
    data->fork = fork_l;
    data->stop_flag = FALSE;

    all_mutex(data, INIT);
    init_philo(data);
}

static void init_philo(t_data *data)
{
    int i;

    i = -1;
    while (++i < data->philo_no)
    {
        data->philo[i].id = i + 1;
        data->philo[i].eating = FALSE;
        data->philo[i].meal_count = 0;
        data->philo[i].r_fork = &data->fork[i];
        data->philo[i].l_fork = &data->fork[(i + 1) % data->philo_no];
        data->philo[i].get = data;
    }
}
