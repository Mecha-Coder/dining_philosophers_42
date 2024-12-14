#include <stdio.h>

int main()
{
    int i = 0;
    int philo_no = 6;

    while (++i <= philo_no)
    {
        printf("Philo_id : %d\n", i);
        printf("l_fork id: %d\n", i - 1);
        printf("r_fork id: %d\n", i % philo_no);

        printf("\n=============================\n");
    }
}