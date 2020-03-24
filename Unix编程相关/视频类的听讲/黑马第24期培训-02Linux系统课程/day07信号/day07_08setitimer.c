#include <sys/time.h>
#include <stdio.h>

int main()
{
	//定义3秒以后发送SIGALRM信号。【只有使用_real才是这个信号】
	struct itimerval myit = { {0,0}, {3,0} };//秒，微秒  【非周期性的】
	setitimer(ITIMER_REAL，&myit,NULL);
	while (true)
	{
		printf("who can kill me!\n");
		sleep(1);
	}
	return 0;
}