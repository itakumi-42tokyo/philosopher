/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutexs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-11 22:15:26 by tigarashi         #+#    #+#             */
/*   Updated: 2025-09-11 22:15:26 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include "philosophers.h"
#include "error_macro.h"
#include "utils.h"

static void	destroy_mutex(t_shared *share, int i)
{
	while (i > 0)
	{
		pthread_mutex_destroy(&(share->forks[i]));
		i--;
	}	
}

static int	check_ret(t_shared *share, int ret, int i)
{
	if (ret != 0)
	{
		if (ret == EINVAL)
			putendl_fd(MUTEX_INIT_EINIVAL_ERROR, STDERR_FILENO);
		else if (ret == ENOMEM)
			putendl_fd(MUTEX_INIT_ENOMEM_ERROR, STDERR_FILENO);
		else if (ret == EBUSY)
			putendl_fd(MUTEX_INIT_EBUSY_ERROR, STDERR_FILENO);
		else
			putendl_fd(UNKNOWN_ERROR, STDERR_FILENO);
		destroy_mutex(share, i);
		return (-1);
	}
	return (0);
}

int	init_mutexes(t_shared *share)
{
	int	i;
	int	ret;	

	i = 0;
	while (i < share->num_philos)
	{
		ret = pthread_mutex_init(&(share->forks[i]), NULL);
		if (check_ret(share, ret, i) == -1)
			return (-1);
		i++;
	}
	ret = pthread_mutex_init(&(share->print_mutex), NULL);
	if (check_ret(share, ret, i) == -1)
		return (-1);
	ret = pthread_mutex_init(&(share->state_mutex), NULL);
	if (check_ret(share, ret, i) == -1)
		return (pthread_mutex_destroy(&(share->print_mutex)), -1);
	return (0);
}