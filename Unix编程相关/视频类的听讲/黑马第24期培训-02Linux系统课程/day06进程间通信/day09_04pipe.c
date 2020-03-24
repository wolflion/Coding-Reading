#include <stdio.h>
#include <unistd.h>

int main()
{
	int fd[2];
	pipe(fd);  //在fork前调用pipe()
	pid_t pid = fork();

	if (pid == 0)
	{
		//son
		sleep(3); //就算睡，也没有事
		write(fd[1], "hello", 5);
	}
	else if (pid > 0)
	{
		//parent
		char buf[12] = { 0 };
		int ret = read(fd[0], buf, sizeof(buf));  //read 设备 是阻塞等待的  【读文件不是】
		if (ret > 0)
			write(STDOUT_FILENO, buf, ret);
	}

	return 0;
}