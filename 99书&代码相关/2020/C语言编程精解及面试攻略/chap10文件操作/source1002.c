// 程序2：从一个文本文件中读入文本
// 读取并显示一个文本文件
#include <stdio.h>
int main()
{
	char ch;

	// 创建一个文件指针用于读入一个文本文件
	FILE *fp = fopen("myfile.txt", "r");

	// 逐字符读入文本并显示
	printf("\nThe file contents: \n");
	while ((ch = getc(fp))!=EOF)
	{
		putchar(ch);
	}

	// 关闭文件
	fclose(fp);
}