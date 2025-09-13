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

#include "parse.h"
#include "philosophers.h"
#include "utils.h"
#include <stdio.h>
#include <stdbool.h>

static void	substitute_share(t_shared *share, int i, int result)
{
	if (i == 0)
		share->num_philos = result;
	else if (i == 1)
		share->time_to_die = result;
	else if (i == 2)
		share->time_to_eat = result;
	else if (i == 3)
		share->time_to_sleep = result;
	else if (i == 4)
		share->required_eat_count = result;
}

//　引数の中に "0" が含まれていた場合は，この後対処することが要求されている。 
int	parse_args(int argc, char **argv, t_shared *share)
{
	int		i;
	int		result;

	if ((argc == 5 || argc == 6) == false)
		return (-1);
	argv++;
	i = 0;
	while (i < argc - 1)
	{
		result = ut_atoi_with_error(argv[i]);
		if (result < 0)
			return (result);
		substitute_share(share, i, result);
		i++;
	}
	if (argc == 5)
		share->required_eat_count = -1;
	share->stop_flag = false;
	share->start_at_ms = now_ms();
	return (0);
}
// required_eat_countは０に到達するまで行う回数とする？
