/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:48:06 by itakumi           #+#    #+#             */
/*   Updated: 2025/09/08 15:05:07 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philosophers.h"
#include "timestamp.h"
#include "utils.h"

void	put_timestamp(t_state state, int philo_number)
{
	(void)philo_number;

	if (state == TAKING_FORK)
		putendl_fd(TAKING_FORK_MSG, STDOUT_FILENO);
	else if (state == EATING)
		putendl_fd(EATING_MSG, STDOUT_FILENO);
	else if (state == SLEEPING)
		putendl_fd(SLEEPING_MSG, STDOUT_FILENO);
	else if (state == THINKING)
		putendl_fd(THINKING_MSG, STDOUT_FILENO);
	else if (state == DIED)
		putendl_fd(DIED_MSG, STDOUT_FILENO);
}
