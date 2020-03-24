#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types>

int main()
{
	int n = 5;
	int i;
	pid_t pid;
	for (i = 0; i < 5;i++)
	{
		pid = fork();
		if (pid == 0)
		{
			break;
		}
	}
	if (i == 5)
	{
		//parent
		printf("I am parent\n");
		//如何使用waitpid回收？【-1代表子进程都死了，都收了】
		while (true)
		{
			pid_t wpid = waitpid(-1, NULL, WNOHANG);
			if (wpid == -1)
			{
				break;
			}
			else if (wpid > 0)
			{
				printf("waitpid wpid=%d\n", wpid);
			}
		}
		while (true)
		{
			sleep(1); //父进程先不死
		}
	}
	if (i < 5)
	{
		sleep(i);//注释去掉前后，可以看下差异 【没有僵尸进程】
		printf("I am child, i=%d,pid=%d\n", i, getpid());
	}
	return 0;
}