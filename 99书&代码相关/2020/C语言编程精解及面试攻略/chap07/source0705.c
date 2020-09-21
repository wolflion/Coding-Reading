// static storage class
#include <stdio.h>
void test()
{
	static int i = 1;
	auto int j = 1;
	printf("\n%d\t%d",i++,j++);
}

int main()
{
	test();
	test();
	test();
}