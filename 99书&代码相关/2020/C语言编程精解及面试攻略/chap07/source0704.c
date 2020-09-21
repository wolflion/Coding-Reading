// The initial default values for auto and static 
#include <stdio.h>
int main()
{
	auto float x;
	static float y;
	auto char str1[20];
	static char str2[20];

	printf("\nx=%f", x);
	printf("\ny=%f", y);
	printf("\nstr1=%s", str1);
	printf("\nstr2=%s", str2);
}