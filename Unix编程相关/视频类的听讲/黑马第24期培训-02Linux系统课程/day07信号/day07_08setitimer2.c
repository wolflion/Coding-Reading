//�����Եģ�Ҫ�в�׽����
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

//typedef void (*sighandler_t)(int);  //����ָ��
//sighandler_t signal(int signum, sighandler_t handler);

void catch_sig(int num)
{
	printf("cat %d sig\n", num);
}

int main()
{
	signal(SIGALRM,catch_sig); //ֻ��ע����

	struct itimerval myit = { {3,0}, {5,0} };//�룬΢��  �������Եġ���һ�ε�5�룬����ÿ��3��
	setitimer(ITIMER_REAL��&myit,NULL);
	while (true)
	{
		printf("who can kill me!\n");
		sleep(1);
	}
	return 0;
}