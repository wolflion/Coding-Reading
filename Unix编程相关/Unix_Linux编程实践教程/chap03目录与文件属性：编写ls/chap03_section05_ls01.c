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
�������ģ�
��1�����򣺰������ļ������뵽һ�����飬��qsort()����
��2���������������ļ������뵽һ�����飬������еĿ�Ⱥ�����
��3��.�ļ�����-a��ʱ����ʾ����
��4��-lѡ� �����̫���ף�Ҫ��stat�ṹ����
*/