/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_atol_with_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-10 14:52:02 by tigarashi         #+#    #+#             */
/*   Updated: 2025-09-10 14:52:02 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <limits.h>
#include <stddef.h>
#include "libft.h"
#include "utils.h"

static bool	has_no_minus_sign(const char *str)
{
	if (str == NULL)
		return (false);
	while (*str != '\0')
	{
		if (*str == '-')
			return (false);
		str++;
	}
	return (true);
}

// with error系は，整数値以外の入力をエラーとするようにしよう。
// マイナスをはじく処理とかは，別にする？
int	ut_atoi_with_error(char *str)
{
	unsigned int	result;

	result = 0;
	if (str == NULL || *str == '\0')
		return (-1);
	if (has_no_minus_sign((const char *)str) == false)
		return (-2);
	while (ut_isspace(*str) == true)
		str++;
	while (*str == '+')
		str++;
	while (ft_isdigit(*str) == true)
	{
		result = result * 10 + *str - '0';
		if (result > INT_MAX)
			return (-3);
		str++;
	}
	if (*str != '\0')
		return (-4);
	return ((int)result);
}