/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:50:00 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/16 16:52:01 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	do_thread(pthread_t *t, int action, void *(*f)(void *), void *data)
{
	if (action == THREAD_CREATE)
		check_error("pthread_create", pthread_create(t, NULL, f, data));
	else if (action == THREAD_JOIN)
		check_error("pthread_join", pthread_join(*t, NULL));
}
