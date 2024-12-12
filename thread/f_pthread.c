#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h> // unsleep

void *print_world(void *arg)
{
    int i;

    (void)arg;
    i = 100;
    while (i--)
    {
        printf("\t\tWorld\n");
        // Too fast, can't simulate.  Need this 
        usleep(1000);
    }
    return (NULL);
}

void *print_hello(void *arg)
{
    int i;

    (void)arg;
    i = 100;
    while (i--)
    {
        printf("Hello");
        // Too fast, can't simulate.  Need this 
        usleep(900);
    }
    return (NULL);
}

void example2(void)
{
    pthread_t   t1;
    pthread_t   t2;

    if (pthread_create(&t1, NULL, print_hello, NULL))
        exit(1);
    if (pthread_create(&t2, NULL, print_world, NULL))
        exit(1);
    
    if (pthread_join(t1, NULL))
        exit(1);
    if (pthread_join(t2, NULL))
        exit(1);
}

void example1(void)
{
    print_hello(NULL);
    print_world(NULL);
}

void *routine(void *arg)
{
    int *num;
    int i;

    num = (int *)arg; // Cast void to desired type
    i = 0;
    while (i < 100000)
    {
        (*num)++;
        i++;
    }
    return (NULL);
}

void example3(void)
{
    int *num;
    pthread_t t1;
    pthread_t t2;

    num = malloc(sizeof(int));
    if(num == NULL)
        exit (1);
    
    *num = 0;
    if (pthread_create(&t1, NULL, routine, num))
        exit(1);
    if (pthread_create(&t2, NULL, routine, num))
        exit(1);

    if (pthread_join(t1, NULL))
        exit(1);
    if (pthread_join(t2, NULL))
        exit(1);

    printf("Num: %d\n", *num);
    free(num);

}

int main()
{
    example3();
}


