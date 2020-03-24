#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types>

int main()
{
	int n = 5;
	int i;
	pid_t pid;
	for (i = 0; i < 5;i++)
	{
		pid = fork();
		if (pid == 0)
		{
			break;
		}
	}
	if (i == 5)
	{
		//parent
		printf("I am parent\n");
		//���ʹ��waitpid���գ���-1�����ӽ��̶����ˣ������ˡ�
		while (true)
		{
			pid_t wpid = waitpid(-1, NULL, WNOHANG);
			if (wpid == -1)
			{
				break;
			}
			else if (wpid > 0)
			{
				printf("waitpid wpid=%d\n", wpid);
			}
		}
		while (true)
		{
			sleep(1); //�������Ȳ���
		}
	}
	if (i < 5)
	{
		sleep(i);//ע��ȥ��ǰ�󣬿��Կ��²��� ��û�н�ʬ���̡�
		printf("I am child, i=%d,pid=%d\n", i, getpid());
	}
	return 0;
}