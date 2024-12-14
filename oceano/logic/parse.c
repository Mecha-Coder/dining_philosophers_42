#include "../philo.h"

static ft_atol(char *s);
static char *valid_input(char *s);
static inline is_space(char c);
static inline is_digit(char c);

/*
Input parameters

./philo  5  800  200  200  {50}
av      [1] [2]  [3]  [4]   [5]

1) Not > INT MAX
    len > 10 is greater than > INT_MAX
    2,147,483,647 -> 9,999,999,999 

2) positive integer
    "    +77$%"  - valid
    "   +&%42"   - invalid

3) timestamps > 60 ms

4) 

Note: don't forget to show error message
*/

void    parse_input(t_data *data, char **av)
{
    data->philo_no = ft_atol(av[1]);
    data->time_to_die = ft_atol(av[2]) * 1000;
    data->time_to_eat = ft_atol(av[3]) * 1000;
    data->time_to_sleep = ft_atol(av[4]) * 1000;
    if (data->time_to_die < 60000
        || data->time_to_eat < 60000
        || data->time_to_sleep < 60000)
        error_exit("time must be more than 60 milliseconds");
    if (av[5])
        data->meal_limit = ft_atol(av[5]);
    else
        data->meal_limit = -1;
}

static ft_atol(char *s)
{
    long num;

    s = valid_input(s);
    while (is_digit(*s))
        num = (num * 10) + (*s++ - '0');
    if (num > INT_MAX)
        error_exit("check_input: number greater than INT_MAX");
}

/*
1) check for negative
2) check if a legit number
3) check for INT_MAX
*/
static char *valid_input(char *s)
{
    int len;
    char *number;

    len = 0;
    while (is_space(*s))
        s++;
    if (*s == '+')
        s++;
    else if (*s == '-')
        error_exit("check_input: negative number");
    if (!is_digit(*s))
        error_exit("check_input: not a number");
    number = s;
    while (is_digit(*s++))
        len++;
    if (len > 10)
        error_exit("check_input: number greater than INT_MAX");
    return (number);
}

/*
\t 9
\n 10
\v 11
\f 12
\r 13
(space): 32
*/
static inline is_space(char c)
{
    return ((c >= 9 && c <= 13) || c == 32);
}

static inline is_digit(char c)
{
    return (c >= '0' && c <= '9');
}
