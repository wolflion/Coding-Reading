//汉诺塔，怎么移？3个的时候，可以推出来。但如果64个的时候，怎么移？

/*
伪算法：
if(n > 1)
{
先把A柱子上的前n-1个盘子从A借助C移到B

将A柱子上的第n个盘子直接移到C

再将B柱子上的n-1个盘子借助A移到C
}
*/

#include <stdio.h>

void hannuota(int n, char x, char y, char z)
{
	/*如果是1个盘子，
			直接将A柱子上的盘子从A移到C
	  否则
			先将A柱子上的n-1个盘子借助C移到B
			直接将A柱子上的盘子从A移到C
			最后将B柱子上的n-1个盘子借助A移到C
	*/
	if (1 == n)
	{
		printf("将编号为%d的盘子直接从%c柱子移到%c柱子", n, A, C);
	}
	else
	{
		hannuota(n - 1, A, C, B);
		printf("将编号为%d的盘子直接从%c柱子移到%c柱子", n, A, C);
		hannuota(n - 1, B, A, C);
	}
}

int main()
{
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';

	int n;
	printf("请输入要移动盘子的个数：");
	scanf("%d", &n);

	hannuota(n, 'A', 'B', 'C');

	return 0;
}
