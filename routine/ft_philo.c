/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 02:25:20 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/20 02:25:20 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void sleeping(t_philo *philo);
static void thinking(t_philo *philo);

void *ft_philo(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;

    if (philo->id % 2)
        wait(philo->get->eat_period / 2);
    while (!check_stop(philo->get))
    {
        eating(philo);
        sleeping(philo);
        thinking(philo);
    }
    return (NULL);
}

static void sleeping(t_philo *philo)
{
    print_log(philo, SLEEP);
    wait(philo->get->sleep_period);
}

static void thinking(t_philo *philo)
{
    print_log(philo, THINK);
}