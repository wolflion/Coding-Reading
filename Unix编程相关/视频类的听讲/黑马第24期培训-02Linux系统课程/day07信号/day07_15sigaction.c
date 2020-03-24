#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

void catch_sig(int num)
{
	printf("catch %d sig\n", num);
}

int main()
{
	//ע��һ�²�׽����
	struct sigaction act;
	act.sa_flags = 0;
	act.sa_handler = catch_sig;
	sigemptyset(&act.sa_mask);
	sigaction(SIGALRM, &act, NULL);
	//setitimer
	struct itimerval myit = { { 3, 0 }, { 5, 0 } };//3�������Եġ���һ����5�룬����ÿ��3����һ��
	setitimer(ITIMER_REAL��&myit, NULL);
	while (true)
	{
		printf("who can kill me!\n");
		sleep(1);
	}
	return 0;
}

//kill 14 ����id��  ������һ�����ܲ�����źš�