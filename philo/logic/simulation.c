/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 02:23:07 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/20 02:23:07 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
simulation
==========
- Clock the start time
- Immediately after that, create thread to reduce time error
- Assign the last_meal_time = start_time
- Lastly, join the threads back to main
*/
void simulation(t_data *data)
{
    pthread_t checker;
    int i;

    mutex(&data->start_key, LOCK);
    i = -1;
    while (++i < data->philo_no)
        thread(&data->philo[i].thread, ft_philo, &data->philo[i], CREATE);
    
    data->start_time = get_time();
    i = -1;
    while (++i < data->philo_no)
        data->philo[i].last_meal_time = data->start_time;

    thread(&checker, ft_monitor, data, CREATE);

    mutex(&data->start_key, UNLOCK);

    i = -1;
    while (++i < data->philo_no)
        thread(&data->philo[i].thread, NULL, NULL, JOIN);
    thread(&checker, NULL, NULL, JOIN);
}

