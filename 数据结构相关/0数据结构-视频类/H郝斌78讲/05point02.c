#include <stdio.h>

int main(void)
{
	int *p; //p是个变量名字，int*表示该p变量只能存储int类型变量的地址
	int i = 10;
	int j;

	p = &i;
	*p = i;  //等价于i = i

	printf("i = %d,  *p = %d\n", i, *p);

	return 0;
}