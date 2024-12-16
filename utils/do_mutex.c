/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_mutex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:50:00 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/16 16:52:21 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void do_mutex(t_mutex *m, int action)
{
    if (action == MUTEX_INIT)
        check_error("mutex_init", pthread_mutex_init(m, NULL));
    else if (action == MUTEX_LOCK)
        check_error("mutex_lock", pthread_mutex_lock(m));
    else if (action == MUTEX_UNLOCK)
        check_error("mutex_unlock", pthread_mutex_unlock(m));
    else if (action == MUTEX_DESTROY)
        check_error("mutex_destroy", pthread_mutex_destroy(m));
}
