/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:54:09 by itakumi           #+#    #+#             */
/*   Updated: 2025/11/12 21:46:24 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <sys/time.h>
# include "philosophers.h"

long long	
calc_elapsed_time_msec(struct timeval before, struct timeval after);
long long	
calc_elapsed_time_usec(struct timeval before, struct timeval after);
void		put_timestamp(t_state state, int philo_number);
void		mark_stop(t_shared *share);
int			ut_issign(int c);
int			ut_isspace(int c);
long long	now_ms(void);
long long	now_us(void);
void		sleep_ms_polling(long ms);
void		sleep_ms_adaptive(long long ms);
void		sleep_us_adaptive(long long us);
void		free_all(t_shared *share, t_philo *phi, pthread_t *th);
void		init_all(t_shared *share);
void		putendl_fd(char *s, int fd);

#endif
