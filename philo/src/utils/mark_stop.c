/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_stop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 21:45:27 by itakumi           #+#    #+#             */
/*   Updated: 2025/11/12 21:52:26 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	mark_stop(t_shared *share)
{
	pthread_mutex_lock(&(share->state_mutex));
	share->stop_flag = 1;
	pthread_mutex_unlock(&(share->state_mutex));
}
