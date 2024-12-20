/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 02:19:44 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/20 02:19:44 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void parse_input(t_data *data)
{
    data->philo_no = 4;
    data->die_period = 450;
    data->eat_period = 200;
    data->sleep_period = 200;
    data->meal_no = ERROR;
}