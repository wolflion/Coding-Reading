// �����嵥10.4 ˵����խת����16λ�汾��
// narrow.c
#include <stdio.h>
void f(int);
void g(short);

int main()
{
	unsigned n = 60000U;
	long m = 70000L;
	float x = 1.23e10;

	f(n);
	f(x);
	g(m);
	return 0;
}

void f(int i)
{
	printf("%d\n", i);
}

void g(short i)
{
	printf("%hd\n", i);
}