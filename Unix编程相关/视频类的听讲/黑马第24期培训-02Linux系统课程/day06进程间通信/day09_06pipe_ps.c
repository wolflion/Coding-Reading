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
		//0、重要的是关闭读端
		close(fd[0]);
		//1、先重定向  **ps的输出是标准输出**，所以要重定向到 写端 fd[1]
		dup2(fd[1], STDOUT_FILENO);//标准输出重定向到管道写端
		//2、execlp
		execlp("ps", "ps", "aux", NULL);
	}
	else if (pid > 0)
	{
		//parent--grep bash
		//同理：关闭写端
		close(fd[1]);
		//1、重定向 本来默认是从标准输出读
		dup2(fd[0], STDOUT_FILENO);
		//2、execlp()
		execlp("grep", "grep", "bash", NULL);
		//3、回收子进程，没回收的话，会产生 僵尸进程
	}

	return 0;
}