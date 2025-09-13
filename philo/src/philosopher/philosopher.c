/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:00:47 by itakumi           #+#    #+#             */
/*   Updated: 2025/09/08 17:20:58 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include "philosophers.h"
#include "error_macro.h"
#include "utils.h"
#include "timestamp.h"
#include "thread.h"

static void	mark_stop(t_shared *share)
{
	pthread_mutex_lock(&(share->state_mutex));
	share->stop_flag = 1;
	pthread_mutex_unlock(&(share->state_mutex));
}

// static void	debug_print(t_philo *philo)
// {
// 	static pthread_mutex_t	print;
// 	pthread_mutex_lock(&print);
// 	printf("philo_id: %d\n", philo->id);
// 	pthread_mutex_unlock(&print);
// }

//1. 美しくするにはcreate_threadの完了を待つまで，哲学者をeatingさせる。
//2. 完了したら，last_eat_msを更新し，はじめに，print_actionするようにする。
// 3. ？？

void	*philosopher(void *arg)
{
	t_philo		*philo;
	long long	now;

	if (arg == NULL)
		return (NULL);
	philo = (t_philo *)arg;
	if (philo->id % 2 == 1 || philo->id == philo->share->num_philos - 1)// 偶奇の重要な部分
	{
		print_action(philo, THINKING_MSG); // 5人の時thinkingが表示されなくなってしまった。
		usleep(1000);
	}
	while (is_stopped(philo->share) == false)
	{
		if (take_forks(philo) == -1)
			break ;// 哲学者が１人の場合は死ぬまで処理を続ける必要がある。
		now = now_ms();
		if (now < 0)
			mark_stop(philo->share);
		else
		{
			pthread_mutex_lock(&(philo->share->state_mutex));
			philo->last_eat_ms = now;
			pthread_mutex_unlock(&(philo->share->state_mutex));
		}	
		print_action(philo, EATING_MSG);
		sleep_ms_adaptive(philo->share->time_to_eat);
		philo->eat_count++;
		put_forks(philo);
		print_action(philo, SLEEPING_MSG);
		sleep_ms_adaptive(philo->share->time_to_sleep);
		print_action(philo, THINKING_MSG);
	}
	return (NULL);
}

// now = now_ms();
// if (now == -1)
// 	return (-1);
// elapsed_time
// 	= now - philo->last_eat_ms;
// if (elapsed_time > philo->share->time_to_die)
// 	// 死亡