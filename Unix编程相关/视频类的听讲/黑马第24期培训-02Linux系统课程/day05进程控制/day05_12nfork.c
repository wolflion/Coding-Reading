#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int n = 5;
	int i = 0;
	pid_t pid = 0;
	// ������ѭ������
	for (i = 0; i < 5; i++)   // ����д����32������1+2+4+6+8+12��-1 �� 2��5�η���
	{
		pid = fork();
		if (pid == 0)
		{
			// �ӽ���
			printf("i am child, pid = %d, ppid = %d\n", getpid(), getppid());
			break; // **��Ҫ**���ӽ����˳�ѭ���������ӽ��̣��㲻��fork()��ֻ�ᴴ��5����
		}
		else if (pid > 0)
		{
			// ������
			printf("I am father,pid = %d, ppid = %d\n", getpid(), getppid());
		}
	}

	while (1)
	{
		sleep(1);
	}
	return 0;
}