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
		printf("I am child, will die!\n");
		sleep(2);
		//�����Ͳ��˳���������kill�ķ�ʽ�����������
		while (true)
		{
			printf("I am child, guo lai da wo!\n");
			sleep(1);
		}

		//��������������������
		//return 101;  // ��д��Ļ���return 0��Ϊ���ø����� ����
		exit(102); // Ҫ��stdlib.h
	}
	else if (pid > 0)
	{
		printf("I am parent, wait for child die!\n");
		// �������ԭ��
		int status;
		pid_t wpid = wait(status);
		//pid_t wpid = wait(NULL);
		printf("wait ok ,wpid = %d,pid=%d\n", wpid, pid);
		if (WIFEXITED(status��)  // ��������
		{
			printf("child exit with %d\n", WEXITSTATUS(status));
		}
		if (WIFSIGNALED(status))  // �쳣����
		{
			printf("child killed by %d\n", WTERMSIG(status));
		}
		while (true)  // Ϊ���ø����̲���
		{
			sleep(1);
		}
	}
	return 0;
}