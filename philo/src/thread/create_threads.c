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
#include "philosophers.h"
#include "error_macro.h"

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
int	create_threads(t_basic_info *info)
{
	int	i;
	int	ret;

	i = 0;
	info->threads = malloc(sizeof(pthread_t) * info->the_number_of_philosophers);
	if (info->threads == NULL)
		return (putendl_fd(MALLOC_ERROR, STDERR_FILENO), -1);
	while (i < info->the_number_of_philosophers)
	{
		ret = thread_create(&(info->threads[i]), NULL, philosopher, info); // 一旦，info
		if (check_ret(ret) == -1)
		{
			info->stop_flag = true;
			while (i > 0)
			{
				thread_join(info->threads[i], NULL);
				i++;
			}
			return (-1);
		}
		i++;
	}
}