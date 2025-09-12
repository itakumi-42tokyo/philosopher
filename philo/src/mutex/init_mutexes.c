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

static int	check_ret(int ret)
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
		return (-1);
	}
	return (0);
}

int	init_mutexes(t_basic_info *info)
{
	int	i;
	int	ret;	

	i = 0;
	info->initialized_mutexes = 0;
	while (i < info->the_number_of_philosophers)
	{
		ret = pthread_mutex_init(&(info->forks[i]), NULL);
		if (check_ret(ret) == -1)
		{
			while (i > 0)
			{
				pthread_mutex_destroy(&(info->forks[i]));
				i--;
			}
			return (-1);
		}
		info->initialized_mutexes++;
		i++;
	}
	return (0);
}