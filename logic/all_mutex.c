/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_mutex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 02:18:54 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/20 02:18:54 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void all_mutex(t_data *data, t_code code)
{
    int i;

    mutex(&data->write_key, code);
    mutex(&data->stop_key, code);
    i = -1;
    while (++i < data->philo_no)
        mutex(&data->fork[i], code);
    i = -1;
    while (++i < data->philo_no)
        mutex(&data->philo[i].my_key, code);
}
