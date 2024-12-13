#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>    // printf
#include <stdlib.h>   // malloc, free
#include <unistd.h>   // write, usleep
#include <stdbool.h>
#include <pthread.h>  // mutex  : init destroy lock unlock
                      // thread : create join detech
#include <sys/time.h> // gettimeofday
#include <limits.h>   // INT_MAX

//=============================================================

void error_exit(char *s);


//=============================================================

typedef pthread_mutex_t t_mutex;
typedef struct s_data t_data;

typedef struct s_fork
{
    t_mutex fork;
    int     fork_id;
}   t_fork;


typedef struct s_philo
{
    int         id;
    pthread_t   thread_id;
    long        meal_count;
    bool        full;
    long        last_meat_time;
    t_fork      *l_fork;
    t_fork      *r_fork;
    t_data      *data;
}   t_philo;

struct s_data
{
    long    philo_no;
    long    time_to_die;
    long    time_to_eat;
    long    time_to_sleep;
    long    meal_limit;
    long    start_time;
    bool    end_simulation;
    t_fork  *fork;
    t_philo *philo;
};

#endif