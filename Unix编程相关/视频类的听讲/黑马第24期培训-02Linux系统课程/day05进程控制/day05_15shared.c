#include <unistd.h>
#include <stdio.h>

int var = 100;  //ȫ�ֱ�����Ҳ�Ƕ�ʱ����дʱ���ơ�

int main()
{
	pid_t pid = fork();
	if (pid == 0)
	{
		//son
		printf("var =%d,child, pid=%d,ppid=%d\n", var, getpid(), getppid());
		var = 1001;
		printf("var =%d,child, pid=%d,ppid=%d\n", var, getpid(), getppid());
		sleep(3); // ˯��3�룬�ø�����ȥ�ģ�
	}
	else if (pid >0)
	{
		//parent
		sleep(1); //��֤�ӽ����ܹ��޸�var��ֵ�ɹ�  ����Ϊ��ȷ�� ���ӽ��̣��ĸ��ȡ�
		printf("var =%d,parent, pid=%d,ppid=%d\n", var, getpid(), getppid());
		var = 2000;
		printf("var =%d,parent, pid=%d,ppid=%d\n", var, getpid(), getppid());
	}
	return 0;
}