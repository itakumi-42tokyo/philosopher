#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include "philosophers.h"

static void init_shared(t_shared *share)
{
    if (!share)
        return;

    // 全てを 0 で初期化
    memset(share, 0, sizeof(t_shared));

    // bool 型や mutex は 0 初期化で false / PTHREAD_MUTEX_INITIALIZER 相当になる
    share->stop_flag = false;

    // mutex は静的初期化もできるが、動的初期化する場合は
    // pthread_mutex_init(&(share->print_action), NULL);
}

int main(void)
{
	t_shared	share;
	pthread_t	thread1;

	init_shared(&share);
	pthread_create(&thread1, NULL, philosopher, (void *)(&share));

	sleep(3);

	share.stop_flag = true;
	
	pthread_join(thread1, NULL);

	puts("stop_flag worked!!!");

	return (0);
}