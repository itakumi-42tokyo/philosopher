/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-11 23:14:02 by tigarashi         #+#    #+#             */
/*   Updated: 2025-09-11 23:14:02 by tigarashi        ###   ########.fr       */
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


// 管理者用スレッドはどのような別変数にしたほうがよさそうかな？
// 本当はエラーメッセージ用関数を設計したほうがよさそう。だけど，今回はいいや，
int	create_threads(t_philo *philo_resource, pthread_t *threads, t_monitor *monitor_resource)
{
	int	i;
	int	ret;

	ret = pthread_create(&(threads[philo_resource->share->num_philos]), NULL, monitor, (void *)monitor_resource);
	if (check_ret(ret) == -1)
		return (-1);
	i = 0;
	while (i < philo_resource->share->num_philos)
	{
		ret = pthread_create(&(threads[i]), NULL, philosopher, &(philo_resource[i])); // 一旦，info
		if (check_ret(ret) == -1)
		{
			philo_resource->share->stop_flag = true;
			while (i > 0)
			{
				pthread_join(threads[i], NULL);
				i--;
			}
			return (-1);
		}
		i++;
	}
	return (0);
}