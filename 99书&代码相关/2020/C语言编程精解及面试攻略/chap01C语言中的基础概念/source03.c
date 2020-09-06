// 程序3：接收一个人的姓名，并打印生日祝福。

#include <stdio.h>
int main()
{
	char name[20];
	printf("Your good name please: ");
	//scanf("%[^\n]",name); //这一行，我真的没看懂唉  【[^\n]表示一读入换行字符就结束读入。这个是scanf的正则用法。】
	scanf("%s",name);
	printf("Hello %s",name);
	printf("\nHappy Birth day to you!");
	return 0;
}