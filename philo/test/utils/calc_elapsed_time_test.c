#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include "utils.h"
// ms に変換する関数
int	main(void)
{
	struct timeval before;
	struct timeval after;

	gettimeofday(&before, NULL);
	sleep_ms_polling(1);
	gettimeofday(&after, NULL);

	long long elapsed_time = calc_elapsed_time_usec(before, after);
	printf("sleep_ms_polling: %lld\n", elapsed_time);

	gettimeofday(&before, NULL);
	usleep(1000);
	gettimeofday(&after, NULL);

	elapsed_time = calc_elapsed_time_usec(before, after);
	printf("usleep: %lld\n", elapsed_time);
	return (0);
}