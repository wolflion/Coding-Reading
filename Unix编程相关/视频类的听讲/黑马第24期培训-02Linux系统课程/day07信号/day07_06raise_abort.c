#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h> //sleep()�ĵ���
#include <stdlib.h>

int main()
{
	printf("I will die!\n");
	sleep(2);
	//raise(SIGKILL);  //kill(getpid(),sig)
	abort();//�Լ����Լ�����һ��SIGABRT�ź�
	return 0;
}