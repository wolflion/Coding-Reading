#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

unsigned int myalarm(unsigned int seconds)
{
	struct itimerval oldit,myit = { { 0, 0 }, { 0, 0 } };//��һ���������ԣ��ڶ�������һ����
	myit.it_vale.tv_sec = seconds;   // ���ӱ���ˣ���������ֵ
	//setitimer(ITIMER_REAL, &myit, NULL); //�൱��seconds����SIGALRM�ź�
	setitimer(ITIMER_REAL, &myit, &oldit);
	//return 0;
	//������ld
	printf("tv_sec=%ld,tv_microsec=%ld\n", oldit.it_value.tv_sec, oldit.it_value.tv_usec);
	return oldit.it_value.tv_sec;
}

//ȡ�����ӣ�����0���ɡ�

int main()
{
#if 0
	int ret = 0;
	ret = myalarm(5);
	printf("ret = %d\n", ret);
	sleep(3);
	ret = myalarm(3);
	printf("ret = %d\n", ret);
#endif

	myalarm(5);
	while (true)
	{
		printf("lai da wo ya!\n");
		sleep(1);
	}
	return 0;
}