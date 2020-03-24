#include <unistd.h>
#include <stdio.h>

int var = 100;  //全局变量，也是读时共享，写时复制。

int main()
{
	pid_t pid = fork();
	if (pid == 0)
	{
		//son
		printf("var =%d,child, pid=%d,ppid=%d\n", var, getpid(), getppid());
		var = 1001;
		printf("var =%d,child, pid=%d,ppid=%d\n", var, getpid(), getppid());
		sleep(3); // 睡个3秒，让父进程去改；
	}
	else if (pid >0)
	{
		//parent
		sleep(1); //保证子进程能够修改var的值成功  【因为不确定 父子进程，哪个先】
		printf("var =%d,parent, pid=%d,ppid=%d\n", var, getpid(), getppid());
		var = 2000;
		printf("var =%d,parent, pid=%d,ppid=%d\n", var, getpid(), getppid());
	}
	return 0;
}