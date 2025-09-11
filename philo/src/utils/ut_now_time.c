/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_now_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-11 09:56:13 by tigarashi         #+#    #+#             */
/*   Updated: 2025-09-11 09:56:13 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "libft.h"
#include "error_macro.h"

long long	now_ms(void)
{
	struct timeval ts;

	if (gettimeofday(&ts, NULL) == -1)
	{
		ft_putendl_fd(GETTIMEOFDAY_ERROR, STDERR_FILENO);
		return (-1);
	}
	return (ts.tv_sec * 1000LL + ts.tv_usec / 1000LL);
}

long long	now_us(void)
{
	struct timeval ts;

	if (gettimeofday(&ts, NULL) == -1)
	{
		ft_putendl_fd(GETTIMEOFDAY_ERROR, STDERR_FILENO);
		return (-1);
	}
	return (ts.tv_sec * 1000000LL + ts.tv_usec);
}