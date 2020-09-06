// 程序1：从键盘接收一个字符作为输入，然后将该字符打印到显示器作为输出。

#include <stdio.h>
int main()
{
	char ch;
	ch = getchar();
	putchar(ch);
	return 0;
}