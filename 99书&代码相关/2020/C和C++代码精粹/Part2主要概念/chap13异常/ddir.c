// ddir.c: 删除子目录树
// 程序清单13.1：一个删除整个目录子树的程序
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <dir.h>

int main(int argc, char **argv)
{
	char *old_path = getcwd(NULL, 64);
	void rd(char *);

	// 删除目录
	while (--argc)
	{
		rd(*++argv);
	}

	// 恢复目录
	chdir(old_path);
	return 0;
}

void rd(char * dir)
{
	void erase_dir(void);

	// 记录将删除的目录
	chdir(dir);
	// 经os外壳（DOS系统版本）删除全部的正规文件
	system("del /q *.* > null");

	// 删除所有保留的目录入口
	erase_dir();

	// 从父目录中去掉目录
	chdir("..");
	rmdir(dir);
}

void erase_dir()
{
	DIR *dirp;
	struct dirent *entry;
	struct stat finfo;   // continued
	// 删除当前目录
	dirp = opendir(".");
	while ((entry = readdir(dirp))!=NULL)
	{
		if (entry->d_name[0] == '.')
		{
			continue;
		}
		stat(entry->d_name, &finfo);
		if (finfo.st_mode & S_IFDIR)
		{
			rd(entry->d_name);  // 子目录
		}
		else
		{
			// 允许删除文件，然后实现
			chmod(entry->d_name, S_IWRITE);
			unlink(entry->d_name);
		}
	}
	closedir(dirp);
}