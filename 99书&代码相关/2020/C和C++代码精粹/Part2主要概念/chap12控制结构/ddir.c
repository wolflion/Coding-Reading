// 程序清单12.9 说明非局部分支的递归目录删除程序
// ddir.c：移动子目录树
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include <sys/stat.h>
#include <setjmp.h>
#include <dirent.h>
#include <dir.h>

// longjmp返回的代码
#define BAD_DIR 1
#define DIR_OPEN_ERR 2
#define FILE_DEL_ERR 3
#define DIR_DEL_ERR 4

// continued

// DOS操作系统与其他的操作系统具体的宏变化
#define CMD_FORMAT "del *.* <%s > nul"
#define CMD_LEN 17

char Response_file[L_tmpnam + 1] = "/";

// 调用环境缓冲器
jmp_buf env;

int main(volatile int argc, volatile char **argv)
{
	FILE *f;
	volatile char *old_path = getcwd(NULL, 64);
	void rd(char *);

	// 为DOS系统del命令创建响应文件
	tmpnam(Response_file + 1);
	if ((f = fopen(Response_file, "w")) == NULL)
		abort();
	fputs("Y\n", f);
	fclose(f);

	switch (setjmp(env))
	{
	case BAD_DIR:
		fputs("Invalid directory\n", stderr);
		break;
	case DIR_OPEN_ERR:
		fputs("Error opening directory\n", stderr);
		break;
	case FILE_DEL_ERR:
		fputs("Error deleting file\n", stderr);
		break;
	case DIR_DEL_ERR:
		fputs("Error deleting directory\n", stderr);
		break;
	}

	// 删除目录
	while (--argc)
	{
		rd((char*)*++argv);
	}

	// 清除
	remove(Response_file);
	chdir((char *)old_path);
	return 0;
}

void rd(char* dir)
{
	char sh_cmd[L_tmpnam + CMD_LEN];
	DIR *dirp;
	struct dirent *entry;
	struct stat finfo;

	// 登录将要删除的目录
	if (chdir(dir) != 0)
		longjmp(env, BAD_DIR);
	printf("%s:\n", strlwr(dir));

	// 通过OS外壳删除所有的一般文件
	sprintf(sh_cmd，CMD_FORMAT，Response_file);
	system(sh_cmd);

	// 删除任何保留的目录入口
	if ((dirp = opendir(".")) == NULL)
		longjmp(env, DIR_OPEN_ERR);
	while ((entry = readdir(dirp))!=NULL)
	{
		if (entry->d_name[0] == '.')
		{
			continue;
		}
		stat(entry->d_name, &finfo);
		if (finfo.st_mode & S_IFDIR)
		{
			rd(entry->d_name); // Subdirectory
		}
		else
		{
			// 允许删除文件，然后完成删除
			chmod(entry->d_name, S_IWRITE);
			if (unlink(entry->d_name) != 0)
				longjmp(env, FILE_DEL_ERR);
		}
	}
	closedir(dirp);

	// 从父目录中删除目录
	chdir("..");
	if (rmdir(dir) != 0)
		longjmp(env, DIR_DEL_ERR);
}


















