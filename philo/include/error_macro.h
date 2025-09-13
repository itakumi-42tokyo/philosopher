/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-11 09:58:25 by tigarashi         #+#    #+#             */
/*   Updated: 2025-09-11 09:58:25 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MACRO_H
# define ERROR_MACRO_H

// Parse error
# define INVALID_ARGC_ERROR				"Error: the number of argument is incorrect"
# define MINUS_ERROR					"Error: input must not be negative"
# define EXCEEDS_INT_MAX_ERROR			"Error: value exceeds INT_MAX"
# define NAN_INPUT_ERROR				"Error: input must be a number"
# define USAGE_ERROR					"Error: !!!"

// Built-in function error
# define GETTIMEOFDAY_ERROR				"Error: gettimeofday failed"
# define MALLOC_ERROR					"Error: malloc failed"

// pthread_mutex_init
# define UNKNOWN_ERROR					"Error: Unknown error"
# define MUTEX_INIT_EINIVAL_ERROR		"Error: Invalid mutex attributes"
# define MUTEX_INIT_ENOMEM_ERROR		"Error: Not enough memory for mutex"
# define MUTEX_INIT_EBUSY_ERROR			"Error: Mutex already initialized"

// pthread_mutex_destroy
# define MUTEX_DESTROY_EINIVAL_ERROR	"Error: invalid or uninitialized mutex"
# define MUTEX_DESTROY_EBUSY_ERROR		"Error: mutex is still locked or in use"

// thread_create
# define THREAD_CREATE_EAGAIN_ERROR		"Error:  insufficient resources or thread limit reached"
# define THREAD_CREATE_EINVAL_ERROR		"Error: invalid thread attributes"
# define THREAD_CREATE_EPERM_ERROR		"Error: no permission to set the specified attributes"

// write ERRNO
# define EBADF_ERROR					"Error: Bad file descriptor\n"
# define EACCES_ERROR					"Error: Permission denied\n"
# define EFAULT_ERROR					"Error: Bad address\n"

# define ESRCH_ERROR					"Error: No such process"
# define EDEADLK_ERROR					"Error: Resource deadlock avoided"
# define EINIVAL_ERROR					"Error: Invalid argument"

void	error_exit(int check);

#endif