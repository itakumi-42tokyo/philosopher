/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 06:59:41 by tigarashi         #+#    #+#             */
/*   Updated: 2025/10/29 16:04:37 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "philosophers.h"

int		parse_args(int argc, char **argv, t_shared *share);
int		ut_atoi_with_error(char *str);

#endif
