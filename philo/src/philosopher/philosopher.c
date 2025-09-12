/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:00:47 by itakumi           #+#    #+#             */
/*   Updated: 2025/09/08 17:20:58 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philosophers.h"

void	*philosopher(void *arg)
{
	t_basic_info *info;

	if (arg == NULL)
		return (NULL);
	info = (t_basic_info *)arg;
	while (info->stop_flag == false)
	{
		
	}
	return (NULL);
}
