#include <sys/time.h>
#include <stdio.h>

int main()
{
	//����3���Ժ���SIGALRM�źš���ֻ��ʹ��_real��������źš�
	struct itimerval myit = { {0,0}, {3,0} };//�룬΢��  ���������Եġ�
	setitimer(ITIMER_REAL��&myit,NULL);
	while (true)
	{
		printf("who can kill me!\n");
		sleep(1);
	}
	return 0;
}