#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int n = 5;
	int i = 0;
	pid_t pid = 0;
	// 父进程循环结束
	for (i = 0; i < 5; i++)   // 这种写法是32个。（1+2+4+6+8+12）-1 ； 2的5次方；
	{
		pid = fork();
		if (pid == 0)
		{
			// 子进程
			printf("i am child, pid = %d, ppid = %d\n", getpid(), getppid());
			break; // **重要**：子进程退出循环，这样子进程，便不会fork()，只会创建5个。
		}
		else if (pid > 0)
		{
			// 父进程
			printf("I am father,pid = %d, ppid = %d\n", getpid(), getppid());
		}
	}

	while (1)
	{
		sleep(1);
	}
	return 0;
}