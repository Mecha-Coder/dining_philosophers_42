#include "../philo.h"

void error_exit(char *s)
{
    printf(RED "%s\n" RESET, s);
    exit (EXIT_FAILURE);
}