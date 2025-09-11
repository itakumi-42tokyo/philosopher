/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:13:50 by itakumi           #+#    #+#             */
/*   Updated: 2025/09/08 17:14:26 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "philosophers.h"

static void	substitute_info(t_basic_info *info, int i, int result)
{
	if (i == 0)
		info->the_number_of_philosophers = result;
	else if (i == 1)
		info->time_to_die = result;
	else if (i == 2)
		info->time_to_eat = result;
	else if (i == 3)
		info->time_to_sleep = result;
	else if (i == 4)
		info->required_eat_count = result;
}

int	parse_args(int argc, char **argv, t_basic_info *info)
{
	int		i;
	int		result;

	if (argc != 5 || argc != 6)
		return (-1);
	i = 0;
	while (i < argc - 1)
	{
		result = ut_atoi_with_error(argv[i]);
		if (result < 0)
			return (result);
		substitute_info(info, i, result);
		i++;
	}
	if (argc == 5)
		info->required_eat_count = -1;
	return (0);
}
// required_eat_countは０に到達するまで行う回数とする？
