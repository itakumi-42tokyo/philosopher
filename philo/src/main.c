/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:07:11 by itakumi           #+#    #+#             */
/*   Updated: 2025/09/08 17:12:49 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "parse.h"
#include "philosophers.h"

int	main(int argc, char **argv)
{
	// pthread_mutex_t	mutex;
	t_basic_info	info;

	parse_args(argc, argv, &info);
	return (0);
}
