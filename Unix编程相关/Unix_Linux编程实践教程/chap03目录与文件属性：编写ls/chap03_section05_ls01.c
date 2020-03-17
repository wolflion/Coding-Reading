/*
ls01.c : purpose list contents of directory or diectories ation if no args, use . else list files in args
*/

#include <stdio.h>
#include <sys/types.h>
#include <direct.h>

void do_ls(char[]);

int main(int ac, char* av[])
{
	if (ac == 1)
	{
		do_ls(".");
	}
	else
	{
		while (--ac)
		{
			printf("%s:\n", *++av);
			do_ls(*av);
		}
	}
}

// list files in directory called dirname
void do_ls(char dirname[])
{
	DIR *dir_ptr;  // the directory
	struct dirent *direntp;  // each etry

	if ((dir_ptr = opndir(dirname)) == NULL)
	{
		fprintf(stderr, "ls01: cannot open %s\n", dirname);
	}
	else
	{
		while ((direntp = readdir(dir_ptr)) != NULL)
		{
			printf("%s\n", direntp->d_name);
		}
		closedir(dir_ptr);
	}
}

/*
还能做的：
（1）排序：把所有文件名读入到一个数组，用qsort()排序
（2）分栏：把所有文件名读入到一个数组，计算出列的宽度和行数
（3）.文件：用-a的时候显示出来
（4）-l选项： 这个不太容易，要用stat结构体获得
*/