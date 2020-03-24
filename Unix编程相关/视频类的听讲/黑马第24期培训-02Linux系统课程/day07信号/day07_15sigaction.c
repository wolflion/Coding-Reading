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
	//注册一下捕捉函数
	struct sigaction act;
	act.sa_flags = 0;
	act.sa_handler = catch_sig;
	sigemptyset(&act.sa_mask);
	sigaction(SIGALRM, &act, NULL);
	//setitimer
	struct itimerval myit = { { 3, 0 }, { 5, 0 } };//3是周期性的。第一次是5秒，后面每隔3秒来一次
	setitimer(ITIMER_REAL，&myit, NULL);
	while (true)
	{
		printf("who can kill me!\n");
		sleep(1);
	}
	return 0;
}

//kill 14 进程id。  【发了一个它能捕获的信号】