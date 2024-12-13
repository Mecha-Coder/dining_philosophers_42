#include "philo.h"

int main(int ac, char **av)
{
    t_data data;

    if (5 == ac || 6 == ac)
    {
        // 1) Check correct input, update data to global struct
        parse_input(&data, av);

        // 2) Initializing philo and fork struct
        initialize(&data);

        // 3) 
        start_simulaltion(&data);

        // 4) phile full | 1 philo die -> Free allocated memory
        clean_up(&data);
    }   
    else
        error_exit("Error: invalid argument count");
}