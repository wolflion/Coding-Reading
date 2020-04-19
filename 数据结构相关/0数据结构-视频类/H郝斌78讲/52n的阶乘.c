#include <stdio.h>

//阶乘的递归实现【先假定n的值是大于等于1的】
long f(long n)  //n规模的解决，可以借助于(n-1)规模的解决而解决
{
	if (1 == n)  //规模为1的时候，直接有答案
		return 1;
	else
		return n * f(n - 1);
}
 
int main(void)
{
	int val;
	int i, mult = 1;
	printf("请输入一个数字：");
	printf("val = ");
	scanf("%d", &val);

	for (i = 1; i <= val; ++i)
	{
		mult = mult*i;
	}
	//思考一下：溢出的原理
	printf("%d的阶乘是：%d\n", val, mult);  //如果输入100的话，就太大了，溢出，输出0 【压栈了，从左到右压栈】
	return 0;
}