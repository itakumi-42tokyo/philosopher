/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   admin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:47:15 by itakumi           #+#    #+#             */
/*   Updated: 2025/09/08 16:53:37 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include <errno.h>
#include "libft.h"
#include "philosophers.h"
#include "admin.h"
#include "utils.h"

// 1s = 1000ms
// 1ms = 1000us

// 各哲学者が最後に食事をした時間を更新する
// ->これはthreadの性質を知る必要がある

// 哲学者が死んだことを1msごとに確認する
// ->now - last_eat > time_to_die
// died!!
// つまり、哲学者が死んだというステータスを持つのはadminのみ？

// 1ms待機する

// 食事カウンタが０以上の時は，食事した回数を数えるようにする?
// 第五引数がない場合はそもそも数えなくても良き気もする（ずれが生じる場合）

// 食事カウンタは哲学者全員が食事した回数の最低値を常にとるようにすれば，
// その変数を確認すれば済むという感じ

void	admin(t_basic_info *info)
{
	struct timeval	now;
	long int		elapsed_time;
	static int		eated_count = 0;

	while (1)
	{
		if (info->required_eat_count == eated_count)
			// exit(0);
		if (gettimeofday(&now, NULL) == -1)
			ft_putendl_fd(GETTIMEOFDAY_ERROR, STDERR_FILENO);
		elapsed_time
			= calc_elapsed_time_usec(now, info->philosophers[0].last_eat);
		if (elapsed_time > info->time_to_die)
			put_timestamp(DIED, 1);
		usleep(1000);
	}
}
