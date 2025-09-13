/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-11 21:22:34 by tigarashi         #+#    #+#             */
/*   Updated: 2025-09-11 21:22:34 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philosophers.h"
#include "utils.h"

void	init_philos(t_philo *philos, t_shared *share)
{
	int	id;

	id = 0;
	while (id < share->num_philos)
	{
		(philos[id]).id = id;
		(philos[id]).left_fork = id;
		(philos[id]).right_fork = (id + 1) % share->num_philos;
		(philos[id]).last_eat_ms = now_ms();
		(philos[id]).share = share;
		id++;
	}
}