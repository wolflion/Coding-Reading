// 程序3：往文件中写入字符串形式的文本
// 往文本文件中写入字符串

#include <stdio.h>
#include <string.h>
int main()
{
	char str[80];
	char fname[15]; // 用于保存文件名
	FILE *fp;

	// 输入文件名
	printf("\nEnter filename: ");
	gets(fname);

	// 打开文件用于写入数据
	fp = fopen(fname, "w");

	// 提示信息
	printf("\nEnter strings:");
	printf("\nPress <ENTER> to quit.\n");

	do 
	{
		gets(str); // 将字符串读入str中
		strcat(str, "\n");  // 追加换行符
		fputs(str, fp); // 将字符串写入文件
	} while (*str != '\n');

	// 关闭文件
	fclose(fp);
}