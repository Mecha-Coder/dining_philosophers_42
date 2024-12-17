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
# define TAKE "has taken fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"

// >> Return state
#define TRUE 1
#define FALSE 0
#define ERROR -1

// =====================================================================
// LIBRARY

# include <stdio.h>    // printf
# include <stdlib.h>   // malloc, free
# include <unistd.h>   // write, usleep
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
typedef struct s_data t_data;

typedef struct s_philo
{
	int			id;
	pthread_t	thread;
	t_data		*data;
}	t_philo;


struct s_data
{
	int			philo_no;
	uint64_t	start_time;
	t_mutex		print_mutex;
	t_philo		*philo_l;
};


// =====================================================================
// PROTOPYPE

// >>> Protect
void 		print_log(int id, char *task, t_data *data);

// >>> Utils
void		ft_usleep(uint64_t millisec);
int			error_msg(char *issue);
uint64_t	get_time(void);

#endif
