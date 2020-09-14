// 程序2：用getche()和putchar()函数输入并显示一个字符
// 输入并显示一个字符
#include<stdio.h>
#include <conio.h>
int main()
{
	char ch;
	printf("\nEnter a character: ");
	ch = getche(); // 可以尝试用getch()替代一下getche()

	printf("\nYou entered: ");
	putchar(ch);
}