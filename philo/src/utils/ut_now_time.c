/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_now_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:56:13 by tigarashi         #+#    #+#             */
/*   Updated: 2025/11/12 21:30:45 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/time.h>
#include "error_macro.h"
#include "utils.h"

long long	now_ms(void)
{
	struct timeval	ts;

	if (gettimeofday(&ts, NULL) == -1)
	{
		putendl_fd(GETTIMEOFDAY_ERROR, STDERR_FILENO);
		return (-1);
	}
	return (ts.tv_sec * 1000LL + ts.tv_usec / 1000LL);
}

long long	now_us(void)
{
	struct timeval	ts;

	if (gettimeofday(&ts, NULL) == -1)
	{
		putendl_fd(GETTIMEOFDAY_ERROR, STDERR_FILENO);
		return (-1);
	}
	return (ts.tv_sec * 1000000LL + ts.tv_usec);
}
