// 程序16：向一个函数传递字符串参数，并在函数内显示该字符串

#include <stdio.h>
void myfunction(char arr[])
{
	puts(arr);
}

int main()
{
	// 创建一个字符串
	char str[20] = "Srinivasa Rao";

	// 调用函数显示字符串
	myfunction(str);
}