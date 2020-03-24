#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main()
{
	int i = 0;
	pid_t pid3, pid;

	for (i = 0; i < 5;i++)
	{
		pid = fork();
		if (pid == 0)
		{
			break;
		}
		if (i==2) //3号进程，子进程不会执行，已经break了，父进程在执行
		{
			pid3 = pid;
		}
	}

	if (i<5)
	{
		while (true)
		{
			// son shua shua
			printf("I am child, pid = %d,ppid=%d\n", getpid(), getppid());
			sleep(3); //1秒刷得太快了，设置为3秒
		}
	}
	else if (i == 5)
	{
		printf("I am parent, pid = %d, I will kill xiao san pid3=%d\n", getpid(), pid3);
		sleep(5);
		kill(pid3, SIGKILL);
		while (true)
		{
			sleep(1);
		}
	}

	return 0;
}

//5秒以后，只有4个进程在刷屏