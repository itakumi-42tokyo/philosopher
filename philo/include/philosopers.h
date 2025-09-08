/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:16:09 by itakumi           #+#    #+#             */
/*   Updated: 2025/09/08 15:39:29 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>

typedef enum e_state
{
	TAKING_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED
}	t_state;

typedef struct s_philosophers
{
	t_state			state;
	int				hp;
	struct timeval last_eat;
}	t_philosophers;

// 時間はミリ秒で表される。
typedef struct s_basic_info
{
	int				the_number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	t_philosophers	*philosophers;
}	t_basic_info;

#endif
