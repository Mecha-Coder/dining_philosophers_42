#include "philo.h"

int main()
{
    t_data data;
    t_philo philo_l[MAX_PHILO];
    t_mutex fork_l[MAX_PHILO];

    parse_input(&data);
    initialize(&data, philo_l, fork_l);
    simulation(&data);
    all_mutex(&data, DESTROY);
}

