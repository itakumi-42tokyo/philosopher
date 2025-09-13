/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putendl_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-12 04:54:25 by tigarashi         #+#    #+#             */
/*   Updated: 2025-09-12 04:54:25 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <errno.h>
#include "error_macro.h"

static size_t	_strlen(char *s)
{
	char	*s_cpy;

	if (s == NULL)
		return (0);
	s_cpy = s;
	while (*s_cpy != '\0')
		s_cpy++;
	return ((size_t)(s_cpy - s));
}

static void	handle_error(void)
{
	int	rtn;

	if (errno == EACCES)
		rtn = write(STDERR_FILENO, EACCES_ERROR, _strlen(EACCES_ERROR));
	else if (errno == EBADF)
		rtn = write(STDERR_FILENO, EBADF_ERROR, _strlen(EBADF_ERROR));
	else if (errno == EFAULT)
		rtn = write(STDERR_FILENO, EFAULT_ERROR, _strlen(EFAULT_ERROR));
	else
		rtn = write(STDERR_FILENO, UNKNOWN_ERROR, _strlen(UNKNOWN_ERROR));
	(void)rtn;
}

void	putendl_fd(char *s, int fd)
{
	size_t	size;

	size = _strlen(s);
	if (write(fd, s, size) == -1)
		handle_error();
	if (write(fd, "\n", 1) == -1)
		handle_error();
}