#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
	//��wait()���ȵķ�ʽ
	int n = 5;
	int i = 0;
	pid_t pid;
	for (i = 0; i < 5; i++)
	{
		pid = fork();
		if (pid == 0)
		{
			printf("I am child, pid = %d\n", getpid());
			break;
		}
	}
	sleep(i);
	if (i == 5)  // �����̵��߼�
	{
		for (i = 0; i < 5; i++)
		{
			pid_t wpid = wait(NULL);//����5��
			printf("wpid=%d\n", wpid);
		}
		while (true)
		{
			sleep(1);
		}
	}
	return 0;
}