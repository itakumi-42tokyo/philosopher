/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:00:47 by itakumi           #+#    #+#             */
/*   Updated: 2025/11/12 21:46:01 by itakumi          ###   ########.fr       */
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

// static void	debug_print(t_philo *philo)
// {
// 	static pthread_mutex_t	print;
// 	pthread_mutex_lock(&print);
// 	printf("philo_id: %d\n", philo->id);
// 	pthread_mutex_unlock(&print);
// }

static void	loop_logic(t_philo *philo)
{
	long long	now;

	while (is_stopped(philo->share) == false)
	{
		if (take_forks(philo) == -1)
			break ;
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
		sleep_us_adaptive(500LL);
	}
}

void	*philosopher(void *arg)
{
	t_philo		*philo;

	if (arg == NULL)
		return (NULL);
	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
	{
		print_action(philo, THINKING_MSG);
		usleep(1000);
	}
	loop_logic(philo);
	return (NULL);
}

// now = now_ms();
// if (now == -1)
// 	return (-1);
// elapsed_time
// 	= now - philo->last_eat_ms;
// if (elapsed_time > philo->share->time_to_die)
// 	// 死亡
