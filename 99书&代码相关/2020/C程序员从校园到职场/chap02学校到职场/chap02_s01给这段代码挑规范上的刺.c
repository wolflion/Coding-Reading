#include <stdio.h>

void main()
{
	float fac(int n);
	int n;
	float y;
	printf("input an integer number: ");
	scanf("%d", &n);
	y = fac(n);
	printf("%d!=%10.0f\n", n, y);
}

float fac(int n)
{
	float f;
	if (n<0)
	{
		printf("n<0, dataerror!");
	}
	else
	if (n == 0 || n == 1)
		f = 1;
	else
		f = fac(n - 1)*n;
	return(f);
}