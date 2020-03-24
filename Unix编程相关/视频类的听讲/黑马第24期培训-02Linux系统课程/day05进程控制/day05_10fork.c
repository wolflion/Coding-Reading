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
		//�ӽ���
		printf("I am a child, pid = %d, ppid=%d\n", getpid(), getppid());
	}
	else if (pid>0)
	{
		printf("I am a child, pid = %d, ppid=%d\n", getpid(), getppid());
	    //sleep(1);  //�Ӳ����������û�й�ϵ  �����������ˣ��ӽ��̱�1�Ž��������ˡ�
	}
	printf("End ...\n");

	return 0;
}