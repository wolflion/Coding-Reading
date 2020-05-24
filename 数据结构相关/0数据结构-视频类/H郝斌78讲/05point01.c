#include <stdio.h>

int main(void)
{
#if 0
	int *p;
	int i = 10;
	int j;

	j = *p; //这个地方*p没有值。  【编译没错，但运行时错】
	printf("%d\n", j);
	return 0;
#endif

	int *p; //p是个变量名字，int*表示该p变量只能存储int类型变量的地址
	int i = 10;
	int j;

	p = &i;//p只能存放整型数量的地址
	p = 10;//error

	j = *p; //等价于 j = i;
	printf("i = %d, j = %d, *p = %d\n", i, j, *p);

	return 0;
}