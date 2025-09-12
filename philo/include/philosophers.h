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

// 食事回数がオーバーフローする可能性がある
typedef struct s_philo
{
	int				id;
	t_state			state;
	struct timeval	last_eat;
	int				eat_count;
}	t_philo;

// forkの状態はナンバリングして，bool値で管理するのが良いかな？
typedef struct s_basic_info
{
	int				the_number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				required_eat_count;
	bool			stop_flag;
	int				initialized_mutexes;
	int				created_threads;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_action;
	t_philo			*philosophers;
}	t_basic_info;

void	*philosopher(void *arg);
void	init_philos(t_basic_info *info);

#endif
