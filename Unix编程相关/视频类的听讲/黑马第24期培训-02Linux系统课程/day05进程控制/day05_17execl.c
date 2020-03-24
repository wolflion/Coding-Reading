#include <stdio.h>
#include <unistd.h>

int main()
{
	//int execlp(const char *file, const char *arg,  .../* (char  *) NULL */); 
	// file 是进程名（程序名），arg就是进程的参数；【要从agrv[0]开始】

	//execlp("ls", "ls", "-l", NULL);
	execlp("ls", "ls", "-l","--color=auto" NULL);  // 这个有环境变量了


	// execl
	execl("/bin/ls", "ls", "-l", "--color=auto" NULL);   // 两种执行效果是一样的
	//不需要判断返回值
	perror("execlp err");

	printf("hello \n");
	return 0;
}