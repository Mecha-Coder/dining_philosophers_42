/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 01:57:06 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/20 01:57:06 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void pick_fork(t_philo *philo);
static void begin_eating(t_philo *philo);
static void release_fork(t_philo *philo);

void eating(t_philo *philo)
{   

    pick_fork(philo);
    begin_eating(philo);
    release_fork(philo);
}

static void pick_fork(t_philo *philo)
{
    mutex(philo->r_fork, LOCK);
    print_log(philo, TAKE);
    mutex(philo->l_fork, LOCK);
    print_log(philo, TAKE);
}

static void begin_eating(t_philo *philo)
{
    print_log(philo, EAT);
    mutex(&philo->my_key, LOCK);
    philo->eating = TRUE;
    philo->last_meal_time = get_time();
    philo->meal_count++;
    mutex(&philo->my_key, UNLOCK);
    wait(philo->get->eat_period);
}

static void release_fork(t_philo *philo)
{
    mutex(&philo->my_key, LOCK);
    philo->eating = FALSE;
    mutex(&philo->my_key, UNLOCK);
    mutex(philo->r_fork, UNLOCK);
    mutex(philo->l_fork, UNLOCK);
}
