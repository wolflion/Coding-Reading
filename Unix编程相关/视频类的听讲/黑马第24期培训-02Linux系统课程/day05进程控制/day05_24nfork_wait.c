#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
	//用wait()死等的方式
	int n = 5;
	int i = 0;
	pid_t pid;
	for (i = 0; i < 5; i++)
	{
		pid = fork();
		if (pid == 0)
		{
			printf("I am child, pid = %d\n", getpid());
			break;
		}
	}
	sleep(i);
	if (i == 5)  // 父进程的逻辑
	{
		for (i = 0; i < 5; i++)
		{
			pid_t wpid = wait(NULL);//死等5次
			printf("wpid=%d\n", wpid);
		}
		while (true)
		{
			sleep(1);
		}
	}
	return 0;
}