/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-12 00:41:43 by tigarashi         #+#    #+#             */
/*   Updated: 2025-09-12 00:41:43 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

# include "philosophers.h"

int		create_threads(t_philo *philo_resource, pthread_t *threads, t_monitor *monitor_resource);
int		is_stopped(t_shared *share);
void	print_action(t_philo *philos, const char *msg);
void	put_forks(t_philo *philo);
int		take_forks(t_philo *philo);

#endif