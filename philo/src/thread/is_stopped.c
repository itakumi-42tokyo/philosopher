/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_stopped.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 07:09:38 by tigarashi         #+#    #+#             */
/*   Updated: 2025/10/29 16:06:48 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_stopped(t_shared *share)
{
	int	stopped;

	pthread_mutex_lock(&(share->state_mutex));
	stopped = share->stop_flag;
	pthread_mutex_unlock(&(share->state_mutex));
	return (stopped);
}
