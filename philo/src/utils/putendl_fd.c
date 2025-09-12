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

void	putendl_fd(char *s, int fd)
{
	size_t	size;

	size = _strlen(s);
	write(fd, s, size);
	write(fd, "\n", 1);
}