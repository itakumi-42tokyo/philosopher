/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 00:41:43 by tigarashi         #+#    #+#             */
/*   Updated: 2025/11/12 22:01:04 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

# include "philosophers.h"

int		
create_threads\
(t_philo *philo_src, pthread_t *threads, t_monitor *moni_src);
int		is_stopped(t_shared *share);
void	print_action(t_philo *philos, const char *msg);
void	print_action2(t_philo *philos, const char *msg, long long now);
void	put_forks(t_philo *philo);
int		take_forks(t_philo *philo);

#endif
