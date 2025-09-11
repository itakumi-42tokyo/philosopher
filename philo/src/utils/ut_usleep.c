/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-11 09:53:28 by tigarashi         #+#    #+#             */
/*   Updated: 2025-09-11 09:53:28 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

void sleep_ms_polling(long ms)
{
	long long start = now_ms();
	while (now_ms() - start < ms)
		usleep(150);
}

void sleep_ms_adaptive(long long ms)
{
	const long long target_us = now_us() + ms * 1000LL;
	long long 		rem_us;

	if (ms <= 0)
		return;
	if (ms > 10)
		usleep((unsigned int)((ms - 10) * 1000));
	while (1)
	{
		rem_us = target_us - now_us();
		if (rem_us <= 0)
			break;
		if (rem_us > 2000)
			usleep((unsigned int)(rem_us - 1000));
		else if (rem_us > 500)
			usleep(200);
		else
		{
			while (now_us() < target_us);
			break;
		}
	}
}

void sleep_us_adaptive(long long us)
{
	const long long target_us = now_us() + us;
	long long rem_us;

	if (us <= 0)
		return;
	if (us > 10000)
		usleep((unsigned int)(us - 10000));
	while (1)
	{
		rem_us = target_us - now_us();
		if (rem_us <= 0)
			break;
		if (rem_us > 2000)
			usleep((unsigned int)(rem_us - 1000));
		else if (rem_us > 500)
			usleep(200);
		else
		{
			while (now_us() < target_us)
				;
			break;
		}
	}
}
