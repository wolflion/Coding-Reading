#include <stdio.h>

int main()
{
	int a = 10;
	int b = 20;

	(a < b ? a : b) = 30; //C语言里，表达式不能做左值
	printf("a=%d,b=%d\n", a, b);

	system("pause");
	return 0;
}