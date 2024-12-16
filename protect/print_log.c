/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:24:12 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/16 17:27:37 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
print_log
==========
Purpose: print log the following format

- timestamp | philo_id  |  task
-     0          1          has taken fork
-    200         1          is sleeping
-    400         2          is thinking
-    600         3          is eating
-    600         5          died
*/
void print_log(uint64_t now, int id, int task, t_data *data)
{
    uint64_t time;

    time = (now - data->start_time) / 1000;
    do_mutex(&data->print_mutex, MUTEX_LOCK);
    if (task == LOG_TAKE)
        printf("%lu %d %s", time, id, "has taken fork\n");
    else if (task == LOG_EAT)
        printf("%lu %d %s", time, id, "is eating\n");
    else if (task == LOG_SLEEP)
        printf("%lu %d %s", time, id, "is sleeping\n");
    else if (task == LOG_THINK)
        printf("%lu %d %s", time, id, "is thinking\n");
    else if (task == LOG_DIE)
        printf("%lu %d %s", time, id, "died\n");
    do_mutex(&data->print_mutex, MUTEX_UNLOCK);
}

/*
void *philo_routine(void *arg)
{
    t_philo *philo;
    int i = 5;

    philo = (t_philo *)arg;
    while (!philo->data->start_time)
        i = 5;
    while (i--)
    {
        print_log(get_time(), philo->id, LOG_EAT, philo->data);
        ft_usleep(2000000);
    }
    return (NULL);
}

int main()
{
    t_data data;
    t_philo philo_1;
    t_philo philo_2;

    data.start_time = 0;
    do_mutex(&data.print_mutex, MUTEX_INIT);

    philo_1.id = 1;
    philo_2.id = 2;
    philo_1.data = &data;
    philo_2.data = &data;

    do_thread(&philo_1.thread, THREAD_CREATE, philo_routine, &philo_1);
    do_thread(&philo_2.thread, THREAD_CREATE, philo_routine, &philo_2);

    data.start_time = get_time();

    do_thread(&philo_1.thread, THREAD_JOIN, NULL, NULL);
    do_thread(&philo_2.thread, THREAD_JOIN, NULL, NULL);

    do_mutex(&data.print_mutex, MUTEX_DESTROY);
}
*/