/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:16:09 by itakumi           #+#    #+#             */
/*   Updated: 2025/09/08 17:03:19 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

typedef enum e_state
{
	TAKING_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED
}	t_state;

// philosophersを共有するのは，危険かな
// そもそも，共有する資源でもない？
typedef struct s_shared
{
	int				num_philos;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				required_eat_count;
	long long		start_at_ms;
	volatile int	stop_flag;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	state_mutex;
}	t_shared;

// 食事回数がオーバーフローする可能性がある
typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	long long		last_eat_ms;
	int				eat_count;
	t_shared		*share;
}	t_philo;

typedef struct s_monitor
{
	t_philo		*philos;
	t_shared	*share;
}	t_monitor;

// forkの状態はナンバリングして，bool値で管理するのが良いかな？
// typedef struct s_basic_info
// {
// 	pthread_t		*threads;
// 	pthread_mutex_t	*forks;
// 	pthread_mutex_t	print_action;
// 	t_philo			*philosophers;
// }	t_basic_info;

void	*philosopher(void *arg);
void	init_philos(t_philo *philos, t_shared *share);

#endif
