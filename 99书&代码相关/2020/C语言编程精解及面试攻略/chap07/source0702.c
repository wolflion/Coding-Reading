// auto storage class

#include <stdio.h>
int main()
{
	{
		// block 1 starts
		auto int i = 10;
		{
			// block 2 starts
			printf("\n%d", i);
		} // block 2 ends
		printf("\n%d", i);
	}// block 1 ends
	printf("\n%d", i);
}