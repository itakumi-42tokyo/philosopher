#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include "philosophers.h"

static void init_basic_info(t_basic_info *info)
{
    if (!info)
        return;

    // 全てを 0 で初期化
    memset(info, 0, sizeof(t_basic_info));

    // bool 型や mutex は 0 初期化で false / PTHREAD_MUTEX_INITIALIZER 相当になる
    info->stop_flag = false;

    // mutex は静的初期化もできるが、動的初期化する場合は
    // pthread_mutex_init(&(info->print_action), NULL);
}

int main(void)
{
	t_basic_info	info;
	pthread_t	thread1;

	init_basic_info(&info);
	pthread_create(&thread1, NULL, philosopher, (void *)(&info));

	sleep(3);

	info.stop_flag = true;
	
	pthread_join(thread1, NULL);

	puts("stop_flag worked!!!");

	return (0);
}