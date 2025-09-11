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

#include "libft.h"
#include "philosophers.h"
#include "timestamp.h"

void	put_timestamp(t_state state, int philo_number)
{
	(void)philo_number;

	if (state == TAKING_FORK)
		ft_putendl_fd(TAKING_FORK_MSG, STDOUT_FILENO);
	else if (state == EATING)
		ft_putendl_fd(EATING_MSG, STDOUT_FILENO);
	else if (state == SLEEPING)
		ft_putendl_fd(SLEEPING_MSG, STDOUT_FILENO);
	else if (state == THINKING)
		ft_putendl_fd(THINKING_MSG, STDOUT_FILENO);
	else if (state == DIED)
		ft_putendl_fd(DIED_MSG, STDOUT_FILENO);
}
