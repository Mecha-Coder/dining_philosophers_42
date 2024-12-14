#include "../philo.h"

/*
./philo 5 800 200 200 [5]

0) If no meals, return ->[0]
1) If only one philo
2) Create a monitor thread, search death
3) Synchronice the beginnning of the simulation

    * pthread_create -> philo start running!
    * every philo start simultaneously
4) JOIN everyone
*/

void    simulation(t_data *data)
{
    int i;

    i = -1;
    if (data->meal_limit == 0)
        return ; // back to main, clean
    else if (data->philo_no == 1)
        ;
    else
    {
        // NOTE: after created thread wait until all created and run simultaneously
        while (++i < data->philo_no)
            safe_thread(&data->philo[i].thread_id, &data->philo[i], CREATE);
    }

    // start simulation
    data->start_time = get_time();

    // now all threads are ready
    set_bool
}