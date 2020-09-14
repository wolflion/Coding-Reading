// 程序1：用getchar()和putchar()函数输入并显示一个字符
// 输入并显示一个字符
#include<stdio.h>
int main()
{
	char ch;
	printf("\nEnter a character: ");
	ch = getchar();

	printf("\nYou entered: ");
	putchar(ch);
}