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
#include "philosophers.h"
#include "admin.h"
#include "utils.h"
#include "error_macro.h"
#include "timestamp.h"
#include "thread.h"

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

// adminはスレッドを作成しなくてよい？

// 哲学者ごとのスレッドの時間を管理者が管理する方針だと，３００とかの時に10ms以内にメッセージを送れないのではないか？
// -> 哲学者自身が死亡を報告するシステムを作る？

// 個人管理表のようなものをつくれば，マスト食事回数を共有資源として扱える。
// (mutex)を使用せずに。

// なぜ，state_mutex を一つにした？

void	*monitor(void *arg)
{
	t_monitor	*monitor;
	long long	now;
	long long	diff;
	int			i;

	if (arg == NULL)
		return (NULL);
	monitor = (t_monitor *)arg;
	while (monitor->share->stop_flag == false)
	{
		i = 0;
		while (i < monitor->share->num_philos && monitor->share->stop_flag == false)
		{
			now = now_ms();
			pthread_mutex_lock(&(monitor->share->state_mutex));
			// 管理者用の構造体を作ったほうが良いのか？
			diff = now - monitor->philos[i].last_eat_ms;
			if (diff > monitor->share->time_to_die)
			{
				monitor->share->stop_flag = 1;
				pthread_mutex_unlock(&(monitor->share->state_mutex));
				print_action(&(monitor->philos[i]), DIED_MSG);
				return (NULL);
			}
			pthread_mutex_unlock(&(monitor->share->state_mutex));
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}

// void	admin(t_shared *share, t_philo *philos)
// {
// 	long long		now;
// 	long long		elapsed_time;
// 	int				eated_count;

// 	eated_count = 0;

// }

// while (1)
// {
// if (share->required_eat_count == eated_count)
// exit(0);
// now = now_ms();
// if (now == -1)
// putendl_fd(GETTIMEOFDAY_ERROR, STDERR_FILENO);
// elapsed_time
// = now - philos[0].last_eat_ms;
// if (elapsed_time > share->time_to_die)// 単位はmsでそろっているはず。
// put_timestamp(DIED, 1);
// sleep_ms_adaptive(1LL);
// }