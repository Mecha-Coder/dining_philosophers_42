/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:45:00 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/22 18:45:00 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

//===========================================================================
// LIBRARY

# include <fcntl.h>      // Macro: O_CREAT | O_EXCL
# include <stdio.h>      // printf
# include <unistd.h>     // write, fork, kill, usleep
# include <stdlib.h>     // exit
# include <pthread.h>    // create, detect, join
# include <sys/time.h>   // gettimeofday
# include <sys/wait.h>   // waitpid
# include <stdint.h>     // type: uin64_t
# include <limits.h>     // INT_MAX
# include <semaphore.h>  // sem_open, sem_close, sem_post, 
//                       // sem_wait, sem_unlink

//===========================================================================
// CONSTANT

# define MAX_PHILO 200

// Color code
# define RED   "\033[1;31m"
# define GREEN "\033[1;32m"
# define CYAN  "\033[0;36m"
# define RESET "\033[0m"

// Return state
# define TRUE 1
# define FALSE 0
# define ERROR -1

// Log message
# define TAKE "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"

// Used by thread & mutex util function
// Purpose: to make those function shorter
typedef enum e_code
{
    CREATE,
    DETACH,
} t_code;

//===========================================================================
// STRUCT

// All philo (process) gets a copy of this struct
// All common info are stored first
// After fork, update id to make it unique to each philo
typedef struct s_data
{
    // Philo unique info
    int         id;
    int         eating;
    int         meal_count;
    int         delay_me;
    uint64_t    last_meal_time;

    // Common info
    int         philo_no;
    int         meal_no;
    uint64_t    die_period;
    uint64_t    eat_period;
    uint64_t    sleep_period;
    uint64_t    start_time;

    // Unnamed semaphore (shared within process, thread protection)
    sem_t       my_unsem;

    // Named semaphore (shared between process)
    sem_t       **synchronizer_sem; // Not using
    sem_t       *fork_sem;
    sem_t       *print_sem; // Because dead_flag update within a process 
    //                      // To prevent others from printing before gets terminated
    //                      // Decrement print_sem to zero (block other processes this way)
    
    // pointer
    pid_t       *philo_pid;

} t_data;


//===========================================================================
// PROTOTYPE

// Logic
int         parse_input(t_data *data, int ac, char **av);
void        initialize(t_data *data, pid_t *philo_pid);
void        simulation(t_data *data);
void        print_log(t_data *data, char *task);
void        clean_up(t_data *data);

// Routine
void        philo_routine(t_data *data, int id);
void        *ft_monitor(void *arg);
void        exit_process(t_data *data, int status);
int         eating(t_data *data);
void        *ft_delay(void *arg);

// Utils
uint64_t    get_time(void);
void        ft_sleep(uint64_t millisec);
int         thread (pthread_t *t, void *(*f)(void *), void *arg, t_code code);
int	        ft_atoi(char *str);
int	        ft_strlen(char *str);

#endif