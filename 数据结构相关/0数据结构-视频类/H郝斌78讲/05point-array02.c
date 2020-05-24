#include <stdio.h>

void Show_Array(int *p, int len)
{
	p[0] = -1;//p[0]等价于*p，其实是*(p+0)

	//p[i]就是主函数的a[i]

	int i = 0;
	for (i = 0; i < len;++i)
	{
		printf("%d\n", p[i]);
	}
}

int main(void)
{
	int a[5] = { 1, 2, 3, 4, 5 };

	Show_Array(a,5);//数组首元素地址，数组长度  【a等价于&a[0], &a[0]本身就是int* 类型】

	printf("%d\n", a[0]); //a[0]的值改变了。

	return 0;
}