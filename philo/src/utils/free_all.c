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
#include "philosophers.h"

// mutexがあるかどうかを確認するスイッチは必要だろうか？
// エラーを出すとわかっているのにその関数を使うのはナンセンス？

void	free_all(t_basic_info *info)
{
	int	i;

	i = 0;
	if (info == NULL)
		return ;
	while (i < info->the_number_of_philosophers)
	{
		pthread_mutex_destroy(&(info->forks[i]));
		i++;
	}
	free(info->philosophers);
	free(info->forks);
	free(info->threads);
}