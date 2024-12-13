#include "philo.h"

/*
Input parameters

./philo  5  800  200  200  {50}
        [1] [2]  [3]  [4]   [5]

1) positive integer
    "    +77$%"  - valid
    "   +&%42"   - invalid

2) Not > INT MAX
    len > 10 is greater than > INT_MAX
    2,147,483,647 -> 9,999,999,999 

3) timestamps > 60 ms

4) 

Note: don't forget to show error message
*/
void    parse_input(t_data *data, char **av)
{

}