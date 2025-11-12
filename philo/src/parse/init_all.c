/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 05:20:16 by tigarashi         #+#    #+#             */
/*   Updated: 2025/11/12 21:28:35 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "philosophers.h"

void	init_all(t_shared *share)
{
	if (!share)
		return ;
	memset(share, 0, sizeof(t_shared));
	pthread_mutex_init(&(share->print_mutex), NULL);
	pthread_mutex_init(&(share->state_mutex), NULL);
}
