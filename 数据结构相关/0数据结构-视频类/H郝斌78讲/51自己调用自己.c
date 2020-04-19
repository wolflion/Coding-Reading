#include <stdio.h>

void f()
{
	printf("哈哈\n");
	f();//直到溢栈
}

void g(int n)
{
	if (n == 1)  //有一个条件，**什么时候才不调用自己**
		printf("哈哈\n");
	else
		g(n - 1);
}


int main(void)
{
	//f();
	g(3);  //输出1个哈哈，**这个要懂一下**，我以为是3个哈哈呢
	return 0;
}