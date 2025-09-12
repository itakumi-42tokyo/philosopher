/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-11 21:22:34 by tigarashi         #+#    #+#             */
/*   Updated: 2025-09-11 21:22:34 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philos(t_basic_info *info)
{
	int	id;

	id = 0;
	while (id < info->the_number_of_philosophers)
	{
		(info->philosophers[id]).id = 0;
		(info->philosophers[id]).eat_count = 0;
		(info->philosophers[id]).state = EATING;
		(info->philosophers[id]).eat_count = 0;
		id++;
	}
}