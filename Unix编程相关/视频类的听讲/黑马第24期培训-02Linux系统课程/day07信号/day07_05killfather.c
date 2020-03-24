#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <singal.h>

int main()
{
	int i;
	for (i = 0; i < 5;i++)
	{
		pid_t pid = fork();
		if (pid==0)
		{
			break;
		}
	}
	if (i==2) //3号进程杀死父进程
	{
		printf("I will kill father after 5s\n");
		sleep(5);
		kill(getppid(), SIGKILL);
		while (true)
		{
			sleep(1);
		}
	}
	else if (i == 5)
	{
		//parent
		while (true)
		{
			printf("I am parent, I am happy!\n");
			sleep(1);
		}
	}
	return 0;
}