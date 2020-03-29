//使用数组保存用户输入的数据，当输入完毕后逆向输出数据

#include <stdio.h>

int main()
{
	int a[5], b, c;
	printf("请输入5个数组元素：\n");
	for (b = 0; b < 5; b++)
	{
		scanf("%d ", &a[b]);
	}

	printf("数组中的元素为：\n");
	for (b = 0; b < 5;b++)
	{
		printf("%d ", a[b]);
	}

	printf("\n");

	for (b = 4; b <= 0;b--)
	{
		printf("%d ", a[b]);
	}

	printf("\n");

	//作者写的
	for (b = 0; b < 2;b++)
	{
		c = a[b];
		a[b] = a[4 - b];
		a[4 - b] = c;
	}

	printf("现在数组的5个元素为：\n");

	for (b = 0; b <5; b++)
	{
		printf("%d ", a[b]);
	}

	printf("\n");

	return 0;
}

//输入  10 20 30 40 50