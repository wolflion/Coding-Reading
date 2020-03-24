#include <unistd.h>
#include <stdio.h>

int main()
{
	pid_t pid = fork();
	if (pid == 0)
	{
		while (true)
		{
			printf("I am child, pid = %d,ppid=%d\n", getpid(), getppid());
			sleep(1);
		}
	}
	else if (pid > 0)
	{
		printf("I am parent, pid = %d,ppid=%d\n", getpid(), getppid());
		sleep(5);
		printf("I am parent ,I will die!\n");
	}
	return 0;
}