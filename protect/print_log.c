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

#define ALPHA "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz\n"

void *philo_routine(void *arg)
{
    t_philo *philo;
    int i = 10;

    philo = (t_philo *)arg;

    while (i--)
    {
        print_log(philo->id, ALPHA, philo->data);
        ft_usleep(100000);
    }
    return (NULL);
}


int init_philo(t_data *data)
{
    int i;
    t_philo *philo;

    philo = (t_philo *)malloc(sizeof(t_philo) * data->philo_no);
    if (philo == NULL)
        return (ERROR);
    
    i = -1;    
    while (++i < data->philo_no)
    {
        philo[i].id = i + 1;
        philo[i].data = data;
        if (pthread_create(&philo[i].thread, NULL, philo_routine, &philo[i]) != 0)
            return (error_msg("pthread_create"));
    }

    i = -1;
    while (++i < data->philo_no)
    {
        if (pthread_join(philo[i].thread, NULL))
            return (error_msg("pthread_join"));
    }
    
    return (TRUE);
}

int main()
{
    t_data data;

    pthread_mutex_init(&data.print_mutex, NULL);
    data.philo_no = 5;
    data.start_time = get_time();

    if (init_philo(&data) == ERROR)
        return (error_msg("init_philo"));

    pthread_mutex_destroy(&data.print_mutex);

}
