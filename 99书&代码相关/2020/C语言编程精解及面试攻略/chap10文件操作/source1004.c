// 程序4：从文本文件中读取字符串并显示它们
// 从文本文件中逐个读出字符串
#include <stdio.h>
#include <string.h>

int main()
{
	char str[80];
	char fname[15];
	FILE *fp;

	printf("\nEnter filename: ");
	gets(fname);

	// 打开文件供读入
	fp = fopen(fname, "r");

	// 检查文件是否存在
	if (fp == NULL)
	{
		printf("\nFile not found");
		return;
	}

	// 在返回NULL之前持续读入字符串
	printf("\nThe file contents: \n");

	while ((fgets(str,80,fp) != NULL)
	{
		puts(str);
	}

	// 关闭文件
	fclose(fp);
}