#include <unistd.h>
#include <stdio.h>

int main()
{
	pid_t pid = fork();
	if (pid == 0)
	{
			printf("I am child, pid = %d,ppid=%d\n", getpid(), getppid());
			sleep(2);
			printf("I am child ,I will die!\n");
	}
	else if (pid > 0)
	{
		while (true)
		{
			printf("I am father, very happy, pid = %d,ppid=%d\n", getpid(), getppid());
			sleep(1);
		}
	}
	return 0;
}