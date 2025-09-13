/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:07:11 by itakumi           #+#    #+#             */
/*   Updated: 2025/09/08 17:12:49 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include "parse.h"
#include "philosophers.h"
#include "thread.h"
#include "utils.h"
#include "mutex.h"
#include "monitor.h"
#include "error_macro.h"

// やはり，堅牢性を求めると出力系の関数にまで，手を加える必要が出てくるところが面倒
static int	alloc_philo_fork_thread(t_shared *share, t_philo **philos, pthread_t **threads, int num_philos)
{
	*philos = malloc(sizeof(t_philo) * num_philos);
	if (*philos == NULL)
		return (-5);
	share->forks = malloc(sizeof(pthread_mutex_t) * num_philos);
	if(share->forks == NULL)
	{
		free(*philos);
		return (-5);
	}
	*threads = malloc(sizeof(pthread_t) * (num_philos + 1));
	if (*threads == NULL)
	{
		free(*philos);
		free(share->forks);
		return (-5);
	}
	return (0);
}
// threadが必要なのは哲学者の数と，管理者１人？
// mutexが必要なのはフォークと出力用のミューテックス？

// info みたいにまとめて管理する必要を疑わなかったことが原因だ。
// 実行開始
// この処理を考える前に，どのようにして，forkを再現するかとか
// philosopherの処理手順を書く必要がある。

static void	join_thread_error_handle(int rtn)
{
	if (rtn == ESRCH)
		putendl_fd(ESRCH_ERROR, STDERR_FILENO);
	else if (rtn == EDEADLK)
		putendl_fd(EDEADLK_ERROR, STDERR_FILENO);
	else if (rtn == EINVAL)
		putendl_fd(EINIVAL_ERROR, STDERR_FILENO);
	else
		putendl_fd(UNKNOWN_ERROR, STDERR_FILENO);
}

static void	join_thread(pthread_t *threads, t_shared *share)
{
	int	i;
	int	rtn;

	i = 0;
	while (i < share->num_philos + 1)
	{
		rtn = pthread_join(threads[i], NULL);
		if (rtn != 0)
			join_thread_error_handle(rtn);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_shared	share;
	t_philo		*philos;
	pthread_t	*threads;
	t_monitor	monitor;
	int			check;

	philos = NULL;
	threads = NULL;
	check = parse_args(argc, argv, &share);
	if (check != 0)
		error_exit(check);
	// init_all(&share);
	check = alloc_philo_fork_thread(&share, &philos, &threads, share.num_philos);
	if (check != 0)
		error_exit(check);
	if (init_mutexes(&share) == -1)
		return (free_all(&share, philos, threads), EXIT_FAILURE);
	init_philos(philos, &share);
	init_monitor(&monitor, philos, &share);
	if (create_threads(philos, threads, &monitor) == -1)
		return (free_all(&share, philos, threads), EXIT_FAILURE);
	join_thread(threads, &share);
	free_all(&share, philos, threads);
	return (EXIT_SUCCESS);
}
