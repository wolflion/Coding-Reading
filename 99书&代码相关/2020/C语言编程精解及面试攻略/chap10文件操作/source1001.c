// 程序1：将一组字符存储到一个文本文件中
// 将一组字符存储到一个文本文件中
#include <stdio.h>
int main()
{
	char ch;

	// 声明文件指针
	FILE *fp;

	// 打开文件用于写入数据
	fp = fopen("myfile.txt", "w");

	// 提示输入数据
	printf("\nEnter text: \n");

	while ((ch = getchar())!=EOF)
	{
		putc(ch, fp);
	}

	// 关闭文件
	fclose(fp);
}