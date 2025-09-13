/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-12 07:24:29 by tigarashi         #+#    #+#             */
/*   Updated: 2025-09-12 07:24:29 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include "philosophers.h"
#include "utils.h"
#include "timestamp.h"
#include "thread.h"

int	take_forks(t_philo *philo)
{
	int	a;
	int	b;
	int	tmp;

	a = philo->left_fork;
	b = philo->right_fork;
	if (a > b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	pthread_mutex_lock(&(philo)->share->forks[a]);
	print_action(philo, TAKING_FORK_MSG);
	if (philo->share->num_philos == 1)
	{
		pthread_mutex_unlock(&(philo->share->forks[a]));
		return (-1);
	}
	pthread_mutex_lock(&(philo->share->forks[b]));
	print_action(philo, TAKING_FORK_MSG);
	return (0);
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->share->forks[philo->left_fork]));
	if (philo->share->num_philos > 1)
		pthread_mutex_unlock(&(philo->share->forks[philo->right_fork]));
}