// 程序1：
// Availablity of a variable
#include <stdio.h>
void function()
{
	/* variable j is declared inside function,
	 so it is available inside this function only */
	int j = 100;
	printf("\n%d", j);
}

int main()
{
	{
		/* variable i is declared inside the block,
			so it is available inside this block only*/
		int i = 10;
		printf("\n%d", i);
	}
	printf("\n%d", i);  // here i is not available
	printf("\n%d", j);  // here j is not available
}

















