//周期性的，要有捕捉函数
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

//typedef void (*sighandler_t)(int);  //函数指针
//sighandler_t signal(int signum, sighandler_t handler);

void catch_sig(int num)
{
	printf("cat %d sig\n", num);
}

int main()
{
	signal(SIGALRM,catch_sig); //只是注册了

	struct itimerval myit = { {3,0}, {5,0} };//秒，微秒  【周期性的】第一次等5秒，后面每隔3秒
	setitimer(ITIMER_REAL，&myit,NULL);
	while (true)
	{
		printf("who can kill me!\n");
		sleep(1);
	}
	return 0;
}