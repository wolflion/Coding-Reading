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
	}
	else if (pid>0)
	{
		printf("I am a child, pid = %d, ppid=%d\n", getpid(), getppid());
	    //sleep(1);  //加不加这个，有没有关系  【父进程死了，子进程被1号进程领养了】
	}
	printf("End ...\n");

	return 0;
}