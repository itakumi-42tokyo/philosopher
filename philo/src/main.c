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
#include "parse.h"
#include "philosophers.h"
#include "thread.h"
#include "utils.h"
#include "mutex.h"
#include "monitor.h"

// やはり，堅牢性を求めると出力系の関数にまで，手を加える必要が出てくるところが面倒
static int	alloc_philo_fork_thread(t_shared *share, t_philo *philos, pthread_t threads, int num_philos)
{
	philos = malloc(sizeof(t_philo) * num_philos);
	if (philos == NULL)
		return (-5);
	share->forks = malloc(sizeof(pthread_mutex_t) * num_philos);
	if(share->forks == NULL)
	{
		free(philos);
		return (-5);
	}
	threads = malloc(sizeof(pthread_t) * num_philos + 1);
	if (threads == NULL)
	{
		free(philos);
		free(share->forks);
		return (-5);
	}
	return (0);
}
// threadが必要なのは哲学者の数と，管理者１人？
// mutexが必要なのはフォークと出力用のミューテックス？

// info みたいにまとめて管理する必要を疑わなかったことが原因だ。
int	main(int argc, char **argv)
{
	t_shared	share;
	t_philo		*philos;
	pthread_t	*threads;
	t_monitor	*monitor;
	int			check;

	check = parse_args(argc, argv, &share);
	if (check != 0)
		error_exit(check);
	init_all(&share);
	check = alloc_philo_fork_thread(&share, philos, threads, share.num_philos);
	if (check != 0)
		error_exit(check);
	if (init_mutexes(&share) == -1)
		return (free_all(&share), EXIT_FAILURE);
	init_philos(&share);
	init_monitor(&monitor, philos, &share);
	if (create_threads(&share, threads) == -1)
		return (free_all(&share), EXIT_FAILURE);
	// 実行開始
	// この処理を考える前に，どのようにして，forkを再現するかとか
	// philosopherの処理手順を書く必要がある。
	return (EXIT_SUCCESS);
}
