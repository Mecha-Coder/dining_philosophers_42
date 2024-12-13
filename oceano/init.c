#include "philo.h"

void *safe_malloc(size)
{
    
}

void safe_mutex_handle(t_mutex *mutex, int action)
{
    if (1 == action)
        pthread_mutex_lock(mutex);
    else if (2 == action)
        pthread_mutex_unlock(mutex);
    else if (3 == action)
        pthread_mutex_init(mutex, NULL);
    else if (4 == action)
        pthread_mutex_destroy(mutex);
    else
        error_exit("Wrong action received");

}

void initialize(t_data *data)
{
    data->end_simulation = false;
    data->philo = safe_malloc(data->philo_no * sizeof(t_philo));
    data->fork = safe_malloc(data->philo_no * sizeof(t_philo));

    while (++i < data->philo_no)
    {
        safe_mutex_handle(data->fork[i].fork, );
    }
}