// 程序2：从键盘输入中读取人名并显示到显示器上。

#include <stdio.h>
int main()
{
	char str[20];
	puts("Type your name: ");  // 也可用于显示器输出的提示符
	str = gets();
	puts(str);
	return 0;
}