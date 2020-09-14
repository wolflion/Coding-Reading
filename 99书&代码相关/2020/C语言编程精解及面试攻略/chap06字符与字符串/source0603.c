// 程序3：用scanf()和putchar()函数输入并显示一个字符
// 输入并显示一个字符
#include<stdio.h>
int main()
{
	char ch;
	printf("\nEnter a character: ");
	scanf("%c", &ch);

	printf("\nYou entered: %c",ch);
}