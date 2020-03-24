#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Begin ....\n");
	pid_t pid = fork();  
	if (pid < 0)
	{
		perror("fork err");
		exit(1);
	}
	if (pid == 0)
	{
		//子进程
		printf("I am a child, pid = %d, ppid=%d\n", getpid(), getppid());
		//11的改造，加个循环
		while (true)
		{
			printf("I am a child\n");
			sleep(1);
		}
	}
	else if (pid>0)
	{
		printf("I am a child, pid = %d, ppid=%d\n", getpid(), getppid());
		while (true)
		{
			sleep(1);
		}
	}
	printf("End ...\n");

	return 0;
}