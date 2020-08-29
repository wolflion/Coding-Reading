// ddir2.c: 删除子目录树
// 程序清单13.2：与程序清单13.1相似但有返回代码
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <dir.h>

// 返回代码
#define BAD_DIR 1
#define DIR_OPEN_ERR 2
#define FILE_DEL_ERR 3
#define DIR_DEL_ERR 4

int main(int argc, char **argv)
{
	char *old_path = getcwd(NULL, 64);
	void rd(char *);

	// 删除目录
	while (--argc)
	{
		int code = rd(**+argv);
		switch (code)
		{
		case BAD_DIR:
			puts("Invalid directory");
			break;
		case DIR_OPEN_ERR:
			puts("Error opening directory");
			break;
		case FILE_DEL_ERR:
			puts("Error deleting file");
			break;
		case DIR_DEL_ERR:
			puts("Error deleting directory");
			break;
		}
	}

	// 恢复目录
	chdir(old_path);
	return 0;
}
//continued
void rd(char * dir)
{
	void erase_dir(void);
	int code;

	// 记录将删除的目录
	if (chdir(dir))
		return BAD_DIR;
	// 经os外壳（DOS系统版本）删除全部的正规文件
	system("del /q *.* > nul");

	// 删除所有保留的目录入口
	code = erase_dir();
	if (code)
	{
		return code;
	}

	// 从父目录中去掉目录
	chdir("..");
	if (rmdir(dir))
		return DIR_DEL_ERR;
	return 0;
}

void erase_dir()
{
	DIR *dirp;
	struct dirent *entry;
	struct stat finfo;   // continued
	// 删除当前目录
	if ((dirp = opendir(".")) == NULL)
		return DIR_OPEN_ERR;
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
			if (unlink(entry->d_name))
			{
				closedir(dirp);
				return FILE_DEL_ERR;
			}
		}
	}
	closedir(dirp);
}