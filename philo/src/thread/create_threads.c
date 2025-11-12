/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_th.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 23:14:02 by tigarashi         #+#    #+#             */
/*   Updated: 2025/11/12 21:20:01 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "philosophers.h"
#include "error_macro.h"
#include "monitor.h"
#include "utils.h"

static int	check_ret(int ret)
{
	if (ret != 0)
	{
		if (ret == EAGAIN)
			putendl_fd(THREAD_CREATE_EAGAIN_ERROR, STDERR_FILENO);
		else if (ret == EINVAL)
			putendl_fd(THREAD_CREATE_EINVAL_ERROR, STDERR_FILENO);
		else if (ret == EPERM)
			putendl_fd(THREAD_CREATE_EPERM_ERROR, STDERR_FILENO);
		else
			putendl_fd(UNKNOWN_ERROR, STDERR_FILENO);
		return (-1);
	}
	return (0);
}

int	create_threads\
(t_philo *philo_s, pthread_t *th, t_monitor *monitor_s)
{
	int	i;
	int	ret;

	ret = \
	pthread_create(&(th[philo_s->share->num_philos]), NULL, monitor, monitor_s);
	if (check_ret(ret) == -1)
		return (-1);
	i = 0;
	while (i < philo_s->share->num_philos)
	{
		ret = pthread_create(&(th[i]), NULL, philosopher, &(philo_s[i]));
		if (check_ret(ret) == -1)
		{
			philo_s->share->stop_flag = true;
			while (i > 0)
			{
				pthread_join(th[i], NULL);
				i--;
			}
			return (-1);
		}
		i++;
	}
	return (0);
}
