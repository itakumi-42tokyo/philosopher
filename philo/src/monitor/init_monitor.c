/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-12 21:45:23 by tigarashi         #+#    #+#             */
/*   Updated: 2025-09-12 21:45:23 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_monitor(t_monitor *monitor, t_philo *philos, t_shared *share)
{
	monitor->philos = philos;
	monitor->share = share;
}