// 程序4：显示ascii码及相应的字符
// 显示所有ascii码及相应的字符
#include<stdio.h>
int main()
{
	int c;
	for (c = 0; c <= 255;c++)
	{
		printf("\nASCII=%d\t char=%c",c,c);
	}
}