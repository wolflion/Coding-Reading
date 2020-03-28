#include "../head.h"

/*
 * 将一整数逆序后放入一数组中，要求递归实现
 */

void convert(int *result, int n)
{
	if (n > 10)
		convert(result + 1, n / 10);
	*result = n % 10;
}

int main(int argc, char *argv[])
{
	int n = 123456789, result[20] = {};
	convert(result, n);
	printf("%d:", n);
	for (int i = 0; i < 9;i++)
	{
		printf("%d", result[i]);
	}
}