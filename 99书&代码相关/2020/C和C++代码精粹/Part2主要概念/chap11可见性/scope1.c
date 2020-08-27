// scope1.c 举例说明局部作用域和原型作用域
// 程序清单11.1  说明局部作用域 
#include <stdio.h>

void f(int val);

int main()
{
	f(1);
	getchar();
	return 0;
}

void f(int i)
{
	printf("i==%d\n", i);  // i == 1
	{
		int j = 10;
		int i = j;
		printf("i=%d\n", i);  // i == 10

	}
}