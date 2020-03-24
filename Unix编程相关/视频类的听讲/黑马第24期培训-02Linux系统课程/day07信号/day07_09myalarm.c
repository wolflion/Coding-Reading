#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

unsigned int myalarm(unsigned int seconds)
{
	struct itimerval oldit,myit = { { 0, 0 }, { 0, 0 } };//第一个是周期性；第二个是下一个；
	myit.it_vale.tv_sec = seconds;   // 闹钟变成了，参数传的值
	//setitimer(ITIMER_REAL, &myit, NULL); //相当于seconds后发送SIGALRM信号
	setitimer(ITIMER_REAL, &myit, &oldit);
	//return 0;
	//类型用ld
	printf("tv_sec=%ld,tv_microsec=%ld\n", oldit.it_value.tv_sec, oldit.it_value.tv_usec);
	return oldit.it_value.tv_sec;
}

//取消闹钟，传入0即可。

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