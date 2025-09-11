#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include "utils.h"

int	main(void)
{
	struct timeval before;
	struct timeval after;

	gettimeofday(&before, NULL);
	sleep_ms_adaptive(1);
	gettimeofday(&after, NULL);

	long long result = calc_elapsed_time_usec(before, after);
	printf("sleep_ms_adaptive: %lld\n", result);

	gettimeofday(&before, NULL);
	usleep(1000);
	gettimeofday(&after, NULL);	

	result = calc_elapsed_time_usec(before, after);
	printf("usleep: %lld\n", result);

	gettimeofday(&before, NULL);
	sleep_us_adaptive(1000);
	gettimeofday(&after, NULL);

	result = calc_elapsed_time_usec(before, after);
	printf("sleep_us_adaptive: %lld\n", result);

	gettimeofday(&before, NULL);
	usleep(1000);
	gettimeofday(&after, NULL);	

	result = calc_elapsed_time_usec(before, after);
	printf("usleep: %lld\n", result);

	return (0);
}