/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:12:32 by tigarashi         #+#    #+#             */
/*   Updated: 2025/10/29 16:06:30 by itakumi          ###   ########.fr       */
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
