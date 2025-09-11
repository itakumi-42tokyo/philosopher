#include <stdio.h>
#include "parse.h"
// テストがOKの時はexit statusを０にする
// そうでないときは，1にするという風にする？
int main(void)
{
	char *str = "---3456789";
	long long result = ut_atoi_with_error(str);
	printf("result: %lld\n", result);
	str = NULL;
	result = ut_atoi_with_error(str);
	printf("res: %lld\n", result);
	str = "11111111111111111111111111";
	result = ut_atoi_with_error(str);
	printf("result: %lld\n", result);
	str = "0000000";
	result = ut_atoi_with_error(str);
	printf("result: %lld\n", result);
	str = "a0000000";
	result = ut_atoi_with_error(str);
	printf("result: %lld\n", result);
	str = "";
	result = ut_atoi_with_error(str);
	printf("result: %lld\n", result);
	return (0);
}