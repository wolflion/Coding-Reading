// register storage class
#include <stdio.h>
int main()
{
	register int i;
	for (i = 0; i < 10;i++)
	{
		printf("\n%d", i);
	}
}