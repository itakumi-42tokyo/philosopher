/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-12 05:20:16 by tigarashi         #+#    #+#             */
/*   Updated: 2025-09-12 05:20:16 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "philosophers.h"

void	init_all(t_shared *share)
{
	if (!share)
		return;
	memset(share, 0, sizeof(t_shared));
	pthread_mutex_init(&(share->print_mutex), NULL);
}