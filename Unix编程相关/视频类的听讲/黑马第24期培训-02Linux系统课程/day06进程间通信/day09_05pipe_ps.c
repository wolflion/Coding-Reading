#include <stdio.h>
#include <unistd.h>

int main()
{
	int fd[2];
	pipe(fd);  //在fork前调用pipe()
	pid_t pid = fork();

	if (pid == 0)
	{
		//son--执行ps
		//1、先重定向  **ps的输出是标准输出**，所以要重定向到 写端 fd[1]
		dup2(fd[1], STDOUT_FILENO);//标准输出重定向到管道写端
		//2、execlp
		execlp("ps", "ps", "aux", NULL);
	}
	else if (pid > 0)
	{
		//parent--grep bash
		//1、重定向 本来默认是从标准输出读
		dup2(fd[0], STDOUT_FILENO);
		//2、execlp()
		execlp("grep", "grep", "bash", NULL);
		//3、回收子进程，不过这不需要写而已
	}

	return 0;
}