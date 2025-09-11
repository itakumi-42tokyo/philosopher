/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_elapsed_time_usec.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:50:07 by itakumi           #+#    #+#             */
/*   Updated: 2025/09/08 16:15:30 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

// before afterの関係は取れているものとする。
long long	calc_elapsed_time_usec(struct timeval before, struct timeval after)
{
	const long long	one_million = 1000000;
	long long		second;
	long long		micro_second;
	long long		result;

	second = after.tv_sec - before.tv_sec;
	micro_second = after.tv_usec - before.tv_usec;
	second = second * one_million;
	result = second + micro_second;
	return (result);
}
