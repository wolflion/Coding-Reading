#include <stdio.h>
int g(int);

int f(int n)
{
	//n=f(n);//如果不在此语句前写个printf()的话，会进入 啥也没输出的死递归
	n = g(n);
	return n;
}

int g(int m)
{
	m = m * 2;
	return m;
}

int main(void)
{
	int val;
	val = f(5);
	printf("val = %d\n",val);//val=10
	return 0;
}