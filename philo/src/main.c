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

// やはり，堅牢性を求めると出力系の関数にまで，手を加える必要が出てくるところが面倒
static int	alloc_philo_fork_thread(t_basic_info *info, int the_number_of_philo)
{
	info->philosophers = malloc(sizeof(t_philo) * the_number_of_philo);
	if (info->philosophers == NULL)
		return (-5);
	info->forks = malloc(sizeof(pthread_mutex_t) * the_number_of_philo);
	if(info->forks == NULL)
	{
		free(info->philosophers);
		return (-5);
	}
	info->threads = malloc(sizeof(pthread_t) * the_number_of_philo + 1);
	if (info->threads == NULL)
	{
		free(info->philosophers);
		free(info->forks);
		return (-5);
	}
	return (0);
}
// threadが必要なのは哲学者の数と，管理者１人？
// mutexが必要なのはフォークと出力用のミューテックス？

// DB: philo(malloc)
int	main(int argc, char **argv)
{
	t_basic_info	info;
	int				check;

	check = parse_args(argc, argv, &info);
	if (check != 0)
		error_exit(check);
	check = alloc_philo_fork_thread(&info, info.the_number_of_philosophers);
	if (check != 0)
		error_exit(check);
	init_philos(&info);
	if (init_mutexes(&info) == -1)
		return (free_all(&info), EXIT_FAILURE);
	if (create_threads(&info) == -1)
		return (free_all(&info), EXIT_FAILURE);
	return (0);
}
