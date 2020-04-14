#include<stdio.h>
#include <malloc.h>

void f(int k)
{
	int m;
	double *q = (double *)malloc(200);  //malloc里的200，是在堆里分配的；
}

int main(void)
{
	int i = 10;  //局部变量，在栈里分配；
	int *p = (int *)malloc(100);

	return 0;
}