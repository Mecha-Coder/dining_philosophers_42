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
Purpose: print log with following format

- timestamp | philo_id  |  task
-     0          1          has taken fork
-    200         1          is sleeping
-    400         2          is thinking
-    600         3          is eating
-    600         5          died
*/
void print_log(int id, char *task, t_data *data)
{
    uint64_t time;

    time = (get_time() - data->start_time) / 1000;
    
    pthread_mutex_lock(&data->print_mutex);
    printf("%lu %d %s", time, id, task);
    pthread_mutex_lock(&data->print_mutex);
}

/* */
void *philo_routine(void *arg)
{
    t_philo *philo;
    int i = 10;

    philo = (t_philo *)arg;

    while (i--)
    {
        print_log(philo->id, LOG_EAT, philo->data);
        ft_usleep(2000000);
    }
    return (NULL);
}

int main()
{
    t_data data;
    t_philo philo_1;
    t_philo philo_2;

    data.start_time = get_time();
    
    if (pthread_mutex_init(&data.print_mutex, NULL))
        return ()

    philo_1.id = 1;
    philo_2.id = 2;
    philo_1.data = &data;
    philo_2.data = &data;

    pthread_create(&philo_1.thread, NULL, philo_routine, &philo_1);
    pthread_create(&philo_2.thread, NULL, philo_routine, &philo_2);


    do_thread(&philo_1.thread, THREAD_JOIN, NULL, NULL);
    do_thread(&philo_2.thread, THREAD_JOIN, NULL, NULL);

    do_mutex(&data.print_mutex, MUTEX_DESTROY);
}
