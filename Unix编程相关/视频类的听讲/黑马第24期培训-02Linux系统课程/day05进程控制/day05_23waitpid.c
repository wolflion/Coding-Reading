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
		printf("I am child, pid = %d\n",getpid());
		sleep(2);
	}
	else if (pid > 0)
	{
		printf("I am parent, pid = %d\n",getpid());
		//int ret = waitpid(-1, NULL, WNOHANG);  // 这种情况下，会产生 僵尸进程
		int ret;
		while ((ret = waitpid(-1, NULL, WNOHANG)) == 0)
		{
			sleep(1);
		}
		printf("ret = %d\n", ret);

		ret = waipid(-1, NULL, WNOHANG);  //再调用一次，之前肯定回收成功，这应该返回-1，因为没有子进程了
		{
			perror("wait err");
		}
		while (true)
		{
			sleep(1);
		}
	}
	return 0;
}