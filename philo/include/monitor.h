/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 21:48:42 by tigarashi         #+#    #+#             */
/*   Updated: 2025/11/12 21:08:14 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_H
# define MONITOR_H

# include "philosophers.h"

void	init_monitor(t_monitor *monitor, t_philo *philos, t_shared *share);
void	*monitor(void *arg);

#endif
