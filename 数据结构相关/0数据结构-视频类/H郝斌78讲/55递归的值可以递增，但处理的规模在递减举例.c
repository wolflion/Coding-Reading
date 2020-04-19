#include <stdio.h>
int g(int);

int f(int n)
{
	if (n > 7)
		printf("哈哈\n");
	else
		//n = g(n);
		n = f(n+1);
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