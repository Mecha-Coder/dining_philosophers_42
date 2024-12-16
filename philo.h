/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:48:32 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/16 17:07:10 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// =====================================================================
// CONSTANT

// >> Color code
# define RED   "\033[1;31m"
# define GREEN "\033[1;32m"
# define CYAN  "\033[0;36m"
# define RESET "\033[0m"

// >> Log message
# define LOG_TAKE 0
# define LOG_EAT 1
# define LOG_SLEEP 2
# define LOG_THINK 3
# define LOG_DIE 4

// >> Mutex flow
# define MUTEX_INIT 0
# define MUTEX_LOCK 1
# define MUTEX_UNLOCK 2
# define MUTEX_DESTROY 3

// >> Thread flow
# define THREAD_CREATE 0
# define THREAD_JOIN 1

// =====================================================================
// LIBRARY

# include <stdio.h>    // printf
# include <stdlib.h>   // malloc, free
# include <unistd.h>   // write, usleep
# include <stdbool.h>
# include <pthread.h>  // mutex  : init destroy lock unlock
//                     // thread : create join
# include <sys/time.h> // gettimeofday
# include <limits.h>   // INT_MAX
# include <errno.h>    // read pthread & mutex error
# include <stdint.h>   // uin64_t

// Remove
# include <string.h>

// =====================================================================
// STRUCT

typedef pthread_mutex_t	t_mutex;

typedef struct s_data
{
	uint64_t	start_time;
	t_mutex		print_mutex;
}	t_data;

typedef struct s_philo
{
	int			id;
	pthread_t	thread;
	t_data		*data;
}	t_philo;

// =====================================================================
// PROTOPYPE

// >>> Protect
void		print_log(uint64_t now, int id, int task, t_data *data);

// >>> Utils
void		do_thread(pthread_t *t, int action, void *(*f)(void *), void *data);
void		do_mutex(t_mutex *m, int action);
void		check_error(char *issue, int result);
void		ft_usleep(uint64_t millisec);
void		error_exit(char *issue);

uint64_t	get_time(void);

#endif
