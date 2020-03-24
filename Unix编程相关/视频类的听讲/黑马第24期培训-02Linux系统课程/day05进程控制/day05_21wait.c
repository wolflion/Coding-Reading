#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
	pid_t pid = fork();
	if (pid == 0)
	{
		printf("I am child, will die!\n");
		sleep(2);
		//这样就不退出，可以用kill的方式造非正常死亡
		while (true)
		{
			printf("I am child, guo lai da wo!\n");
			sleep(1);
		}

		//以下两种是正常死亡；
		//return 101;  // 不写这的话，return 0，为了让父进程 捕获。
		exit(102); // 要用stdlib.h
	}
	else if (pid > 0)
	{
		printf("I am parent, wait for child die!\n");
		// 获得死亡原因
		int status;
		pid_t wpid = wait(status);
		//pid_t wpid = wait(NULL);
		printf("wait ok ,wpid = %d,pid=%d\n", wpid, pid);
		if (WIFEXITED(status）)  // 正常死亡
		{
			printf("child exit with %d\n", WEXITSTATUS(status));
		}
		if (WIFSIGNALED(status))  // 异常死亡
		{
			printf("child killed by %d\n", WTERMSIG(status));
		}
		while (true)  // 为了让父进程不死
		{
			sleep(1);
		}
	}
	return 0;
}