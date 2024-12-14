#ifndef PHILO_H
#define PHILO_H

//=============================================================
// LIBRARY

#include <stdio.h>    // printf
#include <stdlib.h>   // malloc, free
#include <unistd.h>   // write, usleep
#include <stdbool.h>
#include <pthread.h>  // mutex  : init destroy lock unlock
                      // thread : create join detech
#include <sys/time.h> // gettimeofday
#include <limits.h>   // INT_MAX
#include <errno.h>

//=============================================================
// CONSTANT

#define RED   "\033[1;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"

//=============================================================
// ENUM

typedef enum e_action
{
    LOCK,
    UNLOCK,
    INIT,
    DESTROY,
    JOIN,
    DETECH,
    CREATE
} t_action;

//=============================================================
// STRUCT

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
    pthread_t   thread_id;      // Feed value to pthread_create
    long        meal_count;
    bool        done;           // reach optional meal count
    long        last_meat_time;
    t_fork      *l_fork;
    t_fork      *r_fork;

    t_data      *data;           // Linked to the main struct

}   t_philo;

struct s_data
{
    // Input argumrent data
    long    philo_no;
    long    time_to_die;
    long    time_to_eat;
    long    time_to_sleep;
    long    meal_limit;   // [number] || -1 unlimited || 0 simulation won;t start


    long    start_time;
    bool    end_simulation; // a philo die || all philo done = true
    
    t_fork  *fork;
    t_philo *philo;
};

//=============================================================
// PROTOPYPE


// LOGIC
void    parse_input(t_data *data, char **av);
void    initialize(t_data *data);

// UTILS
void    error_exit(char *s);




#endif