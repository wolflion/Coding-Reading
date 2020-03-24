#include <stdio.h>
#include <unistd.h>

int main()
{
	int fd[2];
	pipe(fd);
	pid_t pid = fork();

	if (pid == 0)
	{
		//son
		sleep(3);
		close(fd[0]);  //关闭读端
		write(fd[1], "hello", 5);
		close(fd[1]); //关闭写端
		while (true)
		{
			sleep(1);
		}
	}
	else if (pid > 0)
	{
		//parent
		close(fd[1]);//关闭写端，**试试，如果这行注释掉，会有啥现象**
		char buf[12] = { 0 };
		while (true)
		{
			int ret = read(fd[0], buf, sizeof(buf));  //父进程一直在尝试read
			if (ret == 0)
			{
				printf("read over!\n");
				break;
			}
			if (ret > 0)
				write(STDOUT_FILENO, buf, ret);
		}
	}

	return 0;
}