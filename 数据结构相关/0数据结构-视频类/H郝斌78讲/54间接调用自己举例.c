#include <stdio.h>

void f()
{
	g();
}

void g(int m)
{
	f(m);//间接调用
}

int main(void)
{
	return 0;
}