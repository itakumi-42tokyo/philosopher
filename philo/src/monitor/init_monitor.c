/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 21:45:23 by tigarashi         #+#    #+#             */
/*   Updated: 2025/10/29 16:06:15 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_monitor(t_monitor *monitor, t_philo *philos, t_shared *share)
{
	monitor->philos = philos;
	monitor->share = share;
}
