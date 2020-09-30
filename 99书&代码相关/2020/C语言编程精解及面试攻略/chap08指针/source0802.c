// source02: swap two numbers without using pointers
#include<stdio.h>
void swap(int x,int y);
int main()
{
	int a,b;
	a = 10;
	b = 5;
	printf("\nBefore swapping => a=%d,b=%d",a,b);
	swap(a,b);
	printf("\nAfter swapping => a=%d,b=%d",a,b);
}

void swap(int x,int y)
{
	int t;
	t = x;
	x = y;
	y = t;
}