/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:02:55 by tigarashi         #+#    #+#             */
/*   Updated: 2025/10/29 16:05:58 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "error_macro.h"
#include "utils.h"

void	error_exit(int check)
{
	if (check == -1)
		putendl_fd(INVALID_ARGC_ERROR, STDERR_FILENO);
	else if (check == -2)
		putendl_fd(MINUS_ERROR, STDERR_FILENO);
	else if (check == -3)
		putendl_fd(EXCEEDS_INT_MAX_ERROR, STDERR_FILENO);
	else if (check == -4)
		putendl_fd(NAN_INPUT_ERROR, STDERR_FILENO);
	else if (check == -5)
		putendl_fd(MALLOC_ERROR, STDERR_FILENO);
	else
		putendl_fd(USAGE_ERROR, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
