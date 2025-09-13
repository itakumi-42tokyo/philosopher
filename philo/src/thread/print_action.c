/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-12 07:14:51 by tigarashi         #+#    #+#             */
/*   Updated: 2025-09-12 07:14:51 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philosophers.h"
#include "thread.h"
#include "utils.h"

// この哲学者は特定できるのだろうか？
void	print_action(t_philo *philos, const char *msg)
{
	long long	now;

	if (is_stopped(philos->share))
		return ;
	now = now_ms();
	if (now < 0)
		return ;
	pthread_mutex_lock(&(philos->share->print_mutex));
	if (is_stopped(philos->share) == false)
		printf("%lld %d %s\n", now, philos->id + 1, msg);
	pthread_mutex_unlock(&(philos->share->print_mutex));
}