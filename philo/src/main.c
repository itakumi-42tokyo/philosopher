/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:07:11 by itakumi           #+#    #+#             */
/*   Updated: 2025/11/12 21:57:57 by itakumi          ###   ########.fr       */
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

static int	alloc_src(t_shared *sh, t_philo **ph, pthread_t **th, int n_philo)
{
	*ph = malloc(sizeof(t_philo) * n_philo);
	if (*ph == NULL)
		return (-5);
	sh->forks = malloc(sizeof(pthread_mutex_t) * n_philo);
	if (sh->forks == NULL)
	{
		free(*ph);
		return (-5);
	}
	*th = malloc(sizeof(pthread_t) * (n_philo + 1));
	if (*th == NULL)
	{
		free(*ph);
		free(sh->forks);
		return (-5);
	}
	return (0);
}

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
	check = alloc_src(&share, &philos, &threads, share.num_philos);
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
