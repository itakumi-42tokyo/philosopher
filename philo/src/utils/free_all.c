/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-11 21:12:32 by tigarashi         #+#    #+#             */
/*   Updated: 2025-09-11 21:12:32 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include "philosophers.h"

// mutexがあるかどうかを確認するスイッチは必要だろうか？
// エラーを出すとわかっているのにその関数を使うのはナンセンス？

void	free_all(t_shared *shared, t_philo *philos, pthread_t *threads)
{
	int	i;

	i = 0;
	if (shared == NULL)
		return ;
	while (i < shared->num_philos)
	{
		pthread_mutex_destroy(&(shared->forks[i]));
		i++;
	}
	free(philos);
	philos = NULL;
	free(shared->forks);
	shared->forks = NULL;
	free(threads);
	threads = NULL;
}