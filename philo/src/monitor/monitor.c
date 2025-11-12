/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:47:15 by itakumi           #+#    #+#             */
/*   Updated: 2025/11/12 22:03:35 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <pthread.h>

#include "philosophers.h"
#include "utils.h"
#include "error_macro.h"
#include "timestamp.h"
#include "thread.h"

static void	init_var(int *i, int *clear_philo_n)
{
	*i = 0;
	*clear_philo_n = 0;
}

static bool	check_clear(t_monitor *monitor, int i)
{
	if (monitor->share->required_eat_count > 0
		&& (monitor->philos[i]).eat_count >= monitor->share->required_eat_count)
		return (true);
	return (false);
}

static int	check_each_philo(t_monitor *monitor)
{
	int			i;
	int			clear_philo_n;
	long long	now;
	long long	diff;

	init_var(&i, &clear_philo_n);
	while (i < monitor->share->num_philos && monitor->share->stop_flag == false)
	{
		now = now_ms();
		pthread_mutex_lock(&(monitor->share->state_mutex));
		diff = now - monitor->philos[i].last_eat_ms;
		if (diff > monitor->share->time_to_die)
		{
			pthread_mutex_unlock(&(monitor->share->state_mutex));
			print_action2(&(monitor->philos[i]), DIED_MSG, now);
			mark_stop(monitor->share);
			return (-1);
		}
		pthread_mutex_unlock(&(monitor->share->state_mutex));
		pthread_mutex_lock(&((monitor->share->state_mutex)));
		if (check_clear(monitor, i++) == true)
			clear_philo_n++;
		pthread_mutex_unlock(&(monitor->share->state_mutex));
	}
	return (clear_philo_n);
}

void	*monitor(void *arg)
{
	t_monitor	*monitor;
	int			clear_philo_n;

	if (arg == NULL)
		return (NULL);
	monitor = (t_monitor *)arg;
	clear_philo_n = 0;
	while (monitor->share->stop_flag == false)
	{
		clear_philo_n = check_each_philo(monitor);
		if (clear_philo_n >= monitor->share->num_philos)
			mark_stop(monitor->share);
		else if (clear_philo_n == -1)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

// void	admin(t_shared *share, t_philo *philos)
// {
// 	long long		now;
// 	long long		elapsed_time;
// 	int				eated_count;

// 	eated_count = 0;

// }

// while (1)
// {
// if (share->required_eat_count == eated_count)
// exit(0);
// now = now_ms();
// if (now == -1)
// putendl_fd(GETTIMEOFDAY_ERROR, STDERR_FILENO);
// elapsed_time
// = now - philos[0].last_eat_ms;
// if (elapsed_time > share->time_to_die)// 単位はmsでそろっているはず。
// put_timestamp(DIED, 1);
// sleep_ms_adaptive(1LL);
// }
